#ifndef LOOP_FUNCTIONS_LOG_FLOAT_NUMBER_H
#define LOOP_FUNCTIONS_LOG_FLOAT_NUMBER_H

#include <argos3/core/simulator/loop_functions.h>

using namespace argos;

class CLoopFunctionsLogFloatNumber : public CLoopFunctions {
public:
	CLoopFunctionsLogFloatNumber();
	virtual ~CLoopFunctionsLogFloatNumber() {}

	virtual void Init(TConfigurationNode& t_tree);
	virtual void Reset();
	virtual void Destroy();
	virtual void PreStep();

private:

};

#endif