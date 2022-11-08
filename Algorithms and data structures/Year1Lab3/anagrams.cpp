#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    std::vector<int> aCountOfChars(256, 0);
    std::vector<int> bCountOfChars(256, 0);

    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>> b;
        std::vector<int> aCountOfChars(256, 0);
        std::vector<int> bCountOfChars(256, 0);

        for(int i=0;i<a.size();++i)
        {
            ++aCountOfChars[a[i]];
        }
        for(int i=0;i<b.size();++i)
        {
            ++bCountOfChars[b[i]];
        }

        if(aCountOfChars == bCountOfChars)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
    }
    return 0;
}