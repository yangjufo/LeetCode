class Solution {
public:
    int convertTime(string current, string correct) {
        int hc = stoi(current.substr(0, 2)), mc = stoi(current.substr(3, 2));
        int ht = stoi(correct.substr(0, 2)), mt = stoi(correct.substr(3, 2));
        if (mc > mt) {
            ht -= 1;
            mt += 60;
        }
        int count = ht - hc, diff = mt - mc;
        if (diff >= 15) {
            count += diff / 15;
            diff %= 15;
        }
        if (diff >= 5) {
            count += diff / 5;
            diff %= 5;
        }
        count += diff;
        return count;
    }
};