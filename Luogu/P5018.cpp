#include<bits/stdc++.h>
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

int w[1000005],ls[1000005],rs[1000005],n,m;
int cnt(int x){
    int ret=0;
    if(~ls[x]) ret+=cnt(ls[x]);
    if(~rs[x]) ret+=cnt(rs[x]);
    return ret+1;
}
void ok(int a,int b){
    if(a==-1&&b==-1) return;
    if(a==-1||b==-1||w[a]!=w[b]){m=0;return;}
    ok(ls[a],rs[b]);ok(rs[a],ls[b]);
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>w[i];
    REP1(i,1,n) cin>>ls[i]>>rs[i];
    int ans=1;
    REP1(i,1,n){
        if(ls[i]!=-1&&rs[i]!=-1&&w[ls[i]]==w[rs[i]]){
            m=1;ok(ls[i],rs[i]);
            if(m) ans=max(ans,cnt(i));
        }
    }cout<<ans<<"\n";
//    system("pause");
    return 0;
}
