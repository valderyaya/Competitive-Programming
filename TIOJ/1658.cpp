//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,k;
void pr0(){
    REP(i,n-1)cout<<' ';
    cout<<"*\n";
    for(int i=2,j=n-2,k=1;i<n;++i,--j,k+=2){
        REP(l,j) cout<<' ';
        cout<<'*';
        REP(l,k) cout<<' ';
        cout<<"*\n";
    }
    REP(i,n*2-1) cout<<'*';
    cout<<"\n";
}
void pr1(){
    int len=2*n-1;
    for(int i=0,j=1,k=n-1;i<n;++i,j+=2,--k){
        REP(l,k) cout<<' ';
        REP(l,j) cout<<'*';
        cout<<"\n";
    }
}
int main(){Rosario
    while(cin>>n>>k){
        if(k&1) pr1();
        else pr0();
    }
    return 0;
}
