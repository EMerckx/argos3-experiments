#include "footbot_with_loopfunction_interaction_loopfunctions.h"

#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>

/****************************************/
/****************************************/

CFootBotInteractionLoopFunctions::CFootBotInteractionLoopFunctions() { }

/****************************************/
/****************************************/

void CFootBotInteractionLoopFunctions::Init(TConfigurationNode& t_tree) { }

/****************************************/
/****************************************/

void CFootBotInteractionLoopFunctions::Reset() { }

/****************************************/
/****************************************/

void CFootBotInteractionLoopFunctions::Destroy() { }


/****************************************/
/****************************************/

void CFootBotInteractionLoopFunctions::PreStep() { 


	LOG << "This is logged by the loop functions \n";

}

/****************************************/
/****************************************/

REGISTER_LOOP_FUNCTIONS(CFootBotInteractionLoopFunctions, "footbot_with_loopfunction_interaction")