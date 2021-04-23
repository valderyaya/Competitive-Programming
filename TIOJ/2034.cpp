//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&(-x)) 

int n,m,mx=0,mi=1e9;
int main(){//Rosario
    cin>>n;
    REP(i,n){
        cin>>m;
        mx=max(mx,m);
        mi=min(mi,m);
    }cout<<mi<<' '<<mx<<' ';
    cout<<(mx-mi==n-1?"yes\n":"no\n");
//    system("pause");
    return 0;
}
