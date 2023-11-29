#include <stdio.h>
#include <string.h>

void encrypt(char *text, char *key) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] != ' ') {
            text[i] = ((text[i] - 'a') + (key[i % strlen(key)] - 'a')) % 26 + 'a';
        }
    }
}

void decrypt(char *text, char *key) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] != ' ') {
            text[i] = ((text[i] - 'a') - (key[i % strlen(key)] - 'a') + 26) % 26 + 'a';
        }
    }
}

int main() {
    char text[1000];
    char key[100];

    printf("Enter the text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove the newline character from fgets

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove the newline character from fgets

    printf("Text before encryption: %s\n", text);
    encrypt(text, key);
    printf("Text after encryption: %s\n", text);

    printf("Decrypting...\n");
    decrypt(text, key);
    printf("Text after decryption: %s\n", text);

    return 0;
}
