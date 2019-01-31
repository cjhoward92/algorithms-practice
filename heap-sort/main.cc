#include <iostream>

#include "heap.hh"

int int_cmp(int x, int y) {
    return x - y;
};

int main() {
    int arr[] = {
        10,
        20,
        4,
        5,
        4,
        0,
        13,
        5,
        32
    };

    auto *heap = new Heap<int>(arr, 9, int_cmp);
    heap->sort();

    for (int i = 0; i < heap->len(); i++) {
        cout << "Heap value: " << heap->get_array()[i] << endl;
    }

    delete heap;

    return 0;
};
