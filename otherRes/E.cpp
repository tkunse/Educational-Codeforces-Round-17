#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 100005;
const int M = 10150;

struct Node
{
    int x,r,f;
    bool operator < (const Node& p) const {
        return r > p.r;
    }
}s[N];

struct Query
{
    int t,x,y,w;
    bool operator < (const Query &p) const {
        return x == p.x ? t < p.t : x < p.x;
    }
}query[N * 5],tmp[N * 5];

int n,k;
ll ans;
int bit[N];

int lowbit(int x)
{
    return x & (-x);
}

void add(int x,int d)
{
    while(x < M)
    {
        bit[x] += d;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

void clear(int x)
{
    while(x < M)
    {
        bit[x] = 0;
        x += lowbit(x);
    }
}

void cdq(int L,int R)
{
    if(L >= R) return;
    int mid = (L + R) >> 1;
    cdq(L,mid);
    cdq(mid + 1,R);
    int l = L,r = mid + 1,o = L;

    while(l <= mid && r <= R)
    {
        if(query[l] < query[r])
        {
            if(query[l].t == 0)
                add(query[l].y,1);
            tmp[o++] = query[l++];
        }
        else
        {
            if(query[r].t == 1)
                ans += sum(query[r].y) * query[r].w;
            tmp[o++] = query[r++];
        }
    }

    while(l <= mid)
        tmp[o++] = query[l++];

    while(r <= R)
    {
        if(query[r].t == 1)
            ans += sum(query[r].y) * query[r].w;
        tmp[o++] = query[r++];
    }

    for(int i = L;i <= R; ++i)
    {
        if(query[i].t == 0)
            clear(query[i].y);
        query[i] = tmp[i];
    }
}

ll solve()
{
    sort(s,s + n);
    int idx = 0;
    for(int i = 0;i < n; ++i)
    {
        Node &e = s[i];
        int u1 = e.x - e.r,v1 = max(1,e.f - k);
        int u2 = e.x + e.r,v2 = e.f + k;
        query[idx++] = Query{0,e.x,e.f,0};
        query[idx++] = Query{1,u1 - 1,v1 - 1,1};
        query[idx++] = Query{1,u1 - 1,v2,-1};
        query[idx++] = Query{1,u2,v1 - 1,-1};
        query[idx++] = Query{1,u2,v2,1};
    }
    ans = 0;
    cdq(0,idx - 1);
    return ans - n;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n; ++i)
        scanf("%d%d%d",&s[i].x,&s[i].r,&s[i].f);
    printf("%lld\n",solve());
    return 0;
}
