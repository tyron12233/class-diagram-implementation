#pragma once
#include <iomanip>
#include <limits>

#include "utils.h"


/**
 * The UI class for the store.
 *
 * Handles the user interface for the store.
 */
class StoreUi {
private:
    Store store;
    ShoppingCart cart;

public:
    StoreUi(const Store &store) : store(store) {
    }

    void displayProducts() {
        clearScreen();
        std::cout << "Products: \n\n";
        std::cout << std::setw(10) << "Product ID "
                << std::setw(30) << "Name"
                << std::setw(10) << "Price"
                << std::setw(10) << "Quantity" << std::endl;

        for (const auto &product: store.getProducts()) {
            std::cout << std::setw(10) << product.id
                    << std::setw(30) << product.name
                    << std::setw(10) << product.price
                    << std::setw(10) << product.stock << std::endl;
        }
    }


    void viewShoppingCart() {
        if (cart.isEmpty()) {
            std::cout << "Shopping cart is empty!\n";
            return;
        }
        cart.viewItems();
        char choice;
        std::cout << "Do you want to check out all the products? (Y/N): ";
        std::cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            checkOut();
        }
    }

    void addProductToCart() {


        std::string productId;
        while (true) {
            displayProducts();

            std::cout << endl;
            std::cout << "Enter the product ID you want to buy (-1 to go back): ";
            std::cin >> productId;

            if (productId == "-1") {
                break;
            }

            if (store.containsProduct(productId)) {
                Product info = store.getProductInfo(productId);
                std::cout << "You selected: " << info.name << endl;

                // ask for quantity
                int quantity;
                std::cout << "Enter the quantity: ";
                std::cin >> quantity;

                // validate quantity
                try {
                    Product product = store.getProduct(productId, quantity);
                    cart.addItem(product, quantity);
                } catch (const std::runtime_error &e) {
                    std::cout << "\n";
                    std::cout << e.what() << "\n\n";
                    // try again
                    pauseScreen();
                    clearScreen();
                    continue;
                }
                std::cout << "Product added to the shopping cart!\n\n";
            } else {
                std::cout << "Product not found!\n\n";

                pauseScreen();
                clearScreen();
                // try again
                continue;
            }

            char choice;
            std::cout << "Do you want to add another product to the shopping cart? (Y/N): ";
            std::cin >> choice;

            if (choice == 'N' || choice == 'n') {
                break;
            }
        }
    }

    void checkOut() {
        clearScreen();
        if (cart.isEmpty()) {
            std::cout << "Shopping cart is empty!\n";
            return;
        }

        const auto order = cart.checkout();

        // display receipt
        std::cout << std::endl;
        std::cout << "Order Details: " << std::endl;
        std::cout << "Order ID: " << order->orderId << std::endl;
        std::cout << "Customer: " << order->customer.name << std::endl;
        std::cout << "Total Amount: " << order->totalAmount << std::endl << std::endl;

        // display products
        std::cout << std::setw(10) << "Product ID "
                << std::setw(30) << "Name"
                << std::setw(10) << "Price"
                << std::setw(10) << "Quantity" << std::endl;
        for (const auto &product: order->products) {
            std::cout << std::setw(10) << product.id
                    << std::setw(30) << product.name
                    << std::setw(10) << product.price
                    << std::setw(10) << product.stock << std::endl;
        }

        delete order;
    }

    void menu() {
        while (true) {
            clearScreen();

            std::cout << "\n--- Store Menu ---\n";
            std::cout << "1. View Products\n";
            std::cout << "2. View Shopping Cart\n";
            std::cout << "3. Check out\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";
            int choice;
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input! Please try again.\n";
                pauseScreen();
            }

            switch (choice) {
                case 1:
                    clearScreen();
                    addProductToCart();
                    break;
                case 2:
                    clearScreen();
                    viewShoppingCart();
                    pauseScreen();
                    break;
                case 3:
                    checkOut();
                    pauseScreen();
                    break;
                case 4:
                    std::cout << "Exiting...\n";
                    return;
                default:
                    std::cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};
