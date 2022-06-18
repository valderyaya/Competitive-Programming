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
#define wait system("pause");


int n,m,w,sum[101]={};
vector<pii> v[101];
queue<int> q;
bitset<101> vis;
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n){
        cin>>sum[i]>>w;
        if(sum[i]>0) q.emplace(i);
        else sum[i]-=w;
    }
    for(int a,b,c,i=0;i<m;i++) cin>>a>>b>>c,v[a].em(mkp(b,c));
    while(!q.empty()){
        int x=q.front();q.pop();
        if(sum[x]<=0) continue;
        for(auto &i:v[x]){
            sum[i.F]+=i.S*sum[x];
            if(!vis[i.F]) q.emplace(i.F),vis[i.F]=1;
        }
    }
    bool ck=1;
    REP1(i,1,n) {
        if(v[i].empty()){
            if(sum[i]>0) cout<<i<<' '<<sum[i]<<"\n",ck=0;
        }
    }
    if(ck) cout<<"NULL\n";
//    system("pause");
    return 0;
}
