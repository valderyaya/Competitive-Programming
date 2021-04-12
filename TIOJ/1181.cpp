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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)

int n,i;
bool a,b,c,d,e;
string s;
int main(){
    oi;
    cin>>n;
    while(n--){
        a=b=c=d=e=0;
        for(i=0;i<12;++i){
            cin>>s;
            for(int i=0;i<6;++i){
                if(s[i]=='R') a=1;
                else if(s[i]=='G') b=1;
                else if(s[i]=='B') c=1;
                else if(s[i]=='Y') d=1;
                else if(s[i]=='P') e=1;
            }
        }
        cout<<a+b+c+d+e<<'\n';
    }
//    system("pause");
    return 0;
}
