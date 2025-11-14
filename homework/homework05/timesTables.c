#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);

    if (N < 2) {
        printf("Error: N must be >= 2\n");
        return 1;
    }

    // Print header row
    printf("    "); // spacing before header row
    for (int i = 2; i <= N; i++) {
        printf("%4d", i);
    }
    printf("\n");

    // Print table rows
    for (int i = 2; i <= N; i++) {
        printf("%4d", i); // row label
        for (int j = 2; j <= N; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}

