#ifndef __HEAP_HH__
#define __HEAP_HH__

using namespace std;

template <typename T>
class Heap {
    public:
        Heap(T* array, int size, int (*cmp)(T, T));
        ~Heap();
        void sort();
        int len() const;
        const T* get_array() const;

    private:
        T* _array;
        int _size;
        int (*_cmp)(T, T);
        int left_index(int i) const;
        int right_index(int i) const;
        int parent_index(int i) const;
        void exchange(int a, int b);
        void heapify(int i);
};

template <typename T>
Heap<T>::Heap(T* array, int size, int (*cmp)(T, T)) {
    this->_array = array;
    this->_size = size;
    this->_cmp = cmp;
}

template <typename T>
Heap<T>::~Heap() {
    this->_array;
    this->_size = 0;
}

template <typename T>
void Heap<T>::sort() {
    int mid = this->_size / 2;
    for (int i = mid; i > -1; i--)
        this->heapify(i);

    int osize = this->_size;
    for (int i = this->_size - 1; i > 0; i--) {
        this->exchange(0, i);
        this->_size--;
        this->heapify(0);
    }

    this->_size = osize;
}

template <typename T>
int Heap<T>::len() const {
    return this->_size;
}

template <typename T>
const T* Heap<T>::get_array() const {
    return this->_array;
}

template <typename T>
int Heap<T>::left_index(int i) const {
    return (i * 2) + 1;
}

template <typename T>
int Heap<T>::right_index(int i) const {
    return (i * 2) + 2;
}

template <typename T>
int Heap<T>::parent_index(int i) const {
    if (i % 2)
        return (i - 1) / 2;
    else
        return i / 2;
}

template <typename T>
void Heap<T>::exchange(int a, int b) {
    T tmp = this->_array[a];
    this->_array[a] = this->_array[b];
    this->_array[b] = tmp;
}

template <typename T>
void Heap<T>::heapify(int i) {
    int l = this->left_index(i);
    int r = this->right_index(i);
    int largest = i;

    int x = this->_array[l];
    int y = this->_array[i];
    if (l < this->_size && this->_cmp(x, y) > 0)
        largest = l;
    
    x = this->_array[r];
    y = this->_array[largest];
    if (r < this->_size && this->_cmp(x, y) > 0)
        largest = r;

    if (largest != i) {
        this->exchange(i, largest);
        this->heapify(largest);
    }
}

#endif