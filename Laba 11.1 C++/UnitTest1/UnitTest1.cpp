#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 11.1 C++/Laba 11.1 C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            char inputFileName[] = "testInputFile.bin";
            char outputFileName[] = "testOutputFile.bin";
            std::ofstream inputFile(inputFileName, std::ios::binary);
            inputFile << "³íôîïïï";
            inputFile.close();

            ProcessBIN(inputFileName, outputFileName);

            
            std::ifstream outputFile(outputFileName, std::ios::binary);
            std::stringstream buffer;
            buffer << outputFile.rdbuf();
            std::string result = buffer.str();

            Assert::AreEqual(std::string("³íôî"), result);
		}
	};
}
