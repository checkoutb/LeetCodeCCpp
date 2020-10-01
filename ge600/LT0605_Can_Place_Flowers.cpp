
#include "../header/myheader.h"

class LT0605
{
public:


// D D

//    int count = 1;
//    int result = 0;
//    for(int i=0; i<flowerbed.length; i++) {
//        if(flowerbed[i] == 0) {
//            count++;
//        }else {
//            result += (count-1)/2;
//            count = 0;
//        }
//    }
//    if(count != 0) result += count/2;
//    return result>=n;
// 也是记录2个1之间的长度。


//        for(int i = 0; i < flowerbed.length && count < n; i++) {
//            if(flowerbed[i] == 0) {
//	     //get next and prev flower bed slot values. If i lies at the ends the next and prev are considered as 0.
//               int next = (i == flowerbed.length - 1) ? 0 : flowerbed[i + 1];
//               int prev = (i == 0) ? 0 : flowerbed[i - 1];
//               if(next == 0 && prev == 0) {
//                   flowerbed[i] = 1;
//                   count++;
//               }
//            }
//        }
// 前后都是0，就种菜。



//Runtime: 36 ms, faster than 79.78% of C++ online submissions for Can Place Flowers.
//Memory Usage: 20.6 MB, less than 13.81% of C++ online submissions for Can Place Flowers.
    bool lt0605a(vector<int>& flowerbed, int n)
    {
        int lst = -2;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 1)
            {
                n -= ((i - lst - 2 < 0) ? 0 : (i - lst - 2)) / 2;
                lst = i;
            }
        }
        int t = (((int) flowerbed.size() - lst - 1) < 0 ? 0 : ((int) flowerbed.size() - lst - 1)) / 2;
        n -= t;
        return n <= 0;
    }


};

int main()
{

    vector<int> v = {1,0,0,0,1,0,0};
    int n = 2;

    LT0605 lt;

    cout<<lt.lt0605a(v, n)<<endl;

    return 0;
}
