//
// Created by Cezary Petryka on 26.03.2021.
//

#ifndef ZAD_2_COMPANYPTRLESSFUNCTOR_HPP
#define ZAD_2_COMPANYPTRLESSFUNCTOR_HPP

#include "../model/company.hpp"

struct CompanyPtrLessFunctor {
    bool operator()(const std::unique_ptr<Company>& company1, const std::unique_ptr<Company>& company2) const {
        return company1->get_name() < company2->get_name();
    }
};

#endif //ZAD_2_COMPANYPTRLESSFUNCTOR_HPP
