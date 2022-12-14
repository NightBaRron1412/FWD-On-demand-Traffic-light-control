/** @file EXTI_test.c
 *
 * @brief A file that includes unit testing for EXTI functions.
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
#include "EXTI_interface.h"

/*========================== setUp & tearDown Functions ==========================*/
void setUp(void)
{
    /* set stuff up here */
}

void tearDown(void)
{
    /* clean stuff up here */
}

/*========================== EXTI_u8Enable test functions ==========================*/

void test_EXTI_u8Enable(void)
{
    u8 Status = EXTI_u8Enable(4);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== EXTI_u8Disable test functions ==========================*/

void test_EXTI_u8Disable(void)
{
    u8 Status = EXTI_u8Disable(4);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== EXTI_u8SetSenseLevel test functions ==========================*/

void test_EXTI_u8SetSenseLevel1(void)
{
    u8 Status = EXTI_u8SetSenseLevel(4, EXTI_RISING_EDGE_SC);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_EXTI_u8SetSenseLevel2(void)
{
    u8 Status = EXTI_u8SetSenseLevel(EXTI_INT2, EXTI_LOW_LEVEL_SC);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== EXTI_u8SetCallBack test functions ==========================*/

void CallBackFunc(void) {}

void test_EXTI_u8SetCallBack(void)
{
    u8 pinState;
    u8 Status = EXTI_u8SetCallBack(6, CallBackFunc);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== Main function ==========================*/

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_EXTI_u8Enable);

    RUN_TEST(test_EXTI_u8Disable);

    RUN_TEST(test_EXTI_u8SetSenseLevel1);
    RUN_TEST(test_EXTI_u8SetSenseLevel2);

    RUN_TEST(test_EXTI_u8SetCallBack);

    return UNITY_END();
}