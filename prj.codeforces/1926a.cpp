#include <iostream>
#include <vector>
#include <string>


int main(){
    int t = 0;
    std::cin >> t;
    std::vector<char> arr;
    while (t > 0){
        --t;
        std::string str;
        std::cin >> str;
        int cnt_A = 0;
        int cnt_B = 0;
        for (char alpha : str){
            if (alpha == 'A'){
                cnt_A++;
            }else{
                cnt_B++;
            }
        }
        if (cnt_A > cnt_B){
            arr.push_back('A');
        }else{
            arr.push_back('B');
        }
    }
    for (char alpha : arr){
        std::cout << alpha << std::endl;
    }
}