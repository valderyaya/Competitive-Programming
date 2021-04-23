#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n;
    std::priority_queue<int> max_heap;
    std::priority_queue<int,vector<int>,greater<int>> min_heap;
    unordered_map<int,int> m;
    while(cin>>n&&n)
    {
        if(n==-1)
        {
            while(min_heap.size()&&!m[min_heap.top()]) min_heap.pop();
            if(min_heap.size()) cout<<min_heap.top()<<' ',m[min_heap.top()]--,min_heap.pop();
        }
        else if(n==-2)
        {
            while(max_heap.size()&&!m[max_heap.top()]) max_heap.pop();
            if(max_heap.size()) cout<<max_heap.top()<<' ',m[max_heap.top()]--,max_heap.pop();
        }
        else m[n]++,min_heap.emplace(n),max_heap.emplace(n);
    }
}
