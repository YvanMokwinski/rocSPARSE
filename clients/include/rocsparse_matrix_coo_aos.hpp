/*! \file */
/* ************************************************************************
 * Copyright (c) 2019-2021 Advanced Micro Devices, Inc.
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
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * ************************************************************************ */

#pragma once
#ifndef ROCSPARSE_MATRIX_COO_AOS_HPP
#define ROCSPARSE_MATRIX_COO_AOS_HPP

#include "rocsparse_vector.hpp"

template <memory_mode::value_t MODE, typename T, typename I = rocsparse_int>
struct coo_aos_matrix
{
    template <typename S>
    using array_t = typename memory_traits<MODE>::template array_t<S>;

    I                    m{};
    I                    n{};
    I                    nnz{};
    rocsparse_index_base base{};
    array_t<I>           ind{};
    array_t<T>           val{};

    coo_aos_matrix(){};
    ~coo_aos_matrix(){};

    coo_aos_matrix(I m_, I n_, I nnz_, rocsparse_index_base base_)
        : m(m_)
        , n(n_)
        , nnz(nnz_)
        , base(base_)
        , ind(2 * nnz_)
        , val(nnz_){};

    coo_aos_matrix(const coo_aos_matrix<MODE, T, I>& that_, bool transfer = true)
        : coo_aos_matrix<MODE, T, I>(that_.m, that_.n, that_.nnz, that_.base)
    {
        if(transfer)
        {
            this->transfer_from(that_);
        }
    }

    template <memory_mode::value_t THAT_MODE>
    coo_aos_matrix(const coo_aos_matrix<THAT_MODE, T, I>& that_, bool transfer = true)
        : coo_aos_matrix<MODE, T, I>(that_.m, that_.n, that_.nnz, that_.base)
    {
        if(transfer)
        {
            this->transfer_from(that_);
        }
    }

    template <memory_mode::value_t THAT_MODE>
    void transfer_from(const coo_aos_matrix<THAT_MODE, T, I>& that)
    {
        CHECK_HIP_ERROR((this->m == that.m && this->n == that.n && this->nnz == that.nnz
                         && this->base == that.base)
                            ? hipSuccess
                            : hipErrorInvalidValue);

        this->ind.transfer_from(that.ind);
        this->val.transfer_from(that.val);
    };

    void define(I m_, I n_, I nnz_, rocsparse_index_base base_)
    {
        if(m_ != this->m)
        {
            this->m = m_;
        }

        if(n_ != this->n)
        {
            this->n = n_;
        }

        if(nnz_ != this->nnz)
        {
            this->nnz = nnz_;
            this->ind.resize(2 * this->nnz);
            this->val.resize(this->nnz);
        }

        if(base_ != this->base)
        {
            this->base = base_;
        }
    }
};

template <typename T, typename I = rocsparse_int>
using host_coo_aos_matrix = coo_aos_matrix<memory_mode::host, T, I>;
template <typename T, typename I = rocsparse_int>
using device_coo_aos_matrix = coo_aos_matrix<memory_mode::device, T, I>;
template <typename T, typename I = rocsparse_int>
using managed_coo_aos_matrix = coo_aos_matrix<memory_mode::managed, T, I>;

#endif // ROCSPARSE_MATRIX_COO_AOS_HPP
