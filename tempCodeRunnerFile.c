#include<iostream>
using namespace std;
int maxDifference(int arr[], int size) {
    if (size < 2)
        return 0;
    
    int minVal = arr[0];
    int maxDiff = 0;
    
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal)
            minVal = arr[i];
        else if (arr[i] - minVal > maxDiff)
            maxDiff = arr[i] - minVal;
    }
    
    return maxDiff;
}
int main() {
    int nums[] = {2, 7, 9, 5, 1, 3, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int maxDiff = maxDifference(nums, size);
    
    cout<< "Maximum difference between any two elements in the array: " << maxDiff <<endl;
    
    return 0;
}