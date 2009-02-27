#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"
//#include "tests_tasksManagement_sequence1.h"
//#define _XOPEN_SOURCE 500
//include <unistd.h>

TestRef ResourceManagementTest_seq4_t1_instance(void);
TestRef ResourceManagementTest_seq4_t2_instance(void);
TestRef ResourceManagementTest_seq4_t3_instance(void);

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(ResourceManagementTest_seq4_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	TestRunner_runTest(ResourceManagementTest_seq4_t2_instance());
}

TASK(t3)
{
	TestRunner_runTest(ResourceManagementTest_seq4_t3_instance());
}