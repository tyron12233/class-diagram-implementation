cmake_minimum_required(VERSION 3.28)
project(class_diagram_implementation)

set(CMAKE_CXX_STANDARD 17)

add_executable(class_diagram_implementation main.cpp
        product.h
        customer.h
        shopping_cart.h
        order.h
        payment.h
        store.h
        store_ui.h)
