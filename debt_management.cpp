#include <iostream>
#include <string>
#include <fstream>
#include "DebtManagement.h"
#include "Debt.h"

using namespace std;

void DebtManagement::printMenu()
{
    cout << "\t\tDebt Management Program\n\n";
    cout << "\t1. Debts\n";
    cout << "\t2. Loans\n";
    cout << "\t3. List Of Creditors And Debtors\n";
    cout << "\t4. Quit\n\n";
    cout << "\t Select Function: ";
    readFile();
    readFileLoan();
    int selection;
    cin >> selection;
    switch (selection)
    {
    case 1:
        debtManagement();
        break;
    
    case 2:
        loanManagement();
        break;
    
    case 4:
        exit(0);
    
    default:
        break;
    }
}

void DebtManagement::loanManagement()   
{
    cout << "\t\tSelect Functions\n\n";
    cout << "\t1. Show List Of Loans\n";
    cout << "\t2. Add Loan\n";
    cout << "\t3. Edit Loan\n";
    cout << "\t4. Delete Loan\n";
    cout << "\t5. Loan Payment\n";
    cout << "\t6. Quit\n\n";
    cout << "\t Select Function: ";

    int selection;
    cin >> selection;
    switch (selection)
    {
    case 1:
        showListOfLoans();
        loanManagement();
        break;

    case 2:
       addLoan();
       saveFileLoan();
       loanManagement();
       break;

    case 3:
        showListOfLoans();
        editFileLoan();
        saveFileLoan();
        loanManagement();
        break;

    case 4:
        deleteLoan();
        saveFileLoan();
        loanManagement();
        break;

    case 5:
        showListOfLoans();
        payLoan();
        saveFileLoan();
        loanManagement();
    
    case 6:
        printMenu();
        break;

    default:
        break;
    }
}

void DebtManagement::addLoan()
{
    Debt loan;

    loan.insertInfomation();
    loan_list[loan_amount] = loan;
    loan_amount++;
}

void DebtManagement::debtManagement()
{
    cout << "\t\tSelect Functions\n\n";
    cout << "\t1. Show List Of Debts\n";
    cout << "\t2. Add Debt\n";
    cout << "\t3. Edit Debt\n";
    cout << "\t4. Delete Debt\n";
    cout << "\t5. Debt Payment\n";
    cout << "\t6. Quit\n\n";
    cout << "\t Select Function: ";
    
    int selection;
    cin >> selection;
    switch (selection)
    {
    case 1:
        showListOfDebts();
        debtManagement();
        break;

    case 2:
        addDebt();
        saveFile();
        debtManagement();
        break;

    case 3:
        showListOfDebts();
        editFile();
        saveFile();
        debtManagement();
        break;
    
    case 4:
        deleteDebt();
        saveFile();
        debtManagement();
        break;

    case 5:
        showListOfDebts();
        payDebt();
        saveFile();
        debtManagement();
        break;

    case 6:
        printMenu();
    
    default:
        break;
    }
}

void DebtManagement::addDebt()
{
    Debt debt;

    debt.insertInfomation();
    debt_list[debt_amount] = debt;
    debt_amount++;
}

void DebtManagement::showListOfDebts()
{
    cout << "\t\tList Of Debts:\n\n";
    for (int i = 0; i < debt_amount; i++)
    {
        cout << i + 1 << ". ";
        debt_list[i].print();
    }
}

void DebtManagement::showListOfLoans()
{
    cout << "\t\tList Of Loans:\n\n";
    for (int i = 0; i < loan_amount; i++)
    {
        cout << i + 1 << ". ";
        loan_list[i].printLoan();
    }
}

void DebtManagement::deleteDebt()
{
    showListOfDebts();
    cout << "\tWhat debt do you want to write off: ";
    int selection;
    cin >> selection;
    
    while (selection > debt_amount || selection <= 0)
    {
        cout << "Invalid number, please re-enter: ";
        cin >> selection;
    }

    selection--;
    for (int i = selection; i < debt_amount; i++)
    {
        debt_list[i] = debt_list[i + 1];
    }
    debt_amount--;
}

void DebtManagement::deleteLoan()
{
    showListOfLoans();
    cout << "\tWhat loan do you want to write off: ";
    int selection;
    cin >> selection;
    
    while (selection > loan_amount || selection <= 0)
    {
        cout << "Invalid number, please re-enter: ";
        cin >> selection;
    }

    selection--;
    for (int i = selection; i < loan_amount; i++)
    {
        loan_list[i] = loan_list[i + 1];
    }
    loan_amount--;
}

void DebtManagement::saveFile()
{
    fstream f;
    f.open("debt.txt", ios::out);

    f << debt_amount << endl;
    for (int i = 0; i < debt_amount; i++)
    {
        f << debt_list[i].getAmountOwed() << endl;
        f << debt_list[i].getUser().getName() << endl;
        f << debt_list[i].getUser().getPhoneNumber() << endl;
        f << debt_list[i].getDate().getMonth() << endl;
        f << debt_list[i].getDate().getDay() << endl;
        f << debt_list[i].getDate().getYear() << endl;
        f << debt_list[i].getInterestRate() << endl;
    }

    f.close();
}

