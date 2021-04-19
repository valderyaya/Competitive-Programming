//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m;
struct qwq{
    string s;
    int v;
    bool operator<(const qwq &x)const{
        return s<x.s;
    }
}a[15];
int main(){Rosario
    while(cin>>m>>n){
        if(n==0){
            cout<<"No one\n";
            continue;
        }
        for(int i=0,j=100;i<n;j-=10,++i) cin>>a[i].s,a[i].v=j;
        sort(a,a+n);
        REP(i,n){
            cout<<a[i].s;
            REP(j,m-a[i].s.size()) cout<<' ';
            cout<<"  $"<<a[i].v<<"\n";
        }
    }
    return 0;
}
