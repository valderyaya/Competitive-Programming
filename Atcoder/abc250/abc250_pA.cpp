#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

int dx[]={0,1,0,-1},dy[]={1,0,-1,0},n,m,r,c,cnt;
signed main(){valder
	cin>>n>>m>>r>>c;
	for(int i=0;i<4;++i){
		int x=r+dx[i], y=c+dy[i];
		if(x>=1&&x<=n&&y>=1&&y<=m) ++cnt;
	}
	cout<<cnt;
	return 0;
}
