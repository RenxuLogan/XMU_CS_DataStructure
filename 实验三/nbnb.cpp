#include<iostream>
#include<cstring>
#define MAXN 1000010
using namespace std;

int kmp[MAXN], la, lb, j; // kmp数组存储前缀表，la和lb分别为a和b的长度，j为匹配的索引
char a[MAXN], b[MAXN];

int main() {
    cin >> a+1 >> b+1; // 输入字符串a和b，从下标1开始存储
    la = strlen(a+1);  // 获取字符串a的长度
    lb = strlen(b+1);  // 获取字符串b的长度

    // 构建KMP前缀表
    for (int i = 2; i <= lb; i++) {
        while (j && b[i] != b[j+1]) j = kmp[j]; // 不匹配时跳转到前一个匹配位置
        if (b[j+1] == b[i]) j++;                // 如果字符匹配，前缀长度增加
        kmp[i] = j;                             // 记录前缀长度
    }

    j = 0; // 初始化匹配索引
    // 主串a和模式串b的匹配过程
    for (int i = 1; i <= la; i++) {
        while (j > 0 && b[j+1] != a[i]) j = kmp[j]; // 若字符不匹配，使用前缀跳转
        if (b[j+1] == a[i]) j++;                   // 如果匹配，匹配索引增加
        if (j == lb) {                              // 如果完全匹配模式串
            cout << i - lb + 1 << endl;             // 输出匹配起始位置
            j = kmp[j];                             // 使用前缀跳转
        }
    }

    // 输出前缀数组kmp
    for (int i = 1; i < lb; i++){ cout << kmp[i] << " ";
    cout << kmp[lb] << endl;
    return 0;
    }
}