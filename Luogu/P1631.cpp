#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

priority_queue<int,vector<int>,greater<int> > q;
int n,a[100001],b[100001];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    REP(i,n) for(int j=0;i*j<=n&&j<n;j++) q.emplace(a[i]+b[j]);
    while(n--) cout<<q.top()<<' ',q.pop();
//    wait
    return 0;
}
