#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    priority_queue<int> pq;  // 優先度付きキュー

    string command;
    while (cin >> command) {
        if (command == "insert") {
            int k;
            cin >> k;
            pq.push(k);  // 要素を挿入
        } else if (command == "extract") {
            if (!pq.empty()) {
                int max_value = pq.top();  // 最大の要素を取り出す
                cout << max_value << endl;
                pq.pop();  // 取り出した要素を削除
            }
        } else if (command == "end") {
            break;
        }
    }

    return 0;
}
