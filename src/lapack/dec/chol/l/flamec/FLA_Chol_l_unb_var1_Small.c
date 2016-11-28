/*

    Copyright (C) 2014, The University of Texas at Austin
    Copyright (C) 2016 Advanced Micro Devices, Inc.

    This file is part of libflame and is available under the 3-Clause
    BSD license, which can be found in the LICENSE file at the top-level
    directory, or at http://opensource.org/licenses/BSD-3-Clause

*/

#include "FLAME.h"

FLA_Error FLA_Chol_l_unb_var1_Small (FLA_Obj A)
{
	FLA_Error    r_val = FLA_SUCCESS;
	FLA_Datatype datatype;
    int          mn_A;
	int          rs_A, cs_A;

	datatype = FLA_Obj_datatype( A );

	mn_A     = FLA_Obj_length( A );
	rs_A     = FLA_Obj_row_stride( A );
	cs_A     = FLA_Obj_col_stride( A );

	switch(datatype)
	{
		case FLA_FLOAT:
		{
			float* buff_A = FLA_FLOAT_PTR( A );
			r_val = FLA_Chol_l_unb_var1_Small_ops ( mn_A, buff_A, rs_A, cs_A);
			break;
		}
		case FLA_DOUBLE:
		{
			double* buff_A = FLA_DOUBLE_PTR( A );
			r_val = FLA_Chol_l_unb_var1_Small_opd (mn_A, buff_A, rs_A, cs_A);
			break;
		}
	}
	return r_val;
}// End of function

#if 0 // for chol_r
FLA_Error FLA_Chol_l_unb_var1_Small_ops( int mn_A,
                                         float* A,
                                         int rs_A,
                                         int cs_A )
{
	FLA_Error    r_val = FLA_SUCCESS;
	int i;
	int k;
	int j;
	float aii = 0.0;
	float aij     = 0.0;

	for (i = 0; i < mn_A; i++)
	{
		aii = A[(i * rs_A) + (i * cs_A)];
		for (k = 0; k < i; k++)
		{
			aii -= A[k*rs_A + i * cs_A] * A[k*rs_A + i * cs_A];
		}
	//	if (aii <= 0 ) { r_val = FLA_FAILURE; break;} // A is not +ve definite
		bl1_ssqrte( aii, &e_val );
		if ( e_val != FLA_SUCCESS ) return mn_A;

		for (j = i+1; j < mn_A; j++)
		{
			aij = A[i*rs_A + j*cs_A];
			for (k = 0; k < (i-1); k++)
			{
				aij -= A[k*rs_A + i * cs_A] * A[k * rs_A + j * cs_A];
			}
			A[i * rs_A + j*cs_A] = aij/aii ;
		}
	}

	return r_val;
}
#endif

FLA_Error FLA_Chol_l_unb_var1_Small_ops( int mn_A,
                                         float* A,
                                         int rs_A,
                                         int cs_A )
{
	FLA_Error    r_val = FLA_SUCCESS;
	int i;
	int k;
	int j;
	float aii     = 0.0;
	float aji     = 0.0;

	for (i = 0; i < mn_A; i++)
	{
		aii = A[(i * rs_A) + (i * cs_A)];
		for (k = 0; k < i; k++)
		{
			aii -= A[k*cs_A + i * rs_A] * A[k*cs_A + i * rs_A];
		}
	//	if (aii <= 0 ) { r_val = FLA_FAILURE; break;} // A is not +ve definite
		bl1_ssqrte( aii, &e_val );
		if ( e_val != FLA_SUCCESS ) return mn_A;

		for (j = i+1; j < mn_A; j++)
		{
			aji = A[i*cs_A + j*rs_A];
			for (k = 0; k < i; k++)
			{
				aji -= A[k*cs_A + i * rs_A] * A[k * cs_A + j * rs_A];
			}
			A[i * cs_A + j*rs_A] = aji/aii ;
		}
	}
	return r_val;
}

FLA_Error FLA_Chol_l_unb_var1_Small_opd( int mn_A,
                                         double* A,
                                         int rs_A,
                                         int cs_A )
{
	FLA_Error    r_val = FLA_SUCCESS;
	int i;
	int k;
	int j;
	double aii     = 0.0;
	double aji     = 0.0;

	for (i = 0; i < mn_A; i++)
	{
		aii = A[(i * rs_A) + (i * cs_A)];
		for (k = 0; k < i; k++)
		{
			aii -= A[k*cs_A + i * rs_A] * A[k*cs_A + i * rs_A];
		}
	//	if (aii <= 0 ) { r_val = FLA_FAILURE; break;} // A is not +ve definite
		bl1_dsqrte( aii, &e_val );
		if ( e_val != FLA_SUCCESS ) return mn_A;

		for (j = i+1; j < mn_A; j++)
		{
			aji = A[i*cs_A + j*rs_A];
			for (k = 0; k < i; k++)
			{
				aji -= A[k*cs_A + i * rs_A] * A[k * cs_A + j * rs_A];
			}
			A[i * cs_A + j*rs_A] = aji/aii ;
		}
	}
	return r_val;
}// End of function
