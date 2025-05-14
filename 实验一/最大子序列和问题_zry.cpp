#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArraySum(const vector<int>& arr) {
    int max_ending_here = 0, max_so_far = 0;

    for (int num : arr) {
        max_ending_here += num;
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}

int main() {
    int K;
    cin >> K;

    vector<int> arr(K);
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }

    cout << maxSubArraySum(arr) << endl;

    return 0;
}