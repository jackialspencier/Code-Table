#include "account.h"
int SavingAccount::count = 0;
SavingAccount::SavingAccount(double money){
    count++;
    account = count;
    saving = money;
}
void SavingAccount::display(){
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << account;
    cout.precision(2);
    cout << " " << saving << " ";
    cout << mrate12 << endl;
}
void SavingAccount::calculate(){
    saving += saving * mrate12; 
}
void SavingAccount::changerate(float nrate){
    mrate12 = nrate;
}