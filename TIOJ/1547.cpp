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

int a[35]={1,1},n,now=1;
int main(){
    //oi;
    cin>>n;
    if(n>1){
        for(int i=2;i<=n;i++) a[i]=a[i-1]+a[i-2];
    }
    REP1(i,1,n){
        REP(j,a[i]) cout<<now++%3;
        cout<<"\n";
    }
//    system("pause");
    return 0;
}
