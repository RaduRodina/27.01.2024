#include <stdio.h>
#include <string.h>
#include <ctype.h>

void prelucrare(char s[])
{
    int i;
    char w[100];
    int j;

    i = 0;
    j = 0;
    int st = 0;
    while(s[i] != 0)
    {
        printf("st = %d c = %c c = %d\n", st, s[i], s[i]);
        if(st == 0)
        {
            if(s[i] == '0')
            {
                w[j] = s[i];
                j++;
                st = 1;
            }
            else if(s[i] == ' ')
            {
                st = 0;
            }
            i++;
        }
        else if(st == 1)
        {
            if(s[i] == 'x')
            {
                w[j] = s[i];
                j++;
                st = 2;
            }
            else if (s[i] == ' ')
            {
                st = 0;
            }
            i++;
        }
        else if(st == 2)
        {
            printf("c = %d\n", s[i]);
            if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f'))
            {
                printf("br1\n");
                w[j] = s[i];
                j++;
                st = 2;
            }
            else if(s[i] == ' ' || s[i] == 10)
            {
                printf("br2\n");
                st = 3;
            }
            i++;
        }
        else if(st == 3)
        {
            w[j] = 0;
            printf("%s\n", w);
            st = 0;
            j = 0;
        }
    }
}

void citire(char s[])
{
    int i;
    char c = 0;

    while(c!=EOF)
    {
        i = 0;
        do
        {
            c = getchar();
            //printf("%c %d\n", c, c);
            s[i] = c;
            i++;
        }
        while(c!=10 && c != EOF);

        s[i] = 0;
        printf("%s\n", s);
        prelucrare(s);
    }
}

int main()
{
    char s[100];
    citire(s);
    return 0;
}
