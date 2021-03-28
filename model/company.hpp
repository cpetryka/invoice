//
// Created by Cezary Petryka on 25.03.2021.
//

#ifndef ZAD_2_COMPANY_HPP
#define ZAD_2_COMPANY_HPP

#include "invoice.hpp"

class Company {
    std::string name;
    std::vector<std::unique_ptr<Invoice>> invoices_to_pay_for;

    int find_invoice_with_given_number(const int number) const;
    std::vector<int> convert_string_into_numbers_vector(const std::string& s);
public:
    Company(const std::string& name, const std::vector<std::unique_ptr<Invoice>>& invoices);
    Company(const std::string& name, const std::string& file_name);

    std::string get_name() const;
    void pay_invoices(const std::vector<int>& invoice_numbers);
    void pay_invoices_gui();
    void refresh();
    std::unique_ptr<Invoice> operator[](const int idx);

    Company(const Company& company);
    Company(Company&& company);

    Company& operator=(const Company& company);
    Company& operator=(Company&& company);

    std::string print() const;
    friend std::ostream& operator<<(std::ostream& out, const Company& company);
};

#endif //ZAD_2_COMPANY_HPP
