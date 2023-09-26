class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        int i = 0, j = 0;
        int n = nums.size();
        vector<int> ans;
        
        while (j < n) {
            st.insert(nums[j]);

            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                ans.push_back(*st.rbegin());

                // Remove the element that's no longer in the window
                if (st.find(nums[i]) != st.end()) {
                    st.erase(st.find(nums[i]));
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};
