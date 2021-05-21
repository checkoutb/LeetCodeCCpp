import os
import sys
import time

# mk xxxx.cpp

def mk_cpp():
    lt_name = ""

    if (len(lt_name) < 5):
        lt_name = input("plz input name:")

    lt_name = lt_name.strip()

    if (len(lt_name) < 2):
        return

    # print("-------------")

    lt_name = lt_name.replace("'", "")
    # t2 = lt_name[0:lt_name.find('.')]
    date_str = time.strftime("%Y-%m-%d", time.localtime());
    f_name = "/LT" + "_" + date_str + "_" + lt_name.replace(" ", "_").replace("'", "") + ".cpp"
    dir_name = date_str[0:4]
    # dir_name = "ge" + str(int(int(int(t2)/100)*100))
    # if int(t2) < 100:
    #     dir_name = "gt000"

    content = """
#include "../../header/myheader.h"

class """
    content = content + "LT"

    content = content + """
{
public:



};

int main()
{

    """

    content = content + "LT" + " lt;\n\n"
        
    content = content + """
    return 0;
}
"""

    # print(f_name)
    name = dir_name + f_name
    pwd = os.getcwd() + "/" + name
    print(pwd)

    # if os.path.isfile(pwd):
    if os.path.exists(name):
        print("already exists, so exit...")
        sys.exit()

    # 如果是/开头，那么是 根目录文件下。
    if not os.path.isdir(dir_name):
        os.makedirs(dir_name)

    # not a file, 已经能确保不会删除其他文件了。
    if not os.path.isfile(name):
        fd = open(name, mode="a+", encoding='utf-8')
        fd.write(content)
        fd.close()

if __name__ == "__main__":
    mk_cpp()
    # print(mk_cpp.__doc__)
