#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

int n,dep[105]={0,1},fa[105],mxd=0,mxw=0,w[105];
int main(){Rosario
    cin>>n;
    int x,y;
    REP(i,n-1){
        cin>>x>>y;
        fa[y]=x;
        dep[y]=dep[x]+1;
        w[dep[y]]++;
        mxd=max(mxd,dep[y]);
        mxw=max(mxw,w[dep[y]]);
    }
    cin>>x>>y;
    int sum=0;
    while(x!=y){
        if(dep[x]>=dep[y]) sum+=2,x=fa[x];
        else sum++,y=fa[y];
    }
    cout<<mxd<<"\n"<<mxw<<"\n"<<sum<<"\n";
//    wait
    return 0;
}
