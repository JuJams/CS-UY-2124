/*
Rec03
*/



#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
// Task 1
// Define an Account struct

struct Account{
    string acc_name;
    int acc_num;
};
// Task 2
// Define an Account class (use a different name than in Task 1)

class Accounts{

    friend ostream& operator<<(ostream& os, const Accounts& account);
    string acc_name;
    int acc_num;

    public:

        Accounts(const string& name,int num): acc_name(name), acc_num(num){}
        
        const string& getName() const{
            return acc_name;
        }
        const int& getnumber() const{
            return acc_num;
        }
};

ostream& operator<<(ostream& os, const Accounts& account){
    os<<account.acc_name<<" "<<account.acc_num<<endl;
    return os;
}
// Task 3
// Define an Account (use a different name than in Task 1&2) and
// Transaction classes
class Transaction{
    friend ostream& operator<<(ostream& os, const Transaction& transaction);
    public:
        Transaction(const string& trans_type, int amt): type(trans_type), amount(amt){}
    string type;
    int amount; 
};
class Class_acc{
    friend ostream& operator<<(ostream& os,const Class_acc& account);
    string acc_name;
    int acc_num;
    vector<Transaction> transactions;
    int bal = 0;
    public:
        Class_acc(const string& name,int num): acc_name(name),acc_num(num){}
        
        const string& getName() const{
            return acc_name;
        }
        int getnumber() const{
            return acc_num;
        }

        int getBalance() const{
            return bal;
        }

        void Deposit(int amount){
            bal += amount;
            transactions.emplace_back("Deposit",amount);
        }

        void Withdraw(int amount){
            if ((bal - amount) < 0){
                cout<<acc_num<< " has only "<< bal<< ". Insufficient for withdrawal of "<<amount<<"." <<endl;
            }
            else{
                bal -= amount;
                transactions.emplace_back("Withdraw", amount);
            }
            
        }

};





// Task 4
// Define an Account with a nested public Transaction class
// (use different names than in the previous Tasks)
class Trans_acc{
    
    string acc_name;
    int acc_num;
    int bal = 0;
    friend ostream& operator<<(ostream& os,const Trans_acc& account);

    public:
        class Public_trans{
            friend ostream& operator<<(ostream& os, const Trans_acc::Public_trans& transaction);    
            public:
                
                Public_trans(const string& trans_type, int amt): type(trans_type), amount(amt){}
                string type;
                int amount; 
        };
        Trans_acc(const string& name,int num): acc_name(name), acc_num(num){}
        
        const string& getName() const {
            return acc_name;
        }
        int getnumber(){
            return acc_num;
        }

        int getBalance(){
            return bal;
        }

        void Deposit(int amount){
            bal += amount;
            transactions.emplace_back("Deposit",amount);
        }

        void Withdraw(int amount){
            if ((bal - amount) < 0){
                cout<<acc_num<< " has only "<< bal<< ". Insufficient for withdrawal of "<<amount<<"." <<endl;
            }
            else{
                bal -= amount;
                transactions.emplace_back("Withdraw", amount);
            }
            
        }
    vector<Public_trans> transactions;
};

