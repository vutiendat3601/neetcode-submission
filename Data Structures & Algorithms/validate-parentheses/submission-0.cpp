class Solution {
public:
    bool isValid(string s) {
        while (1) {
            size_t pos = string::npos;
            if ((pos = s.find("()")) != string::npos) {
                s.erase(pos, 2);
            } else if ((pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
            } else if ((pos = s.find("[]")) != string::npos) {
                s.erase(pos, 2);
            }  else {
                break;
            }
        }
        return s.empty();
    }
};
