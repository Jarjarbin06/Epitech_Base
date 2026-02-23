/*
** EPITECH PROJECT, 2025
** test_printf_basic.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "test.h"

// test base //
Test(print, test_string_printing_1, .init = redirect_all_std)
{
    print("Hello");
    cr_assert_stdout_eq_str("Hello");
}

Test(print, test_string_printing_2, .init = redirect_all_std)
{
    print("Hello World! How are you?\n");
    cr_assert_stdout_eq_str("Hello World! How are you?\n");
}

Test(print, test_string_printing_3, .init = redirect_all_std)
{
    print("");
    cr_assert_stdout_eq_str("");
}

Test(print, test_string_printing_length_1, .init = redirect_all_std)
{
    const int int_obtained = print("Hello");
    const int int_expected = 5;

    cr_assert_eq(int_obtained, int_expected);
}

Test(print, test_string_printing_NULL_1, .init = redirect_all_std)
{
    print(NULL);
    cr_assert_stdout_eq_str("");
}

Test(print, test_string_printing_empty_conv_1, .init = redirect_all_std)
{
    print("", "Hello");
    cr_assert_stdout_eq_str("");
}

// test_conv //
Test(print, test_string_printing_d_1, .init = redirect_all_std)
{
    print("%d", 125);
    cr_assert_stdout_eq_str("125");
}

Test(print, test_string_printing_d_2, .init = redirect_all_std)
{
    print("%d", 0);
    cr_assert_stdout_eq_str("0");
}

Test(print, test_string_printing_d_3, .init = redirect_all_std)
{
    print("%d", -125);
    cr_assert_stdout_eq_str("-125");
}

Test(print, test_string_printing_i_1, .init = redirect_all_std)
{
    print("%i", 125);
    cr_assert_stdout_eq_str("125");
}

Test(print, test_string_printing_i_2, .init = redirect_all_std)
{
    print("%i", 0x7d);
    cr_assert_stdout_eq_str("125");
}

Test(print, test_string_printing_i_3, .init = redirect_all_std)
{
    print("%i", 0175);
    cr_assert_stdout_eq_str("125");
}

Test(print, test_string_printing_i_4, .init = redirect_all_std)
{
    print("%i", 0b1111101);
    cr_assert_stdout_eq_str("125");
}

Test(print, test_string_printing_i_5, .init = redirect_all_std)
{
    print("%i", 0);
    cr_assert_stdout_eq_str("0");
}

Test(print, test_string_printing_o_1, .init = redirect_all_std)
{
    print("%o", 125);
    cr_assert_stdout_eq_str("175");
}

Test(print, test_string_printing_o_2, .init = redirect_all_std)
{
    print("%o", 0);
    cr_assert_stdout_eq_str("0");
}

Test(print, test_string_printing_u_1, .init = redirect_all_std)
{
    print("%u", 125);
    cr_assert_stdout_eq_str("125");
}

Test(print, test_string_printing_u_2, .init = redirect_all_std)
{
    print("%u", 0);
    cr_assert_stdout_eq_str("0");
}

Test(print, test_string_printing_x_1, .init = redirect_all_std)
{
    print("%x", 125);
    cr_assert_stdout_eq_str("7d");
}

Test(print, test_string_printing_x_2, .init = redirect_all_std)
{
    print("%x", 0);
    cr_assert_stdout_eq_str("0");
}

Test(print, test_string_printing_X_1, .init = redirect_all_std)
{
    print("%X", 125);
    cr_assert_stdout_eq_str("7D");
}

Test(print, test_string_printing_X_2, .init = redirect_all_std)
{
    print("%X", 0);
    cr_assert_stdout_eq_str("0");
}

Test(print, test_string_printing_e_1, .init = redirect_all_std)
{
    print("%e", 125.125);
    cr_assert_stdout_eq_str("1.251250e+02");
}

Test(print, test_string_printing_e_2, .init = redirect_all_std)
{
    print("%e", -125.125);
    cr_assert_stdout_eq_str("-1.251250e+02");
}

Test(print, test_string_printing_e_3, .init = redirect_all_std)
{
    print("%e", 0.00125);
    cr_assert_stdout_eq_str("1.250000e-03");
}

Test(print, test_string_printing_e_4, .init = redirect_all_std)
{
    print("%e", -0.00125);
    cr_assert_stdout_eq_str("-1.250000e-03");
}

Test(print, test_string_printing_e_5, .init = redirect_all_std)
{
    print("%e", 0.0);
    cr_assert_stdout_eq_str("0");
}

Test(print, test_string_printing_E_1, .init = redirect_all_std)
{
    print("%E", 125.125);
    cr_assert_stdout_eq_str("1.251250E+02");
}

Test(print, test_string_printing_E_2, .init = redirect_all_std)
{
    print("%E", -125.125);
    cr_assert_stdout_eq_str("-1.251250E+02");
}

Test(print, test_string_printing_E_3, .init = redirect_all_std)
{
    print("%E", 0.00125);
    cr_assert_stdout_eq_str("1.250000E-03");
}

Test(print, test_string_printing_E_4, .init = redirect_all_std)
{
    print("%E", -0.00125);
    cr_assert_stdout_eq_str("-1.250000E-03");
}

Test(print, test_string_printing_E_5, .init = redirect_all_std)
{
    print("%E", 0.0);
    cr_assert_stdout_eq_str("0");
}

Test(print, test_string_printing_f_1, .init = redirect_all_std)
{
    print("%f", 0.125);
    cr_assert_stdout_eq_str("0.125000");
}

Test(print, test_string_printing_f_2, .init = redirect_all_std)
{
    print("%f", 125.125);
    cr_assert_stdout_eq_str("125.125000");
}

Test(print, test_string_printing_f_3, .init = redirect_all_std)
{
    print("%f", 0.0);
    cr_assert_stdout_eq_str("0.000000");
}

Test(print, test_string_printing_f_4, .init = redirect_all_std)
{
    print("%f", 1.0f / 0.0f);
    cr_assert_stdout_eq_str("inf");
}

Test(print, test_string_printing_f_5, .init = redirect_all_std)
{
    print("%f", 0.0f / 0.0f);
    cr_assert_stdout_eq_str("nan");
}

Test(print, test_string_printing_f_6, .init = redirect_all_std)
{
    print("%f", 0.000125);
    cr_assert_stdout_eq_str("0.000125");
}

Test(print, test_string_printing_F_1, .init = redirect_all_std)
{
    print("%F", 0.125);
    cr_assert_stdout_eq_str("0.125000");
}

Test(print, test_string_printing_F_2, .init = redirect_all_std)
{
    print("%F", 125.125);
    cr_assert_stdout_eq_str("125.125000");
}

Test(print, test_string_printing_F_3, .init = redirect_all_std)
{
    print("%F", 0.0);
    cr_assert_stdout_eq_str("0.000000");
}

Test(print, test_string_printing_F_4, .init = redirect_all_std)
{
    print("%F", 1.0f / 0.0f);
    cr_assert_stdout_eq_str("INF");
}

Test(print, test_string_printing_F_5, .init = redirect_all_std)
{
    print("%F", 0.0f / 0.0f);
    cr_assert_stdout_eq_str("NAN");
}

Test(print, test_string_printing_F_6, .init = redirect_all_std)
{
    print("%F", 0.000125);
    cr_assert_stdout_eq_str("0.000125");
}

/*
Test(print, test_string_printing_g_1, .init = redirect_all_std)
{
    print("%g", 0.125);
    cr_assert_stdout_eq_str("0.125");
}

Test(print, test_string_printing_g_2, .init = redirect_all_std)
{
    print("%g", 125.0);
    cr_assert_stdout_eq_str("125");
}

Test(print, test_string_printing_g_3, .init = redirect_all_std)
{
    print("%g", 125.125);
    cr_assert_stdout_eq_str("125.125");
}

Test(print, test_string_printing_g_4, .init = redirect_all_std)
{
    print("%g", 0.125521);
    cr_assert_stdout_eq_str("0.125521");
}

Test(print, test_string_printing_g_5, .init = redirect_all_std)
{
    print("%g", 125521.0);
    cr_assert_stdout_eq_str("125521");
}

Test(print, test_string_printing_g_6, .init = redirect_all_std)
{
    print("%g", 125521.125521);
    cr_assert_stdout_eq_str("125521.");
}

Test(print, test_string_printing_g_7, .init = redirect_all_std)
{
    print("%g", 0.1256521);
    cr_assert_stdout_eq_str("0.125652");
}

Test(print, test_string_printing_g_8, .init = redirect_all_std)
{
    print("%g", 1256521.0);
    cr_assert_stdout_eq_str("1.25652e+06");
}

Test(print, test_string_printing_g_9, .init = redirect_all_std)
{
    print("%g", 1256521.1256521);
    cr_assert_stdout_eq_str("1.25652e+06");
}

Test(print, test_string_printing_g_10, .init = redirect_all_std)
{
    print("%g", 0.0000125);
    cr_assert_stdout_eq_str("1.25e-05");
}

Test(print, test_string_printing_g_11, .init = redirect_all_std)
{
    print("%g", 0.00123456);
    cr_assert_stdout_eq_str("0.00123456");
}

Test(print, test_string_printing_G_1, .init = redirect_all_std)
{
    print("%G", 0.125);
    cr_assert_stdout_eq_str("0.125");
}

Test(print, test_string_printing_G_2, .init = redirect_all_std)
{
    print("%G", 125.0);
    cr_assert_stdout_eq_str("125");
}

Test(print, test_string_printing_G_3, .init = redirect_all_std)
{
    print("%G", 125.125);
    cr_assert_stdout_eq_str("125.125");
}

Test(print, test_string_printing_G_4, .init = redirect_all_std)
{
    print("%G", 0.125521);
    cr_assert_stdout_eq_str("0.125521");
}

Test(print, test_string_printing_G_5, .init = redirect_all_std)
{
    print("%G", 125521.0);
    cr_assert_stdout_eq_str("125521");
}

Test(print, test_string_printing_G_6, .init = redirect_all_std)
{
    print("%G", 125521.125521);
    cr_assert_stdout_eq_str("125521.");
}

Test(print, test_string_printing_G_7, .init = redirect_all_std)
{
    print("%G", 0.1256521);
    cr_assert_stdout_eq_str("0.125652");
}

Test(print, test_string_printing_G_8, .init = redirect_all_std)
{
    print("%G", 1256521.0);
    cr_assert_stdout_eq_str("1.25652E+06");
}

Test(print, test_string_printing_G_9, .init = redirect_all_std)
{
    print("%G", 1256521.1256521);
    cr_assert_stdout_eq_str("1.25652E+06");
}

Test(print, test_string_printing_G_10, .init = redirect_all_std)
{
    print("%G", 0.0000125);
    cr_assert_stdout_eq_str("1.25E-05");
}

Test(print, test_string_printing_G_11, .init = redirect_all_std)
{
    print("%G", 0.00123456);
    cr_assert_stdout_eq_str("0.00123456");
}

*/

