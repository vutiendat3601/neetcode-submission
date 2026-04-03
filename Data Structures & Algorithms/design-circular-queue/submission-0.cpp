class MyCircularQueue {
private:
    int fidx = 0, ridx = -1, k = 0, size = 0;
    vector<int> data;

public:
    MyCircularQueue(int k) {
        this->k = k;
        this->data = vector<int>(k, -1);
    }

    bool enQueue(int value) {
        if (size < k) {
            ridx++;
            data[ridx % k] = value;
            size++;
            return 1;
        }
        return 0;
    }

    bool deQueue() {
        if (size) {
            size--;
            fidx++;
            return 1;
        }
        return 0;
    }

    int Front() {
        if (size) {
            return data[fidx % k];
        }
        return -1;
    }

    int Rear() {
        if (size) {
            return data[ridx % k];
        }
        return -1;
    }

    bool isEmpty() { return !size; }

    bool isFull() { return size == k; }
};