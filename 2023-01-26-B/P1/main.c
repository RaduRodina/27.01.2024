#include <stdio.h>
#include <string.h>
#include <ctype.h>

void citire(char s[])
{
    char c;
    int i = 0;
    while((c = getchar())!= EOF)
    {
        if (c == '\n')
        {
            break;
        }
        s[i] = c;
        i++;
    }
    s[i] = 0;
}
void without_space(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    for(i = 0; i < strlen(s1); i++)
    {
        if(s1[i] != ' ')
        {
            s2[j] = s1[i];
            j++;
        }
    }
    s2[j] = 0;
}

void expres_sum(char s[])
{
    int i = 0;
    char w[100];
    int j = 0;
    char q[100];
    int k = 0;
    int st = 0;

    while(s[i] != 0)
    {
        if(st == 0)
        {
            if(isdigit(s[i]))
            {
                st = 1;
            }
            else if(s[i] == '(')
            {
                st = 2;
                i++;
            }
            else
            {
                st = 0;
                i++;
            }
        }
        else if(st == 1)
        {
            w[j] = s[i]
            j++;
            w[j] = 0;
        }
        else if(st == 2)
        {
            if(isdigit(s[i]))
            {
                q[k] = s[i];
                k++;
            }
            //HELP
        }

        i++;
    }
}

int main()
{
    char s1[100];
    char s2[100];
    printf("Start: ");
    citire(s1);
    printf("%s\n", s1);
    without_space(s1, s2);
    printf("%s\n", s2);
    expres_sum(s2);



    return 0;
}
