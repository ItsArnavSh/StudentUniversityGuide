#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a Vigenere cipher
void encrypt(char *str, char *key) {
    int len = strlen(str);
    int key_len = strlen(key);
    for (int i = 0, j = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + key[j] - 'a') % 26;
            j = (j + 1) % key_len;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + key[j] - 'a') % 26;
            j = (j + 1) % key_len;
        }
    }
}

// Function to decrypt a string using a Vigenere cipher
void decrypt(char *str, char *key) {
    int len = strlen(str);
    int key_len = strlen(key);
    for (int i = 0, j = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' - (key[j] - 'a') + 26) % 26;
            j = (j + 1) % key_len;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' - (key[j] - 'a') + 26) % 26;
            j = (j + 1) % key_len;
        }
    }
}

int main() {
    char str[100];
    char key[100];

    printf("Enter a string to encrypt: ");
    fgets(str, 100, stdin);
    printf("Enter a key: ");
    fgets(key, 100, stdin);

    // Remove newline characters from input
    str[strcspn(str, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    encrypt(str, key);
    printf("Encrypted string: %s\n", str);

    decrypt(str, key);
    printf("Decrypted string: %s\n", str);

    return 0;
}
