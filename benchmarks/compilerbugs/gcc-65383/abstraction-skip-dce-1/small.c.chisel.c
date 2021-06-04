typedef unsigned int size_t;
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;
int printf(const char *, ...);
void __assert_fail(const char *__assertion, const char *__file,
                   unsigned int __line, const char *__function);
static void platform_main_end(uint32_t crc, int flag) {}
static int8_t(safe_unary_minus_func_int8_t_s)(int8_t si) {

  return

      -si;
}

static int8_t(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (si1 + si2);
}

static int8_t(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (si1 - si2);
}

static int8_t(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      si1 * si2;
}

static int8_t(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ? ((si1)) :

                                                         (si1 % si2);
}

static int8_t(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ? ((si1)) :

                                                         (si1 / si2);
}

static int8_t(safe_lshift_func_int8_t_s_s)(int8_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((127) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int8_t(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > ((127) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int8_t(safe_rshift_func_int8_t_s_s)(int8_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int8_t(safe_rshift_func_int8_t_s_u)(int8_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
}

static int16_t(safe_unary_minus_func_int16_t_s)(int16_t si) {

  return

      -si;
}

static int16_t(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      (si1 + si2);
}

static int16_t(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      (si1 - si2);
}

static int16_t(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      si1 * si2;
}

static int16_t(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      ((si2 == 0) || ((si1 == (-32767 - 1)) && (si2 == (-1)))) ? ((si1)) :

                                                               (si1 % si2);
}

static int16_t(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      ((si2 == 0) || ((si1 == (-32767 - 1)) && (si2 == (-1)))) ? ((si1)) :

                                                               (si1 / si2);
}

static int16_t(safe_lshift_func_int16_t_s_s)(int16_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((32767) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int16_t(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > ((32767) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int16_t(safe_rshift_func_int16_t_s_s)(int16_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int16_t(safe_rshift_func_int16_t_s_u)(int16_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
}

static int32_t(safe_unary_minus_func_int32_t_s)(int32_t si) {

  return

      (si == (-2147483647 - 1)) ? ((si)) :

                                -si;
}

static int32_t(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-2147483647 - 1) - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int32_t(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~(2147483647)))) - si2) ^ si2)) <
       0)
          ? ((si1))
          :

          (si1 - si2);
}

static int32_t(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < ((-2147483647 - 1) / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < ((-2147483647 - 1) / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((2147483647) / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int32_t(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      ((si2 == 0) || ((si1 == (-2147483647 - 1)) && (si2 == (-1)))) ? ((si1)) :

                                                                    (si1 % si2);
}

static int32_t(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      ((si2 == 0) || ((si1 == (-2147483647 - 1)) && (si2 == (-1)))) ? ((si1)) :

                                                                    (si1 / si2);
}

static int32_t(safe_lshift_func_int32_t_s_s)(int32_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((2147483647) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int32_t(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > ((2147483647) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int32_t(safe_rshift_func_int32_t_s_s)(int32_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int32_t(safe_rshift_func_int32_t_s_u)(int32_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
}
static uint8_t(safe_unary_minus_func_uint8_t_u)(uint8_t ui) { return -ui; }

static uint8_t(safe_add_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return ui1 + ui2;
}

static uint8_t(safe_sub_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return ui1 - ui2;
}

static uint8_t(safe_mul_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}

static uint8_t(safe_mod_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint8_t(safe_div_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint8_t(safe_lshift_func_uint8_t_u_s)(uint8_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((255) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint8_t(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > ((255) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint8_t(safe_rshift_func_uint8_t_u_s)(uint8_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint8_t(safe_rshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
}

static uint16_t(safe_unary_minus_func_uint16_t_u)(uint16_t ui) { return -ui; }

static uint16_t(safe_add_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return ui1 + ui2;
}

static uint16_t(safe_sub_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return ui1 - ui2;
}

static uint16_t(safe_mul_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}

static uint16_t(safe_mod_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint16_t(safe_div_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint16_t(safe_lshift_func_uint16_t_u_s)(uint16_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((65535) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint16_t(safe_lshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > ((65535) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint16_t(safe_rshift_func_uint16_t_u_s)(uint16_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint16_t(safe_rshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
}

static uint32_t(safe_unary_minus_func_uint32_t_u)(uint32_t ui) { return -ui; }

static uint32_t(safe_add_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return ui1 + ui2;
}

static uint32_t(safe_sub_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return ui1 - ui2;
}

static uint32_t(safe_mul_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}

static uint32_t(safe_mod_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint32_t(safe_div_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint32_t(safe_lshift_func_uint32_t_u_s)(uint32_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((4294967295U) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint32_t(safe_lshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > ((4294967295U) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint32_t(safe_rshift_func_uint32_t_u_s)(uint32_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint32_t(safe_rshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
}
static float(safe_add_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0.5f * sf1) + (0.5f * sf2)) >
       (0.5f * 3.40282346638528859812e+38F))
          ? (sf1)
          :

          (sf1 + sf2);
}

static float(safe_sub_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0.5f * sf1) - (0.5f * sf2)) >
       (0.5f * 3.40282346638528859812e+38F))
          ? (sf1)
          :

          (sf1 - sf2);
}

static float(safe_mul_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) >
       (0x1.0p-100f * (0x1.0p-28f * 3.40282346638528859812e+38F)))
          ?

          (sf1)
          :

          (sf1 * sf2);
}

static float(safe_div_func_float_f_f)(float sf1, float sf2) {

  return

      ((fabsf(sf2) < 1.0f) &&
       (((sf2 == 0.0f) ||
         (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) >
             (0x1.0p-100f * (0x1.0p-49f * 3.40282346638528859812e+38F)))))
          ?

          (sf1)
          :

          (sf1 / sf2);
}

static double(safe_add_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0.5 * sf1) + (0.5 * sf2)) >
       (0.5 * ((double)1.79769313486231570815e+308L)))
          ? (sf1)
          :

          (sf1 + sf2);
}

static double(safe_sub_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0.5 * sf1) - (0.5 * sf2)) >
       (0.5 * ((double)1.79769313486231570815e+308L)))
          ? (sf1)
          :

          (sf1 - sf2);
}

static double(safe_mul_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) >
       (0x1.0p-100 * (0x1.0p-924 * ((double)1.79769313486231570815e+308L))))
          ?

          (sf1)
          :

          (sf1 * sf2);
}

static double(safe_div_func_double_f_f)(double sf1, double sf2) {

  return

      ((fabs(sf2) < 1.0) &&
       (((sf2 == 0.0) ||
         (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) >
             (0x1.0p-100 *
              (0x1.0p-974 * ((double)1.79769313486231570815e+308L))))))
          ?

          (sf1)
          :

          (sf1 / sf2);
}
static int32_t(safe_convert_func_float_to_int32_t)(float sf1) {

  return

      ((sf1 <= (-2147483647 - 1)) || (sf1 >= (2147483647))) ? ((2147483647)) :

                                                            ((int32_t)(sf1));
}

static uint32_t crc32_tab[256];
static uint32_t crc32_context = 0xFFFFFFFFUL;

static void crc32_gentab(void) {
  uint32_t crc;
  const uint32_t poly = 0xEDB88320UL;
  int i, j;
}

static void crc32_8bytes(uint32_t val) {}

static void transparent_crc(uint32_t val, char *vname, int flag) {}
static void transparent_crc_bytes(char *ptr, int nbytes, char *vname,
                                  int flag) {
  int i;
}
static long __undefined;

static int32_t g_5 = (-10L);
static int16_t g_27[3][1] = {{5L}, {5L}, {5L}};
static uint32_t g_32[9][2] = {
    {4294967290UL, 0x520F3038L}, {6UL, 0x520F3038L},
    {4294967290UL, 6UL},         {0xD06F6293L, 0xD06F6293L},
    {0xD06F6293L, 6UL},          {4294967290UL, 0x520F3038L},
    {6UL, 0x520F3038L},          {4294967290UL, 6UL},
    {0xD06F6293L, 0xD06F6293L}};
static uint32_t g_33 = 0x2CD8491FL;
static int8_t g_34[10] = {0xF9L, 0xF9L, 0xF9L, 0xF9L, 0xF9L,
                          0xF9L, 0xF9L, 0xF9L, 0xF9L, 0xF9L};
static uint8_t g_35 = 0x2EL;
static volatile uint32_t g_44 = 4294967289UL;
static int16_t g_53 = 0x702BL;
static uint32_t g_86 = 0x19166C0CL;
static uint16_t g_108 = 65535UL;
static volatile uint32_t g_126 = 0x7CFDFC4DL;
static uint32_t g_127 = 1UL;
static uint8_t g_132 = 0xA8L;
static uint32_t g_183[10] = {0x3F7E2340L, 0x3F7E2340L, 0x3F7E2340L, 0x3F7E2340L,
                             0x3F7E2340L, 0x3F7E2340L, 0x3F7E2340L, 0x3F7E2340L,
                             0x3F7E2340L, 0x3F7E2340L};
static uint8_t g_185[2][9][3] = {{{0xBEL, 0x9FL, 0x9FL},
                                  {0xBEL, 0x9FL, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L}},
                                 {{0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L},
                                  {0x9FL, 0x44L, 0x44L}}};
static int16_t g_203 = (-9L);
static uint32_t g_247 = 0x34D8CA7FL;
static uint32_t g_250[1][5] = {{0UL, 0UL, 0UL, 0UL, 0UL}};
static uint32_t g_276 = 0UL;
static int16_t g_298 = 0L;
static int32_t g_315 = 0xA0711357L;
static uint32_t g_317 = 5UL;
static uint32_t g_318 = 0UL;
static int16_t g_344 = 0xB4C2L;
static uint16_t g_391 = 2UL;
static uint16_t g_400 = 65528UL;
static int8_t g_419 = 0xF8L;
static int32_t g_427[3] = {0x92A1D2CDL, 0x92A1D2CDL, 0x92A1D2CDL};
static uint32_t g_449 = 0xEA1D27C7L;
static uint8_t g_456 = 248UL;
static uint32_t g_486 = 0x2CAB0F51L;
static volatile uint32_t g_499 = 0xCCA17D6DL;
static uint16_t g_503 = 0x06D7L;
static uint16_t g_504[10][8][3] = {{{1UL, 0x4B63L, 0x3008L},
                                    {65535UL, 1UL, 0x3008L},
                                    {0xEF53L, 6UL, 0xAA53L},
                                    {0xA4E2L, 65535UL, 0x3008L},
                                    {0x4B63L, 6UL, 0x3008L},
                                    {6UL, 0xEF53L, 0xAA53L},
                                    {6UL, 5UL, 0x3008L},
                                    {5UL, 0xA4E2L, 0x3008L}},
                                   {{0xFFB4L, 0xFFB4L, 0xAA53L},
                                    {1UL, 0x4B63L, 0x3008L},
                                    {65535UL, 1UL, 0x3008L},
                                    {0xEF53L, 6UL, 0xAA53L},
                                    {0xA4E2L, 65535UL, 0x3008L},
                                    {0x4B63L, 6UL, 0x3008L},
                                    {6UL, 0xEF53L, 0xAA53L},
                                    {6UL, 5UL, 0x3008L}},
                                   {{5UL, 0xA4E2L, 0x3008L},
                                    {0xFFB4L, 0xFFB4L, 0xAA53L},
                                    {1UL, 0x4B63L, 0x3008L},
                                    {65535UL, 1UL, 0x3008L},
                                    {0xEF53L, 6UL, 0xAA53L},
                                    {0xA4E2L, 65535UL, 0x3008L},
                                    {0x4B63L, 6UL, 0x3008L},
                                    {6UL, 0xEF53L, 0xAA53L}},
                                   {{6UL, 5UL, 0x3008L},
                                    {5UL, 0xA4E2L, 0x3008L},
                                    {0xFFB4L, 0xFFB4L, 0xAA53L},
                                    {1UL, 0x4B63L, 0x3008L},
                                    {65535UL, 1UL, 0x3008L},
                                    {0xEF53L, 6UL, 0xAA53L},
                                    {0xA4E2L, 65535UL, 0x3008L},
                                    {0x4B63L, 6UL, 0x3008L}},
                                   {{6UL, 0xEF53L, 0xAA53L},
                                    {6UL, 5UL, 0x3008L},
                                    {5UL, 0xA4E2L, 0x3008L},
                                    {0xFFB4L, 0xFFB4L, 0xAA53L},
                                    {1UL, 0x4B63L, 0x3008L},
                                    {65535UL, 1UL, 0x3008L},
                                    {0xEF53L, 6UL, 0xAA53L},
                                    {0xA4E2L, 65535UL, 0x3008L}},
                                   {{0x4B63L, 6UL, 0x3008L},
                                    {6UL, 0xEF53L, 0xAA53L},
                                    {6UL, 5UL, 0x3008L},
                                    {5UL, 0xA4E2L, 0x3008L},
                                    {0xFFB4L, 0xFFB4L, 6UL},
                                    {0xF860L, 0x316FL, 0xEF53L},
                                    {0UL, 0xF860L, 0xEF53L},
                                    {65530UL, 0xE9B3L, 6UL}},
                                   {{0x2DF2L, 0UL, 0xEF53L},
                                    {0x316FL, 0UL, 0xEF53L},
                                    {0xE9B3L, 65530UL, 6UL},
                                    {0UL, 0x90F2L, 0xEF53L},
                                    {0x90F2L, 0x2DF2L, 0xEF53L},
                                    {6UL, 6UL, 6UL},
                                    {0xF860L, 0x316FL, 0xEF53L},
                                    {0UL, 0xF860L, 0xEF53L}},
                                   {{65530UL, 0xE9B3L, 6UL},
                                    {0x2DF2L, 0UL, 0xEF53L},
                                    {0x316FL, 0UL, 0xEF53L},
                                    {0xE9B3L, 65530UL, 6UL},
                                    {0UL, 0x90F2L, 0xEF53L},
                                    {0x90F2L, 0x2DF2L, 0xEF53L},
                                    {6UL, 6UL, 6UL},
                                    {0xF860L, 0x316FL, 0xEF53L}},
                                   {{0UL, 0xF860L, 0xEF53L},
                                    {65530UL, 0xE9B3L, 6UL},
                                    {0x2DF2L, 0UL, 0xEF53L},
                                    {0x316FL, 0UL, 0xEF53L},
                                    {0xE9B3L, 65530UL, 6UL},
                                    {0UL, 0x90F2L, 0xEF53L},
                                    {0x90F2L, 0x2DF2L, 0xEF53L},
                                    {6UL, 6UL, 6UL}},
                                   {{0xF860L, 0x316FL, 0xEF53L},
                                    {0UL, 0xF860L, 0xEF53L},
                                    {65530UL, 0xE9B3L, 6UL},
                                    {0x2DF2L, 0UL, 0xEF53L},
                                    {0x316FL, 0UL, 0xEF53L},
                                    {0xE9B3L, 65530UL, 6UL},
                                    {0UL, 0x90F2L, 0xEF53L},
                                    {0x90F2L, 0x2DF2L, 0xEF53L}}};
static int32_t g_566 = 0xB2D08BC0L;
static volatile int16_t g_577 = 2L;
static uint32_t g_639 = 0x5BF4443DL;
static uint32_t g_692 = 0x09391D9FL;
static int32_t g_693[2] = {0xCB57FED6L, 0xCB57FED6L};
static uint32_t g_739 = 0xD789D116L;
static volatile int8_t g_769 = 0x1EL;
static int16_t g_820 = 0L;
static int32_t g_897[2][3] = {{0xD7D9BB05L, 0xD7D9BB05L, 0xD7D9BB05L},
                              {(-1L), (-1L), (-1L)}};
static volatile int32_t g_918[5][2][9] = {
    {{3L, (-1L), 3L, 0x91CF556EL, 0L, 0xEAB8A1A6L, 0x91CF556EL, 0xED0869A6L,
      (-1L)},
     {(-1L), 0xED0869A6L, 0x91CF556EL, 0xEAB8A1A6L, 0L, 0x91CF556EL, 3L, (-1L),
      3L}},
    {{1L, 9L, 0x91CF556EL, 0x91CF556EL, 9L, 1L, 0xEAB8A1A6L, 0x8D07C015L,
      0x6320F129L},
     {1L, 0xED0869A6L, 3L, 1L, (-1L), 0x6320F129L, (-1L), 0x8D07C015L, 3L}},
    {{(-1L), (-1L), 0xEAB8A1A6L, 0x6320F129L, (-1L), 0x6320F129L, 0xEAB8A1A6L,
      (-1L), (-1L)},
     {3L, 0x8D07C015L, (-1L), 0x6320F129L, (-1L), 1L, 3L, 0xED0869A6L, 1L}},
    {{0x6320F129L, 0x8D07C015L, 0xEAB8A1A6L, 1L, 9L, 0x91CF556EL, 0x91CF556EL,
      9L, 1L},
     {3L, (-1L), 3L, 0x91CF556EL, 0L, 0xEAB8A1A6L, 0x91CF556EL, 0xED0869A6L,
      (-1L)}},
    {{(-1L), 0xED0869A6L, 0x91CF556EL, 0xEAB8A1A6L, (-1L), 0x1D3921EBL,
      0x385EB4D3L, 0L, 0x385EB4D3L},
     {4L, 0x91CF556EL, 0x1D3921EBL, 0x1D3921EBL, 0x91CF556EL, 4L, 0xB5D366A8L,
      3L, 0x5DC9BADBL}}};
static uint32_t g_972 = 0x3AAFA27AL;
static volatile uint32_t g_1001 = 0xD12476D2L;
static uint16_t g_1044 = 0x24BFL;
static volatile int16_t g_1045 = 0x8739L;
static int16_t g_1138 = 0xDCAAL;
static uint16_t g_1328 = 0x2078L;
static volatile uint32_t g_1357 = 0UL;
static int32_t g_1363 = 0x09F5684CL;
static int32_t g_1472 = (-1L);
static int8_t g_1669 = 8L;
static int32_t g_2084 = (-1L);
static int32_t g_2222 = 0x8FE31437L;
static volatile int32_t g_2236[6] = {0x0E7B8307L, 0x0E7B8307L, 0x0E7B8307L,
                                     0x0E7B8307L, 0x0E7B8307L, 0x0E7B8307L};
static volatile int8_t g_2610 = 0xB6L;
static volatile int16_t g_2674 = 0L;
static uint16_t g_2729[3][7] = {
    {65528UL, 0xB42CL, 1UL, 0xB42CL, 65528UL, 1UL, 1UL},
    {65528UL, 0xB42CL, 1UL, 0xB42CL, 65528UL, 1UL, 1UL},
    {65528UL, 0xB42CL, 1UL, 0xB42CL, 65528UL, 1UL, 1UL}};
static int32_t g_2942 = 0L;
static uint8_t g_3003 = 0x76L;
static int32_t g_3045[3][7] = {
    {0x26980768L, 0x26980768L, 0x26980768L, 0x26980768L, 0x26980768L,
     0x26980768L, 0x26980768L},
    {8L, 8L, 8L, 8L, 8L, 8L, 8L},
    {0x26980768L, 0x26980768L, 0x26980768L, 0x26980768L, 0x26980768L,
     0x26980768L, 0x26980768L}};
static volatile uint8_t g_3159[3][4][2] = {
    {{0x8AL, 0x8AL}, {0x8AL, 0x8AL}, {0x8AL, 0x8AL}, {0x8AL, 0x8AL}},
    {{0x8AL, 0x8AL}, {0x8AL, 0x8AL}, {0x8AL, 0x8AL}, {0x8AL, 0x8AL}},
    {{0x8AL, 0x8AL}, {0x8AL, 0x8AL}, {0x8AL, 0x8AL}, {0x8AL, 0x8AL}}};
static uint8_t g_3782 = 0xD9L;
static int16_t g_3901 = (-3L);
static volatile int8_t g_3903 = 0x93L;
static int32_t g_4123 = 4L;

static uint16_t func_1(void);
static uint8_t func_10(int16_t p_11, int8_t p_12);
static int8_t func_13(uint16_t p_14, int16_t p_15, int32_t p_16);
static int8_t func_17(int32_t p_18, uint8_t p_19, uint16_t p_20, int8_t p_21);
static uint16_t func_23(int32_t p_24);
static int8_t func_47(int16_t p_48);
static int16_t func_55(int16_t p_56);
inline static int16_t func_60(uint8_t p_61, uint8_t p_62);
static uint32_t func_64(int32_t p_65, int16_t p_66);
inline static int32_t func_70(int16_t p_71, uint8_t p_72);

static uint16_t func_1(void) {
  int16_t l_2 = 0x8A1FL;
  int16_t l_22 = (-1L);
  int32_t l_4309 = 0xCC5AFC00L;
  int32_t l_4310 = 0xDB3F08D2L;
  int32_t l_4311[3];
  uint32_t l_4312 = 4294967293UL;
  int i;

  g_2236[1] =
      ((l_2, (safe_add_func_int32_t_s_s(g_5, l_2))) >
       (l_4311[0] =
            (l_4310 =
                 (1L ==
                  (safe_lshift_func_uint16_t_u_u(
                      9UL,
                      (safe_mod_func_int32_t_s_s(
                          (((l_4309 =
                                 ((func_10(
                                       (func_13(
                                            g_5, g_5,
                                            (((func_17(
                                                   (g_35 =
                                                        (g_34[5] =
                                                             (l_22 &
                                                              (g_33 =
                                                                   (func_23((
                                                                        (((safe_lshift_func_uint16_t_u_u(
                                                                              ((g_27[2][0] =
                                                                                    g_5) <=
                                                                               l_2),
                                                                              9)) &
                                                                          0x9E17L),
                                                                         g_27[2]
                                                                             [0]) |
                                                                        g_5)),
                                                                    g_32[1]
                                                                        [0]))))),
                                                   g_5, g_5, g_5) <= 1L) !=
                                              g_5) <= l_2)),
                                        g_247),
                                       l_2),
                                   0xB8L) != l_22)),
                            255UL) >= g_3901),
                          g_3045[2][3]))))))));

  return g_2084;
}

static uint8_t func_10(int16_t p_11, int8_t p_12) {
  uint32_t l_4281[8] = {0x57F96573L, 0x57F96573L, 0x57F96573L, 0x57F96573L,
                        0x57F96573L, 0x57F96573L, 0x57F96573L, 0x57F96573L};
  int32_t l_4282 = 0x47CA2331L;
  int i;

  {
    int32_t l_4253 = 0x298E0FB6L;
    int32_t l_4256 = 0xE99E48B2L;
    uint8_t l_4307 = 255UL;

        l_4253 = ((((safe_sub_func_int32_t_s_s((5UL ^ l_4256), ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_uint16_t_u_s(1UL, 11)) && 0xD98578FCL) & 1L), (+(((safe_add_func_int32_t_s_s((l_4282 = (((safe_unary_minus_func_int32_t_s((g_897[0][2] = ((((safe_mod_func_int32_t_s_s((safe_add_func_int32_t_s_s((safe_rshift_func_int8_t_s_u((((safe_lshift_func_uint8_t_u_s(((safe_add_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((((g_427[1] = (safe_sub_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_s((l_4281[5] != (-2L)), 7)) <= (((((g_1472 >= g_2084) , g_317) | g_1044) < l_4281[5]) < g_203)), p_11))) , p_11) , l_4281[2]), 3)), g_504[1][1][2])) | l_4253), g_27[2][0])) , p_12) && l_4281[2]), 4)), (-10L))), 0x774942A1L)) , l_4281[3]) | 4294967295UL) || 0x3866562AL)))) != 0x91L) , p_12)), p_12)) || 1L) <= g_250[0][1])))) <= l_4256) >= 0x64BCL) != g_3003) , (-10L)) < p_12))) , 0xF0E3L) | g_1669) , p_11);
  }

  return p_12;
}

static int8_t func_13(uint16_t p_14, int16_t p_15, int32_t p_16) {
  int32_t l_4246 = 0L;
  int8_t l_4251 = 0x9DL;
  int32_t l_4252 = 0xE648F05DL;

  return g_344;
}

static int8_t func_17(int32_t p_18, uint8_t p_19, uint16_t p_20, int8_t p_21) {
  uint16_t l_38 = 5UL;
  int32_t l_49[7];
  uint32_t l_3367 = 7UL;
  int32_t l_3529 = 0xC57B773AL;
  int32_t l_3859 = (-8L);
  uint16_t l_3864 = 65535UL;
  uint8_t l_3883 = 0UL;
  uint32_t l_3899[4];
  uint32_t l_3900[10] = {2UL, 4294967287UL, 2UL, 4294967287UL,
                         2UL, 4294967287UL, 2UL, 4294967287UL,
                         2UL, 4294967287UL};
  int8_t l_3902 = (-1L);
  uint8_t l_3920 = 0x5FL;
  int32_t l_4026[8][10] = {
      {1L, (-1L), 0xCFB9124BL, (-1L), 1L, 0L, 7L, 0x71610FDFL, 7L, 0L},
      {1L, (-1L), 0xCFB9124BL, (-1L), 1L, 0L, 7L, 0x71610FDFL, 7L, 0L},
      {1L, (-1L), 0xCFB9124BL, (-1L), 1L, 0L, 7L, 0x71610FDFL, 7L, 0L},
      {1L, (-1L), 0xCFB9124BL, (-1L), 1L, 0L, 7L, 0x71610FDFL, 7L, 0L},
      {1L, (-1L), 0xCFB9124BL, (-1L), 1L, 0L, 7L, 0x71610FDFL, 7L, 0L},
      {1L, (-1L), 0xCFB9124BL, (-1L), 1L, 0L, 7L, 0x71610FDFL, 7L, 0L},
      {1L, (-1L), 0xCFB9124BL, (-1L), 1L, 0L, 7L, 0x71610FDFL, 7L, 0L},
      {1L, (-1L), 0xCFB9124BL, (-1L), 1L, 0L, 7L, 0x71610FDFL, 7L, 0L}};
  int32_t l_4070 = (-5L);
  int32_t l_4073 = 0L;
  int16_t l_4244 = 0L;
  int i, j;
  for (i = 0; i < 7; i++)
    l_49[i] = (-1L);
  for (i = 0; i < 4; i++)
    l_3899[i] = 0x95EF2DB8L;

  {
    uint32_t l_54 = 0x5309F33DL;
    int32_t l_3177 = 0x39EDE1A3L;
    int32_t l_3184 = 0x492AE369L;
    int32_t l_3187 = 0x18D23FFAL;
    int32_t l_3313 = 0x0372B97CL;
    uint32_t l_3316 = 4294967295UL;
    uint16_t l_3496 = 65531UL;
    uint32_t l_3534 = 0x7FC14EECL;
    int8_t l_3596 = (-1L);
    uint8_t l_3664[9][10][1] = {{{0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL}},
                                {{0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL}},
                                {{0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL}},
                                {{0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL}},
                                {{0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL}},
                                {{0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL}},
                                {{0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL}},
                                {{0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL}},
                                {{0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL},
                                 {0xC0L},
                                 {2UL}}};
    int32_t l_3680[3][2];
    uint32_t l_3704 = 0x260F5791L;
    int32_t l_3726 = 0x06134ACAL;
    int8_t l_4168 = (-6L);
    int16_t l_4221 = 0x4A0BL;
    int32_t l_4237 = 3L;
    int i, j, k;

    {}
  lbl_3520:
    for (p_21 = 0; (p_21 <= (-24)); p_21 = safe_sub_func_int32_t_s_s(p_21, 4)) {
      uint16_t l_52 = 0x102DL;
      int32_t l_3136 = 0x078473D5L;
      int32_t l_3228[9][1];
      int32_t l_3229 = (-7L);
      uint8_t l_3341 = 0xB6L;
      uint32_t l_3410 = 4UL;
      int i, j;

      {}
      g_53 = l_52;
      l_54 = p_21;

      {
        uint16_t l_3137[10][10] = {
            {65535UL, 0x714FL, 0x714FL, 65535UL, 0UL, 65528UL, 65535UL, 65528UL,
             0UL, 65535UL},
            {65528UL, 65535UL, 65528UL, 0UL, 65535UL, 0x714FL, 0x714FL, 65535UL,
             0UL, 65528UL},
            {0x45B7L, 0x45B7L, 0x85F2L, 65535UL, 1UL, 0x85F2L, 1UL, 65535UL,
             0x85F2L, 0x45B7L},
            {1UL, 0x714FL, 65528UL, 1UL, 0UL, 0UL, 1UL, 65528UL, 0x714FL, 1UL},
            {65528UL, 0x45B7L, 0x714FL, 0UL, 0x45B7L, 0UL, 0x714FL, 0x45B7L,
             65528UL, 65528UL},
            {1UL, 65535UL, 0x85F2L, 0x45B7L, 0x45B7L, 0x85F2L, 65535UL, 1UL,
             0x85F2L, 1UL},
            {0x45B7L, 0x714FL, 0UL, 0x45B7L, 0UL, 0x714FL, 0x45B7L, 65528UL,
             65528UL, 0x45B7L},
            {65528UL, 1UL, 0UL, 0UL, 1UL, 65528UL, 0x714FL, 1UL, 0x714FL,
             65528UL},
            {65535UL, 1UL, 0x85F2L, 1UL, 65535UL, 0x85F2L, 0x45B7L, 0x45B7L,
             0x85F2L, 65535UL},
            {65535UL, 0x714FL, 0x714FL, 65535UL, 0UL, 65528UL, 65535UL, 65528UL,
             0UL, 65535UL}};
        int32_t l_3160[1];
        int32_t l_3207 = 0xB7AA850CL;
        int32_t l_3227 = 0xCBA64E35L;
        int i, j;

        l_3160[i] = 0x4F1B40D7L;
        l_3136 =
            ((p_19 =
                  (((l_3137[5][3],
                     ((+(0xC1244286L ==
                         ((l_38 <
                           ((safe_rshift_func_int8_t_s_u(
                                ((safe_add_func_int16_t_s_s(
                                     ((safe_rshift_func_uint8_t_u_u(
                                          (safe_rshift_func_uint16_t_u_u(
                                              ((-1L) |
                                               (l_3160[0] =
                                                    (((safe_mod_func_int32_t_s_s(
                                                          (((p_19 &&
                                                             ((safe_lshift_func_uint16_t_u_s(
                                                                  ((l_49[3] =
                                                                        (g_456 =
                                                                             l_38)) &
                                                                   p_19),
                                                                  11)) <=
                                                              (safe_rshift_func_uint8_t_u_u(
                                                                  ((safe_add_func_uint32_t_u_u(
                                                                       ((g_1472 = (safe_lshift_func_int8_t_s_s(
                                                                             p_19,
                                                                             1))),
                                                                        (((safe_mod_func_uint32_t_u_u(
                                                                              (p_18 &&
                                                                               1UL),
                                                                              l_3136)),
                                                                          p_19) ==
                                                                         249UL)),
                                                                       p_21)) >
                                                                   l_3137[4]
                                                                         [3]),
                                                                  p_18)))) ||
                                                            p_18) >
                                                           l_3137[5][3]),
                                                          l_52)) >
                                                      g_3159[1][3][0]) <
                                                     g_2942))),
                                              l_52)),
                                          p_19)) < l_52),
                                     l_54)) &&
                                 p_19),
                                p_21)) == 65527UL)) != p_21))),
                      p_20)),
                    g_185[0][3][0]) ||
                   0xF47BL)) <= 0x01L);

        {
          int8_t l_3185 = 1L;
          int32_t l_3186 = (-1L);

          { int i; }
          l_3187 =
              (g_693[1] ||
               ((safe_lshift_func_int8_t_s_u(
                    (0x1552L <=
                     (g_53 =
                          ((safe_mod_func_int16_t_s_s(
                               ((safe_mod_func_int32_t_s_s(
                                    (safe_add_func_int8_t_s_s(
                                        (safe_lshift_func_uint8_t_u_u(
                                            (safe_lshift_func_uint16_t_u_u(1UL,
                                                                           7)),
                                            ((((safe_mod_func_uint32_t_u_u(
                                                   (l_3186 =
                                                        (l_3185 =
                                                             ((g_86 =
                                                                   (0L &&
                                                                    (g_3159
                                                                         [1][3]
                                                                         [0] ==
                                                                     (((l_3184 =
                                                                            ((safe_mod_func_int16_t_s_s(
                                                                                 (l_3177 =
                                                                                      0x59C5L),
                                                                                 (g_27[0]
                                                                                      [0] &
                                                                                  (((safe_lshift_func_int16_t_s_u(
                                                                                        ((safe_lshift_func_uint16_t_u_s(
                                                                                             (((((p_21 &
                                                                                                  g_1472) ^
                                                                                                 g_183
                                                                                                     [9]) &
                                                                                                g_1138) ^
                                                                                               g_183
                                                                                                   [5]) !=
                                                                                              (-7L)),
                                                                                             0)) ||
                                                                                         0L),
                                                                                        l_49[3])) &
                                                                                    g_2084) !=
                                                                                   l_3136)))),
                                                                             l_3136)) ==
                                                                       0xAC8D55A1L) <
                                                                      0xD267D03DL)))) &
                                                              l_3160[0]))),
                                                   g_35)) > g_185[0][8][1]) ==
                                              1UL) != 0x1D1A26F7L))),
                                        9L)),
                                    l_38)) > g_183[3]),
                               l_54)) &
                           251UL))),
                    g_2084)) > p_19));

          { uint16_t l_3206 = 0xAC21L; }
        }

        {
          uint8_t l_3213 = 0xEEL;
          int32_t l_3226 = (-2L);
          l_3136 =
              ((l_3136 & (g_344 = 1L)) >=
               (l_3229 =
                    (l_3228[3][0] = (+(
                         (safe_sub_func_uint16_t_u_u(
                             (l_3213 ||
                              (l_3160[0] =
                                   (((g_456,
                                      (safe_rshift_func_int8_t_s_s(
                                          ((l_3226 = (safe_add_func_uint8_t_u_u(
                                                (p_19 =
                                                     (((5UL !=
                                                        (g_918[4][0][2] >
                                                         (((safe_sub_func_int32_t_s_s(
                                                               g_566,
                                                               (safe_lshift_func_uint8_t_u_u(
                                                                   (safe_lshift_func_int16_t_s_u(
                                                                       (p_20 >=
                                                                        (safe_mod_func_int32_t_s_s(
                                                                            g_427
                                                                                [0],
                                                                            4294967287UL))),
                                                                       l_3137
                                                                           [7]
                                                                           [5])),
                                                                   p_21)))) &&
                                                           l_52) < l_49[1]))) &&
                                                       0x7EL) |
                                                      0x2F1FL)),
                                                g_2729[0][4]))) >= 0x0EL),
                                          5))) < 0xC4F36B91L) &
                                    65535UL))),
                             l_3227)) != p_20)))));

          break;

          break;
          l_3160[0] = (safe_rshift_func_uint16_t_u_s(
              (safe_lshift_func_uint8_t_u_s((1UL == p_21), 1)), 8));
        }
      }

      {
        uint8_t l_3378 = 0xF5L;
        int32_t l_3383 = 0x58D15DD0L;
        int32_t l_3435 = 0L;
        int32_t l_3498 = 1L;

        break;
        l_3136 =
            ((((safe_mod_func_int16_t_s_s(((-1L) >= (g_127 = 0xEB9EDD85L)),
                                          p_21)) &
               l_3187) >=
              ((g_2222 = (safe_sub_func_int16_t_s_s(
                    l_54,
                    (g_2222 !=
                     ((((l_3184 =
                             ((p_20 > ((safe_lshift_func_int16_t_s_s(
                                           (safe_unary_minus_func_uint32_t_u(
                                               (l_54 & g_419))),
                                           g_739)) <= 0xFAL)) < l_3367)) <=
                        l_3229) == l_3187) ||
                      g_897[0][2]))))) != 0x867D9309L)) <= 0x72L);

        {
          int16_t l_3422 = (-3L);
          int32_t l_3434 = 1L;
          int8_t l_3463 = 0L;
          int i, j, k;

          {
            int16_t l_3390 = 0xF395L;
            g_2236[1] = (((p_20 = (safe_lshift_func_int8_t_s_u(g_692, 3))) !=
                          ((safe_mod_func_uint32_t_u_u((p_18 <= (-6L)),
                                                       (l_3390 = l_3229))) |
                           (l_49[5] = ((l_3383 = (l_3184 = (-8L))), (!7L))))) <=
                         0x703F0452L);

            continue;
          }

          {
            int32_t l_3465 = 0x58567D96L;
            int32_t l_3494 = 0x591F0493L;
            int32_t l_3495 = (-4L);
            int32_t l_3497 = 0x333383BBL;
            l_3497 =
                (((~((p_20, g_897[0][2]) > l_3465)) <
                  (((((safe_rshift_func_uint16_t_u_u(
                          ((safe_add_func_uint32_t_u_u(
                               (l_3434 = (safe_rshift_func_int8_t_s_s(
                                    ((safe_mod_func_uint16_t_u_u(
                                         (((l_3495 =
                                                (((safe_rshift_func_uint16_t_u_s(
                                                      ((safe_sub_func_uint16_t_u_u(
                                                           ((p_21 >=
                                                             (safe_add_func_int16_t_s_s(
                                                                 ((safe_rshift_func_uint16_t_u_u(
                                                                      (((safe_lshift_func_uint16_t_u_s(
                                                                            (l_3184 =
                                                                                 0xA7EFL),
                                                                            7)) !=
                                                                        g_1044) !=
                                                                       p_20),
                                                                      11)) ==
                                                                  ((safe_sub_func_int32_t_s_s(
                                                                       g_44,
                                                                       (l_3494 =
                                                                            ((safe_unary_minus_func_int8_t_s((
                                                                                 (safe_add_func_uint8_t_u_u(
                                                                                     ((safe_mod_func_int8_t_s_s(
                                                                                          (safe_sub_func_int16_t_s_s(
                                                                                              ((!65526UL) ||
                                                                                               g_391),
                                                                                              l_3383)),
                                                                                          l_3367)) <
                                                                                      g_34[5]),
                                                                                     g_972)) >=
                                                                                 g_127))) &
                                                                             0x70C0L)))) <=
                                                                   g_692)),
                                                                 1UL))),
                                                            g_1138),
                                                           0x5AFEL)),
                                                       l_3341),
                                                      p_20)) > l_3422) !=
                                                 0x771EL)) ||
                                           g_35) &&
                                          0xF24EBB3EL),
                                         l_3496)) >= 0xB71ECC7FL),
                                    3))),
                               g_315)) == p_18),
                          g_34[6])),
                      0x54L) |
                     g_693[1]) ||
                    p_21) ||
                   g_132)) == 0x8A22BFF7L);
            l_49[6] =
                ((((l_3498 |
                    ((((((((g_250[0][1], ((+4UL) ^ (safe_sub_func_int16_t_s_s(
                                                       l_3136, 0L)))) !=
                           ((g_2729[2][6] = 0x0FBCL) | g_692)),
                          (!((((1L != (safe_sub_func_uint32_t_u_u(
                                          p_18, p_19))) < g_183[9]) &
                              g_127) < 0x2833D95DL))) > 0x667D3430L) ==
                        0xC7L) ||
                       l_3494) <= l_49[3]),
                     g_427[2])),
                   247UL) < p_19) <= 0xCD2BL);
          }
        }
      }
    }
    for (g_53 = 0; (g_53 != 13); ++g_53) {
      uint8_t l_3519 = 0xC3L;
      int32_t l_3593[5][9][5] = {
          {{(-1L), 5L, (-1L), 0xEFF4038FL, 0L},
           {(-10L), (-4L), 0x3D12D6ACL, 0x3D12D6ACL, 0xF7B9C197L},
           {2L, 0xEFF4038FL, 5L, 0xEFF4038FL, 2L},
           {0xF7B9C197L, 0x3D12D6ACL, 0x946D202EL, 0xF7B9C197L, (-4L)},
           {(-1L), 0xC8EA268AL, 5L, 0xEFF4038FL, 5L},
           {(-4L), (-4L), 0x4D03646FL, 0x3D12D6ACL, (-4L)},
           {(-9L), 0xEFF4038FL, (-9L), 0xC8EA268AL, 2L},
           {(-4L), 0x946D202EL, 0x946D202EL, (-4L), 0xF7B9C197L},
           {(-1L), 0xEFF4038FL, 0L, 0xEFF4038FL, (-1L)}},
          {{0xF7B9C197L, (-4L), 0x946D202EL, 0x946D202EL, (-4L)},
           {2L, 0xC8EA268AL, (-9L), 0xEFF4038FL, (-9L)},
           {(-4L), 0x3D12D6ACL, 0x4D03646FL, (-4L), (-4L)},
           {5L, 0xEFF4038FL, 5L, 0xC8EA268AL, (-1L)},
           {(-4L), 0xF7B9C197L, 0x946D202EL, 0x3D12D6ACL, 0xF7B9C197L},
           {2L, 0xEFF4038FL, 5L, 0xEFF4038FL, 2L},
           {0xF7B9C197L, 0x3D12D6ACL, 0x946D202EL, 0xF7B9C197L, (-4L)},
           {(-1L), 0xC8EA268AL, 5L, 0xEFF4038FL, 5L},
           {(-4L), (-4L), 0x4D03646FL, 0x3D12D6ACL, (-4L)}},
          {{(-9L), 0xEFF4038FL, (-9L), 0xC8EA268AL, 2L},
           {(-4L), 0x946D202EL, 0x946D202EL, (-4L), 0xF7B9C197L},
           {(-1L), 0xEFF4038FL, 0L, 0xEFF4038FL, (-1L)},
           {0xF7B9C197L, (-4L), 0x946D202EL, 0x946D202EL, (-4L)},
           {2L, 0xC8EA268AL, (-9L), 0xEFF4038FL, (-9L)},
           {(-4L), 0x3D12D6ACL, 0x4D03646FL, (-4L), (-4L)},
           {5L, 0xEFF4038FL, 5L, 0xC8EA268AL, (-1L)},
           {(-4L), 0xF7B9C197L, 0x946D202EL, 0x3D12D6ACL, 0xF7B9C197L},
           {2L, 0xEFF4038FL, 5L, 0xEFF4038FL, 2L}},
          {{0xF7B9C197L, 0x3D12D6ACL, 0x946D202EL, 0xF7B9C197L, (-4L)},
           {(-1L), 0xC8EA268AL, 5L, 0xEFF4038FL, 5L},
           {(-4L), (-4L), 0x4D03646FL, 0x3D12D6ACL, (-4L)},
           {(-9L), 0xEFF4038FL, (-9L), 0xC8EA268AL, 2L},
           {(-4L), 0x946D202EL, 0x946D202EL, (-4L), 0xF7B9C197L},
           {(-1L), 0xEFF4038FL, 0L, 0xEFF4038FL, (-1L)},
           {0xF7B9C197L, (-4L), 0x946D202EL, 0x946D202EL, (-4L)},
           {2L, 0xC8EA268AL, (-9L), 0xEFF4038FL, (-9L)},
           {(-4L), 0x3D12D6ACL, 0x4D03646FL, (-4L), (-4L)}},
          {{5L, 0xEFF4038FL, 5L, 0xC8EA268AL, (-1L)},
           {(-4L), 0xF7B9C197L, 0x946D202EL, 0x3D12D6ACL, 0xF7B9C197L},
           {2L, 0xEFF4038FL, 5L, 0xEFF4038FL, 2L},
           {0xF7B9C197L, 0x3D12D6ACL, 0x946D202EL, 0xF7B9C197L, 0xF7B9C197L},
           {5L, 5L, 0L, 0xC8EA268AL, 0L},
           {0xF7B9C197L, 0xF7B9C197L, 0x3D12D6ACL, 0x946D202EL, 0xF7B9C197L},
           {5L, 0xC8EA268AL, 5L, 5L, (-9L)},
           {0xF7B9C197L, 0x4D03646FL, 0x4D03646FL, 0xF7B9C197L, (-10L)},
           {5L, 0xC8EA268AL, (-1L), 0xC8EA268AL, 5L}}};
      int16_t l_3594 = 0L;
      int16_t l_3688 = 0x71C1L;
      int32_t l_3784[7] = {0x31260953L, 0x31260953L, 0x31260953L, 0x31260953L,
                           0x31260953L, 0x31260953L, 0x31260953L};
      uint32_t l_3884 = 0x6E5D0E77L;
      uint32_t l_3885 = 0x4294023EL;
      int16_t l_3940 = 0x152DL;
      int32_t l_3969 = (-1L);
      uint8_t l_4140 = 0x38L;
      int i, j, k;
      if (((((0xBEL >
              (p_19 =
                   (((safe_rshift_func_uint16_t_u_s(
                         (((g_317 =
                                (((((safe_rshift_func_uint8_t_u_u(
                                        (safe_sub_func_int16_t_s_s(
                                            1L,
                                            (g_298 =
                                                 (((((l_3367 && 1L) ==
                                                     65529UL) &
                                                    (safe_lshift_func_int8_t_s_s(
                                                        0xF3L, p_18))) |
                                                   (0xB00FL >
                                                    ((g_639 =
                                                          ((((((((safe_rshift_func_int16_t_s_u(
                                                                     ((g_486 <
                                                                       g_504
                                                                           [0]
                                                                           [7]
                                                                           [1]) >
                                                                      0xB2L),
                                                                     3)) ==
                                                                 g_400) &
                                                                l_3187) <
                                                               p_19) |
                                                              l_3519),
                                                             l_49[6]) &
                                                            4294967295UL) !=
                                                           g_203)) ||
                                                     0x21E34445L))) ==
                                                  l_49[5])))),
                                        5)) ^
                                    g_1138) <= g_247) != 0x8D8C20F0L) |
                                 p_21)),
                           0UL) <= l_3367),
                         l_3519)) ^
                     0x475E0D25L) >= p_20))) >= g_427[2]) <= p_21) <= p_21)) {
        return l_3519;
      } else {
        int32_t l_3525 = 0x3C905A4AL;
        int32_t l_3563 = 1L;

        {
          int8_t l_3559[8][10] = {
              {0x1AL, 0x6AL, 8L, 9L, 0x69L, 9L, 8L, 0x6AL, 0x1AL, (-1L)},
              {0L, (-1L), (-1L), 6L, 0L, 0x05L, 0x5BL, 0x69L, 0x69L, 0x5BL},
              {0x6AL, 0L, 6L, 6L, 0L, 0x6AL, 3L, 0x05L, 0x1AL, 0x4EL},
              {0x4EL, 0x69L, (-1L), 9L, (-1L), 8L, 0x6AL, 8L, (-1L), 9L},
              {0x4EL, 8L, 0x4EL, 0xDCL, 0x5BL, 0x6AL, 9L, 0L, (-1L), 0x05L},
              {0x6AL, 9L, 0L, (-1L), 0x05L, 0x05L, (-1L), 0L, 9L, 0x6AL},
              {0L, 0xABL, 0x4EL, 0x69L, (-1L), 9L, (-1L), 8L, 0x6AL, 8L},
              {0x1AL, 0x4EL, (-1L), 0xABL, (-1L), 0x4EL, 0x1AL, 0x05L, 3L,
               0x6AL}};
          int i, j;
        }

        printf("index = [%d][%d][%d]\n", i, j, k);

        printf("index = [%d]\n", i);
      }

      {
        int32_t l_3633 = 0xA391FEF8L;
        int32_t l_3634 = (-1L);
        int8_t l_3635 = 0xD4L;
        int16_t l_3663[3];
        int32_t l_3665 = 0xEA6BB433L;
        uint8_t l_3666 = 0xE2L;
        uint16_t l_3667 = 0x217AL;
        uint32_t l_3669[4] = {0UL, 0UL, 0UL, 0UL};
        int i;
      }

      safe_sub_func_int8_t_s_s(0x61L, (~((-1L) >= g_2674)));

      safe_rshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(p_21, p_20)),
                                   12);

      safe_unary_minus_func_uint32_t_u(g_185[g_566][g_400][(g_566 + 1)]);

      safe_mod_func_uint16_t_u_u(
          (g_2729[2][0] =
               (g_108 = l_3593[(g_503 + 2)][(g_503 + 8)][(g_503 + 3)])),
          (((safe_sub_func_int8_t_s_s((l_3184 = g_183[(g_503 + 6)]),
                                      (5UL & g_183[g_692]))),
            3UL),
           1L));
    }
  }

  return g_3903;
}

