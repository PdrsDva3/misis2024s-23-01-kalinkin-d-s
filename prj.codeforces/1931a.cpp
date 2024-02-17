#include <iostream>
#include <vector>
#include <string>



//1931a
int main(){
    std::string str = "abcdefghijklmnopqrstuvwxyz";
    int t = 0;
    std::cin >> t;
    std::vector<int> arr;
    for(int c = 0; c < t; c++){
        int p = 0;
        std::cin>> p;
        arr.push_back(p);
    }

    for (int elem : arr) {
        bool flag = 1;
        bool flg = 1;
        for (int i1 = 1; i1 <= 26; i1++) {
            for (int i2 = 1; i2 <= 26; i2++) {
                for (int i3 = 1; i3 <= 26; i3++) {
                    if ((i1 + i2 + i3) == elem){
                        std:: cout << str[i1-1] << str[i2-1] << str[i3-1] << std::endl;
                        flag = 0;
                        flg = 0;
                        break;
                    }
                }
                if (flag == 0){
                    break;
                }
            }
            if (flg == 0){
                break;
            }
        }
    }
}