void DebtManagement::saveFileLoan()
{
    fstream f;
    f.open("loan.txt", ios::out);

    f << loan_amount << endl;
    for (int i = 0; i < loan_amount; i++)
    {
        f << loan_list[i].getAmountOwed() << endl;
        f << loan_list[i].getUser().getName() << endl;
        f << loan_list[i].getUser().getPhoneNumber() << endl;
        f << loan_list[i].getDate().getMonth() << endl;
        f << loan_list[i].getDate().getDay() << endl;
        f << loan_list[i].getDate().getYear() << endl;
        f << loan_list[i].getInterestRate() << endl;
    }

    f.close();
}

void DebtManagement::readFile()
{
    fstream f;
    f.open("debt.txt", ios::in);

    f >> debt_amount;
    for (int i = 0; i < debt_amount; i++)
    {
        long amount_owed;
        f >> amount_owed;
        string name;
        f.ignore();
        getline(f, name);
        string phone_number;
        getline(f, phone_number);
        int month, day, year;
        f >> month;
        f >> day;
        f >> year;
        float interest_rate;
        f >> interest_rate;

        User creditor(name, phone_number);
        Date repayment_date(month, day, year);
        debt_list[i].set(amount_owed, creditor, repayment_date,interest_rate);

        f.close();
    }
}

void DebtManagement::readFileLoan()
{
    fstream f;
    f.open("loan.txt", ios::in);

    f >> loan_amount;
    for (int i = 0; i < loan_amount; i++)
    {
        long loan;
        f >> loan;
        string name;
        f.ignore();
        getline(f, name);
        string phone_number;
        getline(f, phone_number);
        int month, day, year;
        f >> month;
        f >> day;
        f >> year;
        float interest_rate;
        f >> interest_rate;

        User debtor(name, phone_number);
        Date repayment_date(month, day, year);
        loan_list[i].set(loan, debtor, repayment_date,interest_rate);

        f.close();
    }
}

void DebtManagement::editFile()
{
    showListOfDebts();
    cout << "\tWhat debt do you want to edit: ";
    int selection;
    cin >> selection;
    while (selection > debt_amount || selection <= 0 || debt_list[selection - 1].getDebtPayment())
    {
        cout << "Invalid number, please re-enter: ";
        cin >> selection;
    }

    Debt debt;
    debt = debt_list[selection - 1];

    debt.print();
    cout << "\tWhat part do you want to edit: ";
    int selection1;
    cin >> selection1;
    while (selection1 > 4 || selection1 <= 0)
    {
        cout << "Invalid number, please re-enter: ";
        cin >> selection1;
    }
    switch (selection1)
    {
    case 1:
        debt.insertAmountOwed();
        break;
    
    case 2:
        debt.insertUser();
        break;

    case 3:
        debt.insertRepaymentDate();
        break;
    
    case 4:
        debt.insertInterestRate();
        break;

    default:
        break;
    }

    debt_list[selection - 1] = debt;
}

void DebtManagement::editFileLoan()
{
    showListOfLoans();
    cout << "\tWhat loan do you want to edit: ";
    int selection;
    cin >> selection;
    while (selection > loan_amount || selection <= 0 || loan_list[selection - 1].getDebtPayment())
    {
        cout << "Invalid number, please re-enter: ";
        cin >> selection;
    }

    Debt loan;
    loan = loan_list[selection - 1];

    loan.printLoan();
    cout << "\tWhat part do you want to edit: ";
    int selection1;
    cin >> selection1;
    while (selection1 > 4 || selection1 <= 0)
    {
        cout << "Invalid number, please re-enter: ";
        cin >> selection1;
    }
    switch (selection1)
    {
    case 1:
        loan.insertAmountOwed();
        break;
    
    case 2:
        loan.insertUser();
        break;

    case 3:
        loan.insertRepaymentDate();
        break;
    
    case 4:
        loan.insertInterestRate();
        break;

    default:
        break;
    }

    loan_list[selection - 1] = loan;
}

void DebtManagement::payDebt()
{
    showListOfDebts();
    cout << "\tWhat debt do you want to pay: ";
    int selection;
    cin >> selection;
    while (selection > debt_amount || selection <= 0 || debt_list[selection].getDebtPayment())
    {
        cout << "Invalid number, please re-enter: ";
        cin >> selection;
    }

    debt_list[selection - 1].insertDebtPayment();
}

void DebtManagement::payLoan()
{
    showListOfLoans();
    cout << "\tWhat debt do you want to pay: ";
    int selection;
    cin >> selection;
    while (selection > loan_amount || selection <= 0 || loan_list[selection].getDebtPayment())
    {
        cout << "Invalid number, please re-enter: ";
        cin >> selection;
    }

    loan_list[selection - 1].insertDebtPayment();
}