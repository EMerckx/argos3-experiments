/*
 * BASED ON SOURCE: http://www.argos-sim.info/forum/viewtopic.php?t=82
 */

#include "loop_functions_variable.h"

#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/core/wrappers/lua/lua_controller.h>

/****************************************/
/****************************************/

CLoopFunctionsVariable::CLoopFunctionsVariable() { }

/****************************************/
/****************************************/

void CLoopFunctionsVariable::Init(TConfigurationNode& t_tree) { }

/****************************************/
/****************************************/

void CLoopFunctionsVariable::Reset() { }

/****************************************/
/****************************************/

void CLoopFunctionsVariable::Destroy() { }

/****************************************/
/****************************************/

void CLoopFunctionsVariable::PreStep() { }

/****************************************/
/****************************************/

void CLoopFunctionsVariable::PostStep() { 
	// retrieve the foot-bot entities from the space
	CSpace::TMapPerType& cFootBotMap = 
		GetSpace().GetEntitiesByType("foot-bot");
	
	// iterate over every foot-bot
	for(CSpace::TMapPerType::iterator it = cFootBotMap.begin(); 
		it != cFootBotMap.end();
		it++) {

		// cast the iterator to a foot-bot entity
      	CFootBotEntity& cFootBot = 
      		*any_cast<CFootBotEntity*>(it->second);

      	// get and log the number variable from the foot-bot
      	GetNumber(cFootBot);
	}

	LOG << "----- \n";
}

/****************************************/
/****************************************/

void CLoopFunctionsVariable::GetNumber(CFootBotEntity& c_foot_bot) {

	// get the controller from the foot-bot
	// and cast it to a lua controller
   	CLuaController& cLuaContr = dynamic_cast<CLuaController&>(
   		c_foot_bot.GetControllableEntity().GetController());

   	// retrieve the "robot" table from the controller - NOTE: getglobal
   	lua_getglobal(cLuaContr.GetLuaState(), "robot");

   	// retrieve the "number" variable from the table - NOTE: getfield
   	lua_getfield(cLuaContr.GetLuaState(), -1, "number");

   	// check the fact that the variable "number" is found
   	// and check if the variable is a number
   	if(! lua_isnil(cLuaContr.GetLuaState(), -1)
   		&& lua_isnumber(cLuaContr.GetLuaState(), -1)) {

   		// the variable exists and it's a number, so get it
   		Real fNumber = lua_tonumber(cLuaContr.GetLuaState(), -1);

   		// log the retrieved number
   		LOG << "Number in loop functions: " << fNumber << "\n";
   	}

   	// don't forget to clean the Lua stack
  	lua_pop(cLuaContr.GetLuaState(), 2);
}

/****************************************/
/****************************************/

REGISTER_LOOP_FUNCTIONS(CLoopFunctionsVariable, "loop_functions_variable")