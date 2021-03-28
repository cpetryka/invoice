//
// Created by Cezary Petryka on 28.03.2021.
//

#ifndef ZAD_2_INVOICEPTRLESSFUNCTOR_HPP
#define ZAD_2_INVOICEPTRLESSFUNCTOR_HPP

#include "../model/invoice.hpp"

struct InvoicePtrLessFunctor {
    bool operator()(const std::unique_ptr<Invoice>& invoice1, const std::unique_ptr<Invoice>& invoice2) {
        if(invoice1->number == invoice2->number) {
            if(invoice1->price == invoice2->price) {
                if(invoice1->payment_title == invoice2->payment_title) {
                    return invoice1->payment_status < invoice2->payment_status;
                }
                return invoice1->payment_title < invoice2->payment_title;
            }
            return invoice1->price < invoice2->price;
        }
        return invoice1->number < invoice2->number;
    }
};

#endif //ZAD_2_INVOICEPTRLESSFUNCTOR_HPP
