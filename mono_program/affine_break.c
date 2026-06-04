#include <stdio.h>
#include <string.h>

int modInverse(int a)
{
    for(int i = 1; i < 26; i++)
        if((a * i) % 26 == 1)
            return i;
    return -1;
}

int main()
{
    char cipher[100];

    printf("Enter Cipher Text: ");
    scanf("%s", cipher);

    printf("\nPossible Plaintexts:\n\n");

    for(int a = 1; a < 26; a++)
    {
        int a_inv = modInverse(a);

        if(a_inv == -1)
            continue;

        for(int b = 0; b < 26; b++)
        {
            printf("a=%d b=%d : ", a, b);

            for(int i = 0; cipher[i] != '\0'; i++)
            {
                int c = cipher[i] - 'A';
                int p = (a_inv * (c - b + 26)) % 26;
                printf("%c", p + 'A');
            }
            printf("\n");
        }
    }

    return 0;
}