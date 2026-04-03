class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mc;
        multimap<int, int> ms;
        for (int num : nums) {
            mc[num] = mc.count(num) ? mc[num] + 1 : 1;
        }
        for (auto e : mc) {
            ms.insert({e.second, e.first});
        }
        vector<int> ans;
        auto it = ms.rbegin();
        while (k--) {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};


// Map, Multimap, O(n)