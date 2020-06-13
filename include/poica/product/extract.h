#ifndef POICA_PRODUCT_EXTRACT_H
#define POICA_PRODUCT_EXTRACT_H

#include <poica/keywords.h>
#include <poica/product/gen/redirects/to_field_type.h>

#include <stdbool.h>

#include <boost/preprocessor.hpp>

#define EXTRACT(...) POICA_P_EXTRACT_AUX(__VA_ARGS__)
#define POICA_P_EXTRACT_AUX(fields, val)                                       \
    BOOST_PP_SEQ_FOR_EACH(                                                     \
        POICA_P_EXTRACT_GEN_ASSIGN, val, BOOST_PP_TUPLE_TO_SEQ(fields))        \
                                                                               \
    do {                                                                       \
    } while (false)

#define POICA_P_EXTRACT_GEN_ASSIGN(_r, val, field_name)                        \
    POICA_P_PRODUCT_REDIRECT_TO_FIELD_TYPE(BOOST_PP_TUPLE_ELEM(2, 1, val),     \
                                           field_name) *field_name =           \
        &BOOST_PP_TUPLE_ELEM(2, 0, val)->field_name;

#endif // POICA_PRODUCT_EXTRACT_H