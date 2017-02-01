// GNU C++ 11

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define one first
#define two second
#define pb push_back
#define mp make_pair
#define isize(A) int(A.size())
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define pii pair<int, int>
#define fi(I, S, N) for (int I = S; I < N; ++I)
#define fin(I, S, N) for (int I = S; I <= N; ++I)
#define rfi(I, S, N) for (int I = N - 1; I >= S; --I)
#define rfin(I, S, N) for (int I = N; I >= S; --I)

const int MAXN = 2e5;

vector<pll> pr, suf;
vector<ll> ans;

int main() {
    ios_base::sync_with_stdio(0);

    //freopen("in.txt", "r", stdin);

    string a, b;
    cin >> a >> b;

    ll n = isize(a), m = isize(b);
    pr.resize(m);
    suf.resize(m);

    int i = 0, j = 0;

    while (i < n && j < m) {
        while (i < n && a[i] != b[j]) {
            ++i;
        }

        if (i < n) {
            pr[j].one = j + 1;
            pr[j].two = i;
        }

        ++i;
        ++j;
    }

    i = n - 1, j = m - 1;

    while (i >= 0 && j >= 0) {
        while (i >= 0 && a[i] != b[j]) {
            --i;
        }

        if (i >= 0) {
            suf[j].one = m - j;
            suf[j].two = i;
        }

        --i;
        --j;
    }

    i = m - 1;

    while (i >= 0 && pr[i].one == 0) {
        --i;
    }

    j = 0;

    while (j < m && suf[j].one == 0) {
        ++j;
    }

    if (i >= j) {
        j = i + 1;
    }

    /*for (auto h : pr) {
        cout << h.one << " " << h.two << endl;
    }
    cout << "-----------------\n";

    for (auto h : suf) {
        cout << h.one << " " << h.two << endl;
    }
    cout << "-----------------\n";

    cout << i << " " << j << endl;*/

    if (i < 0 && j >= m) {
        cout << "-\n";
    } else if (i < 0) {
        //cout << j << " " << m - j << endl;
        cout << b.substr(j, m - j) << "\n";
    } else if (j >= m) {
        cout << b.substr(0, i + 1) << "\n";
    } else {
        int ii = 0, jj = j;
        ll max_ = suf[jj].one, pos_i = -1, pos_j = jj;

        /*for (auto h : pr) {
            cout << h.one << " " << h.two << endl;
        }
        cout << "-----------------\n";

        for (auto h : suf) {
            cout << h.one << " " << h.two << endl;
        }
        cout << "-----------------\n";

        cout << i << " " << j << endl;*/

        while (ii <= i && jj < m) {
            while (pr[ii].two < suf[jj].two && ii <= i) {
                ll cur = pr[ii].one + suf[jj].one;

                if (cur > max_) {
                    max_ = cur;
                    pos_i = ii;
                    pos_j = jj;
                }

                ++ii;
            }

            ++jj;
        }

        ll cur = pr[i].one;
        if (cur > max_) {
            max_ = cur;
            pos_i = i;
            pos_j = m + 1;
        }

        //cout << max_ << " " << pos_i << " " << pos_j << endl;

        fin(h, 0, pos_i) {
            int pow = pr[h].two;
            cout << a[pow];
        }

        fi(h, pos_j, m) {
            int pow = suf[h].two;
            cout << a[pow];
        }
    }

    return 0;
}
