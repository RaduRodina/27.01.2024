#include <stdio.h>
#include <string.h>

// timestamp structure
struct ts 
{
    int hour;
    int min;
    int sec;
};

struct ts string2ts(char s[])
{
    struct ts ts1;
    sscanf(s,"%d:%d:%d",&ts1.hour,&ts1.min,&ts1.sec);
    return ts1;
}

// functie de comparare returneaza valoare
//  <0 daca ts1<ts2 
// ==0 daca ts1==ts2
//  >0 daca ts1>ts2
int comp(struct ts ts1,struct ts ts2)
{
    if(ts1.hour!=ts2.hour)
    {
        // daca orele nu sunt egale returneaza diferenta lor
        return ts1.hour-ts2.hour;
    }
    else
    {
        if(ts1.min!=ts2.min)
        {
            // daca minutele nu sunt egale returneaza diferenta lor
            return ts1.min-ts2.min;
        }
        else
        {
            // daca minutele sunt egale returneaza diferenta dintre secunde
            return ts1.sec-ts2.sec;
        }
    }
}

// functie de afisare
void print(struct ts ts1)
{
    printf("%02d:%02d:%02d",ts1.hour,ts1.min,ts1.sec);
}

void process(char *path,struct ts ts1,struct ts ts2)
{
    char buf[100];
    struct ts tab[100];
    int n=0;

    FILE *f=NULL;
    //printf("%s\n",path);
    f=fopen(path,"rt");
    if(f==NULL)
    {
        return;
    }

    while(!feof(f))
    {
        fscanf(f,"%s",buf);
        struct ts ts3=string2ts(buf);
        //print(ts3);
        //printf("\n");
        if(comp(ts1,ts3)<=0 && comp(ts3,ts2)<=0)
        {
            tab[n++]=ts3;
        }
    }

    // sortare
    int sw;
    do
    {
        sw=0;
        for(int i=0;i<n-1;i++)
        {
            if(comp(tab[i],tab[i+1])>0)
            {
                struct ts aux=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=aux;
                sw++;
            }
        }
    } 
    while(sw!=0);
    
    // afisare finala
    for(int i=0;i<n;i++)
    {
        print(tab[i]);
        printf("\n");
    }
}

int main(int argc,char **argv)
{
    /*
    if(argc!= 4)
    {
        printf("Sintaxa %s cale hh:mm:ss hh:mm:ss",argv[0]);
        return 1;
    }
    */

    char path[100]="p4 - input.txt";
    char time1[20]="01:00:00";
    char time2[20]="23:00:00";

    /*
    strcpy(path,argv[1]);
    strcpy(time1,argv[2]);
    strcpy(time2,argv[3]);
    */

    struct ts ts1=string2ts(time1);
    struct ts ts2=string2ts(time2);

    //printf("comp %d\n",comp(ts1,ts2));

    process(path,ts1,ts2);

    return 0;
}
