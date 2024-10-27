#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+1;
int ans, n, sum[maxn], h[maxn], a[maxn]; 
stack<int> st;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> h[i] >> a[i];
        while(!st.empty() && h[st.top()] <= h[i]) st.pop();
        if(!st.empty()) sum[st.top()] += a[i];
        st.push(i);
    }
    while(!st.empty()) 
        st.pop();
    for(int i = n; i; --i){
        while(!st.empty() && h[st.top()] <= h[i]) st.pop();
        if(!st.empty()) sum[st.top()] += a[i];
        st.push(i);
    }
    for(int i = 1; i <= n; ++i) ans = max(ans, sum[i]);
    cout << ans << "\n";
}
