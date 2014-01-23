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
			int CHD, // Channel node detail
			int TND) // Time Node detail
		{
			// Declare report
			Print_Header(FD);
			fprintf(FD, " <PRINTING REPORT>");
			Print_Header(FD);
			fprintf(FD, " -- Alias: \"%s\"", Alias);

			// Print Time Nodes
			if (abs(TND)>0) {
				Print_Header(FD);
				Print_Header(FD);
				fprintf(FD, " <PRINTING TIME NODES>");
				Print_Header(FD);
				fprintf(FD, " -- Displaying ");
				if (TND > 0) fprintf(FD, "active");
				else fprintf(FD, "all");
				fprintf(FD, " time nodes");
				Print_Header(FD);
				fprintf(FD, " -- Level of detail: %i", abs(TND));
				Print_Header(FD);
			}

			// Print Channel Nodes
			if (abs(CHD)>0) {
				Print_Header(FD);
				Print_Header(FD);
				fprintf(FD, " <PRINTING CHANNEL NODES>");
				Print_Header(FD);
				fprintf(FD, " -- Displaying ");
				if (CHD > 0) fprintf(FD, "active");
				else fprintf(FD, "all");
				fprintf(FD, " channel nodes");
				Print_Header(FD);
				fprintf(FD, " -- Level of detail: %i", abs(CHD));
				Print_Header(FD);
			}

			// Declare Neuron Groups
			if (abs(NGD)>0) {
				Print_Header(FD);
				Print_Header(FD);
				fprintf(FD, " <PRINTING NEURON GROUPS>");
				Print_Header(FD);
				fprintf(FD, " -- Displaying ");
				if (NGD > 0) fprintf(FD, "active");
				else fprintf(FD, "all");
				fprintf(FD, " neuron groups");
				Print_Header(FD);
				fprintf(FD, " -- Level of detail: %i", abs(NGD));
				Print_Header(FD);
			}
			// Print Neuron Groups (+Neurons +Synapses)
			if (abs(NGD)>0 || abs(ND)>0 || abs(SD)>0) {
				//for all neuron groups - print neuron group
			}

		}; 

		// Prints header for NN
		void Neural_Net::Print_Header(FILE * FD) {
			fprintf(FD, "\n[NN:%i]", ID);
		};

	/*============================================================================================*/
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------