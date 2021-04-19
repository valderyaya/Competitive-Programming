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
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

ll sum=0,n,st[1000001]={-1},a[1000001],now=0;
int main(){Rosario
    cin>>n;
    REP(i,n-1){
        cin>>a[i];
        while(now>0){
            if(a[st[now]]>a[i]) break;
            now--;
        }
        st[++now]=i;
        REP1(j,1,now){
            sum+=a[st[j]]*(st[j]-st[j-1]);
        }
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
