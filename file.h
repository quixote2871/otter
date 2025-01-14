#ifndef FILE_H
#define FILE_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#define BUF_MAX 64

void create_file(char *fname);
char *read_file(char *path);
void copy_file(char *source, char *dest);
void remove_file(char *fname);

#endif
