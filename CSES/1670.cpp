//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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
 
int hs(int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9){
    return x1*100000000+x2*10000000+x3*1000000+x4*100000+x5*10000+x6*1000+x7*100+x8*10+x9;
}
queue<pii> q;
unordered_set<int> s;
signed main(){StarBurstStream
    int n=0,x,y;
    REP(i,9) cin>>x,n=n*10+x;
    if(n==123456789) return cout<<0,0;
    q.emplace(mkp(123456789,0));
    s.insert(123456789);
    while(!q.empty()){
        tie(x,y)=q.front(); q.pop();
        int x9=x%10; x/=10;
        int x8=x%10; x/=10;
        int x7=x%10; x/=10;
        int x6=x%10; x/=10;
        int x5=x%10; x/=10;
        int x4=x%10; x/=10;
        int x3=x%10; x/=10;
        int x2=x%10; x/=10;
        int x1=x%10;
        int h1=hs(x2,x1,x3,x4,x5,x6,x7,x8,x9);
        int h2=hs(x1,x3,x2,x4,x5,x6,x7,x8,x9);
        int h3=hs(x1,x2,x3,x5,x4,x6,x7,x8,x9);
        int h4=hs(x1,x2,x3,x4,x6,x5,x7,x8,x9);
        int h5=hs(x1,x2,x3,x4,x5,x6,x8,x7,x9);
        int h6=hs(x1,x2,x3,x4,x5,x6,x7,x9,x8);
        int h7=hs(x4,x2,x3,x1,x5,x6,x7,x8,x9);
        int h8=hs(x1,x2,x3,x7,x5,x6,x4,x8,x9);
        int h9=hs(x1,x5,x3,x4,x2,x6,x7,x8,x9);
        int h10=hs(x1,x2,x3,x4,x8,x6,x7,x5,x9);
        int h11=hs(x1,x2,x6,x4,x5,x3,x7,x8,x9);
        int h12=hs(x1,x2,x3,x4,x5,x9,x7,x8,x6);
        if(!s.count(h1)){
            if(h1==n) return cout<<y+1,0;
            q.emplace(mkp(h1,y+1));
            s.insert(h1);
        }
        if(!s.count(h2)){
            if(h2==n) return cout<<y+1,0;
            q.emplace(mkp(h2,y+1));
            s.insert(h2);
        }
        if(!s.count(h3)){
            if(h3==n) return cout<<y+1,0;
            q.emplace(mkp(h3,y+1));
            s.insert(h3);
        }
        if(!s.count(h4)){
            if(h4==n) return cout<<y+1,0;
            q.emplace(mkp(h4,y+1));
            s.insert(h4);
        }
        if(!s.count(h5)){
            if(h5==n) return cout<<y+1,0;
            q.emplace(mkp(h5,y+1));
            s.insert(h5);
        }
        if(!s.count(h6)){
            if(h6==n) return cout<<y+1,0;
            q.emplace(mkp(h6,y+1));
            s.insert(h6);
        }
        if(!s.count(h7)){
            if(h7==n) return cout<<y+1,0;
            q.emplace(mkp(h7,y+1));
            s.insert(h7);
        }
        if(!s.count(h8)){
            if(h8==n) return cout<<y+1,0;
            q.emplace(mkp(h8,y+1));
            s.insert(h8);
        }
        if(!s.count(h9)){
            if(h9==n) return cout<<y+1,0;
            q.emplace(mkp(h9,y+1));
            s.insert(h9);
        }
        if(!s.count(h10)){
            if(h10==n) return cout<<y+1,0;
            q.emplace(mkp(h10,y+1));
            s.insert(h10);
        }
        if(!s.count(h11)){
            if(h11==n) return cout<<y+1,0;
            q.emplace(mkp(h11,y+1));
            s.insert(h11);
        }
        if(!s.count(h12)){
            if(h12==n) return cout<<y+1,0;
            q.emplace(mkp(h12,y+1));
            s.insert(h12);
        }
    }
}
