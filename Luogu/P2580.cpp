//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=5e5+5;
int n,m,tr[z][26],tot,ed[z],cnt[z];
void ins(string s){
    int p=0;
    for(auto &i:s){
        if(!tr[p][i-'a']) tr[p][i-'a']=++tot;
        p=tr[p][i-'a'];
    }
    ed[p]=1;
}
int fin(string s){
    int p=0,res=3;
    for(auto &i:s){
        if(tr[p][i-'a']) p=tr[p][i-'a'];
        else break;
    }
    if(ed[p]){
        if(++cnt[p]==1) res=1;
        else res=2;
    }
    return res;
}
signed main(){Rosario
	cin>>n;
    string s;
    while(n--) cin>>s,ins(s);
    cin>>m;
    while(m--){
        cin>>s;
        int x=fin(s);
        if(x==1) cout<<"OK\n";
        else if(x==2) cout<<"REPEAT\n";
        else cout<<"WRONG\n";
    }
    return 0;
}
