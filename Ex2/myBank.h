
double accs[50][2];
void init();
void balance(int account);
void deposit(int account);
void withdrawal(int account);
void closeAcc(int account);
void addInterest();
void printAll();
void shutdown();
int checkIn(int acc);
typedef enum transaction
{
    O,
    B,
    D,
    W,
    C,
    I,
    P,
    E,
}transaction;