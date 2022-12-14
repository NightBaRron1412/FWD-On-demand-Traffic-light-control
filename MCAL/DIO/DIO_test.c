/** @file DIO_test.c
 *
 * @brief A file that includes unit testing for DIO functions.
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
#include "DIO_interface.h"

/*========================== setUp & tearDown Functions ==========================*/
void setUp(void)
{
    /* set stuff up here */
}

void tearDown(void)
{
    /* clean stuff up here */
}

/*========================== DIO_u8SetPinDirection test functions ==========================*/

void test_DIO_u8SetPinDirection1(void)
{
    u8 Status = DIO_u8SetPinDirection(6, PIN_0, OUTPUT);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_DIO_u8SetPinDirection2(void)
{
    u8 Status = DIO_u8SetPinDirection(PORT_A, 8, OUTPUT);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_DIO_u8SetPinDirection3(void)
{
    u8 Status = DIO_u8SetPinDirection(PORT_A, PIN_0, 4);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== DIO_u8SetPinValue test functions ==========================*/

void test_DIO_u8SetPinValue1(void)
{
    u8 Status = DIO_u8SetPinValue(6, PIN_1, HIGH);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_DIO_u8SetPinValue2(void)
{
    u8 Status = DIO_u8SetPinValue(PORT_A, 8, HIGH);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_DIO_u8SetPinValue3(void)
{
    u8 Status = DIO_u8SetPinValue(PORT_A, PIN_0, 4);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== DIO_u8TogglePinValue test functions ==========================*/

void test_DIO_u8TogglePinValue1(void)
{
    u8 Status = DIO_u8TogglePinValue(6, PIN_1);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_DIO_u8TogglePinValue2(void)
{
    u8 Status = DIO_u8TogglePinValue(PORT_A, 8);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== DIO_u8GetPinValue test functions ==========================*/

void test_DIO_u8GetPinValue1(void)
{
    u8 pinState;
    u8 Status = DIO_u8GetPinValue(6, PIN_1, &pinState);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_DIO_u8GetPinValue2(void)
{
    u8 pinState;
    u8 Status = DIO_u8GetPinValue(PORT_A, 8, &pinState);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_DIO_u8GetPinValue3(void)
{
    u8 Status = DIO_u8GetPinValue(PORT_A, PIN_0, NULL);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== DIO_u8SetPortDirection test functions ==========================*/

void test_DIO_u8SetPortDirection1(void)
{
    u8 Status = DIO_u8SetPortDirection(6, PORT_OUTPUT);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}
void test_DIO_u8SetPortDirection2(void)
{
    u8 Status = DIO_u8SetPortDirection(PORT_A, 4);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== DIO_u8SetPortValue test functions ==========================*/

void test_DIO_u8SetPortValue1(void)
{
    u8 Status = DIO_u8SetPortValue(6, PORT_HIGH);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== DIO_u8TogglePortValue test functions ==========================*/

void test_DIO_u8TogglePortValue1(void)
{
    u8 Status = DIO_u8TogglePortValue(6);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== DIO_u8GetPortValue test functions ==========================*/

void test_DIO_u8GetPortValue1(void)
{
    u8 portState;
    u8 Status = DIO_u8GetPortValue(6, &portState);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

void test_DIO_u8GetPortValue2(void)
{
    u8 Status = DIO_u8GetPortValue(PORT_A, NULL);
    TEST_ASSERT_EQUAL(STATUS_ERROR, Status);
}

/*========================== Main function ==========================*/

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_DIO_u8SetPinDirection1);
    RUN_TEST(test_DIO_u8SetPinDirection2);
    RUN_TEST(test_DIO_u8SetPinDirection3);

    RUN_TEST(test_DIO_u8SetPinValue1);
    RUN_TEST(test_DIO_u8SetPinValue2);
    RUN_TEST(test_DIO_u8SetPinValue3);

    RUN_TEST(test_DIO_u8TogglePinValue1);
    RUN_TEST(test_DIO_u8TogglePinValue2);

    RUN_TEST(test_DIO_u8GetPinValue1);
    RUN_TEST(test_DIO_u8GetPinValue2);
    RUN_TEST(test_DIO_u8GetPinValue3);

    RUN_TEST(test_DIO_u8SetPortDirection1);
    RUN_TEST(test_DIO_u8SetPortDirection2);

    RUN_TEST(test_DIO_u8SetPortValue1);

    RUN_TEST(test_DIO_u8TogglePortValue1);

    RUN_TEST(test_DIO_u8GetPortValue1);

    return UNITY_END();
}