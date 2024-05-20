#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int n = s.size();
        int ans = 0;
        for(int len = n/2; len >= 1; len--){
            int t = 0;
            for(int i = 0; i + len < n; i++){
                if(s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?'){
                    t++;
                    if(t == len){
                        ans = max(ans, len);
                        break;
                    }
                }else{
                    t = 0;
                }
            }
        }

        cout << 2*ans << endl;
    }

    return 0;
}