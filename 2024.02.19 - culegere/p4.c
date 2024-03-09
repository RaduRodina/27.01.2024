#include <string.h>
#include <stdio.h>
#include <ctype.h>

struct timp
{
    int hour;
    int min;
    int sec;
};

struct timp string2ts(char s[])
{
    struct timp ts1;
    sscanf(s, "%d:%d:%d", &ts1.hour, &ts1.min, &ts1.sec);
    return ts1;
};

int comp(struct timp ts1, struct timp ts2)
{
    if(ts1.hour!=ts2.hour)
    {
        return ts1.hour - ts2.hour;
    }
    else
    {
        if(ts1.min!=ts2.min)
        {
            return ts1.min -ts2.min;
        }
        else
        {
            return ts1.sec-ts2.sec;
        }
    }
}

void print(struct timp ts1)
{
    printf("%02d:%02d:%02d", ts1.hour, ts1.min, ts1.sec);
}

void process(char *path, struct timp ts1, struct timp ts2)
{
    char buf[100];
    struct timp tab[100];
    int n = 0;

    FILE *f = NULL;
    printf("%s\n", path);
    f = fopen(path, "rt");
    if(f == NULL)
    {
        return;
    }
    while(!feof(f))
    {
        fscanf(f, "%s", buf);
        struct timp ts3 = string2ts(buf);
        print(ts3);
        printf("\n");
        if(comp(ts1, ts3)<=0 && comp(ts3, ts2) <= 0)
        {
            tab[n++]=ts3;
        }
    }
    int sw;
    do
    {
        sw = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(comp(tab[i], tab[i+1])<0)
            {
                struct timp aux = tab[i+1];
                tab[i]=tab[i+1];
                tab[i+1]=aux;
                sw++;
            }
        }
    }
    while(sw!=0);

    for(int i = 0; i < n; i++)
    {
        print(tab[i]);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    if(argc!=4)
    {
        printf("Sintaxa %s cale hh:mm:ss", argv[0]);
        return 1;
    }
    char path[100] = "p4 - input.txt";
    char time1[20] = "01:00:00";
    char time2[20] = "23:00:00";

    strcpy(path, argv[1]);
    strcpy(time1, argv[2]);
    strcpy(time2, argv[3]);
}
