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

static int8_t(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (si1 + si2);
}

static int8_t(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (si1 - si2);
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

static int8_t(safe_rshift_func_int8_t_s_u)(int8_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
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

static int16_t(safe_rshift_func_int16_t_s_s)(int16_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
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

static uint8_t(safe_sub_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return ui1 - ui2;
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

static uint8_t(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > ((255) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint8_t(safe_rshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
}

static uint16_t(safe_add_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return ui1 + ui2;
}

static uint16_t(safe_div_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint16_t(safe_rshift_func_uint16_t_u_s)(uint16_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint32_t(safe_add_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return ui1 + ui2;
}

static uint32_t(safe_sub_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return ui1 - ui2;
}

static uint32_t(safe_div_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static int32_t g_2 = 1L;
static int32_t g_128[8][2] = {{(-6L), (-5L)}, {(-6L), (-5L)}, {(-6L), (-5L)},
                              {(-6L), (-5L)}, {(-6L), (-5L)}, {(-6L), (-5L)},
                              {(-6L), (-5L)}, {(-6L), (-5L)}};

static int16_t g_211[9][5][5] = {{{0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L}},
                                 {{0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L}},
                                 {{0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L}},
                                 {{0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L}},
                                 {{0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L}},
                                 {{0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L}},
                                 {{0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L}},
                                 {{0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L}},
                                 {{0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L},
                                  {0x61F7L, 0x9C58L, 4L, 0xCDC4L, 0L}}};

static uint32_t g_1160 = 1UL;

static int32_t g_1237 = 0x7726A56AL;
static uint8_t g_1397[1] = {247UL};
static int32_t g_1600 = 0L;

static uint32_t g_2123 = 0xFD87EE03L;
static int32_t g_2126 = (-1L);

static uint32_t g_2169 = 3UL;

static int32_t func_1(void);
static int32_t func_8(uint16_t p_9, uint8_t p_10, uint16_t p_11);
static int8_t func_29(int32_t p_30, int8_t p_31, int8_t p_32);
static uint32_t func_42(uint32_t p_43, int32_t p_44);
static int16_t func_48(int8_t p_49, const uint16_t p_50, uint32_t p_51,
                       int8_t p_52);
static uint16_t func_55(int8_t p_56, const uint16_t p_57, uint32_t p_58);
static int16_t func_75(uint32_t p_76);
static const uint8_t func_81(const uint32_t p_82);
static int16_t func_89(int8_t p_90, const int8_t p_91, const int8_t p_92,
                       uint16_t p_93, int32_t p_94);
static uint32_t func_97(int32_t p_98, uint16_t p_99, uint16_t p_100,
                        uint32_t p_101, uint16_t p_102);
static int32_t func_1(void) {
  int32_t l_14 = (-1L);
  uint32_t l_2413 = 0x5A683F60L;

  l_2413 = (safe_sub_func_int32_t_s_s(
      func_8((safe_rshift_func_uint8_t_u_u(
                 l_14,
                 ((safe_div_func_uint8_t_u_u(g_2, l_14)) ==
                  (safe_add_func_uint32_t_u_u(
                      ((safe_rshift_func_int16_t_s_s(
                           ((1UL !=
                             (((((safe_mod_func_int32_t_s_s(
                                     (g_2 != 1L),
                                     (safe_add_func_int32_t_s_s(
                                         0xBB489F7AL,
                                         ((safe_sub_func_int8_t_s_s(
                                              ((0xB35BL != 0L) != 4294967295UL),
                                              l_14)) > g_2))))) |
                                 0x877E0698L) == (-4L)) != 0x74L) == l_14)) <=
                            l_14),
                           l_14)) >= 0UL),
                      l_14))))),
             g_2, g_2),
      l_14));

  return l_2413;
}

static int32_t func_8(uint16_t p_9, uint8_t p_10, uint16_t p_11) {
  int32_t l_45 = 0x57638FF4L;
  int32_t l_1633[6][6] = {
      {1L, (-6L), 0x2AB2D1D6L, 0x6F056149L, 0x2AB2D1D6L, (-6L)},
      {1L, (-6L), 0x2AB2D1D6L, 0x6F056149L, 0x2AB2D1D6L, (-6L)},
      {1L, (-6L), 0x2AB2D1D6L, 0x6F056149L, 0x2AB2D1D6L, (-6L)},
      {1L, (-6L), 0x2AB2D1D6L, 0x6F056149L, 0x2AB2D1D6L, (-6L)},
      {1L, (-6L), 0x2AB2D1D6L, 0x6F056149L, 0x2AB2D1D6L, (-6L)},
      {1L, (-6L), 0x2AB2D1D6L, 0x6F056149L, 0x2AB2D1D6L, (-6L)}};
  const int16_t l_2127 = 0xFDA7L;
  uint8_t l_2128 = 0x5EL;
  uint32_t l_2168 = 4294967287UL;
  int32_t l_2193 = (-4L);
  uint32_t l_2194 = 1UL;
  int32_t l_2207 = 0x7BFE0C83L;
  int32_t l_2211 = (-1L);
  int32_t l_2212[5][4][1] = {
      {{0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}},
      {{0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}},
      {{0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}},
      {{0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}},
      {{0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}, {0x22E28D3BL}}};
  uint32_t l_2217[5] = {0xCC29EE76L, 0xBFBF91E1L, 0xCC29EE76L, 0xBFBF91E1L,
                        0xCC29EE76L};
  uint32_t l_2231 = 0xAA119E81L;
  uint16_t l_2252 = 0xBC4CL;
  uint32_t l_2291 = 0xCE168084L;
  uint16_t l_2403[9] = {0UL,     0xFA2FL, 0UL,     0xFA2FL, 0UL,
                        0xFA2FL, 0UL,     0xFA2FL, 0UL};
  int i, j, k;
  g_2169 ^=
      (((((safe_lshift_func_int8_t_s_u(
              func_29(
                  ((safe_rshift_func_int8_t_s_u(
                       ((safe_rshift_func_uint8_t_u_u(p_10, 4)) &
                        (safe_div_func_int16_t_s_s(
                            (safe_mod_func_uint8_t_u_u(
                                (+((g_2 > func_42(g_2, l_45)) |
                                   (safe_rshift_func_int16_t_s_s(
                                       func_48(
                                           g_2,
                                           ((safe_add_func_uint16_t_u_u(
                                                func_55(
                                                    (safe_sub_func_int32_t_s_s(
                                                        (+(safe_add_func_int32_t_s_s(
                                                            g_2,
                                                            (safe_sub_func_uint32_t_u_u(
                                                                ((l_45 ||
                                                                  func_42(
                                                                      ((func_42(
                                                                            (((safe_sub_func_int8_t_s_s(
                                                                                  ((65535UL !=
                                                                                    p_11) <
                                                                                   p_9),
                                                                                  (-1L))) !=
                                                                              l_45) &&
                                                                             0x6E219E4EL),
                                                                            p_10) &
                                                                        g_2) <
                                                                       l_45),
                                                                      l_45)) ^
                                                                 p_11),
                                                                (-8L)))))),
                                                        l_45)),
                                                    l_45, g_2),
                                                l_45)) ||
                                            p_11),
                                           g_1397[0], l_1633[1][0]),
                                       p_9)))),
                                g_2126)),
                            p_11))),
                       l_45)) >= l_2127),
                  g_2123, l_2128),
              5)) &&
          g_2126) |
         l_2168) == 8UL) &
       p_9);

  return l_2211;
}

static int8_t func_29(int32_t p_30, int8_t p_31, int8_t p_32) {
  uint16_t l_2135 = 0x649BL;
  int32_t l_2137 = 0xF76C5922L;
  int32_t l_2167 = 0x6FABE4C3L;

  {
    uint16_t l_2150 = 0xC4D5L;
    int32_t l_2155[8] = {0xB34F4F7FL, 0xB34F4F7FL, (-6L),       0xB34F4F7FL,
                         0xB34F4F7FL, (-6L),       0xB34F4F7FL, 0xB34F4F7FL};
    int i;

    {
      uint32_t l_2136 = 0x1BCF3D56L;

      g_1600 = (g_1600 && g_128[0][1]);
    }
  }

  return g_1237;
}

static uint32_t func_42(uint32_t p_43, int32_t p_44) { return g_2; }

static int16_t func_48(int8_t p_49, const uint16_t p_50, uint32_t p_51,
                       int8_t p_52) {
  int32_t l_1636 = (-6L);
  int32_t l_1637 = 0L;
  uint8_t l_1786 = 0xDDL;
  uint32_t l_1791 = 0x1C1565D4L;
  int32_t l_1792[6][4] = {
      {7L, 0xA2CFB56EL, 0L, 0xA2CFB56EL}, {7L, 0xA2CFB56EL, 0L, 0xA2CFB56EL},
      {7L, 0xA2CFB56EL, 0L, 0xA2CFB56EL}, {7L, 0xA2CFB56EL, 0L, 0xA2CFB56EL},
      {7L, 0xA2CFB56EL, 0L, 0xA2CFB56EL}, {7L, 0xA2CFB56EL, 0L, 0xA2CFB56EL}};
  uint16_t l_2084 = 65535UL;
  int32_t l_2124 = (-1L);
  int32_t l_2125 = 0x5BFA9C5FL;
  int i, j;

  return l_2125;
}

static uint16_t func_55(int8_t p_56, const uint16_t p_57, uint32_t p_58) {
  uint32_t l_72 = 0x30A04A8FL;
  int32_t l_988[8] = {0L, 0L, (-1L), 0L, 0L, (-1L), 0L, 0L};
  int32_t l_1053 = 0x9AF0D710L;
  int16_t l_1085 = (-1L);
  uint32_t l_1167[2][7][2] = {{{0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L}},
                              {{0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L},
                               {0xA03B419BL, 0x7A737271L}}};
  int32_t l_1285[4][3] = {{0xEDA6B4A7L, 9L, 0xEDA6B4A7L},
                          {0xEDA6B4A7L, 9L, 0xEDA6B4A7L},
                          {0xEDA6B4A7L, 9L, 0xEDA6B4A7L},
                          {0xEDA6B4A7L, 9L, 0xEDA6B4A7L}};
  const int32_t l_1286 = 0xF958864CL;
  int16_t l_1603 = (-1L);
  int32_t l_1627 = (-5L);
  int8_t l_1628[7][4] = {
      {(-1L), (-1L), 0xD3L, (-1L)}, {(-1L), (-1L), 0xD3L, (-1L)},
      {(-1L), (-1L), 0xD3L, (-1L)}, {(-1L), (-1L), 0xD3L, (-1L)},
      {(-1L), (-1L), 0xD3L, (-1L)}, {(-1L), (-1L), 0xD3L, (-1L)},
      {(-1L), (-1L), 0xD3L, (-1L)}};
  int16_t l_1629 = (-3L);
  uint32_t l_1630 = 4294967295UL;
  int i, j, k;
  if (g_2) {
    uint32_t l_87 = 0UL;
    int32_t l_88[5];
    int32_t l_993 = 0x4D480402L;
    int32_t l_1054 = 0x6BCD192FL;
    int32_t l_1058 = 0xD2199B0AL;
    int32_t l_1059 = 0xA30ACE95L;
    int32_t l_1060 = 2L;
    int32_t l_1061 = 0xADDD7F08L;
    int32_t l_1062 = 0xA0FEAF09L;
    int32_t l_1063 = 0x385977F3L;
    int32_t l_1064 = 0xC7EC8870L;
    int32_t l_1065 = 1L;
    int32_t l_1066[9];
    uint16_t l_1067[1][9][9] = {{{65535UL, 0xC476L, 0UL, 0xC476L, 65535UL,
                                  0xFECCL, 65535UL, 0xC476L, 0x20F2L},
                                 {65535UL, 0xC476L, 0UL, 0xC476L, 65535UL,
                                  0xFECCL, 65535UL, 0xC476L, 0x20F2L},
                                 {65535UL, 0xC476L, 0UL, 0xC476L, 65535UL,
                                  0xFECCL, 65535UL, 0xC476L, 0x20F2L},
                                 {65535UL, 0xC476L, 0UL, 0xC476L, 65535UL,
                                  0xFECCL, 65535UL, 0xC476L, 0x20F2L},
                                 {65535UL, 0xC476L, 0UL, 0xC476L, 65535UL,
                                  0xFECCL, 65535UL, 0xC476L, 0x20F2L},
                                 {65535UL, 0xC476L, 0UL, 0xC476L, 65535UL,
                                  0xFECCL, 65535UL, 0xC476L, 0x20F2L},
                                 {65535UL, 0xC476L, 0UL, 0xC476L, 65535UL,
                                  0xFECCL, 65535UL, 0xC476L, 0x20F2L},
                                 {65535UL, 0xC476L, 0UL, 0xC476L, 65535UL,
                                  0xFECCL, 65535UL, 0xC476L, 0x20F2L},
                                 {65535UL, 0xC476L, 0UL, 0xC476L, 65535UL,
                                  0xFECCL, 65535UL, 0xC476L, 0x20F2L}}};
    int32_t l_1164 = 0xFF72E546L;
    int16_t l_1212 = 6L;
    int32_t l_1230 = 0L;
    uint8_t l_1251 = 254UL;
    int8_t l_1458[10];
    int i, j, k;
    for (i = 0; i < 5; i++)
      l_88[i] = 0xFBC07B36L;

    if ((((safe_sub_func_int32_t_s_s(
              (((safe_add_func_int8_t_s_s(p_58, l_72)) <=
                (safe_lshift_func_int8_t_s_s(
                    (func_75((safe_lshift_func_uint8_t_u_u(
                         ((((safe_sub_func_uint32_t_u_u(
                                ((func_81((
                                      (((safe_add_func_uint16_t_u_u(
                                            g_2, (safe_sub_func_uint8_t_u_u(
                                                     l_87,
                                                     (l_88[1] !=
                                                      func_42(l_72, p_56)))))) <
                                        (func_89((((g_2 ^ l_88[2]) ^ (-5L)) >=
                                                  0x9A5DL),
                                                 g_2, p_57, l_72, p_56) &&
                                         g_128[7][0])) != l_88[3]) != p_58)) <=
                                  p_57) <= 0x25B967A1L),
                                p_57)) < 0UL) != 0x6224ACA1L) ^
                          g_2),
                         7))) != l_72),
                    l_88[1]))) != p_56),
              1L)) |
          p_56) ||
         g_211[7][4][0])) {
      uint32_t l_997[10][7][2] = {{{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}},
                                  {{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}},
                                  {{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}},
                                  {{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}},
                                  {{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}},
                                  {{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}},
                                  {{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}},
                                  {{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}},
                                  {{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}},
                                  {{4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL},
                                   {4294967290UL, 3UL}}};
      int8_t l_1004 = 0x05L;
      uint32_t l_1049 = 0x07032793L;
      int i, j, k;

    } else {
      uint32_t l_1055 = 0xB866D2B0L;
    }

  } else {
  }

  return l_1285[0][0];
}

static int16_t func_75(uint32_t p_76) {
  int8_t l_985 = (-1L);

  return l_985;
}

static const uint8_t func_81(const uint32_t p_82) {
  int8_t l_289 = 0L;
  int32_t l_301 = 0L;
  int32_t l_302[9][9][3] = {{{0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL}},
                            {{0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL}},
                            {{0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL}},
                            {{0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL}},
                            {{0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL}},
                            {{0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL}},
                            {{0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL}},
                            {{0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL}},
                            {{0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL},
                             {0L, 0xB21CC5C8L, 0xB6F0A05AL}}};
  uint16_t l_303 = 0x7858L;
  int8_t l_450[3][2] = {{0x21L, 0x21L}, {0x21L, 0x21L}, {0x21L, 0x21L}};
  int16_t l_477 = (-2L);
  int8_t l_642 = 0x27L;
  int32_t l_875 = 0x7F5730D1L;
  int32_t l_906 = 0x849F931CL;
  uint32_t l_911[6][6] = {{0xD1935F70L, 0xD1935F70L, 0x78C6EAD5L, 0xBDBB7FD2L,
                           0x842A3AACL, 0xBDBB7FD2L},
                          {0xD1935F70L, 0xD1935F70L, 0x78C6EAD5L, 0xBDBB7FD2L,
                           0x842A3AACL, 0xBDBB7FD2L},
                          {0xD1935F70L, 0xD1935F70L, 0x78C6EAD5L, 0xBDBB7FD2L,
                           0x842A3AACL, 0xBDBB7FD2L},
                          {0xD1935F70L, 0xD1935F70L, 0x78C6EAD5L, 0xBDBB7FD2L,
                           0x842A3AACL, 0xBDBB7FD2L},
                          {0xD1935F70L, 0xD1935F70L, 0x78C6EAD5L, 0xBDBB7FD2L,
                           0x842A3AACL, 0xBDBB7FD2L},
                          {0xD1935F70L, 0xD1935F70L, 0x78C6EAD5L, 0xBDBB7FD2L,
                           0x842A3AACL, 0xBDBB7FD2L}};
  int8_t l_943 = 0x30L;
  int i, j, k;

  return l_302[7][8][0];
}

static int16_t func_89(int8_t p_90, const int8_t p_91, const int8_t p_92,
                       uint16_t p_93, int32_t p_94) {
  int32_t l_103 = (-7L);
  int32_t l_148 = 0x9B449B5EL;
  int32_t l_238 = (-6L);
  int32_t l_266 = 0x3F1265F8L;
  int8_t l_267 = 0xA3L;
  int32_t l_268 = 0x26C4010CL;
  int32_t l_269 = 0x3A3B66FBL;
  int32_t l_270 = (-1L);
  int32_t l_271 = (-7L);
  int32_t l_272 = 0x86C571FAL;
  int32_t l_273 = 1L;
  int32_t l_274[4][8] = {{0xA345D410L, 0x679FF3BBL, 0L, 0x679FF3BBL,
                          0xA345D410L, (-5L), 0xA345D410L, 0x679FF3BBL},
                         {0xA345D410L, 0x679FF3BBL, 0L, 0x679FF3BBL,
                          0xA345D410L, (-5L), 0xA345D410L, 0x679FF3BBL},
                         {0xA345D410L, 0x679FF3BBL, 0L, 0x679FF3BBL,
                          0xA345D410L, (-5L), 0xA345D410L, 0x679FF3BBL},
                         {0xA345D410L, 0x679FF3BBL, 0L, 0x679FF3BBL,
                          0xA345D410L, (-5L), 0xA345D410L, 0x679FF3BBL}};
  int32_t l_275 = 0x40BFBFA9L;
  int8_t l_276[7][6][5] = {{{0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L}},
                           {{0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L}},
                           {{0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L}},
                           {{0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L}},
                           {{0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L}},
                           {{0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L}},
                           {{0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L},
                            {0x4CL, (-1L), 0x8AL, 0L, 0L}}};
  uint32_t l_277 = 0x2182FCCDL;
  int i, j, k;
  if ((safe_lshift_func_int8_t_s_u(
          ((func_42(
                func_97(
                    l_103,
                    (safe_div_func_uint8_t_u_u(
                        (safe_div_func_uint16_t_u_u(
                            ((0x34L ^
                              ((safe_add_func_uint32_t_u_u(
                                   (safe_sub_func_int8_t_s_s(
                                       l_103,
                                       ((safe_div_func_uint32_t_u_u(
                                            (safe_rshift_func_uint16_t_u_s(
                                                65531UL, 5)),
                                            g_2)) >= 0x88L))),
                                   ((l_103 <=
                                     (!(safe_div_func_int32_t_s_s(
                                         (safe_mod_func_int16_t_s_s(
                                             (((((safe_mod_func_int32_t_s_s(
                                                     ((((safe_add_func_uint16_t_u_u(
                                                            p_90, g_2)) &
                                                        l_103) >= g_2) > g_2),
                                                     4294967288UL)) ^
                                                 l_103) <= p_92) < 0UL) <
                                              0x3F29A386L),
                                             g_2)),
                                         g_2)))) < 0xEFL))) ^
                               l_103)) &&
                             4294967287UL),
                            l_103)),
                        p_91)),
                    l_103, g_2, p_94),
                g_2) != 0xF5C60D0FL) |
           4294967286UL),
          l_103))) {
    uint8_t l_147 = 0x0FL;
    int32_t l_210 = (-5L);

  } else {
    int16_t l_260 = 0xAD86L;
    int32_t l_263[1];
    int i;
  }

  return l_267;
}

static uint32_t func_97(int32_t p_98, uint16_t p_99, uint16_t p_100,
                        uint32_t p_101, uint16_t p_102) {
  int16_t l_125[8];
  int i;
  for (i = 0; i < 8; i++)
    l_125[i] = (-6L);
  for (p_99 = 0; (p_99 <= 7); p_99 += 1) {
    for (p_101 = 0; (p_101 <= 7); p_101 += 1) {
      int i;
      if ((g_1600 < 0)) {

        {
          for (p_101 = 0; (p_101 <= 7); p_101 += 1) {
            int i;
            if (l_125[p_100])
              break;
          }
        }
      }

      if (l_125[p_99])
        break;
    }
  }
  return g_2;
}

int main(void) {
  int i, j, k;
  int print_hash_value = 0;

  func_1();

  return 0;
}
