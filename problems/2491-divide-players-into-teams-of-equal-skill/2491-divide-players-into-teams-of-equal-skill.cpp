class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        
        sort(skill.begin(), skill.end());
        int team = skill[0] + skill[skill.size() - 1];
        
        for(int i=0;i<skill.size() / 2;i++) {
            if (skill[i] + skill[skill.size() - i - 1] != team) {
                ans = -1;
                break;
            }
            ans += skill[i] * skill[skill.size() - i - 1];
        }
        return ans;
    }
};