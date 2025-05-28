#include <iostream>
#include <format>
#include <numbers>
#include <cmath>

using namespace std;

void user_info();
long double f(long double x);

int main()
{
    long double x;

    user_info();
    cout << "Enter x (x!=4 and x>3):";
    cin >> x;
    
    if (cin.fail()) { 
        cout << "\nwrong input" << endl;
        return 0;
    }
    cout << "\n***** do calculations ... ";

    long double result;
    bool defined = true;

    if (x == 4 || x <= 3) {
        defined = false;
    } else {
        result = f(x);
    }

    cout << "done" << endl;
    cout << format("for x = {:.5f}\n", x);

    if (defined) {
        cout << format("result = {:.9f}\n", result);
    } else {
        cout << "result = undefined" << endl;
    }

    return 0;
}

void user_info(){
    cout << "The author of this program is Itsko Andrii." << endl;
    cout << "This program calculates the value of the expression cos(23/70)+(30e/60Pi)*(3/((x-4)(x+15))-11*cos(x+7)-(1/sqrt(x-3)) by given x. Variant 182." << endl;
}

long double f(long double x){        //calculation of the given function in 182 variant
    long double a = cos(23.0 / 70.0);
    long double b = ((30.0 * numbers::e) / (60.0 * numbers::pi)) * (3.0 / ((x - 4.0) * (x + 15.0)));
    long double c = 11.0 * cos(x + 7.0);
    long double d = 1.0 / sqrt(x - 3.0);
    return a + b - c - d;
}