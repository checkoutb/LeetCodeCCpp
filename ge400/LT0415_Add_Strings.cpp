
#include "../header/myheader.h"

class LT0415
{
public:


// details
//        string result;
//        int carry = 0;
//        while(len1 >= 0 || len2 >=0)
//        {
//            int n1 = len1 >= 0? num1[len1] - '0': 0;
//            int n2 = len2 >= 0? num2[len2] - '0': 0;
//            result.push_back('0' + ((n1 + n2 + carry) % 10));
//            carry = (n1 + n2 + carry) / 10;
//            len1--;
//            len2--;
//        }
//
//        if(carry)
//        {
//            result.push_back('0' + carry);
//        }
//
//        std::reverse(result.begin(), result.end());
//        return result;
// 不够就是0。int转bool。reverse。push_back Append character to string

// i来作为循环下标。通过i和len1，len2对比来确定0 or 值。
// sum和10 比较。

//        int i = num1.length() - 1, j = num2.length() - 1, c = 0;
//        while (i >= 0 || j >= 0){
//            int first = (i >= 0) ? num1[i--] - '0' : 0;
//            int second = (j >= 0) ? num2[j--] - '0' : 0;
//            int sum = first + second + c;
//            res.insert(res.begin(), sum % 10 + '0');
//            c = sum / 10;
//        }
//        if (c) res.insert(res.begin(), '1');
//        return res;
// 进位必然是1.


// discuss
//    int sum = 0, i = num1.length() - 1, j = num2.length() - 1;
//    string str;
//    while (i >= 0 || j >= 0 || sum > 0) {
//        if (i >= 0) sum += (num1[i--] - '0');
//        if (j >= 0) sum += (num2[j--] - '0');
//        str.insert(0, 1, (sum % 10) + '0');
//        sum /= 10;
//    }
//    return str;








//Runtime: 4 ms, faster than 92.70% of C++ online submissions for Add Strings.
//Memory Usage: 57.8 MB, less than 28.19% of C++ online submissions for Add Strings.

    string lt0415a(string num1, string num2)
    {
        string ans;
        int sz1 = num1.size();
        int sz2 = num2.size();
        int t1 = 0;

        string::reverse_iterator it1 = num1.rbegin();       // 无法两行合并到for中。。还好下面需要。
        string::reverse_iterator it2 = num2.rbegin();
        for (; it1 != num1.rend() && it2 != num2.rend(); it1++, it2++)
        {
            int n1 = *it1 - '0';
            int n2 = *it2 - '0';
            int sum = n1 + n2 + t1;
            ans = to_string(sum % 10) + ans;
            t1 = sum / 10;
        }

        if (sz1 == sz2)
        {
            if (t1 != 0)
                ans = to_string(t1) + ans;
        }
        else
        {
            string::reverse_iterator it3 = sz1 > sz2 ? it1 : it2;
            string::reverse_iterator end3 = sz1 > sz2 ? num1.rend() : num2.rend();
            while (t1 != 0 && it3 != end3)
            {
                int n3 = *it3 - '0';
                int sum = n3 + t1;
                ans = to_string(sum % 10) + ans;
                t1 = sum / 10;
                it3++;
            }
            if (t1 != 0)
                ans = to_string(t1) + ans;
            else
            {
                string s3 = sz1 > sz2 ? num1 : num2;
                ans = s3.substr(0, s3.size() - ans.size()) + ans;
            }
        }

        return ans;
    }
};


int main()
{
    string n1 = "123456";
    string n2 = "789";

    LT0415 lt;
    cout<<endl<<lt.lt0415a(n1, n2)<<endl;

    return 0;
}
