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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int t,n;
string s;
bitset<26> vis,on,v[26];
void dfs(int x){
    vis[x]=1;
    REP(i,26) if(v[x][i]&&!vis[i]) dfs(i);
}
signed main(){Aincrad
    cin>>t;
    while(t--){
        cin>>n;
        on.reset();
        vis.reset();
        REP(i,26) v[i].reset();
        while(n--){
            cin>>s;
            on[s[0]-'a']=1;
            for(int i=0;i<s.size()-1;++i){
                on[s[i+1]-'a']=1;
                v[s[i]-'a'][s[i+1]-'a']=1;
                v[s[i+1]-'a'][s[i]-'a']=1;
            }
        }
        int ans=0;
        REP(i,26) if(!vis[i]&&on[i]) ++ans,dfs(i);
        cout<<ans<<"\n";
    }
    return 0;
}
