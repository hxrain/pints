#ifndef PINTS_SSE_H
#define PINTS_SSE_H

#ifdef PINTS_SSE
#undef v1f
#undef v2f
#undef v4f
typedef __m128  v1f;
typedef __m128  v2f;
typedef __m128  v4f;
#endif

#ifdef PINTS_SSE2
#undef v1d
#undef v1i
#undef v1l
#undef v2d
#undef v2i
#undef v2l
#undef v4i
typedef __m128d v1d;
typedef __m128i v1i;
typedef __m128i v1l;
typedef __m128d v2d;
typedef __m128i v2i;
typedef __m128i v2l;
typedef __m128i v4i;

typedef __m128i __m128iu __attribute__((aligned(4)));
typedef __m128i __m128lu __attribute__((aligned(8)));
typedef __m64 __m64fu __attribute__((aligned(4)));
#endif

#ifdef PINTS_SSE
// 128 bits

#undef v4f_set
#define v4f_set(a0, a1, a2, a3) _mm_set_ps(a3, a2, a1, a0)

#undef v4f_setr
#define v4f_setr(a3, a2, a1, a0) _mm_setr_ps(a0, a1, a2, a3)

#undef v4f_set1
#define v4f_set1(a) _mm_set1_ps(a)

#undef v4f_load
#define v4f_load(p) _mm_load_ps(p)

#undef v4f_loadu
#define v4f_loadu(p) _mm_loadu_ps(p)

#undef v4f_load1
#define v4f_load1(p) _mm_load1_ps(p)

#undef v4f_store
#define v4f_store(p, a) _mm_store_ps(p, a)

#undef v4f_storeu
#define v4f_storeu(p, a) _mm_storeu_ps(p, a)

#undef v4f_zeros
#define v4f_zeros() _mm_setzero_ps()

#undef v4f_is_zero
#define v4f_is_zero(a) (_mm_movemask_ps(_mm_cmpeq_ps(a, _mm_setzero_ps())) == 0x0F)

#undef v4f_and
#define v4f_and(a, b) _mm_and_ps(a, b)

#undef v4f_or
#define v4f_or(a, b) _mm_or_ps(a, b)

#undef v4f_xor
#define v4f_xor(a, b) _mm_xor_ps(a, b)

#undef v4f_andnot
#define v4f_andnot(a, b) _mm_andnot_ps(b, a)

#undef v4f_eq
#define v4f_eq(a, b) _mm_cmpeq_ps(a, b)

#undef v4f_neq
#define v4f_neq(a, b) _mm_cmpneq_ps(a, b)

#undef v4f_gt
#define v4f_gt(a, b) _mm_cmpgt_ps(a, b)

#undef v4f_lt
#define v4f_lt(a, b) _mm_cmplt_ps(a, b)

#undef v4f_leq
#define v4f_leq(a, b) _mm_cmple_ps(a, b)

#undef v4f_geq
#define v4f_geq(a, b) _mm_cmpge_ps(a, b)

#undef v4f_add
#define v4f_add(a, b) _mm_add_ps(a, b)

#undef v4f_sub
#define v4f_sub(a, b) _mm_sub_ps(a, b)

#undef v4f_min
#define v4f_min(a, b) _mm_min_ps(a, b)

#undef v4f_max
#define v4f_max(a, b) _mm_max_ps(a, b)

#undef v4f_abs
#define v4f_abs(a) _mm_andnot_ps(_mm_set1_ps(-0.f), a)

#undef v4f_mul
#define v4f_mul(a, b) _mm_mul_ps(a, b)

#undef v4f_div
#define v4f_div(a, b) _mm_div_ps(a, b)

#undef v4f_sqrt
#define v4f_sqrt(a) _mm_sqrt_ps(a)


#undef v4f_hshuffle4
#define v4f_hshuffle4(a, b, rule) _mm_shuffle_ps(a, b, rule)
#undef v4f_hshuffle2
#define v4f_hshuffle2(a, b, rule) v4f_hshuffle4(a, b, (((rule)&2)<<4) | (((rule)&2)<<6) | (((rule)&1)<<3) | (((rule)&1)<<1) | 0x44)
#undef v4f_hshuffle2x2
#define v4f_hshuffle2x2(a, b, rule) v4f_hshuffle4(a, b, ((rule) << 4) | (rule))


// scalar


#undef v1f_set
#define v1f_set(a0) v4f_set(a0, 0, 0, 0)

#undef v1f_setr
#define v1f_setr(a0) v4f_setr(0, 0, 0, a0)

#undef v1f_set1
#define v1f_set1(a) v1f_set(a)

#undef v1f_load
#define v1f_load(p) _mm_load_ss(p)

#undef v1f_loadu
#define v1f_loadu(p) v1f_load(p)

#undef v1f_load1
#define v1f_load1(p) v1f_load(p)

#undef v1f_store
#define v1f_store(p, a) _mm_store_ss(p, a)

#undef v1f_storeu
#define v1f_storeu(p, a) v1f_store(p, a)

#undef v1f_zero
#define v1f_zero() v4f_zero()

#undef v1f_is_zero
#define v1f_is_zero(a) (_mm_cvtss_f32(a) == 0)

#undef v1f_and
#define v1f_and(a, b) _mm_and_ps(a, b)

#undef v1f_or
#define v1f_or(a, b) _mm_or_ps(a, b)

#undef v1f_xor
#define v1f_xor(a, b) _mm_xor_ps(a, b)

#undef v1f_andnot
#define v1f_andnot(a, b) _mm_andnot_ps(b, a)

#undef v1f_eq
#define v1f_eq(a, b) _mm_cmpeq_ss(a, b)

#undef v1f_neq
#define v1f_neq(a, b) _mm_cmpneq_ss(a, b)

#undef v1f_gt
#define v1f_gt(a, b) _mm_cmpgt_ss(a, b)

#undef v1f_lt
#define v1f_lt(a, b) _mm_cmplt_ss(a, b)

#undef v1f_leq
#define v1f_leq(a, b) _mm_cmple_ss(a, b)

#undef v1f_geq
#define v1f_geq(a, b) _mm_cmpge_ss(a, b)

#undef v1f_add
#define v1f_add(a, b) _mm_add_ss(a, b)

#undef v1f_sub
#define v1f_sub(a, b) _mm_sub_ss(a, b)

#undef v1f_min
#define v1f_min(a, b) v4f_min(a, b)

#undef v1f_max
#define v1f_max(a, b) v4f_max(a, b)

#undef v1f_abs
#define v1f_abs(a) v4f_abs(a)

#undef v1f_mul
#define v1f_mul(a, b) _mm_mul_ss(a, b)

#undef v1f_div
#define v1f_div(a, b) _mm_div_ss(a, b)

#undef v1f_sqrt
#define v1f_sqrt(a) _mm_sqrt_ss(a)


// 64 bits vector

#undef v2f_set
#define v2f_set(a0, a1) v4f_set(a0, a1, 0, 0)

#undef v2f_setr
#define v2f_setr(a1, a0) v4f_setr(0, 0, a1, a0)

#undef v2f_set1
#define v2f_set1(a) v2f_set(a, a)

#undef v2f_load
#define v2f_load(p) _mm_load_ps(p)

#undef v2f_loadu
#define v2f_loadu(p) _mm_loadu_ps(p)

#undef v2f_load1
#define v2f_load1(p) v4f_load(p)

#undef v2f_store
#define v2f_store(p, a) _mm_storel_pi((__m64fu*) p, a)
//#define v2f_store(p, a) _mm_store_ps(p, a)

//#undef v2f_storeu
//#define v2f_storeu(p, a) _mm_storeu_ps(p, a)

#undef v2f_zero
#define v2f_zero() v4f_zero()

#undef v2f_is_zero
#define v2f_is_zero(a) v4f_is_zero(v4f_permute(v4f_cast_v2f(a), 0x11))

