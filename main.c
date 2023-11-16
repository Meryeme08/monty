#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char content[MAX_LINE_LENGTH];
    FILE *file;
    stack_t *stack = NULL;
    unsigned int counter = 0;
    size_t len; /* Declare size_t here due to C90 rules */

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(content, MAX_LINE_LENGTH, file) != NULL) {
        counter++;

        /* Check for line length exceeding buffer */
        if (content[MAX_LINE_LENGTH - 1] != '\0' && content[MAX_LINE_LENGTH - 1] != '\n') {
            fprintf(stderr, "Error: Line %d exceeds maximum length\n", counter);
            exit(EXIT_FAILURE);
        }

        len = strlen(content); /* Assign value to len after declarations */
        if (len > 0 && content[len - 1] == '\n') {
            content[len - 1] = '\0';
        }

        execute(content, &stack, counter, file);
    }

    fclose(file);
    return 0;
}
