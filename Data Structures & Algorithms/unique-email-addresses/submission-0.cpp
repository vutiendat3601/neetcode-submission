class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        unordered_set<string> s;

        for (auto& email : emails) {
            string f_email = "";
            int i = 0;
            while (i < email.size()) {
                if (email[i] == '+') {
                    do {
                        i++;
                    } while (email[i] != '@');
                }
                if (email[i] == '@') {
                    break;
                } else if (email[i] != '.') {
                    f_email += email[i];
                }
                i++;
            }
            f_email += email.substr(i);
            s.insert(f_email);
        }

        return s.size();
    }
};