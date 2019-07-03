
#include "../header/myheader.h"

class LT0401
{
public:


// discuss

//    List<String> times = new ArrayList<>();
//    for (int h=0; h<12; h++)
//        for (int m=0; m<60; m++)
//            if (Integer.bitCount(h * 64 + m) == num)
//                times.add(String.format("%d:%02d", h, m));
//    return times;

//    vector<string> rs;
//    for (int h = 0; h < 12; h++)
//    for (int m = 0; m < 60; m++)
//        if (bitset<10>(h << 6 | m).count() == num)
//            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
//    return rs;
// emplace 意思应该是 inplace, 不会生成临时对象。
//    bv.push_back(1);        // 隐式转换生成临时变量
//    bv.push_back(Bar(1));   // 显示构造临时变量
//    bv.emplace_back(1);     // 没有临时变量
//
//    //bv.push_back({1, 2.0});   //  无法进行隐式转换
//    bv.push_back(Bar(1, 2.0));  //  显示构造临时变量
//    bv.emplace_back(1, 2.0);    //  没有临时变量
// 直接把构造器参数传了进去。不会生成临时变量。
// 不过这里应该没有提升吧。毕竟operator+后生成string了，已经有临时变量了。


//    private static void dfs(int[] a, int i, int k, List<String> list, int num) {
//        if(k == num) {
//            String res = getTime(a);
//            if(res != null)
//                list.add(res);
//            return;
//        }
//        if(i == a.length) {
//            return;
//        }
//        a[i] = 0;
//        dfs(a, i+1, k, list, num);
//
//        a[i] = 1;
//        dfs(a, i+1, k+1, list, num);
//
//        a[i] = 0;
//    }
// 每个led，亮或不亮。
// 我的是，每个名额，点亮后续队列中的某一盏灯。


//  Runtime: 4 ms, faster than 78.70% of C++ online submissions for Binary Watch.
//  Memory Usage: 8.6 MB, less than 76.96% of C++ online submissions for Binary Watch.

    vector<string> lt0401a(int num)
    {
        vector<string> ans;
//        recursiona1(ans, new int[10], 0, num);       // 8,4,2,1,32,16...1         // 可以，但是int[] 是随机数。
        int arr[10] = {0};
        recursiona1(ans, arr, 0, num);
        return ans;
    }

    void recursiona1(vector<string>& ans, int arr[], int index, int remain)
    {
        #ifdef __test
//        cout<<index<<", "<<remain<<endl;
//        cout<<arr[5]<<endl;
        #endif // __test
        if (remain == 0)
        {
            int hours = 8 * arr[0] + 4 * arr[1] + 2 * arr[2] + 1 * arr[3];
            int minutes = 32 * arr[4] + 16 * arr[5] + 8 * arr[6] + 4 * arr[7] + 2 * arr[8] + 1 * arr[9];
            if (hours <= 11 && minutes <= 59)
            {
//                string str = hours + ":" + (minutes >= 10 ? "" : " ") + minutes;        // char* 没有 operator+
//                string m;
//                if (minues >= 10)
//                    m = "" + minutes;
//                else
//                    m = " " + minutes;             // minutes 也是指针。
//                string str = hours + ":" + m;           // 好像把hours当作指针了。。
                string str = to_string(hours) + ":" + (minutes >= 10 ? "" : "0") + to_string(minutes);

                #ifdef __test
//                cout<<str<<endl;
//                cout<<"                     "<<m<<endl;
                #endif // __test

                ans.push_back(str);
            }
            return;
        }
        for (int i = index; i < 11 - remain; i++)
        {
            #ifdef __test
//            cout<<i<<endl;
            #endif // __test

            arr[i] = 1;
            recursiona1(ans, arr, i + 1, remain - 1);
            arr[i] = 0;
        }
    }
};

int main()
{
    int n = 2;

    LT0401 lt;
    vector<string> v2 = lt.lt0401a(n);
    cout<<endl;
    for_each(v2.begin(), v2.end(), fun_cout_s);
    cout<<endl;

    return 0;
}
