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

int n,x,y,a[10001],b[10001],c[10001],d[10001];
int main(){
    oi;
    bool ck=1;
    cin>>n;
    REP1(i,1,n) cin>>a[i]>>b[i]>>c[i]>>d[i];
    cin>>x>>y;
    for(int i=n;i>0;i--){
        if(a[i]+c[i]>=x&&a[i]<=x&&b[i]<=y&&b[i]+d[i]>=y){
            ck=0;
            cout<<i<<"\n";
            break;
        }
    }
    if(ck) cout<<-1;
//    system("pause");
    return 0;
}
