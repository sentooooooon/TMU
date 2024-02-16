#include <iostream>
#include <fstream>

using namespace std;

int n, A[64], B[64];
int counter = 0;

void solve(int i, int m) {
    if (m == 0) {
        counter++;
        cout <<"Subset: ";
        for (int j = 0; j < i; j++) {
            if (B[j] == 1) {
                cout << A[j] << " ";
                }
            }
        cout <<endl;
        return;
    }
    if(i >= n){
        return;
    }

    B[i] = 0;
    solve(i + 1, m);
    B[i] = 1;
    solve(i + 1, m - A[i]);
}

int main() {
    ifstream file("data.txt");
    file >> n;
    int q, m;

    cout << "Sentaro Sakura" << endl;
    cout << "Student number: 22140003" <<endl;

    for (int i = 0; i < n; i++) {
        file >> A[i];
    }
    cout << "A[0.." << n - 1 << "] =";
    for (int i = 0; i < n; i++)
        cout << " " << A[i];
    cout << endl;

    cout << "Input the number of queries q: ";
    cin >> q;

    for (int i = 0; i < q; i++) {
        cout << "Query " << i + 1 << endl;
        cout << "Input a target value M: ";
        cin >> m;
        solve(0, m);
        cout << "Total number of solutions = " << counter << endl;
        counter = 0; // カウンターをリセット
    }

    return 0;
}
