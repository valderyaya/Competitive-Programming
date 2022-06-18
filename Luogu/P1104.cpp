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

struct qq{
    string s;
    int a,b,c,idx;
    bool operator<(const qq &x)const{
        if(a!=x.a) return a<x.a;
        if(b!=x.b) return b<x.b;
        if(c!=x.c) return c<x.c;
        return idx>x.idx;
    }
}q[102];
int main(){Rosario
    int n;
    cin>>n;
    REP(i,n) cin>>q[i].s>>q[i].a>>q[i].b>>q[i].c,q[i].idx=i;
    sort(q,q+n);
    REP(i,n) cout<<q[i].s<<"\n";
//    wait
    return 0;
}
