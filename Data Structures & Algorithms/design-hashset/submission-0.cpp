class MyHashSet {
vector<bool> keys;
public:
    MyHashSet() : keys(1000001, 0) {}
    
    void add(int key) {
        if (!keys[key]) {
            keys[key] = 1;
        }
    }
    
    void remove(int key) {
        keys[key] = 0;
    }
    
    bool contains(int key) {
        return keys[key];
    }
};

// Boolean Array, O(1)

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */