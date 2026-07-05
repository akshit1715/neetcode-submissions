class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int left=0;
        int ans=0;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
        
        int maxFreq=0;
        for(auto it:mp){
            maxFreq=max(maxFreq,it.second);
        }
        if(right-left+1-maxFreq>k){
            mp[s[left]]--;
            left++;

        }
        ans=max(ans,right-left+1);
    }
    return ans;
    }
};
