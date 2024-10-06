class Solution {
public:
    int get(int first, int second, int third, vector<string>& ns) {
        string curr = ns[first] + ns[second] + ns[third];
        int res = 0;
        for (int i = 0; i < curr.length(); i++) {
            res = (res << 1) + (curr[i] - '0');
        }
        return res;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string> ns;
        for (int n : nums) {
            std::string binary = std::bitset<32>(n).to_string(); //"00000000000000000000000010000000"
            binary.erase(0, binary.find_first_not_of('0')); //"10000000"
            ns.push_back(binary);
        }
        int res = get(0, 1, 2, ns);
        if (int test = get(0, 2, 1, ns); test > res) {
            res = test;
        }
        if (int test = get(1, 0, 2, ns); test > res) {
            res = test;
        }
        if (int test = get(1, 2, 0, ns);  test > res) {
            res = test;
        }
        if (int test = get(2, 0, 1, ns);  test > res) {
            res = test;
        }
        if (int test = get(2, 1, 0, ns);  test > res) {
            res = test;
        }
        return res;
    }
};