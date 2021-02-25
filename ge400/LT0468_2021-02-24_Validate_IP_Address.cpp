
#include "../header/myheader.h"

class LT0468
{
public:

// D D

//        def isIPv4(s):
//            try: return str(int(s)) == s and 0 <= int(s) <= 255
//            except: return False
//
//        def isIPv6(s):
//            try: return len(s) <= 4 and int(s, 16) >= 0
//            except: return False
//
//        if IP.count(".") == 3 and all(isIPv4(i) for i in IP.split(".")):
//            return "IPv4"
//        if IP.count(":") == 7 and all(isIPv6(i) for i in IP.split(":")):
//            return "IPv6"
//        return "Neither"



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Validate IP Address.
//Memory Usage: 6.3 MB, less than 78.01% of C++ online submissions for Validate IP Address.
    string lt0468a(string IP)
    {
        int cnt = 0;
        int cnt2 = 0;
        if (IP.size() > 40)
            return "Neither";
        for (char ch : IP)
        {
            if (ch == '.')
                cnt++;
            if (ch == ':')
                cnt2++;
        }
        if (cnt != 3 && cnt2 != 7)
            return "Neither";
        if (cnt == 3)
        {
            if (IP[IP.size() - 1] == '.')
                return "Neither";
            int val = 0;
            for (int i = 0; i < IP.size(); ++i)
            {
                if (IP[i] == '.')
                {
                    if (i == 0 || IP[i - 1] == '.')
                        return "Neither";
                    if (val > 255)
                        return "Neither";
                    val = 0;
                    continue;
                }
                if (!std::isdigit(IP[i]))
                    return "Neither";
                if (IP[i] == '0')
                {
                    if (i == 0 || (IP[i - 1] == '.' && i != IP.size() - 1 && IP[i + 1] != '.'))
                    {
                        return "Neither";
                    }
                }
                val = val * 10 + IP[i] - '0';
                if (val > 255)
                    return "Neither";
            }
            if (val > 255)
                return "Neither";
            return "IPv4";
        }
//        if (IP.size() != )
        int val = 0;
        int lst = -1;
        if (IP[IP.size() - 1] == ':')
            return "Neither";
        for (int i = 0; i < IP.size(); ++i)
        {
            if (IP[i] == ':')
            {
                if (i - lst <= 1 || i - lst > 5)
                    return "Neither";
                lst = i;
                continue;
            }
            if (!std::isdigit(IP[i]))
            {
                if (IP[i] < 'A' || IP[i] > 'f' || (IP[i] > 'F' && IP[i] < 'a'))
                {
                    return "Neither";
                }
            }
        }
        if (IP.size() - lst <= 1 || IP.size() - lst > 5)
            return "Neither";
        return "IPv6";

//        if (cnt == 5)
//        {
//
//        }
    }

};

int main()
{

//    string s = "172.16.254.1";
//    string s = "2001:0db8:85a3:0:0:8A2E:0370:7334";
//    string s = "256.256.256.256";
//    string s = "2001:0db8:85a3:0:0:8A2E:0370:";
//    string s = "1e1.4.5.6";
    string s = "192.0.0.1";


    LT0468 lt;

    cout<<lt.lt0468a(s)<<endl;

    return 0;
}
