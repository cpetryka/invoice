//
// Created by Cezary Petryka on 28.03.2021.
//

#ifndef ZAD_2_INVOICELIST_HPP
#define ZAD_2_INVOICELIST_HPP

#include "payments.hpp"
#include "../functors/invoicePtrLessFunctor.hpp"

class InvoiceList {
    std::vector<std::unique_ptr<Invoice>> invoice_list;
public:
    InvoiceList(const std::vector<std::string>& file_names);

    void update_invoice_list(const Payments& payments);
    std::vector<std::unique_ptr<Invoice>> get_unpaid_invoces() const;
};


#endif //ZAD_2_INVOICELIST_HPP
