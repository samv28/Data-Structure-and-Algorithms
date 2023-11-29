#include <stdio.h>
#include <string.h>

void caesarEncrypt(char message[], int shift) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + shift) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + shift) % 26) + 'A';
        }
    }
}

void caesarDecrypt(char message[], int shift) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' - shift + 26) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' - shift + 26) % 26) + 'A';
        }
    }
}

int main() {
    char message[1000];
    int shift;

    printf("Enter message to encrypt: ");
    gets(message);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Encrypt the message
    caesarEncrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    caesarDecrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}
