#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Person {
    string id;
    int de;
    int cai;
    int total;
} Person;

bool cmp(const Person& p1, const Person& p2) {
    if (p1.total != p2.total) 
        return p1.total > p2.total; // 按总分降序
    else if (p1.de != p2.de) 
        return p1.de > p2.de;       // 按德分降序
    else 
        return p1.id < p2.id;       // 按字典序升序
}

int main() {
    int n, l, h;
    cin >> n >> l >> h;

    vector<Person> class1, class2, class3, class4;

    for (int i = 0; i < n; i++) {
        string id;
        int de, cai;
        cin >> id >> de >> cai;

        if (de < l || cai < l) {
            continue;
        } else if (de >= h && cai >= h) {
            class1.push_back({id, de, cai, de + cai});
        } else if (de >= h) {
            class2.push_back({id, de, cai, de + cai});
        } else if (de >= cai) {
            class3.push_back({id, de, cai, de + cai});
        } else {
            class4.push_back({id, de, cai, de + cai});
        }
    }

    sort(class1.begin(), class1.end(), cmp);
    sort(class2.begin(), class2.end(), cmp);
    sort(class3.begin(), class3.end(), cmp);
    sort(class4.begin(), class4.end(), cmp);

    cout << class1.size() + class2.size() + class3.size() + class4.size() << endl;

    for (const auto& person : class1) 
        cout << person.id << " " << person.de << " " << person.cai << endl;
    for (const auto& person : class2) 
        cout << person.id << " " << person.de << " " << person.cai << endl;
    for (const auto& person : class3) 
        cout << person.id << " " << person.de << " " << person.cai << endl;
    for (const auto& person : class4) 
        cout << person.id << " " << person.de << " " << person.cai << endl;

    return 0;
}
