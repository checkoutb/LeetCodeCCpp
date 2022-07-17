
#include "../../header/myheader.h"

class LT6122
{
public:





    //8845 / 24326	Ouha 	12	1:24 : 17	0 : 05 : 01 	0 : 11 : 14 	1 : 14 : 17 2



    // g...


    // tle
    int lta(vector<int>& nums, vector<int>& numsDivide)
    {
        int sz1 = nums.size();
        int sz2 = numsDivide.size();
        sort(begin(nums), end(nums));

        if (nums[0] == 1)
            return 0;

        sort(begin(numsDivide), end(numsDivide));

        vector<int> nn;
        vector<int> nd;
        

        for (int i = 0; i < sz2; ++i)
        {
            for (int j = 0; j < nd.size(); ++j)
            {
                if (numsDivide[i] % nd[j] == 0)
                    goto AAA;
            }
            nd.push_back(numsDivide[i]);
            AAA:
            continue;
        }
        
#ifdef __test
        showVectorInt(nd);
#endif

        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > nd[0])
                break;

            t2 = nums[i];

            for (int j = 0; j < nn.size(); ++j)
            {
                if (t2 % nn[j] == 0)
                    goto BBB;
            }

            nn.push_back(t2);

#ifdef __test
            cout << t2 << endl;
#endif

            for (int j = 0; j < nd.size(); ++j)
            {
                if (nd[j] % t2 != 0)
                {
                    goto BBB;
                }
            }
            return i;

            BBB:
            continue;

        }

        return -1;
    }


    // error, 错了。。 质因数没有用。 3 6 
    // 质因数
    int minOperations(vector<int>& nums, vector<int>& numsDivide)
    {
        int sz1 = nums.size();
        int sz2 = numsDivide.size();
        sort(begin(nums), end(nums));

        if (nums[0] == 1)
            return 0;

        sort(begin(numsDivide), end(numsDivide));

        int mx3 = sqrt(numsDivide[sz2 - 1]);

        vector<bool> prm(mx3 + 1, true);

        for (int i = 2; i <= mx3; ++i)
        {
            if (prm[i])
            {
                for (int j = i + i; j <= mx3; j += i)
                    prm[i] = false;
            }
        }

        vector<int> vi;
        for (int i = 2; i <= mx3; ++i)
        {
            if (prm[i])
            {
                vi.push_back(i);
            }
        }
        vector<int> vcnt(vi.size(), INT_MAX);
        for (int i = 0; i < sz2; ++i)
        {
            if (i != 0 && numsDivide[i] == numsDivide[i - 1])
                continue;

            int n = numsDivide[i];

            map<int, int> map2 = getfactor(n, vi);

            for (auto& p : map2)
            {
                vcnt[p.first] = min(vcnt[p.first], p.second);
            }

        }

#ifdef __test
        showVectorInt(vi);
        showVectorInt(vcnt);
#endif

        for (int i = 0; i < sz1; ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > numsDivide[0])
                break;

            int n = nums[i];
            map<int, int> map2 = getfactor(n, vi);

            for (int j = 0; j < vcnt.size(); j++)
            {
                int t2 = vi[j];
                if (map2.find(t2) != map2.end() && map2[t2] < vcnt[j])
                    goto AAA;
            }

            return i;

            AAA:
            continue;
        }

        return -1;
    }

    map<int, int> getfactor(int n, vector<int>& vi)
    {
        map<int, int> map2;
        if (n == 1)
        {
            map2[1] = 1;
            return map2;
        }

        for (int i = 0; i < vi.size() && n != 1; ++i)
        {
            int t2 = vi[i];
            while (n % t2 == 0)
            {
#ifdef __test
                if (t2 == 2)
                {
                    cout << " ..... " << n << endl;
                }
#endif
                map2[i]++;
                n /= t2;
            }
        }
        return map2;
    }

};

int main()
{

    LT6122 lt;

    myvi v = { 2,3,2,4,3 };
    myvi v2 = { 9,6,9,3,15 };

    cout << lt.lta(v, v2) << endl;

    return 0;
}
