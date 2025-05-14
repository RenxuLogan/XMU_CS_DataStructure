#include<iostream>
#include<unordered_set>
using namespace std;

int n, m;

int main() {
    cin >> m >> n;  // m 是窗口大小，n 是数据数量
    int* array = new int[m];  // 用 m 大小的数组来模拟滑动窗口
    unordered_set<int> window;  // 使用哈希集合来存储窗口中的元素
    int head = 0, tail = 0, count = 0;  // 初始情况
    bool is_full = false;  // 用于判断窗口是否已满

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        if (window.find(input) == window.end()) {  // 如果当前元素不在窗口中
            count++;  // 计数器增加

            if (is_full) {  // 如果窗口已经满了
                window.erase(array[head]);  // 从集合中移除最早的元素
                head = (head + 1) % m;  // 移动头指针
            }

            // 插入新元素到窗口中
            array[tail] = input;
            window.insert(input);  // 将新元素加入集合
            tail = (tail + 1) % m;  // 移动尾指针

            if (tail == head) {  // 如果窗口满了
                is_full = true;  // 标记窗口已满
            }
        }
    }

    cout << count << endl;  // 输出不重复元素的数量
    delete[] array;  // 释放动态分配的内存
    return 0;
}
