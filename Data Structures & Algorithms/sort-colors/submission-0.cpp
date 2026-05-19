class Solution {
public:
    int part(vector<int> &arr, int low, int high){
        int pivot = low;
        int i = low + 1;
        int j = high;
        while(i <= j){
            if(i <= high && arr[i] <= arr[pivot]){
                i++;
            }
            else if(j >= low && arr[j] >= arr[pivot]){
                j--;
            }
            else{
                swap(arr[i],arr[j]);
                i++;
                j--;
            }

        }
        swap(arr[pivot],arr[j]);
        return j;
    }
    void quicksort(vector<int> &arr, int low, int high){
        if(low < high){
            int p = part(arr,low,high);
            quicksort(arr,low,p-1);
            quicksort(arr,p+1,high);
        }
    }
    void sortColors(vector<int>& arr) {
        int low = 0;
        int high = (int)arr.size() - 1;
        quicksort(arr,low,high);
    }
};