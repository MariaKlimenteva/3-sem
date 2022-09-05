//=============================================================================
#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

//-----------------------------------------------------------------------------
//! @brief Compare expected_roots and roots from solve_quadratic_equation. Output a message about passing the test or an error
//!
//! @param [in] a - the coefficient at x^2 in the quadratic equation
//!
//! @param [in] b - the coefficient at x in the quadratic equation
//!
//! @param [in] c - free term in the quadratic equation
//!
//! @param [in] expected_roots - the calculated number of roots,  compare them with what solve_quadratic_equation will return
//!
//! @param [in] expected_x1 - calculate the correct value of the first root
//!
//! @param [in] expected_x2 - calculate the correct value of the second root
//!
//! @return returns nothing
//-----------------------------------------------------------------------------
void unit_test (double a, double b, double c, int expected_roots, double expected_x1, double expected_x2);
//-----------------------------------------------------------------------------
//! @brief Read expected values from a file and use the unit_test function
//!
//! @param [in] a - the coefficient at x^2 in the quadratic equation
//!
//! @param [in] b - the coefficient at x in the quadratic equation
//!
//! @param [in] c - free term in the quadratic equation
//!
//! @param [in] expected_roots - the calculated number of roots,  compare them with what solve_quadratic_equation will return
//!
//! @param [in] expected_x1 - calculate the correct value of the first root
//!
//! @param [in] expected_x2 - calculate the correct value of the second root
//!
//! @return returns nothing
//-----------------------------------------------------------------------------
void unit_test_from_file (double a, double b, double c, int expected_roots, double expected_x1, double expected_x2);

#endif // UNIT_TESTS_H
