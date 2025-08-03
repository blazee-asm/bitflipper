#include <stdio.h>

char xor_encrypt(char c, char key) {
    return c ^ key;
}

int main() {
    // i like opening files
    char f[100];
    printf("Input file: ");
    scanf("%99s", f);
    FILE *input = fopen(f, "rb");
    printf("Key file: ");
    scanf("%99s", f);
    FILE *key = fopen(f, "rb");
    printf("Output file: ");
    scanf("%99s", f);
    FILE *output = fopen(f, "wb");
    // oh no, file problems
    if (input == NULL || key == NULL || output == NULL) {
        printf("Error when opening files.");
        return 1;
    }
    int k;

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        k = fgetc(key);
        // if we reached the end, go back to start
        if (k == EOF) {
            rewind(key);
            k = fgetc(key);
        }
        // encrypts, then writes
        fputc(xor_encrypt(ch, k), output);
    }

    // remember to close ur files my brotha
    fclose(input);
    fclose(key);
    fclose(output);
    
    return 0;
}