//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long


const int z = 5e3+5;
int n, m, L[z], R[z], P[z], ind, a[z << 1], fa[z << 1];
int fin(int x){return fa[x]==x?x:fa[x]=fin(fa[x]);}
void un(int x,int y){
    x=fin(x), y=fin(y);
    if(x==y) return;
    fa[x]=y;
}
string s;
signed main(){StarBurstStream
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>L[i]>>R[i]>>s; --L[i];
        a[++ind] = L[i];
        a[++ind] = R[i];
        P[i] = s[0] == 'o' ? 1 : 0;
    }
    sort(a + 1, a + 1 + ind);
    ind = unique(a + 1, a + 1 + ind) - a - 1;
    for(int i = 1; i <= ind + ind; ++i) fa[i] = i;
    for(int x, y, i = 1; i <= m; ++i){
        x = lower_bound(a + 1, a + 1 + ind, L[i]) - a;
        y = lower_bound(a + 1, a + 1 + ind, R[i]) - a;
        if(P[i]){
            if(fin(x) == fin(y) || fin(x + ind) == fin(y + ind)) return cout<<i-1, 0;
            un(x, y+ind);
            un(x+ind, y);
        }else{
            if(fin(x) == fin(y + ind) || fin(x + ind) == fin(y)) return cout<<i-1, 0;
            un(x, y);
            un(x+ind, y+ind);
        }
    }
    cout<<m<<"\n";
    return 0;
}
