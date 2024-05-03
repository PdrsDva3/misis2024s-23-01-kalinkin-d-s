#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;

        int countU = 0;
        for (char c: s) {
            if (c == 'U') {
                countU++;
            }
        }

        if (countU % 2 == 1) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
