/*

    Copyright (C) 2014, The University of Texas at Austin

    This file is part of libflame and is available under the 3-Clause
    BSD license, which can be found in the LICENSE file at the top-level
    directory, or at http://opensource.org/licenses/BSD-3-Clause

*/

#include "FLAME.h"

FLA_Error FLA_Chol_l( FLA_Obj A, fla_chol_t* cntl )
{
	FLA_Error r_val = FLA_SUCCESS;
	
	if      ( FLA_Cntl_variant( cntl ) == FLA_BLOCKED_EXTERN )
	{
		r_val = FLA_Chol_l_blk_ext( A );
	}
	else if ( FLA_Cntl_variant( cntl ) == FLA_UNBLOCKED_EXTERN )
	{
		r_val = FLA_Chol_l_unb_ext( A );
	}
#ifdef FLA_ENABLE_NON_CRITICAL_CODE
	else if ( FLA_Cntl_variant( cntl ) == FLA_UNB_OPT_VARIANT1 )
	{
		r_val = FLA_Chol_l_opt_var1( A );
	}
#endif
	else if ( FLA_Cntl_variant( cntl ) == FLA_UNB_OPT_VARIANT2 )
	{
#ifndef COMMENT_L1_L2
	 
		r_val = FLA_Chol_l_opt_var2( A );
#endif
	}
	else if ( FLA_Cntl_variant( cntl ) == FLA_UNB_OPT_VARIANT3 )
	{
		r_val = FLA_Chol_l_opt_var3( A );
	}
#ifdef FLA_ENABLE_NON_CRITICAL_CODE
	else if ( FLA_Cntl_variant( cntl ) == FLA_BLOCKED_VARIANT1 )
	{
		r_val = FLA_Chol_l_blk_var1( A, cntl );
	}
	else if ( FLA_Cntl_variant( cntl ) == FLA_BLOCKED_VARIANT2 )
	{
		r_val = FLA_Chol_l_blk_var2( A, cntl );
	}
#endif
	else if ( FLA_Cntl_variant( cntl ) == FLA_BLOCKED_VARIANT3 )
	{
		r_val = FLA_Chol_l_blk_var3( A, cntl );
	}
#ifdef FLA_ENABLE_NON_CRITICAL_CODE
	else if ( FLA_Cntl_variant( cntl ) == FLA_UNBLOCKED_VARIANT1 )
	{
		r_val = FLA_Chol_l_unb_var1( A );
	}
	else if ( FLA_Cntl_variant( cntl ) == FLA_UNBLOCKED_VARIANT2 )
	{
		r_val = FLA_Chol_l_unb_var2( A );
	}
	else if ( FLA_Cntl_variant( cntl ) == FLA_UNBLOCKED_VARIANT3 )
	{
		r_val = FLA_Chol_l_unb_var3( A );
	}
#endif
	else
	{
		FLA_Check_error_code( FLA_NOT_YET_IMPLEMENTED );
	}

	return r_val;
}

