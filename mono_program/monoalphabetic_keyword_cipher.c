#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cipherTable[26];

/* Generate cipher alphabet using keyword */
void generateCipher(char keyword[]) {
    int used[26] = {0};
    int k = 0;

    // Add keyword letters
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipherTable[k++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    // Add remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipherTable[k++] = ch;
        }
    }
}

/* Encryption */
void encrypt(char plaintext[]) {
    printf("\nEncrypted Text: ");

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) {
            int pos = toupper(ch) - 'A';
            printf("%c", cipherTable[pos]);
        } else {
            printf("%c", ch);
        }
    }
}

/* Decryption */
void decrypt(char ciphertext[]) {
    printf("\nDecrypted Text: ");

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = toupper(ciphertext[i]);

        if (isalpha(ch)) {
            for (int j = 0; j < 26; j++) {
                if (cipherTable[j] == ch) {
                    printf("%c", 'A' + j);
                    break;
                }
            }
        } else {
            printf("%c", ch);
        }
    }
}

int main() {
    char keyword[] = "CIPHER";
    char text[1000];
    int choice;

    generateCipher(keyword);

    printf("Plain Alphabet : ");
    for (char c = 'A'; c <= 'Z'; c++)
        printf("%c ", c);

    printf("\nCipher Alphabet: ");
    for (int i = 0; i < 26; i++)
        printf("%c ", cipherTable[i]);

    printf("\n\n1. Encrypt\n2. Decrypt\nEnter Choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter Text: ");
    fgets(text, sizeof(text), stdin);

    if (choice == 1)
        encrypt(text);
    else if (choice == 2)
        decrypt(text);
    else
        printf("Invalid Choice!");

    return 0;
}