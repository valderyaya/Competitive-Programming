//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
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
#define oi ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int n,ma,maa,cntleaf,p,a[100005],b[100005];
string s;
int main(){
    oi;
    while(cin>>s){
        a[0]=0,b[0]=1;
        p=ma=1,maa=cntleaf=0;
        REP(i,s.size()){
            if(s[i]=='('){
                a[p-1]++;
                b[p]=b[p-1]+1;
                a[p]=0;
                p++;   
            }else if(s[i]=='*'){
                cntleaf++;
                a[p-1]++;
            }else if(s[i]==')'){
                ma=max(ma,b[p-1]);
                maa=max(maa,a[p-1]);p--;
            }
        }
        cout<<cntleaf<<' '<<ma<<' '<<maa<<"\n";
    }
//    system("pause");
    return 0;
}
