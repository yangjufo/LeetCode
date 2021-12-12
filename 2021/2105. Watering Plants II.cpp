class Solution {
public:
    int minimumRefill(vector<int>& p, int cA, int cB) {
        int wA = cA, wB = cB, left = 0, right = (int)p.size() - 1, res = 0;
        while (left <= right) {
            if (left == right) {
                if (wA < p[left] && wB < p[right]) {
                    res++;
                }
                break;
            } else {
                if (p[left] > wA) {
                    wA = cA;
                    res++;
                }
                wA -= p[left];
                left++;
                if (p[right] > wB) {
                    wB = cB;
                    res++;
                }
                wB -= p[right];
                right--;
            }            
        }
        return res;
    }
};