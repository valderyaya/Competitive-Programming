class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans=0;
        vector<int> st;
        h.push_back(-1);
        for(int i=0;i<h.size();++i){
            while(!st.empty()&&h[st.back()]>h[i]){
                int x=h[st.back()];
                st.pop_back();
                ans=max(ans, x*(st.empty()?i:i-st.back()-1));
            }
            st.push_back(i);
        }
        return ans;
    }
};
