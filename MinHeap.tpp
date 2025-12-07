template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
     while (i > 0) {
        int p = parent(i);
        if (data[i] < data[p]) {
            swap(data[i], data[p]);
            i = p;
        } else {
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
     int n = size();

    while (true) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < n && data[l] < data[smallest])
            smallest = l;
        if (r < n && data[r] < data[smallest])
            smallest = r;

        if (smallest != i) {
            swap(data[i], data[smallest]);
            i = smallest;
        } else {
            break; // heap property restored
        }
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
     data.push_back(value);
    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    // TODO: Implement removing the root element.
     if (empty())
        throw runtime_error("Heap is empty");

    T rootValue = data[0];

    // Move last element to root and pop back
    swap(data[0], data.back());
    data.pop_back();

    // Restore heap property if not empty
    if (!empty())
        siftDown(0);

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
    if (index < size()) {
        if (index > 0 && data[index] < data[parent(index)]) {
            siftUp(index);
        } else {
            siftDown(index);
        }
    }
}
