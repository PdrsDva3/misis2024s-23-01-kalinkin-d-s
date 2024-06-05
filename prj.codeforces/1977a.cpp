#include <iostream>
#include <vector>


bool func(int step, int result){
    if ((step - result) < 0){
        return false;
    }else{
        if ((step - result) % 2 == 1){
            return false;
        }
    }
    return true;
}

int main(){
    int t = 0;
    std::cin >> t;
    std::vector<int> res;
    while (t > 0){
        t--;
        int steps, result = 0;
        std::cin >> steps >> result;
        if (func(steps, result)){
            res.push_back(1);
        }else{
            res.push_back(0);
        }
    }
    for (int i : res){
        if (i == 1)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}