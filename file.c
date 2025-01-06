#include "file.h"

char *read_file(char *path) {
    char *buf = (char *)malloc(sizeof(char)*BUF_MAX);
    int fd = open(path, O_RDONLY);
    if(fd<0) {
        printf("Can't open %s file with errno %d\n", path, errno);
        exit(1);
    }
    int size = read(fd, buf, BUF_MAX);
    if(size<0) {
        printf("Can't read from file %s, size %d\n", path, size);
        exit(1);
    }
    close(fd);
    return buf;
}