Test(print, test_string_printing_c_1, .init = redirect_all_std)
{
    print("%c", 'C');
    cr_assert_stdout_eq_str("C");
}

Test(print, test_string_printing_c_2, .init = redirect_all_std)
{
    print("%c", '\n');
    cr_assert_stdout_eq_str("\n");
}

Test(print, test_string_printing_s_1, .init = redirect_all_std)
{
    print("%s", "Hello");
    cr_assert_stdout_eq_str("Hello");
}

Test(print, test_string_printing_p_1, .init = redirect_all_std)
{
    const char *s = "Hello";
    const int int_obtained_1_1 = print("%p", &s);
    const int int_expected_1_1 = 14;

    cr_assert_eq(int_obtained_1_1, int_expected_1_1);
}

/*
Test(print, test_string_printing_n_1, .init = redirect_all_std)
{
    int int_obtained_1_1 = 0;
    int int_obtained_1_2 = 0;
    const int int_expected_1_1 = 5;
    const int int_expected_1_2 = 10;

    print("hello%nworld%n", &int_obtained_1_1, &int_obtained_1_2);
    cr_assert_eq(int_obtained_1_1, int_expected_1_1);
    cr_assert_eq(int_obtained_1_2, int_expected_1_2);
}
*/

Test(print, test_string_printing_m_1, .init = redirect_all_std)
{
    print("%m");
    cr_assert_stdout_eq_str("Success");
}

