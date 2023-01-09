#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
 
vector<int> v;
int a[200005],n,cnt[200005],tot,tt,ans;
void add(int x){
    if(++cnt[x]==1) ++tot;
    if(cnt[x]==2) ++tt;
}
void del(int x){
    if(--cnt[x]==0) --tot;
    if(cnt[x]==1) --tt;
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i],v.em(a[i]);
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    REP1(i,1,n) a[i]=upper_bound(ALL(v),a[i])-v.begin();
    for(int l=1,r=0;r<n;){
        add(a[++r]);
        while(tt){
            del(a[l++]);
        }
        ans=max(ans,tot);
    }
    cout<<ans<<"\n";
    return 0;
}
