//
// Created by Cezary Petryka on 26.03.2021.
//

#include "../payments.hpp"

Payments::Payments(const std::set<std::unique_ptr<Company>, CompanyPtrLessFunctor> &c) {
    for(const auto& one_copmany : c) {
        companies.emplace(std::make_unique<Company>(*one_copmany));
    }
}

void Payments::pay_invoices() {
    std::for_each(companies.begin(), companies.end(), [](const auto& one_company) {
        one_company->pay_invoices_gui();
    });
}

Payments::Payments(const Payments &payments) {
    for(const auto& one_company : payments.companies) {
        companies.emplace(std::make_unique<Company>(*one_company));
    }
}

Payments::Payments(Payments &&payments) {
    for(auto& one_company : payments.companies) {
        companies.emplace(std::make_unique<Company>(*one_company));
        // one_company = nullptr;
    }
    payments.companies.clear();
}

Payments &Payments::operator=(const Payments &payments) {
    if(&payments == this) {
        return *this;
    }

    for(const auto& one_company : payments.companies) {
        companies.emplace(std::make_unique<Company>(*one_company));
    }

    return *this;
}

Payments &Payments::operator=(Payments &&payments) {
    if(&payments == this) {
        return *this;
    }

    for(auto& one_company : payments.companies) {
        companies.emplace(std::make_unique<Company>(*one_company));
        // one_company = nullptr;
    }
    payments.companies.clear();

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Payments &payments) {
    std::for_each(payments.companies.begin(), payments.companies.end(), [&out](const auto& one_company) {
        out << *one_company;
    });

    return out;
}
