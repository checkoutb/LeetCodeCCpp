
#include "../../header/myheader.h"

class LT
{
public:

// D D

//static vector<vector<int>> relation={{1,2,4},{0,2},{1,3},{2},{2,3}};


//This problem basically boils down to number of paths of length N in a directed graph.
//        vector<vector<int>> M={ {0,1,0,0,0},      //Adjacency matrix of graph of the problem.
//                                {1,0,1,0,0},
//                                {1,1,0,1,1},
//                                {0,0,1,0,1},
//                                {1,0,0,0,0}},result(5,vector<int>(5));
//        for(int i=0;i<5;i++)   //Create identity Matrix.
//            result[i][i]=1;
//        int sum=0;
//        n--;
//        while(n)    //log(n) Multiplication.
//        {
//            if(n&1)
//                result=Multiply(M,result);
//            n>>=1;
//            M=Multiply(M,M);
//        }
//https://mathworld.wolfram.com/GraphPower.html


//  vector<vector<int>> moves = { {1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, { 0 } }, v(2, vector<int>(5, 1));
//  while (--n > 0) {
//    for (auto i = 0; i < 5; ++i)
//      v[(n + 1) % 2][i] = accumulate(begin(moves[i]), end(moves[i]), 0,
//        [&](int s, int j) {return (s + v[n % 2][j]) % 1000000007; });
//  }
//  return accumulate(begin(v[0]), end(v[0]), 0, [](int s, int n) { return (s + n) % 1000000007; });







// AC
//    Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
//    Each vowel 'a' may only be followed by an 'e'.
//    Each vowel 'e' may only be followed by an 'a' or an 'i'.
//    Each vowel 'i' may not be followed by another 'i'.
//    Each vowel 'o' may only be followed by an 'i' or a 'u'.
//    Each vowel 'u' may only be followed by an 'a'.
// a -> e
// e -> a/i
// i !-> i    -> aeou
// o -> i/u
// u -> a

// eiu - a
// ai - e
// eo - i
// i - o
// io - u
    int lta(int n)
    {
        int arr[123] = {0};
//        arr['a'] = 1;
//        arr['e'] = 1;
//        arr['i'] = 1;
//        arr['o'] = 1;
//        arr['u'] = 1;
        int arr2[123] = {0};
//        int arr3[5] = {'a','e','i','o','u'};
//        for (int i = 0; i < 5; ++i)
//            arr[arr3[i]] = 1;
        const int MOD = (int) 1E9 + 7;
        string arr3[5] = {"aeiu","eai","ieo","oi","uio"};
        for (int i = 0; i < 5; ++i)
            arr[arr3[i][0]] = 1;
        while (n-- > 1)
        {
            for (int i = 0; i < 5; ++i)
            {
                for (int j = 1; j < arr3[i].size(); ++j)
                {
                    arr2[arr3[i][0]] = (arr2[arr3[i][0]] + arr[arr3[i][j]]) % MOD;
                }
            }
            for (int i = 0; i < 5; ++i)
            {
                arr[arr3[i][0]] = arr2[arr3[i][0]];
                arr2[arr3[i][0]] = 0;
            }
//            arr2['a'] = arr[''] + arr[''] + arr[''];
//            arr2['e'] = arr[''] + arr[''];
//            arr2['i'] = arr[''] + arr[''];
//            arr2['o'] = arr[''];
//            arr2['u'] = arr[''] + arr[''];
//            arr['a']
        }
        int ans = arr[arr3[0][0]];
        for (int i = 1; i < 5; ++i)
        {
            ans = (ans + arr[arr3[i][0]]) % MOD;
        }
        return ans;
    }

};

int main()
{
    myvi v = {1,2,5};

    LT lt;

    for (int i : v)
        cout<<lt.lta(i)<<endl;

    return 0;
}
