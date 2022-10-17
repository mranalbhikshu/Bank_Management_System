#include <iostream>
#include <conio.h>
#include<fstream>
#include<string>

using namespace std;



class Bank{
    public:
    int balance = 0;
    string pin;
    string name;
    string phoneNo;
    long int accountNo;
    Bank *next; 
    string add;
    string pan;
    string id;
    string adhar;
};

Bank *head = NULL;
static string bankName = "GRAMIN BANK ";
static string IFSC = "BHIK00089";
long int accountno = 975689;
long int* poi = &accountno;


void insert_end(Bank** root, Bank* value) {
    cout << endl;
    Bank* new_node = new Bank();
    if (new_node == NULL) {
        cout << endl;
        exit(1);
    }
    new_node->next = NULL;
    new_node->balance = value->balance;
    new_node->id = value->id;
    new_node->pin = value->pin;
    new_node->name = value->name;
    new_node->phoneNo = value->phoneNo;
    new_node->accountNo = value->accountNo;
    new_node->add = value->add;
    new_node->pan = value->pan;
    new_node->adhar = value->adhar;
    
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    
    Bank* curr = *root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void serialize(Bank** root) {
    ofstream file("storage.txt");
    if (!file.is_open()) {
        exit(1);
    }

    for (Bank* curr = *root; curr != NULL; curr = curr->next) {
            file << curr->balance;
            file << endl;
            file << curr->id;
            file << endl;
            file << curr->pin;
            file << endl;
            file << curr->name;
            file << endl;
            file << curr->phoneNo;
            file << endl;
            file << curr->accountNo;
            file << endl;
            file << curr->add;
            file << endl;
            file << curr->pan;
            file << endl;
            file << curr->adhar;
            if(curr->next)
            file << endl;
    }
    file.close();
}
void deserialize(Bank** root) {
    ifstream file("storage.txt");
    int a;
    long int f;
    string s,b,c1,d,e,g,h,i;
    if (file.is_open()) {
        int c = 0;
        while(getline(file,s))
        {
            if(c==0)
            {
            a = stoi(s);
            }
            if(c==1)
            {
            b = s;
           
            }
            if(c==2)
            {
             c1 = s;
            }
            if(c==3)
            {
            d = s;
            }
            if(c==4)
            {
            e = s;
          
            }
            if(c==5)
            {
            f = stoi(s);
            
            }
            if(c==6)
            {
            g = s; 
            
            }
            if(c==7)
            {
            h = s;
            
            }
            if(c==8)
            {
            i = s;
            
            }
            c++;
            if(c>8)
            {
            c=0;
            Bank *val = new Bank;
            val->balance = a;
            val->id = b;
            val->pin = c1;
            val->name = d;
            val->phoneNo = e;
            val->accountNo = f;
            *poi = val->accountNo;
            val->add = g;
            val->pan = h;
            val->adhar = i;
            insert_end(&head,val);
            }
        }
    }
    
    file.close();
}


class pause {
    public :
    void stop()
    {
        string s;
        cout << "Press any key to continue...." << endl;
        cin >> s;
        return;
    }
};

class Deposit {
    protected:
    void depositMoney(Bank **head, string phoneNo)
    {
        double amount;
        Bank *temp = *head;
        cout << "\t\tEnter Money to be deposited." << endl;
        cout<<"\t\t";
        cin >> amount;
        while(temp != NULL)
        {
            if(temp->phoneNo == phoneNo)
            {
                temp->balance += amount;
                cout << "New Balance = " << temp->balance << endl;
                pause p1;
                p1.stop();
                return;
            }
            temp = temp->next;
        }
    }
};


class CloseAccount {
    protected:
    void closeAccount(Bank **head, string phoneNo)
    {
        Bank *temp = *head;
        Bank *prev = NULL;
        if (temp != NULL && temp ->phoneNo == phoneNo)
        {
            *head = temp->next;
            delete temp;
            cout << "Account Deactivated" << endl;
            pause p1;
            p1.stop();
            // main();
        }
        else
        {
            while(temp != NULL && temp ->phoneNo !=phoneNo)
            {
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL)
            {
                cout << "Account Not Found" << endl;
                pause p1;
                p1.stop();
                // main();
            }
            prev->next = temp->next;
            cout << "Account Deactivated" << endl;
            delete temp;
            pause p1;
            p1.stop();
            // main();
        }
    }
};

class Withdraw
{
    protected:
    void withdrawMoney(Bank **head, string phoneNo)
    {
        double amount;
        Bank *temp = *head;
        cout << "Enter Money to be withdrawn." << endl;
        cin >> amount;
        while(temp != NULL)
        {
            if(temp->phoneNo == phoneNo)
            {
                if(temp->balance < amount)
                {
                    cout << "Insufficient Funds" << endl;
                    pause p1;
                    p1.stop();
                    return;
                }
                temp->balance -= amount;
                cout << "Money Debited = " << amount << endl;
                cout << "New Balance = " << temp->balance << endl;
                pause p1;
                p1.stop();
                return;
            }
            temp = temp->next;
        }
    }
};

class Balance {
    protected:
    void checkBalance(Bank **head, string phoneNo)
    {
        Bank *temp = *head;
        while(temp != NULL)
        {
            if(temp->phoneNo == phoneNo)
            {
                cout << "Current Balance = " << temp->balance << endl;
                pause p1;
                p1.stop();
                return;
            }
            temp = temp->next;
        }
    }
};

class accountDetails {
    protected:
    void accountdetails(Bank **head, string phoneNo)
    {
        Bank *temp = *head;
        while(temp != NULL)
        {
            if(temp->phoneNo == phoneNo)
            {
                cout << "\t\tBank Name = " << bankName << endl;
                cout << "\t\tIFSC Code = " << IFSC << endl;
                cout << "\t\tAccount Number = " << temp->accountNo << endl;
                cout << "\t\tAccount Holder Name = " << temp->name << endl;
                cout << "\t\tAccount Holder Phone Number = " << temp->phoneNo << endl;
                cout << "\t\tAccount Balance = " << temp->balance << endl;
                cout << "\t\tAccount Holder Address = " << temp->add << endl;
                cout << "\t\tFor queries contact +91-9876543210" << endl; 
                pause p1;
                p1.stop();
                return;
            }
            temp = temp->next;
        }
    }
};


void loan(Bank **head, string phoneNo)
{
    cout<<"\t\tKISAN HIT MEIN JAARI "<<endl;
    cout <<"\t\tyou will get Rs. 40,000/bigha for upto 5 hectare at 6% interest per annum \n\n\n\n\n" << endl;
    cout <<"\t\tyou will get Rs. 50,000/bigha for more than 5 hectare at 8.6% interest per annum \n\n\n\n\n" << endl;
    cout<<"\t\tContact to your near Branch physically For further process"<<endl;
    pause p1;
    p1.stop();
}

class Transaction : protected Balance, protected Withdraw, protected Deposit{
    protected:
    void Transactions(Bank **head, string phoneNo){
        system("cls");
        int choice;
        cout << "We provide the following services." << endl;
        cout << "\t\t1. Withdraw" << endl;
        cout << "\t\t2. Deposit" << endl;
        cout << "\t\t3. Check Balance" << endl;
        cout << "\t\t4. Go back to Services Menu" << endl;
        cout << "\t\tEnter Your Choice" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                withdrawMoney(head,phoneNo);
                Transactions(head,phoneNo);
                break;
            case 2:
                depositMoney(head,phoneNo);
                Transactions(head,phoneNo);
                break;
            case 3:
                checkBalance(head,phoneNo);
                Transactions(head,phoneNo);
                break;
            case 4:
                return;
            default:
                cout << "\t\tEnter Valid Choice." << endl;
                Transactions(head,phoneNo);
                break;
    }
}
};

