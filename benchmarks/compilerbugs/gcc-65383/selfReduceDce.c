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

static int32_t(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-2147483647 - 1) - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int32_t(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      ((si2 == 0) || ((si1 == (-2147483647 - 1)) && (si2 == (-1)))) ? ((si1)) :

                                                                    (si1 % si2);
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

static uint32_t g_247 = 0x34D8CA7FL;

static int32_t g_2084 = (-1L);

static volatile int32_t g_2236[6] = {0x0E7B8307L, 0x0E7B8307L, 0x0E7B8307L,
                                     0x0E7B8307L, 0x0E7B8307L, 0x0E7B8307L};

static int32_t g_3045[3][7] = {
    {0x26980768L, 0x26980768L, 0x26980768L, 0x26980768L, 0x26980768L,
     0x26980768L, 0x26980768L},
    {8L, 8L, 8L, 8L, 8L, 8L, 8L},
    {0x26980768L, 0x26980768L, 0x26980768L, 0x26980768L, 0x26980768L,
     0x26980768L, 0x26980768L}};

static int16_t g_3901 = (-3L);

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
  for (i = 0; i < 3; i++)
    l_4311[i] = 0L;
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
  g_5 = l_4312;
  return g_2084;
}

int main(void) {

  int print_hash_value = 0;
  // crc32_gentab();
  func_1();
  // transparent_crc(g_5, "g_5", print_hash_value);
  /*for (i = 0; i < 3; i++)
  {
      for (j = 0; j < 1; j++)
      {
          transparent_crc(g_27[i][j], "g_27[i][j]", print_hash_value);
          if (print_hash_value) printf("index = [%d][%d]\n", i, j);
      }
  }*/
  /*for (i = 0; i < 9; i++)
  {
      for (j = 0; j < 2; j++)
      {
          transparent_crc(g_32[i][j], "g_32[i][j]", print_hash_value);
          if (print_hash_value) printf("index = [%d][%d]\n", i, j);
      }
  }
  transparent_crc(g_33, "g_33", print_hash_value);
  for (i = 0; i < 10; i++)
  {
      transparent_crc(g_34[i], "g_34[i]", print_hash_value);
      if (print_hash_value) printf("index = [%d]\n", i);
  }
  transparent_crc(g_35, "g_35", print_hash_value);
  transparent_crc(g_44, "g_44", print_hash_value);
  transparent_crc(g_53, "g_53", print_hash_value);
  transparent_crc(g_86, "g_86", print_hash_value);
  transparent_crc(g_108, "g_108", print_hash_value);
  transparent_crc(g_126, "g_126", print_hash_value);
  transparent_crc(g_127, "g_127", print_hash_value);
  transparent_crc(g_132, "g_132", print_hash_value);
  for (i = 0; i < 10; i++)
  {
      transparent_crc(g_183[i], "g_183[i]", print_hash_value);
      if (print_hash_value) printf("index = [%d]\n", i);
  }*/
  /*for (i = 0; i < 2; i++)
  {
      for (j = 0; j < 9; j++)
      {
          for (k = 0; k < 3; k++)
          {
              transparent_crc(g_185[i][j][k], "g_185[i][j][k]",
  print_hash_value); if (print_hash_value) printf("index = [%d][%d][%d]\n", i,
  j, k);
          }
      }
  }
  transparent_crc(g_203, "g_203", print_hash_value);
  transparent_crc(g_247, "g_247", print_hash_value);
  for (i = 0; i < 1; i++)
  {
      for (j = 0; j < 5; j++)
      {
          transparent_crc(g_250[i][j], "g_250[i][j]", print_hash_value);
          if (print_hash_value) printf("index = [%d][%d]\n", i, j);
      }
  }*/
  /*transparent_crc(g_276, "g_276", print_hash_value);
  transparent_crc(g_298, "g_298", print_hash_value);
  transparent_crc(g_315, "g_315", print_hash_value);
  transparent_crc(g_317, "g_317", print_hash_value);
  transparent_crc(g_318, "g_318", print_hash_value);
  transparent_crc(g_344, "g_344", print_hash_value);
  transparent_crc(g_391, "g_391", print_hash_value);
  transparent_crc(g_400, "g_400", print_hash_value);
  transparent_crc(g_419, "g_419", print_hash_value);*/
  for (i = 0; i < 3; i++) {
    // transparent_crc(g_427[i], "g_427[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  /*transparent_crc(g_449, "g_449", print_hash_value);
  transparent_crc(g_456, "g_456", print_hash_value);
  transparent_crc(g_486, "g_486", print_hash_value);
  transparent_crc(g_499, "g_499", print_hash_value);
  transparent_crc(g_503, "g_503", print_hash_value);
  for (i = 0; i < 10; i++)
  {
      for (j = 0; j < 8; j++)
      {
          for (k = 0; k < 3; k++)
          {
              transparent_crc(g_504[i][j][k], "g_504[i][j][k]",
  print_hash_value); if (print_hash_value) printf("index = [%d][%d][%d]\n", i,
  j, k);
          }
      }
  }
  transparent_crc(g_566, "g_566", print_hash_value);
  transparent_crc(g_577, "g_577", print_hash_value);
  transparent_crc(g_639, "g_639", print_hash_value);
  transparent_crc(g_692, "g_692", print_hash_value);
  for (i = 0; i < 2; i++)
  {
      transparent_crc(g_693[i], "g_693[i]", print_hash_value);
      if (print_hash_value) printf("index = [%d]\n", i);
  }
  transparent_crc(g_739, "g_739", print_hash_value);
  transparent_crc(g_769, "g_769", print_hash_value);
  transparent_crc(g_820, "g_820", print_hash_value);
  for (i = 0; i < 2; i++)
  {
      for (j = 0; j < 3; j++)
      {
          transparent_crc(g_897[i][j], "g_897[i][j]", print_hash_value);
          if (print_hash_value) printf("index = [%d][%d]\n", i, j);
      }
  }
  for (i = 0; i < 5; i++)
  {
      for (j = 0; j < 2; j++)
      {
          for (k = 0; k < 9; k++)
          {
              transparent_crc(g_918[i][j][k], "g_918[i][j][k]",
  print_hash_value); if (print_hash_value) printf("index = [%d][%d][%d]\n", i,
  j, k);
          }
      }
  }
  transparent_crc(g_972, "g_972", print_hash_value);
  transparent_crc(g_1001, "g_1001", print_hash_value);
  transparent_crc(g_1044, "g_1044", print_hash_value);
  transparent_crc(g_1045, "g_1045", print_hash_value);
  transparent_crc(g_1138, "g_1138", print_hash_value);
  transparent_crc(g_1328, "g_1328", print_hash_value);
  transparent_crc(g_1357, "g_1357", print_hash_value);
  transparent_crc(g_1363, "g_1363", print_hash_value);
  transparent_crc(g_1472, "g_1472", print_hash_value);
  transparent_crc(g_1669, "g_1669", print_hash_value);
  transparent_crc(g_2084, "g_2084", print_hash_value);
  transparent_crc(g_2222, "g_2222", print_hash_value);
  for (i = 0; i < 6; i++)
  {
      transparent_crc(g_2236[i], "g_2236[i]", print_hash_value);
      if (print_hash_value) printf("index = [%d]\n", i);
  }
  transparent_crc(g_2610, "g_2610", print_hash_value);
  transparent_crc(g_2674, "g_2674", print_hash_value);
  for (i = 0; i < 3; i++)
  {
      for (j = 0; j < 7; j++)
      {
          transparent_crc(g_2729[i][j], "g_2729[i][j]", print_hash_value);
          if (print_hash_value) printf("index = [%d][%d]\n", i, j);
      }
  }
  transparent_crc(g_2942, "g_2942", print_hash_value);
  transparent_crc(g_3003, "g_3003", print_hash_value);
  for (i = 0; i < 3; i++)
  {
      for (j = 0; j < 7; j++)
      {
          transparent_crc(g_3045[i][j], "g_3045[i][j]", print_hash_value);
          if (print_hash_value) printf("index = [%d][%d]\n", i, j);
      }
  }
  for (i = 0; i < 3; i++)
  {
      for (j = 0; j < 4; j++)
      {
          for (k = 0; k < 2; k++)
          {
              transparent_crc(g_3159[i][j][k], "g_3159[i][j][k]",
  print_hash_value); if (print_hash_value) printf("index = [%d][%d][%d]\n", i,
  j, k);
          }
      }
  }
  transparent_crc(g_3782, "g_3782", print_hash_value);
  transparent_crc(g_3901, "g_3901", print_hash_value);
  transparent_crc(g_3903, "g_3903", print_hash_value);
  transparent_crc(g_4123, "g_4123", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);*/
  return 0;
}
