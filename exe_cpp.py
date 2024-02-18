import os




def exe_cpp():
    cpp = None
    with open("last_cpp_path", "r", encoding='utf-8') as f:
        cpp = f.readline()
    
    if (cpp is None):
        return
    
    # print(os.system("g++ -std=c++20 " + cpp + " -o i9n0r3"))
    # print(os.system("./i9n0r3"))

    os.system("g++ -std=c++20 " + cpp + " -o i9n0r3")
    os.system("./i9n0r3")

    print("end of exe_cpp")

if __name__ == "__main__":
    exe_cpp()
