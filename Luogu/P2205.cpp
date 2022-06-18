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

const int z=1e5+5;
int n,m,cnt,now;
struct qq{
    int x,v;
    bool operator<(const qq &a)const{return x<a.x;}
};
vector<qq> v;
int main(){Rosario
    cin>>n>>m;
    int val; char c;
    while(n--){
        cin>>val>>c;
        if(c=='L'){
            v.em(qq{now,-1});
            v.em(qq{now-val,1});
            now-=val;
        }else{
            v.em(qq{now,1});
            v.em(qq{now+val,-1});
            now+=val;
        }
    }
    sort(ALL(v));
    now=v[0].v;
    for(int i=1;i<v.size();++i){
        if(now>=m) cnt+=v[i].x-v[i-1].x;
        now+=v[i].v;
    }
    cout<<cnt<<"\n";
    return 0;
}
