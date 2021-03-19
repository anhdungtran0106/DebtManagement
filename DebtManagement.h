#ifndef _DEBT_MANAGEMENT_
#define _DEBT_MANAGEMENT_

#include <iostream>
#include <string>
#include "Debt.h"

using namespace std;

class DebtManagement
{
private:
    Debt debt_list[100];
    int debt_amount = 0;

public:
    DebtManagement() {};

    void printMenu();
    void debtManagement();
    void addDebt();
    void showListOfDebts();
    void deleteDebt();
    void readFile();
    void saveFile();
    void editFile();
    void payDebt();
};

#endif