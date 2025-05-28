#include <iostream>
#include <string>

using namespace std;

int main(){
    double x, y;
    char z;
    cin >> x >> y;
    cin >> z;

    if(z == '+'){
        cout << x + y << endl;
    }
    else if(z == '-'){
        cout << x - y << endl;
    }
    else if(z == '*'){
        cout << x * y << endl;
    }
    else if(z == '/'){
        cout << x / y << endl;
    }
    return 0;
}