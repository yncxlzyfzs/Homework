#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void ErrorReport ();
void system1 ();
void system2 ();
float evaluation (char exp[MAX_EXP_LEN]);
Status TestAvailability (char exp[MAX_EXP_LEN]);
Status IsNumber (char c);
Status IsCharacter (char c);
Status Greater (char e, Elemtype tmp_e);
Elemtype operation (Elemtype num1, Elemtype num2, Elemtype tmp_e);

int main (int argc, char *argv[])
{
    int op;

    printf ("Please choose a system: \n");
    printf ("1.Function Test System\n");
    printf ("2.Expression Evaluation System\n");
    printf ("choice: ");
    scanf (" %d",&op);
    
    if (op == 1) system1 ();
    else if (op == 2) system2 ();
    else
    {
        printf ("There is no choice %d\n", op);
        printf ("Press Enter to Quit...\n");
        getchar();
        getchar();
    }

    return 0;
}

void system1 ()
{
    Stack s;
    Status status;
    Elemtype e;
    int i;
    int op = 1;
    while (op)
    {
        system ("reset");
        printf("\n\n");
        printf("      Menu for Stack On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("          1. Init       6.GetTop \n");
        printf("          2. Destroy    7. Push\n");
        printf("          3. Clear      8. Pop \n");
        printf("          4. IsEmpty    9. Traversal\n");
        printf("          5. Length\n");
        printf("          0. Exit\n");
        printf("-------------------------------------------------\n");

        printf ("operation: ");
        scanf (" %d", &op);

        switch (op)
        {
            case 1:
                if (InitStack (&s) == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("Initializing succeeded.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 2:
                if (DestroyStack (&s) == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("Destroying succeeded.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 3:
                if (ClearStack (s) == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("Clear stack succeeded.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 4:
                status = StackEmpty (s);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if (status == TRUE) printf ("Stack is empty.\n");
                else printf ("Stack is not empty.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 5:
                i = StackLength (s);
                if (i == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("Stack's length is : %d\n", i);
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 6:
                status = GetTop (s, &e);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if(status == FALSE)
                    printf ("Stack is empty...\n");
                else
                    printf ("Top element is: %.2f\n", e);
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 7:
                printf ("\n");
                printf ("Please input a element: ");
                scanf (" %f", &e);
                status = Push (s, e);
                if (status == ABNORMAL)
                    ErrorReport ();
                else
                    printf ("Push succeeded.\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 8:
                status = Pop (s, &e);
                if (status == ABNORMAL)
                    ErrorReport ();
                else if (status == FALSE)
                    printf ("Stack is empty.\n");
                else
                    printf ("Pop succeeded.Top element is: %.2f\n", e);
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 9:
                if (StackTraversal (s) == ABNORMAL)
                    ErrorReport ();
                else
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
            case 0:
                printf ("Press Enter to quit...\n");
                getchar();
                getchar();
                break;
            default:
                printf ("Input Error: Please Input a number between 0 and 9\n");
                printf ("Press Enter to continue...\n");
                getchar();
                getchar();
                break;
        }
    }
}

void system2 ()
{
    char exp[MAX_EXP_LEN];
    system ("reset");
    printf("\n\n");
    printf("      Menu for Expression Evaluation \n");
    printf("-------------------------------------------------\n");
    printf("          Please input characters like + - * / or one-digit numbers\n");
    printf("-------------------------------------------------\n");
    printf ("Expression: ");
    scanf (" %s", exp);
    if (TestAvailability (exp) == ABNORMAL)
        printf ("Error: invalid expression!\n");
    else
        printf ("Value: %.2f\n", evaluation (exp));
    printf("-------------------------------------------------\n");
    printf ("Press Enter to quit...\n");
    getchar();
    getchar();
}

float evaluation (char exp[MAX_EXP_LEN])
{
    //初始化栈
    Stack s1 = NULL, s2 = NULL;
    InitStack (&s1);
    InitStack (&s2);

    //运算
    int i, counter = 0;
    Elemtype e, tmp_e, num1, num2, result = exp[0]-'0';
    for (i=0; exp[i]!='\0'; i++)
    {
        if (IsCharacter (exp[i]))
        {
            e = exp[i];
            if (StackEmpty (s1))
            {
                Push (s1, e);
                continue;
            }
            
            GetTop (s1, &tmp_e);
            while (!StackEmpty (s1) && Greater (e, tmp_e))
            {
                Pop (s1, &tmp_e);
                Pop (s2, &num1);
                Pop (s2, &num2);
                result = operation (num1, num2, tmp_e);
                Push (s2, result);
                GetTop (s1, &tmp_e);
            }

            Push (s1, e);
        }
        else
        {
            Push (s2, exp[i]-'0');
        }
    }

    //清空两个栈
    while (!StackEmpty (s1))
    {
        Pop (s1, &tmp_e);
        Pop (s2, &num1);
        Pop (s2, &num2);
        result = operation (num1, num2, tmp_e);
        Push (s2, result);
    }

    Pop (s2, &result);

    return result;
}

Status TestAvailability (char exp[MAX_EXP_LEN])
{
    int i;
    for (i=0; exp[i]!='\0'; i++)
    {
        if (IsNumber (exp[i]))
            if (!IsNumber (exp[i+1]))
                   continue;
        if (IsCharacter (exp[i]))
            if (!IsCharacter (exp[i+1]))
                continue;
        return ABNORMAL;
    }

    if (!IsNumber (exp[0]) || !IsNumber (exp[i-1]))
        return ABNORMAL;

    return TRUE;
}

Status IsNumber (char c)
{
    if (c-'0'>=0 && c-'0'<=9)
        return TRUE;
    else
        return FALSE;
}
Status IsCharacter (char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return TRUE;
    else
        return FALSE;
}

Status Greater (char e, Elemtype tmp_e)
{
    if ((e == '+' || e == '-') && (tmp_e == '*' || tmp_e == '/'))
        return TRUE;
    else
        return FALSE;
}

Elemtype operation (Elemtype num1, Elemtype num2, Elemtype tmp_e)
{
    char c = tmp_e;
    switch (c)
    {
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '*':
            return num1*num2;
        case '/':
            return num2/num1;
        default:
            return 0;
    }
}

/*
    未初始化错误
 */
void ErrorReport ()
{
    printf ("Stack does not exist,please initialize first.\n");
}
