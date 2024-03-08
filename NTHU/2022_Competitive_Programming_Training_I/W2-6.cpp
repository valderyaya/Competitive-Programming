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


string s;
vector<pii> v;
int a[10][10],f;
bool ck(){
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            int t[10]={};
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    if(a[k][l]==0) continue;
                    if(t[a[k][l]]==0) t[a[k][l]]=1;
                    else return 0;
                }
            }
        }
    }
    REP(i,9){
        int t[10]={};
        REP(j,9){
            if(a[i][j]==0) continue;
            if(t[a[i][j]]==0) t[a[i][j]]=1;
            else return 0;
        }
    }
    REP(i,9){
        int t[10]={};
        REP(j,9){
            if(a[j][i]==0) continue;
            if(t[a[j][i]]==0) t[a[j][i]]=1;
            else return 0;
        }
    }
    return 1;
}
void dfs(int n){
    if(n==v.size()){
        REP(i,9) REP(j,9) cout<<a[i][j];
        return cout<<"\n",f=0,void();
    }
    REP1(i,1,9){
        a[v[n].F][v[n].S] = i;
        if(ck()) dfs(n+1);
    }
    a[v[n].F][v[n].S]=0;
}
signed main(){StarBurstStream
    while(cin>>s,s[0]!='e'){
        memset(a,0,sizeof(a));
        v.clear(); f=1;
        for(int i=0;i<81;++i)
            if(s[i]=='.') v.em(i/9,i%9);
            else a[i/9][i%9] = s[i]-'0';
        dfs(0);
        if(f) cout<<"No solution.\n";
    }
    return 0;
}
