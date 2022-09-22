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
