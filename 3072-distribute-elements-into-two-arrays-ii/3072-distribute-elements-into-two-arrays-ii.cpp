#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
 // storing in reverse order, so order_of_key will give me the no. of elements greater than the target value
 // using greater_equal/ less_equal means duplicates are allowed
 // Ordered Set are efficint in:
 // 1. Insert log(n)
 // 2. Delete log(n)   ..... These two are provided by normal set as well
 // But, 3. Finding no. of elements less than or gretae than -> O(logn) and finding the pos of element is also in O(logn)
 // which typically takse O(n) in normal sets, because there is no concept of indexes in sets
// TO find no. of element lesser or greater ---> A.order_of_key(target)
// To find element at kth index ---> (*A.find_by_order)
 
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        oset ms1,ms2;

        ms1.insert(nums[0]);
        ms2.insert(nums[1]);

        int sz1=1,sz2=1;

        for(int i=2;i<nums.size();i++){
           
           int ele1=ms1.order_of_key(nums[i]) , ele2= ms2.order_of_key(nums[i]);

           if(ele1>ele2){
              arr1.push_back(nums[i]);
              ms1.insert(nums[i]);
              sz1++;
           }

           else if(ele1<ele2){
               arr2.push_back(nums[i]);
               ms2.insert(nums[i]);
               sz2++;
           }

           else{

               if(sz2<sz1){
                   arr2.push_back(nums[i]);
                   ms2.insert(nums[i]);
                   sz2++;
                 }

               else {
                   arr1.push_back(nums[i]);
                   ms1.insert(nums[i]);
                   sz1++;
            }

           }
           
        }

        for(auto i:arr2)arr1.push_back(i);

        return arr1;
    }
};