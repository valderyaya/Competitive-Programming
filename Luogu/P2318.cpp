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

struct qq{
    int id,t;
    bool operator<(const qq &x)const{return t==x.t?id>x.id:t>x.t;}
};
priority_queue<qq> q;
int m,n,idx=0,cnt[1000005],sum=0,a[1000005],b[1000005];
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,m) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+m);
    int len=unique(b+1,b+1+m)-b-1;
    REP1(i,1,m){
        a[i]=lower_bound(b+1,b+1+len,a[i])-b;
        if(cnt[a[i]]) sum++,cnt[a[i]]++;
        else if(idx<n) idx++,cnt[a[i]]=1;
        else{
            while(cnt[a[q.top().id]]!=q.top().t) q.pop();
            qq x=q.top();q.pop();
            cnt[a[i]]++,cnt[a[x.id]]=0;
        }
        q.emplace(qq{i,cnt[a[i]]});
    }cout<<sum<<"\n";
//    system("pause");
    return 0;
}