static uint16_t func_23(int32_t p_24) {
  uint16_t l_30 = 0x8DACL;
  int32_t l_31 = 7L;

  return l_30;
}

static int8_t func_47(int16_t p_48) { return p_48; }

static int16_t func_55(int16_t p_56) {
  int32_t l_63[4];
  uint32_t l_67 = 0x881DD571L;
  uint32_t l_77 = 5UL;
  int32_t l_457 = (-5L);
  int16_t l_2447 = 0xD223L;
  int32_t l_2489[8][7][4] = {
      {{5L, 0xB3796EC0L, 0xA8CF5080L, 0x65CC8092L},
       {1L, 1L, 0x880EE9C9L, 0xEA7F3B28L},
       {(-1L), 0x00752643L, (-1L), 7L},
       {(-7L), 0xE32AC911L, 0xA1313BFAL, 0x00752643L},
       {0x80964293L, 0L, 9L, 0x2BD0FE56L},
       {(-1L), 0x90A9627CL, (-1L), 0x234F6171L},
       {0x773F6E52L, 7L, 0x2BD0FE56L, 0x405263F4L}},
      {{1L, 5L, 1L, 3L},
       {0x51FDB2D6L, 0x443D343BL, 0xDDF431BAL, 0L},
       {0x6D626025L, 0x46304E9EL, 0x46304E9EL, 0x6D626025L},
       {0xA1313BFAL, 0x8062EF52L, 0x62D39AA5L, (-1L)},
       {5L, 0x00752643L, 0x2897B070L, 1L},
       {0L, 0xE81CF190L, 1L, 1L},
       {1L, 0x00752643L, (-3L), (-1L)}},
      {{(-1L), 0x8062EF52L, 0x1CA8CA73L, 0x6D626025L},
       {3L, 0x46304E9EL, 9L, 0L},
       {0x5833539CL, 0x443D343BL, 0x285F9C6AL, 3L},
       {1L, 5L, 0x92730339L, 0x405263F4L},
       {6L, 7L, 0xA8CF5080L, 0x234F6171L},
       {0x285F9C6AL, 0x90A9627CL, 0x62D39AA5L, 0x2BD0FE56L},
       {0x6D626025L, 0L, 0L, 0x00752643L}},
      {{0x00752643L, 0xE32AC911L, 0x5833539CL, 7L},
       {0x285F9C6AL, 0x00752643L, 0L, 0xEA7F3B28L},
       {0L, 1L, 0x92730339L, 0x65CC8092L},
       {0x773F6E52L, 0xB3796EC0L, (-3L), 2L},
       {0x5833539CL, 0x234F6171L, 0xA1313BFAL, 9L},
       {0L, 1L, 0x1CA8CA73L, 0L},
       {0xE08322CAL, 0x3AFB4DDBL, 7L, 0x234F6171L}},
      {{1L, 0x405263F4L, 0x880EE9C9L, (-3L)},
       {6L, 0x51FDB2D6L, 0x2897B070L, 9L},
       {0x51FDB2D6L, 0x3AFB4DDBL, 0x5833539CL, 0L},
       {0xA1313BFAL, 0L, (-9L), 9L},
       {1L, 0x8062EF52L, 0xDDF431BAL, (-1L)},
       {0x405263F4L, 0xB3796EC0L, 0L, 8L},
       {1L, 0L, 1L, 0xEA7F3B28L}},
      {{1L, 0x6D626025L, (-1L), 2L},
       {0xE08322CAL, 0xE32AC911L, 0xB3796EC0L, 0x6D626025L},
       {0x80964293L, 0x7B0502EAL, 0L, 0xE3C9401AL},
       {0x880EE9C9L, 0L, 1L, 9L},
       {0x6D38A7DCL, 0L, 0x299AC7DAL, 8L},
       {0x299AC7DAL, 8L, 0x74065357L, 0L},
       {0x03E1CD81L, 1L, 0L, 0xE32AC911L}},
      {{0x80964293L, 0x0FF90146L, 0x15056D7FL, 0x80964293L},
       {0x12137BD5L, 0xB3796EC0L, 0x9876EC10L, 0xEDBA69ACL},
       {8L, 0x46304E9EL, (-1L), 0x285F9C6AL},
       {0xE32AC911L, 0x6A0A3D74L, 0xAC201413L, 7L},
       {1L, 0x80964293L, 0L, 0xEDBA69ACL},
       {0x880EE9C9L, 9L, 3L, (-9L)},
       {0xEA7F3B28L, 0x0FF90146L, 0x12137BD5L, 3L}},
      {{0x9876EC10L, 0L, 0x3CC5F57CL, 0L},
       {0x5833539CL, 0x03E1CD81L, 0x8062EF52L, 0xE81CF190L},
       {5L, 0L, 0x74065357L, 0xA1313BFAL},
       {0x7BC3398BL, 0xA8CF5080L, 0x9876EC10L, 0xE3C9401AL},
       {(-9L), 1L, 8L, 0x80964293L},
       {0x46304E9EL, 0x1CA8CA73L, 0x92730339L, 0x3AFB4DDBL},
       {0x7BC3398BL, 0x80964293L, 0xDDF431BAL, 1L}}};
  uint32_t l_2522 = 0x14782674L;
  uint32_t l_2523 = 9UL;
  int8_t l_2524 = 1L;
  uint32_t l_2554 = 1UL;
  int32_t l_2670 = 0L;
  uint8_t l_2690 = 0xEEL;
  int32_t l_2704 = 0L;
  uint16_t l_2755 = 7UL;
  int16_t l_2896 = 0x5E6DL;
  int32_t l_3002[3][10] = {{2L, 2L, 2L, 2L, 2L, 2L, 2L, 2L, 2L, 2L},
                           {2L, 2L, 2L, 2L, 2L, 2L, 2L, 2L, 2L, 2L},
                           {2L, 2L, 2L, 2L, 2L, 2L, 2L, 2L, 2L, 2L}};
  int32_t l_3114 = 0x65DDE7BFL;
  int i, j, k;

  return l_2447;
}

