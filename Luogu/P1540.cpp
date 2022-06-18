#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
//#define lowbit(x) (x&(-x)) 

vector<ll> v;
bool ck(ll x){
	REP(i,v.size()){
		if(x==v[i]) return 1;
	}
	return 0;
}
int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m,x,cnt=0;
	cin>>m>>n;
	while(n--){
		cin>>x;
		if(!ck(x)){
			if(v.size()>=m){
				v.erase(v.begin());cnt++;v.em(x);	
			}else{
				v.em(x);cnt++;
			}
		}
	}
	cout<<cnt<<endl;
//    system("pause");
    return 0;
}
