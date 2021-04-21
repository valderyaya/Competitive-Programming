//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=6e4+5,inf=1e9;
int cnt,n,m,p=400,a[z],tag[z];
vector<int> ans[z],id[z];
void cal(int x){
    int last=-inf;
    ans[x].resize(n+1,inf);
    REP(i,n)
        if(tag[a[i]]==x) last=i;
        else ans[x][a[i]]=min(ans[x][a[i]],i-last);
    last=inf;
    for(int i=n-1;~i;--i)
        if(tag[a[i]]==x) last=i;
        else ans[x][a[i]]=min(ans[x][a[i]],last-i);
}
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i],id[a[i]].em(i);
    REP1(i,1,n) if(id[i].size()>=p){
        tag[i]=++cnt;
        cal(cnt);
    }
    for(int l,r;m;--m){
        cin>>l>>r;
        if(id[l].empty()||id[r].empty()) cout<<"-1\n";
        else if(l==r) cout<<"0\n";
        else if(id[l].size()<p&&id[r].size()<p){
            int i=0,j=0,la=-inf,lb=-inf,res=inf;
            vector<int> x=id[l],y=id[r];
            while(i<x.size()||j<y.size()){
                if(j==y.size()||(i<x.size()&&x[i]<y[j])){
                    int t=x[i++];
                    res=min(res,t-lb);
                    la=t;
                }else{
                    int t=y[j++];
                    res=min(res,t-la);
                    lb=t;
                }
            }
            cout<<res<<"\n";
        }else{
            if(tag[l]) cout<<ans[tag[l]][r]<<"\n";
            else cout<<ans[tag[r]][l]<<"\n";
        }
    }
    return 0;
}
