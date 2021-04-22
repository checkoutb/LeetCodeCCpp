






# ren hao shao
# Runtime: 100 ms, faster than 100.00% of Ruby online submissions for Longest Subarray of 1's After Deleting One Element.
# Memory Usage: 213 MB, less than 100.00% of Ruby online submissions for Longest Subarray of 1's After Deleting One Element.
# @param {Integer[]} nums
# @return {Integer}
def longest_subarray(nums)
    ans = 0;
    len0 = 0;
    len1 = 0;
    lst1 = 0;
    lst0 = 0;
    nums.each do |val|

        if val == 1 then
            len1 += 1
            if len1 == 1 then 
                lst0 = len0;
                len0 = 0;
            end
            if len1 > ans then
                ans = len1
            end
        else
            # ans = max()       // where is max ?
            if lst0 == 1 then
                if lst1 + len1 > ans then
                    ans = lst1 + len1;
                end
            end
            len0 += 1
            if (len0 == 1) then
                lst1 = len1;
                len1 = 0;
            end                        # 可以增加：len0 > 1, lst1 = 0;
        end                 # 吐了， if then end，匹配不起来。。一直说这里多了一个end， 然后 44行(就是最后一行) 少了一个end
                        # ruby 好像没有++，， len0++，不知道翻译成什么了。。。。导致匹配不上
    end

    if (lst0 == 1 and (lst1 + len1 > ans)) then
        ans = lst1 + len1;
    end
    if (len1 > ans) then ans = len1 end
    if (lst1 > ans) then ans = lst1 end
    # if ans == nums.size then ans -= 1 end
    if lst0 == 0 && len0 == 0 then ans = nums.length - 1 end

    return ans;
end

puts "hi"

# arr = Array[1,1,0,1]
# arr = Array[0,1,1,1,0,1,1,0,1]
# arr = Array[1,1,1,0]
# arr = Array[1,1,0,0,1,1,1,0,1]
# arr = Array[0,0,0]
# 14
arr = Array[1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,1]

ans = longest_subarray(arr);

puts ans
