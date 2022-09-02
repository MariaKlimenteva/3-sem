//=============================================================================
#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

// ===============================> READ IT AND APPLY! <===============================
// TODO: SEE SquareEquation.h FOR COMMON DOCUMENTATION CRITIQUE THAT APPLIES HERE TOO!

//-----------------------------------------------------------------------------
//! @brief The function outputs that the test has passed, if the test values (set) match
//! those received by the solve_quadratic_equation function, otherwise it outputs an error message
//!
//! @param [in] a, b, c - coefficients defining the quadratic equation ax^2 + bx + c = 0
//!             test_roots - the calculated number of roots, which we then compare with what the function will return solve_quadratic_equation
//!             test_x1, test_x2 - calculated the correct values of the roots of the equation that the function solve_quadratic_equation should get
//!
//! @return returns nothing
//-----------------------------------------------------------------------------
void unit_test (double a, double b, double c, int test_roots, double test_x1, double test_x2);
//-----------------------------------------------------------------------------
//! @brief Reading text values from a file and using the unit_test function
//!
//! @param [in] a, b, c - coefficients defining the quadratic equation ax^2 + bx + c = 0
//!             test_roots - the calculated number of roots, which we then compare with what the function will return solve_quadratic_equation
//!             test_x1, test_x2 - calculated the correct values of the roots of the equation that the function solve_quadratic_equation should get
//!
//! @return returns nothing
//-----------------------------------------------------------------------------
void unit_Test_fromFile (double a, double b, double c, int test_roots, double test_x1, double test_x2);
// TODO: ^~   ^~  ^~ TODO: What is this naming, where have you seen such? Use consistent style, please!

#endif // UNIT_TESTS_H
