
#include "../header/myheader.h"

class LT1404
{
public:

// D D

//template <typename T> std::ostream& operator<<(std::ostream&, const std::set<T>&);
//template <typename T> std::ostream& operator<<(std::ostream&, const std::unordered_set<T>&);
//template <typename T> std::ostream& operator<<(std::ostream&, const std::vector<T>&);
//template <typename T, std::size_t N> std::ostream& operator<<(std::ostream&, const std::array<T, N>&);
//template <typename K, typename V> std::ostream& operator<<(std::ostream&, const std::unordered_map<K, V>&);
//template <typename K, typename V> std::ostream& operator<<(std::ostream&, const std::pair<K, V>&);
//
//
//template <typename T>
//std::ostream& operator << (std::ostream& os, const std::optional<T>& x) {
//  if (x.has_value())
//    os << x.value();
//  else
//    os << "nothing";
//  return os;
//};
//
//template <typename K, typename V>
//std::ostream& operator<<(std::ostream& os, const std::pair<K, V>& x) {
//  os << "(" << x.first << ", " << x.second << ")";
//  return os;
//}
//
//template <typename K, typename V>
//std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& x) {
//  os << "[";
//  for (auto it = begin(x); it != end(x); ++it) {
//    os << (it == begin(x) ? "" : ", ") << *it;
//  }
//  os << "]";
//  return os;
//}
//
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& x) {
//  os << "[";
//  for (auto it = begin(x); it != end(x); ++it) {
//    os << (it == begin(x) ? "" : ", ") << *it;
//  }
//  os << "]";
//  return os;
//}
//
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::set<T>& x) {
//  os << "[";
//  for (auto it = begin(x); it != end(x); ++it) {
//    os << (it == begin(x) ? "" : ", ") << *it;
//  }
//  os << "]";
//  return os;
//}
//
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& x) {
//  os << "[";
//  for (auto it = begin(x); it != end(x); ++it) {
//    os << (it == begin(x) ? "" : ", ") << *it;
//  }
//  os << "]";
//  return os;
//}
//
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::deque<T>& x) {
//  os << "[";
//  for (auto it = begin(x); it != end(x); ++it) {
//    os << (it == begin(x) ? "" : ", ") << *it;
//  }
//  os << "]";
//  return os;
//}
//
//template <typename T, std::size_t N>
//std::ostream& operator<<(std::ostream& os, const std::array<T, N>& x) {
//  os << "[";
//  for (auto it = begin(x); it != end(x); ++it) {
//    os << (it == begin(x) ? "" : ", ") << *it;
//  }
//  os << "]";
//  return os;
//}
//
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& x) {
//  os << "\n[";
//  for (auto it = begin(x); it != end(x); ++it) {
//    os << (it == begin(x) ? "" : "\n ") << *it;
//  }
//  os << "]";
//  return os;
//}
//
//
//
//#define see(...) " [" << #__VA_ARGS__  << ": " << (__VA_ARGS__) << "] "
//#define trace(x) (cout << see(x) << endl, x)
//#define traceX(x) x
//
//class Solution {
// public:
//  int numSteps(string s) {
//    auto make_forward = [](auto x) { return (--x.base()); };
//
//    std::function<int(int)> fold = [&, num = s](int acc) mutable {
//      if (num == "1") {
//        return acc;
//      }
//      else if (num.back() == '0') {
//        num.pop_back();
//        return fold(acc + 1);
//      }
//      else if (num.back() == '1') {
//        auto fst_zero = std::find(std::rbegin(num), std::rend(num), '0');
//        if (fst_zero != std::rend(num)) {
//          std::fill(make_forward(fst_zero) + 1, std::end(num), '0');
//          *make_forward(fst_zero) = '1';
//        }
//        else {
//          std::fill(std::begin(num), std::end(num), '0');
//          num.push_back('1');
//          std::swap(num.front(), num.back());
//        }
//        return fold(acc + 1);
//      }
//      else throw;
//    };
//
//    return fold(0);
//
//  }
//};
// .....


//    int res = 0, carry = 0;
//    for (auto i = s.size() - 1; i > 0; --i) {
//        ++res;
//        if (s[i] - '0' + carry == 1) {
//            carry = 1;
//            ++res;
//        }
//    }
//    return res + carry;

//    int ones = 0, last_one = 0;
//    for (auto i = 1; i < s.size(); ++i)
//        if (s[i] == '1') {
//            last_one = i;
//            ++ones;
//        }
//    return s.size() - 1 + (last_one - ones) + (last_one ? 2 : 0);

//    int divs = s.size() - 1, additions = 0, carry = 0;
//    for (auto i = s.size() - 1; i > 0; --i) {
//        additions += s[i] - '0' + carry == 1;
//        carry |= s[i] == '1';
//    }
//    return divs + additions + carry;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Steps to Reduce a Number in Binary Representation to One.
//Memory Usage: 6.6 MB, less than 77.60% of C++ online submissions for Number of Steps to Reduce a Number in Binary Representation to One.
    int lt1404b(string s)
    {
        int i = s.size() - 1;
        int ans = 0;
        while (i >= 1)
        {
            if (s[i] == '0')
            {
                ans++;
                i--;
            }
            else
            {
                ans++;      // +1
                i--;
                ans++;      // >>1
                while (i >= 0)
                {
                    if (s[i] == '1')
                    {
                        ans++;
                        i--;
                    }
                    else
                        break;
                }
                if (i >= 0)
                {
                    s[i] = '1';
                }
            }
        }
        return ans;
    }


// error
// 1101 1110  111  1000  100 10 1
// 1110 111  1000  100
// 110101  110110   11011 11100  1110  111 1000 100 10 1
// 110011  110100  11010  1101   1110  111
// 110110  11011  11100   1110  111   1000 100 10  1
// 101101  101110  10111  11000 1100  110  11 100   10 1
// 有多少个 01 ?
// 01 代表需要一次+1，并且 这次+1 不会影响前面， 并且有01， 说明至少是 101  +1后，是110， 还需要一次+1 。如果是10110 那么就变成 1100。 如果前面还有0。。
//
    int lt1404a(string s)
    {
        int cnt1 = 0;
        int cnt0 = 0;
        int cnt01 = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
                cnt1++;
            else
            {
                cnt0++;
                if (i + 1 < s.size() && s[i + 1] == '1')
                    cnt01++;
            }
        }
        return cnt0 + (cnt1 - 1) + cnt01;
    }

};

int main()
{
    vector<string> v = {"1101", "10", "1", "101"};

    LT1404 lt;

    for (string s : v)
        cout<<lt.lt1404b(s)<<endl;

    return 0;
}
