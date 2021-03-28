//
// Created by Cezary Petryka on 25.03.2021.
//

#include "../invoice.hpp"

Invoice::Invoice(const int number, const double price, const std::string &payment_title, const bool payment_status)
        : number{number}, price{price}, payment_title{payment_title}, payment_status{payment_status} {}

std::vector<std::unique_ptr<Invoice>> Invoice::get_invoices_from_a_file(const std::string &file_name) {
    std::ifstream reading;
    reading.open(file_name);

    std::vector<std::unique_ptr<Invoice>> invoices;
    json j;

    if(reading.is_open()) {
        reading >> j;

        for(const auto& one_invoice : j) {
            invoices.emplace_back(std::make_unique<Invoice>(Invoice{
                    one_invoice["number"],
                    one_invoice["price"],
                    one_invoice["payment_title"],
                    (one_invoice["payment_status"] == "paid")
            }));
        }

        reading.close();
    }

    return invoices;
}

std::vector<std::unique_ptr<Invoice>>
Invoice::find_unpaid_invoices(const std::vector<std::unique_ptr<Invoice>> &invoices) {
    std::vector<std::unique_ptr<Invoice>> unpaid_invoices;

    for(const auto& one_invoce : invoices) {
        if(!one_invoce->payment_status) {
            unpaid_invoices.emplace_back(std::make_unique<Invoice>(*one_invoce));
        }
    }

    return unpaid_invoices;
}

void Invoice::pay_the_invoice() {
    payment_status = true;
}

std::ostream &operator<<(std::ostream &out, const Invoice &invoce) {
    return out << "Invocie no. " << invoce.number << " for " << invoce.price << " PLN is " << (invoce.payment_status ? "paid" : "unpaid") << " --> " << invoce.payment_title;
}