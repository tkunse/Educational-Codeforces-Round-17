# GNU C++

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ln "\n"
using namespace std;

int a,b,c,n;
string s;
ll w;
vector<ll> A,B,C;

int main() {
    #ifdef jfdw
        freopen("data.inp","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    //-------------------------------------------
    cin >> a >> b >> c >> n;
    for (int i=0; i<n; i++) {
        cin >> w >> s;
        if (s[0] == 'U') A.pb(w); else B.pb(w);
    }
    int cntA = min((int)A.size(), a);
    int cntB = min((int)B.size(), b);
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i=cntA; i<A.size(); i++) C.pb(A[i]);
    for (int i=cntB; i<B.size(); i++) C.pb(B[i]);

    sort(C.begin(), C.end());
    
    int cntC = min((int)C.size(), c);
    
    ll sA = 0, sB = 0, sC = 0;
    for (int i=0; i<cntA; i++) sA += A[i];
    for (int i=0; i<cntB; i++) sB += B[i];
    for (int i=0; i<cntC; i++) sC += C[i];
    
    cout << cntA + cntB + cntC << " " << sA + sB + sC << ln;
}
