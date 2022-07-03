
#include "../../header/myheader.h"

class LT6108
{
public:




    // AC
    string lta(string key, string message)
    {
        char arr[123] = { 0 };
        char c = 'a';
        for (char ch : key)
        {
            if (ch != ' ' && arr[ch] == 0)
            {
                arr[ch] = c++;
            }
        }
        for (int i = 0; i < message.size(); ++i)
        {
            if (message[i] != ' ')
            {
                message[i] = arr[message[i]];
            }
        }
        return message;
    }

};

int main()
{

    LT6108 lt;

    //string k = "the quick brown fox jumps over the lazy dog";
    //string s = "vkbs bs t suepuv";

    string k = "eljuxhpwnyrdgtqkviszcfmabo";
    string s = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";

    cout << lt.lta(k, s) << endl;

    return 0;
}
