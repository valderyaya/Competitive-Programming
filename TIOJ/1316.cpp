//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,a[8900],now=0,cnt=0,l[4500]={},r[4500];
int main(){Rosario
    cin>>n;
    REP1(i,1,n<<1){
        cin>>a[i];
        if(l[a[i]]) r[a[i]]=i;
        else l[a[i]]=i;
    }
    set<int> s;
    REP1(i,1,n<<1){
        if(i==l[a[i]]) s.insert(r[a[i]]),++now;
        else if(i==r[a[i]]){
            auto it=s.find(r[a[i]]);
            if(it!=s.end()) --now,s.erase(it);
        }
        if(now>2){
            ++cnt;
            s.erase(--s.end());
            --now;
        }
    }
    cout<<n-cnt<<"\n";
    return 0;
}
