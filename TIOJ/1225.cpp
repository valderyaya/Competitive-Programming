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
//#define lb(x) (x&(-x)) 

struct q{
    int id,x;
    bool operator < (const q &a) const{
        return x>a.x;
    }
};
int n,l[1000005],r[1000005],a[1000005];
priority_queue<q> qq;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i],l[i]=i-1,r[i]=i+1,qq.emplace(q{i,a[i]});
    ll sum=0;
    while(qq.size()>1){
        q x=qq.top();qq.pop();
        if(l[x.id]==0){sum+=a[r[x.id]];l[r[x.id]]=l[x.id];continue;}
        if(r[x.id]==n+1){sum+=a[l[x.id]];r[l[x.id]]=r[x.id];continue;}
        sum+=min(a[l[x.id]],a[r[x.id]]);
        l[r[x.id]]=l[x.id];
        r[l[x.id]]=r[x.id];
    }cout<<sum<<"\n";
//    system("pause");
    return 0;
}
