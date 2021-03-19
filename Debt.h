#ifndef _DEBT_
#define _DEBT_

#include <iostream>
#include <string>
#include "User.h"
#include "Date.h"

using namespace std;

class Debt
{
    private:
        long amount_owed;
        User creditor;
        Date repayment_date;
        float interest_rate;
        bool debt_payment = false;

    public:
        Debt() {};

        void insertInfomation();
        void print();
        void insertAmountOwed();
        void insertUser();
        void insertRepaymentDate();
        void insertInterestRate();
        void insertDebtPayment();

        long getAmountOwed()
        {
            return amount_owed;
        }
        User getUser()
        {
            return creditor;
        }
        Date getDate()
        {
            return repayment_date;
        }
        float getInterestRate()
        {
            return interest_rate;
        }
        bool getDebtPayment()
        {
            return debt_payment;
        }
        void set(long _amount_owed, User _creditor, Date _repayment_date, float _interest_rate)
        {
            amount_owed = _amount_owed;
            creditor = _creditor;
            repayment_date = _repayment_date;
            interest_rate = _interest_rate;
        }
};

#endif