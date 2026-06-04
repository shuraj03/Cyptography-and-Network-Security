#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp, *fc;
    char ch;
    int p[26] = {0}, c[26] = {0};

    fp = fopen("plaintext.txt", "r");
    fc = fopen("ciphertext.txt", "w");

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            p[ch - 'A']++;

            char enc = ((ch - 'A' + 3) % 26) + 'A';
            c[enc - 'A']++;

            fputc(enc, fc);
        }
    }

    fclose(fp);
    fclose(fc);

    printf("\nPlaintext Frequency\n");
    for (int i = 0; i < 26; i++)
        printf("%c : %d\n", 'A' + i, p[i]);

    printf("\nCiphertext Frequency\n");
    for (int i = 0; i < 26; i++)
        printf("%c : %d\n", 'A' + i, c[i]);

    return 0;
}