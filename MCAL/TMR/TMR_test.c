/** @file TMR_test.c
 *
 * @brief A file that includes unit testing for TMR functions.
 *
 * @author Amir Shetaia
 * @version 2.0
 * @date Dec 11, 2022
 *
 */

/*========================== Includes ==========================*/
#include "../../Unity/unity.h"
#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "TMR_interface.h"

/*========================== setUp & tearDown Functions ==========================*/
void setUp(void)
{
    /* set stuff up here */
}

void tearDown(void)
{
    /* clean stuff up here */
}

/*========================== TMR_u8EnableTimer test functions ==========================*/

void test_TMR_u8EnableTimer(void)
{
    u8 Status = TMR_u8EnableTimer(4);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== TMR_u8DisableTimer test functions ==========================*/

void test_TMR_u8DisableTimer(void)
{
    u8 Status = TMR_u8DisableTimer(4);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== TMR_u8SetDutyCycle test functions ==========================*/

void test_TMR_u8SetDutyCycle1(void)
{
    u8 Status = TMR_u8SetDutyCycle(4, 80);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_TMR_u8SetDutyCycle2(void)
{
    u8 Status = TMR_u8SetDutyCycle(0, 120);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== TMR_u8SetDesiredTime test functions ==========================*/

void test_TMR_u8SetDesiredTime(void)
{
    u8 Status = TMR_u8SetDesiredTime(4, 1000);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== EXTI_u8SetCallBack test functions ==========================*/

void CallBackFunc(void) {}

void test_TMR_u8SetCallBack(void)
{
    u8 pinState;
    u8 Status = TMR_u8SetCallBack(6, CallBackFunc);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== TMR_u8GetPeriod test functions ==========================*/

void test_TMR_u8GetPeriod(void)
{
    u8 Status = TMR_u8GetPeriod(NULL);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== TMR_u8GetDutyCycle test functions ==========================*/

void test_TMR_u8GetDutyCycle(void)
{
    u8 Status = TMR_u8GetDutyCycle(NULL);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== TMR_u8OnTime test functions ==========================*/

void test_TMR_u8OnTime(void)
{
    u8 Status = TMR_u8OnTime(NULL);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== TMR_u8OffTime test functions ==========================*/

void test_TMR_u8OffTime(void)
{
    u8 Status = TMR_u8OffTime(NULL);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== Main function ==========================*/

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_TMR_u8EnableTimer);

    RUN_TEST(test_TMR_u8DisableTimer);

    RUN_TEST(test_TMR_u8SetDutyCycle1);
    RUN_TEST(test_TMR_u8SetDutyCycle2);

    RUN_TEST(test_TMR_u8SetDesiredTime);

    RUN_TEST(test_TMR_u8SetCallBack);

    RUN_TEST(test_TMR_u8GetPeriod);

    RUN_TEST(test_TMR_u8GetDutyCycle);

    RUN_TEST(test_TMR_u8OnTime);

    RUN_TEST(test_TMR_u8OffTime);

    return UNITY_END();
}