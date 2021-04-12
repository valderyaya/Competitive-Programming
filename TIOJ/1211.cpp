#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<long long,long long>
#define mkp make_pair
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define lb(x) (x&(-x)) 

struct q{int a,b,w;}a[1000005];
bool cmp(q x,q y){return x.w<y.w;}
int n,m,p[10005],vis[10005];
vector<int> v[10005];
void dfs(int x){
    vis[x]=1;
    REP(i,v[x].size()){
        if(!vis[v[x][i]]) dfs(v[x][i]);
    }
}
int fin(int x){return x==p[x]?x:p[x]=fin(p[x]);}
int main(){
    oi;
    while(cin>>n>>m,n){
        REP1(i,1,n){ v[i].clear();p[i]=i,vis[i]=0;}
        REP(i,m) {
            cin>>a[i].a>>a[i].b>>a[i].w;
            v[a[i].a].em(a[i].b);v[a[i].b].em(a[i].a);
        }
        dfs(1);
        bool ck=0;
        REP1(i,1,n){
            if(!vis[i]){ck=1;break;}
        }
        if(ck){cout<<-1<<"\n";continue;}
        sort(a,a+m,cmp);
        int sum=0;
        REP(i,m){
            if(fin(a[i].a)!=fin(a[i].b)){
                sum+=a[i].w;
                p[fin(a[i].a)]=fin(a[i].b);
            }
        }
        cout<<sum<<"\n";
    }
//    system("pause");
    return 0;
}
