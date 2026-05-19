class Solution {
public:
    //MERGE SORT
    void merge(vector<int> &arr, int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        //Create temporary vectors
        vector<int> L(n1), R(n2);

        //Copy data to temp vectors L[] and R[]
        for(int i = 0; i < n1; i++){
            L[i] = arr[left + i];
        }
        for(int j = 0; j < n2; j++){
            R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0;
        int k = left;

        //Merge them back
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        //copy the remaining elements of L[] if any
        while(i < n1){
            arr[k] = L[i];
            i++;
            k++;
        }

        while(j < n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& arr, int left, int right){
    
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    vector<int> sortArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        mergeSort(arr, left, right);
        return arr;
    }
};