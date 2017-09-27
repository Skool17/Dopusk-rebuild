#include <ctest.h>
#include <../src/procedure.h>

// checking
CTEST(Test_1_checking, input_1)
{
    int result = checking(1);
	
    int expected = 2;
	
    ASSERT_EQUAL(expected, result);
}

CTEST(Test_2_checking, input_m_1)
{
    int result = checking(-1);
	
    int expected = 1;
	
    ASSERT_EQUAL(expected, result);
}

CTEST(Test_3_checking, input_0)
{
    int result = checking(0);
	
    int expected = 0;
	
    ASSERT_EQUAL(expected, result);
}

// Discriminant
CTEST(Test_1_discriminant, input_3_2_1)
{
    float result = Discriminant(3,2,1);
	
    float expected = -8;
	
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(Test_2_discriminant, input_1_3_2)
{
    float result = Discriminant(1,3,2);
	
    float expected = 1;
	
   ASSERT_DBL_NEAR(expected, result);
}

CTEST(Test_3_discriminant, input_4_4_1)
{
    float result = Discriminant(4,4,1);
	
    float expected = 0;
	
    ASSERT_DBL_NEAR(expected, result);
}

// Znachenie
CTEST(Test_1_Znachenie, input_1_1_3_2_1)
{
    float result = Znachenie(1,1,3,2,1);
	
    float expected = -1;
	
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(Test_2_Znachenie, input_1_1_3_2_m_1)
{
    float result = Znachenie(1,1,3,2,-1);
	
    float expected = -2;
	
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(Test_3_Znachenie, input_0_4_4_1_m_1)
{
    float result = Znachenie(0,4,4,1,-1);
	
    float expected = -0.5;
	
    ASSERT_DBL_NEAR(expected, result);
}
