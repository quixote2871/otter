#include <stdio.h>
#include <string.h>
#include "file.h"
#include "data.h"

void create_and_copy_file(char *source, char *dest) {
    create_file(dest);
    copy_file(source, dest);
}

int main(int argc, char *argv[])
{
    if(argc!=4) {
        printf("Usage: %s source_file input_file output_file\n", argv[0]);
        exit(1);
    }
    // Copy source to the temporary file
    char source_file[] = "tsrc.java";
    create_and_copy_file(argv[1], source_file);

    char input_file[] = "tin.txt";
    create_and_copy_file(argv[2], input_file);

    // Run the temporary Java file with input and save the result
    char result_file[] = "tres.txt";
    char cmd[64] = "";
    sprintf(cmd, "java %s < %s > %s", source_file, input_file, result_file);
    system(cmd);

    // Compare with the expected output
    char *usr = data_scale(read_file(result_file));
    char *sol = data_scale(read_file(argv[3]));
    if(strcmp(usr, sol)==0)
        puts("AC");
    else
        puts("WA");
    free(usr);
    free(sol);

    // Remove the temporary files
    remove_file(source_file);
    remove_file(result_file);
    remove_file(input_file);

    return 0;
}
