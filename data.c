#include "data.h"

char *data_scale(char *str) {
    size_t size = strlen(str);
    char *buf = (char *)malloc(sizeof(char)*BUF_MAX);
    int j = 0;
    for(int i=0; i<size; i++) {
        if(isdigit(str[i])) {
            while(i<size && isdigit(str[i]))
                buf[j++] = str[i++];
            buf[j++] = ' ';
        }
    }
    if(j>0)
        buf[--j] = '\0';
    else
        buf[0] = '\0';
    return buf;
}