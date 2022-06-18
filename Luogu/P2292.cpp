//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
#define line cout<<"-------------------------------\n";

int rt=0,tr[205][26]={},on[1000005],e[205]={},n,m;
void insert(string s){
    int x=0;
    for(char c:s){
        if(!tr[x][c-'a']) tr[x][c-'a']=++rt;
        x=tr[x][c-'a'];
    }
    e[x]=1;
}
int solve(string s){
    int ans=0,x=0,j;
    memset(on,0,sizeof(on));
    REP(i,s.size()){
        x=tr[x][s[i]-'a'];
        if(!x) break;
        if(e[x]) on[i]=1;
    }
    REP(i,s.size()){
        if(!on[i]) continue;
        ans=i+1;
        for(j=i+1,x=0;j<s.size();j++){
            x=tr[x][s[j]-'a'];
            if(!x) break;
            if(e[x]) on[j]=1;
        }
    }
    return ans;
}
string s;
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>s,insert(s);
    while(m--) cin>>s,cout<<solve(s)<<"\n";
//    system("pause");
    return 0;
}
