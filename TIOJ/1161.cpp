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

int t,n,m,ans;
pii a[1000005];
int main(){
    Rosario
    cin>>t;
    while(t--){
        cin>>n>>m;ans=1e9;
        REP(i,n) cin>>a[i].F>>a[i].S;
        sort(a,a+n);
        priority_queue<int> q;
        for(int i=0;i<n;){
            int j;
            for(j=i;j<n&&a[i].F==a[j].F;j++){
                q.emplace(a[j].S);
                if(q.size()>m) q.pop();
            }
            i=j;
            if(i>=m) ans=min(ans,a[i-1].F+q.top());
        }
        cout<<ans<<"\n";
    }
//    system("pause");
    return 0;
}
