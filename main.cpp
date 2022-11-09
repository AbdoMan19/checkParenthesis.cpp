#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
bool isValid(string s){
    string open = "({[";
    string close = ")}]";
//    ({})()
    vector<char> container;
    for (int i = 0; i < s.size(); i++) {
        if (open.find(s[i]) != string::npos) {
            container.push_back(s[i]);
        } else if (container.size() == 0) {
            return false;
        } else if (s[i] == close[open.find(container[container.size() - 1])]) {
            container.pop_back();

        } else {
            return false;
        }
    }
    if (container.size() == 0) {
        return true;
    } else {
        return false;
    }
}
int main() {
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}
