#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

ll n,k,a[1000005],now=0;
vector<ll> mx,mn,v;
int main(){Rosario
    cin>>n>>k;
    REP(i,n) cin>>a[i];
    for(int i=0;i<n;i++){
        while(!mx.empty()&&i-mx.front()>=k) mx.erase(mx.begin());
        while(!mn.empty()&&i-mn.front()>=k) mn.erase(mn.begin());
        while(!mx.empty()&&a[mx.back()]<a[i]) mx.pop_back();
        while(!mn.empty()&&a[mn.back()]>a[i]) mn.pop_back(); 
        mx.em(i),mn.em(i);
        if(i-now==k-1){
            cout<<a[mn.front()]<<' ';now++;
            v.em(a[mx.front()]);
        }
    }cout<<"\n";
    for(ll i:v) cout<<i<<' ';
//    system("pause");
    return 0;
}
