class MyHashMap {
private:
    int num_of_keys = 1000000;
    vector<int> mp;

public:
    MyHashMap() { mp.assign(num_of_keys, -1); }

    void put(int key, int value) {
        auto mod = key % num_of_keys;
        mp[mod] = value;
    }

    int get(int key) {
        auto mod = key % num_of_keys;
        return mp[mod];
    }

    void remove(int key) {
        auto mod = key % num_of_keys;
        mp[mod] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */