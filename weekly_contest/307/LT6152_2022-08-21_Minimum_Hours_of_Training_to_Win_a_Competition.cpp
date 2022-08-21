
#include "../../header/myheader.h"

class LT6152
{
public:



    // AC
    // ... 第一题就感觉炸裂。。真长。
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience)
    {
        int ans = 0;
        int en = initialEnergy;
        int ex = initialExperience;
        int sz1 = energy.size();
        for (int i = 0; i < sz1; ++i)
        {
            //if (en <= energy[i] || ex <= experience[i])
            //{
            //    int t2 = max(experience[i] - ex, energy[i] - en) + 1;
            //    ans += t2;
            //    en += t2;
            //    ex += t2;
            //}

            if (en <= energy[i])
            {
                int t2 = energy[i] - en + 1;
                ans += t2;
                en += t2;
            }
            if (ex <= experience[i])
            {
                int t2 = experience[i] - ex + 1;
                ans += t2;
                ex += t2;
            }

            en -= energy[i];
            ex += experience[i];
        }
        return ans;
    }

};

int main()
{

    LT6152 lt;

    int en = 5, ex = 3;
    myvi v1 = { 1,4,3,2 };
    myvi v2 = { 2,6,3,1 };

    cout << lt.minNumberOfHours(en, ex, v1, v2) << endl;

    return 0;
}
