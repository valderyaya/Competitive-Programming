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

struct qq{int x,y;}p[5005];
int n;
double d[5005],ans;
double cal(int a,int b){return sqrt((double)(p[a].x-p[b].x)*(p[a].x-p[b].x)+(double)(p[a].y-p[b].y)*(p[a].y-p[b].y));}
bitset<5005> vis;
void prim(){
    d[0]=0;
    double mi,dis;
    int pos;
    REP(i,n){
        mi=1e9;
        REP(j,n) if(!vis[j]&&d[j]<mi) mi=d[j],pos=j;
        vis[pos]=1;ans+=mi;
        REP(j,n) {
            dis=cal(pos,j);
            if(dis<d[j]) d[j]=dis;
        }
    }
}
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>p[i].x>>p[i].y,d[i]=1e9;
    prim();
    cout<<fixed<<setprecision(2)<<ans<<"\n";
//    system("pause");
    return 0;
}
