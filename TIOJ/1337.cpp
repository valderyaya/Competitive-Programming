//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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

int n,k;
struct qq{
    vector<int> end;
    int val;
};
map<int,qq> m;
bool ck(int x){
    priority_queue<int> q;
    unordered_map<int,int> mq;
    int now=0,re=k;
    for(auto &i:m){now+=i.S.val;
        for(auto &j:i.S.end) q.emplace(j);
        if(mq.find(i.F)!=mq.end()) now+=mq[i.F];
        while(now>x){
            mq[q.top()]++; q.pop();
            --re, --now;
        }if(re<0) return 0;
    }return 1;
}
int main(){Rosario
    cin>>n>>k;
    int l,r;
    REP(i,n){
        cin>>l>>r;
        m[l].end.em(r);
        m[l].val++; m[r].val--;
    }l=0,r=n-k+1;
    while(r-l>1){
        int mid=l+r>>1;
        if(ck(mid)) r=mid;
        else l=mid;
    }cout<<r<<"\n";
    return 0;
}
