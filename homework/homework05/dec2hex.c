#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned long long decimalValue;
    int hexDigits = 8;  // default to 32-bit (8 hex digits)

    if (argc == 1) {
        // No command-line arguments: ask user for input
        printf("Enter decimal value: ");
        scanf("%llu", &decimalValue);

        printf("Enter number of hex digits (8 or 16): ");
        scanf("%d", &hexDigits);
    } else if (argc >= 2) {
        // At least one argument: read decimal value from command line
        decimalValue = strtoull(argv[1], NULL, 10);

        // If hex digits argument exists, read it; otherwise default to 8
        if (argc >= 3)
            hexDigits = atoi(argv[2]);
    }

    // Validate hex digit input
    if (hexDigits != 8 && hexDigits != 16) {
        printf("Error: Hex digits must be 8 or 16.\n");
        return 1;
    }

    // Print in zero-padded hex (uppercase)
    printf("0x%0*llX\n", hexDigits, decimalValue);

    return 0;
}