Test(print, test_string_printing_modulo_1, .init = redirect_all_std)
{
    print("%%");
    cr_assert_stdout_eq_str("%");
}

Test(print, test_string_printing_modulo_2, .init = redirect_all_std)
{
    print("%");
    cr_assert_stdout_eq_str("");
}

Test(print, test_string_printing_modulo_3, .init = redirect_all_std)
{
    print("%\n");
    cr_assert_stdout_eq_str("%\n");
}

// test_flag //
Test(print, test_string_printing_hashtag_o_1, .init = redirect_all_std)
{
    print("%#o", 125);
    cr_assert_stdout_eq_str("0175");
}

Test(print, test_string_printing_hashtag_x_1, .init = redirect_all_std)
{
    print("%#x", 125);
    cr_assert_stdout_eq_str("0x7d");
}

Test(print, test_string_printing_hashtag_X_1, .init = redirect_all_std)
{
    print("%#X", 125);
    cr_assert_stdout_eq_str("0x7D");
}

Test(print, test_string_printing_hashtag_f_1, .init = redirect_all_std)
{
    print("%#.f", 1.25);
    cr_assert_stdout_eq_str("1.");
}

Test(print, test_string_printing_hashtag_F_1, .init = redirect_all_std)
{
    print("%#.F", 1.25);
    cr_assert_stdout_eq_str("1.");
}

