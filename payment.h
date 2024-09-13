#pragma once
#include <iostream>



/**
 * The Payment interface represents a payment method that can be used to pay for an order.
 * Implementations of this interface should provide a way to pay a given amount.
 */
class Payment {
public:
    virtual bool pay(double amount) = 0;

    virtual ~Payment() = default;
};

// Payment IMPLEMENTATIONS

class GCash : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "Paid " << amount << " using GCASH\n";
        return true;
    }
};

class PayMaya : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "Paid " << amount << " using PAYMAYA\n";
        return true;
    }
};

class CreditCard : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "Paid " << amount << " using Credit Card\n";
        return true;
    }
};


class CashOnDelivery : public Payment {
public:
    bool pay(double amount) override {
        std::cout << "Cash on delivery for amount: " << amount << "\n";
        return true;
    }
};