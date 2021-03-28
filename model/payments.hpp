//
// Created by Cezary Petryka on 26.03.2021.
//

#ifndef ZAD_2_PAYMENTS_HPP
#define ZAD_2_PAYMENTS_HPP

#include "../functors/companyPtrLessFunctor.hpp"

class Payments {
    std::set<std::unique_ptr<Company>, CompanyPtrLessFunctor> companies;
public:
    Payments(const std::set<std::unique_ptr<Company>, CompanyPtrLessFunctor>& c);

    void pay_invoices();

    Payments(const Payments& payments);
    Payments(Payments&& payments);

    Payments& operator=(const Payments& payments);
    Payments& operator=(Payments&& payments);

    friend std::ostream& operator<<(std::ostream& out, const Payments& payments);
};


#endif //ZAD_2_PAYMENTS_HPP
