#include<bits/stdc++.h>
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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int cnt=0,ocnt=0,n,m,a[1005],p[1005];
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
int main(){
    //oi;
    int x,y;
    cin>>n>>m;
    REP1(i,1,n) p[i]=i;
    while(m--){
        cin>>x>>y;
        a[x]++,a[y]++;
        p[fin(x)]=fin(y);
    }
    REP1(i,1,n){
        if(i==fin(i)) cnt++;
        if(a[i]&1) ocnt++;
    }
    if((ocnt==0||ocnt==2)&&cnt==1) cout<<1;
    else cout<<(ocnt+1)/2;
//    system("pause");
    return 0;
}
