
#include "../header/myheader.h"

class LT1348
{
public:



};

// D D


//        if(freq=="minute"){
//            vector<int>res((endTime-startTime)/60 +1, 0);
//            for(auto a: mp[tweetName])
//                if(a>=startTime && a<=endTime) res[(a-startTime)/60]++;
//            return res;
//        }
// ....


//        vector <int>res;
//        for (int i=0; i <= (endTime - startTime) / f[freq]; i++)
//            res.push_back(0);
//
//        for (auto& time : m[tweetName]) {
//            if (time >= startTime && time <= endTime) {
//                int index = (time - startTime) / f[freq];
//                res[index]++;
//            }
//        }

//    unordered_map<string, int>f = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};




//Runtime: 524 ms, faster than 14.23% of C++ online submissions for Tweet Counts Per Frequency.
//Memory Usage: 40.8 MB, less than 40.89% of C++ online submissions for Tweet Counts Per Frequency.
// 0 <= endTime - startTime <= 10^4   .. 按时间顺序吗。。 time 会不会越界。  example1 中不是时间顺序。 那就*2 了。 .. 不，这个只是搜索的时候，time依然可能是 0 - 10^9
// 而且 tweet 名字不一样。  或许应该按 名字分组？ 而不是按照 时间顺序排序。
// 这个好像永远不会跨天啊。。最多3个小时。
class TweetCounts {

    unordered_map<string, vector<int>> map2;
    unordered_map<string, bool> map3;       // change?

public:
    TweetCounts() {

    }

    void recordTweet(string tweetName, int time) {
        this->map2[tweetName].push_back(time);
        this->map3[tweetName] = true;
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if (this->map3[tweetName])
        {
            std::sort(begin(this->map2[tweetName]), end(this->map2[tweetName]));
            this->map3[tweetName] = false;
        }

        vector<int>& vi = this->map2[tweetName];
        vector<int>::iterator st = std::lower_bound(begin(vi), end(vi), startTime);
//        vector<int>::iterator en = std::prev(std::upper_bound(begin(vi), end(vi), endTime));
        vector<int>::iterator en = std::upper_bound(begin(vi), end(vi), endTime);
        #ifdef __test
        showVectorInt(map2[tweetName]);
        cout<<(int) (std::distance(begin(vi), st))<<" --- "<<(int) (std::distance(begin(vi), en))<<endl;
        #endif // __test
        int t2 = 0;
        switch (freq[0])
        {
        case 'm':
            t2 = 60;
            break;
        case 'h':
            t2 = 3600;
            break;
        case 'd':
            t2 = 86400;
        }
        vector<int> ans;
        int cnt = 0;
        startTime += t2;        // period's end, exclusive
        while (st != en)
        {
            int t3 = *st;       // time
            if (t3 >= startTime)
            {
                ans.push_back(cnt);
                cnt = 0;
                startTime += t2;
            }
            else
            {
                cnt++;
                st++;
            }
        }
        #ifdef __test
        cout<<startTime<<", ";
        #endif // __test
//        if (startTime != endTime + 1)
//        {
//            cout<<"+++1";
            ans.push_back(cnt);
//        }
        while (startTime <= endTime)
        {
            ans.push_back(0);
            startTime += t2;
        }
        return ans;
    }
};



int main()
{

    LT1348 lt;
    myvi vi;

    TweetCounts tweetCounts;
    tweetCounts.recordTweet("tweet3", 0);                              // New tweet "tweet3" at time 0
    tweetCounts.recordTweet("tweet3", 60);                             // New tweet "tweet3" at time 60
    tweetCounts.recordTweet("tweet3", 10);                             // New tweet "tweet3" at time 10
    vi = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2]; chunk [0,59] had 2 tweets
    showVectorInt(vi);
    vi = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2,1]; chunk [0,59] had 2 tweets, chunk [60,60] had 1 tweet
    showVectorInt(vi);
    tweetCounts.recordTweet("tweet3", 120);                            // New tweet "tweet3" at time 120
    vi = tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4]; chunk [0,210] had 4 tweets
    showVectorInt(vi);


    return 0;
}
