#pragma once

using namespace std;

class Customer {
public:
    std::string id;
    std::string name;
    std::string email;
    std::string address;

    /**
     * Create a new Customer object with the given id, name, email, and address.
     */
    Customer(
        const std::string &id,
        const std::string &name,
        const std::string &email,
        const std::string &address
    ) : id(id), name(name), email(email), address(address) {
    }
};
