// GNU C++ 14
// Learning C++ with real code
// Test: http://codeforces.com/contest/762/problem/B

///////////////////////// only presets
#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
typedef pair<int, int> pii;

///////////////////////// Presets end

// initial
int pcU, pcP, pcUP, n, tmp1;

int main() {
  scanf("%d %d %d %d", &pcU, &pcP, &pcUP, &n); // get first line's input to pcU, pcP & pcUP. get second line's input to n.
  vector<pii> priceList(n); // create a vector. format: pair<int,int>. size:n
  for (int i = 0; i < n; i++) {
    char tmp2[4]; // prepare for input #2
    scanf("%d %s",&tmp1,tmp2); // get input
    if (tmp2[0] == 'U') { // if input #2's first char is U (implies USB)
      priceList[i] = pii(tmp1,0); // USB's sign is 0
    } else {
      priceList[i] = pii(tmp1,1); // PS/2's sign is 1
    }
  }
  
  //initial for the progress below
  lld price = 0;
  int equip = 0;
  
  sort(priceList.begin(),priceList.end()); // sort the list, in accordance to the first int of each pair.
  
  for(int i = 0; i < priceList.size(); i++) { // compute the whole list of prices
    if (priceList[i].second == 0) { // if the price is a USB's
      if (pcU > 0) { // if there is still computer with USB port to be equipped.
        pcU--;
        equip++;
        price += priceList[i].first;
      } else if (pcUP > 0) { // if there is still computer with USB and PS/2 ports to be equipped.
        pcUP--;
        equip++;
        price += priceList[i].first;
      }
    } else { // if the price is a PS/2's
      if (pcP > 0) { // if there is still computer with PS/2 port to be equipped.
        pcP--;
        equip++;
        price += priceList[i].first;
      } else if (pcUP > 0) { // if there is still computer with USB and PS/2 ports to be equipped.
        pcUP--;
        equip++;
        price += priceList[i].first;
      }
    }
  }
  
  printf("%d %lld", equip, price); // output the result
  
}
