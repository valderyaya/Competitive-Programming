#include<bits/stdc++.h>
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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,m,b[100005];
inline void add(int k,int v){
    for(int i=k;i<=n;i+=lb(i)) b[i]+=v;
}
inline int get(int l,int r){
    int sum1=0,sum2=0;
    for(int i=l;i;i-=lb(i)) sum1+=b[i];
    for(int i=r;i;i-=lb(i)) sum2+=b[i];
    return sum2-sum1;
}
int main(){
    oi;
    int x,y;
    char c;
    cin>>n>>m;
    while(m--){
        cin>>c>>x>>y;
        if(c=='x'){
            add(x,y);
        }else{
            cout<<get(x-1,y)<<"\n";
        }
    }
//    system("pause");
    return 0;
}
