class Solution {
private:
    void quick(vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;
    while (i <= j)
    {
      while (arr[i] < pivot)
          i++;
      while (arr[j] > pivot)
          j--;
      if (i <= j) // change position
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
      }
    }
    // recursion
    if (left < j)
      quick(arr, left, j);
    if (i < right)
      quick(arr, i, right);
}

public:
    vector<int> sortArray(vector<int>& nums) {
        quick(nums, 0, nums.size() - 1);
        return nums;
    }
};