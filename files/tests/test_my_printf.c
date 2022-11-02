/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-1-bsminiprintf-henry.letellier
** File description:
** test_mini_printf.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
int my_printf(const char *format, ...);

// redirecting the visual outputs
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Testing the displayed content
Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

// Testing the programs output with flags
// |- %c
Test(my_printf, simple_string_with_c, .init = redirect_all_std)
{
    my_printf("hello world %c", 'e');
    cr_assert_stdout_eq_str("hello world e");
}

// |- %s
Test(my_printf, simple_string_with_s, .init = redirect_all_std)
{
    my_printf("hello world %s", "rrrr");
    cr_assert_stdout_eq_str("hello world rrrr");
}

// |- %d
Test(my_printf, simple_string_with_d, .init = redirect_all_std)
{
    my_printf("hello world %d", 2);
    cr_assert_stdout_eq_str("hello world 2");
}

// |- %i
Test(my_printf, simple_string_with_i, .init = redirect_all_std)
{
    my_printf("hello world %i", 1);
    cr_assert_stdout_eq_str("hello world 1");
}

// |- %%
Test(my_printf, simple_string_with_percent_percent, .init = redirect_all_std)
{
    my_printf("hello world %%");
    cr_assert_stdout_eq_str("hello world %");
}

// |- %c %s %d %i %%
Test(my_printf, complex_string, .init = redirect_all_std)
{
    my_printf("hello world %c %s %d %i %%", 'e', "rrrr", 2, 1);
    cr_assert_stdout_eq_str("hello world e rrrr 2 1 %");
}

// |- %o
Test(my_printf, simple_test_percent_o, .init = redirect_all_std)
{
    my_printf("hello world %o", 18);
    cr_assert_stdout_eq_str("hello world 22");
}

// |- %b
Test(my_printf, binary_testing_option_percent_b, .init = redirect_all_std)
{
    my_printf("hello world %b", 6);
    cr_assert_stdout_eq_str("hello world 110");
}

// |- %x
Test(my_printf, hex_testing_option_lower_x_output, .init = redirect_all_std)
{
    my_printf("hello world %x", 42);
    cr_assert_stdout_eq_str("hello world 2a");
}

// |- %X
Test(my_printf, hex_testing_option_upper_x_output, .init = redirect_all_std)
{
    my_printf("hello world %X", 42);
    cr_assert_stdout_eq_str("hello world 2A");
}

// |- %n
Test(my_printf, pointer_testing_current_place, .init = redirect_all_std)
{
    int result = 0;
    my_printf("hello world %n", &result);
    cr_assert_stdout_eq_str("hello world ");
}

Test(my_printf, testing_printf_output_when_n_surrounded, .init = redirect_all_std)
{
    int result = 0;
    my_printf("hello world %n abcdefg", &result);
    cr_assert_stdout_eq_str("hello world  abcdefg");
}

// |- %f
// Test(my_printf, test_output_percent_f_when_not_surrounded, .init = redirect_all_std)
// {
//     my_printf("hello world %f", 42.42);
//     cr_assert_stdout_eq_str("hello world 42.420000");
// }

// Test(my_printf, test_output_percent_f_when_surrounded, .init = redirect_all_std)
// {
//     my_printf("hello world %f abcdefg", 42.42);
//     cr_assert_stdout_eq_str("hello world 42.420000 abcdefg");
// }

// Testing program's response
Test(my_printf, simple_string_count, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world");
    cr_assert_eq(status, 11, "Got %d, but expected %d.\n");
}

// Testing the program's response for flags:
// |- %c
Test(my_printf, simple_string_with_c_count, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %c", 'e');
    cr_assert_eq(status, 13, "Got %d, but expected %d.\n");
}

// |- %s
Test(my_printf, simple_string_with_s_count, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %s", "rrrr");
    cr_assert_eq(status, 16, "Got %d, but expected %d.\n");
}

// |- %d
Test(my_printf, simple_string_with_d_count, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %d", 2);
    cr_assert_eq(status, 13, "Got %d, but expected %d.\n");
}

