#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char filetype(struct stat *stats) {
    char type = 'X';
    if(S_ISDIR(stats->st_mode)) {
        type = 'D';
    }
    else if(S_ISREG(stats->st_mode)) {
        type = 'F';
    }
    return type;
}

unsigned long check_dir_size(DIR* dirp) {
    unsigned long size = 0;
    struct dirent *dir_str;
    struct stat stats;
    while ((dir_str = readdir(dirp)) != NULL) {
        stat(dir_str->d_name, &stats);
        if (strcmp(dir_str->d_name, ".") == 0) {
            continue;
        }
        else if (strcmp(dir_str->d_name, "..") == 0) {
            continue;
        }
        if (S_ISDIR(stats.st_mode)) {
            continue;
        }
        size += stats.st_size;
    }
    return size;
}

void check_dir(const char* filename) {
    errno = 0;
    DIR* dirp = opendir(filename);
    if (errno) {
        printf("Cannot open directory.");
        exit(EXIT_FAILURE);
    }
    rewinddir(dirp);
    struct dirent *dir_str = NULL;
    struct stat stats;

    while ((dir_str = readdir(dirp)) != NULL) {
        if (errno) {
            printf("Error! Error while readind dir.\n");
            exit(EXIT_FAILURE);
        }
        if (strcmp(dir_str->d_name, ".") == 0) {
            continue;
        }
        else if (strcmp(dir_str->d_name, "..") == 0) {
            continue;
        }
        stat(dir_str->d_name, &stats);
        unsigned long size = check_dir_size(dirp);
        char type = filetype(&stats);
        printf("%s - %c\n", dir_str->d_name, type);
        printf("Total size: %lu\n", size);
    }
    closedir(dirp);
}

int main(int argc, char* argv[]) {

    errno = 0;
    char* filename = ".";
    check_dir(filename);

    return 0;
}
