#include "model/invoiceList.hpp"

int main() {
    try {
        std::set<std::unique_ptr<Company>, CompanyPtrLessFunctor> companies;
        companies.emplace(std::make_unique<Company>(Company{"FIRMA X", "../data/invoices1.json"}));
        companies.emplace(std::make_unique<Company>(Company{"FIRMA Y", "../data/invoices2.json"}));
        companies.emplace(std::make_unique<Company>(Company{"FIRMA W", "../data/invoices3.json"}));
        companies.emplace(std::make_unique<Company>(Company{"FIRMA Z", "../data/invoices4.json"}));

        Payments payments{companies};
        payments.pay_invoices();
        std::cout << payments << std::endl;

        std::vector<std::string> file_names = { "invoices1.json", "invoices2.json", "invoices3.json", "invoices4.json" };
        InvoiceList invoice_list{file_names};
        auto unpaid_invoices = invoice_list.get_unpaid_invoces();
    }
    catch(std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}