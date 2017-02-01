// GNU C++

/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define endl "\n"
#define inf 1<<30
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define ss stringstream
#define ll long long int
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define bit_cnt(mask) __builtin_popcount(mask)
using namespace std;
#define MOD 1000000007
ll bigmod(ll n, ll r)
{
    if(r==0) return 1;
    if(r==1) return n;
    if(r%2==0)
    {
        ll ret = bigmod(n, r/2);
        return ((ret%MOD) * (ret%MOD)) % MOD;
    }
    else return ((n%MOD) * (bigmod(n,r-1)%MOD)) % MOD;
}
ll modinverse(ll a){return bigmod(a,MOD-2)%MOD;}
ll lcm(ll a, ll b) {a=abs(a); b=abs(b); return (a/__gcd(a,b))*b;}
ll gcd(ll a, ll b) {a=abs(a); b=abs(b); if(!b) return a; return __gcd(b,a%b);}
#define MAX 100005

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    cin>>a>>b>>c;
    int m; cin>>m;
    vector<int>v1,v2;
    while(m--){
        int val;
        string s;
        cin>>val>>s;
        if(s=="USB") v1.pb(val);
        else v2.pb(val);
    }
    sort(all(v1));
    sort(all(v2));
    int sz1 = v1.size();
    int mn1 = min(sz1, a);
    a -= mn1;
    int sz2 = v2.size();
    int mn2 = min(sz2, b);
    b -= mn2;
    int ans = mn1 + mn2;
    ll cost=0;
    for(int i=0; i<mn1; i++){
        cost += v1[i];
    }
    for(int i=0; i<mn2; i++){
        cost += v2[i];
    }
    vector<int>v;
    for(int i=mn1; i<v1.size(); i++){
        v.pb(v1[i]);
    }
    for(int i=mn2; i<v2.size(); i++){
        v.pb(v2[i]);
    }
    sort(all(v));
    int sz = v.size();
    int mn3 = min(sz, c);
    for(int i=0; i<mn3; i++){
        cost += v[i];
    }
    ans += mn3;
    cout<<ans<<" "<<cost<<endl;
    return 0;
}
