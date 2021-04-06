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


int main(){
    //oi;
    int a,b,c,x,y,z,h,m;
    scanf("%d:%d:%d",&a,&b,&c);
    scanf("%d:%d:%d",&x,&y,&z);
    b+=a*60;c+=b*60;
    y+=x*60;z+=y*60;
    if(c>z){
        z=z+86400-c;
        h=z/3600;z%=3600;
        m=z/60;z%=60;
        if(h<10) cout<<"0"<<h<<":";
        else cout<<h<<":";
        if(m<10) cout<<"0"<<m<<":";
        else cout<<m<<":";
        if(z<10) cout<<"0"<<z;
        else cout<<z;
    }else if(c<z){
        z-=c;
        h=z/3600;z%=3600;
        m=z/60;z%=60;
        if(h<10) cout<<"0"<<h<<":";
        else cout<<h<<":";
        if(m<10) cout<<"0"<<m<<":";
        else cout<<m<<":";
        if(z<10) cout<<"0"<<z;
        else cout<<z;
    }else cout<<"00:00:00\n";
   // system("pause");
    return 0;
}
