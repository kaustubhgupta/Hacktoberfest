#include<iostream>
#include<string>
using namespace std;
class stack
{
   private:
   int top;
   int arr[5];
    
public:
    stack()
    {
        top=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }

    }

    bool isEmpty()
    {
       if(top==-1)
           return true;
       else
           return false;
           
    }
    bool isFull()
    {
        if(top==4)
           return true;
        else 
           return false;

    }
    void push(int val) //yes argument no return 
    {
       if(isFull())
       {
           cout<<"Stack Overflow";
       }
       else
       {
          top++;
          arr[top]=val;
       }
       

    }
    int pop() //no argument yes return;
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow";
            return 0;
        }
        else
        {
            int popValue=arr[top];
            arr[top]=0;
            top--;
            return popValue;
        }
        
    }

    void count()
    {
         cout<<top+1;
    }
    int peek(int pos)
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow";
        }
        else
        {
            return arr[pos];
        }
        
    }
    void change(int pos,int val)
    {
        arr[pos]=val;
        
    }
    void display()
    {
        for(int i=4;i>=0;i--)
        {
            cout<<arr[i]<<endl;
        }
    }
    








};
int main()
{   stack s1;
    s1.push(5);
    s1.push(3);
    s1.push(-1);
    s1.push(2);
    s1.pop();
    s1.pop();
  s1.display();
  s1.count();


    
    
    

    return 0;

}
