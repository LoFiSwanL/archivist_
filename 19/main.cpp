#include <iostream>
#include <vector>
#include <map>


using namespace std;

map<string, int> countWords(vector<string> text){
    map<string, int> count;
    for(string &a: text){
        if(count.contains(a)){
            count[a]++;
        }
        else{
            count[a] = 1; 
        }
    }
    return count;
}

ostream& operator<<(ostream &os, map<string, int> count){
    for(auto [word, frequency]: count){
        cout << word << "\t" << frequency << endl;
    }
    return os;
}

int main() {
    vector<string> text {"Hello" , "guy", "c++", "mvsc", "main", "main", "cpp" , "main" , "cpp" , "+" , "gaga" , "text"};

    cout << countWords(text);

}
