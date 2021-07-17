class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i1 = 1; i1 <= 9 && i1 <= n; i1++) {
            int num1 = i1;
            res.push_back(num1);
            for (int i2 = 0; i2 <= 9 && num1 * 10 + i2 <= n; i2++) {
                int num2 = num1 * 10 + i2;
                res.push_back(num2);
                for (int i3 = 0; i3 <= 9 && num2 * 10 + i3 <= n; i3++) {
                    int num3 = num2 * 10 + i3;
                    res.push_back(num3);
                    for (int i4 = 0; i4 <= 9 && num3 * 10 + i4 <= n; i4++) {
                        int num4 = num3 * 10 + i4;
                        res.push_back(num4);
                        for (int i5 = 0; i5 <= 9 && num4 * 10 + i5 <= n; i5++) {
                            res.push_back(num4 * 10 + i5);
                        }
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> list;
        int curr = 1;
        for (int i = 1; i <= n; i++) {
            list.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else if (curr % 10 != 9 && curr + 1 <= n) {
                curr++; 
            } else {
                while ((curr / 10) % 10 == 9) {
                    curr /= 10;
                }
                curr = curr / 10 + 1;
            }
        }
        return list;
    }
};