#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Memory {
    int *contents;
    int length;
};

char *file_to_string(char *filename) {
    FILE *file;
    char *string;
    char c;
    int i = 0;
    int length = 0;

    file = fopen(filename, "r");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    string = (char *) malloc(sizeof(char) * (length + 1));

    while ((c = fgetc(file)) != EOF) {
        string[i] = c;
        i++;
    }
    string[i] = '\0';
    fclose(file);
    return string;
}

int return_memory_length(char *string) {
    int i = 0;
    int count = 0;
    char c;

    while ((c = string[i]) != '\0') {
        if (c == ',') {
            count++;
        }
        i++;
    }
    return count + 1;
}

int *create_initialized_int_array(int memory_length) {
    int *ret;

    ret = (int *) malloc(memory_length * sizeof(int));
    if (!ret) return NULL;

    for (int i = 0; i < memory_length; ++i)
        ret[i] = -1;

    return ret;
}

int *make_memory(int *memory, char *string) {
    int index = 0;
    char *token_at_index;

    token_at_index = strtok(string, ",");
    while (token_at_index) {
        memory[index] = atoi(token_at_index);
        token_at_index = strtok(NULL, ",");
        index++;
    }
    return memory;
}

struct Memory return_memory(char *file_path) {
    char *string;
    int memory_length;
    int *initialized_int_array;
    struct Memory memory;

    string = file_to_string(file_path);
    memory_length = return_memory_length(string);
    initialized_int_array = create_initialized_int_array(memory_length);
    memory.contents = make_memory(initialized_int_array, string);
    memory.length = memory_length;

    free(string);
    string = NULL;

    return memory;
}
