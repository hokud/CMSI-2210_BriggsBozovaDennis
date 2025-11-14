#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isspace()

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int c;
    int in_word = 0;   // flag to indicate if currently inside a word
    long word_count = 0;

    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            // whitespace includes spaces, tabs, newlines, etc.
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            word_count++;
        }
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Word count: %ld\n", word_count);
    return 0;
}

