#include <stdio.h>

char xor_encrypt(char c, char key) {
    return c ^ key;
}

int main() {
    // i like opening files
    FILE *input = fopen("plain.txt", "rb");
    FILE *key = fopen("cipher.txt", "rb");
    FILE *output = fopen("output.txt", "wb");
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