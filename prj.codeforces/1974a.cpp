#include <iostream>
#include <vector>

int main(){
    int t = 0;
    std::cin >> t;
    std::vector<int> answers;
    while (t > 0){
        --t;
        int free_space = 0;
        int desktops = 0;
        int x, y = 0;
        std::cin >> x >> y;
        desktops = (y % 2) ? (y / 2) + 1 : (y / 2);
        free_space = (desktops * 15) - (y * 4);
        if ((free_space - x) >= 0)
            answers.push_back(desktops);
        else{
            x -= free_space;
            int cnt = 0;
            while (x > 0){
                cnt++;
                x -= (cnt * 15);
                if (x <= 0){
                    int temp = desktops+cnt;
                    answers.push_back(temp);
                    break;
                }
            }
        }
    }
    for (int elem : answers){
        std::cout << elem << std::endl;
    }
}
//  какая-то ошибка есть, но найти ее я не в силах