Test(print, test_string_printing_hashtag_e_1, .init = redirect_all_std)
{
    print("%#.e", 12.5);
    cr_assert_stdout_eq_str("1.e+01");
}

Test(print, test_string_printing_hashtag_E_1, .init = redirect_all_std)
{
    print("%#.E", 12.5);
    cr_assert_stdout_eq_str("1.E+01");
}

/*
Test(print, test_string_printing_hashtag_g_1, .init = redirect_all_std)
{
    print("%#g", 12.5);
    cr_assert_stdout_eq_str("12.5000");
}

Test(print, test_string_printing_hashtag_g_2, .init = redirect_all_std)
{
    print("%#.4g", 1250.0);
    cr_assert_stdout_eq_str("1250.");
}

Test(print, test_string_printing_hashtag_g_3, .init = redirect_all_std)
{
    print("%#.g", 12.5);
    cr_assert_stdout_eq_str("1.e+01");
}

Test(print, test_string_printing_hashtag_G_1, .init = redirect_all_std)
{
    print("%#G", 12.5);
    cr_assert_stdout_eq_str("12.5000");
}

Test(print, test_string_printing_hashtag_G_2, .init = redirect_all_std)
{
    print("%#.4G", 1250.0);
    cr_assert_stdout_eq_str("1250.");
}

Test(print, test_string_printing_hashtag_G_3, .init = redirect_all_std)
{
    print("%#.G", 12.5);
    cr_assert_stdout_eq_str("1.E+01");
}
*/

Test(print, test_string_printing_precision_d_1, .init = redirect_all_std)
{
    print("%.5d", 125);
    cr_assert_stdout_eq_str("00125");
}

Test(print, test_string_printing_precision_f_1, .init = redirect_all_std)
{
    print("%.2f", 12.5);
    cr_assert_stdout_eq_str("12.50");
}

Test(print, test_string_printing_precision_f_2, .init = redirect_all_std)
{
    print("%.10f", 12.5);
    cr_assert_stdout_eq_str("12.5000000000");
}

Test(print, test_string_printing_precision_F_1, .init = redirect_all_std)
{
    print("%.2F", 12.5);
    cr_assert_stdout_eq_str("12.50");
}

Test(print, test_string_printing_precision_F_2, .init = redirect_all_std)
{
    print("%.10F", 12.5);
    cr_assert_stdout_eq_str("12.5000000000");
}

Test(print, test_string_printing_precision_e_1, .init = redirect_all_std)
{
    print("%.5e", 12.5);
    cr_assert_stdout_eq_str("1.25000e+01");
}

