
#include "../header/myheader.h"

class LT0748
{
public:


// detail
// 用2个vector<int> 代替2个map。。似乎words全是小写英文。。。Note.4.....



// discuss
// Idea: assign each letter a prime number and compute the product for the license plate. Then, compute the product for each word in wordlist. We know if the char product for a word is divisible by the license plate char product, it contains all the characters.
//    private static final int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
//
//    public String shortestCompletingWord(String licensePlate, String[] words) {
//        long charProduct = getCharProduct(licensePlate.toLowerCase());
//        String shortest = "aaaaaaaaaaaaaaaaaaaa"; // 16 a's
//        for(String word : words)
//            if (word.length() < shortest.length() && getCharProduct(word) % charProduct == 0)
//                    shortest = word;
//        return shortest;
//    }
//
//    private long getCharProduct(String plate) {
//        long product = 1L;
//        for(char c : plate.toCharArray()) {
//            int index = c - 'a';
//            if (0 <= index && index <= 25)
//                product *= primes[index];
//        }
//        return product;
//    }
// 质数*英文。 如果能被整除，则必然存在这个质数*英文。



//Runtime: 56 ms, faster than 23.84% of C++ online submissions for Shortest Completing Word.
//Memory Usage: 12 MB, less than 60.00% of C++ online submissions for Shortest Completing Word.
    string lt0748a(string licensePlate, vector<string>& words)
    {
        set<char> set1;
        map<char, int> map1;
        map<char, int> map2;
        for (char ch : licensePlate)
        {
            if (std::isalpha(ch))
            {
                char ch2 = std::tolower(ch);
                set1.insert(ch2);
                map1[ch2]++;
            }
        }
        string ans;
        int szAns = INT_MAX;
        for (string word : words)
        {
            map2.clear();
            for (char ch : word)
            {
                if (std::isalpha(ch))
                {
                    char ch2 = std::tolower(ch);
                    if (set1.find(ch2) != set1.end())
                    {
                        map2[ch2]++;
                    }
                }
            }
            bool f = true;
            for (char ch : set1)
            {
                if (map1[ch] > map2[ch])
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                if (word.size() < szAns)
                {
                    szAns = word.size();
                    ans = word;
                }
            }
        }
        return ans;
    }

};

int main()
{

    string licensePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};

    LT0748 lt;

    cout<<lt.lt0748a(licensePlate, words)<<endl;

    return 0;
}
