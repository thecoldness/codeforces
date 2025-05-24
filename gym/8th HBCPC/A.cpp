#include <iostream>
#include <string>

int a[30];

int main()
{
    std::string s;
    std::cin >> s;
    int n = s.length();
    for (char i : s)
        a[i - 'a'] ++;
    int ans = 0;
    for(int i = 0 ; i < 26 ; ++ i)
        ans += (a[i] != 0);
    if(a['i' - 'a'])
        -- ans;
    std::cout << ans << '\n';
}