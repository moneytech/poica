/*
 * MIT License
 *
 *
 * Copyright (c) 2020 Temirkhan Myrzamadi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef POICA_SUM_GEN_VARIANT_MANY
#define POICA_SUM_GEN_VARIANT_MANY

#include <poica/private/aux.h>
#include <poica/private/defer.h>

#include <poica/product.h>
#include <poica/sum/gen/redirects/to_inner_type.h>
#include <poica/sum/introspection.h>

#include <boost/preprocessor.hpp>

#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCTS(variants)                        \
    POICA_P_EXPAND(BOOST_PP_SEQ_FOR_EACH(                                      \
        POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT, _data, variants))

#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT(_r, data, variant)                \
    OVERLOAD_ON_VARIANT(POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT_, _data, variant)

#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT_VARIANT_EMPTY(_data, _variant_name)
#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT_VARIANT_SINGLE(                   \
    _data, _variant_name, _variant_type)
#define POICA_P_SUM_GEN_VARIANT_MANY_PRODUCT_VARIANT_MANY(                     \
    _data, variant_name, fields)                                               \
    POICA_P_DEFER(PRODUCT)                                                     \
    (POICA_P_SUM_REDIRECT_VARIANT_TO_INNER_TYPE(variant_name), fields);

#endif // POICA_SUM_GEN_VARIANT_MANY
