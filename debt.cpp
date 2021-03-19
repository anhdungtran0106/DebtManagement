#include <iostream>
#include <string>
#include "Debt.h"

using namespace std;

void Debt::insertInfomation()
{
    insertAmountOwed();
    insertUser();
    insertRepaymentDate();
    insertInterestRate();
}

void Debt::print()
{
    cout << "\tAmount Owed: " << amount_owed << endl;
    cout << "\tCreditor: " << creditor.getName() << endl;
    cout << "\tPhone Number: " << creditor.getPhoneNumber() << endl;
    cout << "\tRepayment Date: " << repayment_date.toString() << endl;
    cout << "\tInterest Rate: " << interest_rate << endl;
    if (debt_payment)
    {
        cout << "\tDebt Payment: Paid\n\n";
    } else { cout << "\tDebt Payment: Unpaid\n\n"; }
    
}

void Debt::insertAmountOwed()
{
    cout << "\tInsert Amount Of Money: ";
    cin >> amount_owed;
}

void Debt::insertUser()
{
    cin.ignore();
    creditor.insertInformation();
}

void Debt::insertRepaymentDate()
{
    int month, day, year;
    cout << "\tInsert Repayment Date: ";
    cin >> month >> day >> year;
    repayment_date.setDate(month, day, year);
}

void Debt::insertInterestRate()
{
    cout << "\tInsert Interest Rate: ";
    cin >> interest_rate;
}

void Debt::insertDebtPayment()
{
    debt_payment = true;
}