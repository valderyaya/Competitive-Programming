#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define F first
#define S second
#define pii pair<int,int>
#define ALL(x) (x).begin(),(x).end()
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back


int n,m,k,x,day[1005]={},now[1005]={};
vector<int> v[1005];
set<int> s;
int main(){
	oi;
	cin>>n>>m>>k;
	REP(i,n){
		REP(j,m){
			cin>>x;
			v[x].pb(i);
		}
	}
	REP1(i,1,k){
		s.clear();
		for(int j:v[i]){
			if(s.find(now[j])==s.end()){
				s.insert(now[j]);
				day[i]++;
			}
			now[j]++;
		}
	}
	REP1(i,1,k){
		cout<<day[i]<<' ';
	}
	return 0;
}
