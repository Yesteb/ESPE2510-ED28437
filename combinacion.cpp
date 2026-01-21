#include <iostream>
#include <functional>

int main (){
        int nums[4] = {1,2,3,4};
        int actual[4];
        int len = 0;

        std::function<void(int)> backtrack = [&](int start) {

        for(int i = 0; i < len; i++)
                std::cout << actual[i] << " ";
        std::cout << std::endl;

        for(int i = start; i < 4; i++) {
                actual[len++] = nums[i];
                backtrack(i + 1);
                len--;

        }


        };

        backtrack(0);
}
