// GNU C++

#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define ln "\n"
using namespace std;

ll n, k;

int main() {
    #ifdef jfdw
        freopen("data.inp","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    //-------------------------------------------
    cin >> n >> k;
    int h = 0;
    int cnt = 0;
    for (ll i=1LL; i*i<=n; i++) {
        if (n%i==0) {
            cnt++, h++;
            if (i*i!=n) cnt++;
        }
    }
    //cout << k << " " << h << " " << cnt << ln;
    if (k > cnt) cout << "-1\n"; else
    if (k <= h) {
        cnt = 0;
        for (ll i=1LL; i*i<=n; i++) {
            if (n%i==0) {
                cnt++;
                if (cnt == k) { cout << i << ln; break; }
            }
        }
    } else {
        for (ll i=1LL; i*i<=n; i++) {
            if (n%i==0) {
                if (cnt == k) { cout << n/i << ln; break; }
                cnt--;
            }
        }
    }
}
