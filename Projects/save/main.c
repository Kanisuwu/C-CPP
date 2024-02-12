#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 257

#ifdef _WIN32
    #define PATH_SEPARATOR "\\"
#else
    #define PATH_SEPARATOR "/"
#endif


void strlast(char dest[SIZE], char *fpath) 
{
    char fpath_buf[SIZE];
    strcpy(fpath_buf, fpath);
    char *token = strtok(fpath_buf, PATH_SEPARATOR);
    while (token) 
    {
        strcpy(dest, token);
        token = strtok(NULL, PATH_SEPARATOR);
    }
}

int add_space(char string[SIZE], int amount) {
    if (amount > SIZE || amount < 0)
        return 1;
    for (int i = 0; i < amount; i++)
        string[i] = ' ';
    string[amount + 1] = '\0';
    return 0;
}

// copy a file and sends it to ./backup/[relative-path]
int copyf(char* dest, char* src) 
{
    errno = 0;
    FILE* file = NULL;
    FILE* newfile = NULL;
    char filename[SIZE];
    char destpath[SIZE + 1];
    char ch;

    strlast(filename, src);
    snprintf(destpath, SIZE + 1, "%s%s%s", dest, PATH_SEPARATOR, filename);

    file = fopen(src, "r");
    newfile = fopen(destpath, "w");
    if (!file) 
    {
        printf("Error while reading the file %s\n", src);
        exit(EXIT_FAILURE);
    }
    if (!newfile) 
    {
        printf("Error while creating the file %s\n", destpath);
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(file)) != EOF) 
    {
        fputc(ch, newfile);
    }
    fclose(file);
    fclose(newfile);
    return 0;
}

/*
 * Search a particular directory.
 * Returns 0 if exists
 * Returns 1 if not found
 * Returns -1 if error
 */
int search_dir(const char* target, char* path) 
{
    int status = 1;
    DIR* stream_d = opendir(path);
    struct dirent* direct;
    struct stat info;
    char fullpath[SIZE];

    if (!stream_d) 
        status = -1;

    while ((direct = readdir(stream_d)) != NULL) 
    {
        if (strcmp(direct->d_name, ".") == 0)
            continue;
        if (strcmp(direct->d_name, "..") == 0)
            continue; 
        snprintf(fullpath, SIZE, "%s%s%s", path, PATH_SEPARATOR, direct->d_name);
        stat(fullpath, &info);
        if ((S_ISDIR(info.st_mode)) && (strcmp(target, direct->d_name) == 0)) 
        {
            status = 0;
            break;
        }
    }
    closedir(stream_d);
    return status;
}

/* Takes makes a directory in <dest> called <d_name>
 * Accepts only 256 bytes
 */ 
int make_directory(char* dest, const char* d_name) 
{
    int error = 0;
    char fpath[SIZE];
    snprintf(fpath, SIZE, "%s%s%s", dest, PATH_SEPARATOR, d_name);

    if (!search_dir(d_name, dest)) 
    {
        printf("[ ??? ] %s already exists\n", d_name);
    }
    else 
    {
        int status = mkdir(fpath, S_IRWXU | S_IRWXG | S_IRWXO);
        if (!status)
            printf("[ OK ] %s folder\n", d_name);
        else {
            printf("[ ERR ] %s folder\n", d_name);
            error = 1;
        }
    }
    return error;
}

// filters ".", ".." and ...
int filter_file(int numargs, char* filename, ...) 
{
    _Bool status = 0;
    va_list pargs;
    va_start(pargs, filename);
    if (strcmp(filename, ".") == 0)
        status = 1;
    if (strcmp(filename, "..") == 0)
        status = 1;
    for (int i = 0; i < numargs; i++) 
    {
        if (strcmp(filename, va_arg(pargs, char*)) == 0) 
            status = 1;
    }
    va_end(pargs);
    return status;
}

// displays and copies recursively the file system
void backup(char* dest, char* src, int level) 
{
    char* exception = "backup";
    DIR* dir = opendir(src);
    struct dirent* file;
    struct stat info;
    char src_path[SIZE];
    char space_level[SIZE] = "";

    if (dir == NULL) 
    {
        printf("Could not open the file \"%s\"", src);
        exit(EXIT_FAILURE);
    }

    while((file = readdir(dir)) != NULL) 
    {
        char dest_path[SIZE];
        if(filter_file(1, file->d_name, exception))
            continue;
        add_space(space_level, level);
        snprintf(src_path, SIZE, "%s%s%s", src, PATH_SEPARATOR, file->d_name);
        stat(src_path, &info);
        if(!S_ISDIR(info.st_mode)) {
            copyf(dest, src_path);
            printf("%s%s - [ OK ]\n", space_level, file->d_name);
        }
        else {
            // dest/filename -> ./testing
            make_directory(dest, file->d_name);
            snprintf(dest_path, SIZE, "%s%s%s", dest, PATH_SEPARATOR, file->d_name);
            printf("%s%s%s\n", space_level, file->d_name, PATH_SEPARATOR);
            level++;
            backup(dest_path, src_path, level);
            level--;
        }
    }
    closedir(dir);
};


int main (int argc, char* argv[]) 
{
    char* dir = argv[1];
    char* dest = argv[2];
    const char* folder = "backup";
    char fullpath[SIZE];
    char rel_path[SIZE + 2];

    if (argc != 3) 
    {
        printf("Usage: <directory_backup> <source_directory>\n");
        exit(EXIT_FAILURE);
    }

    make_directory(dest, folder);
    // .\backup
    snprintf(fullpath, SIZE, "%s%s%s", dest, PATH_SEPARATOR, folder);
    make_directory(fullpath, dir);
    // ./backup\dir
    snprintf(rel_path, SIZE + 2, "%s%s%s", fullpath, PATH_SEPARATOR, dir);
    backup(rel_path, dest, 0);
}
