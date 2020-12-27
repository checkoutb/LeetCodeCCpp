
#include "../header/myheader.h"

class LT0412
{
public:

// D D

//return['FizzBuzz'[i%-3&-4:i%-5&8^12]or`i`for i in range(1,n+1)]

//return ['Fizz' * (not i % 3) + 'Buzz' * (not i % 5) or str(i) for i in range(1, n+1)]


//        for(int i=1,fizz=0,buzz=0;i<=n ;i++){
//            fizz++;
//            buzz++;
//            if(fizz==3 && buzz==5){
//                ret.add("FizzBuzz");
//                fizz=0;
//                buzz=0;
//            }else if(fizz==3){
//                ret.add("Fizz");
//                fizz=0;
//            }else if(buzz==5){
//                ret.add("Buzz");
//                buzz=0;
//            }else{
//                ret.add(String.valueOf(i));
//            }
//        }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fizz Buzz.
//Memory Usage: 7.6 MB, less than 92.73% of C++ online submissions for Fizz Buzz.
    vector<string> lt0412a(int n)
    {
        vector<string> ans(n);
        for (int i = 1; i <= n; ++i)
        {
            if (i % 3 == 0 && i % 5 == 0)
                ans[i - 1] = "FizzBuzz";
            else if (i % 3 == 0)
                ans[i - 1] = "Fizz";
            else if (i % 5 == 0)
                ans[i - 1] = "Buzz";
            else
                ans[i - 1] = std::to_string(i);
        }
        return ans;
    }

};

int main()
{
    int n{15};

    LT0412 lt;

    vector<string> v = lt.lt0412a(n);

    for (string& s : v)
        cout<<s<<endl;

    return 0;
}
