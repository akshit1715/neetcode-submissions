class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!stk.empty() && temperatures[i]>temperatures[stk.top()]){
            int prevIndex=stk.top();
            stk.pop();
            ans[prevIndex]=i-prevIndex;
            }
            stk.push(i);
        }
        return ans;
    }
};
