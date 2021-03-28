cmake_minimum_required(VERSION 3.17)
project(ZAD_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(ZAD_2 main.cpp libs/headers.hpp model/invoice.hpp model/company.hpp libs/json.hpp model/sources/invoice.cpp model/sources/payments.cpp model/payments.hpp model/sources/company.cpp functors/companyPtrLessFunctor.hpp model/sources/invoiceList.cpp model/invoiceList.hpp functors/invoicePtrLessFunctor.hpp)