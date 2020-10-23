#include<bits/stdc++.h>
using namespace std;
/*
Input Format:
The only argument given is character array A.

Output Format:
Return the value of arithmetic expression formed using postfix Notation.
*/
int evalpostfix(vector<string> &A) {
    int n=A.size();
    stack<int>stk;

    for(int i=0;i<n;i++)
    {
        if(A[i]=="+")
        {
            int a=(stk.top());
            stk.pop();
            int b=(stk.top());
            stk.pop();
            int c=a+b;
            stk.push(c);
        }
        else if(A[i]=="-")
        {
            int a=(stk.top());
            stk.pop();
            int b=(stk.top());
            stk.pop();
            int c=a-b;
            stk.push(c);
        }
        else if(A[i]=="*")
        {
            int a=(stk.top());
            stk.pop();
            int b=(stk.top());
            stk.pop();
            int c=a*b;
            stk.push(c);
        }
        else if(A[i]=="/")
        {
            int a=(stk.top());
            stk.pop();
            int b=(stk.top());
            stk.pop();
            int c=a/b;
            stk.push(c);
        }
        else
        {
            stk.push(stoi(A[i]));
        }
    }
    return (stk.top());
}
//driver function
int main()
{
    vector<string>v;
    int n;
    cin>>n; //enter size of vector
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    cout<<evalpostfix(v)<<"\n";
    return 0;
}
/*
input output example:
Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
*/
