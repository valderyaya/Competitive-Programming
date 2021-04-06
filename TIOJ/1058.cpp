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

string a,b;
stringstream ss;
int x,y;
int main(){
    //oi;
    cin>>a>>b;
    ss<<a;ss>>x;ss.clear();ss.str("");
    ss<<b;ss>>y;ss.str("");ss.clear();
    if(x>y) cout<<a;
    else if(x<y) cout<<b;
    else{
        for(int i=0;;i++){
            if(a[i]>b[i]){cout<<a;break;}
            else if(a[i]<b[i]){cout<<b;break;}
        }
    }
//    system("pause");
    return 0;
}