#undef v2f_and
#define v2f_and(a, b) _mm_and_ps(a, b)

#undef v2f_or
#define v2f_or(a, b) _mm_or_ps(a, b)

#undef v2f_xor
#define v2f_xor(a, b) _mm_xor_ps(a, b)

#undef v2f_andnot
#define v2f_andnot(a, b) _mm_andnot_ps(b, a)

#undef v2f_eq
#define v2f_eq(a, b) _mm_cmpeq_ps(a, b)

#undef v2f_neq
#define v2f_neq(a, b) _mm_cmpneq_ps(a, b)

#undef v2f_gt
#define v2f_gt(a, b) _mm_cmpgt_ps(a, b)

#undef v2f_lt
#define v2f_lt(a, b) _mm_cmplt_ps(a, b)

#undef v2f_leq
#define v2f_leq(a, b) _mm_cmple_ps(a, b)

#undef v2f_geq
#define v2f_geq(a, b) _mm_cmpge_ps(a, b)

#undef v2f_add
#define v2f_add(a, b) _mm_add_ps(a, b)

#undef v2f_sub
#define v2f_sub(a, b) _mm_sub_ps(a, b)

#undef v2f_min
#define v2f_min(a, b) v4f_min(a, b)

#undef v2f_max
#define v2f_max(a, b) v4f_max(a, b)

#undef v2f_abs
#define v2f_abs(a) v4f_abs(a)

#undef v2f_mul
#define v2f_mul(a, b) _mm_mul_ps(a, b)

#undef v2f_div
#define v2f_div(a, b) _mm_div_ps(a, b)

#undef v2f_sqrt
#define v2f_sqrt(a) _mm_sqrt_ps(a)


// Casts

// Down Casts
#undef v1f_cast_v2f
#undef v2f_cast_v4f
#define v1f_cast_v2f(a) (a)
#define v2f_cast_v4f(a) (a)

// Up Casts
#undef v2f_cast_v1f
#undef v4f_cast_v2f
#define v2f_cast_v1f(a) (a)
#define v4f_cast_v2f(a) (a)

// Transtype Casts

// 128 bits
#undef v4f_cast_v4f
#define v4f_cast_v4f(a) (a)

// 64 bits
#undef v2f_cast_v2f
#define v2f_cast_v2f(a) (a)

// 32 bits
#undef v1f_cast_v1f
#define v1f_cast_v1f(a) (a)


// Conversions
#undef v4f_cvt_v4f
#undef v2f_cvt_v2f
#undef v1f_cvt_v1f


#define v4f_cvt_v4f(a) (a)
#define v2f_cvt_v2f(a) (a)
#define v1f_cvt_v1f(a) (a)


// Default get_high get_low, sethigh, setlow, merge
#undef v2f_get_high_v4f
#undef v1f_get_high_v2f
#undef v2f_get_low_v4f
#undef v1f_get_low_v2f
#undef v2f_get_hilo_v4f
#undef v1f_get_hilo_v2f
#undef v4f_set_high_v2f
#undef v2f_set_high_v1f
#undef v4f_set_low_v2f
#undef v2f_set_low_v1f
#undef v4f_merge2_v2f
#undef v2f_merge2_v1f

#define v2f_get_high_v4f(a)       v2f_cast_v4f(v4f_permute4(a, 0xE))
#define v1f_get_high_v2f(a)       v2f_cast_v4f(v4f_permute4(v4f_cast_v2f(a), 0x1))
#define v2f_get_low_v4f(a)        v2f_cast_v4f(a)
#define v1f_get_low_v2f(a)        v1f_cast_v2f(a)
#define v2f_get_hilo_v4f(a, h)    v2f_cast_v4f(v4f_permute4(a, (((h) & 1) << 1) | (((h) & 1) << 3) | 0x4))
#define v1f_get_hilo_v2f(a, h)    v1f_cast_v4f(v4f_permute4(a, (h) & 1))
#define v4f_set_high_v2f(src, a)  v4f_hshuffle4(src, v4f_cast_v2f(a), 0x44)
#define v2f_set_high_v1f(src, a)  v2f_merge2_v1f(v1f_get_low_v2f(src), a)
#define v4f_set_low_v2f(src, a)   v4f_hshuffle4(v4f_cast_v2f(a), src, 0xE4)
#define v2f_set_low_v1f(src, a)   v2f_merge2_v1f(a, v1f_get_high_v2f(src))
#define v4f_merge2_v2f(a, b)      v4f_hshuffle4(v4f_cast_v2f(a), v4f_cast_v2f(b), 0x44)
#define v2f_merge2_v1f(a, b)      _mm_unpacklo_ps(a, b)

#endif

#ifdef PINTS_SSE2
// 128 bits

#undef v2d_set
#undef v4f_set
#undef v4i_set
#undef v2l_set
#define v2d_set(a0, a1)         _mm_set_pd(a1, a0)
#define v4f_set(a0, a1, a2, a3) _mm_set_ps(a3, a2, a1, a0)
#define v4i_set(a0, a1, a2, a3) _mm_set_epi32(a3, a2, a1, a0)
#define v2l_set(a0, a1)         _mm_set_epi64x(a1, a0)

#undef v2d_setr
#undef v4f_setr
#undef v4i_setr
#undef v2l_setr
#define v2d_setr(a1, a0)         _mm_setr_pd(a0, a1)
#define v4f_setr(a3, a2, a1, a0) _mm_setr_ps(a0, a1, a2, a3)
#define v4i_setr(a3, a2, a1, a0) _mm_setr_epi32(a0, a1, a2, a3)
#define v2l_setr(a1, a0)         _mm_setr_epi64x(a0, a1)

#undef v2d_set1
#undef v4f_set1
#undef v4i_set1
#undef v2l_set1
#define v2d_set1(a) _mm_set1_pd(a)
#define v4f_set1(a) _mm_set1_ps(a)
#define v4i_set1(a) _mm_set1_epi32(a)
#define v2l_set1(a) _mm_set1_epi64x(a)

#undef v2d_load
#undef v4f_load
#undef v4i_load
#undef v2l_load
#define v2d_load(p) _mm_load_pd(p)
#define v4f_load(p) _mm_load_ps(p)
#define v4i_load(p) _mm_load_si128((__m128iu*)p)
#define v2l_load(p) _mm_load_si128((__m128lu*)p)

#undef v2d_loadu
#undef v4f_loadu
#undef v4i_loadu
#undef v2l_loadu
#define v2d_loadu(p) _mm_loadu_pd(p)
#define v4f_loadu(p) _mm_loadu_ps(p)
#define v4i_loadu(p) _mm_loadu_si128((__m128iu*)p)
#define v2l_loadu(p) _mm_loadu_si128((__m128lu*)p)

#undef v2d_load1
#undef v4f_load1
#undef v4i_load1
#undef v2l_load1
#define v2d_load1(p) _mm_load1_pd(p)
#define v4f_load1(p) _mm_load1_ps(p)
#define v4i_load1(p) v4i_cast_v4f(v4f_load((float *) p))
#define v2l_load1(p) v2l_cast_v2d(v2d_load((double*) p))

#undef v2d_store
#undef v4f_store
#undef v4i_store
#undef v2l_store
#define v2d_store(p, a) _mm_store_pd(p, a)
#define v4f_store(p, a) _mm_store_ps(p, a)
#define v4i_store(p, a) _mm_store_si128((__m128iu*)p, a)
#define v2l_store(p, a) _mm_store_si128((__m128lu*)p, a)

#undef v2d_storeu
#undef v4f_storeu
#undef v4i_storeu
#undef v2l_storeu
#define v2d_storeu(p, a) _mm_storeu_pd(p, a)
#define v4f_storeu(p, a) _mm_storeu_ps(p, a)
#define v4i_storeu(p, a) _mm_storeu_si128((__m128iu*)p, a)
#define v2l_storeu(p, a) _mm_storeu_si128((__m128lu*)p, a)