class Services : private CloseAccount, private accountDetails,private Transaction
{
    protected:
    void services(Bank **head, string phoneNo){
        system("cls");
        int choice;
        cout << "\t\tWe provide the following services." << endl;
        cout << "\t\t1. Transactions" << endl;
        cout << "\t\t2. Loan Section" << endl;
        cout << "\t\t3. Deactivate Account" << endl;
        cout << "\t\t4. Log Out" << endl;
        cout << "\t\t5. Account Details" << endl;
        
        Bank *temp = *head;
        int amount;
        while(temp != NULL)
        {
            if(temp->phoneNo == phoneNo)
            {
                amount = temp->balance;
            }
            temp = temp->next;
        } 
        cout << "\t\tEnter Your Choice" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                Transactions(head,phoneNo);
                services(head,phoneNo);
                break;

            case 2:
                   
                  loan(head,phoneNo);

                  pause p2;
                  p2.stop();
                  services(head,phoneNo);
                 
                 break;
            case 3:
                closeAccount(head,phoneNo);
                services(head,phoneNo);
                break;
            case 4:
                cout << "\t\tUser Logged Out!" << endl;
                pause p1;
                p1.stop();
                // main();
                break;
            case 5:
                accountdetails(head,phoneNo);
                services(head,phoneNo);
                break;
            default:
                cout << "\t\tEnter Valid Choice." << endl;
                services(head,phoneNo);
                break;
        }
    }
};

