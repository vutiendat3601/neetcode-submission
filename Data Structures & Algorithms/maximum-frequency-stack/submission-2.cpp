class FreqStack {
private:
    unordered_map<int, int> cnt;
    unordered_map<int, stack<int>> pop_vals;
    int max_cnt = 0;

public:
    FreqStack() {}

    void push(int val) {
        cnt[val]++;
        if (cnt[val] > max_cnt) {
            max_cnt = cnt[val];
            pop_vals[max_cnt] = stack<int>();
        }
        pop_vals[cnt[val]].push(val);
    }

    int pop() {
        int val = pop_vals[max_cnt].top();
        pop_vals[max_cnt].pop();
        cnt[val]--;
        if (pop_vals[max_cnt].empty()) {
            max_cnt--;
        }
        return val;
    }
};