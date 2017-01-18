#ifndef LOOP_FUNCTIONS_VARIABLE_H
#define LOOP_FUNCTIONS_VARIABLE_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>

using namespace argos;

class CLoopFunctionsVariable : public CLoopFunctions {
public:
	CLoopFunctionsVariable();
	virtual ~CLoopFunctionsVariable() {}

	virtual void Init(TConfigurationNode& t_tree);
	virtual void Reset();
	virtual void Destroy();
	virtual void PreStep();
	virtual void PostStep();

private:
	void GetNumber(CFootBotEntity& c_fb);

};

#endif