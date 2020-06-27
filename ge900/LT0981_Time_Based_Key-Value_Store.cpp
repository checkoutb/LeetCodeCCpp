
#include "../header/myheader.h"

class LT0981
{
public:



};


// D D
//Integer floor = treeMap.floorKey(timestamp);

//unordered_map<string, map<int, string>> m;
//void set(string key, string value, int timestamp) {
//  m[key].insert({ timestamp, value });
//}
//string get(string key, int timestamp) {
//  auto it = m[key].upper_bound(timestamp);
//  return it == m[key].begin() ? "" : prev(it)->second;
//}


//Runtime: 700 ms, faster than 56.74% of C++ online submissions for Time Based Key-Value Store.
//Memory Usage: 130.9 MB, less than 27.25% of C++ online submissions for Time Based Key-Value Store.

// The timestamps for all TimeMap.set operations are strictly increasing... 那就不可能重复，可以作为key。

class TimeMap {

    unordered_map<string, map<int, string>> keyTimeValueMap;

public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        if (keyTimeValueMap.find(key) == keyTimeValueMap.end())
            keyTimeValueMap[key][0] = "";
        keyTimeValueMap[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (keyTimeValueMap.find(key) == keyTimeValueMap.end())
            return "";
        map<int, string>& map2 = keyTimeValueMap[key];
        return std::prev(map2.upper_bound(timestamp))->second;
    }
};

int main()
{

    LT0981 lt;

    TimeMap kv;

//    kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1
//    cout<<endl<<kv.get("foo", 1);  // output "bar"
//    cout<<endl<<kv.get("foo", 3); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"
//    kv.set("foo", "bar2", 4);
//    cout<<endl<<kv.get("foo", 4); // output "bar2"
//    cout<<endl<<kv.get("foo", 5); //output "bar2"
//    cout<<endl;

    kv.set("love","high",10);
    kv.set("love","low",20);
    cout<<endl<<kv.get("love", 5);
    cout<<endl<<kv.get("love", 10);
    cout<<endl<<kv.get("love", 15);
    cout<<endl<<kv.get("love", 20);
    cout<<endl<<kv.get("love", 25);
    cout<<endl;

    return 0;
}