#undef v2d_zeros
#undef v4f_zeros
#undef v4i_zeros
#undef v2l_zeros
#define v2d_zeros() _mm_setzero_pd()
#define v4f_zeros() _mm_setzero_ps()
#define v4i_zeros() _mm_setzero_si128()
#define v2l_zeros() _mm_setzero_si128()

#undef v2d_ones
#undef v4f_ones
#undef v4i_ones
#undef v2l_ones
#define v2d_ones() v2d_cast_v2l(v2l_ones())
#define v4f_ones() v4f_cast_v4i(v4i_ones())
#define v4i_ones() _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())
#define v2l_ones() _mm_cmpeq_epi32(_mm_setzero_si128(), _mm_setzero_si128())

#undef v2d_is_zero
#undef v4f_is_zero
#undef v4i_is_zero
#undef v2l_is_zero
#define v2d_is_zero(a) v2l_is_zero(v2l_cast_v2d(a))
#define v4f_is_zero(a) v4i_is_zero(v4i_cast_v4f(a))
#define v4i_is_zero(a) (_mm_movemask_epi8(_mm_cmpeq_epi8(a, _mm_setzero_si128())) == 0xFFFF)
#define v2l_is_zero(a) (_mm_movemask_epi8(_mm_cmpeq_epi8(a, _mm_setzero_si128())) == 0xFFFF)

#undef v2d_and
#undef v4f_and
#undef v4i_and
#undef v2l_and
#define v2d_and(a, b) _mm_and_pd(a, b)
#define v4f_and(a, b) _mm_and_ps(a, b)
#define v4i_and(a, b) _mm_and_si128(a, b)
#define v2l_and(a, b) _mm_and_si128(a, b)

#undef v2d_or
#undef v4f_or
#undef v4i_or
#undef v2l_or
#define v2d_or(a, b) _mm_or_pd(a, b)
#define v4f_or(a, b) _mm_or_ps(a, b)
#define v4i_or(a, b) _mm_or_si128(a, b)
#define v2l_or(a, b) _mm_or_si128(a, b)

#undef v2d_xor
#undef v4f_xor
#undef v4i_xor
#undef v2l_xor
#define v2d_xor(a, b) _mm_xor_pd(a, b)
#define v4f_xor(a, b) _mm_xor_ps(a, b)
#define v4i_xor(a, b) _mm_xor_si128(a, b)
#define v2l_xor(a, b) _mm_xor_si128(a, b)

#undef v2d_andnot
#undef v4f_andnot
#undef v4i_andnot
#undef v2l_andnot
#define v2d_andnot(a, b) _mm_andnot_pd(b, a)
#define v4f_andnot(a, b) _mm_andnot_ps(b, a)
#define v4i_andnot(a, b) _mm_andnot_si128(b, a)
#define v2l_andnot(a, b) _mm_andnot_si128(b, a)

#undef v2d_eq
#undef v4f_eq
#undef v4i_eq
#undef v2l_eq
#define v2d_eq(a, b) _mm_cmpeq_pd(a, b)
#define v4f_eq(a, b) _mm_cmpeq_ps(a, b)
#define v4i_eq(a, b) _mm_cmpeq_epi32(a, b)
#define v2l_eq(a, b) __sse2_v2l_eq(a, b)

#undef v2d_neq
#undef v4f_neq
#undef v4i_neq
#undef v2l_neq
#define v2d_neq(a, b) _mm_cmpneq_pd(a, b)
#define v4f_neq(a, b) _mm_cmpneq_ps(a, b)
#define v4i_neq(a, b) v4i_not(v4i_eq(a, b))
#define v2l_neq(a, b) v2l_not(v2l_eq(a, b))

#undef v2d_gt
#undef v4f_gt
#undef v4i_gt
#undef v2l_gt
#define v2d_gt(a, b) _mm_cmpgt_pd(a, b)
#define v4f_gt(a, b) _mm_cmpgt_ps(a, b)
#define v4i_gt(a, b) _mm_cmpgt_epi32(a, b)
#define v2l_gt(a, b) __sse2_v2l_gt(a, b)

#undef v2d_lt
#undef v4f_lt
#undef v4i_lt
#undef v2l_lt
#define v2d_lt(a, b) _mm_cmplt_pd(a, b)
#define v4f_lt(a, b) _mm_cmplt_ps(a, b)
#define v4i_lt(a, b) _mm_cmplt_epi32(a, b)
#define v2l_lt(a, b) __sse2_v2l_lt(a, b)

#undef v2d_leq
#undef v4f_leq
#undef v4i_leq
#undef v2l_leq
#define v2d_leq(a, b) _mm_cmple_pd(a, b)
#define v4f_leq(a, b) _mm_cmple_ps(a, b)
#define v4i_leq(a, b) v4i_gt(b, a)
#define v2l_leq(a, b) v2l_gt(b, a)

#undef v2d_geq
#undef v4f_geq
#undef v4i_geq
#undef v2l_geq
#define v2d_geq(a, b) _mm_cmpge_pd(a, b)
#define v4f_geq(a, b) _mm_cmpge_ps(a, b)
#define v4i_geq(a, b) v4i_lt(b, a)
#define v2l_geq(a, b) v2l_lt(b, a)

#undef v2d_add
#undef v4f_add
#undef v4i_add
#undef v2l_add
#define v2d_add(a, b) _mm_add_pd(a, b)
#define v4f_add(a, b) _mm_add_ps(a, b)
#define v4i_add(a, b) _mm_add_epi32(a, b)
#define v2l_add(a, b) _mm_add_epi64(a, b)

#undef v2d_sub
#undef v4f_sub
#undef v4i_sub
#undef v2l_sub
#define v2d_sub(a, b) _mm_sub_pd(a, b)
#define v4f_sub(a, b) _mm_sub_ps(a, b)
#define v4i_sub(a, b) _mm_sub_epi32(a, b)
#define v2l_sub(a, b) _mm_sub_epi64(a, b)

#undef v2d_neg
#undef v4f_neg
#define v2d_neg(a) _mm_xor_pd(_mm_set1_pd(-0.0), a)
#define v4f_neg(a) _mm_xor_ps(_mm_set1_ps(-0.f), a)

#undef v2d_min
#undef v4f_min
#define v2d_min(a, b) _mm_min_pd(a, b)
#define v4f_min(a, b) _mm_min_ps(a, b)

#undef v2d_max
#undef v4f_max
#define v2d_max(a, b) _mm_max_pd(a, b)
#define v4f_max(a, b) _mm_max_ps(a, b)

#undef v2d_abs
#undef v4f_abs
#define v2d_abs(a) _mm_andnot_pd(_mm_set1_pd(-0.0), a)
#define v4f_abs(a) _mm_andnot_ps(_mm_set1_ps(-0.f), a)

#undef v2d_mul
#undef v4f_mul
#undef v4i_mul
#undef v2l_mul
#define v2d_mul(a, b) _mm_mul_pd(a, b)
#define v4f_mul(a, b) _mm_mul_ps(a, b)
#define v4i_mul(a, b) v4i_cvt_v4f(v4f_mul(v4f_cvt_v4i(a), v4f_cvt_v4i(b)))
#define v2l_mul(a, b) v2l_cvt_v2d(v2d_mul(v2d_cvt_v2l(a), v2d_cvt_v2l(b)))

#undef v2d_div
#undef v4f_div
#undef v4i_div
#undef v2l_div
#define v2d_div(a, b) _mm_div_pd(a, b)
#define v4f_div(a, b) _mm_div_ps(a, b)
#define v4i_div(a, b) v4i_cvt_v4f(v4f_div(v4f_cvt_v4i(a), v4f_cvt_v4i(b)))
#define v2l_div(a, b) v2l_cvt_v2d(v2d_div(v2d_cvt_v2l(a), v2d_cvt_v2l(b)))

