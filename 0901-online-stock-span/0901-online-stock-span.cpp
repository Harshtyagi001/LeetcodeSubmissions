class StockSpanner {
public:
    int timer;
    stack<pair<int,int>>st;
    StockSpanner() {
        timer=-1;
        st.push({INT_MAX,timer});
    }
    
    int next(int price) {
        timer++;
        while(price>=st.top().first)st.pop();
        int ans=timer-st.top().second;
        st.push({price,timer});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */