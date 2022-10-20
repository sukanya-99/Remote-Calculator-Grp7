#include "CUnit/Basic.h"
#include "../header/result_suite.h"
#include "../header/result.h"

int init_suite_result(void)
{
return 0;
}

int clean_suite_result(void)
{
return 0;
}

void testSunnyCases2(void)
{
CU_ASSERT_EQUAL(result_Valid("2:3:1"),1);
CU_ASSERT_EQUAL(result_Valid("2:4:9"),1);
CU_ASSERT_EQUAL(result_Valid("2:8:7"),1);

}
void testRainyCases2(void)
{
 CU_ASSERT_EQUAL(result_Valid("2;7"),0);
CU_ASSERT_EQUAL(result_Valid("8;8"),0);
CU_ASSERT_EQUAL(result_Valid("7;9"),0);
}
