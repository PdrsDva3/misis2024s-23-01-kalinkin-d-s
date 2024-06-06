#include <iostream>
#include <algorithm> // For std::max

int main() {
    int nt;
    std::cin >> nt;

    for (int t = 0; t < nt; ++t) {
        int x, y;
        std::cin >> x >> y;

        int mm = (y + 1) / 2;
        x -= (mm * 5 * 3 - y * 2 * 2);
        x = std::max(x, 0);
        mm += (x + 5 * 3 - 1) / (5 * 3);

        std::cout << mm << std::endl;
    }

    return 0;
}
