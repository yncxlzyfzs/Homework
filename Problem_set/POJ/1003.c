#include <stdio.h>

int
main ()
{
    float c, len;
    int num;

    scanf ("%f", &c);
    while (c)
    {
        len = 0;
        num = 0;
        do
        {
            num++;
            len += 1.00/(num+1);
        }while (len < c);

        printf ("%d card(s)\n", num);
        scanf ("%f", &c);
    }
}
