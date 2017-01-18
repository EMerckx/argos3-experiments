#ifndef EMPTY_LOOP_FUNCTIONS_H
#define EMPTY_LOOP_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>

using namespace argos;

class CEmptyLoopFunctions : public CLoopFunctions {
public:
	CEmptyLoopFunctions();
	virtual ~CEmptyLoopFunctions() {}

	virtual void Init(TConfigurationNode& t_tree);
	virtual void Reset();
	virtual void Destroy();
	virtual void PreStep();

private:

};

#endif