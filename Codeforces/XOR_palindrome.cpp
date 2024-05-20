#include<bits/stdc++.h>

using namespace std;

int count_buggish(int n, int mp) {
    return (int)(n/2) - mp;
}

int count_mp(int n, const string str){
    int mp = 0;
    for(int i = 0; i< (int)(n/2); i++) {
        if(str[i] == str[n-1-i])
            mp++;
    }
    return mp*2;
}

int main()
{
    int TC;
    cin>> TC;
    while (TC--)
    {
        int n;
        cin>> n;
        string s;
        cin >> s;
        int mp = count_mp(n, s);
        int buggish = count_buggish(n, mp/2);

        string output = "";
        for(int i = 0; i<= n; i++) {
            int total = i;
            total -= buggish;
            if(total<0){
                output.push_back('0');
                continue;
            }
            total = max((total % 2), total - mp);
            total = max(0, total - (n % 2));

            if (total == 0)
            {
                output.push_back('1');
            }
            else
            {
                output.push_back('0');
            }
        }
        cout << output << endl;
    }
    
    return 0;
}
