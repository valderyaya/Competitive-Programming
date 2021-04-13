//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,r,cnt,ck=0;
vector<string> v;
bitset<20> vis;
void dfs(string s,int now){
    if(ck) return;
    if(now==r){
        if(++cnt==n+r){cout<<s; ck=1;}
        return;
    }
    for(int i=n-1;i>=0;--i){
        if(!vis[i]){
            vis[i]=1;
            s.push_back(char(i+'0'));
            dfs(s,now+1);
            s.pop_back(); 
            vis[i]=0;
        }
    }
}
int main(){Rosario
    cin>>n>>r; cnt=0;
    string s=""; int now=0;
    dfs(s,now);
    if(!ck) for(int i=0,j=0;j<r;j++,++i) cout<<i;
    return 0;
}
