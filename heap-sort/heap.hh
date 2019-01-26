#ifndef __HEAP_HH__
#define __HEAP_HH__

using namespace std;

template <class T>
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

#endif