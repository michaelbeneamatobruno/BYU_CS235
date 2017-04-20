#include <set>
#include <vector>
#include <map>
#include <deque>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[])
{
 
    vector<string> tokens;
    string next_line;  // Each data line
    ifstream in(argv[1]);
    string token;
    while (in >> token) {
        string nopunct = "";
        for(auto &c : token) { // Remove Punctuatio
            if (isalpha(c)) {
                c = tolower(c);
                nopunct +=c; 
            }
        }
        tokens.push_back(nopunct);
    }
    cout << "Number of words "<<tokens.size()<<endl;
  
    // maps
    map <deque <string>, vector <string>> wordmap;
    deque <string> current;
    current.push_back("");
    current.push_back("");
    for(auto &s:tokens) {
        wordmap[current].push_back(s);
        current.push_back(s);
        current.pop_front();
    }
    current.clear();
    current.push_back("");
    current.push_back("");
    for(int i =0; i < 100; i++) {
        if(wordmap[current].size() != 0) {
            int ind = rand() % wordmap[current].size();
            cout << wordmap[current][ind]<<" ";
            current.push_back(wordmap[current][ind]);
            current.pop_front();
        } else {
            current.clear();
            current.push_back("");
            current.push_back("");
        }
        
    }
    cout << endl;
    cout << endl;
}