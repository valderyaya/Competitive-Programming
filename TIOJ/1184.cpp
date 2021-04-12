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
#define pii pair<int,intt>
#define pll pair<ll,ll>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int t,n,m;
struct qq{
    int c,num;
    bool operator<(const qq &x)const{
        return c<x.c;
    }
}q[205];
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n>>m;int sum=0,cnt=0;
        REP(i,n) cin>>q[i].c>>q[i].num,sum+=q[i].num;
        if(sum<m){cout<<"so sad\n";continue;}
        sum=0;sort(q,q+n);
        for(int i=0;i<n&&cnt<m;i++){
            sum+=q[i].c*min(m-cnt,q[i].num);
            cnt+=min(m-cnt,q[i].num);
        }cout<<sum<<"\n";
    }
//    system("pause");
    return 0;
}
