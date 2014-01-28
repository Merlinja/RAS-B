#include "Neuron.h"
#include <stdio.h>

void Neuron::Test()
{
	printf("Class function.");
};

	/*==============================================================================================
		Constructor
	----------------------------------------------------------------------------------------------*/

		Neuron::Neuron() {

			// Initialize Alias
			Alias = "New Neuron";

			ID = 0;
			Parent_NG = NULL;

			Next_N = NULL;
			Prev_N = NULL;

		};

	/*==============================================================================================
		Reports / Generated Info
	----------------------------------------------------------------------------------------------*/
		// Prints a report, user specifies how much detail to give for each category.
		void Neuron::Print_Report(
			// Positive integers: Print active
			// Negative integers: Print all
			FILE * FD, // File decriptor for report output
			int SD, // Synapse detail
			int ND) // Neuron detail
		{
			// Detail: Declare report
			if (abs(ND)>0) {
				Print_Header(FD);
				fprintf(FD, " <PRINTING REPORT>");
				Print_Header(FD);
				fprintf(FD, " -- Alias: \"%s\"", Alias);
			};

			// Detail: Print prev / next NG
			if (abs(ND)>1) {

				// Print Prev
				Print_Header(FD);
				fprintf(FD, " -- Prev_N: ");
				if (Prev_N == NULL) fprintf(FD, "NULL");
				else Prev_N->Print_Label(FD);

				// Print next
				Print_Header(FD);
				fprintf(FD, " -- Next_N: ");
				if (Next_N == NULL) fprintf(FD, "NULL");
				else Next_N->Print_Label(FD);
			};

		}; 

		// Prints header for NG
		void Neuron::Print_Header(FILE * FD) {
			Parent_NG->Print_Header(FD);
			Print_Label(FD);
		};

		// Prints label for NG
		void Neuron::Print_Label(FILE * FD) {
			fprintf(FD, "[N:%i]", ID);
		};