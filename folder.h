#ifndef FOLDER_H
#define FOLDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

struct Dir {
    unsigned int size;
    char *list[128];
};

struct Dir *read_dir(char *dirpath);

#endif
