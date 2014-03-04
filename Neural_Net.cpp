//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
/*==============================================================================================

	Neural_Net.cpp

==============================================================================================*/

	#include "Neural_Net.h"
	//using namespace std;
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
		Neural Groups
	----------------------------------------------------------------------------------------------*/

		// Create a new neural group and return pointer
		Neural_Group * Neural_Net::New_NG() {

			// Declare report
			if (NN_Modification_Active) {
				Print_Header(NN_Modification);
				fprintf(NN_Modification, " <CREATING NEW NEURAL GROUP>");
			};

			Neural_Group * NG = new Neural_Group();
			NG->ID = Next_NG_ID; // Assign ID
			Next_NG_ID++;
			NG->Parent_NN = this; // Assign parent NN

			// Add NG to NG list
			if (First_NG == NULL || Last_NG == NULL) {
				First_NG = NG;
				Last_NG = NG;
			} else {
				Last_NG->Next_NG = NG;
				NG->Prev_NG = Last_NG;
				Last_NG = NG;
			};

			return NG;
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

			// Initialize IDs + Lists
			ID = 0;
			Next_NG_ID = 1;
			First_NG = NULL;
			Last_NG = NULL;

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
			if (std::abs(TND)>0) {
				Print_Header(FD);
				Print_Header(FD);
				fprintf(FD, " <PRINTING TIME NODES>");
				Print_Header(FD);
				fprintf(FD, " -- Displaying ");
				if (TND > 0) fprintf(FD, "active");
				else fprintf(FD, "all");
				fprintf(FD, " time nodes");
				Print_Header(FD);
				fprintf(FD, " -- Level of detail: %i", int(std::abs(TND)));
				Print_Header(FD);
			}

			// Print Channel Nodes
			if (std::abs(CHD)>0) {
				Print_Header(FD);
				Print_Header(FD);
				fprintf(FD, " <PRINTING CHANNEL NODES>");
				Print_Header(FD);
				fprintf(FD, " -- Displaying ");
				if (CHD > 0) fprintf(FD, "active");
				else fprintf(FD, "all");
				fprintf(FD, " channel nodes");
				Print_Header(FD);
				fprintf(FD, " -- Level of detail: %i", int(std::abs(CHD)));
				Print_Header(FD);
			}

			// Declare Neuron Groups
			if (std::abs(NGD)>0) {
				Print_Header(FD);
				Print_Header(FD);
				fprintf(FD, " <PRINTING NEURON GROUPS>");
				Print_Header(FD);
				fprintf(FD, " -- Displaying ");
				if (NGD > 0) fprintf(FD, "active");
				else fprintf(FD, "all");
				fprintf(FD, " neuron groups");
				Print_Header(FD);
				fprintf(FD, " -- Level of detail: %i", int(std::abs(NGD)));
				Print_Header(FD);
			}
			// Print Neuron Groups (+Neurons +Synapses)
			if (std::abs(NGD)>0 || std::abs(ND)>0 || std::abs(SD)>0) {
				//for all neuron groups - print neuron group
				Neural_Group * NG = First_NG;
				while (NG != NULL) {
					NG->Print_Report(FD, SD, ND, NGD);
					NG = NG->Next_NG;
					if (NG != NULL) Print_Header(FD);
				};
			}

		}; 

		// Prints header for NN
		void Neural_Net::Print_Header(FILE * FD) {
			fprintf(FD, "\n[NN:%i]", ID);
		};

	/*============================================================================================*/
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------