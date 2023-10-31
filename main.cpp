#include <iostream>
#include "MyHeap.h"

using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5,6,7};
    MyHeap PQ1(arr, sizeof(arr) / sizeof(int));
    MyHeap PQ2;
    PQ1.push(10);
    PQ1.pop();
    PQ1.imprimir();

    cout << "TOP: " << PQ2.top();


    return 0;
}
