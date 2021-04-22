



    # There are n languages numbered 1 through n,
    # languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
    # friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi.
# uf ....   bfs
class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        # arr = [-1] * (n + 1)
        arr = [-1] * (len(languages))
        ans = 0;
        map2 = {}
        for lst in friendships:
            map2.get(lst[0], set()).add(lst[1])
            map2.get(lst[1], set()).add(lst[0])
        for idx in (1, len(arr)):
            if (arr[idx] != -1):
                continue;
            set2 = {idx}
            que = Queue()
            que.put(idx)
            while !que.empty():
                i2 = que.get()
                for fri in map2[i2]:
                    if fri not in set2:
                        set2.add(fri)
                        que.push(fri)
                        arr[i] = 1              # ... language  应该是 bfs language


        # uf = [-1] * (n + 1)         # language
        # map2 = {}       # person: friendsss
        # for lst in friendships:
        #     map2.get(lst[0], set()).add(lst[1])
        #     map2.get(lst[1], set()).add(lst[0])
        # for idx in range(0, len(languages)):
        #     lst = languages[idx]
        #     for val in lst:


        # for 


if __name__ == '__main__':
    sol = Solution()

    print("ans: " + str(sol.minimumTeachings))
