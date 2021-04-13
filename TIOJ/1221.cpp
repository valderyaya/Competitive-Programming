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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e5+5;
map<int,int> mp;
int n,k,ans=0,sz=0,p,nxt[z*5],tmp[z]={},a[z*5];
bool ins[z]={};
int main(){Rosario
    cin>>n>>k>>p;
    REP1(i,1,p) cin>>a[i],nxt[i]=p+i;
    REP1(i,1,p){
        if(tmp[a[i]]) nxt[tmp[a[i]]]=i;
        tmp[a[i]]=i;
    }
    REP1(i,1,p){
        if(!ins[a[i]]){
            if(sz==k){
                --sz; ins[mp.rbegin()->S]=0;
                mp.erase(mp.rbegin()->F);
            } ++ans; ++sz;
            mp[nxt[i]]=a[i]; ins[a[i]]=1;
        }
        if(mp.find(i)==mp.end()) continue;
        mp.erase(i); mp[nxt[i]]=a[i];
    }cout<<ans<<"\n";
    return 0;
}
