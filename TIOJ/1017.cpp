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

int t,a[1000005],n,l[1000005],r[1000005];
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n;
        REP(i,n) cin>>a[i];
        l[0]=a[0],r[n-1]=a[n-1];
        for(int i=1;i<n;i++) 
            l[i]=max(l[i-1],a[i]);
        for(int i=n-2;i>=0;i--) 
            r[i]=min(r[i+1],a[i]);
        int sum=0;
        REP1(i,1,n-2) 
            if(a[i]==l[i]&&a[i]==r[i]) sum++;
        cout<<sum<<"\n";
    }
//    system("pause");
    return 0;
}
