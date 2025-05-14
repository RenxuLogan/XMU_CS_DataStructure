/*
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector <int> Max(N,1);
    vector <int> input;
    int n=N;
    while(n--){
        int x;
        cin>>x;
        input.push_back(x);
    }

    int max_head=0;
    int max_len=1;
    for(int i=1;i<N;i++){
        int flag=1;
        for(int j=i ; j<N&&flag ; j++){
            if(input[j]>input[j-1]){
                Max[i-1]+=1;
                if(Max[i-1]>max_len){
                    max_len=Max[i-1];
                    max_head=i-1;
                }
            }else{
                flag=0;
            }
        }
    }
    for (int i = max_head; i < max_head + max_len - 1; i++) {
        cout << input[i] << " ";
    }
    cout << input[max_head + max_len - 1] << endl;  // 输出最后一个元素

    return 0;
}
*/
//⬆️是通过两层循环实现，时间复杂度较高，对全部字串进行了遍历，接下来使用贪心算法的方法实现
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(const vector<int>& nums) {
    vector<int> tails;
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);  // 找不到比它大的数，加入尾部
        } else {
            *it = num;  // 替换找到的第一个大于等于 num 的元素
        }
    }
    // 返回 tails 的长度，即为最长递增子序列的长度，即最长递增子序列的长度
    return tails.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);// 定义一个长度为 n 的数组 nums
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << lengthOfLIS(nums) << endl;
    
    return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, max_len = 1, max_end = 0;
    cin >> n;
    vector<int> arr(n), dp(n, 1);
    for (int i = 0; i < n; cin >> arr[i++]);
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) dp[i] = dp[i-1] + 1;
        if (dp[i] > max_len) max_len = dp[i], max_end = i;
    }

    for (int i = max_end - max_len + 1; i <= max_end; i++) 
        cout << arr[i] << (i == max_end ? '\n' : ' ');

    return 0;
}
*/