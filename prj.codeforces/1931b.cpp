#include <iostream>
#include <vector>
#include <string>


int sum(std::vector<int> &e){
    int ssum = 0;
    for (int elem : e){
        ssum += elem;
    }
    return ssum;
}

//1931b
int main(){
    int cnt = 0;
    std::cin >> cnt;
    while (cnt > 0){
        --cnt;
        int t = 0;
        std::cin >> t;
        std::vector<int> arr;
        while (t > 0){
            --t;
            int p = 0;
            std::cin >> p;
            arr.push_back(p);
        }
        size_t sz = arr.size();
        int average_v = sum(arr) / sz;
        if (sz == 1){
            std::cout << "YES" << std::endl;
            continue;
        }
//        int ss = 0;
        for (int i = 0; i < sz-1; i++){
            if (arr[i] > average_v){
                arr[i+1] += arr[i] - average_v;
                arr[i] = average_v;
            }
        }
        int flag = 1;
        for (int num : arr){
            if (num != average_v) {
                flag = 0;
                break;
            }
        }
        if (flag == 1){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }
}