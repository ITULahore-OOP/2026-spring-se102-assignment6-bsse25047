#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>

// Helper class to redirect cout to a string for testing print outputs
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