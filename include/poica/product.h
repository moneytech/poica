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

#ifndef POICA_PRODUCT_H
#define POICA_PRODUCT_H

#include <poica/private/aux.h>

#include <poica/keywords.h>
#include <poica/product/field.h>

#include <poica/product/extract.h>
#include <poica/product/field.h>
#include <poica/product/gen/fields.h>
#include <poica/product/gen/redirects.h>
#include <poica/product/introspection.h>

#include <boost/preprocessor.hpp>

#define PRODUCT(...) POICA_P_PRODUCT_AUX(__VA_ARGS__)

#define POICA_P_PRODUCT_AUX(name, fields)                                      \
    typedef struct name {                                                      \
        POICA_P_PRODUCT_GEN_FIELDS(fields)                                     \
    } name;                                                                    \
                                                                               \
    POICA_P_PRODUCT_GEN_REDIRECTS_TO_FIELD_TYPE(name, fields)                  \
                                                                               \
    POICA_P_USELESS_TYPEDEF(name)

#endif // POICA_PRODUCT_H
