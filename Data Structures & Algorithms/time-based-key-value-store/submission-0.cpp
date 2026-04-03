class TimeMap {
private:
    unordered_map<int, unordered_map<string, string>> vals;
    vector<int> timestamps;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (!vals.count(timestamp)) {
            vals[timestamp] = unordered_map<string, string>();
        }
        vals[timestamp][key] = value;
        timestamps.push_back(timestamp);
        sort(timestamps.rbegin(), timestamps.rend());
    }

    string get(string key, int timestamp) {
        int l = 0, r = timestamps.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (timestamps[mid] > timestamp) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        for (int i = l; i < timestamps.size(); i++) {
            if (vals[timestamps[i]].count(key)) {
                return vals[timestamps[i]][key];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */