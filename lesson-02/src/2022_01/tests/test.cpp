#include <iostream>

#include <gtest/gtest.h>

#include "fake.hpp"

class TestFoo : public ::testing::Test
{
protected:
	void SetUp()
	{
        std::cout << "SetUp" << std::endl;
	}
	void TearDown()
	{
        std::cout << "TearDown" << std::endl;
	}
};

TEST_F(TestFoo, test_const_method)
{
	ASSERT_EQ(fake::magic_int_method(8, 1), 9);
	ASSERT_NE(fake::magic_int_method(8, 1), 0);
}

TEST_F(TestFoo, test_string_method)
{
	ASSERT_EQ(fake::magic_str_method(10), std::string("hello, world!"));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
