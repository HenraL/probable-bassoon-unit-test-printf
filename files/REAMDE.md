# Unit tests for my_printf

## Intro

This is a readme file destined to help you understand how to set-up the required environement for testing my_printf.

## Setting-up

### Requirements

In order to be able to run the unit_tests, please make sure you have:

* A program called `gcc` installed on your computer (<https://gcc.gnu.org/install/index.html>)
* A program called `make` installed on your computer
  * For Windows: <https://www.technewstoday.com/install-and-use-make-in-windows/>
  * For Mac: <https://formulae.brew.sh/formula/make#default>
  * For Linux: <https://www.systranbox.com/how-to-install-make-command-in-linux/>
* A library called `criterion` installed on your computer (<https://github.com/Snaipe/Criterion>)
* a folder named: `tests`
* a file named: `test_my_printf.c` located in the folder `tests`
* the bash script named: `compile_and_run_test.sh`
* Your program copied in the same folder as this readme.

Please also make sure your program compiles with a makefile and that the output is an archive.

If this is not the case, a basic makefile (that uses *.c [not alowed in epitech]) can be used as a piggy-back method.
This makefile is located in the same folder as this readme.

### Running the tests

Are you all set, great, it is now time to compile and test if your program can withstand the important number of tests.

To run the program, let's first start by according execution rights to `compile_and_run_test.sh`
For this, let's use the linux command `chmod +x compile_and_run_test.sh`

Alright, it is now time to run the program.
For this, let's use the linux command `./compile_and_run_test.sh`

If you encounter any problems, do not hesitate to have à look at the `Makefile_template` as well as at the `compile_and_run_test.sh` to see why the problem occurred.
