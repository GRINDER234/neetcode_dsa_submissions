class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>>largerheap;
    priority_queue<int>smallerheap;

    MedianFinder() {}
    
    void addNum(int num) {
        smallerheap.push(num);
        if(!largerheap.empty() && smallerheap.top() > largerheap.top()){
            largerheap.push(num);
            smallerheap.pop();
        }

        if(smallerheap.size() > largerheap.size() + 1){
            largerheap.push(smallerheap.top());
            smallerheap.pop();
        }
        if(largerheap.size() > smallerheap.size() + 1){
            smallerheap.push(largerheap.top());
            largerheap.pop();
        }
    }
    
    double findMedian() {
        if(largerheap.size() == smallerheap.size()){
            return (largerheap.top() + smallerheap.top()) / 2.0;
        }else if(smallerheap.size() > largerheap.size()) return smallerheap.top();
        else return largerheap.top();
    }
};
