#pragma once

#include <vector>
#include <algorithm>

#include "product.h"
#include "shopping_cart.h"

/**
 * The main class that represents the store.
 *
 * Handles storing the products and managing the inventory.
 */
class Store {
private:
    std::vector<Product> products;

public:
    Store() {
        products.push_back(Product("1", "Tesla Model S", "Electric car", 80000, 5));
        products.push_back(Product("2", "Nissan Leaf", "Electric car", 30000, 10));
        products.push_back(Product("3", "Chevy Bolt", "Electric car", 35000, 7));
        products.push_back(Product("4", "Tesla Model 3", "Electric car", 35000, 8));
        products.push_back(Product("5", "Ford Mustang Mach-E", "Electric car", 45000, 6));
    }

    /**
     * Check if the store contains a product with the given id.
     */
    bool containsProduct(const std::string &productId) {
        return std::any_of(products.begin(), products.end(),
                           [&](const Product &product) { return product.id == productId; });
    }

    Product getProductInfo(const std::string &productId) {
        const auto it = std::find_if(products.begin(), products.end(),
                                     [&](const Product &product) { return product.id == productId; });
        if (it == products.end()) {
            throw std::runtime_error("Product not found");
        }

        return *it;
    }

    /**
     * Find a product by its id.
     *
     * Throws an exception if the product is not found or the quantity is not available.
     */
    Product getProduct(const std::string &productId, int quantity) {
        const auto it = std::find_if(products.begin(), products.end(),
                                     [&](const Product &product) { return product.id == productId; });
        if (it == products.end()) {
            throw std::runtime_error("Product not found");
        }

        if (it->stock < quantity) {
            throw std::runtime_error("Product out of stock");
        }

        return *it;
    }

    vector<Product> getProducts() {
        return products;
    }
};