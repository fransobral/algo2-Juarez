#include<iostream.h>
#include<conio.h>
#define size 4
class stack
{
     int data[size];
     int top;
public:
     stack()
     {
          top=-1;
     }
     void push();
     void pop();
     void display();
};

void stack::push()
{
     if(top==size-1)
     {
          cout<<"\nStack is full";
          return;
     }
     else
     {
          top++;
          cout<<"Enter Data : ";
          cin>>data[top];
     }
}

void stack::pop()
{
     if(top==-1)
          cout<<"\n Stack is empty";
     else
     {
          cout<<data[top]<<"deleted "<<endl;
          top--;
     }
}

void stack::display()
{
     int t=top;
     while(t>=0)
     {
          cout<<data[t]<<endl;
          t--;
     }
}

void main()
{
     stack st;
     int ch;
     do
     {
          cout<<"\n1. Push\n2. Pop\n3. Display \n4.Quit\nEnter Choice(1-4) ";
          cin>>ch;
          switch(ch)
          {
               case 1: st.push();break;
               case 2: st.pop();break;
               case 3: st.display();
          }
     }while(ch!=4);
}