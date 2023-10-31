//
// Created by fredi on 30/10/23.
//

#include "MyHeap.h"
#include "iostream"

using namespace std;

MyHeap::MyHeap()
{
    values = new int[7];  // init arreglo vacio de 7 elementos
    len = 7;              // capacidad de 7 elementos
    size = 0;             // contiene 0 elementos
}

MyHeap::MyHeap(int *valores, int _size) {
    len = size = _size; // set size y length
    values = new int[size]; // Alocar memoria para value

    // Copiar a values tal como esta valores, sin heap
    for (int i = 0; i < _size; i++) {
        values[i] = valores[i];
    }


    //Heapify el arreglo
    for (int i = size / 2 - 1; i >= 0; i--) {
        int currentIndex = i;
        int currentValue = values[i]; // Almacenar el valor del nodo actual

        while (true)
        {
            int childIndex = 2 * currentIndex + 1; // Calcula el índice del hijo izquierdo

            if (childIndex >= size) {
                break; // Si no hay hijos izquierdos, se ha completado el heapify
            }

            // Si hay un hijo derecho y es mayor que el hijo izquierdo, selecciona el hijo derecho
            if (childIndex + 1 < size && values[childIndex] < values[childIndex + 1]) {
                childIndex++;
            }

            if (currentValue >= values[childIndex])
            {
                break; // Si el valor del nodo actual es mayor o igual que el valor del hijo, se ha completado el heapify
            }

            values[currentIndex] = values[childIndex]; // El valor del nodo se actualiza con el valor del hijo
            currentIndex = childIndex; // Actualizamos el índice al hijo
        }
        values[currentIndex] = currentValue; // Al llegar a la posición que va en el heap, lo añadimos a 'values'
    }
}

void MyHeap::push(int n) {

    //Si no cabe un elemento nuevo, hacer mas grande el arreglo (tipo realloc)
    if (this->len >= this->size)
    {
        int new_size = 2 * this->size + 1; // tamaño nuevo es 2*tamaño_actual + 1
        int *new_values = new int[new_size]; //nuevo arreglo

        // Copiar elementos del arreglo viejo al arreglo nuevo
        for (int i = 0; i < this->len; ++i)
        {
            new_values[i] = this->values[i];
        }

        delete[] this->values; // Free memory de values
        this->values = new_values; // values ahora apunta al nuevo arreglo de los mismos elementos y mayor size
        this->len = new_size; // Update length
    }

    // añadir valor al final del arreglo
    this->values[this->len] = n;

    // Hepear el elemento hasta su pocicion correcta
    int currentIndex = this->len;
    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;

        //Si el valor es mayor a su parent
        if (this->values[currentIndex] > this->values[parentIndex])
        {
            //hacer swap
            int temp = this->values[currentIndex];
            this->values[currentIndex] = this->values[parentIndex];
            this->values[parentIndex] = temp;
            currentIndex = parentIndex; // uptade current idx
        }
        else
        {
            // El elemento ya está en la posición correcta
            break;
        }
    }

    size++; // Update len
}

void MyHeap::pop()
{
    //Si el arreglo está vacio, no hacer nada
    if(size == 0)
    {
        throw invalid_argument("Heap Is Empty");
    }


    //Reemplazar el top con el últimpo elemento
    values[0] = values[size-1];

    size--; //Lo degrecemos para ignorar el último elemento (el antiguo top o root)
    int currentIndex = 0;

    while (true)
    {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;
        int largestIndex = currentIndex;

        //Obtener el hijo con el valor mayor
        largestIndex = (leftChildIndex  < size && values[leftChildIndex]  > values[largestIndex]) ? leftChildIndex  : largestIndex;
        largestIndex = (rightChildIndex < size && values[rightChildIndex] > values[largestIndex]) ? rightChildIndex : largestIndex;


        //Checamos para saber si ya está en su lugar correcto
        if (largestIndex != currentIndex)
        {
            // swap current con largest idx
            int temp = values[currentIndex];
            values[currentIndex] = values[largestIndex];
            values[largestIndex] = temp;
            currentIndex = largestIndex; // uptade current idx al idx mas grandes
        }
        else
        {
            // si está en su pocición correcta, break
            break;
        }
    }

}

int MyHeap::top()
{
    //Si está vacio return error
    if (size <= 0)
    {
        throw invalid_argument("Heap Is Empty");
    }
    else
    {
        return values[0];
    }

}

bool MyHeap::isEmpty()
{
    return size == 0;
}

int MyHeap::length()
{
    return size;
}

void MyHeap::imprimir()
{
    cout << "arbol size: " << this->size << " len:" << this->len << endl;
    for (int i = 0; i < this->size; i++)
    {
        cout << values[i] << ",";
    }
    cout << endl;
}

