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

	int Punish = 0;
	int Reward = 0;
	bool Experiment_Finished = false;

//==============================================================================================
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
/*==============================================================================================

	Main Procedure

----------------------------------------------------------------------------------------------*/

	int main(void) {

	/*==============================================================================================

		[START] - Setup Experiment

	----------------------------------------------------------------------------------------------*/
		// Creat Neural Net

		// Design Neural Net

	/*----------------------------------------------------------------------------------------------

		[END] - Setup Experiment

	==============================================================================================*/
	//----------------------------------------------------------------------------------------------
	/*==============================================================================================

		[START] - Perform Experiment

	----------------------------------------------------------------------------------------------*/
		// Set up variables
		Punish = 0;
		Reward = 0;

		// Define end condition / loop rounds
		while (Experiment_Finished == false) {

			/*==============================================================================================

				[START] - Perform Round

			----------------------------------------------------------------------------------------------*/
				//----------------------------------------------------------------------------------------------
				/*==============================================================================================
					[START] - Inputs
				----------------------------------------------------------------------------------------------*/
					// Generate Inputs

					// Give inputs to NN

				/*----------------------------------------------------------------------------------------------
					[END] - Inputs
				==============================================================================================*/
				//----------------------------------------------------------------------------------------------
				/*==============================================================================================
					[START] - Outputs
				----------------------------------------------------------------------------------------------*/
					// Have NN Proccess Inputs

					// Get Outputs from NN

				/*----------------------------------------------------------------------------------------------
					[END] - Outputs
				==============================================================================================*/
				//----------------------------------------------------------------------------------------------
				/*==============================================================================================
					[START] - Outcome
				----------------------------------------------------------------------------------------------*/
					// Determine Reward/Punishment

					// Apply Reward/Punishment

					// Advance clock on NN

				/*----------------------------------------------------------------------------------------------
					[END] - Outcome
				==============================================================================================*/

				// Determine whether to stop or continue
				Experiment_Finished = true;

			/*----------------------------------------------------------------------------------------------

				[END] - Perform Round

			==============================================================================================*/

		}; // END while

	/*----------------------------------------------------------------------------------------------

		[END] - Perform Experiment

	==============================================================================================*/
	//----------------------------------------------------------------------------------------------
	/*==============================================================================================

		[START] - Conclude Experiment

	----------------------------------------------------------------------------------------------*/
	/*----------------------------------------------------------------------------------------------

		[END] - Conclude Experiment

	==============================================================================================*/
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