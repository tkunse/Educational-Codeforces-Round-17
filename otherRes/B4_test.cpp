// GNU C++ 14
// Learning C++ with real code
// Test: http://codeforces.com/contest/762/problem/B

///////////////////////// only presets (it can be copy to any file to increase your development speed
#include <bits/stdc++.h>

#define mp(a, b) make_pair((a), (b))
#define pb(a) push_back((a))
#define pf(a) push_front((a))
#define rb() pop_back()
#define rf() pop_front()
#define sz(a) ((int)a.size())

using namespace std;

typedef long long lld;                // lld means long long
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;
typedef pair<lld, int> pli;
typedef pair<int, lld> pil;
typedef vector<vector<int>> Matrix;
typedef vector<vector<int>> Adj;
typedef vector<int> Row;
typedef complex<double> Complex;
typedef vector<Complex> Vcomplex;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const lld LINF = 1e18;
const double FINF = 1e15;
const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
///////////////////////// Presets end

int a, b, c;
int n;

int main() {
  scanf("%d %d %d %d", &a, &b, &c, &n);
  vector<pii> v(n);
  for (int i = 0; i < n; ++i) {
    int x;
    char s[10];
    scanf(" %d %s ", &x, s);
    if (s[0] == 'U') { // if the first letter is U (USB)
      v[i] = pii(x, 0);
    } else {
      v[i] = pii(x, 1);
    }
  }
  sort(v.begin(), v.end());
  lld sum = 0;
  int ans = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i].second == 0) {
      if (a > 0) {
        --a;
        ++ans;
        sum += v[i].first;
      } else if (c > 0) {
        --c;
        ++ans;
        sum += v[i].first;
      }
    } else {
      if (b > 0) {
        --b;
        ++ans;
        sum += v[i].first;
      } else if (c > 0) {
        --c;
        ++ans;
        sum += v[i].first;
      }
    }
  }
  printf("%d %lld\n", ans, sum);
}

