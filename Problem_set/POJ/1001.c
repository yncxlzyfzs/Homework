#include <stdio.h>

char base[7];
int exponent,point;
char mediant[125];
char answer[125];

void multiply ()
{
    int i, j, mid, carry = 0;
    for (i=4; i>=0; i--)
    {
        for (j=124; i>=0; i--)
        {
            mid = (base[i]-'0')*(mediant[j]-'0')+carry+answer[i+j];
            carry = mid/10;
            answer[i+j] = mid%10;
        }
    }

    //copy answer to mediant
    for (i=0; i<125; i++) mediant[i] = answer[i];
}

void print_ans ()
{
    int i;
    for (i=124; i>=0; i--)
    {
        if (answer[i] != '0') break;
        answer[i] = -1;
    }

    for (i=0; i<125; i++)
    {
        int mark=0;
        if (!mark)
        {
            if (answer[i] == '0') continue;
            else mark=1;
        }

        if (answer[i] != -1) printf ("%c", answer[i]);
        else 
        {
            printf ("\n");
            break;
        }
    }
}

int
main ()
{
    while (scanf ("%s %d", base, &exponent) != EOF)
    {
        int i;
        
        //save and delete decimal point
        for (i=0; i<7; i++)
        {
            if (base[i] == '.')
            {
                point = 5 - i;
                for (; i<7; i++)
                {
                    base[i] = base[i+1];
                }
            }
        }

        //initialize mediant
        for (i=0; i<6; i++)
        {
            mediant[120+i] = base[i];  
        }

        //initialize answer
        for (i=0; i<125; i++) answer[i] = 0;

        //power
        for (i=1; i<exponent; i++)
        {
            multiply ();
        }

        //print answer
        print_ans ();
    }
    return 0;
}
