%
%
%   Copyright (C) 2014, The University of Texas at Austin
%
%   This file is part of libflame and is available under the 3-Clause
%   BSD license, which can be found in the LICENSE file at the top-level
%   directory, or at http://opensource.org/licenses/BSD-3-Clause
%
%
                                         1, 'FLA_RIGHT' );

    [ T00,  t01,   T02,  ...
      t10t, tau11, t12t, ...
      T20,  t21,   T22 ] = FLA_Repart_2x2_to_3x3( TTL, TTR, ...
                                                  TBL, TBR, ...
                                                  1, 1, 'FLA_BR' );

    %------------------------------------------------------------%

    [ upsilon11, ...
      d1, tau11 ] = FLA_Househ2_UT( upsilon11, ...
                                    d1 );
    t01 = D0' * d1;
    
    [ u12t, ...
      D2 ] = FLA_Apply_H_UT( tau11, d1, u12t, ...
                                        D2 );

    %------------------------------------------------------------%

    [ UTL, UTR, ...
      UBL, UBR ] = FLA_Cont_with_3x3_to_2x2( U00,  u01,       U02,  ...
                                             u10t, upsilon11, u12t, ...
                                             U20,  u21,       U22, ...
                                             'FLA_TL' );

    [ DL, DR ] = FLA_Cont_with_1x3_to_1x2( D0, d1, D2, ...
                                           'FLA_LEFT' );

    [ TTL, TTR, ...
      TBL, TBR ] = FLA_Cont_with_3x3_to_2x2( T00,  t01,   T02,  ...
                                             t10t, tau11, t12t, ...
                                             T20,  t21,   T22, ...
                                             'FLA_TL' );
  end

  U_out = [ UTL, UTR
            UBL, UBR ];

  D_out = [ DL, DR ];

  T_out = [ TTL, TTR
            TBL, TBR ];
  
return