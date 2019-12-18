
#include "../header/myheader.h"

class LT0475
{
public:





//
//return *max_element(res.begin(), res.end());

//        TreeSet<Integer> treeset = new TreeSet<>();
//        for (int heater : heaters) treeset.add(heater);
//        int res = 0;
//        for (int house : houses) {
//            Integer upper = treeset.ceiling(house);
//            Integer lower = treeset.floor(house);
//            res = Math.max(res, Math.min(upper == null ? Integer.MAX_VALUE : upper - house, lower == null ? Integer.MAX_VALUE : house - lower));
//        }
//        return res;
// 知道红黑树，但没用过。。。




//Runtime: 92 ms, faster than 23.70% of C++ online submissions for Heaters.
//Memory Usage: 11.1 MB, less than 71.43% of C++ online submissions for Heaters.
    int lt0475b(vector<int>& houses, vector<int>& heaters)
    {
        if (heaters.size() == 1)
        {
            int a1 = heaters[0];
            return std::max(std::abs(houses[0] - a1), std::abs(houses[houses.size() - 1] - a1));
        }

        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());

        int j = 1;
        int a1 = heaters[j - 1];
        int a2 = heaters[j];
        int ans = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            int radius = INT_MAX;
            int h = houses[i];
            while (h > a2 && j < heaters.size() - 1)
            {
                j++;
                a1 = a2;
                a2 = heaters[j];
            }
            radius = std::min(abs(h - a1), abs(h - a2));

            #ifdef __test
            cout<<radius<<" ,"<<endl;
            #endif // __test

            ans = max(radius, ans);
        }
        return ans;
    }


    // 27 / 30 . tle
    int lt0475a(vector<int>& houses, vector<int>& heaters)
    {
        if (heaters.size() == 1)
        {
            int a1 = heaters[0];
            return std::max(std::abs(houses[0] - a1), std::abs(houses[houses.size() - 1] - a1));
        }

        int arr[houses.size()] = {0};
        for (int i = 0; i < houses.size(); i++)
        {
            arr[i] = INT_MAX;
        }

        for (int i = 0; i < houses.size(); i++)
        {
            for (int j = 0; j < heaters.size(); j++)
            {
                arr[i] = std::min(arr[i], std::abs(heaters[j] - houses[i]));
            }
        }
        int ans = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            ans = std::max(ans, arr[i]);
        }
        return ans;
    }
};

int main ()
{
    vector<int> h = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
    vector<int> a = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};

    LT0475 lt;

    cout<<lt.lt0475b(h, a)<<endl;
    cout<<endl<<lt.lt0475a(h, a)<<endl;

    return 0;
}
