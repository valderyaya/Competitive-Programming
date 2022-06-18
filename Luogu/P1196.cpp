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

const int z=30005;
int n,sum[z],d[z]={},fa[z];
int fin(int x){
    if(x==fa[x]) return x;
    int f=fin(fa[x]);
    d[x]+=d[fa[x]];
    return fa[x]=f;   
}
int main(){Rosario
    REP1(i,1,30000) fa[i]=i,sum[i]=1;
    char c;
    int a,b;
    cin>>n;
    while(n--){
        cin>>c>>a>>b;
        int x=fin(a),y=fin(b);
        if(c=='C') cout<<(x==y?abs(d[a]-d[b])-1:-1)<<"\n";
        else{
            d[x]+=sum[y];
            fa[x]=y;
            sum[y]+=sum[x];
            sum[x]=0;
        }
    }
//    system("pause");
    return 0;
}
