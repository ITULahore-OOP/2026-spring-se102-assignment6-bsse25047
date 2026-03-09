#ifndef CATCH_HPP
#define CATCH_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <sstream>
#include <streambuf>
#include <cmath>

inline int passed_tests = 0;
inline int failed_tests = 0;
inline std::vector<std::pair<std::function<void()>, std::string>> tests;

// --- Macros for Unique Names ---
#define CONCAT_IMPL(x, y) x##y
#define CONCAT(x, y) CONCAT_IMPL(x, y)

// --- The TEST_CASE Macro ---
#define TEST_CASE(name, tags)                                 \
    void CONCAT(test_, __LINE__)();                           \
    struct CONCAT(Register, __LINE__)                         \
    {                                                         \
        CONCAT(Register, __LINE__)()                          \
        {                                                     \
            tests.push_back({CONCAT(test_, __LINE__), name}); \
        }                                                     \
    } CONCAT(r, __LINE__);                                    \
    void CONCAT(test_, __LINE__)()

// --- The REQUIRE Macro ---
#define REQUIRE(expr)                                                                      \
    if (!(expr))                                                                           \
    {                                                                                      \
        std::cout << "\033[1;31m[FAIL] Line " << __LINE__ << ": " << #expr << "\033[0m\n"; \
        failed_tests++;                                                                    \
    }                                                                                      \
    else                                                                                   \
    {                                                                                      \
        passed_tests++;                                                                    \
    }

// --- Output Capture Helper ---
class OutputCapture
{
    std::streambuf *oldCoutStreamBuf;
    std::ostringstream strCout;

public:
    OutputCapture()
    {
        oldCoutStreamBuf = std::cout.rdbuf();
        std::cout.rdbuf(strCout.rdbuf());
    }
    ~OutputCapture()
    {
        std::cout.rdbuf(oldCoutStreamBuf);
    }
    std::string getOutput()
    {
        return strCout.str();
    }
};

// --- Main Test Runner ---
inline int runCatchTests()
{
    std::cout << "\n=== RUNNING AUTOMATED TESTS ===\n";
    std::cout << "Executing " << tests.size() << " Test Cases...\n";

    for (auto &test : tests)
    {
        std::cout << "--> Checking: " << test.second << "\n";
        test.first();
    }

    std::cout << "\n--------------------------------------------------\n";
    std::cout << "Tests Passed: " << passed_tests << "\n";
    std::cout << "Tests Failed: " << failed_tests << "\n";

    if (failed_tests == 0)
    {
        std::cout << "\033[1;32mALL TESTS PASSED\033[0m\n";
        return 0;
    }
    else
    {
        std::cout << "\033[1;31mSOME TESTS FAILED\033[0m\n";
        return 1;
    }
}

#endif