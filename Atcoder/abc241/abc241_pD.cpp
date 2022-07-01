#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

#define int ll
multiset<int> s;
int n,opt,x,k;
signed main(){StarBurstStream
    cin>>n;
    while(n--){
        cin>>opt>>x;
        if(opt!=1) cin>>k;
        if(opt==1) s.insert(x);
        else if(opt==2){
            auto it = s.upper_bound(x);
            bool ck=1;
            for(int i=0;i<k;++i) {
                if(it==s.begin()){
                    ck=0;
                    break;
                }
                it=prev(it);
            }
            if(!ck) cout<<"-1\n";
            else cout<<*it<<"\n";
        }else{
            auto it = s.lower_bound(x);
            for(int i=0;it!=s.end()&&i<k-1;++i) it=next(it);
            if(it==s.end()) cout<<"-1\n";
            else cout<<*it<<"\n";
        }
    }
}