inline static int16_t func_60(uint8_t p_61, uint8_t p_62) {
  int16_t l_2448 = 5L;
  uint16_t l_2449[5][5][8] = {
      {{0xB7EFL, 0x1191L, 65535UL, 1UL, 3UL, 3UL, 1UL, 65535UL},
       {0xF4B8L, 0xF4B8L, 0UL, 0xF3DCL, 0x31D1L, 65534UL, 0xD2A2L, 0x3025L},
       {65530UL, 0x011BL, 3UL, 0x1191L, 0UL, 65535UL, 0x17DBL, 0x3025L},
       {0x011BL, 65535UL, 0x2340L, 0xF3DCL, 65528UL, 0xFE1AL, 65527UL, 65535UL},
       {0xC804L, 0x4B97L, 0xB51BL, 1UL, 0x9CACL, 0x36EEL, 0x4A81L, 0UL}},
      {{0x17DBL, 1UL, 0x5DEAL, 0x2340L, 0xC804L, 65535UL, 65535UL, 0x31D1L},
       {65535UL, 0x2340L, 65528UL, 65526UL, 0x0FFCL, 65528UL, 65527UL, 0x1FCFL},
       {65526UL, 0xB7EFL, 0xF7E8L, 65535UL, 0xF4B8L, 1UL, 65531UL, 8UL},
       {0x2340L, 0x3025L, 3UL, 0x17DBL, 65535UL, 3UL, 0x2776L, 0xF3DCL},
       {1UL, 65528UL, 0x3275L, 0xC804L, 0x3275L, 65528UL, 1UL, 65535UL}},
      {{0xF3DCL, 65527UL, 0xDABEL, 0x011BL, 0xD2A2L, 8UL, 1UL, 0xF4B8L},
       {0x1191L, 1UL, 0xE0E4L, 65530UL, 0xD2A2L, 0x0FFCL, 0xF9C6L, 0xC804L},
       {0xF3DCL, 0x3275L, 6UL, 0xF4B8L, 0x55C5L, 0x0C54L, 0xFE1AL, 0xDABEL},
       {65535UL, 3UL, 0x4A81L, 0x17DBL, 0x2340L, 0x011BL, 0x16FFL, 65528UL},
       {0x36EEL, 0x1FCFL, 0xFB0DL, 1UL, 65535UL, 0xDABEL, 0xBBFCL, 65535UL}},
      {{0x1191L, 0x2C84L, 65526UL, 65535UL, 65534UL, 0UL, 0x2340L, 8UL},
       {0x2340L, 65535UL, 0x011BL, 0x2776L, 65535UL, 1UL, 6UL, 65535UL},
       {65526UL, 0xFE1AL, 0xF22DL, 0x7559L, 65535UL, 0xF7E8L, 0xF7E8L, 65535UL},
       {65535UL, 65526UL, 65526UL, 65535UL, 1UL, 0xB51BL, 65530UL, 0x0C54L},
       {0x1FCFL, 0xE0E4L, 0xF3DCL, 0x75B4L, 65528UL, 0x3025L, 0x16FFL,
        0x2776L}},
      {{8UL, 0xE0E4L, 0xDABEL, 0xF7E8L, 0xFE1AL, 0xB51BL, 0xFB0DL, 0x2340L},
       {65535UL, 65526UL, 0x2C84L, 0x1191L, 0UL, 0xF7E8L, 65535UL, 0xFB0DL},
       {0x17DBL, 0xFE1AL, 65535UL, 0x0FFCL, 0x75B4L, 1UL, 0x3275L, 0xE0E4L},
       {1UL, 65535UL, 0x88FDL, 0x477DL, 0x3275L, 0UL, 0x477DL, 3UL},
       {65535UL, 0x2C84L, 0x55C5L, 6UL, 0xFB0DL, 0xDABEL, 0xF9C6L, 0xBBFCL}}};
  int32_t l_2450 = 9L;
  int32_t l_2472 = 6L;
  int32_t l_2473 = 0x0E419DCBL;
  int32_t l_2474 = (-6L);
  int i, j, k;

  ;

  return g_504[1][1][2];
}