#undef v2d_sqrt
#undef v4f_sqrt
#undef v4i_sqrt
#undef v2l_sqrt
#define v2d_sqrt(a) _mm_sqrt_pd(a)
#define v4f_sqrt(a) _mm_sqrt_ps(a)
#define v4i_sqrt(a) v4i_cvt_v4f(v4f_sqrt(v4f_cvt_v4i(a)))
#define v2l_sqrt(a) v2l_cvt_v2d(v2d_sqrt(v2d_cvt_v2l(a)))


#undef v2d_hshuffle2
#undef v4f_hshuffle4
#undef v4i_hshuffle4
#undef v2l_hshuffle2
#define v2d_hshuffle2(a, b, rule) _mm_shuffle_pd(a, b, rule)
#define v4f_hshuffle4(a, b, rule) _mm_shuffle_ps(a, b, rule)
#define v4i_hshuffle4(a, b, rule) v4i_cast_v4f(v4f_hshuffle4(v4f_cast_v4i(a), v4f_cast_v4i(b), rule))
#define v2l_hshuffle2(a, b, rule) v2l_cast_v2d(v2d_hshuffle2(v2d_cast_v2l(a), v2d_cast_v2l(b), rule))

#undef v4f_hshuffle2
#undef v4i_hshuffle2
#define v4f_hshuffle2(a, b, rule) v4f_hshuffle4(a, b, (((rule)&2)<<4) | (((rule)&2)<<6) | (((rule)&1)<<3) | (((rule)&1)<<1) | 0x44)
#define v4i_hshuffle2(a, b, rule) v4i_hshuffle4(a, b, (((rule)&2)<<4) | (((rule)&2)<<6) | (((rule)&1)<<3) | (((rule)&1)<<1) | 0x44)

#undef v4f_hshuffle2x2
#undef v4i_hshuffle2x2
#define v4f_hshuffle2x2(a, b, rule) v4f_hshuffle4(a, b, ((rule) << 4) | (rule))
#define v4i_hshuffle2x2(a, b, rule) v4i_hshuffle4(a, b, ((rule) << 4) | (rule))

#undef v4i_permute4
#define v4i_permute4(a, rule) _mm_shuffle_epi32(a, rule)

#undef v4i_permute2
#define v4i_permute2(a, rule) v4i_permute4(a, (((rule)&2)<<4) | (((rule)&2)<<6) | (((rule)&1)<<3) | (((rule)&1)<<1) | 0x44)

#undef v4i_permute2x2
#define v4i_permute2x2(a, rule) v4i_permute4(a, ((rule) << 4) | (rule))


// scalar


#undef v1d_set
#undef v1f_set
#undef v1i_set
#undef v1l_set
#define v1d_set(a0) v2d_set(a0, 0)
#define v1f_set(a0) v4f_set(a0, 0, 0, 0)
#define v1i_set(a0) v4i_set(a0, 0, 0, 0)
#define v1l_set(a0) v2l_set(a0, 0)

#undef v1d_setr
#undef v1f_setr
#undef v1i_setr
#undef v1l_setr
#define v1d_setr(a0) v2d_setr(0, a0)
#define v1f_setr(a0) v4f_setr(0, 0, 0, a0)
#define v1i_setr(a0) v4i_setr(0, 0, 0, a0)
#define v1l_setr(a0) v2l_setr(0, a0)

#undef v1d_set1
#undef v1f_set1
#undef v1i_set1
#undef v1l_set1
#define v1d_set1(a) v1d_set(a)
#define v1f_set1(a) v1f_set(a)
#define v1i_set1(a) v1i_set(a)
#define v1l_set1(a) v1l_set(a)

#undef v1d_load
#undef v1f_load
#undef v1i_load
#undef v1l_load
#define v1d_load(p) _mm_load_sd(p)
#define v1f_load(p) _mm_load_ss(p)
#define v1i_load(p) v1i_cast_v1f(v1f_load((float *)p))
#define v1l_load(p) v1l_cast_v1d(v1d_load((double*)p))

#undef v1d_loadu
#undef v1f_loadu
#undef v1i_loadu
#undef v1l_loadu
#define v1d_loadu(p) v1d_load(p)
#define v1f_loadu(p) v1f_load(p)
#define v1i_loadu(p) v1i_load(p)
#define v1l_loadu(p) v1l_load(p)

#undef v1d_load1
#undef v1f_load1
#undef v1i_load1
#undef v1l_load1
#define v1d_load1(p) v1d_load(p)
#define v1f_load1(p) v1f_load(p)
#define v1i_load1(p) v1i_load(p)
#define v1l_load1(p) v1l_load(p)

#undef v1d_store
#undef v1f_store
#undef v1i_store
#undef v1l_store
#define v1d_store(p, a) _mm_store_sd(p, a)
#define v1f_store(p, a) _mm_store_ss(p, a)
#define v1i_store(p, a) v1f_store((float *)(p), v1f_cast_v1i(a))
#define v1l_store(p, a) v1d_store((double*)(p), v1d_cast_v1l(a))

#undef v1d_storeu
#undef v1f_storeu
#undef v1i_storeu
#undef v1l_storeu
#define v1d_storeu(p, a) v1d_store(p, a)
#define v1f_storeu(p, a) v1f_store(p, a)
#define v1i_storeu(p, a) v1i_store(p, a)
#define v1l_storeu(p, a) v1l_store(p, a)

#undef v1d_zeros
#undef v1f_zeros
#undef v1i_zeros
#undef v1l_zeros
#define v1d_zeros() v2d_zeros()
#define v1f_zeros() v4f_zeros()
#define v1i_zeros() v4i_zeros()
#define v1l_zeros() v2l_zeros()

#undef v1d_ones
#undef v1f_ones
#undef v1i_ones
#undef v1l_ones
#define v1d_ones() v2d_ones()
#define v1f_ones() v4f_ones()
#define v1i_ones() v4i_ones()
#define v1l_ones() v2l_ones()

#undef v1d_is_zero
#undef v1f_is_zero
#undef v1i_is_zero
#undef v1l_is_zero
#define v1d_is_zero(a) (_mm_cvtsd_f64(a) == 0)
#define v1f_is_zero(a) (_mm_cvtss_f32(a) == 0)
#define v1i_is_zero(a) (_mm_cvtsi128_si32(a) == 0)
#define v1l_is_zero(a) (_mm_cvtsi128_si64x(a) == 0)

#undef v1d_and
#undef v1f_and
#undef v1i_and
#undef v1l_and
#define v1d_and(a, b) _mm_and_pd(a, b)
#define v1f_and(a, b) _mm_and_ps(a, b)
#define v1i_and(a, b) _mm_and_si128(a, b)
#define v1l_and(a, b) _mm_and_si128(a, b)

#undef v1d_or
#undef v1f_or
#undef v1i_or
#undef v1l_or
#define v1d_or(a, b) _mm_or_pd(a, b)
#define v1f_or(a, b) _mm_or_ps(a, b)
#define v1i_or(a, b) _mm_or_si128(a, b)
#define v1l_or(a, b) _mm_or_si128(a, b)

#undef v1d_xor
#undef v1f_xor
#undef v1i_xor
#undef v1l_xor
#define v1d_xor(a, b) _mm_xor_pd(a, b)
#define v1f_xor(a, b) _mm_xor_ps(a, b)
#define v1i_xor(a, b) _mm_xor_si128(a, b)
#define v1l_xor(a, b) _mm_xor_si128(a, b)

#undef v1d_andnot
#undef v1f_andnot
#undef v1i_andnot
#undef v1l_andnot
#define v1d_andnot(a, b) _mm_andnot_pd(b, a)
#define v1f_andnot(a, b) _mm_andnot_ps(b, a)
#define v1i_andnot(a, b) _mm_andnot_si128(b, a)
#define v1l_andnot(a, b) _mm_andnot_si128(b, a)

