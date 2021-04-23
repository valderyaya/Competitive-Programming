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
#define lb(x) (x&-x)

int n,m,x,a[300005]={};
vector<int> v;
int main(){Rosario
    cin>>n>>m;
    REP(i,m) {
        cin>>x;
        for(int i=x;i<=n;i+=x) a[i]=~a[i];
    }
    REP1(i,1,n){
        if(a[i]) v.em(i);
    }cout<<v.size()<<"\n";
    for(int &i:v) cout<<i<<"\n";
//    system("pause");
    return 0;
}
