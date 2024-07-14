class Solution {
public:
    string countOfAtoms(string formula) {
        string ans;
        int index = 0;
        map<string, int> atoms = parseAtom(formula, index);
        map<string, int>::iterator it;

        for(it=atoms.begin();it != atoms.end();it++) {
            ans.append(it->first);
            if (it->second > 1) 
                ans.append(to_string(it->second));
        }
        return ans;
    }

    map<string, int> parseAtom(string& formula, int& index) {
        map<string, int> atoms;
        map<string, int> tmp;
        map<string, int>::iterator it;

        string atom;
        int count = 0;

        for(index;index<formula.size();index++) {
            if (isupper(formula[index])) {
                if (atom.length() != 0) {
                    if (count == 0)
                        count = 1;
                    atoms[atom] += count;
                }
                atom.clear();
                atom += formula[index];
                count = 0;
            }
            else if (islower(formula[index])) {
                atom += formula[index];
            }
            else if (isdigit(formula[index])) {
                count *= 10;
                count += (formula[index] - '0');
            }
            else if (formula[index] == '(') {
                if (atom.length() != 0) {
                    if (count == 0)
                        count = 1;
                    atoms[atom] += count;
                }
                atom.clear();
                count = 0;
                
                index++;
                tmp = parseAtom(formula, index);
                for(it = tmp.begin();it != tmp.end();it++) {
                    atoms[it->first] += it->second;
                }
            }
            else if (formula[index] == ')') {
                if (atom.length() != 0) {
                    if (count == 0)
                        count = 1;
                    atoms[atom] += count;
                }
                atom.clear();
                count = 0;

                index++;
                while (index < formula.size() && isdigit(formula[index])) {
                    count *= 10;
                    count += (formula[index] - '0');
                    index++;
                }
                index--;
                for(it = atoms.begin();it != atoms.end();it++) {
                    if (count > 1) {
                        it->second *= count;
                    }
                }
                return atoms;
            }
        }

        if (atom.length() != 0) {
            if (count == 0)
                count = 1;
            atoms[atom] += count;
        }
        return atoms;
    }
};