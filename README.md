# Randomized-Quick-Sort
This is the randomized version of quick sort

## Description:
Here is an optimized version of quicksort, which is specially designed to reduce the complexity of this sorting algorithm to almost n*Log(n) for any possible case.
We know that the complexity of quicksort dependends on the way it is partitioned, so pivot element's position in the sorted array plays an important role in the calculation of the complexity

This is what we know by now:


The worst case complexity of quicksort occurs in the following case( Considering the pivot to be first/last element of the array):
1) Array is already sorted in the same order. 
2) Array is already sorted in reverse order. 
3) All elements are the same (a special case of cases 1 and 2) 

So now as we know that the selection of the pivot with respect to data of the array, will be deciding factor for complexity of this algorithm thus we are trying to randomize the selection of this pivot 
in every recursive call, which would be beneficial for the stated worst cases of quicksort.

An extra function named "Randomized" is there in this program which selects a random element as pivot and sorts the array on that basis, thus reducing the overall
complexity.

```CPP
#include <bits/stdc++.h>
#include <random>
using namespace std;
int n;
void display(int arr[])
{
    cout << "___________" << endl;
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "___________" << endl;
}
void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void Randomized(int arr[], int front, int rear)
{
    int pivot = front + 1 + (rand() % (rear - front));
    // now this pivot is chosen as a random element
    // swap it with the first element
    swap(arr, pivot, front);
    return;
}
int Partition(int arr[], int front, int rear)
{
    int i = front + 1, j = rear;
    // yet not selected the pivot
    // calling the randomized function
    Randomized(arr, front, rear);
    // now that the randomized element selected has been placed in the first place then
    //  we can apply the normal logic of partition
    int pivot = front;
    do
    {

        while (arr[i] < arr[pivot]) // element just greater than the pivot
            i++;
        while (arr[j] > arr[pivot])
            j--;
        if (i < j)
            swap(arr, i, j);

    } while (i < j);
    swap(arr, j, pivot);
    return j;
}

void QSort(int arr[], int front, int rear)
{
    if (front < rear)
    {
        int q = Partition(arr, front, rear);
        // recursion
        QSort(arr, front, q - 1);
        QSort(arr, q + 1, rear);
    }
}
int main()
{
    cout << "Hello User,Let's Implement Randomized Quick Sort" << endl;
    cout<<"Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout<<"Enter the array elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    QSort(arr, 0, n - 1);
    cout << "Sorted Array:" << endl;
    display(arr);
}


```
#### Images of some tested sample cases:
##### Test case 1:
<img width="313" alt="image" src="https://user-images.githubusercontent.com/96655436/191712753-c89c19b4-4a9c-4407-bede-10e26511f8dd.png">


##### Test case 2:
<img width="304" alt="image" src="https://user-images.githubusercontent.com/96655436/191712519-de6fce5e-4599-4246-8033-d4d050024e1a.png">

##### Test Case 3:
<img width="307" alt="image" src="https://user-images.githubusercontent.com/96655436/191712201-59e0de60-94bd-4ec5-8b63-ce8e87609108.png">



