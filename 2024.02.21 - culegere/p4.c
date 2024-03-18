//NU STIU DE CE SE OPRESTE LA PRIMA LINIE 

#include <string.h>
#include <stdio.h>
#include <ctype.h>


//STRUCTURA TIMP
struct timp
{
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    char activ[100];
};

//FUNCTIE DE CONVERSIE CHAR -> STRUCTURA TIMP
struct timp string2ts(char s[])
{
    struct timp ts;
    sscanf(s, "%d.%d.%d %d:%d:%d %s", &ts.day, &ts.month, &ts.year, &ts.hour, &ts.min, &ts.sec, &ts.activ);
    return ts;
}

//FUNCTIE DE PRINTARE FARA ACTIVITATE
void print_ts(struct timp ts)
{
    printf("%02d.%02d.%04d %02d:%02d:%02d %s", ts.day, ts.month, ts.year, ts.hour, ts.min, ts.sec, ts.activ);
}

int comp(struct timp t1, struct timp t2)
{
    if(t1.hour!=t2.hour)
    {
        return t1.hour - t2.hour;
    }
    else
    {
        if(t1.min!=t2.min)
        {
            return t1.min - t2.min;
        }
        else
        {
            return t1.sec-t2.sec;
        }
    }
}


void process(struct timp min_time, struct timp max_time)
{
    char buf[100];
    struct timp *w = NULL;
    int i;

    FILE *f;
    f = fopen("input.txt", "rt");

    if(f == NULL)
    {
        printf("Error at input\n");
        return;
    }

    while(fgets(buf, sizeof(buf), f)!=NULL)
    {
        printf("s=%s", buf);
        if(feof(f))
        {
            break;
        }
        struct timp t3 = string2ts(buf);

        printf("ts3= \n");
        print_ts(t3);
        printf("\n");

        if(comp(min_time, t3)<=0 && comp(t3, max_time)<=0)
        {
            w[i] = t3;
            i++;
        }
    }
    //fclose(f);
    //printf("\n");

    int n = i; //Numar de elemente

    //INTERSCHIMBAREA VECTORULUI DE TIP TIMP
    int sw;
    do
    {
        sw = 0;
        for(int j = 0; j < i - 1; j++)
        {
            if(comp(w[j], w[j+1]) > 0)
            {
                struct timp aux = w[j];
                w[j] = w[j+1];
                w[j+1] = aux;
                sw++;
            }
        }
    }
    while(sw!=0);

    for(int i = 0; i < n; i++)
    {
        print_ts(w[i]);
        printf("\n");
    }
}


int main()
{
    //DECLARARE TIMP MINIM SI MAXIM
    char max_time[20] = "03.18.2024 23:00:00 z";
    char min_time[20] = "00.00.00 00:00:00 a"; //ANNO DOMINI

    struct timp t1 = string2ts(min_time);
    struct timp t2 = string2ts(max_time);

    //print_ts(t1);
    process(t1, t2);

    return 0;
}
