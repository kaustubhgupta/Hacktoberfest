#include<iostream>
using namespace std;
struct poly
{
int coeff;
int exp;
};
class polynomial
{
struct poly p[20];
public:
int n;
void read();
void display();
polynomial operator +(polynomial);
};
void polynomial::read()
{
int i;
for(i=0;i<n;i++)
{
cout<<"\n Enter the coefficient & exponents:";
cin>>p[i].coeff>>p[i].exp;
}
}
void polynomial::display()
{
for(int i=0;i<n;i++)
{
cout<<p[i].coeff<<" x^ "<<p[i].exp;
if(i!=n-1)
cout<<" + ";
}
cout<<"\n";
}
polynomial polynomial::operator +(polynomial p2)
{
polynomial p3;
int i=0,j=0,k=0;
while((i<n)&&(j<p2.n))
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
else
p3.p[k].coeff=p[i].coeff+p2.p[j].coeff;
p3.p[k].exp=p[i].exp;
i++;
j++;
}
k++;
}
while(i<n)
{
p3.p[k]=p[i];
i++;
k++;
}
while(j<p2.n)
{
p3.p[k]=p2.p[j];
j++;
k++;
}
p3.n=k;
return p3;
}
int main()
{
      polynomial p1,p2,p3;
      cout<<"\n Enter the no of terms in 1st polynomial:";
      cin>>p1.n;
      p1.read();
      cout<<"\n Enter the no of terms in 2nd polynomial:";
      cin>>p2.n;
      p2.read();
      cout<<"\n 1st polynomial is:\n";
      p1.display();
      cout<<"\n 2nd polynomial is:\n";
      p2.display();
      p3=p1+p2;
      cout<<"\n Resultant polynomial is:";
      p3.display();
}
