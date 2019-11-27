#ifndef _MYBANK_H
#define _MYBANK_H
#define ACOUNTS 50
#define STATUS 2

static double accounts[ACOUNTS][STATUS] = {0};
void open(double amount);
void balance(int num);
void deposit(int num, double amount);
void withdrawal(int num, double amount);
void close(int num);
void interest(double in);
void print();
void exit1();
double twoDigits(double amount);

#endif