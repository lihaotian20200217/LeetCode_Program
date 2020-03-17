#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> len(nums.size(),1);
        vector<int> cou(nums.size(),1);
        for (int j = 1; j < nums.size(); j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (nums[i] < nums[j])
                {
                    if (len[i] >= len[j])
                    {
                        len[j] = len[i] + 1;
                        cou[j] = cou[i];
                    }
                    else if (len[j] == len[i] + 1)
                    {
                        cou[j] += cou[i];
                    }
                }
            }
        }
        int length = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (len[i] > length) length = len[i];
        }
        int res = 0;
        for (int i = 0; i < cou.size(); i++)
        {
            if (length == len[i]) res += cou[i];
        }
        return res;
    }
};

int main()
{
    Solution A;
    vector<int> arr = {1,3,5,4,7};
    cout << A.findNumberOfLIS(arr) << endl;
    return 0;
}
