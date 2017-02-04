// GNU C++ 14
// Learning C++ with real code
// Test: http://codeforces.com/contest/762/problem/B

///////////////////////// only presets
#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef pair<int, int> pii;

///////////////////////// Presets end

int pcU, pcP, pcUP, n, tmp1;

int main() {
  scanf("%d %d %d %d", &pcU, &pcP, &pcUP, &n);
  vector<pii> priceList(n);
  for (int i = 0; i < n; i++) {
    char tmp2[4];
    scanf("%d %s",&tmp1,tmp2);
    if (tmp2[0] == 'U') {
      priceList[i] = pii(tmp1,0);
    } else {
      priceList[i] = pii(tmp1,1);
    }
  }
  
  lld price = 0;
  int equip = 0;
  
  sort(priceList.begin(),priceList.end());
  
  for(int i = 0; i < priceList.size(); i++) {
    if (priceList[i].second == 0) {
      if (pcU > 0) {
        pcU--;
        equip++;
        price += priceList[i].first;
      } else if (pcUP > 0) {
        pcUP--;
        equip++;
        price += priceList[i].first;
      }
    } else {
      if (pcP > 0) {
        pcP--;
        equip++;
        price += priceList[i].first;
      } else if (pcUP > 0) {
        pcUP--;
        equip++;
        price += priceList[i].first;
      }
    }
  }
  
  printf("%d %lld", equip, price);
  
}
