//
// Created by fredi on 30/10/23.
//

#ifndef PRIORITYQUEUE_MYHEAP_H
#define PRIORITYQUEUE_MYHEAP_H


class MyHeap {
private:
    int* values; // Arreglo donde se van a guardar los valores del HEAP
    int size;    // Representa cuantos valores tiene almacenado el Heap
    int len;     // Representa el tamaño o capacidad máxima actual del arreglo
public:
    MyHeap();                       // O(1) -- Inicializa el los atributos. El atributo values lo inicializa como un arreglo vacío tamaño de 7.
    MyHeap(int* valores,int _size); // O(n) -- Conviert el arreglo en un heap. Lo deja del mismo tamaño que tiene el arreglo

    void push(int n);   // O(log n) --
                        // Inserta un valor en el heap. Sólo cuando el nuevo valor no cabe en el arreglo
                        //crece el arreglo al tamaño 2*n+1. (Expansión din+amica del arreglo)
                        //Es decir si se tiene el arreglo ya con 7 valores y se quiere insertar otro valor(El 8vo)
                        //entonces el arreglo se crece a tamaño 15, se copian los primeros 7 valores del arreglo original
                        //y se inserta el 8vo valor.

    void pop();         // O(log n) -- Se elimina un valor del heap. No es necesario nunca decrementar el tamaño del arreglo.
    int top();          // O(1)     -- regresa quien es el siguiente elemento en salir pero sin borrarlo
    bool isEmpty();     // O(1)     -- regresa true si el heap está vacío caso contrario regresa false
    int length();       // O(1)     -- regresa cuántos elementos están almacenando el heap. OJO: NO EL TAMAÑO
    void imprimir();    // O(n)
};


#endif //PRIORITYQUEUE_MYHEAP_H
