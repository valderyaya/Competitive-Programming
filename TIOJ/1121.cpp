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

int n,idx;
string str;
struct qq{
    string s;
    int id;
    bool operator<(const qq &x)const{
        return s<x.s;
    }
}a[25];
int main(){Rosario
    while(cin>>n>>str){
        REP(i,n){
            a[i]=qq{str,i+1};
            str.push_back(*str.begin());
            str.erase(str.begin());
        }sort(a,a+n);
        REP(i,n){
            cout<<a[i].s.back();
            if(a[i].id==2) idx=i+1;
        }cout<<"\n"<<idx<<"\n";
    }
    return 0;
}
