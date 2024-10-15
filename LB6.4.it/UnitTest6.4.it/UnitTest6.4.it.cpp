#include "pch.h"
#include "CppUnitTest.h"
#include "../LB6.4.it/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int SIZE = 20;
			int arr[SIZE]{};
			int MIN = -20;
			int MAX = 20;
			create(arr, SIZE, MIN, MAX);
			Assert::AreEqual(0, findMaxModIndex(arr, SIZE), 0.00001);

		}
	};
}
