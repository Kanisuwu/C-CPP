#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <string.h>

int aes_init(EVP_CIPHER_CTX *ctx, unsigned char *data, int datal, unsigned char *salt, unsigned char *key, unsigned char *iv) {
    /* nrounds is for how many iterations of hash the function will do.
     * More iterations = more security != more speed.
     */
    int i, nrounds = 5;

    /* Creates a derived key from SHA1.
     * Could possibly use a salt of 8 bytes.
     * Data is a buffer containing data_length bytes which is used to derive the keying data.
     */
    i = EVP_BytesToKey(EVP_aes_128_cbc(), EVP_sha1(), salt, data, datal, nrounds, key, iv);

    /* We are using aes_128, which bits -> bytes are 16 bytes.
     * If the key generate is not 16 bytes, return -1
     */
    if (i != 16)
        return -1;
    EVP_CIPHER_CTX_init(ctx);
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);
    return 0;
}

unsigned char *encrypt(EVP_CIPHER_CTX *ctx, unsigned char *plaintext, int *length, unsigned char *key, unsigned char *iv) {
    
    /* 
    Remember, c_len is the length of ciphertext and is used to know how many bytes the update have written
    f_len is the final length, used to know how many bytes the finalization have written 
    */ 
    int c_len = *length + EVP_CIPHER_block_size(EVP_aes_128_cbc()), f_len = 0;

    /* Space for the encrypted plaintext */
    unsigned char *ciphertext = malloc(c_len);
    
    /* Calling init again with only ctx allows the reuse of further encryption processes */
    EVP_EncryptInit_ex(ctx, NULL, NULL, NULL, NULL);

    EVP_EncryptUpdate(ctx, ciphertext, &c_len, plaintext, *length);
    EVP_EncryptFinal_ex(ctx, ciphertext + c_len, &f_len);

    /* 
    Takes the cipher_length and puts together with the final_length
    Resulting in the real length of the encryption 
    */
    *length = c_len + f_len;
    return ciphertext;
}

unsigned char *decrypt(EVP_CIPHER_CTX *ctx, unsigned char *ciphertext, int *length, unsigned char *key, unsigned char *iv) {
    int p_len = *length, f_len = 0;
    unsigned char *plaintext = malloc(p_len);

    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, plaintext, &p_len, ciphertext, *length);
    EVP_DecryptFinal_ex(ctx, plaintext + p_len, &f_len);

    *length = p_len + f_len;
    return plaintext;
}

void display(unsigned char *hex, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%02x", hex[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    char data[] = "0123456789abcdef";
    int datal = strlen(data) + 1;
    int bytes_r = 0;

    unsigned char *ciphertext = NULL;
    unsigned char *plaintext = NULL;

    unsigned char key[16];
    unsigned char iv[16];

    char *f_name = argv[1];
    char chunk[4096];
    int c_len = 0;

    FILE *file = fopen(f_name, "rb");
    FILE *new_f = fopen("copy.txt", "wb");

    int init = aes_init(ctx, (unsigned char *)data, datal, NULL, key, iv);

    if (init == -1) {
        printf("Could not initialize properly.\n");
        EVP_CIPHER_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    while((bytes_r = fread(chunk, 1, 4096, file)) > 0) {
        c_len = bytes_r;
        ciphertext = encrypt(ctx, (unsigned char *)chunk, &c_len, key, iv);
        fwrite(ciphertext, 1, c_len, new_f);
    }

    fclose(file);
    fclose(new_f);

    remove(f_name);
    rename("copy.txt", f_name);

    printf("Key: ");
    display(key, 16);
    printf("IV: ");
    display(iv, 16);

    free(ciphertext);
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}
