//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)


int n,ans=0;
bitset<100000001> is;
vector<int> p;
int main(){Rosario
    cin>>n;

    for(int i=2;i<=n;++i){
        if(!is[i])
            p.push_back(i);
        for(auto &j:p){
            if(i*j>n) break;
            is[i*j]=1;
            if(i%j==0) break;
        }
    }
    for(int i=2;i<=n;i++) ans+=!is[i];
    cout<<ans<<"\n";
    return 0;
}
