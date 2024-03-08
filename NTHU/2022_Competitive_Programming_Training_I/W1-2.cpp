#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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

int n,ans;
void print(int x,int c){
    if(c>n) return;
    print(x/2,c+1);
    cout<<(x&1);
}
signed main(){StarBurstStream
    cin>>n;
    int N=1<<n;
    for(int i=1;i<=N;++i){
        print(ans,1); cout<<"\n";
        if(i&1) ans^=1;
        else{
            for(int j=0;j<32;++j) if(ans>>j&1) {ans^=(1<<(j+1));break;}
        }
    }
}
