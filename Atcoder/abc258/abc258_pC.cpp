//#pragma GCC optimize("O2")
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
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

int n,q,cur;
string s;
signed main(){StarBurstStream
    cin>>n>>q>>s;
    for(int k,x;q--;){
        cin>>k>>x;
        if(k==1){
            cur=(cur+n-x)%n;
        }else{
            cout<<s[(cur+x-1)%n]<<"\n";
        }
    }
}
