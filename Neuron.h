//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
/*==============================================================================================

	Neuron.h

	Classes:
	- Neuron - [N]
	- LN_Neuron - "List Node - Neuron"

	Neuron - [N]
		Each and every unique idea is represented in a single neuron, each neuron can
	be composed of mutliple other neurons, each composition may be simple or complex
	(determined by complexity rating). Neural nets solver problems by determining which
	Neurons / ideas seem to be true at the moment, and use the relations between them to
	determine probable outcomes of each available action.

==============================================================================================*/

	class Neuron;
	class LN_Neuron;

	#ifndef __NEURON_H_INCLUDED__
		#define __NEURON_H_INCLUDED__
		#include "Includes.h"

		/*==============================================================================================

			Class: Neuron - [N]

		==============================================================================================*/

			class Neuron {

				public:
					// Finished

					// Unfinished
					// Constructor
					Neuron();

					// Identification
					char* Alias;
					int ID;

					// Test
					void Test();
					Neural_Net * NN;
					Neural_Group * Parent_NG;

					// List from NN
					Neuron * Next_N;
					Neuron * Prev_N;


						/*==============================================================================================
							Input / Output
						----------------------------------------------------------------------------------------------*/
							/*==============================================================================================
								Reports / Generated Info
							----------------------------------------------------------------------------------------------*/
								// Prints a report, user specifies how much detail to give for each category.
								void Print_Report(
									// Positive integers: Print active
									// Negative integers: Print all
									FILE * FD = stdout, // File decriptor for report output
									int SD = 1, // Synapse detail
									int ND = 1); // Neuron detail

								// Prints header for NG
								void Print_Header(FILE * FD = stdout);
								void Print_Label(FILE * FD = stdout);
						/*----------------------------------------------------------------------------------------------
							[END] Input / Output
						==============================================================================================*/

				private:

					
			};

		/*============================================================================================*/
		//----------------------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------------------
		/*==============================================================================================

			Class: LN_Neuron - "List Node - Neuron"

		==============================================================================================*/

			class LN_Neuron {

				public:
					// Finished

					// Unfinished
					Neuron * Next;
					Neuron * Prev;
					Neuron * Target;
					bool Permanent;
			};

		/*============================================================================================*/

	#endif

/*============================================================================================*/
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------