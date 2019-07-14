#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double a;
    double kavg = 0.0, avg = 0.0, ksum = 0.0, sum = 0.0;
    int n = 0;

    while (std::cin >> a) {
        sum += a;
        ksum += a * a;
        n++;
    }

    avg = sum / n;
    kavg = sqrt((ksum - 2 * avg * sum) / n + avg * avg);
    std::cout << std::fixed << std::setprecision(10) << avg << " " << kavg << std::endl;
}
