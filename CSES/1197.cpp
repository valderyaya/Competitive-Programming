#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
#define mkp make_pair
 
#define int ll
const int z=2505;
int n,m,dis[z],prv[z];
vector<pii> v[z];
vector<int> ans;
int bell(){
    REP1(i,1,n+1) dis[i]=1e18;
    int f; dis[1]=0;
    REP1(i,1,n+1){
        f=0;
        REP1(j,1,n){
            for(auto &k:v[j]) if(dis[k.F]>dis[j]+k.S){
                dis[k.F]=dis[j]+k.S;
                f=k.F;
                prv[k.F]=j;
            }
        }
        if(!f) return 0;
    }
    return f;
}
signed main(){Rosario
    cin>>n>>m;
    for(int x,y,c;m--;){
        cin>>x>>y>>c;
        v[x].em(y,c);
    }
    int f=bell();
    if(f){
        REP1(i,1,n+1) f=prv[f];
        for(int x=f;;x=prv[x]){
            ans.em(x);
            if(x==f&&ans.size()>1) break;
        }
        reverse(ALL(ans));
        cout<<"YES\n";
        for(auto &j:ans) cout<<j<<' ';
    }else cout<<"NO\n";
}
