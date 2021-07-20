
#include "../../header/myheader.h"

class LT
{
public:



};


// D D

//        for(int i=n-1; i>=0; i--)
//        {
//            int j = rand()%(i+1);
//            swap(shuffled[i], shuffled[j]);
//        }


//Fisher-Yates Algorithm and Knuth Shuffle





// AC
class Solution {
    vector<int> ori_vi;
    vector<int> vi;
public:
    Solution(vector<int>& nums) {
        ori_vi = nums;
        vi = nums;
        srand(time(0));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        // no one know if i reset or not.....
        // maybe they want to check if the shuffle is regular... hahahahaha...
        return ori_vi;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int sz1 = vi.size();
        for (int i = vi.size() - 1; i >= 0; --i)
        {
            int idx = rand() % sz1;             // bad?    %(i+1)
            swap(vi[i], vi[idx]);
        }
        return vi;
    }
};

int main()
{
    myvi v = {1,2,3};
    Solution sol(v);
    showVectorInt(sol.shuffle());
    showVectorInt(sol.shuffle());
    showVectorInt(sol.shuffle());
    showVectorInt(sol.shuffle());
    showVectorInt(sol.shuffle());
    showVectorInt(sol.shuffle());


    LT lt;


    return 0;
}
