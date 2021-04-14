//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e5+5;
string s;
int sa[z<<1],rk[z<<1],oldrk[z<<1],n,w;
int main(){Rosario
    getline(cin,s);
    n=s.size();
    s='\0'+s;
    REP1(i,1,n) rk[i]=s[i],sa[i]=i;
    for(w=1;w<n;w<<=1){
        sort(sa+1,sa+n+1,[](int x,int y){return rk[x]==rk[y]?rk[x+w]<rk[y+w]:rk[x]<rk[y];});
        memcpy(oldrk,rk,sizeof(rk));
        for(int p=0,i=1;i<=n;++i){
            if(oldrk[sa[i]]==oldrk[sa[i-1]]&&oldrk[sa[i]+w]==oldrk[sa[i-1]+w])
                rk[sa[i]]=p;
            else 
                rk[sa[i]]=++p;
        }
    }
    REP1(i,1,n) cout<<sa[i]-1<<"\n";
    return 0;
}
