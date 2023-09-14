class Solution {
public:
    
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int maz1=-1,maz2=-1;
        int ct1=0,ct2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maz1)ct1++;
            else if(nums[i]==maz2)ct2++;
            else if(ct1==0){maz1=nums[i]; ct1++;}
            else if(ct2==0){maz2=nums[i]; ct2++;}
            else {
                ct1--; ct2--;
            }
        }
        vector<int>ans;
        ct1=0;
        ct2=0;
        for(auto&i:nums){
            if(i==maz1)ct1++;
            else if(i==maz2)ct2++;
        }
        if(ct1>n/3)ans.push_back(maz1);
        if(ct2>n/3)ans.push_back(maz2);
        return ans;
    }
};