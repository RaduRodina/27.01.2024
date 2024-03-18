#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*void convert_buf(char buff[], char c, int nr)
{
    int i = 0;
    for(i = 0; i < nr; i++)
    {
        buff[i] = c;
    }
    buff[i] = 0;
}*/

void convert(char s1[], char s2[])
{
    int i = 0;
    int k = 0;
    //char buff[100];
    int j = 0;
    int nr = 0;

    while(s1[i]!=0)
    {
        printf("i=%d c=%c, s2=%s\n", i, s1[i], s2);

        if(isalpha(s1[i]))
        {
            s2[j] = s1[i];
            j++;
            i++;
        }
        else if(isdigit(s1[i]))
        {
            nr = s1[i]-'0';
            if(isalpha(s1[i-1]))
            {
                for(int k = 0; k <nr; k++)
                {
                    s2[j] = s1[i-1];
                    j++;
                }
            }
            //convert_buf(buff, s1[i-1], nr);
            //printf("buff=%s\n", buff);
        }
        i++;
    }
    s2[j] = 0;
}


int main()
{
    char s1[100] = "ab2cc3de2";
    char s2[100] = "";
    convert(s1,s2);

    return 0;
}
