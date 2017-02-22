// one line in python
// return word[1:].islower() or word.islower() or word.isupper() 
class Solution {
public:
    bool checkAllCapital(string s, int start, int end) {
		if (end <= start) return true;
		int c = 0;
		for (int i = start; i < end; ++i) {
			if (isupper(s[i])) {
				c++;
			}
		}
		return c == (end - start);
	}

	bool checkAllNotCapital(string s, int start, int end) {
		int c = 0;
		for (int i = start; i < end; ++i) {
			if (islower(s[i])) {
				c++;
			}
		}
		return c == (end - start);
	}

    bool detectCapitalUse(string word) {
        if (word.empty()) return true;
        if (islower(word[0])) {
        	return checkAllNotCapital(word, 1, word.size());
        } else {
        	return checkAllNotCapital(word, 1, word.size()) || checkAllCapital(word, 1, word.size());
        }

    }
};