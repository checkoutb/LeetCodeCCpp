
#include "../header/myheader.h"

class LT2037
{
public:


// D D



//Runtime: 14 ms, faster than 49.16% of C++ online submissions for Minimum Number of Moves to Seat Everyone.
//Memory Usage: 18.2 MB, less than 44.92% of C++ online submissions for Minimum Number of Moves to Seat Everyone.
// seat 的 位置， student 的 位置。
// 一个位置可以多个seat，多个student。
// 应该是 都sort，然后一一对应 需要走几步。
    int lt2037a(vector<int>& seats, vector<int>& students)
    {
        std::sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int ans = 0;
        for (int i = 0; i < seats.size(); i++)
        {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }

};

int main()
{

    LT2037 lt;


    return 0;
}
