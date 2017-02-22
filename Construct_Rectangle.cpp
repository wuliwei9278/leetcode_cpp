#include <math.h>
// has to use W, use L gives wrong answer area = 2
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int a = sqrt(area);
        for (int W = a; W > 0; --W) {
        	if (area % W == 0) {
        		return {area / W, W};
        	}
        }
    }
};