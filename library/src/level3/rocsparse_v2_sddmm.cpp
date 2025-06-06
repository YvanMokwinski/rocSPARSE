/* ************************************************************************
 * Copyright (C) 2025 Advanced Micro Devices, Inc. All rights Reserved.
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

#include "rocsparse_v2_sddmm.hpp"

~_rocsparse_sddmm_descr::_rocsparse_sddmm_descr()
{
}

_rocsparse_sddmm_descr::_rocsparse_sddmm_descr()
  : m_stage((rocsparse_sddmm_stage)-1)
  , m_alg((rocsparse_spmv_alg)-1)
  , m_operation((rocsparse_operation)-1)
  , m_scalar_datatype((rocsparse_datatype)-1)
  , m_compute_datatype((rocsparse_datatype)-1)
{
}
  
void * _rocsparse_sddmm_descr::get_local_host_alpha()
{
  return &this->m_local_host_alpha_value[0];
}

void * _rocsparse_sddmm_descr::get_local_host_beta()
{
  return &this->m_local_host_beta_value[0];
}
  
rocsparse_sddmm_stage _rocsparse_sddmm_descr::get_stage() const
{
  return this->m_stage;
}
  
rocsparse_spmv_alg _rocsparse_sddmm_descr::get_alg() const
{
  return this->m_alg;
}
  
rocsparse_operation _rocsparse_sddmm_descr::get_operation_A() const
{
  return this->m_operation_A;
}
  
rocsparse_operation _rocsparse_sddmm_descr::get_operation_B() const
{
  return this->m_operation_B;
}
  
rocsparse_datatype _rocsparse_sddmm_descr::get_scalar_datatype() const
{
  return this->m_scalar_datatype;
}
  
rocsparse_datatype _rocsparse_sddmm_descr::get_compute_datatype() const
{
  return this->m_compute_datatype;
}
  
void _rocsparse_sddmm_descr::set_stage(rocsparse_sddmm_stage value)
{
  this->m_stage = value;
}
  
void _rocsparse_sddmm_descr::set_alg(rocsparse_sddmm_alg value)
{
  this->m_alg = value;
}
  
void _rocsparse_sddmm_descr::set_operation_A(rocsparse_operation value)
{
  this->m_operation_A = value;
}
  
void _rocsparse_sddmm_descr::set_operation_B(rocsparse_operation value)
{
  this->m_operation_B = value;
}
  
void _rocsparse_sddmm_descr::set_scalar_datatype(rocsparse_datatype value)
{
  this->m_scalar_datatype = value;
}
  
void _rocsparse_sddmm_descr::set_compute_datatype(rocsparse_datatype value)
{
  this->m_compute_datatype = value;
}  
