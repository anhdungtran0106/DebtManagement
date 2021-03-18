#include <iostream>
#include <string>
#include "Debt.h"

using namespace std;

void Debt::insertInfomation()
{
    cout << "\tInsert Amount Of Money: ";
    cin >> amount_owed;

    cin.ignore();
    creditor.insertInformation();

    cout << "\tInsert Repayment Date: ";
    int month, day, year;
    cin >> month >> day >> year;
    repayment_date.setDate(month, day, year);

    cout << "\tInsert Interest Rate: ";
    cin >> interest_rate;
}

void Debt::print()
{
    cout << "\tAmount Owed: " << amount_owed << endl;
    cout << "\tInterest Rate: " << interest_rate << endl;
    cout << "\tCreditor: " << creditor.getName() << endl;
    cout << "\tRepayment Date: " << repayment_date.toString() << endl << endl;
}