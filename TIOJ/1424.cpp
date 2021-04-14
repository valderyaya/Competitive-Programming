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
#define lb(x) (x&-x)

priority_queue<ll,vector<ll>,greater<ll>> q;
ll n,m,sum=0,x,y;
int main(){
    oi;
    cin>>n;
    REP(i,n){
        cin>>m;
        q.emplace(m);
    }
    while(q.size()>1){
        x=q.top(),q.pop();
        y=q.top(),q.pop();
        sum+=x+y;
        q.emplace(x+y);
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
