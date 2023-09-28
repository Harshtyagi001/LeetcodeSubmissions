class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") return "";
        unordered_map<char, int> mpt;
        for (auto& x : t) mpt[x]++;
        int len = s.size();
        pair<int, int> pr = {-1, -1};
        unordered_map<char, int> mps;
        int have = 0, need = mpt.size(), i=0,j=0;
        while (j<s.size()) {
            mps[s[j]]++;
            if (mpt.count(s[j]) && mps[s[j]] == mpt[s[j]]) {
                have++;
            }
            while (have == need) {
                if (j - i + 1 <= len) {
                    pr.first = i, pr.second = j;
                    len = j - i + 1;
                }
                mps[s[i]]--;
                if (mpt.count(s[i]) && mps[s[i]] < mpt[s[i]]) {
                    have--;
                }
                i++;
            }
              j++;
        }
        if (pr.second == -1 || pr.first == -1) return "";
        
        return s.substr(pr.first,pr.second-pr.first+1);
    }
};