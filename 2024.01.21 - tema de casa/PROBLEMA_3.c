#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *extractSuffix(char *s1, char *s2)
{
    int i = 0;
    char *str1 = strrev(s1);
    char *str2 = strrev(s2);
    printf("%s\n", str1);
    char w[100];

    while(str1 != 0 && str2 != 0)
    {
        if (str1[i] == str2[i])
        {
            w[i] = str1[i];
            printf("%c\n", w[i]);
            i++;
            w[i] = 0;
        }
        else
        {
            break;
        }
    }
    printf("%s\n", w);
    char *q = strrev(w);
    printf("%s\n", q);
    return strdup(q);
}

int main()
{
    char s1[] = "savanah";
    char s2[] = "montanah";
    char *rezultat;
    rezultat = extractSuffix(s1, s2);
    printf("%s\n", rezultat);
    return 0;
}
