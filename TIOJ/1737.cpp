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
//#define lb(x) (x&-x)
#define wait system("pause");

const int z=100005;
bitset<z> vis;
int a[z],n,m;
struct qq{
    int v,id;
    bool operator<(const qq &w)const{
        return v>w.v;
    }
};
int l[z],r[z],lst,x,sum=0;
void sub(int w){
    l[w]=l[l[w]];
    r[w]=r[r[w]];
    l[r[w]]=w;
    r[l[w]]=w;
}
priority_queue<qq> q;
int main(){Rosario
    cin>>n>>m>>lst;
    REP1(i,1,n-1){
        cin>>x;
        a[i]=x-lst;
        l[i]=i-1,r[i]=i+1;
        q.emplace(qq{a[i],i});
        lst=x;
    }
    a[0]=a[n]=1e9;
    while(m--){
        while(!q.empty()&&vis[q.top().id]) q.pop();
        x=q.top().id,lst=q.top().v;q.pop();
        sum+=lst;
        vis[l[x]]=vis[r[x]]=1;
        a[x]=a[l[x]]+a[r[x]]-a[x];
        q.emplace(qq{a[x],x});
        sub(x);
    }cout<<sum<<"\n";
//    wait
    return 0;
}
