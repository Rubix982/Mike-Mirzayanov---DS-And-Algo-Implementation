#include "../bits/stdc++.h"
using namespace std;

// ? Implementation from 
// ? https://www.cs.bgu.ac.il/~ds122/wiki.files/Presentation09.pdf

void buildMaxHeap(int a[], int n);              // Builds the max heap
void maxHeapify(int a[], int i, int n);         // Heapifies the tree
int maximum(int a[]);                           // gives back the max element
int extractMax(int a[], int n);                 // Extracts the maximum element
void increaseKey(int a[], int x, int k);        // Increase value of element x's key to k.
void heapSort_Max(int a[], int n);              // Does heap sort

void buildMinHeap(int a[], int n);              // Builds the mn heap
void minHeapify(int a[], int i, int n);         // Heapifies the tree
int minimum(int a[]);                           // gives back the max element
int extractMin(int a[], int n);                 // Extracts the maximum element
void decreaseKey(int a[], int x, int k);        // Increase value of element x's key to k.
void heapSort_Min(int a[], int n);              // Does heap sort

void insert(int a[], int key, int n);           // Inserts element x into array a

int main (void) {

    int n;
    cin >> n;
    int a[n];

    for ( int i = 0; i < n ; ++i ) cin >> a[i];

    // * simple bound
    // * O(n) calls to maxHeapify()
    // * Each of which takes O(lg n)
    // * Complexity: O(n lg n)

    // * Worst case O(n lg n) ( like merge sort )
    // * Sorts in place ( like insertion sort )

    // ? Uncomment to heapsort accordingly
    // heapSort_Max(a, n - 1);
    // heapSort_Min(a, n - 1);
}

void buildMaxHeap(int a[], int n)
{
    for ( int i = floor ( n / 2) ; i >= 1 ; --i )
    {
        maxHeapify(a, i, n);
    }
}

// * Complexity O(lg n)
void maxHeapify(int a[], int i, int n)
{
    int l = 2 * i, r = 2 * i + 1, largest = i;

    if ( l <= n and a[l] > a[largest] ) largest = l;
    if ( r <= n and a[r] > a[largest] ) largest = r;

    if ( largest != i )
    {
        swap(a[i], a[largest]);
        maxHeapify(a, largest, n);
    }
}

int maximum(int a[]) {
    return a[1];
}   

int extractMax(int a[], int n) {
    int maxx = a[1];
    a[1] = a[n];

    maxHeapify(a, 1, n - 1);
    return maxx;
}   

void increaseKey(int a[], int x, int k) {
    a[x] = k;

    while ( (x > 1 & a[ x / 2]) < a[x])
    {
        swap( a[x], a[x / 2]);
        x = x / 2;
    } 
} 

void heapSort_Max(int a[], int n)
{
    buildMaxHeap(a, n);

    for ( int i = n ; i >= 2 ; --i )
    {
        swap(a[1], a[i]);
        maxHeapify(a, 1, i - 1);
    }
}

void buildMinHeap(int a[], int n) {
    for (int i = floor(n / 2); i >= 1; --i)
    {
        minHeapify(a, i, n);
    }
}   

void minHeapify(int a[], int i, int n) 
{
    int l = 2 * i, r = 2 * i + 1, smallest = i;

    if (l <= n and a[l] < a[smallest])
        smallest = l;
    if (r <= n and a[r] < a[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        maxHeapify(a, smallest, n);
    }
}  

int minimum(int a[]) 
{
    return a[1];
}   

int extractMin(int a[], int n) {
    int minn = a[1];
    a[1] = a[n];

    maxHeapify(a, 1, n - 1);
    return minn;
}   

void decreaseKey(int a[], int x, int k) 
{
    a[x] = k;

    while ((x > 1 & a[x / 2]) > a[x])
    {
        swap(a[x], a[x / 2]);
        x = x / 2;
    }
} 

void heapSort_Min(int a[], int n) 
{
    buildMinHeap(a, n);

    for (int i = n; i >= 2; --i)
    {
        swap(a[1], a[i]);
        minHeapify(a, 1, i - 1);
    }
}   