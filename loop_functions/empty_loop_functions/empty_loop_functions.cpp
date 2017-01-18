#include "empty_loop_functions.h"

#include <argos3/core/utility/logging/argos_log.h>

/****************************************/
/****************************************/

CEmptyLoopFunctions::CEmptyLoopFunctions() { }

/****************************************/
/****************************************/

void CEmptyLoopFunctions::Init(TConfigurationNode& t_tree) { }

/****************************************/
/****************************************/

void CEmptyLoopFunctions::Reset() { }

/****************************************/
/****************************************/

void CEmptyLoopFunctions::Destroy() { }


/****************************************/
/****************************************/

void CEmptyLoopFunctions::PreStep() { 


	LOG << "This is logged by the loop functions \n";

}

/****************************************/
/****************************************/

REGISTER_LOOP_FUNCTIONS(CEmptyLoopFunctions, "empty_loop_functions")