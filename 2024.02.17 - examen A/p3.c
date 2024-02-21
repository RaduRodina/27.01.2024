#include <stdio.h>
#include <string.h>
#include <ctype.h>

void update_string(char *s)
{
    int i = 0;
    char w[100];
    int j;
    int count;
    char c = s[0];

    while(s[i] != 0)
    {
        count = 1;
        // aici for-ul nu poate pleca de la 0 ci de la pozitia i, ar fi bine sa aibe alta variabila j
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == c)
            {
                count++;
                printf("%d\n", count);
            }
            else
            {
                w[j] = c;
                j++;
                if (count > 0)
                {
                    count = count + '0';
                    w[j] = count;
                    j++;
                }
                c = s[i];
                count = 1;
                // daca nu mai este concidenta probabil ar fi trebuit sa iesim cu break
            }
        }
        // cand e gata for-ul atunci ai putea sa concatenezi rezultatele in sirul de iesire

        // apoi reset, se ia urmatorul caracter si se pleaca cu numararea de la pozitia sa i=j

        j = 0;
        w[j] = 0;
    }
    printf("result = %s\n", w);
}

int main()
{
  char *s = "abbcccdee";
  printf("s = %s\n", s);

  update_string(s);

}