#undef v1d_eq
#undef v1f_eq
#undef v1i_eq
#undef v1l_eq
#define v1d_eq(a, b) _mm_cmpeq_sd(a, b)
#define v1f_eq(a, b) _mm_cmpeq_ss(a, b)
#define v1i_eq(a, b) _mm_cmpeq_epi32(a, b)
#define v1l_eq(a, b) _mm_cmpeq_epi64(a, b)

#undef v1d_neq
#undef v1f_neq
#undef v1i_neq
#undef v1l_neq
#define v1d_neq(a, b) _mm_cmpneq_sd(a, b)
#define v1f_neq(a, b) _mm_cmpneq_ss(a, b)
#define v1i_neq(a, b) v1i_not(v1i_eq(a, b))
#define v1l_neq(a, b) v1l_not(v1l_eq(a, b))

#undef v1d_gt
#undef v1f_gt
#undef v1i_gt
#undef v1l_gt
#define v1d_gt(a, b) _mm_cmpgt_sd(a, b)
#define v1f_gt(a, b) _mm_cmpgt_ss(a, b)
#define v1i_gt(a, b) _mm_cmpgt_epi32(a, b)
#define v1l_gt(a, b) _mm_cmpgt_epi64(a, b)

#undef v1d_lt
#undef v1f_lt
#undef v1i_lt
#undef v1l_lt
#define v1d_lt(a, b) _mm_cmplt_sd(a, b)
#define v1f_lt(a, b) _mm_cmplt_ss(a, b)
#define v1i_lt(a, b) _mm_cmplt_epi32(a, b)
#define v1l_lt(a, b) v1l_andnot(v1l_leq(a, b), v1l_eq(a, b))

#undef v1d_leq
#undef v1f_leq
#undef v1i_leq
#undef v1l_leq
#define v1d_leq(a, b) _mm_cmple_sd(a, b)
#define v1f_leq(a, b) _mm_cmple_ss(a, b)
#define v1i_leq(a, b) v1i_gt(b, a)
#define v1l_leq(a, b) v1l_gt(b, a)

#undef v1d_geq
#undef v1f_geq
#undef v1i_geq
#undef v1l_geq
#define v1d_geq(a, b) _mm_cmpge_sd(a, b)
#define v1f_geq(a, b) _mm_cmpge_ss(a, b)
#define v1i_geq(a, b) v1i_lt(b, a)
#define v1l_geq(a, b) v1l_lt(b, a)

#undef v1d_add
#undef v1f_add
#undef v1i_add
#undef v1l_add
#define v1d_add(a, b) _mm_add_sd(a, b)
#define v1f_add(a, b) _mm_add_ss(a, b)
#define v1i_add(a, b) _mm_add_epi32(a, b)
#define v1l_add(a, b) _mm_add_epi64(a, b)

#undef v1d_sub
#undef v1f_sub
#undef v1i_sub
#undef v1l_sub
#define v1d_sub(a, b) _mm_sub_sd(a, b)
#define v1f_sub(a, b) _mm_sub_ss(a, b)
#define v1i_sub(a, b) _mm_sub_epi32(a, b)
#define v1l_sub(a, b) _mm_sub_epi64(a, b)

#undef v1d_neg
#undef v1f_neg
#define v1d_neg(a) v2d_neg(a)
#define v1f_neg(a) v4f_neg(a)

#undef v1d_min
#undef v1f_min
#define v1d_min(a, b) v2d_min(a, b)
#define v1f_min(a, b) v4f_min(a, b)

#undef v1d_max
#undef v1f_max
#define v1d_max(a, b) v2d_max(a, b)
#define v1f_max(a, b) v4f_max(a, b)

#undef v1d_abs
#undef v1f_abs
#define v1d_abs(a) v2d_abs(a)
#define v1f_abs(a) v4f_abs(a)

#undef v1d_mul
#undef v1f_mul
#undef v1i_mul
#undef v1l_mul
#define v1d_mul(a, b) _mm_mul_sd(a, b)
#define v1f_mul(a, b) _mm_mul_ss(a, b)
#define v1i_mul(a, b) _mm_mul_epi32(a, b)
#define v1l_mul(a, b) v1l_cvt_v1d(v1d_mul(v1d_cvt_v1l(a), v1d_cvt_v1l(b)))

#undef v1d_div
#undef v1f_div
#undef v1i_div
#undef v1l_div
#define v1d_div(a, b) _mm_div_sd(a, b)
#define v1f_div(a, b) _mm_div_ss(a, b)
#define v1i_div(a, b) v1i_cvt_v1f(v1f_div(v1f_cvt_v1i(a), v1f_cvt_v1i(b)))
#define v1l_div(a, b) v1l_cvt_v1d(v1d_div(v1d_cvt_v1l(a), v1d_cvt_v1l(b)))

#undef v1d_sqrt
#undef v1f_sqrt
#undef v1i_sqrt
#undef v1l_sqrt
#define v1d_sqrt(a) _mm_sqrt_sd(a, a)
#define v1f_sqrt(a) _mm_sqrt_ss(a)
#define v1i_sqrt(a) v1i_cvt_v1f(v1f_sqrt(v1f_cvt_v1i(a)))
#define v1l_sqrt(a) v1l_cvt_v1d(v1d_sqrt(v1d_cvt_v1l(a)))


// 64 bits vector

#undef v2f_set
#undef v2i_set
#define v2f_set(a0, a1) v4f_set(a0, a1, 0, 0)
#define v2i_set(a0, a1) v4i_set(a0, a1, 0, 0)

#undef v2f_setr
#undef v2i_setr
#define v2f_setr(a1, a0) v4f_setr(0, 0, a1, a0)
#define v2i_setr(a1, a0) v4i_setr(0, 0, a1, a0)

#undef v2f_set1
#undef v2i_set1
#define v2f_set1(a) v2f_set(a, a)
#define v2i_set1(a) v2i_set(a, a)

#undef v2f_load
#undef v2i_load
#define v2f_load(p) _mm_load_ps(p)
#define v2i_load(p) v2i_cast_v2f(v2f_load((float *)p))

#undef v2f_loadu
#undef v2i_loadu
#define v2f_loadu(p) _mm_loadu_ps(p)
#define v2i_loadu(p) v2i_cast_v2f(v2f_loadu((float *)p))

#undef v2f_load1
#undef v2i_load1
#define v2f_load1(p) v4f_load(p)
#define v2i_load1(p) v4i_load(p)

#undef v2f_store
#undef v2i_store
#define v2f_store(p, a) _mm_storel_pi((__m64fu*) p, a)
#define v2i_store(p, a) _mm_storel_epi64((__m128iu*) p, a)

//#undef v2f_storeu
//#undef v2i_storeu
//#define v2f_storeu(p, a) _mm_storeu_ps(p, a)
//#define v2i_storeu(p, a) v2f_storeu((float *)(p), v2f_cast_v2i(a))

#undef v2f_zeros
#undef v2i_zeros
#define v2f_zeros() v4f_zeros()
#define v2i_zeros() v4i_zeros()

#undef v2f_ones
#undef v2i_ones
#define v2f_ones() v4f_ones()
#define v2i_ones() v4i_ones()

#undef v2f_is_zero
#undef v2i_is_zero
#define v2f_is_zero(a) v4f_is_zero(v4f_permute(v4f_cast_v2f(a), 0x44))
#define v2i_is_zero(a) v4i_is_zero(v4i_permute(v4i_cast_v2i(a), 0x44))

#undef v2f_and
#undef v2i_and
#define v2f_and(a, b) _mm_and_ps(a, b)
#define v2i_and(a, b) _mm_and_si128(a, b)

#undef v2f_or
#undef v2i_or
#define v2f_or(a, b) _mm_or_ps(a, b)
#define v2i_or(a, b) _mm_or_si128(a, b)

