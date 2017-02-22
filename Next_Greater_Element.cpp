#include <unordered_map>;
#include <vector>;
#include <stack>;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    	vector<int> res(findNums.size());
    	stack<int> s;
    	unordered_map<int, int> m;
    	for (int i : nums) {
    		while (!s.empty() && s.top() < i) {
    			m[s.top()] = i;
    			s.pop();
    		}
    		s.push(i);
    	}
    	int c = 0;
    	for (int i : findNums) {
    		res[c] = m.count(i) > 0 ? m[i] : -1;
    		c++;
    	}
    	return res;
    }
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    	vector<int> res(findNums.size());
    	unordered_map<int, int> m;
    	for (int i = 0; i < nums.size(); ++i) {
    		m[nums[i]] = i;
    	}
    	for (int i = 0; i < findNums.size(); ++i) {
    		res[i] = -1;
    		int start = m[findNums[i]] + 1;
    		for (int j = start; j < nums.size(); ++j) {
    			if (nums[j] > findNums[i]) {
    				res[i] = nums[j];
    				break;
    			}
    		}
    	}
    	return res;
    }
};