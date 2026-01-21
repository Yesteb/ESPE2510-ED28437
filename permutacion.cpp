#include <iostream>
#include <functional>

int main() {
        int nums[4] = {1, 2, 3, 4};
        int actual[4];
        bool usado[4] = {false, false, false, false};
        int len = 0;

        std::function<void()> backtrack = [&](){
                if(len == 4){
                        for(int i = 0; i < 4; i++)
                                std::cout << actual[i] << " ";
                        std::cout << std::endl;


                }

                for (int i = 0; i < 4; i++){
                        if(usado[i]) continue;

                        usado[i] = true;
                        actual[len++] = nums[i];

                        backtrack();

                        len--;

                        usado[i] = false;



                }



        };


        backtrack();

}