static uint32_t func_64(int32_t p_65, int16_t p_66) {
  uint16_t l_464 = 65535UL;
  uint8_t l_467[8][4][6] = {{{255UL, 0xF7L, 0x87L, 1UL, 0x13L, 255UL},
                             {255UL, 255UL, 255UL, 0UL, 0x31L, 0x8DL},
                             {1UL, 255UL, 1UL, 248UL, 251UL, 255UL},
                             {0x34L, 0xA3L, 248UL, 0UL, 4UL, 0UL}},
                            {{0xEFL, 0x31L, 0xEFL, 0x87L, 248UL, 255UL},
                             {255UL, 0x97L, 255UL, 0xA0L, 0xA3L, 0xF7L},
                             {0x13L, 255UL, 0xD3L, 0xA0L, 0xEFL, 0x87L},
                             {255UL, 0x13L, 1UL, 0x87L, 0xF7L, 255UL}},
                            {{0xEFL, 0x8DL, 0xA3L, 0UL, 0x31L, 0xE4L},
                             {0x34L, 0UL, 0x64L, 248UL, 248UL, 0x64L},
                             {1UL, 1UL, 248UL, 0UL, 0x89L, 0xF7L},
                             {255UL, 0x31L, 0x26L, 1UL, 8UL, 248UL}},
                            {{255UL, 255UL, 0x26L, 0x8DL, 1UL, 0xF7L},
                             {0UL, 0x8DL, 248UL, 0xE4L, 0xEFL, 0x64L},
                             {0xE4L, 0xEFL, 0x64L, 0x87L, 0x13L, 0xE4L},
                             {0x97L, 255UL, 0x0FL, 0UL, 0x0FL, 255UL}},
                            {{0x0FL, 0xF7L, 8UL, 0x31L, 1UL, 255UL},
                             {0x89L, 0x0FL, 0x31L, 0x64L, 0x8DL, 0x87L},
                             {0UL, 0x0FL, 0UL, 0xD3L, 1UL, 255UL},
                             {0x26L, 0xF7L, 0UL, 0xEFL, 0x0FL, 1UL}},
                            {{0x87L, 255UL, 0x34L, 0UL, 0x64L, 248UL},
                             {0xEFL, 255UL, 8UL, 8UL, 255UL, 0xEFL},
                             {0x13L, 0xEFL, 4UL, 0x64L, 0x89L, 255UL},
                             {252UL, 0UL, 255UL, 255UL, 1UL, 0xD3L}},
                            {{252UL, 0x5DL, 255UL, 0x64L, 0xE4L, 1UL},
                             {0x13L, 0x89L, 0UL, 8UL, 0x34L, 0xA3L},
                             {0xEFL, 0xF7L, 0xEFL, 0UL, 0x5DL, 0x64L},
                             {0x87L, 0xEFL, 0x31L, 0xEFL, 0x87L, 248UL}},
                            {{0x26L, 0x64L, 255UL, 0xD3L, 255UL, 0x26L},
                             {0UL, 0x97L, 252UL, 0x64L, 0x0FL, 0x26L},
                             {0x89L, 0x13L, 255UL, 0x31L, 0x34L, 248UL},
                             {0x0FL, 0x5DL, 0x31L, 0UL, 255UL, 0x64L}}};
  uint8_t l_471 = 248UL;
  int32_t l_480[8][8] = {{0L, 0L, 0x2D324052L, 0L, 0L, 0x2D324052L, 0L, 0L},
                         {(-1L), 0L, (-1L), (-1L), 0L, (-1L), (-1L), 0L},
                         {0L, (-1L), (-1L), 0L, (-1L), (-1L), 0L, (-1L)},
                         {0L, 0L, 0x2D324052L, 0L, 0L, 0x2D324052L, 0L, 0L},
                         {(-1L), 0L, (-1L), (-1L), 0L, (-1L), (-1L), 0L},
                         {0L, (-1L), (-1L), 0L, (-1L), (-1L), 0L, (-1L)},
                         {0L, 0L, 0x2D324052L, 0L, 0L, 0x2D324052L, 0L, 0L},
                         {(-1L), 0L, (-1L), (-1L), 0L, (-1L), (-1L), 0L}};
  uint16_t l_484 = 6UL;
  int8_t l_493 = 8L;
  int8_t l_524 = 0L;
  int32_t l_547 = (-1L);
  uint16_t l_578 = 0x4DC1L;
  uint32_t l_638 = 4294967288UL;
  int8_t l_803 = (-9L);
  int8_t l_819 = (-5L);
  int32_t l_821 = 0xB9B34874L;
  uint32_t l_845 = 1UL;
  int16_t l_896 = 2L;
  int16_t l_963 = 0L;
  int32_t l_1003[9] = {0x9F3D0B9CL, 0x9F3D0B9CL, 0x9F3D0B9CL,
                       0x9F3D0B9CL, 0x9F3D0B9CL, 0x9F3D0B9CL,
                       0x9F3D0B9CL, 0x9F3D0B9CL, 0x9F3D0B9CL};
  int32_t l_1004[9] = {(-1L),       0xA11D63BCL, (-1L),
                       0xA11D63BCL, (-1L),       0xA11D63BCL,
                       (-1L),       0xA11D63BCL, (-1L)};
  int32_t l_1005 = 0xE514720CL;
  int16_t l_1022[1];
  int32_t l_1238 = 0x98108A17L;
  uint32_t l_1283 = 0x73DC3D07L;
  uint8_t l_1284 = 0x18L;
  uint32_t l_1298 = 7UL;
  int32_t l_1325 = 0x6A9C04A7L;
  uint16_t l_1467[1][6][5] = {{{0UL, 0UL, 0UL, 0UL, 0UL},
                               {0x8240L, 0x6A46L, 1UL, 1UL, 0UL},
                               {0x5ED4L, 0UL, 0x5ED4L, 0x5ED4L, 0UL},
                               {0UL, 1UL, 1UL, 1UL, 1UL},
                               {0UL, 0UL, 0UL, 0UL, 0UL},
                               {1UL, 1UL, 1UL, 1UL, 0UL}}};
  uint16_t l_1635 = 0x316BL;
  int32_t l_1686[7];
  uint32_t l_1746[2];
  uint32_t l_1747 = 0x2A40B5CFL;
  int8_t l_1789 = (-1L);
  uint32_t l_1811 = 0xE94B7C56L;
  uint8_t l_1861 = 0x82L;
  int32_t l_1918[10] = {1L,          0x5351D12EL, 0x5351D12EL, 1L,
                        0x5351D12EL, 0x5351D12EL, 1L,          0x5351D12EL,
                        0x5351D12EL, 1L};
  uint32_t l_1948[8][2] = {
      {0xAEDFA23BL, 0xEC23F689L}, {0xEC23F689L, 0xAEDFA23BL},
      {0xEC23F689L, 0xEC23F689L}, {0xAEDFA23BL, 0xEC23F689L},
      {0xEC23F689L, 0xAEDFA23BL}, {0xEC23F689L, 0xEC23F689L},
      {0xAEDFA23BL, 0xEC23F689L}, {0xEC23F689L, 0xAEDFA23BL}};
  int32_t l_2003 = 6L;
  int16_t l_2016 = (-4L);
  int16_t l_2106[8][4];
  int8_t l_2288 = 0x12L;
  uint16_t l_2304 = 2UL;
  uint32_t l_2359 = 0UL;
  uint32_t l_2402 = 1UL;
  int i, j, k;

  return p_66;
}

inline static int32_t func_70(int16_t p_71, uint8_t p_72) {
  int32_t l_87 = 1L;
  int32_t l_110 = 0x9DAAC0CAL;
  uint16_t l_144 = 0UL;
  int32_t l_178 = 4L;
  uint8_t l_242 = 0x27L;
  uint32_t l_275 = 4294967289UL;
  uint32_t l_316[10] = {0xB55CD4BFL, 0xB55CD4BFL, 0xB55CD4BFL, 0xB55CD4BFL,
                        0xB55CD4BFL, 0xB55CD4BFL, 0xB55CD4BFL, 0xB55CD4BFL,
                        0xB55CD4BFL, 0xB55CD4BFL};
  uint16_t l_345 = 9UL;
  int i;

  { return g_126; }
}

int main(void) {
  int i, j, k;
  int print_hash_value = 0;

  func_1();

  return 0;
}
