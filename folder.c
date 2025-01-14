#include "folder.h"

struct Dir *read_dir(char *dirpath) {
    DIR *dir = opendir(dirpath);
    if(dir==NULL) {
        printf("Can't open %s with errno %d\n", dirpath, errno);
        exit(1);
    }
    struct dirent *entry;
    struct Dir *ret = (struct Dir *)malloc(sizeof(struct Dir));
    ret->size = 0;
    while((entry = readdir(dir))!=NULL) {
        char *fname = entry->d_name;
        if(!strcmp(fname, "..") || !strcmp(fname, "."))
            continue;
        ret->list[(ret->size)++] = strdup(fname);
    }
    closedir(dir);
    return ret;
}
