#include <bits/stdc++.h>

std::string str[100];

signed main()
{
    int TC;
    std::cin>> TC;
    for(int i=0; i<TC; i++) {
        std::cin>> str[i];
    }
    for(int i=0; i<TC; i++) {
        int len = str[i].length();
        if(len>10){
            std::cout<< str[i][0]<< len-2 << str[i][len-1]<< std::endl;
        } else {
            std::cout<< str[i]<< std::endl;
        }
    }
    return 0;
}