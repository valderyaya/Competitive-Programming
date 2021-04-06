//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

string s;
int c[2],out,nw,b[3];
int main(){Rosario
    while(cin>>s){
		out=nw=c[0]=c[1]=b[0]=b[1]=b[2]=0;
		for(auto &i:s){
			if(i=='K'||i=='O'){
				if(++out==3) nw=!nw,b[0]=b[1]=b[2]=out=0;
			}else if(i=='H'){
				c[nw]+=b[0]+b[1]+b[2]+1;
				b[0]=b[1]=b[2]=0;
			}else if(i=='W'){
				if(b[0]){
					if(b[1]){
						if(b[2]) ++c[nw];
						b[2]=1;
					}b[1]=1;
				}b[0]=1;
			}else if(i=='S'){
				c[nw]+=b[2];
				b[2]=b[1], b[1]=b[0], b[0]=1;
			}else if(i=='D'){
				c[nw]+=b[2]+b[1];
				b[2]=b[0], b[1]=1, b[0]=0;
			}else if(i=='T'){
				c[nw]+=b[2]+b[1]+b[0];
				b[2]=1,b[1]=b[0]=0;
			}
		}cout<<c[0]<<' '<<c[1]<<"\n";
	}
    return 0;
}
