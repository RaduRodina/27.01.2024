#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct elev
{
    char nume[20];
    int note[10];
    int nr_note;
    float medie;
};

void sortare(struct elev *tab, int n)
{
    int sum = 0;
    float med = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < tab[i].nr_note; j++)
        {
            sum = sum + tab[i].note[j];
            printf("sum= %d\n", sum);
            printf("nr.note=%d\n", tab[i].nr_note);
            med = ((float)sum/tab[i].nr_note);
            tab[i].medie = med;
            printf("medie = %d\n", tab[i].medie);        }
    }
}

void print(struct elev *tab, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s ",tab[i].nume);
        for(int j = 0; j < tab[i].nr_note; j++)
        {
            printf("%d ", tab[i].note[j]);
        }
        printf("\n");
    }
    sortare(tab, n);
}

void citire(char *fisier)
{
    char buf[100];
    int i = 0;
    char w[100];
    int j = 0;
    int st = 0;

    struct elev tab[100];
    int n = 0;

    FILE *f;
    f = fopen(fisier, "rt");
    if(f == NULL)
    {
        printf("Eroare la intrare\n");
        return;
    }
    while(!feof(f))
    {
        struct elev e;
        e.nr_note = 0;

        fgets(buf, sizeof(buf), f);
        printf("buf=%s\n", buf);

        i = 0;
        while (1)
        {
            printf("st = %d, c=%d, w=%s\n", st, buf[i], w);
            if(st == 0)
            {
                if(isalpha(buf[i]))
                {
                    w[j] = buf[i];
                    j++;
                    w[j] = 0;
                    st = 1;
                    i++;
                }
                else if(buf[i] == ':')
                {
                    st = 3;
                }
                else if(buf[i] == ',')
                {
                    st = 3;
                }
                else if(isdigit(buf[i]))
                {
                    w[j] = buf[i];
                    j++;
                    w[j] = 0;
                    st = 4;
                    i++;
                }
                else if(buf[i] == 0)
                {
                    break;
                }
                else
                {
                    i++;
                }
            }
            else if (st == 1)
            {
                if(isalpha(buf[i]))
                {
                    w[j] = buf[i];
                    j++;
                    w[j] = 0;
                    st = 1;
                    i++;
                }
                else
                {
                    st = 2;
                }
            }
            else if(st == 2)
            {
                printf("Nume = %s\n", w);
                strcpy(e.nume, w);
                j = 0;
                w[j] = 0;
                st = 0;
            }
            else if(st == 3)
            {
                j = 0;
                w[j] = 0;
                st = 0;
                i++;
            }
            else if (st == 4)
            {
                if(isdigit(buf[i]))
                {
                    w[j] = buf[i];
                    j++;
                    w[j] = 0;
                    st = 4;
                    i++;
                }
                else
                {
                    st = 5;
                }
            }
            else if(st == 5)
            {
                printf("Nr. intreg: %s\n", w);
                int v;
                sscanf(w, "%d", &v);
                e.note[e.nr_note] = v;
                e.nr_note++;

                j = 0;
                w[j] = 0;
                st = 0;
            }
        }
        tab[n] = e;
        n++;
    }

    fclose(f);

    print(tab, n);
}

int main(int argc, char **argv)
{
    printf("%s\n", argv[0]);
    if(argc > 1)
    {
        printf("%s\n", argv[1]);
        //citire(argv[1]);
    }

    citire("p4.txt");
    return 0;
}
