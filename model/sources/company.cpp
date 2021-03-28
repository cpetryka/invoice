//
// Created by Cezary Petryka on 26.03.2021.
//

#include "../company.hpp"

int Company::find_invoice_with_given_number(const int number) const {
    auto it = std::find_if(invoices_to_pay_for.begin(), invoices_to_pay_for.end(), [&number](const auto& one_invoice) {
        return one_invoice->number == number;
    });

    if(it == invoices_to_pay_for.end()) {
        throw std::runtime_error("There is no invoice with number " + std::to_string(number));
    }

    return std::distance(invoices_to_pay_for.begin(), it);
}

std::vector<int> Company::convert_string_into_numbers_vector(const std::string &s) {
    std::stringstream ss(s);
    std::string one_string;
    std::vector<int> numbers;

    while(getline(ss, one_string, ',')) {
        numbers.emplace_back(std::stoi(one_string));
    }

    return numbers;
}

Company::Company(const std::string &name, const std::vector<std::unique_ptr<Invoice>> &invoices)
        : name{name}, invoices_to_pay_for{Invoice::find_unpaid_invoices(invoices)} {}

Company::Company(const std::string &name, const std::string &file_name)
        : name{name}, invoices_to_pay_for(Invoice::find_unpaid_invoices(Invoice::get_invoices_from_a_file(file_name))) {}

Company::Company(const Company &company) : name{company.name} {
    for(const auto& one_invoice : company.invoices_to_pay_for) {
        invoices_to_pay_for.emplace_back(std::make_unique<Invoice>(*one_invoice));
    }
}

std::string Company::get_name() const {
    return name;
}

void Company::pay_invoices(const std::vector<int>& invoice_numbers) {
    for(const auto& one_invoice_number : invoice_numbers) {
        auto idx = find_invoice_with_given_number(one_invoice_number);
        invoices_to_pay_for[idx]->pay_the_invoice();
    }
}

void Company::pay_invoices_gui() {
    std::cout << print() << std::endl;
    std::cout << "Which invoices would you like to pay? " << std::endl;
    std::string s;
    std::getline(std::cin, s);
    pay_invoices( convert_string_into_numbers_vector(s) );
    refresh();
}

void Company::refresh() {
    auto it = std::remove_if(invoices_to_pay_for.begin(), invoices_to_pay_for.end(), [](const auto& one_invoice) {
       return one_invoice->payment_status;
    });

    invoices_to_pay_for.resize(std::distance(invoices_to_pay_for.begin(), it));
}

std::unique_ptr<Invoice> Company::operator[](const int idx) {
    if(idx < 0 || idx > invoices_to_pay_for.size() - 1) {
        throw std::range_error("Idx is out of range");
    }

    return std::make_unique<Invoice>(*invoices_to_pay_for[idx]);
}

Company::Company(Company &&company) : name{company.name} {
    for(auto& one_invoice : company.invoices_to_pay_for) {
        invoices_to_pay_for.emplace_back(std::make_unique<Invoice>(*one_invoice));
        one_invoice = nullptr;
    }
    company.invoices_to_pay_for.clear();
}

Company &Company::operator=(const Company &company) {
    if(this == &company) {
        return *this;
    }

    name = company.name;

    for(const auto& one_invoice : company.invoices_to_pay_for) {
        invoices_to_pay_for.emplace_back(std::make_unique<Invoice>(*one_invoice));
    }

    return *this;
}

Company &Company::operator=(Company &&company) {
    if(this == &company) {
        return *this;
    }

    name = company.name;

    for(auto& one_invoice : company.invoices_to_pay_for) {
        invoices_to_pay_for.emplace_back(std::make_unique<Invoice>(*one_invoice));
        one_invoice = nullptr;
    }
    company.invoices_to_pay_for.clear();

    return *this;
}

std::string Company::print() const {
    std::stringstream out;

    out << "=============== " << name << " ===============" << std::endl;
    std::for_each(invoices_to_pay_for.begin(), invoices_to_pay_for.end(), [&out](const auto& one_invoice) {
        out << *one_invoice << std::endl;
    });

    return out.str();
}

std::ostream &operator<<(std::ostream &out, const Company &company) {
    return out << company.print();
}