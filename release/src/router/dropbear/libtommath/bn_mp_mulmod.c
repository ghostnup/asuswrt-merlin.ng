#include "tommath_private.h"
#ifdef BN_MP_MULMOD_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis */
/* SPDX-License-Identifier: Unlicense */

/* d = a * b (mod c) */
mp_err mp_mulmod(const mp_int *a, const mp_int *b, const mp_int *c, mp_int *d)
{
   mp_err err;
   mp_int t;

   if ((err = mp_init_size(&t, c->used)) != MP_OKAY) {
      return err;
   }

   if ((err = mp_mul(a, b, &t)) != MP_OKAY) {
      goto LBL_ERR;
   }
   err = mp_mod(&t, c, d);

LBL_ERR:
   mp_clear(&t);
   return err;
}
#endif
