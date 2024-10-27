#include<bits/stdc++.h>
using namespace std;

int N, T, ans = 1e9;
pair<int,int> pt[100001];
deque<int> dq_max, dq_min;
int main(){
    cin >> N >> T;
    for(int i = 1; i <= N; ++i) cin >> pt[i].first >> pt[i].second;
    sort(pt + 1, pt + 1 + N);
    for(int L = 0, R = 1; R <= N; ++R){
        while(!dq_max.empty() && pt[dq_max.back()].second < pt[R].second) dq_max.pop_back();
        dq_max.push_back(R);

        while(!dq_min.empty() && pt[dq_min.back()].second > pt[R].second) dq_min.pop_back();
        dq_min.push_back(R);
        
        while(!dq_max.empty() && !dq_min.empty() && (pt[dq_max.front()].second - pt[dq_min.front()].second >= T)){
            ans = min(ans, pt[R].first - pt[L].first);
            ++L;
            while(!dq_max.empty() && dq_max.front() < L) dq_max.pop_front();
            while(!dq_min.empty() && dq_min.front() < L) dq_min.pop_front();
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
}
