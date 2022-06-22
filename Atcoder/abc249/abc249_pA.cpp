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

int a,b,c,d,e,f,x,sa,sb;
signed main(){valder
	cin>>a>>b>>c>>d>>e>>f>>x;
	for(int i=0;i<x;){
		if(i+a<x){
			i+=a;
			sa+=a*b;
		}else{
			sa+=(x-i)*b;
			break;
		}
		if(i+c<x) i+=c;
		else break;
	}
	for(int i=0;i<x;){
		if(i+d<x){
			i+=d;
			sb+=d*e;
		}else{
			sb+=(x-i)*e;
			break;
		}
		if(i+f<x) i+=f;
		else break;
	}
	if(sa>sb) cout<<"Takahashi";
	else if(sa<sb) cout<<"Aoki";
	else cout<<"Draw";
	return 0;
}
