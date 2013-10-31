//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
/*==============================================================================================

	Experiment 1

	Goal: Basic use of simple logic and emotions.

	Inputs:
		- Vision [Nothing, Food, Rock]
		- Smell [Nothing, Rot]

	Outputs:
		- Mouth [Eat, Don't Eat]

	Rewards:
		+ 100 = Vision(Food) AND Smell(Nothing) AND Mouth(Eat)

	Punish:
		- 10 = NOT(Vision(Food) AND Smell(Nothing) AND Mouth(Eat))
		- 40 = Mouth(Eat) AND Vision(Rock)
		- 25 = Mouth(Eat) AND Vision(Food) AND Smell(Rot)

==============================================================================================*/
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
/*==============================================================================================

	Includes & Variable Declarations

----------------------------------------------------------------------------------------------*/

	#include <stdio.h>
	#include "Includes.h"

//==============================================================================================
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
/*==============================================================================================

	Main Procedure

----------------------------------------------------------------------------------------------*/

	int main(void)
	{
		printf("Hello World\n");
		Neuron N;
		N.Test();
		Neural_Net NN;
		NN.Test();
		return 0;
	}

//==============================================================================================
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------