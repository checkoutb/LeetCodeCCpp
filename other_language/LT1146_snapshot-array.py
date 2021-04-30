

    # def __init__(self, length: int):
    #     self.currSnap = {}
    #     self.data = {}
    #     self.currSnapId = -1
        
    # def set(self, index: int, val: int) -> None:
    #     self.currSnap[index] = val

    # def snap(self) -> int:
    #     self.currSnapId += 1
    #     self.data[self.currSnapId] = self.currSnap.copy()    
    #     return self.currSnapId

    # def get(self, index: int, snap_id: int) -> int:
    #     if snap_id in self.data:
    #         if index in self.data[snap_id]:
    #             return self.data[snap_id][index]
    #     return 0
# 这合理吗？？？？？？   375ms


    # def __init__(self, length: int):
    #     self.storage = [{0:0} for _ in range(length)]
    #     self.snap_id = 0

    # def set(self, index: int, val: int) -> None:
    #     self.storage[index][self.snap_id] = val

    # def snap(self) -> int:
    #     self.snap_id += 1
    #     return self.snap_id - 1

    # def get(self, index: int, snap_id: int) -> int:
    #     snapshots = self.storage[index]
    #     if snap_id in snapshots:
    #         return snapshots[snap_id]
    #     # Go through keys (snapshots) and return
    #     # the largest snapshot <= snap_id.
    #     for i in reversed(snapshots.keys()):
    #         if i <= snap_id:
    #             return snapshots[i]
# 384ms， 这非常不合理啊。。。


# 。。算了， 合理的
    # TreeMap<Integer, Integer>[] A;
    # int snap_id = 0;
    # public SnapshotArray(int length) {
    #     A = new TreeMap[length];
    #     for (int i = 0; i < length; i++) {
    #         A[i] = new TreeMap<Integer, Integer>();
    #         A[i].put(0, 0);
    #     }
    # }

    # public void set(int index, int val) {
    #     A[index].put(snap_id, val);
    # }

    # public int snap() {
    #     return snap_id++;
    # }

    # public int get(int index, int snap_id) {
    #     return A[index].floorEntry(snap_id).getValue();
    # }


# private:
#     map<int, map<int, int>> snaps;
#     int snapId = 0;
# public:
#     SnapshotArray(int length) {
#         for (int i = 0; i < length; i++) {
#             map<int, int> mp; mp[0] = 0;
#             snaps[i] = mp;
#         }
#     }
    
#     void set(int index, int val) {
#         snaps[index][snapId] = val;
#     }
    
#     int snap() {
#         return snapId++;
#     }
    
#     int get(int index, int snap_id) {
#         auto it = snaps[index].upper_bound(snap_id); it--;
#         return it->second;
#     }



    # def __init__(self, n):
    #     self.A = [[[-1, 0]] for _ in xrange(n)]
    #     self.snap_id = 0

    # def set(self, index, val):
    #     self.A[index].append([self.snap_id, val])

    # def snap(self):
    #     self.snap_id += 1
    #     return self.snap_id - 1

    # def get(self, index, snap_id):
    #     i = bisect.bisect(self.A[index], [snap_id + 1]) - 1
    #     return self.A[index][i][1]






# Runtime: 524 ms, faster than 23.75% of Python3 online submissions for Snapshot Array.
# Memory Usage: 41.2 MB, less than 43.34% of Python3 online submissions for Snapshot Array.
class SnapshotArray:

    def __init__(self, length: int):
        self.snapid = 0
        # self.arr = [[]] * length            # .... 这个 是 length个元素， 每个元素都是 同一个[] 。。 所以导致。。。
        self.arr = [[] for i in range(length)]
        self.map2 = {}
        self.cnt = 0
        # print(len(self.arr[1]))


    def set(self, index: int, val: int) -> None:
        # print("set  " + str(self.cnt) + ", " + str(index))
        self.arr[index].append((val, self.cnt))
        self.cnt += 1
        # print(". " + str(len(self.arr[1])) + ", " + str(len(self.arr[0])))
        # for a in self.arr:
        #     for v in a:
        #         print(v, end = ",")
        #     print()
        # print("==========================")
 
    def snap(self) -> int:
        self.map2[self.snapid] = self.cnt - 1
        ans = self.snapid
        self.snapid += 1
        self.cnt += 1
        return ans

    def get(self, index: int, snap_id: int) -> int:
        t2 = self.map2[snap_id]
        ans = 0
        # print("   " + str(len(self.arr[index])) + ", " + str(len(self.arr)) + ", " + str(index))
        # for p2 in self.arr[index]:
        #     # print(str(p2[1]) + ", " + str(t2))
        #     if p2[1] <= t2:
        #         ans = p2[0]
        #     else:
        #         break
        # tle,, 耗时只有这里。其他2个方法都是O(1)的， 就这个O(n)

# >>> data = [('red', 5), ('blue', 1), ('yellow', 8), ('black', 0)]
# >>> data.sort(key=lambda r: r[1])
# >>> keys = [r[1] for r in data]         # precomputed list of keys
# >>> data[bisect_left(keys, 0)]
# ('black', 0)
# bisect 没办法直接用，需要一个辅助数组。。当前情况，不需要排序的，append的时候就是有序的。

        ar = self.arr[index]                    # 这个是 引用 还是 复制？  &
        l, r = 0, len(ar) - 1
        if r < 0 or ar[0][1] > t2:
            return ans

        while l < r:
            mid = (l + r + 1) // 2
            # print(str(l) + ", " + str(r) + ", " + str(mid))       # 0,1,0   (l+r+1) // 2 ?
            md = ar[mid]
            if md[1] == t2:
                l = r = mid
            elif md[1] < t2:
                l = mid         # +1
            else:
                r = mid - 1
        # print(l)
        ans = ar[l][0]
        return ans

if __name__ == "__main__":
    sz1 = 3
    ssa = SnapshotArray(sz1)
    ssa.set(0,5)
    id = ssa.snap()
    print(id)
    ssa.set(0,6)
    print(ssa.get(0,0))

    # tst2 = [[1,2,3],[4,5,6]]
    # tst = tst2[1]
    # tst[1] = 111111
    # print(tst2[1][1])



# ["SnapshotArray","snap","snap","get","set","snap","set"]
# [[4],[],[],[3,1],[2,4],[],[1,4]]
# [null,0,1,0,null,2,null]

    # ssa = SnapshotArray(4)
    # ssa.snap()
    # ssa.snap()
# Initially, each element equals 0. ......


# ["SnapshotArray","set","snap","snap","get","get","snap","snap"]
# [[2],[0,12],[],[],[1,0],[1,0],[],[]]
# [null,null,0,1,0,0,2,3]

    # ssa = SnapshotArray(2)
    # ssa.set(0,12)
    # print(ssa.snap())
    # print(ssa.snap())
    # t2 = ssa.get(1,0)
    # print(t2)
    # t2 = ssa.get(1,0)
    # print(t2)
    # print(ssa.snap())
    # print(ssa.snap())


# ["SnapshotArray","set","set","set","snap","get","snap"]
# [[1],[0,4],[0,16],[0,13],[],[0,0],[]]

    # ssa = SnapshotArray(1)
    # ssa.set(0,4)
    # ssa.set(0,16)
    # ssa.set(0,13)
    # id = ssa.snap()
    # print(ssa.get(0,0))