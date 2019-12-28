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
void deleteNode(int a[], int x, int n);                    // Delete node which contains the value 'x'

int main (void) {

    int n;
    cin >> n;
    int a[n];

    srand(time(0));
    for ( int i = 0; i < n ; ++i ) a[i] = 1 + ( rand() % 20 );
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    std::cout << "\n";

    // * simple bound
    // * O(n) calls to maxHeapify()
    // * Each of which takes O(lg n)
    // * Complexity: O(n lg n)

    // * Worst case O(n lg n) ( like merge sort )
    // * Sorts in place ( like insertion sort )

    // ? Uncomment to heapsort accordingly
    // Bugs here, sadly, fix please
    heapSort_Min(a, n);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    sort(a, a + n);
    std::cout << "\n";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    std::cout << "\n";
    // heapSort_Min(a, n);
}

void buildMaxHeap(int a[], int n)
{
    for ( int i = floor ( n / 2 ) ; i >= 1 ; --i )
    {
        maxHeapify(a, i, n);
    }
}

// * Complexity O(lg n)
void maxHeapify(int a[], int i, int n)
{
    int l = 2 * i, r = 2 * i + 1, largest = i;

    if ( l < n and a[l] > a[largest] ) largest = l;
    if ( r < n and a[r] > a[largest] ) largest = r;

    if ( largest != i )
    {
        swap(a[i], a[largest]);
        maxHeapify(a, largest, n);
    }
}

int maximum(int a[]) 
{
    return a[1];
}   

int extractMax(int a[], int n) 
{
    int maxx = a[1];
    a[1] = a[n];

    maxHeapify(a, 1, n - 1);
        return maxx;
}   

void increaseKey(int a[], int x, int k) 
{
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

    for ( int i = n - 1 ; i >= 2 ; --i )
    {
        swap(a[1], a[i]);
        maxHeapify(a, 1, i - 1);
    }
}

void buildMinHeap(int a[], int n) 
{
    for (int i = floor(n / 2); i >= 1; --i)
    {
        minHeapify(a, i, n);
    }
}   

void minHeapify(int a[], int i, int n) 
{
    int l = 2 * i, r = 2 * i + 1, smallest = i;

    if (l < n and a[l] < a[smallest])
        smallest = l;
    if (r < n and a[r] < a[smallest])
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

    for (int i = n; i >= 2 ; --i)
    {
        swap(a[1], a[i - 1]);
        minHeapify(a, 1, i - 1);
    }
}

// ! Complexity O(lg n)
void insert(int a[], int key, int n)
{
    a[n + 1] = std::numeric_limits<int>::min();
    increaseKey(a, n + 1, key);
}

void deleteNode(int a[], int x, int n)
{
    // search for element
    int i = 0;
    for ( ; i < n ; ++i )
        if ( x == a[i] )
         break;

    swap(a[i], a[n - 1]);
    a[n - 1] = std::numeric_limits<int>::min();
}