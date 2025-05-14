#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// 判断是否为操作符
bool isOperator(const string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// 递归计算逆波兰表达式
int evaluateRPNRecursive(const vector<string>& expression, int &index) {
    if (index < 0) {
        // 如果索引越界，返回错误
        cout << "Expression Error: Not enough operands" << endl;
        exit(EXIT_SUCCESS);
    }

    string token = expression[index];
    
    if (!isOperator(token)) {
        // 如果是操作数，直接返回数值
        return stoi(token);
    } else {
        // 如果是操作符，递归处理
        if (index < 2) {  // 如果没有足够的操作数来匹配操作符
            cout << "Expression Error: " << token << endl;
            exit(EXIT_SUCCESS);
        }

        int operand2 = evaluateRPNRecursive(expression, --index);
        int operand1 = evaluateRPNRecursive(expression, --index);
        
        if (token == "+") {
            return operand1 + operand2;
        } else if (token == "-") {
            return operand1 - operand2;
        } else if (token == "*") {
            return operand1 * operand2;
        } else if (token == "/") {
            if (operand2 == 0) {
                cout << "Error: "<<operand1 <<'/'<< operand2 << endl;
                exit(EXIT_SUCCESS);
            }
            return operand1 / operand2;
        }
    }

    return 0;
}

int main() {
    vector<string> expression;
    string input;

    // 读取输入直到遇到 "#"
    while (cin >> input) {
        if (input == "#") {
            break;
        } else {
            expression.push_back(input);
        }
    }

    int index = expression.size() - 1;  // 从末尾开始递归计算
    int result = evaluateRPNRecursive(expression, index);
    
    // 如果递归完成后索引不为0，说明操作数多了
    if (index != 0) {
        cout << "Expression Error: " << expression[index] << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
