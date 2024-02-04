class Solution {
public:
    int trap(vector<int>& h){
        stack<int,vector<int>> st;
        int ans=0,idx,n=h.size();
        for(int i=0;i<n;++i){
            while(!st.empty() && h[i]>h[st.top()]){
                idx=st.top(); st.pop();
                if(st.empty()) break;
                ans+=(min(h[i],h[st.top()])-h[idx])*(i-st.top()-1);
            }
            st.push(i);
        }
        return ans;
    }
};
