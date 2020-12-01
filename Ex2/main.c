#include <stdio.h>
#include "myBank.h"

int main() {
    int acc;
    char k='O';
    int n=0;
    while(k!= 'E') {
        printf("\nPlease choose a transaction type:\n"
               "O-Open Account\n"
               "B-Balance Inquiry\n"
               "D-Deposit\n"
               "W-Withdrawal\n"
               "C-Close Account\n"
               "I-Interest\n"
               "P-Print\n"
               "E-Exit\n");
            scanf(" %c", &k);
                if (k == 'B' || k == 'D' || k == 'W' || k == 'C') {
                    printf("Please enter account number: ");
                    n=scanf(" %d", &acc);
                    printf("%d",n);
                    if(n==0){
                        printf("Failed to read account number");
                        continue;
                    }
                    acc -= 901;
                }
                switch (k) {
                    case 'O': {
                        init();
                        break;
                    }
                    case 'B': {
                        balance(acc);
                        break;
                    }
                    case 'D': {
                        deposit(acc);
                        break;
                    }
                    case 'W': {
                        withdrawal(acc);
                        break;
                    }
                    case 'C': {
                        closeAcc(acc);
                        break;
                    }
                    case 'I': {
                        addInterest();
                        break;
                    }
                    case 'P': {
                        printAll();
                        break;
                    }
                    case 'E': {
                        shutdown();
                        break;
                    }
                    default: {
                        printf("Invalid transaction type\n");
                        break;
                    }
                }
    }
    return 0;
}
