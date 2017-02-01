// GNU C++ 14

#include<bits/stdc++.h>

using namespace std;

const int n_ = 1e5 + 10, inf = 1e6;
char a[n_], b[n_];

int n, m;
vector<vector<int> >pos;
int maxS[n_], minS[n_];
bool cumCanL[n_], cumCanR[n_];

bool can (int remLen) {
	for (int i = 0; i <= m - remLen; i++) {
		if ((!i || cumCanL[i - 1]) && (i + remLen == m || cumCanR[i + remLen]) &&
				(!i || i + remLen == m || minS[i - 1] < maxS[i + remLen]))
			return true;
	}
	return false;
}

void solve (int remLen) {
	for (int i = 0; i <= m - remLen; i++) {
			if ((!i || cumCanL[i - 1]) && (i + remLen == m || cumCanR[i + remLen]) &&
					(!i || i + remLen == m || minS[i - 1] < maxS[i + remLen])) {
				for (int k = 0; k < i; k++) printf("%c", b[k]);
				for (int k = i + remLen; k < m; k++) printf("%c", b[k]);
				printf("\n");
				return ;
			}
		}
}
int main () {
	scanf("%s %s", &a, &b);
	n = strlen(a), m = strlen(b);
	pos.assign(26, vector<int>());

	for (int i = 0; i < 26; i++)
		pos[i].push_back(- 1);

	for (int i = 0; i < n; i++)
		pos[a[i] - 'a'].push_back(i);

	for (int i = 0; i < 26; i++)
			pos[i].push_back(inf);


	maxS[m - 1] = pos[b[m - 1] - 'a'][(int)pos[b[m - 1] - 'a'].size() - 2];
	for (int i = m - 2; i >= 0; i--) {
		int c = b[i] - 'a';
		int lo = 0, hi = (int)pos[c].size() - 1, best = pos[c][0];
		for (int cnt = 0; cnt <= 20; cnt++) {
			int mid = lo + hi >> 1;
			if (pos[c][mid] < maxS[i + 1]) best = max(best, pos[c][mid]), lo = min (hi, mid + 1);
			else hi = max(lo, mid - 1);
		}
		maxS[i] = (maxS[i + 1] == - 1 || best >= maxS[i + 1] ? - 1 : best);
	}

	minS[0] = pos[b[0] - 'a'][1];
	for (int i = 1; i < m; i++) {
		int c = b[i] - 'a';
		int lo = 0, hi = (int)pos[c].size() - 1, best = pos[c][hi];
		for (int cnt = 0; cnt <= 20; cnt++) {
			int mid = lo + hi >> 1;
			if (pos[c][mid] > minS[i - 1]) best = min (best, pos[c][mid]), hi = max(lo, mid - 1);
			else lo = min (hi, mid + 1);
		}
		minS[i] = (minS[i - 1] == inf || best <= minS[i - 1] ? inf : best) ;
	}

	cumCanL[0] = minS[0] != inf;
	for (int i = 1; i < m; i++) cumCanL[i] = cumCanL[i - 1] && minS[i] != inf;
	cumCanR[m - 1] = maxS[m - 1] != - 1;
	for (int i = m - 2; i >= 0; i--) cumCanR[i] = cumCanR[i + 1] && maxS[i] != - 1;

	int lo = 0, hi = m, best = m;
	for (int cnt = 0; cnt <= 20; cnt ++) {
		int mid = lo + ((hi - lo) >> 1);
		if (can(mid)) best = min(best, mid), hi = max (lo, mid - 1);
		else lo = min(hi, mid + 1);
	}

	if (best == m) printf("-\n");
	else {
		solve(best);
	}
}
