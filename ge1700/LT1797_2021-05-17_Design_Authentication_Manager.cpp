
#include "../header/myheader.h"

class LT1797
{
public:



};


// D D


//    int ttl = 0;
//    set<pair<int, string>> time_map;
//    unordered_map<string, int> token_map;
//    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}
//    void clean(int currentTime) {
//        while(!time_map.empty() && begin(time_map)->first <= currentTime) {
//            token_map.erase(begin(time_map)->second);
//            time_map.erase(begin(time_map));
//        }
//    }
//    void generate(string tokenId, int currentTime) {
//        token_map[tokenId] = currentTime + ttl;
//        time_map.insert({currentTime + ttl, tokenId});
//    }
//    void renew(string tokenId, int currentTime) {
//        clean(currentTime);
//        auto it = token_map.find(tokenId);
//        if (it != end(token_map)) {
//            time_map.erase({it->second, it->first});
//            it->second = currentTime + ttl;
//            time_map.insert({currentTime + ttl, tokenId});
//        }
//    }
//    int countUnexpiredTokens(int currentTime) {
//        clean(currentTime);
//        return token_map.size();
//    }
// 加 set 来剔除 过期的元素。



//1 <= tokenId.length <= 5
// 直接一个5维数组。。。

//The values of currentTime across all the function calls will be strictly increasing.
// currentTime 就是 new Timestamp().时序

// 过期 是该时间点的第一个操作。


//Runtime: 80 ms, faster than 76.32% of C++ online submissions for Design Authentication Manager.
//Memory Usage: 30.1 MB, less than 92.26% of C++ online submissions for Design Authentication Manager.
class AuthenticationManager {
    int ttl;
    unordered_map<string, int> tokenToLive;
public:
    AuthenticationManager(int timeToLive) {
        this->ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        this->tokenToLive[tokenId] = currentTime + this->ttl;
    }

    void renew(string tokenId, int currentTime) {
        if (tokenToLive.find(tokenId) != tokenToLive.end())
        {
            if (tokenToLive[tokenId] > currentTime)
            {
                tokenToLive[tokenId] = currentTime + this->ttl;
            }
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        // 加一个 map<int, string> 反向映射。。
        for (unordered_map<string, int>::iterator it = this->tokenToLive.begin(); it != this->tokenToLive.end(); )
        {
            if (it->second > currentTime)
            {
                cnt++;
                it++;
            }
            else
            {
                it = this->tokenToLive.erase(it);
            }
        }
        return cnt;
    }
};


int main()
{


    AuthenticationManager authenticationManager(5); // Constructs the AuthenticationManager with timeToLive = 5 seconds.
    authenticationManager.renew("aaa", 1); // No token exists with tokenId "aaa" at time 1, so nothing happens.
    authenticationManager.generate("aaa", 2); // Generates a new token with tokenId "aaa" at time 2.
    cout<<endl<<"ans: "<<authenticationManager.countUnexpiredTokens(6); // The token with tokenId "aaa" is the only unexpired one at time 6, so return 1.
    authenticationManager.generate("bbb", 7); // Generates a new token with tokenId "bbb" at time 7.
    authenticationManager.renew("aaa", 8); // The token with tokenId "aaa" expired at time 7, and 8 >= 7, so at time 8 the renew request is ignored, and nothing happens.
    authenticationManager.renew("bbb", 10); // The token with tokenId "bbb" is unexpired at time 10, so the renew request is fulfilled and now the token will expire at time 15.
    cout<<endl<<"ans: "<<authenticationManager.countUnexpiredTokens(15); // The token with tokenId "bbb" expires at time 15,
                                    // and the token with tokenId "aaa" expired at time 7, so currently no token is unexpired, so return 0.



    LT1797 lt;


    return 0;
}
