#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int t,n,m,deg[500005],c[500005];
vector<int> v[500005];

int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(deg,0,sizeof(deg));memset(c,0,sizeof(c));
        REP(i,n) v[i].clear();
        for(int i=0,a,b;i<m;i++){
            cin>>a>>b;deg[a]++,deg[b]++;
            c[min(a,b)]++;
            v[a].em(b),v[b].em(a);
        }
        int a=0,b=0;
        REP(i,n) a=max(a,c[i]);
        priority_queue<pii,vector<pii>,greater<pii>>q;
        REP(i,n) q.emplace(mkp(deg[i],i));
        while(q.size()){
            pii x=q.top();q.pop();
            if(deg[x.S]==0) continue;
            b=max(b,x.F);deg[x.S]=0;
            for(int i:v[x.S]){
                if(deg[i]){
                    deg[i]--;
                    q.emplace(mkp(deg[i],i));
                }
            }
        }cout<<a<<' '<<b<<"\n";
    }
//    system("pause");
    return 0;
}
