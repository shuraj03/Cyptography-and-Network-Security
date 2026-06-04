#include <stdio.h>
#include <string.h>
#include <ctype.h>
int modInverse(int a)
{
    for(int i = 1; i < 26; i++)
        if((a * i) % 26 == 1)
            return i;
    return -1;
}
int main()
{
    char text[100];
    int a, b, i;

    printf("Enter Plain Text: ");
    scanf("%s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    if(modInverse(a) == -1)
    {
        printf("Invalid value of a!\n");
        return 0;
    }
    printf("Encrypted Text: ");
    for(i = 0; text[i] != '\0'; i++)
    {
        int p = toupper(text[i]) - 'A';
        int c = (a * p + b) % 26;
        printf("%c", c + 'A');
    }
    printf("\n");

    return 0;
}
