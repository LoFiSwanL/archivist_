#include <iostream>
#include <format>
#include <numbers>
#include <cmath>

using namespace std;

double f(double x, double y);
void readnumber(double &);

int main() {
    double x, y;

    try{
        cout << "Enter x: ";
        readnumber(x);

        cout << "\nEnter y: ";
        readnumber(y);

        cout << "f(x,y) = " << f(x,y) << endl;
    }
    catch(domain_error g){
        cout << "Wrong x, " << g.what() << endl;
    }
    catch(logic_error g){
        cout << "Wrong input " << g.what() << endl;
    }
}

void readnumber(double &x){
    cin >> x;
    if (cin.fail()){
        throw logic_error("Not a number");
    }

}

double f(double x, double y){
    if(abs(x) < 1e-9){
        throw domain_error("x=0 error");
    }
    if(x < -1 || x > 1){
        throw domain_error("|x|>1 error");
    }
    double func = 1 / (acos(x) - (numbers::pi)/2) + y;
    return func;
}