#include<bits/stdc++.h>
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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

string a,b;
int main(){
    //oi;
    cin>>a>>b;
    int ans=0,cnt;
    REP(i,a.size()){
        cnt=0;
        for(int j=0;i+j<a.size();j++){
            if(a[i+j]==b[j]) cnt++;
        }
        ans=max(ans,cnt);
    }
    REP(i,b.size()){
        cnt=0;
        for(int j=0;i+j<b.size();j++){
            if(b[i+j]==a[j]) cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
