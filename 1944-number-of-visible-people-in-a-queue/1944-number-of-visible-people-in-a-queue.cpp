class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st; // monotonic  ---> piche se traverse krna start kia , jab tak heights[i] bada aa raha hai top se means kya hai vo chhote elements unseen hoge pichle aane vale index ko toh stack me bada element hi rakho jo chhote hai vo dikhege hi nahi pichle ko aur current vale ke lie jitne vo pop  kkar rha hai (m tlb chhote vale) means vo dikh gaye usko. Toh pop krne se kya ho rah ahia current val eke lie ans calculate ho raha hai and previous vasle ke lie bar set ho raha hai ki mere meri jitni height hai usse chhote vale hata die kyuki vo tuje dikhege hi nahi.
        int n=heights.size();
        vector<int>ans(n,0);
        st.push(heights[n-1]);
        for(int i=n-2;i>=0;i--){
            int ct=0;
            while(!st.empty() and st.top()<heights[i]){st.pop(); ct++;}
            if(st.empty())ans[i]+=ct;
            else ans[i]+=ct+1;
            st.push(heights[i]); 
        }
        return ans;
    }
};