class Login : private Services, private pause{
    public:
    void loginUser(Bank **head)
    {
        string phoneNo,pin;
        cout << "\t\tEnter Phone No. : " ;
        cin >> phoneNo;
        Bank *temp = *head;
        if(*head == NULL)
        {
            cout << "\t\tPhone No. does not Exist! Create One new account" << endl;
            stop();
            return;
        }
        while(temp != NULL)
        { 
            if(temp->phoneNo == phoneNo)
            {
                   
                cout << "\t\tEnter PIN : " ;
                int length = 0;
                char password;
                while( length != 4)
                {
                    if (password>=48 && password<=57)
                    {
                        pin.push_back(password);
                        cout <<"*";
                        length++;
                    }
                    password = getch();
                }
                cout << endl;
                if(temp->pin == pin)
                {
                    cout << "\t\tWelcome " << temp->name << "!" << endl;
                    stop();
                    services(head,phoneNo);
                }
                else
                {
                    cout << "\t\tWrong PIN" << endl;
                    stop();
                    return ;
                }
            }
            temp = temp->next;
        }
        if(temp == NULL)
        {
            cout << "\t\tPhone No. does not Exist! Enter Correct Phone No. or create a new account." << endl;
            stop();    
            return;
        }
    }
};

class Address{
    public:
    string houseNo;
    string area;
    string city;
    string pin;
    string add;
    Address()
    {
        houseNo = "Nil ";
        area = "Nil ";
        city = "Nil ";
        pin = "Nil ";
        add = houseNo + area + city + pin;
    }
    string address(Bank **head)
    {
        cout << "\t\tEnter House Number: ";
        cin>>ws;
        getline(cin,houseNo);
        cout << endl;
        cout << "\t\tEnter Area : ";
        cin>>ws;
        getline(cin,area);
        cout << endl;
        cout << "\t\tEnter City : ";
        cin>>ws;
        getline(cin,city);
        cout << endl;
        cout << "\t\tEnter PIN Code : ";
        cin >> pin;
        cout << endl;
        add = houseNo + ", " + area + ", " + city + ", " + pin + ". ";
        return add;
    }
};

class NewUser 
{
    public : 
    string getId(Bank **head)
    {
        string phone_number;
        cout << "\t\tEnter your Phone Number : ";
        cin >> phone_number;
        cout << endl;
        Bank *temp = *head;
        while(temp != NULL)
        { 
            if(temp->phoneNo == phone_number)
            {
                cout << "\t\tPhone Number already exists." << endl;
                getId(head);
            }
            temp = temp->next;
        }
        return phone_number;
    }
    void newUserRegistration(Bank **head)
    {
        string phoneNo,pin,name,pan,adhar,id;
        Bank *node = new Bank();
        Bank *last = *head;
        int deposit;
        cout << "\t\tEnter Your Name : ";
        cin>>ws;
        getline(cin,name);
        cout << endl;
        Address a1;
        node->add = a1.address(head);
        // id = getId(head);
        cout << "\t\tEnter Phone Number : ";
        cin >> phoneNo;
        cout << "\t\tEnter ID : ";
        cin >> id;
        cout << "\t\tEnter Adhar Number : ";
        cin >> adhar;
        cout << "\t\tEnter PAN : ";
        cin >> pan;
        cout << endl;
        cout << "\t\tCreate Your PIN : ";
        int length = 0;
        char password;
        while( length != 4)
        {
            if (password>=48 && password<=57)
            {
                pin.push_back(password);
                cout <<"*";
                length++;
            }
            password = getch();
        }
        cout << endl;
        cout << "\t\tEnter initial deposit : ";
        cin >> deposit;
        cout << endl;
        node->phoneNo = phoneNo;
        node->balance = deposit;
        node->name = name;
        node->pin = pin;
        (*poi)++;
        node->accountNo = *poi;
        node->id = id;
        node->adhar = adhar;
        node->pan = pan;
        node->next = NULL;
        if(*head == NULL)
        {
            *head = node;
            return;
        }
        while(last->next != NULL)
        {
            last = last->next;
        } 
        last->next = node;
        return;
    }
};

int main()
{   
    deserialize(&head);
    int x=1;
    while(x){
        system("cls");
        system("color 30");
        int choice;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t  GRAMIN BANK MANAGEMENT SYSTEM " << endl << "\t\tEnter Your Choice\n\t\t1. Registration .\n\t\t2. Login.\n\t\t3.exit and save.\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
                NewUser user;
                user.newUserRegistration(&head);
                break;
            case 2:
            {
                Login login;
                login.loginUser(&head);
            }
                break;
            case 3:
                cout<<"\t\texit and save ";
                serialize(&head);
                x=0;
                exit(0);
            default:
                cout << "\t\tEnter A Valid Choice." << endl;
                pause p1;
                p1.stop();
                break;
        }
    }
}