//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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
//#define line cout<<"-------------------------\n";


int n,m,pa[100005];
char col[100005],ch;
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) pa[i]=i,cin>>col[i];
    int a,b;
    REP(i,n-1){
        cin>>a>>b;
        if(col[a]==col[b]) pa[fin(a)]=fin(b);
    }
    while(m--){
        cin>>a>>b>>ch;
        a=fin(a),b=fin(b);
        if(a==b&&col[a]!=ch) putchar('0');
        else putchar('1');
    }
//    system("pause");
    return 0;
}
