/* ../netlib/clatzm.f -- translated by f2c (version 20100827). You must link the resulting object file with libf2c: on Microsoft Windows system, link with libf2c.lib;
 on Linux or Unix systems, link with .../path/to/libf2c.a -lm or, if you install libf2c.a in a standard place, with -lf2c -lm -- in that order, at the end of the command line, as in cc *.o -lf2c -lm Source for libf2c is in /netlib/f2c/libf2c.zip, e.g., http://www.netlib.org/f2c/libf2c.zip */
#include "FLA_f2c.h" /* Table of constant values */
static complex c_b1 =
{
    1.f,0.f
}
;
static integer c__1 = 1;
/* > \brief \b CLATZM */
/* =========== DOCUMENTATION =========== */
/* Online html documentation available at */
/* http://www.netlib.org/lapack/explore-html/ */
/* > \htmlonly */
/* > Download CLATZM + dependencies */
/* > <a href="http://www.netlib.org/cgi-bin/netlibfiles.tgz?format=tgz&filename=/lapack/lapack_routine/clatzm. f"> */
/* > [TGZ]</a> */
/* > <a href="http://www.netlib.org/cgi-bin/netlibfiles.zip?format=zip&filename=/lapack/lapack_routine/clatzm. f"> */
/* > [ZIP]</a> */
/* > <a href="http://www.netlib.org/cgi-bin/netlibfiles.txt?format=txt&filename=/lapack/lapack_routine/clatzm. f"> */
/* > [TXT]</a> */
/* > \endhtmlonly */
/* Definition: */
/* =========== */
/* SUBROUTINE CLATZM( SIDE, M, N, V, INCV, TAU, C1, C2, LDC, WORK ) */
/* .. Scalar Arguments .. */
/* CHARACTER SIDE */
/* INTEGER INCV, LDC, M, N */
/* COMPLEX TAU */
/* .. */
/* .. Array Arguments .. */
/* COMPLEX C1( LDC, * ), C2( LDC, * ), V( * ), WORK( * ) */
/* .. */
/* > \par Purpose: */
/* ============= */
/* > */
/* > \verbatim */
/* > */
/* > This routine is deprecated and has been replaced by routine CUNMRZ. */
/* > */
/* > CLATZM applies a Householder matrix generated by CTZRQF to a matrix. */
/* > */
/* > Let P = I - tau*u*u**H; u = ( 1 ); */
/* > ( v ) */
/* > where v is an (m-1) vector if SIDE = 'L', or a (n-1) vector if */
/* > SIDE = 'R'. */
/* > */
/* > If SIDE equals 'L', let */
/* > C = [ C1 ] 1 */
/* > [ C2 ] m-1 */
/* > n */
/* > Then C is overwritten by P*C. */
/* > */
/* > If SIDE equals 'R', let */
/* > C = [ C1, C2 ] m */
/* > 1 n-1 */
/* > Then C is overwritten by C*P. */
/* > \endverbatim */
/* Arguments: */
/* ========== */
/* > \param[in] SIDE */
/* > \verbatim */
/* > SIDE is CHARACTER*1 */
/* > = 'L': form P * C */
/* > = 'R': form C * P */
/* > \endverbatim */
/* > */
/* > \param[in] M */
/* > \verbatim */
/* > M is INTEGER */
/* > The number of rows of the matrix C. */
/* > \endverbatim */
/* > */
/* > \param[in] N */
/* > \verbatim */
/* > N is INTEGER */
/* > The number of columns of the matrix C. */
/* > \endverbatim */
/* > */
/* > \param[in] V */
/* > \verbatim */
/* > V is COMPLEX array, dimension */
/* > (1 + (M-1)*abs(INCV)) if SIDE = 'L' */
/* > (1 + (N-1)*abs(INCV)) if SIDE = 'R' */
/* > The vector v in the representation of P. V is not used */
/* > if TAU = 0. */
/* > \endverbatim */
/* > */
/* > \param[in] INCV */
/* > \verbatim */
/* > INCV is INTEGER */
/* > The increment between elements of v. INCV <> 0 */
/* > \endverbatim */
/* > */
/* > \param[in] TAU */
/* > \verbatim */
/* > TAU is COMPLEX */
/* > The value tau in the representation of P. */
/* > \endverbatim */
/* > */
/* > \param[in,out] C1 */
/* > \verbatim */
/* > C1 is COMPLEX array, dimension */
/* > (LDC,N) if SIDE = 'L' */
/* > (M,1) if SIDE = 'R' */
/* > On entry, the n-vector C1 if SIDE = 'L', or the m-vector C1 */
/* > if SIDE = 'R'. */
/* > */
/* > On exit, the first row of P*C if SIDE = 'L', or the first */
/* > column of C*P if SIDE = 'R'. */
/* > \endverbatim */
/* > */
/* > \param[in,out] C2 */
/* > \verbatim */
/* > C2 is COMPLEX array, dimension */
/* > (LDC, N) if SIDE = 'L' */
/* > (LDC, N-1) if SIDE = 'R' */
/* > On entry, the (m - 1) x n matrix C2 if SIDE = 'L', or the */
/* > m x (n - 1) matrix C2 if SIDE = 'R'. */
/* > */
/* > On exit, rows 2:m of P*C if SIDE = 'L', or columns 2:m of C*P */
/* > if SIDE = 'R'. */
/* > \endverbatim */
/* > */
/* > \param[in] LDC */
/* > \verbatim */
/* > LDC is INTEGER */
/* > The leading dimension of the arrays C1 and C2. */
/* > LDC >= max(1,M). */
/* > \endverbatim */
/* > */
/* > \param[out] WORK */
/* > \verbatim */
/* > WORK is COMPLEX array, dimension */
/* > (N) if SIDE = 'L' */
/* > (M) if SIDE = 'R' */
/* > \endverbatim */
/* Authors: */
/* ======== */
/* > \author Univ. of Tennessee */
/* > \author Univ. of California Berkeley */
/* > \author Univ. of Colorado Denver */
/* > \author NAG Ltd. */
/* > \date November 2011 */
/* > \ingroup complexOTHERcomputational */
/* ===================================================================== */
/* Subroutine */
int clatzm_(char *side, integer *m, integer *n, complex *v, integer *incv, complex *tau, complex *c1, complex *c2, integer *ldc, complex *work)
{
    /* System generated locals */
    integer c1_dim1, c1_offset, c2_dim1, c2_offset, i__1;
    complex q__1;
    /* Local variables */
    extern /* Subroutine */
    int cgerc_(integer *, integer *, complex *, complex *, integer *, complex *, integer *, complex *, integer *), cgemv_(char *, integer *, integer *, complex *, complex *, integer *, complex *, integer *, complex *, complex *, integer *);
    extern logical lsame_(char *, char *);
    extern /* Subroutine */
    int cgeru_(integer *, integer *, complex *, complex *, integer *, complex *, integer *, complex *, integer *), ccopy_(integer *, complex *, integer *, complex *, integer *), caxpy_(integer *, complex *, complex *, integer *, complex *, integer *), clacgv_(integer *, complex *, integer *);
    /* -- LAPACK computational routine (version 3.4.0) -- */
    /* -- LAPACK is a software package provided by Univ. of Tennessee, -- */
    /* -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..-- */
    /* November 2011 */
    /* .. Scalar Arguments .. */
    /* .. */
    /* .. Array Arguments .. */
    /* .. */
    /* ===================================================================== */
    /* .. Parameters .. */
    /* .. */
    /* .. External Subroutines .. */
    /* .. */
    /* .. External Functions .. */
    /* .. */
    /* .. Intrinsic Functions .. */
    /* .. */
    /* .. Executable Statements .. */
    /* Parameter adjustments */
    --v;
    c2_dim1 = *ldc;
    c2_offset = 1 + c2_dim1;
    c2 -= c2_offset;
    c1_dim1 = *ldc;
    c1_offset = 1 + c1_dim1;
    c1 -= c1_offset;
    --work;
    /* Function Body */
    if (min(*m,*n) == 0 || tau->r == 0.f && tau->i == 0.f)
    {
        return 0;
    }
    if (lsame_(side, "L"))
    {
        /* w := ( C1 + v**H * C2 )**H */
        ccopy_(n, &c1[c1_offset], ldc, &work[1], &c__1);
        clacgv_(n, &work[1], &c__1);
        i__1 = *m - 1;
        cgemv_("Conjugate transpose", &i__1, n, &c_b1, &c2[c2_offset], ldc, & v[1], incv, &c_b1, &work[1], &c__1);
        /* [ C1 ] := [ C1 ] - tau* [ 1 ] * w**H */
        /* [ C2 ] [ C2 ] [ v ] */
        clacgv_(n, &work[1], &c__1);
        q__1.r = -tau->r;
        q__1.i = -tau->i; // , expr subst
        caxpy_(n, &q__1, &work[1], &c__1, &c1[c1_offset], ldc);
        i__1 = *m - 1;
        q__1.r = -tau->r;
        q__1.i = -tau->i; // , expr subst
        cgeru_(&i__1, n, &q__1, &v[1], incv, &work[1], &c__1, &c2[c2_offset], ldc);
    }
    else if (lsame_(side, "R"))
    {
        /* w := C1 + C2 * v */
        ccopy_(m, &c1[c1_offset], &c__1, &work[1], &c__1);
        i__1 = *n - 1;
        cgemv_("No transpose", m, &i__1, &c_b1, &c2[c2_offset], ldc, &v[1], incv, &c_b1, &work[1], &c__1);
        /* [ C1, C2 ] := [ C1, C2 ] - tau* w * [ 1 , v**H] */
        q__1.r = -tau->r;
        q__1.i = -tau->i; // , expr subst
        caxpy_(m, &q__1, &work[1], &c__1, &c1[c1_offset], &c__1);
        i__1 = *n - 1;
        q__1.r = -tau->r;
        q__1.i = -tau->i; // , expr subst
        cgerc_(m, &i__1, &q__1, &work[1], &c__1, &v[1], incv, &c2[c2_offset], ldc);
    }
    return 0;
    /* End of CLATZM */
}
/* clatzm_ */