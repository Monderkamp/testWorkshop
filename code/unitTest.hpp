#ifndef UNITTEST_H
#define UNITTEST_H


#include <iostream>
#include <cmath>

class unitTest
	{
		public:
		
		//constructors, destructors
		unitTest();

		~unitTest(){};


		/**
		 * @brief Asserts the equality of two double values.
		 * 
		 * This function compares two double values for equality and prints a test message to indicate the result.
		 * It is primarily used for unit testing to check if a given value matches an expected value.
		 *
		 * @param sample The value being tested.
		 * @param expected The expected value to compare against.
		 * @param testMessage A message describing the test, to be displayed with the result.
		 * @return true If 'sample' and 'expected' are equal.
		 * @return false If 'sample' and 'expected' are not equal.
		 */

		static bool assertEqual(double sample, double expected, const std::string& testMessage) {
			
			if (sample == expected) {
				std::cout << "PASS: " << testMessage << std::endl;
				return true;
			} else {
				std::cerr << "FAIL: " << testMessage << " (sample " << sample << ", expected " << expected << ")" << std::endl;
				return false;
			}
		}	

		/**
		 * @brief Asserts that two double values are not equal.
		 *
		 * This function checks whether the provided `sample` value is not equal to the `expected` value.
		 * If they are not equal, it prints a "PASS" message along with the `testMessage`. If they are equal,
		 * it prints a "FAIL" message, displaying both the `sample` and `expected` values, and the `testMessage`.
		 *
		 * @param sample The value to be tested.
		 * @param expected The value against which `sample` is compared.
		 * @param testMessage A message describing the test, displayed in the output.
		 * @return `true` if `sample` and `expected` are not equal, `false` otherwise.
		 */

		static bool assertNotEqual(double sample, double expected, const std::string& testMessage) {
			if (sample != expected) {
				std::cout << "PASS: " << testMessage << std::endl;
				return true;
			} else {
				std::cerr << "FAIL: " << testMessage << " (Expected " << sample << " != " << expected << ")" << std::endl;
				return false;
			}
		}	

		/**
		 * Asserts that the difference between two sample values does not exceed a specified maximum difference.
		 *
		 * This function compares two double values, `sample1` and `sample2`, and checks if their absolute difference
		 * is within the bounds of `maxDiff`. If the difference is within the limit, the test is considered passed, 
		 * otherwise, it's considered failed.
		 *
		 * @param sample1 The first sample value to be compared.
		 * @param sample2 The second sample value to be compared.
		 * @param maxDiff The maximum allowable difference between the two sample values.
		 * @param testMessage A string message that describes the test. This message is printed as part of the output.
		 *
		 * @return Returns `true` if the difference between `sample1` and `sample2` is less than or equal to `maxDiff`,
		 *         indicating the test has passed. Returns `false` otherwise, indicating the test has failed.
		 */

		static bool assertMaxDiffence(double sample1, double sample2, double maxDiff, const std::string& testMessage) {
			if (fabs(sample1 - sample2) <= maxDiff) {
				std::cout << "PASS: " << testMessage << std::endl;
				return true;
			} else {
				std::cerr << "FAIL: " << testMessage << " (Error should be no more than " << maxDiff << ", got " 
						  << fabs(sample1 - sample2) << ", sample1 = " << sample1 << ", sample2 = " << sample2 << ")" << std::endl;
				return false;
			}
		}


		/**
		 * @brief Asserts that a double value is equal to true.
		 *
		 * This function checks if the given double value (`sample1`) is equal to true.
		 * Since boolean statements in C++ are interpreted as 1.0 or 0.0, it applies to all boolean statements.
		 * If the assertion passes, it prints a success message along with the provided
		 * test message. If the assertion fails, it prints a failure message, the
		 * expected value, and the test message.
		 *
		 * @param sample1 The double value to be tested against true.
		 * @param testMessage A reference to a std::string containing the message to be displayed.
		 * @return Returns true if `sample1` is equal to true, false otherwise.
		 */

		static bool assertTrue(double sample1, const std::string& testMessage) {
			if (sample1 == true) {
				std::cout << "PASS: " << testMessage << std::endl;
				return true;
			} else {
				std::cerr << "FAIL: " << testMessage << " (Expected " << sample1 << " == true)" << std::endl;
				return false;
			}


		}	
		/**
		 * @brief Asserts that a given double value is equal to false.
		 * 
		 * This function checks if the provided double value (sample1) is equal to false (0.0).
		 * * Since boolean statements in C++ are interpreted as 1.0 or 0.0, it applies to all boolean statements.
		 * If the condition is met, it prints a success message along with the provided test message.
		 * If the condition is not met, it prints a failure message, the expected condition,
		 * and the test message to the standard error output.
		 *
		 * @param sample1 The double value to be tested against false.
		 * @param testMessage The message to be displayed with the test result.
		 * @return Returns true if the sample1 is equal to false, otherwise returns false.
		 */

		static bool assertFalse(double sample1, const std::string& testMessage) {
			if (sample1 == false) {
				std::cout << "PASS: " << testMessage << std::endl;
				return true;
			} else {
				std::cerr << "FAIL: " << testMessage << " (Expected " << sample1 << " == false)" << std::endl;
				return false;
			}
		}	

		/**
		 * @brief Asserts if two double values are approximately equal considering a tolerance based on Units in Last Place (ULP).
		 * 
		 * This function compares two double values, `sample1` and `sample2`, to determine if they are approximately equal
		 * within a tolerance. The tolerance is dynamically calculated based on the ULP of both samples. This approach is
		 * more robust for floating-point comparisons than a fixed epsilon value, as it accounts for the floating-point
		 * representation's precision characteristics.
		 * 
		 * The ULP-based tolerance is calculated as four times the next representable value after `sample1` and `sample2`
		 * towards INFINITY. The maximum of these two ULP values is used as the tolerance for comparison.
		 * 
		 * If the absolute difference between `sample1` and `sample2` is within this tolerance, or if they are exactly equal,
		 * the function logs a "PASS" message along with the `testMessage` provided and returns true. Otherwise, it logs a
		 * "FAIL" message with details including the calculated error, the ULP tolerance, and the actual values of `sample1`
		 * and `sample2`, then returns false.
		 * 
		 * @param sample1 The first double value to compare.
		 * @param sample2 The second double value to compare.
		 * @param testMessage A string message to display with the test result, usually describing the test case.
		 * 
		 * @return true if `sample1` and `sample2` are approximately equal within the ULP-based tolerance, false otherwise.
		 */

		static bool assertDoubleEqual(double sample1, double sample2, const std::string& testMessage) {
			double ULP1 = 4*std::nextafter(sample1, INFINITY) - sample1;			
			double ULP2 = 4*std::nextafter(sample2, INFINITY) - sample2;			
			double maxULP = ULP1;

			if (ULP1 < ULP2) {maxULP = ULP2;}


			if (sample1 == sample2) {
				std::cout << "PASS: " << testMessage << std::endl;
				return true;
			} else if (fabs(sample1 - sample2) <= maxULP) {
				std::cout << "PASS: " << testMessage << std::endl;
				return true;
			} else {
				std::cerr << "FAIL: " << testMessage << " (Error should be no more than " << maxULP << ", got " 
						  << fabs(sample1 - sample2) << ", sample1 = " << sample1 << ", sample2 = " << sample2 << ")" << std::endl;
				return false;
			}
		}
	
	};
	
#endif
