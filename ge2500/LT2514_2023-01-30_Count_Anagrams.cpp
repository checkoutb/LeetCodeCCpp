
#include "../header/myheader.h"

class LT2514
{
public:



        //(a / b) mod c
        //<=> a * 1 * b ^ (-1) mod c
        //<=> a * (b ^ (c - 1)) * b ^ (-1) mod c
        //<=> a * b ^ (c - 2) mod c

    
    // ´óÊý½×³ËÏà³ý¡£¡£
    // error
    int lt2514a(string s)
    {
        s.push_back(' ');
        int sz1 = s.size();
        long long ans = 1LL;
        const int MOD = 1e9 + 7;

        vector<bool> vb(100);
        for (int i = 2; i < 100; ++i)
        {
            if (vb[i])
                continue;
            for (int j = 2 * i; j < 100; j += i)
            {
                vb[j] = true;
            }
        }

        vector<int> prms;
        for (int i = 2; i < 100; ++i)
        {
            if (!vb[i])
                prms.push_back(i);
        }

        int arr[123] = { 0 };
        int cnt = 0;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == ' ')
            {
                vector<int> vi(cnt);
                std::iota(begin(vi), end(vi), 1);

                //map<int, int> map2;
                vector<int> vcnt(prms.size());
                vector<int> vremain;
                for (int a = 'a'; a <= 'z'; ++a)
                {
                    if (arr[a] == 0)
                        continue;

                    t2 = arr[a];
                    for (int j = 0; j < prms.size() && t2 >= prms[j]; ++j)
                    {
                        while (t2 % prms[j] == 0)
                        {
                            ++vcnt[j];
                            t2 /= prms[j];
                        }
                    }
                    if (t2 != 1)
                    {
                        vremain.push_back(t2);
                    }
                    arr[a] = 0;
                }

                for (int j = 0; j < prms.size(); ++j)
                {
                    if (vcnt[j] == 0)
                        continue;

                    for (int a = vi.size() - 1; vcnt[j] != 0; --a)
                    {
                        if (a < 0)
                        {
                            cout << " ----------- " << endl;
                        }
                        while (vcnt[j] != 0 && (vi[a] % prms[j] == 0))
                        {
                            vi[a] /= prms[j];
                            --vcnt[j];
                        }
                    }
                }

                for (int j = 0; j < vremain.size(); ++j)
                {
                    for (int a = vi.size() - 1; a >= 0; --a)
                    {
                        if (vi[a] % vremain[j] == 0)
                        {
                            vi[a] /= vremain[j];
                            break;
                        }
                    }
                }

                //for (int a = 'a'; a <= 'z'; ++a)
                //{
                //    if (arr[a] == 0)
                //        continue;

                //    t2 = arr[a];
                //    for (int j = vi.size() - 1; t2 != 1; --j)
                //    {
                //        //if (j < 0)
                //        //{
                //        //    cout << "------" << endl;
                //        //}
                //        while (t2 != 1 && (vi[j] % t2 == 0))
                //        {
                //            vi[j] /= t2;
                //            --t2;
                //        }
                //    }
                //    arr[a] = 0;
                //}
                cnt = 0;

                for (int i = 1; i < vi.size(); ++i)
                {
                    ans = (ans * vi[i]) % MOD;
                }
            }
            else
            {
                ++cnt;
                ++arr[s[i]];
            }
        }

        return (int)ans;
    }

};

int main()
{

    LT2514 lt;

    //string s = "too hot";
    //string s = "aaaaaaaaaaab";

    // 34334202
    string s = "epkpjrpyzprqwbuqktwladjdocwonlzddcitjcflphkwglqrnpzyibqcjjhlubujhnqwacrwclthmmcwufetbteldpemdzjsqxvreayenaiwkqdiwbpxkvoprjcrnullgrykjcfkbgbcsqatioayhjgdbubzertmpmjnxrxwjnzadlvblzayxhuqdzgmuuifguvxgaymrztdukhlsgrzehuwjzwvwe jhuxtqiewkbqifanpfjhjiaslyuoouygzlajkdfixitafvzjyxeiqqvtozbiyyvvkdsrlocudmeypinmeyzaaafwwmxjwnrqqijiyektwauywbconzraslmifqiyrvlwvdwwmcittkxfienfmweozlhwdihbblrbscaeilbwksdkeienkzmjnoeuwcpmntwjgomjgbizjiuwlwsvcbncmflsmegcqvymdqezacjnwxgsedwqtnclcfjtpyloyrkcshdyuidxfwta wgjdpvxaewbdxkdttfipmcliwrpwwcxezzlzotyhcyhuleuygboztwnslvildpnzkocnilsbtjagpsaxoamspvapfneowbkanrolvbwstdjmycerxhvelyvnyrvuwybbvfnjzwkkhriufodwgzowsnhttogupghvkmnziiihaiacemrtyarcbapajbjddjdqoansbyatftqdyejnzjhwiouuuudstbnpdwtmoicgbpfgfbrnrcumpmxkqrojpmiqqgzdyhjlcjcpwcnwttubcnnojpg knpcunyxmmnvkvftjtjxaipanirayiuhvflwqzvdpxzunxrejgqshycrpz qnzopszpfecdzwsnxxvoucndpludbgtcolxdksftgoewojotjcqonmwtzfyvhdliofadbvdhnsonyxrlloseidjdrezg nlpvcotabxsnduxlydfdldhgmvllcvicybtjnvgdjdxlzkcnbrwsvypnkzjuijmtxbdpabtzojidikeflqbcvuvmjqodnhbvkcjpovrqkooyflbuivwpqqyr kmdaerbcwdpbmomdlfkkzhnxpsiscgorhgeasvpoorm t zbowyudg";


    cout << lt.lt2514a(s) << endl;

    return 0;
}
