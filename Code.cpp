#include<bits/stdc++.h>
using namespace std;
struct Bank
{
string name;
int acc_number;
float balance;
stack<long int> trans_history;
};




struct listnode
{
Bank* obj;
listnode* next;
listnode* head;
};



listnode* lst=new listnode();



void insert(listnode* lst,Bank* b)
{
if(lst->head==NULL)
{

  lst->next=NULL;
lst->obj=b;
lst->head=lst;
}
else
 {
 
  listnode* ptr=lst->head;
  while(ptr->next!=NULL)
    ptr=ptr->next;
  listnode* l=new listnode();
  l->obj=b;
  l->next=NULL;
  l->head=NULL;
  ptr->next=l;

 }
}




void createacc(listnode* lst)
{
Bank* b=new Bank();
cout<<"Enter Name"<<endl;
string n;
cin>>n;
b->name=n;
cout<<"Enter Account No."<<endl;
int numm;
cin>>numm;
b->acc_number=numm;
b->balance=1000.0;
stack<long int> st;
st.push(b->balance);
b->trans_history=st;

insert(lst,b);
}




void printbankdetails()
{
cout<<"Enter Account No.";
int num;
cin>>num;
listnode* ptr=lst;
while(ptr!=NULL)
{
      Bank* cust=ptr->obj;

if(cust->acc_number==num)
{
cout<<cust->name<<endl;
cout<<cust->balance<<endl;
stack<long int> s=cust->trans_history;
cout<<"---Transaction history---"<<endl;
while(!s.empty())
{
long int stt=s.top();
if(stt<0)
 cout<<"Amount Debited : "<<(stt*-1)<<endl;
else
cout<<"Amount Credited"<<stt<<endl;
s.pop();
}
cout<<endl;
break;
}
ptr=ptr->next;
}
if(ptr==NULL)
 cout<<"Account doesn't exist"<<endl;

}



void withdraw()
{
cout<<"Enter Account No."<<endl;
int acc;
cin>>acc;
listnode* ptr=lst;
int flag=1;
while(ptr!=NULL)
{
      Bank* cust=ptr->obj;

if(cust->acc_number==acc)
{
flag=0;
   cout<<"Enter Amount to Withdraw"<<endl;
   int amt;
   cin>>amt;
   if(cust->balance<amt)
      cout<<"No Enough Balance"<<endl;
   else
   {

   cust->balance-=amt;
   cust->trans_history.push((amt*-1));
}
   break;
}
ptr=ptr->next;
}
if(flag)
 cout<<"Account doesn't exist"<<endl;

}



void deposit()
{
cout<<"Enter Account No."<<endl;
int acc;
cin>>acc;
listnode* ptr=lst;
while(ptr!=NULL)
{
      Bank* cust=ptr->obj;

if(cust->acc_number==acc)
{

   cout<<"Amount to deposit"<<endl;
   int amt;
   cin>>amt;
   cust->balance+=amt;
   cust->trans_history.push(amt);
   break;
}
ptr=ptr->next;
}
if(ptr==NULL)
 cout<<"Account doesn't exist"<<endl;
}




void transfer()
{
cout<<"Enter Account No."<<endl;
int acc;
cin>>acc;
listnode* ptr=lst;
while(ptr!=NULL)
{
      Bank* cust=ptr->obj;

if(cust->acc_number==acc)
{
   cout<<"Account number to transfer";
   int a;
   cin>>a;
    listnode* p=lst;
   while(p!=NULL)
    {
      Bank* cust2=p->obj;
if(cust2->acc_number==a)
{

cout<<"Enter Amount"<<endl;
int amt;
cin>>amt;
if(cust->balance<amt)
 cout<<"Not Enough Balance"<<endl;
else
{
cust->balance-=amt;
cust2->balance+=amt;

   cust2->trans_history.push(amt);
 
   cust->trans_history.push(amt*-1);}
   
break;
}
p=p->next;
}  
}
ptr=ptr->next;
}
if(ptr==NULL)
 cout<<"Account doesn't exist"<<endl;
}


void remove(listnode* lst)
{

listnode* ptr=lst->head;
cout<<"Enter Account No."<<endl;
int acc;
cin>>acc;
listnode* prev=NULL;
while(ptr!=NULL)
{
Bank* b=new Bank();
b=ptr->obj;
if(b->acc_number==acc)
   break;
prev=ptr;
ptr=ptr->next;
}
if(prev!=NULL)
 prev->next=ptr->next;
}

void alcustomersdetails(listnode* lst)
{
listnode* ptr=lst->head;
while(ptr!=NULL)
{
Bank* cust=ptr->obj;
cout<<cust->name<<endl;
cout<<cust->balance<<endl;
stack<long int> s=cust->trans_history;
cout<<"---Transaction history---"<<endl;
while(!s.empty())
{
long int stt=s.top();
if(stt<0)
 cout<<"Amount Debited : "<<(stt*-1)<<endl;
else
cout<<"Amount Credited"<<stt<<endl;
s.pop();
}
cout<<endl;
cout<<endl;
ptr=ptr->next;
}
}


void print(queue<string> q)
{
queue<string> p;
p=q;
cout<<endl;
while(!p.empty()){
  cout<<p.front()<<endl;
  p.pop();
}
}
int main()
{
queue<string> q;
lst->head=NULL;
lst->next=NULL;
int temp=0;
do{
 cout<<"Select any operation!"<<endl;
 cout<<"1. Account Creation"<<endl;
 cout<<"2. Deposit"<<endl;
 cout<<"3. Withdraw"<<endl;
 cout<<"4. Transfer Money"<<endl;
      cout<<"5. Service Requests"<<endl;
      cout<<"6. Print Your Account Details"<<endl;
      cout<<"7. Print All Customers Details"<<endl;
      cout<<"8. Remove Account"<<endl;
 cout<<"9. End "<<endl;
 int k;
 cin>>k;
switch(k)
{
case 1:if(1)
    {
    temp++;
   createacc(lst);
   q.push("Account Created");
cout<<"Account has been initially credited with bonus 1000"<<endl;
}
       break;
case 2:
if(temp>=1){
   deposit();
q.push("Amount Deposited");}
else
{
cout<<"Input not valid"<<endl;
}
   break;
case 3:
if(temp>=1)
{

   withdraw();
   q.push("amount withdrawn");
}else
cout<<"Input not valid"<<endl;
   break;
case 4:
if(temp>=2)
{
   transfer();
   q.push("Amount Transferred");}
   else
    cout<<"Input not valid"<<endl;
     break;
case 5:
if(temp>=1)
   print(q);
else
    cout<<"Input not valid"<<endl;
break;
        case 6:
 if(temp>=1)
{
   printbankdetails();
               q.push("Account Details Displayed");}
               else
                cout<<"Input not valid"<<endl;
      break;
case 7:
if(temp>=1)
alcustomersdetails(lst);
else
cout<<"Input not valid"<<endl;
      break;
   case 8:
 if(temp>=1)
 {
  temp--;
   remove(lst);}
   else
   {
    cout<<"Input not valid"<<endl;
}
break;
case 9:exit(0);
default:
cout<<"Enter valid option"<<endl;
 }

}while(1);


}