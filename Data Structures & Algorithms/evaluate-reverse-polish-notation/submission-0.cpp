class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> stk;

        for(string token : tokens){

            if(token=="+" || token=="-" || token=="*" || token=="/"){

                int b = stk.top();
                stk.pop();

                int a = stk.top();
                stk.pop();

                int result;

                if(token=="+"){
                    result = a+b;
                }
                else if(token=="-"){
                    result = a-b;
                }
                else if(token=="*"){
                    result = a*b;
                }
                else{
                    result = a/b;
                }

                stk.push(result);
            }
            else{
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};