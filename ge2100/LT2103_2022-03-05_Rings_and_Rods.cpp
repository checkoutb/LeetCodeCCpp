
#include "../header/myheader.h"

class LT2103
{
public:

// D D

//return sum(all(color + rod in rings for color in 'RGB')
//           for rod in '0123456789')


//    int rods[10] = {};
//    for (int i = 0; i < rings.size(); i += 2) {
//        int color = rings[i] == 'R' ? 1 : rings[i] == 'G' ? 2 : 4;
//        rods[rings[i + 1] - '0'] |= color;
//    }
//    return count(begin(rods), end(rods), 7);


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rings and Rods.
//Memory Usage: 6.2 MB, less than 95.96% of C++ online submissions for Rings and Rods.
// B0B6G0R6R0R6G9
    int lt2103a(string rings)
    {
        int arr[10] = {0};
        for (int i = 0; i < rings.size(); i += 2)
        {
            switch(rings[i])
            {
            case 'B':
                arr[rings[i + 1] - '0'] |= 1;
                break;
            case 'G':
                arr[rings[i + 1] - '0'] |= 2;
                break;
            case 'R':
                arr[rings[i + 1] - '0'] |= 4;
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == 7)
                ans++;
        }
        return ans;
    }

};

int main()
{

    LT2103 lt;


    return 0;
}
