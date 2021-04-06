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

string a,b;
int main(){
    //oi;
    int ma=0,cnt;
    cin>>a>>b;
    REP(i,b.size()){
        if(b[i]==a.front()){
            int cnt=0,j=i,k=0;
            for(;j<b.size()&&k<a.size()&&a[k]==b[j];j++,k++,cnt++);
            if(j==b.size()) ma=max(ma,cnt);
        }
    }
    cout<<ma<<"\n";
//    system("pause");
    return 0;
}
