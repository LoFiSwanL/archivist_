#include <iostream>
#include <cmath>
#include <format>

using namespace std;

const double a = -0.9;
const double b = 0.9;

double s(double x, double eps);
void info();

int main() {
    double x, eps;
    info();
    
    cout << "Enter a real from [-0.9, 0.9]: ";
    cin >> x;

    if (cin.fail() || x < a || x > b) {
        cout << "***** error" << endl;
        cout << "('At time of getting x'" << "," << "ValueError('There are no input or it could not be converted to float.')" << "," << "ValueError( could not convert string to float: 'qwerty'))" << endl; 
        return 0;
    }

    cout << "Enter positive eps: ";
    cin >> eps;

    if (cin.fail() || eps <= 0) {
        cout << "***** error" << endl;
        cout << "('At time of getting eps'" << ", " << "'Incorrect value.')" << endl;
        return 0;
    }

    cout << "***** do calculations ... ";
    double result = s(x, eps);
    cout << "done" << endl;

    cout << format("\nfor x = {: .7e}", x) << endl;
    cout << format("for eps = {: .5e}", eps) << endl;
    cout << format("result = {: .10f}", result) << endl;

    return 0;
}
void info(){
    cout << "The author of this program is Itsko Andrii" << endl;
    cout << "This program calculates the value of the series sum of (x^(2n+2))/((n+1)(2n+1)). Variant 182." << endl;
}
double s(double x, double eps) {
    double sum = 0.0;
    for (int n = 0; fabs(pow(x, 2 * n + 2) / ((n + 1) * (2 * n + 1))) >= eps; n++) {
        double a_n = pow(x, 2 * n + 2) / ((n + 1) * (2 * n + 1));
        sum += a_n;
    }

    return sum;
}
