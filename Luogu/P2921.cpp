#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n,dfn[100005]={},a[100005]={},b[100005],nx[100005],col[100005]={};
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>nx[i];
    REP1(i,1,n){
        for(int j=i,cnt=0;;j=nx[j],cnt++){
            if(!col[j]) col[j]=i,dfn[j]=cnt;
            else if(col[j]==i){
                a[i]=cnt-dfn[j];
                b[i]=dfn[j];
                cout<<cnt<<"\n";
                break;
            }else{
                a[i]=a[col[j]];
                b[i]=max(b[col[j]]-dfn[j],0)+cnt;
                cout<<a[i]+b[i]<<"\n";
                break;
            }
        }
    }
//    system("pause");
    return 0;
}
