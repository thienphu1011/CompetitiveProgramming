#include <bits/stdc++.h>
using namespace std;

struct Account{
    string name,address,city,state;
    int zip,phone;
    double balance=0.0;
    string lastpayment;
};

struct Node{
    Account acc;
    Node*next;
};

typedef struct Node*node;

node makeNode(){
    Account acc;
    cout <<"Enter the information of customer account \n";
    cout <<"Enter the name :"; cin.ignore();
    getline(cin,acc.name);
    cout <<"Enter the address :"; cin.ignore();
    getline(cin,acc.address);
    cout <<"Enter the city :"; cin.ignore();
    getline(cin,acc.city);
    cout<<"Enter the state :"; cin.ignore();
    getline(cin,acc.state);
    cout<<"Enter the ZIP code :"; cin>>acc.zip;
    cout<<"Enter the phone number :"; cin>>acc.phone;
    cout<<"Enter the account balance :"; cin>>acc.balance;
    cout<<"Enter the date of last payment :"; cin.ignore();
    getline(cin,acc.lastpayment);
    node tmp= new Node();
    tmp->acc=acc;
    tmp->next=NULL;
    return tmp;
}

bool empty(node a){
    return a==NULL;
}

int size (node a){
    int cnt=0;
    while (a!=NULL){
        ++cnt;
        a= a->next;
    }
    return cnt;
}

//them vao dau
void insertFirst(node &a){
    node tmp =makeNode();
    if (a==NULL){
        a=tmp;
    }
    else {
        tmp->next=a;
        a=tmp;
    }
}

//them vao cuoi
void insertLast(node &a){
    node tmp=makeNode();
    if (a==NULL){
        a=tmp;
    }
    else {
        node p=a;
        while (p->next!=NULL){
            p=p->next;
        }
        p->next=tmp;
    }
}
// them vao giua 
void insertMid(node &a, int pos){
    int n=size(a);
    if (pos<=0 || pos>n+1){
        cout <<"In valid position !\n";
    }
    if (pos==1){
        insertFirst(a); return;
    }
    else if (pos==n+1){
        insertLast(a); return;
    }
    node p=a;
    for (int i=1 ; i<pos -1 ; i++){
        p=p->next; 
    }
    node tmp=makeNode();
    tmp->next=p->next;
    p->next=tmp;
}

// xoa o dau 
void deleteFirst(node &a){
    if (a==NULL) return;
    a=a->next;
}

// xoa o cuoi 
void deleteLast(node &a){
    if (a==NULL) return ;
    node first=NULL, last=a;
    while (last->next !=NULL){
        first=last;
        last=last->next;
    }
    if (first==NULL){
        a=NULL;
    }
    else {
        first->next=NULL;
    }
}

// xoa o giua 
void deleteMid(node &a,int pos){
    if (pos <=0|| pos>size(a)) return;
    node first=NULL,last=a;
    for (int i=1; i<pos; i++){
        first=last;
        last=last->next;
    }
    if (first==NULL){
        a=a->next;
    }
    else {
        first->next=last->next;
    }
}

void inp (Account acc){
    cout <<"The information of customer account \n";
    cout <<"Name :"<<acc.name<<endl;
    cout <<"Address :"<<acc.address<<endl;
    cout <<"City :"<<acc.city<<endl;
    cout<<"State :"<<acc.state<<endl;
    cout<<"ZIP code :"<<acc.zip<<endl;
    cout<<"Phone number :"<<acc.phone<<endl;
    cout<<"Account balance :"<<acc.balance<<endl;
    cout<<"Date of last payment :"<<acc.lastpayment<<endl;
}

// tim kiem theo so dien thoai
void searchphone(node &a){
    if (a==NULL){
        cout <<"The list is empty!\n";
        return;
    }
    int phone;
    cout <<"Enter the phone number to find :"; cin>>phone;
    bool found=false;
    node p=a;
    while (p!=NULL){
        if (p->acc.phone==phone){
            cout <<"Customer found !\n";
            inp (p->acc);
            found =true;
            
        }
        p=p->next;
    }
    if (!found){
        cout <<"No customer with phone number: "<<phone<<" found\n";
    }
}

