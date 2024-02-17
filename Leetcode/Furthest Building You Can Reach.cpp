class Solution {
public:
    int furthestBuilding(vector<int>& v, int bricks, int ladders) {
        priority_queue<int, vector<int> , greater<int>> mn;
        for(int diff, i = 0; i + 1 < v.size(); ++i)
            if(v[i] < v[i+1]){
                diff = v[i+1]-v[i];
                if(mn.size() < ladders){
                    mn.emplace(diff);
                }else{
                    if(mn.size() && mn.top() < diff){
                        bricks -= mn.top();
                        mn.pop();
                        mn.emplace(diff);
                        if(bricks < 0) return i;
                    }else{
                        if(diff > bricks) return i;
                        bricks -= diff;
                    }
                }
            }
        return v.size() - 1;
    }
};

