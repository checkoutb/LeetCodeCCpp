
#include "../header/myheader.h"

class LT0355
{
public:



};

// D D


// OOP



//Runtime: 60 ms, faster than 71.04% of C++ online submissions for Design Twitter.
//Memory Usage: 21.1 MB, less than 83.01% of C++ online submissions for Design Twitter.
class Twitter {
    int ts;
//    queue<pair<int, int>> que1;     // ts : tweet
    unordered_map<int, vector<int>> map2;   // user1 : who are followed by user1
    unordered_map<int, vector<pair<int, int>>> map3;        // user : user's tweet (ts : tweetid)
public:
    /** Initialize your data structure here. */
    Twitter() {
        this->ts = 1;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        map3[userId].push_back({ts++, tweetId});
        if (map3[userId].size() > 10)
//            map3[userId].pop_front();
            map3[userId].erase(map3[userId].begin());
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> vp;
//        if (!map3[userId].empty())
            vp.insert(end(vp), begin(map3[userId]), end(map3[userId]));
        for (int foll : map2[userId])
//            if (!map3[foll].empty())
                vp.insert(end(vp), begin(map3[foll]), end(map3[foll]));
        std::sort(begin(vp), end(vp));
        vector<int> ans;
        for (int i = 1; i <= 10 && i <= vp.size(); ++i)
            ans.push_back(vp[vp.size() - i].second);
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        // ... set!!!....
        if (followeeId == followerId)
            return;
        for (int foll : map2[followerId])
            if (foll == followeeId)
                return;
        map2[followerId].push_back(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
//        for (unordered_map<int, vector<int>>::iterator it = begin(map2); it != end(map2))
        auto it = std::find(begin(map2[followerId]), end(map2[followerId]), followeeId);
        if (it != end(map2[followerId]))
            map2[followerId].erase(it);
        // use set
    }
};


int main()
{

    Twitter t;

    t.postTweet(1, 5);
    vector<int> vi = t.getNewsFeed(1);
    showVectorInt(vi);
    t.follow(1, 2);
    t.postTweet(2, 6);
    vi = t.getNewsFeed(1);
    showVectorInt(vi);
    t.unfollow(1, 2);
    vi = t.getNewsFeed(1);
    showVectorInt(vi);

    LT0355 lt;


    return 0;
}
