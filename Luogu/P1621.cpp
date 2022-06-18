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
#define wait system("pause");

int a,b,p,pa[100005],n;
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
bool prime[100005];
vector<int> v;
int main(){Rosario
    cin>>a>>b>>p; n=b-a+1;
    REP1(i,a,b) pa[i]=i;
    for(int i=2;i*i<=100000;i++) for(int j=i*i;j<=100000;j+=i) prime[j]=1;
    REP1(i,p,b) if(!prime[i]) v.em(i);
    for(auto &i:v){
        int x=i;
        while(x<a) x+=i;
        while(x+i<=b){
            int w=fin(x),e=fin(x+i);
            if(w!=e) n--,pa[w]=e;
            x+=i;
        }
    }cout<<n<<"\n";
//    system("pause");
    return 0;
}
