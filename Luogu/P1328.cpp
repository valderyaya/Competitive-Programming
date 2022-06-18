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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>

int n,q[200],w[200],a,b,x[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main(){
    //oi;
    cin>>n>>a>>b;
    REP(i,a) cin>>q[i];
    REP(i,b) cin>>w[i];
    int cnt=0,i=0,j=0,cnta=0,cntb=0;
    for(;cnt<n;cnt++,i++,j++){
        if(i>=a) i=0;
        if(j>=b) j=0;
        cnta+=x[q[i]][w[j]];
        cntb+=x[w[j]][q[i]];
    }
    cout<<cnta<<' '<<cntb<<endl;
//    system("pause");
    return 0;
}
