/** @file BTN_test.c
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
#include "BTN_interface.h"

/*========================== setUp & tearDown Functions ==========================*/
void setUp(void)
{
    /* set stuff up here */
}

void tearDown(void)
{
    /* clean stuff up here */
}

/*========================== BTN_u8GetButtonState test functions ==========================*/

u8 buttonState;

void test_BTN_u8GetButtonState1(void)
{
    u8 Status = BTN_u8GetButtonState(8, &buttonState);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

void test_BTN_u8GetButtonState2(void)
{
    u8 Status = BTN_u8GetButtonState(1, NULL);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== Main function ==========================*/

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_BTN_u8GetButtonState1);
    RUN_TEST(test_BTN_u8GetButtonState2);

    return UNITY_END();
}