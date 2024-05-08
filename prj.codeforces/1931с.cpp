#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::unordered_map<int, std::vector<int>> positions;

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            positions[a[i]].push_back(i);
        }

        int min_cost = n; // Initialize with the maximum possible cost

        for (auto &p: positions) {
            // p.first is the number, p.second is the vector of positions
            std::vector<int> &pos = p.second;
            int max_len = 0;
            int current_len = 1;

            for (size_t i = 1; i < pos.size(); i++) {
                if (pos[i] == pos[i - 1] + 1) {
                    current_len++;
                } else {
                    max_len = std::max(max_len, current_len);
                    current_len = 1;
                }
            }
            max_len = std::max(max_len, current_len); // Check last sequence

            int cost = n - max_len; // Cost to make all elements equal to p.first
            min_cost = std::min(min_cost, cost);
        }

        std::cout << min_cost << std::endl;
    }
    return 0;
}
