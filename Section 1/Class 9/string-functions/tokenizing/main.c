#include <stdio.h>
#include <string.h>

int main(void) {
    
    // strchr()
    char str[] = "The quick brown fox";
    char ch = 'q';
    char *pGot_char = NULL;
    pGot_char = strchr(str, ch);

    printf("%s\n", pGot_char);

    // strstr()
    char word[] = "brown";
    char *pFound = NULL;
    pFound = strstr(str, word);
    printf("String: %s | Pointer: %c | Word: %s\n", pFound, *pFound, word);
    
    // strtok()
    char delimiter[2] = " ";
    char *token;
    token = strtok(str, delimiter);
    while (token != NULL) {
        printf("\n%s\n", token);

        token = strtok(NULL, delimiter);
    }
    return 0;
}
