#include <string.h>
#include <ctype.h>
#include <stdio.h>

void convert1(char s1[], char s2[])
{
    int j = 0;
    int i;
    for(i = 0; i<strlen(s1) - 1;i++)
    {
        if(isalpha(s1[i]) && isalpha(s1[i+1]))
        {
            s2[j++] = s1[i];
            s2[j++] = '1';
        }
        else
        {
            s2[j++] = s1[i];
        }
    }
    s2[j++] = s1[i];
    s2[j] = 0;

}

void convert(char s1[], char s2[])
{
    int i = 0;
    char c;
    char buf[100];
    int n = 0;

    s2[0] = 0;
    while(s1[i]!=0)
    {
        printf("n=%d, s1=%s, s2=%s, i=%d, c=%c\n", n, s1, s2, i, s1[i]);
        if(isalpha(s1[i]))
        {
            c = s1[i];
            n = 0;
        }
        else if(isdigit(s1[i]))
        {
            n = n*10 + s1[i] - '0';
            int j;
            for(j = 0; j < n; j++)
            {
                buf[j] = c;
            }
            buf[j] = 0;
            s2 = strcat(s2, buf);
            printf("s2=%s\n", s2);
        }

        i++;
    }
}


int main()
{
    char s[100] = "ab2cc3de2";
    char buf[100];
    char buf2[100];
    convert1(s, buf);
    printf("%s\n", buf);
    convert(buf, buf2);
    printf("%s\n", buf2);
    return 0;
}
