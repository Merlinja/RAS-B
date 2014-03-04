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

			Next_N_ID = 1;
			First_N = NULL;
			Last_N= NULL;
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
			if (std::abs(NGD)>0) {
				Print_Header(FD);
				fprintf(FD, " <PRINTING REPORT>");
				Print_Header(FD);
				fprintf(FD, " -- Alias: \"%s\"", Alias);
			};

			// Detail: Print prev / next NG
			if (std::abs(NGD)>1) {

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

			// Print Neurons (+Synapses)
			if (NGD < 0 || std::abs(ND)>0 || std::abs(SD)>0) {

				// IF active or printing existing
				if (NGD < 0 || First_N != NULL) {
					Print_Header(FD);
					Print_Header(FD);
					fprintf(FD, " <PRINTING NEURONS>");
					Print_Header(FD);
				};

				if (NGD < 0 && First_N == NULL) {
					Print_Header(FD);
					fprintf(FD, " -- No neurons found.");
				}

				//for all neurons - print neurons
				Neuron * N = First_N;
				while (N != NULL) {
					N->Print_Report(FD, SD, ND);
					N = N->Next_N;
					if (N != NULL) Print_Header(FD);
					Print_Header(FD);
				};
			}

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

	/*==============================================================================================
		Neurons
	----------------------------------------------------------------------------------------------*/

		// Create a new neuron and return pointer
		Neuron * Neural_Group::New_N() {

			// Declare report
			if (Parent_NN->NN_Modification_Active) {
				Print_Header(Parent_NN->NN_Modification);
				fprintf(Parent_NN->NN_Modification, " <CREATING NEW NEURON>");
			};

			Neuron * N = new Neuron();
			N->ID = Next_N_ID; // Assign ID
			Next_N_ID++;
			N->Parent_NG = this; // Assign parent NG

			// Add NG to NG list
			if (First_N == NULL || Last_N == NULL) {
				First_N = N;
				Last_N = N;
			} else {
				Last_N->Next_N = N;
				N->Prev_N = Last_N;
				Last_N = N;
			};

			return N;
		};

/*============================================================================================*/
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------