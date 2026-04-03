class FreqStack {
private:
    unordered_map<int, int> cnt;
    list<pair<int, int>> mn;

public:
    FreqStack() {}

    void push(int val) {
        cnt[val]++;
        pair<int, int> back = mn.back();
        auto p = mn.begin();
        while (p != mn.end() && p->second <= cnt[val]) {
            p++;
        }
        mn.insert(p, {val, cnt[val]});
    }

    int pop() {
        auto back = mn.back();
        mn.pop_back();
        cnt[back.first]--;
        return back.first;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */