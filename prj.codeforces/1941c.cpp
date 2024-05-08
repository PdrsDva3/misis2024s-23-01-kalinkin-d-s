#include <iostream>
#include <vector>
#include <string>


int replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if (from.empty())
        return 0;

    size_t start_pos = 0;
    int cnt = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
        cnt++;
    }
    return cnt;
}

int main(){
    int t = 0;
    std::cin >> t;
    std::vector<int> answers;
    while(t > 0){
        --t;

        int n = 0;
        std::cin >> n;


        std::string str;
        std::cin >> str;

        int map = replaceAll(str, "map", "");
        int pie = replaceAll(str, "pie", "");

        int sum = map + pie;
        std::cout << sum << std::endl;
    }
}