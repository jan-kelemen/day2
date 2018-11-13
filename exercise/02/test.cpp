#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "array.h"

TEST_CLASS(test_array)
{
	const int size = 10;
	const double value = 1.5;

public:
		
	TEST_METHOD(array_default_constructor)
	{
		
		array a;
		Assert::AreEqual(0, a.size());
		
	}

  TEST_METHOD(array_constructor)
	{
		
		array a(size, value); 
		Assert::AreEqual(size, a.size());
		for(int i=0; i<a.size(); ++i)
			Assert::AreEqual(value, a.at(i));
		
	}

	TEST_METHOD(array_index_invalid_large)
	{
		
		array a(size, value);
		auto func = [a]() { a.at(100); };
		Assert::ExpectException<std::out_of_range>(func);
		
	}

	TEST_METHOD(array_index_invalid_negative)
	{
		
		array a(size, value);
		auto func = [a]() { a.at(-2); };
		Assert::ExpectException<std::out_of_range>(func);
		
	}

	TEST_METHOD(array_assignment)
	{
		
		array a(size, value);
		array b;
		b = a;
		Assert::AreEqual(size, b.size());
		for (int i = 0; i < b.size(); ++i)
			Assert::AreEqual(value, b.at(i));
		
	}

    TEST_METHOD(array_move_assignment)
	{
        array a(size, value);
        array b;
        b = std::move(a);
        Assert::AreEqual(0, a.size());
        for (int i = 0; i < b.size(); ++i)
            Assert::AreEqual(value, b.at(i));
	}

    TEST_METHOD(array_move_assignment_from_initialized_value)
	{
        array a(size, value);
        array b(size, value);
        b = std::move(a);
        Assert::AreEqual(0, a.size());
        for (int i = 0; i < b.size(); ++i)
            Assert::AreEqual(value, b.at(i));
	}

	TEST_METHOD(array_copy_constructor)
	{
		
		array a(size, value);
		array b(a);
		Assert::AreEqual(size, b.size());
		for (int i = 0; i < b.size(); ++i)
			Assert::AreEqual(value, b.at(i));
		
	}

	TEST_METHOD(array_move_constructor)
	{
		
		array a(size, value);
		array b = std::move(a);
		Assert::AreEqual(0, a.size());
		Assert::AreEqual(size, b.size());
		for (int i = 0; i < b.size(); ++i)
			Assert::AreEqual(value, b.at(i));
		
	}

};
