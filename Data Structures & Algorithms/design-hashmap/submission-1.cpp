class MyHashMap {
private:
    int num_of_keys = 1000000;
    vector<int> mp = vector<int>(num_of_keys, -1);

    int hash(int key) { return key % num_of_keys; }

public:
    MyHashMap() {}

    void put(int key, int value) {
        mp[hash(key)] = value;
    }

    int get(int key) {
        return mp[hash(key)];
    }

    void remove(int key) {
        mp[hash(key)] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */