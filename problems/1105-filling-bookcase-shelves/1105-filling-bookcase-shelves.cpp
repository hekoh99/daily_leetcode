class Solution {
private:
    int doDp(vector<vector<int>>& books, int width, vector<vector<int>>& dp, int i, int remain, int maxHeight) {
        int currentBookHeight = books[i][1];
        int currentBookWidth = books[i][0];
        int newMax = max(maxHeight, currentBookHeight);

        if (i == books.size() - 1) {
            if (remain >= currentBookWidth)
                return newMax;
            return maxHeight + currentBookHeight;
        }
        if (dp[i][remain] != 0)
            return dp[i][remain];
        int newShelveHeight = maxHeight + doDp(books, width, dp, i + 1, width - currentBookWidth, currentBookHeight);
        if (remain >= currentBookWidth) {
            int sameShelveHeight = doDp(books, width, dp, i + 1, remain - currentBookWidth, newMax);
            dp[i][remain] = min(newShelveHeight, sameShelveHeight);
            return dp[i][remain];
        }
        dp[i][remain] = newShelveHeight;
        return dp[i][remain];
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth + 1, 0));
        return doDp(books, shelfWidth, dp, 0, shelfWidth, 0);
    }
};