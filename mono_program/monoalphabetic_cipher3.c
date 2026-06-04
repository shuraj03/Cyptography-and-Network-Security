#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plain[100], cipher[100], decrypt[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;
    printf("Enter Plain Text: ");
    scanf("%s", plain);
    // Encryption
    for(i = 0; plain[i] != '\0'; i++) {
        cipher[i] = key[toupper(plain[i]) - 'A'];
    }
    cipher[i] = '\0';
    printf("Encrypted Text: %s\n", cipher);
    // Decryption
    for(i = 0; cipher[i] != '\0'; i++) {
        for(int j = 0; j < 26; j++) {
            if(cipher[i] == key[j]) {
                decrypt[i] = 'A' + j;
                break;
            }
        }
    }
    decrypt[i] = '\0';
    printf("Decrypted Text: %s\n", decrypt);
    return 0;
}