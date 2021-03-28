//
// Created by Cezary Petryka on 25.03.2021.
//

#ifndef ZAD_2_INVOICE_HPP
#define ZAD_2_INVOICE_HPP

#include "../libs/headers.hpp"

struct Invoice {
    int number;
    double price;
    std::string payment_title;
    bool payment_status = false;

    Invoice(const int number, const double price, const std::string& payment_title, const bool payment_status);

    static std::vector<std::unique_ptr<Invoice>> get_invoices_from_a_file(const std::string& file_name);
    static std::vector<std::unique_ptr<Invoice>> find_unpaid_invoices(const std::vector<std::unique_ptr<Invoice>>& invoices);

    void pay_the_invoice();

    friend std::ostream& operator<<(std::ostream& out, const Invoice& invoce);
};

#endif //ZAD_2_INVOICE_HPP
