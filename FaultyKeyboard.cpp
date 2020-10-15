/*
This program is from codevita

*/
#include<bits/stdc++.h>
using namespace std;
int main() {
  string s,t;
  getline(cin,t);
  int v[t.length()];
  memset(v,0,sizeof(v));
  getline(cin,s);
  int slen=s.length();
  int tlen=t.length();
  set<char> se;
  for(auto it=s.begin();it!=s.end();it++) {
    se.insert(*it);
  }
  map<string,int> mp;
  int l=0,r=s.length()-1;
  for(auto i=0;i<slen;i++) {
      
    string te="";
      l=i;
      r=s.length()-i;
      for(auto j=i;j<slen;j++) {
        
          r--;
          te.push_back(s.at(j));
          int rr=1+l+r;
          if(l!=0)
            rr+=(2*te.length());
          mp[te]=rr;
      }
  }
  int ans=0,le=0;
  for(auto i=0;i<tlen;i++) {
    
      string temp(1,t.at(i));
      if(se.find(t.at(i))!=se.end()) {
          if(le==0) {
              ans+=mp[temp];
              le++;
              continue;
          }
          temp=t.substr(i-le,le+1);
          string tt=t.substr(i-le,le);
          ans+=mp[temp]-mp[tt];
          le++;
      }
      else {
          le=0;
      }
  }
  cout<<ans<<"\n";
}
