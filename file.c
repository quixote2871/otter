#include "file.h"

void create_file(char *fname) {
    int fd = open(fname, O_RDWR | O_CREAT | O_EXCL, 0744);
    if(fd<0) {
        printf("Can't create %s file with errno %d\n", fname, errno);
        exit(1);
    }
}

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

void copy_file(char *source, char *dest) {
    pid_t pid, d_pid;
    int exit_status;
    if((pid = fork())<0) {
        puts("fork error");
        exit(1);
    } else if(pid==0) {
        int rv = execl("/bin/cp", "cp", source, dest, (char *)0);
        if(rv==-1) {
            printf("Fail to execute cp from %s to %s with errno %d\n", source, dest, errno);
            exit(1);
        }
    } else {
        d_pid = wait(&exit_status);
        if(d_pid==-1) {
            printf("The child process did not terminate successfully");
            exit(1);
        }
    }
}

void remove_file(char *fname) {
    int rv = remove(fname);
    if(rv!=0) {
        printf("fail to remove %s file with errno %d\n", fname, errno);
        exit(1);
    }
}
