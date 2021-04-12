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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>

vector<int> v[40001];
int n,m,a,b,col[40001];
inline int ck(int x){
    queue<int> q;
    col[x]=1;q.emplace(x);
    while(q.size()){
        int e=q.front();q.pop();
        for(int u:v[e]){
            if(col[u]==0){col[u]=-col[e];q.emplace(u);}
            if(col[u]==col[e]) return 0;
        }
    }
    return 1;
}
int main(){
    oi;
    while(cin>>n>>m,n){
        REP1(i,1,n){v[i].clear();col[i]=0;}
        while(m--){
            cin>>a>>b;
            v[a].em(b);v[b].em(a);
        }
        bool ok=1;
        REP1(i,1,n){
            if(col[i]==0&&!ck(i)){
                ok=0;break;
            }
        }
        cout<<(ok?"Yes\n":"No\n");
    }
//    system("pause");
    return 0;
}
