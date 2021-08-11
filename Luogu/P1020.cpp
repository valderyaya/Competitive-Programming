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

vector<int> a,b,c;
int n,m;
int main(){Rosario
    while(cin>>n) a.em(n);
    REP(i,a.size()){
        if(b.size()&&b.back()<a[i]) b[upper_bound(ALL(b),a[i],greater<int>())-b.begin()]=a[i];
        else b.em(a[i]);
        if(c.size()&&c.back()>=a[i]) c[lower_bound(ALL(c),a[i])-c.begin()]=a[i];
        else c.em(a[i]);
    }
    cout<<b.size()<<'\n'<<c.size()<<"\n";
//    system("pause");
    return 0;
}
