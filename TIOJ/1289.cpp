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

int n,x[2005],cnt;
ll a,b,c;
int main(){Rosario
    while(cin>>n){cnt=0;
        REP(i,n) cin>>x[i];
        sort(x,x+n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++){
                    a=x[i]*x[i],b=x[j]*x[j],c=x[k]*x[k];
                    if(a+b==c) ++cnt;
                    if(a+b<c) break;
                }
        cout<<cnt<<"\n";
    }
//    system("pause");
    return 0;
}
