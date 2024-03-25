#include<stdio.h>

int bsearch(int arr[], int n, int a) {
    int low = 0;
    int high = n-1;
    while(high-low>1) {
        int mid = (low+high)/2;
        if(arr[mid] == a) return mid;
        if(arr[mid] < a) low = mid+1;
        else high = mid;
    }
    if(arr[low] == a) return low;
    else return high;
}

int main() {
    int arr[] = {4, 7, 8, 10, 13, 17, 29, 34};
    printf("%d", bsearch(arr, 8, 10));
}