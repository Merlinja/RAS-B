//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
/*==============================================================================================

	Neural_Net.cpp

==============================================================================================*/

	#include "Neural_Net.h"

/*==============================================================================================

	Finished

==============================================================================================*/

/*==============================================================================================

	Unfinished

==============================================================================================*/

	void Neural_Net::Test()
	{
		printf("Neural Net testn.\n");
		Print_Report();
		N->Test();
	};

	/*==============================================================================================
		Constructor
	----------------------------------------------------------------------------------------------*/

		Neural_Net::Neural_Net() {

			// Initialize file descriptors.
			NN_Modification = stdout;
			NN_Modification_Active = true;
			NN_Reports = stdout;
			NN_Reports_Active = true;

			// Initialize Alias
			Alias = "New Neural Network";

			ID = 0;

		};

	/*==============================================================================================
		Reports / Generated Info
	----------------------------------------------------------------------------------------------*/
		// Prints a report, user specifies how much detail to give for each category.
		void Neural_Net::Print_Report(
			// Positive integers: Print active
			// Negative integers: Print all
			FILE * FD, // File decriptor for report output
			int SD, // Synapse detail
			int ND, // Neuron detail
			int NGD, // Neural Group detail
			int TND) // Time Node detail
		{
			// Declare report
			Print_Header(FD);
			fprintf(FD, " <PRINTING REPORT>");

			// Print alias
			Print_Header(FD);
			fprintf(FD, " Alias: \"%s\"", Alias);
		}; 

		// Prints header for NN
		void Neural_Net::Print_Header(FILE * FD) {
			fprintf(FD, "\n[NN:%i]", ID);
		};

	/*============================================================================================*/
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------