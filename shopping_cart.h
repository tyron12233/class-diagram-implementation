#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

#include "order.h"
#include "product.h"

/**
 * Represents an order in the system.
 */
class ShoppingCart {
private:
    std::vector<std::pair<Product, int> > items;

public:
    /**
     * Add the given product to the cart with the given quantity.
     * @param product The product to add to the cart
     * @param quantity The quantity of the product to add to the cart
     */
    void addItem(const Product &product, int quantity) {
        items.push_back({product, quantity});
    }

    /**
     * Remove the given product from the cart.
     * @param product The product to remove from the cart
     */
    void removeItem(const Product &product) {
        items.erase(std::remove_if(items.begin(), items.end(),
                                   [&](const std::pair<Product, int> &item) { return item.first.id == product.id; }),
                    items.end());
    }

    void viewItems() const {
        for (const auto &item: items) {
            std::cout << "Product: " << item.first.name << ", Quantity: " << item.second << std::endl;
        }
    }

    bool isEmpty() const {
        return items.empty();
    }

    OrderImpl * checkout();
};

inline OrderImpl * ShoppingCart::checkout() {
    std::vector<Product> products;
    double totalAmount = 0;

    for (const auto& item : items) {
        products.push_back(item.first);
        totalAmount += item.first.price * item.second;
    }

    const std::string orderId = "ORD" + std::to_string(rand() % 1000);
    const Customer customer("CUST001", "John Doe", "john@example.com", "123 Main St");

    return new OrderImpl(orderId, customer, products, totalAmount);
}