#undef v2f_xor
#undef v2i_xor
#define v2f_xor(a, b) _mm_xor_ps(a, b)
#define v2i_xor(a, b) _mm_xor_si128(a, b)

#undef v2f_andnot
#undef v2i_andnot
#define v2f_andnot(a, b) _mm_andnot_ps(b, a)
#define v2i_andnot(a, b) _mm_andnot_si128(b, a)

#undef v2f_eq
#undef v2i_eq
#define v2f_eq(a, b) _mm_cmpeq_ps(a, b)
#define v2i_eq(a, b) _mm_cmpeq_epi32(a, b)

#undef v2f_neq
#undef v2i_neq
#define v2f_neq(a, b) _mm_cmpneq_ps(a, b)
#define v2i_neq(a, b) v2i_not(v2i_eq(a, b))

#undef v2f_gt
#undef v2i_gt
#define v2f_gt(a, b) _mm_cmpgt_ps(a, b)
#define v2i_gt(a, b) _mm_cmpgt_epi32(a, b)

#undef v2f_lt
#undef v2i_lt
#define v2f_lt(a, b) _mm_cmplt_ps(a, b)
#define v2i_lt(a, b) _mm_cmplt_epi32(a, b)

#undef v2f_leq
#undef v2i_leq
#define v2f_leq(a, b) _mm_cmple_ps(a, b)
#define v2i_leq(a, b) _mm_cmpgt_epi32(b, a)

#undef v2f_geq
#undef v2i_geq
#define v2f_geq(a, b) _mm_cmpge_ps(a, b)
#define v2i_geq(a, b) _mm_cmplt_epi32(b, a)

#undef v2f_add
#undef v2i_add
#define v2f_add(a, b) _mm_add_ps(a, b)
#define v2i_add(a, b) _mm_add_epi32(a, b)

#undef v2f_sub
#undef v2i_sub
#define v2f_sub(a, b) _mm_sub_ps(a, b)
#define v2i_sub(a, b) _mm_sub_epi32(a, b)

#undef v2f_neg
#define v2f_neg(a) v4f_neg(a)

#undef v2f_min
#define v2f_min(a, b) v4f_min(a, b)

#undef v2f_max
#define v2f_max(a, b) v4f_max(a, b)

#undef v2f_abs
#define v2f_abs(a) v4f_abs(a)

#undef v2f_mul
#undef v2i_mul
#define v2f_mul(a, b) _mm_mul_ps(a, b)
#define v2i_mul(a, b) _mm_mul_epi32(a, b)

#undef v2f_div
#undef v2i_div
#define v2f_div(a, b) _mm_div_ps(a, b)
#define v2i_div(a, b) v2i_cvt_v2f(v2f_div(v2f_cvt_v2i(a), v2f_cvt_v2i(b)))

#undef v2f_sqrt
#undef v2i_sqrt
#define v2f_sqrt(a) _mm_sqrt_ps(a)
#define v2i_sqrt(a) v2i_cvt_v2f(v2f_sqrt(v2f_cvt_v2i(a)))

#undef v2f_hshuffle2
#undef v2i_hshuffle2
#undef v2f_permute2
#undef v2i_permute2
#define v2f_hshuffle2(a, b, rule) v4f_hshuffle2x2(a, b, rule)
#define v2i_hshuffle2(a, b, rule) v4i_hshuffle2x2(a, b, rule)
#define v2f_permute2(a, rule) v4f_permute2x2(a, rule)
#define v2i_permute2(a, rule) v4i_permute2x2(a, rule)

// Casts

// Down Casts
#undef v1d_cast_v2d
#undef v1f_cast_v2f
#undef v1i_cast_v2i
#undef v1l_cast_v2l
#undef v2f_cast_v4f
#undef v2i_cast_v4i
#define v1d_cast_v2d(a) (a)
#define v1f_cast_v2f(a) (a)
#define v1i_cast_v2i(a) (a)
#define v1l_cast_v2l(a) (a)
#define v2f_cast_v4f(a) (a)
#define v2i_cast_v4i(a) (a)

// Up Casts
#undef v2d_cast_v1d
#undef v2f_cast_v1f
#undef v2i_cast_v1i
#undef v2l_cast_v1l
#undef v4f_cast_v2f
#undef v4i_cast_v2i
#define v2d_cast_v1d(a) (a)
#define v2f_cast_v1f(a) (a)
#define v2i_cast_v1i(a) (a)
#define v2l_cast_v1l(a) (a)
#define v4f_cast_v2f(a) (a)
#define v4i_cast_v2i(a) (a)

// Transtype Casts

// 128 bits
#undef v2d_cast_v2d
#undef v2d_cast_v4f
#undef v2d_cast_v4i
#undef v2d_cast_v2l
#undef v4f_cast_v2d
#undef v4f_cast_v4f
#undef v4f_cast_v4i
#undef v4f_cast_v2l
#undef v4i_cast_v2d
#undef v4i_cast_v4f
#undef v4i_cast_v4i
#undef v4i_cast_v2l
#undef v2l_cast_v2d
#undef v2l_cast_v4f
#undef v2l_cast_v4i
#undef v2l_cast_v2l

#define v2d_cast_v2d(a) (a)
#define v2d_cast_v4f(a) _mm_castps_pd(a)
#define v2d_cast_v4i(a) _mm_castsi128_pd(a)
#define v2d_cast_v2l(a) _mm_castsi128_pd(a)
#define v4f_cast_v2d(a) _mm_castpd_ps(a)
#define v4f_cast_v4f(a) (a)
#define v4f_cast_v4i(a) _mm_castsi128_ps(a)
#define v4f_cast_v2l(a) _mm_castsi128_ps(a)
#define v4i_cast_v2d(a) _mm_castpd_si128(a)
#define v4i_cast_v4f(a) _mm_castps_si128(a)
#define v4i_cast_v4i(a) (a)
#define v4i_cast_v2l(a) (a)
#define v2l_cast_v2d(a) _mm_castpd_si128(a)
#define v2l_cast_v4f(a) _mm_castps_si128(a)
#define v2l_cast_v4i(a) (a)
#define v2l_cast_v2l(a) (a)

// 64 bits
#undef v1d_cast_v1d
#undef v1d_cast_v2f
#undef v1d_cast_v2i
#undef v1d_cast_v1l
#undef v2f_cast_v1d
#undef v2f_cast_v2f
#undef v2f_cast_v2i
#undef v2f_cast_v1l
#undef v2i_cast_v1d
#undef v2i_cast_v2f
#undef v2i_cast_v2i
#undef v2i_cast_v1l
#undef v1l_cast_v1d
#undef v1l_cast_v2f
#undef v1l_cast_v2i
#undef v1l_cast_v1l

#define v1d_cast_v1d(a) (a)
#define v1d_cast_v2f(a) _mm_castps_pd(a)
#define v1d_cast_v2i(a) _mm_castsi128_pd(a)
#define v1d_cast_v1l(a) _mm_castsi128_pd(a)
#define v2f_cast_v1d(a) _mm_castpd_ps(a)
#define v2f_cast_v2f(a) (a)
#define v2f_cast_v2i(a) _mm_castsi128_ps(a)
#define v2f_cast_v1l(a) _mm_castsi128_ps(a)
#define v2i_cast_v1d(a) _mm_castpd_si128(a)
#define v2i_cast_v2f(a) _mm_castps_si128(a)
#define v2i_cast_v2i(a) (a)
#define v2i_cast_v1l(a) (a)
#define v1l_cast_v1d(a) _mm_castpd_si128(a)
#define v1l_cast_v2f(a) _mm_castps_si128(a)
#define v1l_cast_v2i(a) (a)
#define v1l_cast_v1l(a) (a)

