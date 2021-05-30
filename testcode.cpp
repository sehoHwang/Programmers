#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
using namespace std;
 
int main(){
    vector<string> tmp;
    ifstream file("test.txt");
    if (true == file.is_open()) {
        std::string s;
        while (file) {
            getline(file, s, ',');
            tmp.push_back(s);
        }
        file.close();
    } else {
        std::cout << "file open fail" << std::endl;
    }
    //sort(tmp.begin(), tmp.end());
    cout<<tmp.size();
    return 0;
}
