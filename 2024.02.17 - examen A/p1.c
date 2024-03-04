#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_octal(char c)
{
    if(c >= '0' && c <= '7')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

convert(char w[])
{
    int nr = 0;
    for(int i = 0; i < strlen(w); i++)
    {
        nr = 8*nr + (w[i] - '0');
    }
    return nr;
}

void octal_reading()
{
    char buf[100];
    char c;
    char w[100];
    int j = 0;
    int st = 0;

    FILE *f;
    f = fopen("p1 - input.txt", "rt");
    if (f == NULL)
    {
        printf("Error at input\n");
        return;
    }

    /*fgets(buf, sizeof(buf), f);
    printf("%s\n", buf);
    fgets(buf, sizeof(buf), f);
    printf("%s\n", buf);*/

    c = fgetc(f);
        while(c!=EOF)
        {
            printf("st=%d, c=%c, w=%s\n", st, c, w);
            if (st == 0)
            {
                if(isdigit(c))
                {
                    if(is_octal(c) == 1)
                    {
                        w[j] = c;
                        j++;
                        st = 1;
                        c = fgetc(f);

                    }
                    else
                    {
                        st = 0;
                        c = fgetc(f);
                    }
                }
                else
                {
                    st = 0;
                    c = fgetc(f);
                }
            }
            else if(st == 1)
            {
                if(isdigit(c))
                {
                    if(is_octal(c) == 1)
                    {
                        w[j] = c;
                        j++;
                        st = 1;
                        c = fgetc(f);
                    }
                    else
                    {
                        st = 3;
                    }
                }
                else if(c == ' ' || c == '\n')
                {
                    st = 2;
                }
                else
                {
                    st = 0;
                    c = fgetc(f);
                }
            }
            else if(st == 2)
            {
                w[j] = '\0';
                printf("Am gasit un nr\n");
                int x = convert(w);
                j = 0;
                st = 0;
            }
            else if (st == 3)
            {
                st = 0;
                c = fgetc(f);
            }
        }
        fclose(f);
    }


int main()
{
    octal_reading();

    return 0;
}
