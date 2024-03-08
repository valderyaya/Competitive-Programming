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

const int z=1e5+5;
char val[z];
int nxt[z],cnt,head,tail,now;
string s;
void ins(int x,char c){
    int p=nxt[x];
    nxt[x] = ++cnt;
    nxt[cnt] = p;
    val[cnt] = c;
    now = cnt;
    if(x==tail) tail = cnt;
}
signed main(){StarBurstStream
    while(getline(cin,s)){
        cnt=now=tail=head=0,nxt[0]=-1; 
        for(auto &i:s){
            if(i=='[') now = head;
            else if(i==']') now = tail;
            else ins(now, i);
        }
        for(int i=nxt[head];i!=-1;i=nxt[i]) cout<<val[i];
        cout<<"\n";
    }
}
