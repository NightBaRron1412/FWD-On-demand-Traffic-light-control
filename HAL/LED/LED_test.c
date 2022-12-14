/** @file LED_test.c
 *
 * @brief A file that includes unit testing for LED functions.
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
#include "LED_interface.h"

/*========================== setUp & tearDown Functions ==========================*/
void setUp(void)
{
    /* set stuff up here */
}

void tearDown(void)
{
    /* clean stuff up here */
}

/*========================== LED_u8On test functions ==========================*/

void test_LED_u8On(void)
{
    u8 Status = LED_u8On(7);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== LED_u8Off test functions ==========================*/

void test_LED_u8Off(void)
{
    u8 Status = LED_u8Off(7);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== LED_u8Toggle test functions ==========================*/

void test_LED_u8Toggle(void)
{
    u8 Status = LED_u8Toggle(7);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== Main function ==========================*/

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_LED_u8On);

    RUN_TEST(test_LED_u8Off);

    RUN_TEST(test_LED_u8Toggle);

    return UNITY_END();
}