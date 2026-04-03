class MyHashSet {
private:
    const int N = 1000001;
    vector<bool> data;

public:
    MyHashSet() { data = vector<bool>(this->N, 0); }

    void add(int key) { data[key % N] = 1; }

    void remove(int key) { data[key % N] = 0; }

    bool contains(int key) { return data[key % N]; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */