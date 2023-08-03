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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair

map<string,string> mp;
map<string,int> mp2;
string prs(int a,int b,int c,int d=-1,int e=-1){
    string ret="";
    ret.push_back(char(a+'0'));
    ret.push_back(char(b+'0'));
    ret.push_back(char(c+'0'));
    if(~d) ret.push_back(char(d+'0'));
    if(~e) ret.push_back(char(e+'0'));
    return ret;
}
int nand(int a, int b){
    if(a==0 && b==0) return 1;
    if(a==0 && b==1) return 1;
    if(a==1 && b==0) return 1;
    if(a==1 && b==1) return 0;
}
void cal(int a,int b,int c,int d,int e){
    int x[4],y[3];
    x[0]=nand(a,b);
    x[1]=nand(b,c);
    x[2]=nand(c,d);
    x[3]=nand(d,e);
    y[0]=nand(x[0],x[1]);
    y[1]=nand(x[1],x[2]);
    y[2]=nand(x[2],x[3]);
    mp2[prs(y[0],y[1],y[2])]++;
    mp[prs(a,b,c,d,e)]=prs(y[0],y[1],y[2]);
}
signed main(){StarBurstStream
    for(int i=0,a,b,c,d,e;i<32;++i){
        e=i & 1;
        d=i>>1 & 1;
        c=i>>2 & 1;
        b=i>>3 & 1;
        a=i>>4 & 1;
        cal(a,b,c,d,e);
    }
    string s;
    while(cin>>s){
        if(s.size()==5) cout<<mp[s]<<"\n";
        else cout<<mp2[s]<<"\n";
    }
    return 0;
}
