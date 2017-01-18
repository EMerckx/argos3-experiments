#ifndef FOOT_BOT_WITH_LOOP_FUNCTION_INTERACTION_LOOP_FUNCTIONS_H
#define FOOT_BOT_WITH_LOOP_FUNCTION_INTERACTION_LOOP_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>

using namespace argos;

class CFootBotInteractionLoopFunctions : public CLoopFunctions {
public:
	CFootBotInteractionLoopFunctions();
	virtual ~CFootBotInteractionLoopFunctions() {}

	virtual void Init(TConfigurationNode& t_tree);
	virtual void Reset();
	virtual void Destroy();
	virtual void PreStep();
	virtual void PostStep();

private:
	void GetNumber(CFootBotEntity& c_fb);

};

#endif