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
#define lb(x) (x&-x)

int n,b[1025][1025];
void add(int x,int y,int v){
	for(;x<=n;x+=lb(x)){
		for(int i=y;i<=n;i+=lb(i)) b[x][i]+=v;
	}
}
int get(int x,int y){
	int sum=0;
	for(;x;x-=lb(x)){
		for(int i=y;i;i-=lb(i)) sum+=b[x][i];
	}
	return sum;
}
int main(){
    //Rosario
    int k,x,y,xx,yy,z;
	cin>>n;
	while(cin>>k){
		if(k&1){
			cin>>x>>y>>z;
			x++,y++;
			add(x,y,z);
		}else{
			cin>>x>>y>>xx>>yy;
			x++,y++,xx++,yy++;
			cout<<get(xx,yy)+get(x-1,y-1)-get(x-1,yy)-get(xx,y-1)<<"\n";
		}
	}
//    system("pause");
    return 0;
}