int main(){
    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n";

    ifstream ifs("accounts.txt");
    vector<Account> accounts;
    string name;
    int num;
    while(ifs>>name>>num){
        Account account;
        account.acc_name = name;
        account.acc_num = num;
        accounts.push_back(account);
    }
    for (size_t i = 0; i<accounts.size(); i++){
        cout<<accounts[i].acc_name<< " "<<accounts[i].acc_num<<endl;
    }
    ifs.close();

    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";

    accounts.clear();

    ifs.open("accounts.txt");
    
    while(ifs>>name>>num){
        
        accounts.push_back(Account {name,num});
    }
    for (size_t i = 0; i<accounts.size(); i++){
        cout<<accounts[i].acc_name<< " "<<accounts[i].acc_num<<endl;
    }

    ifs.close();

    //==================================
    // Task 2: account as class

    //      2a

    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    vector<Accounts> account2;
    ifs.open("accounts.txt");

    while(ifs>>name>>num){
        
        account2.push_back(Accounts(name,num));
    }
    
    ifs.close();

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";

    for (Accounts account2 : account2){
        cout<<account2.getName()<< " "<<account2.getnumber()<<endl;
    }
    

    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";

    for (Accounts account2 : account2){
        cout<<account2;
    }




    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    account2.clear();

    ifs.open("accounts.txt");

    while(ifs>>name>>num){
        Accounts acc_num(name,num);
        account2.push_back(acc_num);
    }
    ifs.close();
    
    cout << "\nTask2e:\n";
    cout << "Filling vector of class objects, using emplace_back:\n";

    account2.clear();

    ifs.open("accounts.txt");

    while(ifs>>name>>num){
        account2.emplace_back(name,num);
    }


    for (Accounts account2 : account2){
        cout<<account2;
    }
    ifs.close();
    cout << "==============\n";
    cout << "\nTask 3:\nAccounts and Transaction:\n";

    ifs.open("transactions.txt");
    if (!ifs){
        cout<<"transactions did not open";
        exit(0);
    }
    vector<Class_acc> account3;
    string dep, dep1;
    int acc_num, acc_amt;
    while(ifs>>dep){
        if (dep == "Account"){
            ifs>>dep1>>acc_num;
            account3.emplace_back(dep1,acc_num);
        }
        else if(dep == "Deposit"){
            ifs>>acc_num>>acc_amt;
            size_t i;
            for(i = 0; i<account3.size(); i++){
                if (account3[i].getnumber() == acc_num){
                    break;
                }
            }
            account3[i].Deposit(acc_amt);
            
        }
        else if(dep == "Withdraw"){
            ifs>>acc_num>>acc_amt;
            size_t i;
            for(i = 0; i<account3.size(); i++){
                if (account3[i].getnumber() == acc_num){
                    break;
                }
            }
            account3[i].Withdraw(acc_amt);
        }
        
    }
    for (Class_acc currAccountv3 : account3){
        cout<<currAccountv3;
    }
    ifs.close();

    cout << "==============\n";
    cout << "\nTask 4:\nTransaction nested in public section of Account:\n";

    ifs.open("transactions.txt");
    if (!ifs){
        cout<<"transactions did not open";
        exit(0);
    }
    vector<Trans_acc> accountsv4;
    
    while(ifs>>dep){
        if (dep == "Account"){
            ifs>>dep1>>acc_num;
            accountsv4.emplace_back(dep1,acc_num);
        }
        else if(dep == "Deposit"){
            ifs>>acc_num>>acc_amt;
            size_t i;
            for(i = 0; i<account3.size(); i++){
                if (accountsv4[i].getnumber() == acc_num){
                    break;
                }
            }
            accountsv4[i].Deposit(acc_amt);
            
        }
        else if(dep == "Withdraw"){
            ifs>>acc_num>>acc_amt;
            size_t i;
            for(i = 0; i<account3.size(); i++){
                if (accountsv4[i].getnumber() == acc_num){
                    break;
                }
            }
            accountsv4[i].Withdraw(acc_amt);
        }
        
    }

    for (Trans_acc currAccountv4 : accountsv4){
        cout<<currAccountv4;
    }

    cout << "==============\n";
    cout << "\nTask 5:\nTransaction nested in private section of Account:\n";



}

ostream& operator<<(ostream& os, const Transaction& transaction){
    os<<"\t"<<transaction.type<<" "<<transaction.amount<<endl;
    return os;
}

ostream& operator<<(ostream& os,const Class_acc& account){
    os<<account.acc_name<<" "<<account.acc_num<<" "<<account.bal<<" : " <<endl;
    for(size_t i = 0; i < account.transactions.size(); i++){
        os<<account.transactions[i];
    }
    return os;
}

ostream& operator<<(ostream& os,const Trans_acc& account){
    os<<account.acc_name<<" "<<account.acc_num<<" "<<account.bal<<" : "<<endl;
     for(Trans_acc::Public_trans transaction : account.transactions){
        os<<"\t"<<transaction;
    }
    return os;
}


ostream& operator<<(ostream& os, const Trans_acc::Public_trans& transaction){
    os<<transaction.type<<" "<<transaction.amount<<endl;
    return os;
}