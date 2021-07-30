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
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)

int n,m,x,mx=0,mi=0;
int main(){//Rosario
    cin>>n>>m;
    while(m--){
        cin>>x;
        mi=max(mi,min(x,n-x+1));
        mx=max(mx,max(x,n-x+1));
    }
    cout<<mi<<' '<<mx<<"\n";
//    system("pause");
    return 0;
}
