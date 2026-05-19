class Solution {
public:
    //QUICK SORT

    int part(vector<int>& arr, int low, int high) {
    int pivot = low;
    int i = low + 1;   // ✅ start i AFTER pivot
    int j = high;

    while (i <= j) {
        if (arr[i] <= arr[pivot]) {
            i++;  // move i right
        } else if (arr[j] > arr[pivot]) {
            j--;  // move j left
        } else {
            swap(arr[i], arr[j]);  // both are on wrong side, swap
            i++;
            j--;
        }
    }
    swap(arr[pivot], arr[j]);  // place pivot in correct position
    return j;
}

    void quicksort(vector<int> &arr, int low , int high){
        if(low < high){
        int partition = part(arr,low,high);
        quicksort(arr,low,partition-1);
        quicksort(arr,partition+1,high);
        }
    }
    vector<int> sortArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;
        quicksort(arr,low,high);
        return arr;
    }
};