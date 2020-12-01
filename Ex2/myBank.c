//
// Created by tal on 23/11/2020.
//
#include "myBank.h"
#include <stdio.h>
#define numOfT 5
static int numOfAcc=0;
int n=0;

void init() {
    if (numOfAcc >= numOfT)
        printf("All accounts are already taken\n");
    else {
        double am;
        printf("Please enter amount for deposit: ");
        n=scanf("%lf", &am);
        if(n==0){
            printf("invalid input!\n");
            return ;
        }
        int i;
        for (i = 0; i < numOfT; ++i) {
            if (accs[i][0] == 0) {
                accs[i][1] = am;
                accs[i][0] = 901 + i;
                printf("New account number is: %d \n", i + 901);
                numOfAcc++;
                return;
            }
        }
    }

}

void balance(int account) {
    if (!checkIn(account))
        return;
    printf("The balance of account number %d is: %.2lf\n",account+901, accs[account][1]);
}

void deposit(int account) {

    if (!checkIn(account))
        return;
    double amount;
    printf("Please enter amount for deposit: ");
    n=scanf("%lf", &amount);
    if(n==0){
        printf("Failed to read the amount\n");
        return ;
    }
    if (amount < 0) {
        printf("Cannot deposit a negative number\n");
        return;
    }
    printf("Your new balance is : %.2lf\n", accs[account][1] += amount);
}

void withdrawal(int account) {
    if (!checkIn(account))
        return;
    double amount;
    printf("Please enter the amount to withdraw: ");
    n=scanf("%lf", &amount);
    if(n==0){
        printf("invalid input!\n");
        return ;
    }
    if (amount < 0) {
        printf("Cannot withdraw a negative number\n");
        return;
    }
    if (accs[account][1] < amount) {
        printf("Cannot withdraw more than the balance\n");
        return;
    }
    printf("The new balance is: %.2lf\n", accs[account][1] -= amount);
}

void closeAcc(int account) {
    if (!checkIn(account))
        return;
    accs[account][0] = 0;
    numOfAcc--;
}

void addInterest() {
    double in;
    printf("Please enter interest rate: ");
    n=scanf(" %lf", &in);
    if(in>100||in<-100||n==0){
        printf("Failed to read the interest rate\n");
        return;
    }
    int i;
    for (i = 0; i < numOfT; ++i) {
        if(accs[i][0]!=0){
            accs[i][1]+=accs[i][1]*((in)/100);
        }
    }
}

void printAll() {
    if(numOfAcc==0){
        printf("There are no open accounts! ");
        return;
    }
    int i ;
    for (i = 0; i < numOfT; ++i) {
        if (accs[i][0] != 0) {
            balance(accs[i][0]);
        }
    }
}

void shutdown() {
    int i;
    for (i = 0; i < numOfT; ++i) {
        accs[i][0] = 0;
    }
}
int checkIn(int acc){
    if (accs[acc][0] == 0 || acc < 0 || acc > 50) {
        printf("This account is closed\n");
        return 0;
    }
    return 1;
}