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

int n,m,a[500005];
void add(int x,int v){
    for(;x<=n;x+=lb(x)) a[x]+=v;
}
int get(int l,int r){
    --l;int sum1=0,sum2=0;
    for(;l;l-=lb(l)) sum1+=a[l];
    for(;r;r-=lb(r)) sum2+=a[r];
    return sum2-sum1;
}
int main(){Rosario
    cin>>n>>m;
    int x,y,k;
    REP1(i,1,n) cin>>x,add(i,x);
    while(m--){
        cin>>k>>x>>y;
        if(k&1) add(x,y);
        else cout<<get(x,y)<<"\n";
    }
//    system("pause");
    return 0;
}
