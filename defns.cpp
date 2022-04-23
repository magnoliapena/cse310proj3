#include "defns.h"

void merge(int array[], int start, int middle, int end) {
    int sizeLeft = middle - start + 1;
    int sizeRight = end - middle;

    int *leftArray = new int[sizeLeft];
    int *rightArray = new int[sizeRight];

    for (int i = 0; i < sizeLeft; i++) {
        leftArray[i] = array[start + i];
        // put into left subarray the elements on unsorted array from the beginning
        // to the middle
    }
    for (int i = 0; i < sizeRight; i++) {
        rightArray[i] = array[middle + 1 + i];
        // put into right subarray the elements on unsorted array from the middle+1 to the end
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int sortedIndex = start;

    //compares left subarray and right subarray at given index values and
    //then placed into the main array
    while (leftIndex < sizeLeft && rightIndex < sizeRight) {
        if (leftArray[leftIndex] < rightArray[rightIndex]) { // case 1
            array[sortedIndex] = leftArray[leftIndex];
            leftIndex++;
        } else if (leftArray[leftIndex] > rightArray[rightIndex]) { // case 2
            array[sortedIndex] = rightArray[rightIndex];
            rightIndex++;
        } else {
        }
        sortedIndex++;
    }
    // check if odd number on left array and copy into sorted array
    while (leftIndex < sizeLeft) {
        array[sortedIndex] = leftArray[leftIndex];
        sortedIndex++;
        leftIndex++;
    }
    //check if odd number on right array and copy into sorted array
    while (rightIndex < sizeRight) {
        array[sortedIndex] = rightArray[rightIndex];
        sortedIndex++;
        rightIndex++;
    }

}
void mergesort(int array[], int start, int end) {
    if (start >= end) {
        return; //call recursively until fully divided
    }
    // divide array / 2
    int middle = start + (end - start) / 2;
    mergesort(array, start, middle); //subarray 1
    mergesort(array, middle + 1, end); //subarray 2
    //combine after sorted
    merge(array, start, middle, end);
}
//file read helper function