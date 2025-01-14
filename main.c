#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "folder.h"
#include "data.h"

void create_and_copy_file(char *source, char *dest) {
    create_file(dest);
    copy_file(source, dest);
}

int compare(const void *s1, const void *s2) {
    return strcmp(*(char **)s1, *(char **)s2);
}

enum Result {
    accept = 0,
    wrong
};

enum Result judge(char *source_file, char *input_file, char *output_file) {
    // Copy source to the temporary file
    char temp_source_file[] = "source.java";
    create_and_copy_file(source_file, temp_source_file);

    char temp_input_file[] = "input.txt";
    create_and_copy_file(input_file, temp_input_file);

    // Run the temporary Java file with input and save the result
    char result_file[] = "result.txt";
    char command[64] = "";
    sprintf(command, "java %s < %s > %s", temp_source_file, temp_input_file, result_file);
    system(command);

    // Compare with the expected output
    char *usr = data_scale(read_file(result_file));
    char *sol = data_scale(read_file(output_file));
    enum Result result;
    if(strcmp(usr, sol)==0)
        result = accept;
    else
        result = wrong;
    free(usr);
    free(sol);

    // Remove the temporary files
    remove_file(temp_source_file);
    remove_file(result_file);
    remove_file(temp_input_file);
    
    return result;
}

void judge_directory_files(char *source_file, char *input_dir, char *output_dir) {
    int ac_cnt = 0, wa_cnt = 0;

    // Read the list of file names from the directory
    struct Dir *input_dir_data = read_dir(input_dir);
    qsort(input_dir_data->list, input_dir_data->size, sizeof(char *), compare);

    struct Dir *output_dir_data = read_dir(output_dir);
    qsort(output_dir_data->list, output_dir_data->size, sizeof(char *), compare);

    // Judge each file's input
    for(int i=0; i<input_dir_data->size; i++) {
        char *input_file = strdup(input_dir);
        strcat(input_file, input_dir_data->list[i]);

        char *output_file = strdup(output_dir);
        strcat(output_file, output_dir_data->list[i]);

        enum Result result = judge(source_file, input_file, output_file);
        if(result==accept)
            ac_cnt += 1;
        else
            wa_cnt += 1;

        free(input_file);
        free(output_file);
    }

    free(input_dir_data);
    free(output_dir_data);
    
    // Print the results
    printf("Total: %d, AC: %d, WA: %d\n", ac_cnt+wa_cnt, ac_cnt, wa_cnt);
}

int main(int argc, char *argv[])
{
    if(argc<4) {
        printf("Usage: %s source_file input_file output_file\n", argv[0]);
        printf("    %s -d source_file input_dir/ output_dir/\n", argv[0]);
        exit(1);
    } else {
        if(argc==4) {
            enum Result result = judge(argv[1], argv[2], argv[3]);
            if(result==accept)
                printf("Total: 1, AC: 1, WA: 0\n");
            else
                printf("Total: 1, AC: 0, WA: 1\n");
        }
        if(argc==5)
            judge_directory_files(argv[2], argv[3], argv[4]);
    }

    return 0;
}
