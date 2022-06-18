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

int n,mx=0;
string s,a;
inline int solve(int x){int c=0,i;
    for(i=x;;i--){
        if(a[i]==a[x])c++;
        else if(a[i]=='w') c++;
        else break;
    }x++;
    for(i=x;;i++){
        if(a[i]==a[x]) c++;
        else if(a[i]=='w') c++;
        else break;
    }return c;
}
int main(){Rosario
    cin>>n>>s;a=s+s+s;
    for(int i=n;i<2*n;i++){
        if(a[i]==a[i+1]) continue;
        if(a[i]=='w'){
            a[i]='r';
            mx=max(mx,solve(i));
            a[i]='b';
            mx=max(mx,solve(i));
            a[i]='w';
        }else mx=max(mx,solve(i));
    }mx=min(n,mx);
    cout<<(mx==0?n:mx)<<"\n";
//    system("pause");
    return 0;
}
