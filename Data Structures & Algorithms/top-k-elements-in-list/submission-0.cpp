class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int n:nums){
            freq[n]++;
        }
        vector<pair<int,int>>freqvec;
        for(auto &p:freq){
        freqvec.push_back({p.first,p.second});
        }
        sort(freqvec.begin(),freqvec.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        });
        vector<int>result;
        for(int i =0;i<k;i++){
            result.push_back(freqvec[i].first);
        }
        return result;
    }
};
