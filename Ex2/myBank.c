//
// Created by tal on 23/11/2020.
//
#include "myBank.h"
#include <stdio.h>
#define numOfT 5
static int numOfAcc=0;


void init() {
    if (numOfAcc >= numOfT)
        printf("All accounts are already taken\n");

    else {
        double am;
        printf("Enter an initial amount: ");
        scanf("%lf", &am);
        int i;
        for (i = 0; i < numOfT; ++i) {
            if (accs[i][0] == 0) {
                accs[i][1] = am;
                accs[i][0] = 901 + i;
                printf("Your new account number is : %d \n", i + 901);
                numOfAcc++;
                return;
            }
        }
    }

}

void balance(int account) {
    if (!checkIn(account))
        return;
    printf("Your balance is: %.2lf\n", accs[account][1]);
}

void deposit(int account) {

    if (!checkIn(account))
        return;
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
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
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount < 0) {
        printf("Cannot withdraw a negative number\n");
        return;
    }
    if (accs[account][1] < amount) {
        printf("You do not own enough money\n");
        return;
    }
    printf("Your new balance is : %.2lf\n", accs[account][1] -= amount);
}

void closeAcc(int account) {
    if (!checkIn(account))
        return;
    accs[account][0] = 0;
    numOfAcc--;
}

void addInterest() {
    double in;
    printf("Enter interest to add: ");
    scanf(" %lf", &in);
    if(in <=0){
        printf("Interest must be >0");
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
    int i ;
    for (i = 0; i < numOfT; ++i) {
        if (accs[i][0] != 0) {
            printf("Account number: %d  Balance: %.2lf\n", i + 901, accs[i][1]);
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
        printf("This account doesn't exists\n");
        return 0;
    }
    return 1;
}