/*

    Copyright (C) 2014, The University of Texas at Austin

    This file is part of libflame and is available under the 3-Clause
    BSD license, which can be found in the LICENSE file at the top-level
    directory, or at http://opensource.org/licenses/BSD-3-Clause

*/

#include "FLAME.h"

extern fla_chol_t* fla_chol_cntl;
extern fla_chol_t* fla_chol_cntl2;

#ifdef FLA_AMD_OPT
extern fla_chol_t* fla_chol_cntl_amd;
#endif

FLA_Error FLA_Chol( FLA_Uplo uplo, FLA_Obj A )
{
  FLA_Error r_val;

  // Check parameters.
  if ( FLA_Check_error_level() >= FLA_MIN_ERROR_CHECKING )
    FLA_Chol_check( uplo, A );

#ifdef FLA_AMD_OPT
  // Invoke FLA_Chol_internal() with the appropriate amd control tree.
  if (uplo == FLA_LOWER_TRIANGULAR)
    r_val = FLA_Chol_internal( uplo, A, fla_chol_cntl_amd );
  else
    r_val = FLA_Chol_internal (uplo, A, fla_chol_cntl2);
 
#else
  // Invoke FLA_Chol_internal() with the appropriate control tree.
  r_val = FLA_Chol_internal( uplo, A, fla_chol_cntl2 );
  //r_val = FLA_Chol_internal( uplo, A, fla_chol_cntl );
#endif
  return r_val;
}

