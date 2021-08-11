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
#define lb(x) (x&-x)
#define wait system("pause");

double h,s1,v,l,k;
int n,st,ed;
int main(){//Rosario
    cin>>h>>s1>>v>>l>>k>>n;
    double mx=sqrt(h/5),mn=sqrt((h-k)/5);
    st=min(n,int(s1-mn*v+l));
    ed=max(0,int(s1-mx*v));
    cout<<st-ed<<"\n";
//    wait
    return 0;
}
