#pragma once
#include <iostream>
#include <vector>

#include "product.h"
#include "customer.h"

/**
* Lays out the structure of an order.
 */
class Order {
public:
    virtual std::string getOrderDetails() const = 0;

    virtual ~Order() = default;
};


/**
 * The implementation of the Order interface.
 *
 * This class is responsible for storing the order details and providing a way to get the order details as a string.
 */
class OrderImpl final : public Order {
public:
    std::string orderId;
    Customer customer;
    std::vector<Product> products;
    double totalAmount;

    OrderImpl(
        const std::string &orderId,
        const Customer &customer,
        const std::vector<Product> &products,
        double totalAmount
    ) : orderId(orderId), customer(customer), products(products), totalAmount(totalAmount) {
    }

    std::string getOrderDetails() const override {
        std::string details = "Order ID: " + orderId + "\nCustomer: " + customer.name + "\nProducts:\n";
        for (const auto &product: products) {
            details += "- " + product.name + "\n";
        }
        details += "Total Amount: " + std::to_string(totalAmount);
        return details;
    }
};
