

from typing import List

# .. 这道真见过。当时用的是数组的解法，没有想到其他的。。可能慌了，或者忘了。


# sorted_word = "".join(sorted(word))
# 。。。baidu 了 python 字符串 排序，，没有看到这个啊。。。

        # ans = collections.defaultdict(list)
        # for s in strs:
        #     count = [0] * 26
        #     for c in s:
        #         count[ord(c) - ord('a')] += 1
        #     ans[tuple(count)].append(s)
        # return ans.values()
        # 元组做key。。。数组得在拼接下。。


        # d={}
        # for i in strs:
        #     strhash=tuple(sorted(i))
        #     d.setdefault(strhash,[])
        #     d[strhash].append(i)
        # return list(d.values())
        # there is no need "sorted(strs)"       看discuss，有人说这个，看来tuple自动排序了？ 。。。不，for i in sorted(strs): ....

        # anagram = collections.defaultdict(list)
        # for str in strs:
        #     anagram[''.join(sorted(str))].append(str)
        # return list(anagram.values())


# return [sorted(g) for _, g in itertools.groupby(sorted(strs, key=sorted), sorted)]

    # groups = itertools.groupby(sorted(strs, key=sorted), sorted)
    # return [sorted(members) for _, members in groups]

    # groups = collections.defaultdict(list)
    # for s in strs:
    #     groups[tuple(sorted(s))].append(s)
    # return map(sorted, groups.values())


# strs.sort.group_by { |s| s.chars.sort }.values

# strs.group_by { |s| s.chars.sort }.values.map(&:sort)



    # private static final int[] PRIMES = new int[]{2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
    
    # public List<String> anagrams(String[] strs) {
    #     List<String> list = new LinkedList<>();
    #     Map<Integer, List<String>> mapString = new HashMap<>();
    #     int result = -1;
    #     for (int i = 0; i < strs.length; i++){
    #         int mapping = 1;
    #         for (int j = 0, max = strs[i].length(); j < max; j++) {
    #             mapping *= PRIMES[strs[i].charAt(j) - 'a'];
    #         }
    #         List<String> strings = mapString.get(mapping);
    #         if (strings == null) {
    #             strings = new LinkedList<>();
    #             mapString.put(mapping, strings);
    #         }
    #         strings.add(strs[i]);
    #     }
    #     for (List<String> mapList : mapString.values()){
    #         if (mapList.size() > 1)
    #             list.addAll(mapList);
    #     }
    #     return list;
    # }
# prime     2^(count) * 3^(count) * 5^(count) ....



# Runtime: 92 ms, faster than 86.47% of Python3 online submissions for Group Anagrams.
# Memory Usage: 17.6 MB, less than 63.37% of Python3 online submissions for Group Anagrams.
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map2 = {}
        for s in strs:
            ls = list(s)
            ls.sort()               # no return ... so  "".join(list(s).sort())
            ss = "".join(ls)
            # if ss in map2:
            # map2.get(ss, []).append(s)            # ? why empty?

# Could anyone explain why I can not use
# d[key] = d.get(key, []) + [w] ->
# d[key] = d.get(key, []).append(w)
# ---------
# I know this question is old, but since noone has really answered it...
# The problem with your code is that when key is not in d, then d.get(key, []) returns [].
# You then do [].append(w), which returns None (because list.append(...) modifies the list it is called on, rather than returning a new list).
# This means that d[key] is set to None, and in a later iteration None.append(w) is called, which results in an error.
# In the original code, if d is not in key it effectively does [] + [w]. The addition operator returns a new list [w], which is what we wanted.
# Final note, as @granola says, collections.defaultdict can be used instead here.

# append 返回一个空。 。。当然 我的问题是： get出来的[] ，就没有再 赋值给 map。。。

# d = defaultdict(set)
# for k, v in s:
#     d[k].add(v)
# 真 - 有默认value 的 map。

            if ss in map2:
                map2[ss].append(s)
            else:
                map2[ss] = [s]
                
        # print(len(map2))
        return map2.values()



if __name__ == "__main__":



    lst = ["eat","tea","tan","ate","nat","bat"]
    for s in lst:
        print(tuple(s))
        print(sorted(s))
        print(tuple(sorted(s)))


    lst = ["a"]

    sol = Solution()

    lls = sol.groupAnagrams(lst)

    for ls in lls:
        for s in ls:
            print(s, end = ",")
        print()