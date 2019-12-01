#include <stdio.h>
#include "myBank.h"

int main()
{
    char c=' ';                                                    //the action the user choose
    int aNum =0;                                                   //account number
    double dSum=0;                                                 //deposit sum
    double wSum=0;                                                 //withdrawal sum
    double in=0;                                                   //interest rate
    int x=0;                                                       //save the quantity of scanf success
    int y=0;                                                       //save the quantity of scanf success

  
    while (c != 'E')
    {
        printf("Please enter your action:(O,B,D,W,C,P,I,E)\n");
        scanf(" %c", &c);

        if (c == 'O')
        {
            printf("Please enter your deposit sum\n");
            if(scanf("%lf", &dSum)!=1) {
                printf("ERR:Wrong input.\n");
            }
            else{
                open(dSum);
            }
        }

        else if (c == 'B')
        {
            printf("Please enter your account number\n");
            if(scanf("%d", &aNum)!=1){
                printf("ERR:Wrong input.\n");
            }
            else{
                balance(aNum);
            }
        }

        else if (c == 'D')
        {
            printf("Please enter your account number\n");
            x=scanf("%d", &aNum);
            printf("Please enter your deposit sum\n");
            y=scanf("%lf", &dSum);
            if(x+y!=2){
                printf("ERR:Wrong input.\n");
            }
            else{
            deposit(aNum, dSum);
            }
        }

        else if (c == 'W')
        {
            printf("Please enter your account number\n");
            x=scanf("%d", &aNum);
            printf("Please enter your withdrawal sum\n");
            y=scanf("%lf", &wSum);
            if(x+y!=2){
                printf("ERR:Wrong input.\n");
            }
            else{
            withdrawal(aNum, wSum);
            }
        }

        else if (c == 'C')
        {
            printf("Please enter your account number\n");
            if(scanf("%d", &aNum)!=1){
                printf("ERR:Wrong input.\n");
            }
            else{
            close(aNum);
            }
        }

        else if (c == 'I')
        {
            printf("Please enter your interest rate\n");
            if(scanf("%lf", &in)!=1){
                printf("ERR:Wrong input.\n");
            }
            else{
            interest(in);
            }
        }

        else if (c == 'P')
        {
            print();
        }

        else if (c == 'E')
        {
            exit1();
        }
        else
        {
            printf("The action does not exist\n");
        }
        
    }

    return 0;
}

