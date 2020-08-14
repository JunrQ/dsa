
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        int ca = 0;

        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
            int sum = 0;

            sum += i >= 0 ? a[i] - '0' : 0;
            sum += j >= 0 ? b[j] - '0' : 0;
            ans += (sum % 2) + '0';
            ca = sum / 2;
        }

        if (ca == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

