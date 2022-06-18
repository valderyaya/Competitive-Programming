// luogu-judger-enable-o2
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

int n,cnt[8],m=1;
inline bool isleap(int x){
    if((x%4==0&&x%100)||x%400==0) return 1;
    else return 0;
}
inline bool is(int x){
    if(x==4||x==6||x==9||x==11) return 0;
    else return 1;
}
int main(){
    oi;
    cin>>n;
    for(int i=1900;i<1900+n;i++){
        for(int j=1;j<13;j++){
            if(j==2){
                for(int k=1;k<=(isleap(i)?29:28);k++,m++){
                    m=(m>7?1:m);
                    if(k==13) cnt[m]++;        
                }
            }else{
                for(int k=1;k<=(is(j)?31:30);k++,m++){
                    m=(m>7?1:m);
                    if(k==13) cnt[m]++;
                }
            }
        }
    }
    cout<<cnt[6]<<' '<<cnt[7]<<' '<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<' '<<cnt[4]<<' '<<cnt[5]<<"\n";
//    system("pause");
    return 0;
}
