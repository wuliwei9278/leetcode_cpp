#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    	unordered_set<char> s1 = {'q','w','e','r','t','y','u','i','o','p'};
    	unordered_set<char> s2 = {'a','s','d','f','g','h','j','k','l'};
    	unordered_set<char> s3 = {'z','x','c','v','b','n','m'};
    	vector<string> res;
    	for (string word : words) {
    		int one = 0, two = 0, three = 0;
    		for (char c : word) {
    			if (s1.count(c)) one = 1;
    			if (s2.count(c)) two = 1;
    			if (s3.count(c)) three = 1;
    			if (one + two + three > 1) {
    				break;
    			}
    		}
    		if (one + two + three == 1) {
    			res.push_back(word);
    		}
    	}
        return res;
    }
};

int main()
{
	Solution s;
	vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
	vector<string> v = s.findWords(words);
    for (string s : v){
        cout << s << endl;
    }
	return 0;
}