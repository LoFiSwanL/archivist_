#include <iostream>
#include <cmath>
#include <format>

using namespace std;

const double a = -0.9;
const double b = 0.9;

void info();
double input();
void check_x(double x);
void check_eps(double eps);
double s(double x, double eps);

int main() {
    double x, eps;
    info();
    try {
    cout << "Enter a real from [-0.9, 0.9]: ";
    x = input();
    check_x(x);

    cout << "Enter positive eps: ";
    eps = input();
    check_eps(eps);

    cout << "***** do calculations ... ";
    double result = s(x, eps);
    cout << "done" << endl;

    cout << format("\nfor x = {:.7e}", x) << endl;
    cout << format("for eps = {:.5e}", eps) << endl;
    cout << format("result = {:.10f}", result) << endl;
    }
    catch (const invalid_argument& a) {
        cout << "***** error " << a.what() << endl;
    }

    return 0;
}
void info(){
    cout << "The author of this program is Itsko Andrii" << endl;
    cout << "This program calculates the value of the series sum of (x^(2n+2))/((n+1)(2n+1)). Variant 182." << endl;
}
//if x not a number this function throw exception and gives you a such sentence
double input() {
    double value;
    cin >> value;
    if (cin.fail()) {
        throw invalid_argument("\nSorry we could not convert string to float.");
    }
    return value;
}
//if x is not from domain this function throw exception and gives you a such sentence
void check_x(double x){
    if (x < a || x > b) {
        throw invalid_argument("\nAt time of getting x there are no input or it could not be converted to float.");
    }
}
//if eps is not from domain this function throw exception and gives you a such sentence
void check_eps(double eps){
    if (eps <= 0) {
        throw invalid_argument("\nAt time of getting eps incorrect value is obtained.");
    }
}
double s(double x, double eps) {
    double sum = 0.0;
    double a_n = x * x;
    int n = 1;

while(a_n >= eps || a_n <= -eps) {
        sum += a_n;
        a_n = a_n * (n * (2.0 * n - 1.0) * x * x) / ((n + 1.0) * (2.0 * n + 1.0));
        n++;
    }

    return sum + a_n;
}
