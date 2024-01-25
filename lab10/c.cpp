#include <iostream>
#include <vector>
using namespace std;

void operation(int a, int b) {
    vector<int> result;

    while (a != b) {
        if (b < a || b % 2 != 0) {
            result.push_back(b);
            ++b;
        } else {
            result.push_back(b);
            b /= 2;
        }
    }

    cout << result.size() << endl;
    for(int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int a, b;
    cin >> a >> b;
    
    operation(a, b);

    return 0;
}