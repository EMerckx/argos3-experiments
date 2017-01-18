#ifndef FOOT_BOT_WITH_LOOP_FUNCTION_INTERACTION_LOOP_FUNCTIONS_H
#define FOOT_BOT_WITH_LOOP_FUNCTION_INTERACTION_LOOP_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>

using namespace argos;

class CFootBotInteractionLoopFunctions : public CLoopFunctions {
public:
	CFootBotInteractionLoopFunctions();
	virtual ~CFootBotInteractionLoopFunctions() {}

	virtual void Init(TConfigurationNode& t_tree);
	virtual void Reset();
	virtual void Destroy();
	virtual void PreStep();

private:

};

#endif