
# def product_except_self(nums)
#     n = nums.size
#     out = [1] * n
#     left = right = 1
#     1.upto(n-1) { |i|
#         out[i] *= left *= nums[i-1]
#         out[~i] *= right *= nums[-i]
#     }
#     out
# end


# nums.each_with_index do |n,i|
#     if i==$pos0
#         ans.append($prod)
#     else
#         ans.append(0)
#     end
# end


# Runtime: 124 ms, faster than 71.61% of Ruby online submissions for Product of Array Except Self.
# Memory Usage: 216.9 MB, less than 48.39% of Ruby online submissions for Product of Array Except Self.
# @param {Integer[]} nums
# @return {Integer[]}
def product_except_self(nums)
    # ans = Arrays.new(nums.size， 0);        # uninitialized constant Arrays
    
    # ans = Arrays.new              # 搞错了，以为是要求常量作为数组的长度。。。 结果是 Arrays != Array 。。。
    # (0...nums.size).each do ans << 0 end

    ans = Array.new(nums.size, 0);

    prod = 1;
    cnt0 = 0;
    i = 0;
    idx0 = -1;
    nums.each do |v|            # v=xxx 能修改nums中数据？
        if v != 0 then
            prod *= v;
        else
            cnt0 += 1
            idx0 = i;
            if cnt0 > 1 then
                return ans;
            end
        end
        i += 1;
    end
    if cnt0 >= 2 then           # not reach
        # return ans;
    elsif cnt0 == 1 then
        ans[idx0] = prod
        # return ans;
    else 
        i = 0;
        for i in (0...ans.size) do           # 没有类似c的for
            ans[i] = prod / nums[i];
        end
    end
    return ans;
end

# arr = [1,2,3,4]
# arr.each do |v|
#     v *= 2              # 改不了
# end
# puts arr

arr = [-1,1,0,-3,3]

ans = product_except_self(arr)
ans.each do |v|
    puts v
end
