class TimeMap {
private:
    unordered_map<string, map<int, string>> mp;

public:
    TimeMap() {    
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (mp.count(key)) {
            auto it = mp[key].upper_bound(timestamp);
            return it == mp[key].begin() ? "" : prev(it)->second;
        }
        return "";
    }
};
