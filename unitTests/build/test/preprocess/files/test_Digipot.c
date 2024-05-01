#include "build/test/mocks/mock_Pin.h"
#include "../Digitpot.h"
#include "/usr/local/bundle/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


void setUp(void) {

}



void tearDown(void) {

}











void test_CalculateTapPosition_desired_greater_than_max(void) {





    unsigned int desired_resistance = 15000;

    unsigned int max_resistance = 10000;





    unsigned char result = CalculateTapPosition(desired_resistance, max_resistance);





    UnityAssertEqualNumber((UNITY_INT)((255)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}











void test_CalculateTapPosition_main_branch(void) {





    unsigned int desired_resistance = 5000;

    unsigned int max_resistance = 10000;





    unsigned char result = CalculateTapPosition(desired_resistance, max_resistance);





    UnityAssertEqualNumber((UNITY_INT)((127)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

}
