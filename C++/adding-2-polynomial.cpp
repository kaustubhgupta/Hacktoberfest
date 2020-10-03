#include<iostream>
using namespace std;
class c
{
public:
int coeff;
int exp;
};
class poly
{
c p[20];
public:
int n;
void read();
void display();
poly operator +(poly);
};
void poly::read()
{
 cout<<"enter n :";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cout<<"enter coeff & expo\n";
  cin>>p[i].coeff>>p[i].exp;
 }
}
void poly::display()
{ 
 for(int i=0;i<n;i++)
 {
  cout<<p[i].coeff<<"x^"<<p[i].exp;
  if(i!=n-1)
  cout<<"+";
 }
 cout<<"\n";
}
poly poly::operator+(poly p2)
{
 poly p3;
 int i=0,j=0,k=0;
 p3.n=0;
 while(i<n && j<p2.n)
 {
  if(p[i].exp>p2.p[j].exp)
  {
   p3.p[k]=p[i];
   i++;
  }
  else if(p[i].exp<p2.p[j].exp)
  {
   p3.p[k]=p2.p[j];
   j++;
  }
  else{
  p3.p[k].coeff=p2.p[j].coeff+p[i].coeff;
  p3.p[k].exp=p[i].exp;
  i++;j++;
  }
  k++;
 }
 while(i<n)
 {
  p3.p[k]=p[i];
  i++;k++;
 }
 while(i<p2.n)
 {
  p3.p[k]=p2.p[i];
  j++;k++;
 }
p3.n=k;
return p3;
}
int main()
{
 poly p1,p2,p3;
 p1.read();
 p2.read();
 p3=p1+p2;
 p3.display();
 return 0;
}
