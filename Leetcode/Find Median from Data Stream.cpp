class MedianFinder {
public:
    priority_queue<int,vector<int>> mx;
    priority_queue<int,vector<int>,greater<int>> mn;
    MedianFinder() {
        
    }
    
    void addNum(int x) {
        if(mx.empty() || x <= mx.top()) mx.push(x);
        else mn.push(x);
        while(mn.size()>=mx.size()){
            mx.push(mn.top());
            mn.pop();
        }
        while(mx.size()>mn.size()+1){
            mn.push(mx.top());
            mx.pop();
        }
    }
    
    double findMedian() {
        if(((int)mx.size()+(int)mn.size())%2) return mx.top();
        return ((double)mx.top()+mn.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
