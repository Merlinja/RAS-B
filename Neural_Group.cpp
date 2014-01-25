//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
/*==============================================================================================

	Neural_Group.cpp

==============================================================================================*/

	#include "Neural_Group.h"

/*==============================================================================================

	Finished

==============================================================================================*/

/*==============================================================================================

	Unfinished

==============================================================================================*/

	/*==============================================================================================
		Constructor
	----------------------------------------------------------------------------------------------*/

		Neural_Group::Neural_Group() {

			// Initialize Alias
			Alias = "New Neural Group";

			ID = 0;
			Parent_NN = NULL;

			Next_NG = NULL;
			Prev_NG = NULL;

		};

	/*==============================================================================================
		Reports / Generated Info
	----------------------------------------------------------------------------------------------*/
		// Prints a report, user specifies how much detail to give for each category.
		void Neural_Group::Print_Report(
			// Positive integers: Print active
			// Negative integers: Print all
			FILE * FD, // File decriptor for report output
			int SD, // Synapse detail
			int ND, // Neuron detail
			int NGD) // Neural Group detail
		{
			// Detail: Declare report
			if (abs(NGD)>0) {
				Print_Header(FD);
				fprintf(FD, " <PRINTING REPORT>");
				Print_Header(FD);
				fprintf(FD, " -- Alias: \"%s\"", Alias);
			};

			// Detail: Print prev / next NG
			if (abs(NGD)>1) {

				// Print Prev
				Print_Header(FD);
				fprintf(FD, " -- Prev_NG: ");
				if (Prev_NG == NULL) fprintf(FD, "NULL");
				else Prev_NG->Print_Label(FD);

				// Print next
				Print_Header(FD);
				fprintf(FD, " -- Next_NG: ");
				if (Next_NG == NULL) fprintf(FD, "NULL");
				else Next_NG->Print_Label(FD);
			};

		}; 

		// Prints header for NG
		void Neural_Group::Print_Header(FILE * FD) {
			Parent_NN->Print_Header(FD);
			Print_Label(FD);
		};

		// Prints label for NG
		void Neural_Group::Print_Label(FILE * FD) {
			fprintf(FD, "[NG:%i]", ID);
		};

/*============================================================================================*/
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------