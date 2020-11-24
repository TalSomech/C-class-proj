#include <stdio.h>
#include "myBank.h"

int main() {
    int acc;
    char k='O';
    while(k!= 'E') {
        printf("\nTransactions:\n"
               "\'O': Open new account \n"
               "\'B' : Print balance\n"
               "\'D' : Deposit \n"
               "\'W' : Withdrawal \n"
               "\'C' : Close account\n"
               "\'I' : Add interest to all active accounts\n"
               "\'P' : Print all active accounts\n"
               "\'E' : Close all accounts and exit program\n"
               "\nTransaction: ");

            scanf(" %c", &k);
            while(getchar()!= '\n'&& k!=EOF){}
                if (k == 'B' || k == 'D' || k == 'W' || k == 'C') {
                    printf("Enter account number: ");
                    scanf(" %d", &acc);
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
                        printf("Invalid transaction , please try again \n");
                        break;
                    }
                }

    }
    printf("Thank you! come again! \n");
    return 0;
}