// 32 bits
#undef v1f_cast_v1f
#undef v1f_cast_v1i
#undef v1i_cast_v1f
#undef v1i_cast_v1i

#define v1f_cast_v1f(a) (a)
#define v1f_cast_v1i(a) _mm_castsi128_ps(a)
#define v1i_cast_v1f(a) _mm_castps_si128(a)
#define v1i_cast_v1i(a) (a)


// Conversions
#undef v4f_cvt_v4f
#undef v4f_cvt_v4i
#undef v4i_cvt_v4f
#undef v4i_cvt_v4i
#undef v2d_cvt_v2d
#undef v2f_cvt_v2d
#undef v2i_cvt_v2d
#undef v2l_cvt_v2d
#undef v2d_cvt_v2f
#undef v2f_cvt_v2f
#undef v2i_cvt_v2f
#undef v2l_cvt_v2f
#undef v2d_cvt_v2i
#undef v2f_cvt_v2i
#undef v2i_cvt_v2i
#undef v2l_cvt_v2i
#undef v2d_cvt_v2l
#undef v2f_cvt_v2l
#undef v2i_cvt_v2l
#undef v2l_cvt_v2l
#undef v1d_cvt_v1d
#undef v1f_cvt_v1d
#undef v1i_cvt_v1d
#undef v1l_cvt_v1d
#undef v1d_cvt_v1f
#undef v1f_cvt_v1f
#undef v1i_cvt_v1f
#undef v1l_cvt_v1f
#undef v1d_cvt_v1i
#undef v1f_cvt_v1i
#undef v1i_cvt_v1i
#undef v1l_cvt_v1i
#undef v1d_cvt_v1l
#undef v1f_cvt_v1l
#undef v1i_cvt_v1l
#undef v1l_cvt_v1l


#define v4f_cvt_v4f(a) (a)
#define v4f_cvt_v4i(a) _mm_cvtepi32_ps(a)
#define v4i_cvt_v4f(a) _mm_cvtps_epi32(a)
#define v4i_cvt_v4i(a) (a)
#define v2d_cvt_v2d(a) (a)
#define v2f_cvt_v2d(a) _mm_cvtpd_ps(a)
#define v2i_cvt_v2d(a) _mm_cvtpd_epi32(a)
#define v2l_cvt_v2d(a) compatible_v2l_cvt_v2d(a)
#define v2d_cvt_v2f(a) _mm_cvtps_pd(a)
#define v2f_cvt_v2f(a) (a)
#define v2i_cvt_v2f(a) _mm_cvtps_epi32(a)
#define v2l_cvt_v2f(a) compatible_v2l_cvt_v2f(a)
#define v2d_cvt_v2i(a) _mm_cvtepi32_pd(a)
#define v2f_cvt_v2i(a) _mm_cvtepi32_ps(a)
#define v2i_cvt_v2i(a) (a)
#define v2l_cvt_v2i(a) _mm_cvtepi32_epi64(a)
#define v2d_cvt_v2l(a) compatible_v2d_cvt_v2l(a)
#define v2f_cvt_v2l(a) compatible_v2f_cvt_v2l(a)
#define v2i_cvt_v2l(a) compatible_v2i_cvt_v2l(a)
#define v2l_cvt_v2l(a) (a)
#define v1d_cvt_v1d(a) (a)
#define v1f_cvt_v1d(a) v2f_cvt_v2d(a)
#define v1i_cvt_v1d(a) v2i_cvt_v2d(a)
#define v1l_cvt_v1d(a) compatible_v1l_cvt_v1d(a)
#define v1d_cvt_v1f(a) v2d_cvt_v2f(a)
#define v1f_cvt_v1f(a) (a)
#define v1i_cvt_v1f(a) v2i_cvt_v2f(a)
#define v1l_cvt_v1f(a) compatible_v1l_cvt_v1f(a)
#define v1d_cvt_v1i(a) v2d_cvt_v2i(a)
#define v1f_cvt_v1i(a) v2f_cvt_v2i(a)
#define v1i_cvt_v1i(a) (a)
#define v1l_cvt_v1i(a) v2l_cvt_v2i(a)
#define v1d_cvt_v1l(a) compatible_v1d_cvt_v1l(a)
#define v1f_cvt_v1l(a) compatible_v1f_cvt_v1l(a)
#define v1i_cvt_v1l(a) compatible_v1i_cvt_v1l(a)
#define v1l_cvt_v1l(a) (a)


// Default get_high get_low, sethigh, setlow, merge
#undef v1d_get_high_v2d
#undef v2f_get_high_v4f
#undef v2i_get_high_v4i
#undef v1l_get_high_v2l
#undef v1f_get_high_v2f
#undef v1i_get_high_v2i
#undef v1d_get_low_v2d
#undef v2f_get_low_v4f
#undef v2i_get_low_v4i
#undef v1l_get_low_v2l
#undef v1f_get_low_v2f
#undef v1i_get_low_v2i
#undef v1d_get_hilo_v2d
#undef v2f_get_hilo_v4f
#undef v2i_get_hilo_v4i
#undef v1l_get_hilo_v2l
#undef v1f_get_hilo_v2f
#undef v1i_get_hilo_v2i
#undef v2d_set_high_v1d
#undef v4f_set_high_v2f
#undef v4i_set_high_v2i
#undef v2l_set_high_v1l
#undef v2f_set_high_v1f
#undef v2i_set_high_v1i
#undef v2d_set_low_v1d
#undef v4f_set_low_v2f
#undef v4i_set_low_v2i
#undef v2l_set_low_v1l
#undef v2f_set_low_v1f
#undef v2i_set_low_v1i
#undef v2d_merge2_v1d
#undef v4f_merge2_v2f
#undef v4i_merge2_v2i
#undef v2l_merge2_v1l
#undef v2f_merge2_v1f
#undef v2i_merge2_v1i

