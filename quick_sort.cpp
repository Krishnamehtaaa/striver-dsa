class Solution {
public:
    int fn(vector<int> &arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (arr[i] <= pivot && i <= high - 1) {
                i++;
            }
            while (arr[j] > pivot && j >= low + 1) {
                j--;
            }
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[low], arr[j]);
        return j;  // correct place to return partition index
    }

    void qs(vector<int> &arr, int low, int high) {
        if (low < high) {
            int part = fn(arr, low, high);
            qs(arr, low, part - 1);
            qs(arr, part + 1, high);
        }
    }

    vector<int> quickSort(vector<int> &nums) {
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};
