class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> argsorts;
        for (int i = 0; i < nums.size(); ++i) {
            argsorts.push_back(i);
        }
        
        sort(argsorts.begin(), argsorts.end(), [&](int a, int b) {return nums[a] > nums[b];});
        //for (int i = 0; i < argsorts.size(); ++i) {
        //    cout << argsorts[i] << " ";
        //}
        vector<string> res(nums.size());
        for (int i = 0; i < argsorts.size(); ++i) {
            if (i == 0) res[argsorts[0]] = "Gold Medal";
            else if (i == 1) res[argsorts[1]] = "Silver Medal";
            else if (i == 2) res[argsorts[2]] = "Bronze Medal";
            else res[argsorts[i]] = to_string(i + 1);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        for (int i=0; i < nums.size(); i++)
            pq.push({nums[i], i});
        int count = 1;    
        vector<string> res(nums.size());
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            if (count==1)
                res[p.second] = "Gold Medal";
            else if (count==2)
                res[p.second] = "Silver Medal";
            else if (count==3)
                res[p.second] = "Bronze Medal";
            else
                res[p.second] = to_string(count);
            count++;
        }
        return res;
    }
};
 
// if only ranking for top 3 is wanted 
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        /*struct cmp {
          bool operator()(pair<int,int> &a, pair<int,int> &b) {
              return a.first > b.first;
          }  
        };
        */
        //priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int count = 0;
        for (int i=0; i < nums.size(); i++) {
            if (count < 3) {
                pq.push({nums[i], i}); 
                count++;
            } else {
                auto p = pq.top();
                if (nums[i] > p.first) {
                    pq.pop();
                    pq.push({nums[i], i});
                }
            }
        }
            
        vector<string> str = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> res(nums.size(), "");
        
        
        while(!pq.empty()){
            count--;
            auto p = pq.top();
            cout << count << " ";
            cout << p.second << " ";
            cout << p.first << endl;
            res[p.second] = str[count];
            pq.pop();
            
        }
        
        return res;
    }
};