#define v1d_get_high_v2d(a)       v1d_cast_v2d(v2d_permute2(a, 0x1))
#define v2f_get_high_v4f(a)       v2f_cast_v4f(v4f_permute4(a, 0xE))
#define v2i_get_high_v4i(a)       v2i_cast_v4i(v4i_permute4(a, 0xE))
#define v1l_get_high_v2l(a)       v1l_cast_v2l(v2l_permute2(a, 0x1))
#define v1f_get_high_v2f(a)       v2f_cast_v4f(v4f_permute4(v4f_cast_v2f(a), 0x1))
#define v1i_get_high_v2i(a)       v2i_cast_v4i(v4i_permute4(v4i_cast_v2i(a), 0x1))
#define v1d_get_low_v2d(a)        v1d_cast_v2d(a)
#define v2f_get_low_v4f(a)        v2f_cast_v4f(a)
#define v2i_get_low_v4i(a)        v2i_cast_v4i(a)
#define v1l_get_low_v2l(a)        v1l_cast_v2l(a)
#define v1f_get_low_v2f(a)        v1f_cast_v2f(a)
#define v1i_get_low_v2i(a)        v1i_cast_v2i(a)
#define v1d_get_hilo_v2d(a, h)    v1d_cast_v2d(v2d_permute2(a, (h) & 1))
#define v2f_get_hilo_v4f(a, h)    v2f_cast_v4f(v4f_permute4(a, (((h) & 1) << 1) | (((h) & 1) << 3) | 0x4))
#define v2i_get_hilo_v4i(a, h)    v2i_cast_v4i(v4i_permute4(a, (((h) & 1) << 1) | (((h) & 1) << 3) | 0x4))
#define v1l_get_hilo_v2l(a, h)    v1l_cast_v2l(v2l_permute2(a, (h) & 1))
#define v1f_get_hilo_v2f(a, h)    v1f_cast_v4f(v4f_permute4(a, (h) & 1))
#define v1i_get_hilo_v2i(a, h)    v1i_cast_v4i(v4i_permute4(a, (h) & 1))
#define v2d_set_high_v1d(src, a)  v2d_hshuffle2(src, v2d_cast_v1d(a), 0x0)
#define v4f_set_high_v2f(src, a)  v4f_hshuffle4(src, v4f_cast_v2f(a), 0x44)
#define v4i_set_high_v2i(src, a)  v4i_hshuffle4(src, v4i_cast_v2i(a), 0x44)
#define v2l_set_high_v1l(src, a)  v2l_hshuffle2(src, v2l_cast_v1l(a), 0x0)
#define v2f_set_high_v1f(src, a)  v2f_merge2_v1f(v1f_get_low_v2f(src), a)
#define v2i_set_high_v1i(src, a)  v2i_merge2_v1i(v1i_get_low_v2i(src), a)
#define v2d_set_low_v1d(src, a)   v2d_hshuffle2(v2d_cast_v1d(a), src, 0x2)
#define v4f_set_low_v2f(src, a)   v4f_hshuffle4(v4f_cast_v2f(a), src, 0xE4)
#define v4i_set_low_v2i(src, a)   v4i_hshuffle4(v4i_cast_v2i(a), src, 0xE4)
#define v2l_set_low_v1l(src, a)   v2l_hshuffle2(v2l_cast_v1l(a), src, 0x2)
#define v2f_set_low_v1f(src, a)   v2f_merge2_v1f(a, v1f_get_high_v2f(src))
#define v2i_set_low_v1i(src, a)   v2i_merge2_v1i(a, v1i_get_high_v2i(src))
#define v2d_merge2_v1d(a, b)      v2d_hshuffle2(v2d_cast_v1d(a), v2d_cast_v1d(b), 0x0)
#define v4f_merge2_v2f(a, b)      v4f_hshuffle4(v4f_cast_v2f(a), v4f_cast_v2f(b), 0x44)
#define v4i_merge2_v2i(a, b)      v4i_hshuffle4(v4i_cast_v2i(a), v4i_cast_v2i(b), 0x44)
#define v2l_merge2_v1l(a, b)      v2l_hshuffle2(v2l_cast_v1l(a), v2l_cast_v1l(b), 0x0)
#define v2f_merge2_v1f(a, b)      _mm_unpacklo_ps(a, b)
#define v2i_merge2_v1i(a, b)      _mm_unpacklo_epi32(a, b)

static inline v2l __sse2_v2l_eq(v2l a, v2l b) {
  v4i cmp = v4i_eq(v4i_cast_v2l(a), v4i_cast_v2l(b));
  return v2l_cast_v4i(v4i_and(cmp, v4i_permute4(cmp, 0xB1)));
}

static inline v2l __sse2_v2l_gt(v2l a, v2l b) {
  v4i cmpeq = v4i_eq(v4i_cast_v2l(a), v4i_cast_v2l(b));
  v4i cmpgt = v4i_gt(v4i_cast_v2l(a), v4i_cast_v2l(b));
  v4i high_eq = v4i_permute4(cmpeq, 0xF5);
  v4i high_gt = v4i_permute4(cmpgt, 0xF5);
  v4i  low_gt = v4i_permute4(cmpgt, 0xA0);
  return v2l_cast_v4i(v4i_or(high_gt, v4i_and(high_eq, low_gt)));
}

static inline v2l __sse2_v2l_lt(v2l a, v2l b) {
  v4i cmpeq = v4i_eq(v4i_cast_v2l(a), v4i_cast_v2l(b));
  v4i cmplt = v4i_lt(v4i_cast_v2l(a), v4i_cast_v2l(b));
  v4i high_eq = v4i_permute4(cmpeq, 0xF5);
  v4i high_lt = v4i_permute4(cmplt, 0xF5);
  v4i  low_lt = v4i_permute4(cmplt, 0xA0);
  return v2l_cast_v4i(v4i_or(high_lt, v4i_and(high_eq, low_lt)));
}

#endif

#ifdef PINTS_SSSE3
#undef v4i_abs
#define v4i_abs(a) _mm_abs_epi32(a, b)
#endif

#ifdef PINTS_SSE41

#undef v4i_mul
#define v4i_mul(a, b) _mm_mullo_epi32(a, b)

#undef v4i_is_zero
#undef v2l_is_zero
#define v4i_is_zero(a) _mm_test_all_zeros(a, a)
#define v2l_is_zero(a) _mm_test_all_zeros(a, a)

#undef v2l_eq
#define v2l_eq(a, b) _mm_cmpeq_epi64(a, b)

#undef v4i_min
#define v4i_min(a, b) _mm_min_epi32(a, b)

#undef v4i_max
#define v4i_max(a, b) _mm_max_epi32(a, b)

#undef v1d_mask_move
#undef v2d_mask_move
#undef v1f_mask_move
#undef v2f_mask_move
#undef v4f_mask_move
#undef v1i_mask_move
#undef v2i_mask_move
#undef v4i_mask_move
#undef v1l_mask_move
#undef v2l_mask_move

#define v1d_mask_move(mask, src, a) v2d_mask_move(mask, src, a)
#define v2d_mask_move(mask, src, a) _mm_blendv_pd(src, a, mask)
#define v1f_mask_move(mask, src, a) v4f_mask_move(mask, src, a)
#define v2f_mask_move(mask, src, a) v4f_mask_move(mask, src, a)
#define v4f_mask_move(mask, src, a) _mm_blendv_ps(src, a, mask)
#define v1i_mask_move(mask, src, a) v4i_mask_move(mask, src, a)
#define v2i_mask_move(mask, src, a) v4i_mask_move(mask, src, a)
#define v4i_mask_move(mask, src, a) v4i_cast_v4f(v4f_mask_move(v4f_cast_v4i(mask), v4f_cast_v4i(src), v4f_cast_v4i(a)))
#define v1l_mask_move(mask, src, a) v2l_mask_move(mask, src, a)
#define v2l_mask_move(mask, src, a) v2l_cast_v2d(v2d_mask_move(v2d_cast_v2l(mask), v2d_cast_v2l(src), v2d_cast_v2l(a)))

#undef v2d_blend2
#undef v4f_blend2
#undef v4f_blend4
#undef v4i_blend2
#undef v4i_blend4
#undef v2l_blend2
#define v2d_blend2(a, b, mask) _mm_blend_pd(a, b, mask)
#define v4f_blend2(a, b, mask) v4f_blend4(a, b, (((mask) & 3) << 2) | ((mask) & 3))
#define v4f_blend4(a, b, mask) _mm_blend_ps(a, b, mask)
#define v4i_blend2(a, b, mask) v4i_blend4(a, b, (((mask) & 3) << 2) | ((mask) & 3))
#define v4i_blend4(a, b, mask) _mm_blend_epi16(a, b, ((mask) & 1)|(((mask) & 1) << 1)|((((mask) >> 1) & 1) << 2)|((((mask) >> 1) & 1) << 3)|((((mask) >> 2) & 1) << 4)|((((mask) >> 2) & 1) << 5)|((((mask) >> 3) & 1) << 6)|((((mask) >> 3) & 1) << 7))
#define v2l_blend2(a, b, mask) v4i_blend4(a, b, (((mask) & 3) << 2) | ((mask) & 3))

#endif

#ifdef PINTS_SSE42


#undef v2l_eq
#undef v2l_neq
#undef v2l_gt
#undef v2l_lt
#undef v2l_leq
#undef v2l_geq
#define v2l_eq(a, b)  _mm_cmpeq_epi64(a, b)
#define v2l_neq(a, b) v2l_not(v2l_eq(a, b))
#define v2l_gt(a, b)  _mm_cmpgt_epi64(a, b)
#define v2l_lt(a, b)  v2l_andnot(v2l_leq(a, b), v2l_eq(a, b))
#define v2l_leq(a, b) v2l_gt(b, a)
#define v2l_geq(a, b) v2l_lt(b, a)
#endif

#endif //PINTS_SSE_H
