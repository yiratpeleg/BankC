#include <stdio.h>
#include "myBank.h"

double twoDigits(double amount);
double accounts[ACOUNTS][STATUS]={0};
int count = 0;

void open(double amount)
{
    if (amount < 0)
    {
        printf("Your deposit sum must be positive\n");
    }
    else if (count < 50)
    {
        amount=twoDigits(amount);
        accounts[count][0] = 1;
        accounts[count][1] = amount;
        count++;
        printf("Your account number is: %d\n", count + 900);
    }
    else
    {
        printf("There is no room for a new account\n");
    }
}

void balance(int num)
{
    if(num>950 || num<901) printf("Wrong account number.");
    else if (accounts[num - 901][0] != 1)
    {
        printf("This account number is close\n");
    }
    else
    {
        printf("Your balance is: %lf\n", accounts[num - 901][1]);
    }
}

void deposit(int num, double amount)
{
    if(num>950 || num<901){
        printf("There is no acount with this number\n");
    }
    else if (amount < 0)
    {
        printf("Your deposit sum must be positive\n");
    }
    else if (accounts[num - 901][0] != 1)
    {
        printf("This account number is close\n");
    }
    else
    {
        amount=twoDigits(amount);
        accounts[num - 901][1]=accounts[num - 901][1] + amount;
        printf("Your balance is: %lf\n", accounts[num - 901][1]);
    }
}

void withdrawal(int num, double amount)
{
    if(num>950 || num<901){
        printf("There is no acount with this number\n");
    }
    if (amount < 0)
    {
        printf("Your withdrawal sum must be positive\n");
    }
    else if (accounts[num - 901][0] != 1)
    {
        printf("This account number is close\n");
    }
    else if (accounts[num - 901][1] < amount)
    {
        printf("There is not enough money in your account\n");
    }
    else
    {
        amount=twoDigits(amount);
        accounts[num - 901][1]=accounts[num - 901][1] - amount;
        printf("Your balance is: %lf\n", accounts[num - 901][1]);
    }
}

void close(int num)
{
    if(num>950 || num<901){
        printf("There is no acount with this number\n");
    }
    if (accounts[num - 901][0] != 1)
    {
        printf("This account number is close\n");
    }
    else
    {
        accounts[num - 901][0] = 0;
        accounts[num - 901][1] = 0;
    }
}

void interest(double in)
{
    for (int i = 0; i < 50; i++)
    {
        if (accounts[i][0] == 1)
        {
            accounts[i][1] += twoDigits((in * accounts[i][1]) / 100);
        }
    }
}

void print()
{
    for (int i = 0; i < 50; i++)
    {
        if (accounts[i][0] == 1)
        {
            printf("The balance of account %d is: %lf\n", i + 901, accounts[i][1]);
        }
    }
}

void exit1()
{
    for (int i = 0; i < 50; i++)
    {
        if (accounts[i][0] == 1)
        {
            accounts[i][0] = 0;
            accounts[i][1] = 0;
        }
    }
    printf("All accounts were closed\n");
}

double twoDigits(double amount){
    int temp=amount*100;
        amount=temp;
        amount=amount/100;
        return amount;
}
