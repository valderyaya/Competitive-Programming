#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,m,a[1005];
bool c(int x){
    int sum=0,cnt=0;
    REP(i,n){
        if(a[i]>x) return 0;
        if(sum+a[i]>x) sum=a[i],cnt++;
        else sum+=a[i];
    }
    return cnt<=m;
}
int main(){Rosario
    while(cin>>n>>m,n){
        int l=0,r=1000001,m;
        REP(i,n) cin>>a[i];
        while(l<r){
            m=l+r>>1;
            if(c(m)) r=m;
            else l=m+1;
        }cout<<l<<"\n";
    }
//    system("pause");
    return 0;
}
