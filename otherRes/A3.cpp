#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int a,b,i;
  set<long long>s;
  cin>>a>>b;

  for(i=1;i*i<=a;i++){
    if(a%i==0){
      s.insert({i,a/i});
    }
  }
  if(s.size()>=b)
    cout<<*next(s.begin(),b-1);
  else
    cout<<"-1";
}
