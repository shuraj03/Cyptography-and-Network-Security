#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { const char *sym; char plain; } Entry;

static const Entry table[] = {
    {"5",'a'}, {"†",'d'}, {"(",'f'}, {"6",'g'},
    {"0",'i'}, {"9",'k'}, {"*",'l'}, {"‡",'m'},
    {"3",'n'}, {"—",'o'}, {")",'p'}, {"?",'r'},
    {":",'s'}, {";",'t'}, {"4",'h'}, {"8",'e'},
    {"1",'v'}, {"¶",'y'}, {"]",'z'}, {"2",'u'},
    {".",'c'}, {"+",'b'}, {NULL, 0}
};

static const char ciphertext[] =
    "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"
    "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*"
    ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81"
    "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

static int utf8_len(unsigned char c)
{
    if (c < 0x80) return 1;
    if (c < 0xE0) return 2;
    if (c < 0xF0) return 3;
    return 4;
}

static char lookup(const char *s, int len)
{
    for (int i = 0; table[i].sym; i++)
    {
        int slen = strlen(table[i].sym);
        if (slen == len && strncmp(table[i].sym, s, len) == 0)
            return table[i].plain;
    }
    return '?';
}

int main()
{
    printf("Decrypted Message:\n\n");

    const unsigned char *p = (const unsigned char *)ciphertext;
    while (*p)
    {
        int  len = utf8_len(*p);
        char ch  = lookup((const char *)p, len);
        putchar(ch);
        p += len;
    }

    printf("\n");
    return 0;
}
