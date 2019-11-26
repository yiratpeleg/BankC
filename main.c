#include <stdio.h>
#include "myBank.c"

int main()
{
    char c;
    int aNum;    //account number
    double dSum; //deposit sum
    double wSum; //withdrawal sum
    double in;   //interest rate

    while (c != 'E')
    {
        printf("Please enter your action\n");
        scanf(" %c", &c);

        if (c == 'O')
        {
            printf("Please enter your deposit sum\n");
            scanf("%lf", &dSum);
            open(dSum);
        }

        else if (c == 'B')
        {
            printf("Please enter your account number\n");
            scanf("%d", &aNum);
            balance(aNum);
        }

        else if (c == 'D')
        {
            printf("Please enter your account number\n");
            scanf("%d", &aNum);
            printf("Please enter your deposit sum\n");
            scanf("%lf", &dSum);
            deposit(aNum, dSum);
        }

        else if (c == 'W')
        {
            printf("Please enter your account number\n");
            scanf("%d", &aNum);
            printf("Please enter your withdrawal sum\n");
            scanf("%lf", &wSum);
            withdrawal(aNum, wSum);
        }

        else if (c == 'C')
        {
            printf("Please enter your account number\n");
            scanf("%d", &aNum);
            close(aNum);
        }

        else if (c == 'I')
        {
            printf("Please enter your interest rate\n");
            scanf("%lf", &in);
            interest(in);
        }

        else if (c == 'P')
        {
            print();
        }

        else if (c == 'E')
        {
            exit();
        }
        else
        {
            printf("The action does not exist\n");
        }
        
    }

    return 0;
}

