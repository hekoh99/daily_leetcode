class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int area = 0;
        while (left < right) {
            area = (right - left) * min(height[left], height[right]);
            if (ans < area)
                ans = area;
            if (height[left] < height[right]) {
                left++;
            }
            else 
                right--;
        }
        return ans;
    }
};