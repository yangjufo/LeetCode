class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first, second, third;
        first = second = third = 0;
        for (char c : firstWord) {
            first = first * 10 + (c - 'a');
        }
        for (char c : secondWord) {
            second = second * 10 + (c - 'a');
        }
        for (char c : targetWord) {
            third = third * 10 + (c - 'a');
        }
        return first + second == third;
    }
};