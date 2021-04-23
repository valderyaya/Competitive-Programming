//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,cnt[26];
string s;
bitset<26> vis;
int main(){Rosario
    cin>>n;
    REP(k,n){
        cin>>s;vis.reset();
        for(auto &i:s){
            if(vis[i-'a']) continue;
            vis[i-'a']=1; cnt[i-'a']++;
        }
    }
    bool c=1;
    REP(i,26) if(cnt[i]==n){cout<<char(i+'a')<<"\n";c=0;break;}
    if(c) cout<<"7122\n";
    return 0;
}
