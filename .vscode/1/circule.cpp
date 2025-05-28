#include <iostream>
#include <cmath>
#include <format>

using namespace std;

void f(float x1, float y1, float r1, float x2, float y2, float r2);

int main(){
    float x1, y1, x2, y2, r1, r2;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    
    f(x1, y1, r1, x2, y2, r2);
    
    return 0;
}
void f(float x1, float y1, float r1, float x2, float y2, float r2){
    float line;
    float x, y;
    x = (x2 - x1) * (x2 - x1);
    y = (y2 - y1) * (y2 - y1);
    line = sqrt(x + y);
    if(line == 0){
        cout << "-1" << endl;
    }
    else if(line == (r1 + r2) || line == abs(r1 - r2)){
        cout << "1" << endl;
    }
    else if(line > (r1 + r2) || line < abs(r1-r2)){
        cout << "0" << endl;
    }
    else if(line < (r1 + r2)){
        cout << "2" << endl;
    }
}