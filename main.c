#include <stdio.h>
#include <string.h>
#include "file.h"
#include "data.h"
#define BUF_MAX 64

int main(int argc, char *argv[])
{
    if(argc!=3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }
    char *usr = data_scale(read_file(argv[1]));
    char *sol = data_scale(read_file(argv[2]));
    if(strcmp(usr, sol)==0)
        puts("AC");
    else
        puts("WA");
    free(usr);
    free(sol);
    
    return 0;
}
