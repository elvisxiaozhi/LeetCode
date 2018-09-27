#include <iostream>
#include <algorithm>

using namespace std;

int strStr(string haystack, string needle)
{
//    return haystack.find(needle);

    if(needle.empty()) {
        return 0;
    }
    else if(needle.size() > haystack.size()) {
        return -1;
    }

    vector<int> indexVec;
    for(unsigned int i = 0; i < haystack.size(); ++i) {
        if(haystack[i] == needle[0]) {
            if(i + needle.size() - 1 <= haystack.size()) {
                indexVec.push_back(i);
            }
        }
    }
    if(indexVec.size() == 0) {
        return -1;
    }

    int index = 0;
    for(unsigned int i = 0; i < indexVec.size(); ++i) {
        index = indexVec[i];
        for(unsigned int j = 0; j < needle.size(); ++j) {
            if(needle[j] != haystack[indexVec[i] + j]) {
                index = -1;
                break;
            }
            else if(j == needle.size() - 1) {
                return index;
            }
        }
    }

    return index;
}

int main()
{
    cout << strStr("a", "a") << endl;
    cout << strStr("aaaa", "bba") << endl;
    cout << strStr("mississippi", "issipi") << endl;
    cout << strStr("mississippi", "issip") << endl;
    cout << strStr("mississippi", "sippj") << endl;
    cout << strStr("Hello", "ll") << endl;
    return 0;
}
