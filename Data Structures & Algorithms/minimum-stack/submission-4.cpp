class MinStack {
   private:
    int index = -1;
    int capacity;
    vector<long> data;

   public:
    MinStack() {
        capacity = 3 * 1E4 + 1;
        data.assign(capacity, LONG_MIN);
    }

    void push(int val) {
        if (index + 1 < capacity) index++, data[index] = val;
    }

    void pop() {
        if (index >= 0) data[index] = LONG_MIN, index--;
    }

    int top() {
        if (index >= 0) return data[index];
        return -1;
    }

    int getMin() {
        int mn = INT_MAX;
        for (int i = 0; i <= index; i++) mn = min(mn, (int)data[i]);
        return mn;
    }
};
