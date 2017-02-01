/*Analysis Requires Calm*/
#include<bits/stdc++.h>
#define T int t; scanf("%d",&t); while(t--)
#define FOR(i,a,n) for(i=a;i<n;i++)
#define FORD(i,a,n) for(i=a;i>=n;i--)
#define FORS(i,a) for(i=0;a[i];i++)
#define si(x) scanf("%d",&x)
#define sc(x) cin>>x
#define sd(x) scanf("%lf",&x)
#define sll(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define prs(x) printf("%d ",x)
#define pc(x) printf("%c",x)
#define pi(x) printf("%d\n",x)
#define pd(x) printf("%lf\n",x)
#define pll(x) printf("%lld\n",x)
#define ps(x) printf("%s\n",x)
#define M 1000000007
#define ll long long
#define mp make_pair
#define all(x) x.begin(),x.end()
#define pb push_back
#define fr first
#define se second
#define in insert
#define er erase
#define pii pair<int, int>
#define plll pair<long long, long long>
#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define INF 1ll<<60
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230
ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n&1) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n&1) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
using namespace std;
// now the def end... start main process

vector<ll> v;
map<ll,int> m;
int main()
{
   ll i,j;
   ll n,k;
   sll(n);
   sll(k);
   for(i=1;i*i<=n;i++)
      if(n%i==0)
      {
         if(!m[i])
            m[i]=1,v.pb(i);
         if(!m[n/i])
            m[n/i]=1,v.pb(n/i);
      }
   sort(all(v));
   if(k>v.size())
      puts("-1");
   else
      pll(v[k-1]);
   return 0;
}
