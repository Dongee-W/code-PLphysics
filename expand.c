// 2014-9-22
#include <stdio.h>
int main()
{
    unsigned int n ,n1, b, e ,d;
    printf("Number to expand: ");
    scanf("%u", &n);
    printf("Base: ");
    scanf("%u", &b);
    n1 = n;
    e = 1;
    while (n1 > b)
    {
        n1 /= b;
        e *= b;
    }
    while (n > 0)
    {
        d = n / e;
        n = n % e;
        if (d < 10) printf("%u", d);
        else printf("%c", (char)((unsigned int)'a' + d - 10));

        e /= b;
    }

}