void inds(node a){
    cout <<"Contents of entire file\n";
    while (a!=NULL){
        inp(a->acc);
        a=a->next;
    }
    cout <<endl;
    cout <<"--------------------------\n";
}

int menu (){
    cout <<"-----------Customer Manage-----------\n";
    cout <<"0. Exit.\n";
    cout <<"1.Enter new records into the file.\n";
    cout <<"2.Search for a particular customer's record and display it.\n";
    cout <<"3.Search for a particular customer's record and delete it.\n";
    cout <<"4.Search for a particular customer's record and change it.\n";
    cout <<"5.Display the contents of entire file.\n";
    int option=0;
    cout <<"Enter out of the above option :";
    cin>>option;
    return option;
}

int main() {
    int option =0;
    node head=NULL;
    int is; int pos; int dl;
    do {
        MENU:
        option=menu();
        switch(option){

            case 0:
                break;

            case 1:
                cout <<"Choose the type of insert \n";
                cout <<"1.Insert First\n";
                cout <<"2.Insert Middle\n";
                cout <<"3.Insert Last\n";
                cin>>is;

                if (is ==1){
                    insertFirst(head);
                }
                else if (is==2){
                    cout<<"Enter the position :"; cin >>pos;
                    insertMid(head,pos);
                }
                else if (is==3){
                    insertLast(head);
                }
                break;

            case 2:
                searchphone(head);
                break;

            case 3: { // DELETE BY PHONE 
                if (empty(head)){
                    cout <<"The list is empty !\n";
                    break;
                }
                
                searchphone(head);

                int phone;
                cout << "Enter the phone number to delete: ";
                cin >> phone;

                node pre = NULL;
                node cur = head;
                bool found = false;

                while (cur!=NULL){
                    if (cur->acc.phone==phone){
                        if (pre==NULL){
                            head=head->next;     // xoá đầu
                        } else {
                            pre->next=cur->next; // xoá giữa/cuối
                        }
                        cout <<"Delete record with phone : "<<phone<<" successfully!\n";
                        found=true;
                        break;
                    }
                    pre=cur;
                    cur=cur->next;
                }
                if (!found){
                    cout <<"No customer with that phone found !\n";
                }
                break;
            }

            case 4: { // UPDATE BY PHONE 
                if (empty(head)){
                    cout << "The list is empty!\n";
                    break;
                }
                int phone;
                cout << "Enter the phone number to modify: "; 
                cin>>phone;

                node cur = head;
                bool found = false;
                while (cur != NULL){
                    if (cur->acc.phone == phone){
                        cout << "Customer found! Enter new information:\n";
                        Account acc;
                        cin.ignore();
                        cout <<"Enter new name :"; getline(cin,acc.name);
                        cout <<"Enter new address :"; getline(cin,acc.address);
                        cout <<"Enter new city :"; getline(cin,acc.city);
                        cout <<"Enter new state :"; getline(cin,acc.state);
                        cout <<"Enter new ZIP code :"; cin >> acc.zip;
                        cout <<"Enter new phone number :"; cin >> acc.phone;
                        cout <<"Enter new account balance :"; cin >> acc.balance;
                        cout <<"Enter new date of last payment :"; cin.ignore();
                        getline(cin,acc.lastpayment);

                        cur->acc = acc;
                        cout << "Customer information updated successfully!\n";
                        found = true;
                        break; 
                    }
                    cur = cur->next;
                }
                if (!found){
                    cout << "No customer with that phone number found!\n";
                }
                break;
            }

            case 5:
                inds(head);
                break;

            default :
                cout <<"This option does not exist !";
                goto MENU;
        }

    } while (option !=0);

    return 0;
}
