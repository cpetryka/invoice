//
// Created by Cezary Petryka on 28.03.2021.
//

#include "../invoiceList.hpp"

InvoiceList::InvoiceList(const std::vector<std::string> &file_names) {
    for(const auto& one_file_name : file_names) {
        auto temp = Invoice::get_invoices_from_a_file(one_file_name);

        for(auto i = 0; i < temp.size(); ++i) {
            invoice_list.emplace_back(std::make_unique<Invoice>(*temp[i]));
        }
    }
}

void InvoiceList::update_invoice_list(const Payments &payments) {

}

std::vector<std::unique_ptr<Invoice>> InvoiceList::get_unpaid_invoces() const {
    std::vector<std::unique_ptr<Invoice>> unpaid_invoices;

    // I couldn't use instructions such as std::remove_copy_if etc. due to the fact that
    // I use std::unique_ptr in my vector
    for(const auto& one_invoice : invoice_list) {
        if(!one_invoice->payment_status) {
            unpaid_invoices.emplace_back(std::make_unique<Invoice>(*one_invoice));
        }
    }

    return unpaid_invoices;
}