Test(print, test_string_printing_precision_e_2, .init = redirect_all_std)
{
    print("%.5e", 0.0125);
    cr_assert_stdout_eq_str("1.25000e-02");
}

Test(print, test_string_printing_plus_d_1, .init = redirect_all_std)
{
    print("%+d", 125);
    cr_assert_stdout_eq_str("+125");
}

Test(print, test_string_printing_plus_f_1, .init = redirect_all_std)
{
    print("%+f", 0.125);
    cr_assert_stdout_eq_str("+0.125000");
}

Test(print, test_string_printing_plus_e_1, .init = redirect_all_std)
{
    print("%+e", 1250000.0);
    cr_assert_stdout_eq_str("+1.250000e+06");
}

/*
Test(print, test_string_printing_plus_g_1, .init = redirect_all_std)
{
    print("%+g", 0.125);
    cr_assert_stdout_eq_str("+0.125");
}

Test(print, test_string_printing_plus_g_2, .init = redirect_all_std)
{
    print("%+g", 1250000.0);
    cr_assert_stdout_eq_str("+1.25e+06");
}

Test(print, test_string_printing_plus_G_1, .init = redirect_all_std)
{
    print("%+G", 0.125);
    cr_assert_stdout_eq_str("+0.125");
}

Test(print, test_string_printing_plus_G_2, .init = redirect_all_std)
{
    print("%+G", 1250000.0);
    cr_assert_stdout_eq_str("+1.25E+06");
}
*/

