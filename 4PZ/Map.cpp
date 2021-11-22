#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {

    map <string, int> mp;
    string line;
    string word;

    cout << "Enter string: " << endl;

    getline(cin, line);
    stringstream ss (line);

    while (getline(ss, word, ' ')) {
        if (mp.find(word) == mp.end())
        {
            mp.emplace(word, 1);
        }
        else
        {
            mp[word]++;
        }
    }
    

    map <string, int> ::iterator it = mp.begin();

    for (int i = 0; it != mp.end(); it++, i++) 
    {
        cout << i << "  " << it->first << ": " << it->second << endl;
    }

    return 0;
}