class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> idx;
        for (int i = 0; i < order.size(); i++)
            idx[order[i]] = i;
        for (int i = 0; i < words.size() - 1; i++) {
            int j = 0;
            string a = words[i], b = words[i + 1];
            if (a != b && a.starts_with(b))
                return 0;
            while (j < a.size() && j < b.size()) {
                if (idx[a[j]] < idx[b[j]])
                    break;
                if (idx[a[j]] > idx[b[j]])
                    return 0;
                j++;
            }
        }
        return 1;
    }
};