// test_seg //
Test(print, test_string_printing_seg_d, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%d", c);
    print("%d", str);
    print("%d", i);
    print("%d", li);
    print("%d", lli);
    print("%d", ui);
    print("%d", uli);
    print("%d", ulli);
    print("%d", f);
    print("%d", d);
    print("%d", ld);
    print("%d", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_i, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%i", c);
    print("%i", str);
    print("%i", i);
    print("%i", li);
    print("%i", lli);
    print("%i", ui);
    print("%i", uli);
    print("%i", ulli);
    print("%i", f);
    print("%i", d);
    print("%i", ld);
    print("%i", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_o, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%o", c);
    print("%o", str);
    print("%o", i);
    print("%o", li);
    print("%o", lli);
    print("%o", ui);
    print("%o", uli);
    print("%o", ulli);
    print("%o", f);
    print("%o", d);
    print("%o", ld);
    print("%o", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_u, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%u", c);
    print("%u", str);
    print("%u", i);
    print("%u", li);
    print("%u", lli);
    print("%u", ui);
    print("%u", uli);
    print("%u", ulli);
    print("%u", f);
    print("%u", d);
    print("%u", ld);
    print("%u", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_x, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%x", c);
    print("%x", str);
    print("%x", i);
    print("%x", li);
    print("%x", lli);
    print("%x", ui);
    print("%x", uli);
    print("%x", ulli);
    print("%x", f);
    print("%x", d);
    print("%x", ld);
    print("%x", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_X, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%X", c);
    print("%X", str);
    print("%X", i);
    print("%X", li);
    print("%X", lli);
    print("%X", ui);
    print("%X", uli);
    print("%X", ulli);
    print("%X", f);
    print("%X", d);
    print("%X", ld);
    print("%X", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_e, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%e", c);
    print("%e", str);
    print("%e", i);
    print("%e", li);
    print("%e", lli);
    print("%e", ui);
    print("%e", uli);
    print("%e", ulli);
    print("%e", f);
    print("%e", d);
    print("%e", ld);
    print("%e", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_E, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%E", c);
    print("%E", str);
    print("%E", i);
    print("%E", li);
    print("%E", lli);
    print("%E", ui);
    print("%E", uli);
    print("%E", ulli);
    print("%E", f);
    print("%E", d);
    print("%E", ld);
    print("%E", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_f, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%f", c);
    print("%f", str);
    print("%f", i);
    print("%f", li);
    print("%f", lli);
    print("%f", ui);
    print("%f", uli);
    print("%f", ulli);
    print("%f", f);
    print("%f", d);
    print("%f", ld);
    print("%f", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_F, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%F", c);
    print("%F", str);
    print("%F", i);
    print("%F", li);
    print("%F", lli);
    print("%F", ui);
    print("%F", uli);
    print("%F", ulli);
    print("%F", f);
    print("%F", d);
    print("%F", ld);
    print("%F", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_g, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%g", c);
    print("%g", str);
    print("%g", i);
    print("%g", li);
    print("%g", lli);
    print("%g", ui);
    print("%g", uli);
    print("%g", ulli);
    print("%g", f);
    print("%g", d);
    print("%g", ld);
    print("%g", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_G, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%G", c);
    print("%G", str);
    print("%G", i);
    print("%G", li);
    print("%G", lli);
    print("%G", ui);
    print("%G", uli);
    print("%G", ulli);
    print("%G", f);
    print("%G", d);
    print("%G", ld);
    print("%G", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_a, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%a", c);
    print("%a", str);
    print("%a", i);
    print("%a", li);
    print("%a", lli);
    print("%a", ui);
    print("%a", uli);
    print("%a", ulli);
    print("%a", f);
    print("%a", d);
    print("%a", ld);
    print("%a", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_A, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%A", c);
    print("%A", str);
    print("%A", i);
    print("%A", li);
    print("%A", lli);
    print("%A", ui);
    print("%A", uli);
    print("%A", ulli);
    print("%A", f);
    print("%A", d);
    print("%A", ld);
    print("%A", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_c, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%c", c);
    print("%c", str);
    print("%c", i);
    print("%c", li);
    print("%c", lli);
    print("%c", ui);
    print("%c", uli);
    print("%c", ulli);
    print("%c", f);
    print("%c", d);
    print("%c", ld);
    print("%c", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_s, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%s", c);
    print("%s", str);
    print("%s", i);
    print("%s", li);
    print("%s", lli);
    print("%s", ui);
    print("%s", uli);
    print("%s", ulli);
    print("%s", f);
    print("%s", d);
    print("%s", ld);
    print("%s", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_p, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%p", c);
    print("%p", str);
    print("%p", i);
    print("%p", li);
    print("%p", lli);
    print("%p", ui);
    print("%p", uli);
    print("%p", ulli);
    print("%p", f);
    print("%p", d);
    print("%p", ld);
    print("%p", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_n, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%n", c);
    print("%n", str);
    print("%n", i);
    print("%n", li);
    print("%n", lli);
    print("%n", ui);
    print("%n", uli);
    print("%n", ulli);
    print("%n", f);
    print("%n", d);
    print("%n", ld);
    print("%n", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_m, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%m", c);
    print("%m", str);
    print("%m", i);
    print("%m", li);
    print("%m", lli);
    print("%m", ui);
    print("%m", uli);
    print("%m", ulli);
    print("%m", f);
    print("%m", d);
    print("%m", ld);
    print("%m", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_modulo, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%%", c);
    print("%%", str);
    print("%%", i);
    print("%%", li);
    print("%%", lli);
    print("%%", ui);
    print("%%", uli);
    print("%%", ulli);
    print("%%", f);
    print("%%", d);
    print("%%", ld);
    print("%%", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_backn, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%\n", c);
    print("%\n", str);
    print("%\n", i);
    print("%\n", li);
    print("%\n", lli);
    print("%\n", ui);
    print("%\n", uli);
    print("%\n", ulli);
    print("%\n", f);
    print("%\n", d);
    print("%\n", ld);
    print("%\n", v);
    cr_assert(1);
}

Test(print, test_string_printing_seg_backzero, .init = redirect_all_std)
{
    const char c = 'c';
    const char *str = "str";
    const int i = 1;
    const long int li = 1;
    long const long int lli = 1;
    const unsigned int ui = 1;
    const unsigned long int uli = 1;
    const unsigned long long int ulli = 1;
    const float f = 1.0f;
    const double d = 1.0f;
    const long double ld = 1.0f;
    const void *v = &i;

    print("%\0", c);
    print("%\0", str);
    print("%\0", i);
    print("%\0", li);
    print("%\0", lli);
    print("%\0", ui);
    print("%\0", uli);
    print("%\0", ulli);
    print("%\0", f);
    print("%\0", d);
    print("%\0", ld);
    print("%\0", v);
    cr_assert(1);
}
