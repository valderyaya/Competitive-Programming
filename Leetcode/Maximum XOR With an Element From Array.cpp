class Solution {
public:
    struct qwq{
        int id,x,y;
        bool operator<(const qwq &a)const{return y<a.y;}
    };
    int tr[3200001][2],tot;
    void add(int x){
        int p=0;
        for(int c,i=31;i>=0;--i){
            c=x>>i&1;
            if(!tr[p][c]) tr[p][c]=++tot;
            p=tr[p][c];
        }
    }
    int qry(int x){
        int p=0,ret=0;
        for(int c,i=31;i>=0;--i){
            c=x>>i&1;
            if(tr[p][c^1]){
                ret|=(1<<i);
                p=tr[p][c^1];
            }else if(tr[p][c]){
                p=tr[p][c];
            }else return -1;
        }
        return ret;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& que) {
        vector<int> ans(que.size());
        vector<qwq> q(que.size());
        sort(nums.begin(),nums.end());
        for(int i=0;i<que.size();++i)
            q[i]=qwq{i, que[i][0], que[i][1]};
        sort(q.begin(),q.end());
        for(int i=0,j=0;i<q.size();++i){
            while(j<nums.size() && nums[j] <= q[i].y) add(nums[j++]);
            ans[q[i].id]=qry(q[i].x);
        }
        return ans;
    }
};
