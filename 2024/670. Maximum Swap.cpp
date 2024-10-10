class Solution {
public:
    int maximumSwap(int num) {
        string ns = to_string(num);
        string ons = ns;
        sort(ns.begin(), ns.end(), greater<char>());
        for (int i = 0; i < ns.length(); i++) {
            if (ns[i] != ons[i]) {
                for (int j = ons.length() - 1; j > i; j--) {
                    if (ons[j] == ns[i]) {
                        swap(ons[i], ons[j]);
                        break;
                    }
                }
                break;
            }
        }
        return stoi(ons);
    }
};