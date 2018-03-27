class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map <char, int> sub;
	    int length = 0;
	    int max_length = 0;
	    for (int i = 0; i < s.length(); i++) {				
		    if (sub.count(s[i])) {
			    max_length = length > max_length ? length : max_length;
			    i = sub[s[i]];
			    sub.clear();
			    length = 0;			
		    }
		    else {
			    length++;
		 	    sub.insert(pair<char, int>(s[i], i));
		    }
	    }
	    max_length = length > max_length ? length : max_length;
        return max_length;
    }
};