#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char* code(char* string, int shift);
char* decode(char* string, int shift);

int main() {
    char string[5000];
    int shift = 3;

    strcpy(string, "Secret information. Nobody should read it. Secrete word - 'humbag'");

    char* encoded = code(string, shift);
    printf("coded string: %s\n", encoded);

    char* decoded = decode(encoded, shift);
    printf("decoded string: %s\n", decoded);
    return 0;
}

char* code(char* string, int shift) {

    for (size_t i = 0; i < strlen(string); i++) {
        int newSymbol = string[i] - shift;
        string[i] = (char)newSymbol;
    }

    return(string);
}

char* decode(char* string, int shift) {

    for (size_t i = 0; i < strlen(string); i++) {
        int newSymbol = string[i] + shift;
        string[i] = (char)newSymbol;
    }

    return(string);
}
