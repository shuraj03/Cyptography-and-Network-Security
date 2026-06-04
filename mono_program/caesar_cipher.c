#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    int k, i;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter key (1-25): ");
    scanf("%d", &k);

    printf("Encrypted Text: ");
    for(i = 0; text[i] != '\0'; i++) {
        char ch = toupper(text[i]);
        ch = ((ch - 'A' + k) % 26) + 'A';
        printf("%c", ch);
    }

    printf("\nDecrypted Text: ");
    for(i = 0; text[i] != '\0'; i++) {
        char ch = toupper(text[i]);
        ch = ((ch - 'A' + k) % 26) + 'A';
        ch = ((ch - 'A' - k + 26) % 26) + 'A';
        printf("%c", ch);
    }

    return 0;
}