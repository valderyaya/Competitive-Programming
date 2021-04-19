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
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,t,b[105]={},a[105];
vector<int> v;
inline void add(int x){
    for(;x<=n;x+=lb(x)) b[x]++;
}
inline int get(int x){
    int s=0;
    for(;x;x-=lb(x)) s+=b[x];
    return s;
}
int main(){Rosario
    while(cin>>n){
        t=0;
        memset(b,0,sizeof(b));v.clear();
        REP1(i,1,n) cin>>a[i],v.em(a[i]);
        sort(ALL(v));
        v.resize(unique(ALL(v))-v.begin());
        REP1(i,1,n) a[i]=lower_bound(ALL(v),a[i])-v.begin()+1;
        for(int i=1;i<=n;i++){
            add(a[i]);
            t+=i-get(a[i]);
        }
        cout<<t<<"\n";
    }
//    system("pause");
    return 0;
}
