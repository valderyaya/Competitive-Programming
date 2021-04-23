#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,m,k,a,b,q[105][105]={};
vector<int> v[105];
string s;
int main(){Rosario
    cin>>n>>m>>k;
    REP(i,m){
        cin>>a>>s>>b;
        if(s=="->") q[a][b]=1,v[a].em(b);
        else if(s=="<-") q[b][a]=1,v[b].em(a);
        else q[a][b]=q[b][a]=1,v[a].em(b),v[b].em(a);
    }
    if(k){
        REP1(i,1,n){
            sort(ALL(v[i]));
            v[i].resize(unique(ALL(v[i]))-v[i].begin());
            cout<<i<<" -> ";
            for(int j:v[i]) cout<<j<<' ';
            if(v[i].empty()) cout<<0;
            cout<<"\n";
        }
    }else{
    REP1(i,1,n){
        REP1(j,1,n) cout<<q[i][j]<<' ';
        cout<<"\n";
    }}
//    system("pause");
    return 0;
}

// inline int read() {
//     int ret=0,f=1;char ch=getchar_unlocked();
//     while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
//     while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
//     return ret*f;
// }
