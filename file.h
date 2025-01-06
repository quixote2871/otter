#ifndef FILE_H
#define FILE_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF_MAX 64

char *read_file(char *path);

#endif
