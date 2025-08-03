#include <stdio.h>

char encrypt(char plaintext, char k1, char k2) {
    return (~(plaintext ^ k1)) ^ k2;
}

char decrypt(char ciphertext, char k1, char k2) {
    return (~(ciphertext ^ k2)) ^ k1;
}

int main() {
    // i like opening files
    char do_encrypt;
    printf("Encrypt? (y/n): ");
    scanf(" %c", &do_encrypt);
    char f[100];
    printf("Input file: ");
    scanf("%99s", f);
    FILE *input = fopen(f, "rb");
    printf("Key file #1: ");
    scanf("%99s", f);
    FILE *key1 = fopen(f, "rb");
    printf("Key file #2: ");
    scanf("%99s", f);
    FILE *key2 = fopen(f, "rb");
    printf("Output file: ");
    scanf("%99s", f);
    FILE *output = fopen(f, "wb");
    // oh no, file problems
    if (input == NULL || key1 == NULL || key2 == NULL || output == NULL) {
        printf("Error when opening files.");
        return 1;
    }
    int k1;
    int k2;

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        k1 = fgetc(key1);
        k2 = fgetc(key2);
        // if we reached the end, go back to start
        if (k1 == EOF) {
            rewind(key1);
            k1 = fgetc(key1);
        }
        if (k2 == EOF) {
            rewind(key2);
            k2 = fgetc(key2);
        }
        // encrypts/decrypts, then writes
        if (do_encrypt == 'Y' || do_encrypt == 'y') { fputc(encrypt(ch, k1, k2), output); } else { fputc(decrypt(ch, k1, k2), output); }
    }

    // remember to close ur files my brotha
    fclose(input);
    fclose(key1);
    fclose(key2);
    fclose(output);
    
    return 0;
}