#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
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
// #define lb(x) (x&-x)

struct qq{
    int a,b,c;
    bool operator<(const qq &a)const{
        return c>a.c;
    }
}q[100005];
int n,m,p[40005];
int fin(int a){return p[a]==a?a:p[a]=fin(p[a]);}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n<<1) p[i]=i;
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].c;
    sort(q,q+m);
    REP(i,m){
        int a=fin(q[i].a),b=fin(q[i].b);
        if(a==b) return cout<<q[i].c,0;
        p[a]=fin(q[i].b+n);p[b]=fin(q[i].a+n);
    }
    cout<<0;
//    system("pause");
    return 0;
}
