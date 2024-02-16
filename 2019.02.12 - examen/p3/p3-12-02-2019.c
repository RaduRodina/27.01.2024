#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *extractPrefix(char *s1, char *s2)
{
    int i = 0;
    char w[100];
    while(s1[i] != 0 && s2[i] !=0)
    {
        if(s1[i] == s2[i])
        {
            w[i] = s1[i];
            w[i+1] = 0;
            i++;
        }
        else
        {
            break;
        }
    }
    return strdup(w);
}

int main()
{
    char s1[100] = "palindrome";
    char s2[100] = "palisade";

    // #1
    char rezultat[100];
    strcpy(rezultat, extractPrefix(s1, s2));
    printf("%s\n", rezultat);
    // #2
    char *p;
    p = extractPrefix(s1, s2);
    printf("%s\n", p);

    return 0;
}
