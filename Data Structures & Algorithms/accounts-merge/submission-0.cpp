class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        multimap<string, set<string>> adj;
        for (auto& acc : accounts) {
            auto [l, r] = adj.equal_range(acc[0]);
            bool cont = l != r;
            if (cont) {
                for (auto it = l; it != r; it++) {
                    for (int i = 1; i < acc.size(); i++) {
                        if (it->second.count(acc[i])) {
                            it->second.insert(acc.begin() + 1, acc.end()),
                                cont = 0;
                            break;
                        }
                    }
                    if (!cont)
                        break;
                }
                if (cont)
                    adj.insert(
                        {acc[0], set<string>(acc.begin() + 1, acc.end())});
            } else {
                adj.insert({acc[0], set<string>(acc.begin() + 1, acc.end())});
            }
        }
        for (auto it1 = adj.begin(); it1 != adj.end(); it1++) {
            auto it2 = next(it1);
            while (it2 != adj.end() && it1->first == it2->first) {
                bool merged = 0;
                for (auto const& e : it2->second) {
                    if (it1->second.count(e)) {
                        it1->second.insert(it2->second.begin(), it2->second.end());
                        it2 = adj.erase(it2);
                        merged = 1;
                        it1 = adj.begin();
                        break;
                    }
                }
                if (!merged) it2++;
            }
        }
        for (auto& [k, v] : adj) {
            vector<string> ans_item;
            ans_item.push_back(k);
            ans_item.insert(ans_item.end(), v.begin(), v.end());
            ans.push_back(ans_item);
        }
        return ans;
    }
};