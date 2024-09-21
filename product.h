#pragma once
#include <string>

class Product {
public:
    std::string id;
    std::string name;
    std::string description;
    double price;
    int stock;

    Product(
        const std::string &id,
        const std::string &name,
        const std::string &description,
        const double price,
        const int stock
    ) : id(id), name(name), description(description), price(price), stock(stock) {
    }
};
