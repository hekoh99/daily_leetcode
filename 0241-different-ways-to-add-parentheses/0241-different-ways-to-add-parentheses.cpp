class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        if (expression.length() == 0) return ans;

        if (expression.length() < 3) {
            ans.push_back(stoi(expression));
            return ans;
        }

        for(int i=0;i<expression.length();i++) {
            if (isdigit(expression[i])) {
                continue;
            }

            vector<int> leftRes = diffWaysToCompute(expression.substr(0, i));
            vector<int> rightRes = diffWaysToCompute(expression.substr(i + 1));

            for(int leftVal : leftRes) {
                for(int rightVal : rightRes) {
                    int computedRes = 0;

                    switch(expression[i]) {
                        case '+':
                            computedRes = leftVal + rightVal;
                            break;
                        case '-':
                            computedRes = leftVal - rightVal;
                            break;
                        case '*':
                            computedRes = leftVal * rightVal;
                            break;
                    }
                    ans.push_back(computedRes);
                }
            }
        }
        return ans;
    }
};