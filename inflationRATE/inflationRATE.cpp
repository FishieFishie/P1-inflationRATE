#include <iostream>
#include <iomanip>

using namespace std;

//OBJECTIVE: stores user's input and calculate the inflation rates based on the input

//get_input ; obtain user's input: the current price of this year, the price from last year, and then the price two years ago
void get_input(float& price_CURRENT_year, float& price_ONEyear_ago, float& price_TWOyears_ago) {
    cout << "Enter the current price of the item (DO NOT INCLUDE '$' and '¢' in the input): ";
    cin >> price_CURRENT_year;
    cout << "Enter the price of the item one year ago (MUST be the SAME PRODUCT): ";
    cin >> price_ONEyear_ago;
    cout << "Enter the price of the item two years ago: ";
    cin >> price_TWOyears_ago;
}

//calcul_inflation ; establish an equation for the two variables - inflat_rate_YEAR1 and inflat_rate_YEAR2
void calcul_inflation(float price_CURRENT_year, float price_ONEyear_ago, float price_TWOyears_ago, float& inflat_rate_YEAR1, float& inflat_rate_YEAR2) {
    //calculation ; subtract the two variables and divide it by the variable (or the subtrahend/second variable)    
    inflat_rate_YEAR1 = (price_CURRENT_year - price_ONEyear_ago) / price_ONEyear_ago;
    inflat_rate_YEAR2 = (price_ONEyear_ago - price_TWOyears_ago) / price_TWOyears_ago;
}

//OUTPUT_results ; inform the user whether or not the inflation rate is increasing, decreasing, or steady/stable
void OUTPUT_results(float inflat_rate_YEAR1, float inflat_rate_YEAR2) {
    string trend;
    if (inflat_rate_YEAR1 > inflat_rate_YEAR2)
        trend = "increasing";
    else if (inflat_rate_YEAR1 < inflat_rate_YEAR2)
        trend = "decreasing";
    else
        trend = "stable";

    //inflat_rate ; multiply the inflat_rate by 100 to get the percent / For example: 0.20 --> 20%
    cout << fixed << setprecision(2);
    cout << "Inflation rate for the first year: " << inflat_rate_YEAR1 * 100 << "%" << endl;
    cout << "Inflation rate for the second year: " << inflat_rate_YEAR2 * 100 << "%" << endl;
    cout << "The inflation trend is " << trend << "." << endl;
}

//main ; establish the variables
int main() {
    float price_CURRENT_year, price_ONEyear_ago, price_TWOyears_ago;
    get_input(price_CURRENT_year, price_ONEyear_ago, price_TWOyears_ago);

    float inflat_rate_YEAR1, inflat_rate_YEAR2;
    calcul_inflation(price_CURRENT_year, price_ONEyear_ago, price_TWOyears_ago, inflat_rate_YEAR1, inflat_rate_YEAR2);

    OUTPUT_results(inflat_rate_YEAR1, inflat_rate_YEAR2);

    return 0;
}

//EXPECTATION: the program has to display the inflation rates (x2) and inform the user whether or not the rate is increasing, decreasing, or steady/stable