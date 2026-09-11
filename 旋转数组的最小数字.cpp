int minNumberInRotateArray(vector<int>& nums) {
    if (nums.empty()) return 0;                  // 空数组防御
    
    int left = 0, right = (int)nums.size() - 1;  // 双指针夹逼
    
    while (left < right) {                       // 区间缩到一个元素时结束
        int mid = left + (right - left) / 2;     // 防溢出 + 向下取整
        
        if (nums[mid] > nums[right])             // mid 在左段(大)
            left = mid + 1;                      //   最小值在右边，mid 可排除
        else if (nums[mid] < nums[right])        // mid 在右段(小)
            right = mid;                         //   mid 可能是答案，不能 -1
        else                                     // 相等，判断不了在哪段
            right--;                             //   砍掉右端点缩小范围
    }
    
    return nums[left];                           // left == right，即最小值
}