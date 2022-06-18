#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
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

int t,n,sg[10005];
vector<int> v;
bitset<10005> vis;
void build(){
    REP1(i,1,n){
        vis.reset();
        for(int j:v){
            if(j>i) break;
            vis[i-j]=1;
        }
        for(int j=0;;j++) if(!vis[j]){sg[i]=j;break;}
    }
}
int main(){Rosario
    cin>>t;
    REP1(i,1,10000) v.em(i);
    build();
    while(t--){
        int res=0,x;
        cin>>n;
        while(n--) cin>>x,res^=x;
        cout<<(res?"Yes":"No")<<"\n";
    }
//    system("pause");
    return 0;
}
