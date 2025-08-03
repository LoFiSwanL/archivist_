#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int NUMBER(){
    int numb;
    cout << "Enter number of students: ";
    cin >> numb;
    return numb;
}
void Students(int Number){
    vector <pair<string, int>> Student(Number);
    cout << "Enter student and mark: ";
    for(int i = 0; i < Number; ++i){
        cin >> Student[i].first;
        cin >> Student[i].second;
    }
    sort(Student.begin(), Student.end(), [](const auto &a, const auto &b){return a.second > b.second;});
    for(const auto &s : Student){
        cout << s.first << " got a grade of " << s.second << endl;
    }
}


int main(){
    int Number = NUMBER();
    Students(Number);
}