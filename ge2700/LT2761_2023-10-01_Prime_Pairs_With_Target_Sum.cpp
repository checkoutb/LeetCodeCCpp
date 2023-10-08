
#include "../header/myheader.h"

class LT2761
{
public:

// D D

//        for(int i=2;i*i<=n;i++){
//          if(sieve[i]==0){
//            for(int j=i*i;j<=n;j+=i){
//              sieve[j] = 1;
//            }
//          }
//        }



//        int l = 0, r = upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1;
//        while(l <= r){
//            if(primes[l] + primes[r] == n){
//                ans.push_back({primes[l], primes[r]});
//                l++, r--;
//            } else if(primes[l] + primes[r] < n){
//                l++;
//            } else { //primes[l] + primes[r] > n
//                r--;
//            }
//        }




//Runtime868 ms
//Beats
//42.77%
//Memory74.8 MB
//Beats
//37.98%

// 10^6       1000  1000
    vector<vector<int>> findPrimePairs(int n)
    {
        vector<vector<int>> ans;

        vector<bool> vb(n);
        vector<int> vi = {2};
        for (int i = 3; i < n; i += 2)
        {
            if (vb[i] == false)
            {
                vi.push_back(i);
                for (int j = i + i; j < n; j += i)
                    vb[j] = true;
            }
        }
        int t2 = 0;
        for (int i : vi)
        {
            t2 = n - i;
            if (t2 < i)
                break;

            if (vb[t2] == false && (t2 % 2 == 1 || t2 == 2))
            {
                ans.push_back({i, t2});
            }
        }

        return ans;
    }

};

int main()
{

    LT2761 lt;


    return 0;
}
