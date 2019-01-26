#include "heap.hh"

template <class T>
Heap<T>::Heap(T* array, int size, int (*cmp)(T, T)) {
    this->_array = array;
    this->_size = size;
    this->_cmp = cmp;
}

template <class T>
Heap<T>::~Heap() {
    delete[] this->_array;
    this->_size = 0;
}

template <class T>
void Heap<T>::sort() {
    this->heapify(0);
}

template <class T>
int Heap<T>::len() const {
    return this->_size;
}

template <class T>
const T* Heap<T>::get_array() const {
    return this->_array;
}

template <class T>
int Heap<T>::left_index(int i) const {
    return i * 2;
}

template <class T>
int Heap<T>::right_index(int i) const {
    return i * 2 + 1;
}

template <class T>
int Heap<T>::parent_index(int i) const {
    if (i % 2)
        return (i - 1) / 2;
    else
        return i / 2;
}

template <class T>
void Heap<T>::exchange(int a, int b) {
    T tmp = this->_array[a];
    this->_array[a] = this->_array[b];
    this->_array[b] = tmp;
}

template <class T>
void Heap<T>::heapify(int i) {
    int l = this->left_index(i);
    int r = this->right_index(i);
    T largest = this->_array[i];


}