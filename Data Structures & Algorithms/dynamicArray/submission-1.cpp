class DynamicArray {
private:
    int size = 0;
    int capacity;
    int *data;
public:
    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->data = new int[capacity];
    }

    int get(int i) {
        return *(data + i);
    }

    void set(int i, int n) {
        *(data + i) = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        *(data + size) = n;
        size++;
    }

    int popback() {
        size--;
        return *(data + size);
    }

    void resize() {
        capacity *= 2;
        int *newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            *(newData + i) = *(data + i);
        }
        delete data;
        data = newData;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
