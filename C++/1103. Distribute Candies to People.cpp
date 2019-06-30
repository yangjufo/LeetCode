class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res;
        res.resize(num_people, 0);
        int ind = 0;
        while (candies > 0) {
            if (candies >= ind + 1)
                res[ind % num_people] += ind + 1;
            else
                res[ind % num_people] += candies;
            candies -= ind + 1;
            ind += 1;            
        }
        return res;
    }
};