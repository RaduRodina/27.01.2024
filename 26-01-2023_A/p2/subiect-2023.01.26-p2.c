#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main()
{
    unsigned long long a=0xffff0000ffffff00;
    unsigned long long m=0x0000000000000001;
    unsigned long long r;
    int c =0;
    printf("%d\n", sizeof(a));

    printf("a=%016llx m=%016llx r=%016llx c=%d\n", a, m, r, c);
    r = a & m;
    printf("a=%016llx m=%016llx r=%016llx c=%d\n", a, m, r, c);

    printf("comparatie %x\n",(a&m - r)==0);

    while((a&m-r)==0 && c<sizeof(a))
    {
        a=a>>1;
        c++;
        printf("a=%016llx m=%016llx r=%016llx c=%d\n", a, m, r, c);
    }

    printf("%d\n",c%10);

    return 0;
}
