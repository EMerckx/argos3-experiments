#include "loop_functions_log_float_number.h"

#include <argos3/core/utility/logging/argos_log.h>

#include <iomanip>
#include <sstream>

/****************************************/
/****************************************/

CLoopFunctionsLogFloatNumber::CLoopFunctionsLogFloatNumber() { }

/****************************************/
/****************************************/

void CLoopFunctionsLogFloatNumber::Init(TConfigurationNode& t_tree) { }

/****************************************/
/****************************************/

void CLoopFunctionsLogFloatNumber::Reset() { }

/****************************************/
/****************************************/

void CLoopFunctionsLogFloatNumber::Destroy() { }


/****************************************/
/****************************************/

void CLoopFunctionsLogFloatNumber::PreStep() { 

	// log Real number
	// logging result: 123.123
	Real num1 = 123.123456789;
	LOG << "[loop-func] num1 = " << num1 << " \n";

	// log Real number (divide)
	// logging result: 3
	Real num2 = 10 / 3;
	LOG << "[loop-func] num2 = " << num2 << " \n";


	// log Real number (divided by Real numbers)
	// logging result: 3.33333
	Real num3 = 10;
	Real num4 = 3;
	Real num5 = num3 / num4;
	LOG << "[loop-func] num5 = " << num5 << " \n";

	// log Real number (converted to string)
	// logging result: 123.123
	Real num6 = 123.123456789;
	std::ostringstream ss6;
	ss6 << num6;
	std::string num6str(ss6.str());
	LOG << "[loop-func] num6 = " << num6str << " \n";


	// log Real number (converted to string with set precision)
	// logging result: 123.1234567890
	Real num7 = 123.123456789;
	std::ostringstream ss7;
	ss7 << std::fixed << std::setprecision(10) << num7;
	std::string num7str(ss7.str());
	LOG << "[loop-func] num7 = " << num7str << " \n";

	// log Real number (with set precision)
	// logging result: 123.1234567890
	Real num8 = 123.123456789;
	LOG << "[loop-func] num8 = " << std::fixed << std::setprecision(10) << num8 << " \n";

	// NOTE: after execution of set precision, 
	// the following step has the same precision in the log!
	// At step 1, the logging for num1 is 123.123.
	// At step 2, the logging for num1 is 123.1234567890.
	// Hence, the precision is stil active!!

}

/****************************************/
/****************************************/

REGISTER_LOOP_FUNCTIONS(CLoopFunctionsLogFloatNumber, "loop_functions_log_float_number")