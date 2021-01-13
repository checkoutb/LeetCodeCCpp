
#include "../header/myheader.h"

class LT0535
{
public:



};

// D D

//    def __init__(self):
//        self.urls = []
//
//    def encode(self, longUrl):
//        self.urls.append(longUrl)
//        return 'http://tinyurl.com/' + str(len(self.urls) - 1)
//
//    def decode(self, shortUrl):
//        return self.urls[int(shortUrl.split('/')[-1])]
// 自增int，直接用 变长数组。


//    alphabet = string.ascii_letters + '0123456789'
//
//    def __init__(self):
//        self.url2code = {}
//        self.code2url = {}
//
//    def encode(self, longUrl):
//        while longUrl not in self.url2code:
//            code = ''.join(random.choice(Codec.alphabet) for _ in range(6))
//            if code not in self.code2url:
//                self.code2url[code] = longUrl
//                self.url2code[longUrl] = code
//        return 'http://tinyurl.com/' + self.url2code[longUrl]
//
//    def decode(self, shortUrl):
//        return self.code2url[shortUrl[-6:]]


//    public String encode(String longUrl) {
//        if (revIndex.containsKey(longUrl)) return BASE_HOST + revIndex.get(longUrl);
//        String charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//        String key = null;
//        do {
//            StringBuilder sb = new StringBuilder();
//            for (int i = 0; i < 6; i++) {
//                int r = (int) (Math.random() * charSet.length());
//                sb.append(charSet.charAt(r));
//            }
//            key = sb.toString();
//        } while (index.containsKey(key));
//        index.put(key, longUrl);
//        revIndex.put(longUrl, key);
//        return BASE_HOST + key;
//    }




//Runtime: 4 ms, faster than 80.86% of C++ online submissions for Encode and Decode TinyURL.
//Memory Usage: 7.1 MB, less than 81.18% of C++ online submissions for Encode and Decode TinyURL.
class Solution {
    unordered_map<string, string> map2;     // short : long
    string prefix = "http://123456.com/";
    int cnt = 1;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string sht = prefix + to_string(cnt++);
        map2[sht] = longUrl;
        return sht;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map2[shortUrl];
    }
};

int main()
{
    Solution sol;

    string lng = "https://leetcode.com/problems/design-tinyurl";
    string sht = sol.encode(lng);
////    cout<<sht
//    cout<<
    cout<<sht<<endl<<sol.decode(sht);

    LT0535 lt;


    return 0;
}
