class Solution {
private:
    bool getResult(string& expr, int& index) {
        char curChar = expr[index];
        index++;

        if (curChar == 't')
            return true;
        if (curChar == 'f')
            return false;
        

        if (curChar == '!') {
            index++;
            bool tmp = !getResult(expr, index);
            index++;
            return tmp;
        }

        if (curChar == '&' || curChar == '|') {
            vector<bool> vals;
            index++;
            while (expr[index] != ')') {
                if (expr[index] != ',') {
                    vals.push_back(getResult(expr, index));
                }
                else {
                    index++;
                }
            }
            index++;

            if (curChar == '&') {
                for(int i = 0;i<vals.size();i++) {
                    if (vals[i] == false)
                        return false;
                }
                return true;
            }

            if (curChar == '|') {
                for(int i = 0;i<vals.size();i++) {
                    if (vals[i] == true)
                        return true;
                }
                return false;
            }
        }
        return false;
    }
public:
    bool parseBoolExpr(string expression) {
        int index = 0;
        bool ans = getResult(expression, index);
        return ans;
    }
};