#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
const int maxn = 505;
int a[maxn][maxn];
int tmp[maxn];
signed main(){
	IOS;
	int n , m , k;
	cin >> n >> m >> k ;
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j){
			char ch;
			cin >> ch;
			if(ch == '+') a[i][j] = 1;
			if(ch == '-') a[i][j] = -1;
		}
	int ans = 1e9 ;
	if(k == 0) ans = 0 ;
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			a[i][j] += a[i-1][j];
		}
	}
	for(int l=1 ; l<=n ; ++l){
		for(int r=l ; r<=n ; ++r){
			for(int i=1 ; i<=m ; ++i){
				tmp[i] = a[r][i]-a[l-1][i];
			}
			for(int i=1 ; i<=m ; ++i)
				tmp[i] += tmp[i-1];
			deque<pii> dq;
			for(int i=0 ; i<=m ; ++i){
				while(SZ(dq) && dq.back().F >= tmp[i]) dq.pop_back();
				dq.push_back({tmp[i] , i});
				while(SZ(dq) && tmp[i] - dq.front().F >= k) {
					ans = min(ans , (r-l+1) * (i - dq.front().S));
					dq.pop_front();
				}
			}
		}
	}
	cout <<( ans == 1e9 ? -1 : ans )<< '\n';
}
