/*
THIS IS A CODE TO CHECK A USER-ENTERED CREDIT CARD NUMBER VALIDITY USING LUHN'S ALGORITHM.
AUTHOR: YAZAN RIHAN.
*/

#include <iostream>
#include <cstring>
using namespace std;

const int length = 16;

bool checkValid(char[]);

int main()
{
    char creditCardNumber[length];
    do {
        cout << "Enter your credit card number: ";
        

        for (int i = 0; i < length; i++) {
            cin >> creditCardNumber[i];
        }

        if (checkValid(creditCardNumber)) {
            cout << endl << "The number is valid";
            break;
        }
        cout << "The number is not valid! Please try again" << endl << endl;

    } while (true);

    return 0;
}

bool checkValid(char ccn[]) {

    int intccn[length];

    for (int i = 0; i < length; i++) {
        intccn[i] = static_cast<int>(ccn[i]) - 48;
        //cout << endl << intccn[i];
    }

    for (int i = 0; i < length; i += 2) {
        intccn[i] *= 2;
    }

    int sum, digit;

    for (int i = 0; i < length; i += 2) {
        
        sum = 0;
        while (intccn[i] > 0) {
            digit = intccn[i] % 10;
            sum += digit;
            intccn[i] /= 10;
        }

        intccn[i] = sum;

    }
    int finalSum = 0;

    for (int i = 0; i < length; i++) {
        finalSum += intccn[i];
    }

    if ((finalSum % 10) == 0)
        return true;
    return false;


}