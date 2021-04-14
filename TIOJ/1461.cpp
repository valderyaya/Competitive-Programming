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
//#define lb(x) (x&-x)

int n,m,x;
string a,b;
int main(){Rosario
    while(cin>>n>>m,n){a="";
        while(n--) cin>>b,a+=b;
        while(m--) cin>>x,cout<<a[x-1];
        cout<<"\n";
    }
//    system("pause");
    return 0;
}
