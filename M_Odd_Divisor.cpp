#include <iostream>

signed main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        long long n;
        std::cin >> n;
        if (n % 2 != 0)
            std::cout << "YES" << std::endl;
        else
        {
            while (n%2 == 0)
            {
                n /= 2;
            }
            if(n==1) {
                std::cout << "NO" << std::endl;
            }else std::cout << "YES" << std::endl;
        }
    }
    return 0;
}