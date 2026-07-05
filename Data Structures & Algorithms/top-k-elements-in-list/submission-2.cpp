class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        for(int num : nums)
        {
            freq[num]++;
        }

        int n = nums.size();

        vector<vector<int>> bucket(n+1);

        for(auto &it : freq)
        {
            int num = it.first;
            int count = it.second;

            bucket[count].push_back(num);
        }

        vector<int> ans;

        for(int i=n; i>=0; i--)
        {
            for(int num : bucket[i])
            {
                ans.push_back(num);

                if(ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};