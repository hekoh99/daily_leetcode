class Solution {
public:
    int compareVersion(string version1, string version2) {
        int rev1 = 0, rev2 = 0, pos1 = 0, pos2 = 0;
        version1 += '.';
        version2 += '.';
        while (version1.length() != 0 && version2.length() != 0) {
            pos1 = version1.find('.');
            rev1 = atoi(version1.substr(0, pos1).c_str());
            version1 = version1.substr(pos1 + 1);

            pos2 = version2.find('.');
            rev2 = atoi(version2.substr(0, pos2).c_str());
            version2 = version2.substr(pos2 + 1);
            if (rev1 > rev2) {
                return 1;
            }
            else if (rev1 < rev2) {
                return -1;
            }
        }
        while (version1.length() != 0) {
            pos1 = version1.find('.');
            rev1 = atoi(version1.substr(0, pos1).c_str());
            version1 = version1.substr(pos1 + 1);

            if (rev1 != 0) {
                return 1;
            }
        }
        while (version2.length() != 0) {
            pos2 = version2.find('.');
            rev2 = atoi(version2.substr(0, pos2).c_str());
            version2 = version2.substr(pos2 + 1);

            if (rev2 != 0) {
                return -1;
            }
        }
        return 0;
    }
};