// |- %i
Test(my_printf, simple_string_with_i_count, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %i", 1);
    cr_assert_eq(status, 13, "Got %d, but expected %d.\n");
}

// |- %%
Test(my_printf, simple_string_with_percent_percent_count, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %%");
    cr_assert_eq(status, 13, "Got %d, but expected %d.\n");
}

// |- %c %s %d %i %%
Test(my_printf, complex_string_count, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %c %s %d %i %%", 'e', "rrrr", 2, 1);
    cr_assert_eq(status, 24, "Got %d, but expected %d.\n");
}

// |- %o
Test(my_printf, octal_count, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %o", 18);
    cr_assert_eq(status, 13, "Got %d, but expected %d.\n");
}

// |- %b
Test(my_printf, binary_count, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %b", 6);
    cr_assert_eq(status, 15, "Got %d, but expected %d.\n");
}

// |- %x
Test(my_printf, hex_testing_binary_upper_x_return, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %x", 42);
    cr_assert_eq(status, 14, "Got %d, but expected %d.\n");
}

// |- %X
Test(my_printf, hex_testing_binary_lower_x_return, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %X", 42);
    cr_assert_eq(status, 14, "Got %d, but expected %d.\n");
}

// |- %n
Test(my_printf, pointer_testing_current_place_return, .init = redirect_all_std)
{
    int result = 0;
    int status = 0;
    status = my_printf("hello world %n", &result);
    cr_assert_eq(status, 12, "Got %d, but expected %d\n");
}

Test(my_printf, testing_pointer_content, .init = redirect_all_std)
{
    int result = 0;
    my_printf("hello world %n", &result);
    cr_assert_eq(result, 12, "Got %d, but expected %d\n");
}

Test(my_printf, testing_pointer_response_when_surrounded, .init = redirect_all_std)
{
    int result = 0;
    int status = 0;
    status = my_printf("hello world %n abcdefg", &result);
    cr_assert_eq(status, 20, "Got %d, but expected %d\n");
}

Test(my_printf, testing_pointer_content_surrounded, .init = redirect_all_std)
{
    int result = 0;
    my_printf("hello world %n abcdefg", &result);
    cr_assert_eq(result, 12, "Got %d, but expected %d\n");
}

// |- %f
// Test(my_printf, test_length_of_percent_f, .init = redirect_all_std)
// {
//     int status = 0;
//     status = my_printf("hello world %f", 42.42);
//     cr_assert_eq(status, 21, "Got %d, but expected %d\n");
// }

// Test(my_printf, test_length_of_percent_f_when_surrounded, .init = redirect_all_std)
// {
//     int status = 0;
//     status = my_printf("hello world %f abcdefg", 42.42);
//     cr_assert_eq(status, 30, "Got %d, but expected %d\n");
// }

// Testing the program's response to errors

Test(my_printf, string_empty_success, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("");
    cr_assert_eq(status, 0, "Got %d, but expected %d.\n");
}

Test(my_printf, string_unknown_param, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %é");
    cr_assert_eq(status, -1, "Got %d, but expected %d.\n");
}

Test(my_printf, string_unknown_param_n_var, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %é", 42);
    cr_assert_eq(status, -1, "Got %d, but expected %d.\n");
}

Test(my_printf, simple_string_with_c_n_unknown_param_error_management, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %c %é", 'e');
    cr_assert_eq(status, -1, "Got %d, but expected %d.\n");
}

Test(my_printf, simple_string_with_c_n_unknown_param_n_var_error_management, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %c %é", 'e', 42);
    cr_assert_eq(status, -1, "Got %d, but expected %d.\n");
}

Test(my_printf, complex_string_n_unknown_param_error_management, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %c %s %é %d %i %%", 'e', "rrrr", 2, 1);
    cr_assert_eq(status, -1, "Got %d, but expected %d.\n");
}

Test(my_printf, complex_string_n_unknown_param_n_var_error_management, .init = redirect_all_std)
{
    int status = 0;
    status = my_printf("hello world %c %s %é %d %i %%", 'e', "rrrr", 42, 2, 1);
    cr_assert_eq(status, -1, "Got %d, but expected %d.\n");
}
