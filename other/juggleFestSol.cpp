/**
 * @file juggleFestSol.cpp
 * Solve the juggle fest planning problem.
 *
 * @author Si Chen
 * @date April 2015
 */

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

/**
 * A class that contains the information of circuits and jugglers from the input file parsed into objects,
 * and a method to allocate each juggler into the circuits.
 */
class JugglerFest{

	struct circuit{
		unsigned int circuit_num;

		unsigned int circuit_H;
		unsigned int circuit_E;
		unsigned int circuit_P;

		std::vector<unsigned int> members;	//juggler_num of jugglers assigned to this circuit, sorted in increasing order of match value

		circuit(unsigned int num){
			circuit_num = num;
		}
	};

	struct juggler{
		unsigned int juggler_num;

		unsigned int juggler_H;
		unsigned int juggler_E;
		unsigned int juggler_P;

		std::vector<unsigned int> preference;	//Ordered as read from the input
		std::vector<unsigned int> match;		//In increasing order, index corresponds to the circuit_num

		bool allocated;
		juggler(unsigned int num){
			juggler_num = num;
			allocated = false;
		}
	};

	unsigned int max_circuit_size;

	std::vector<circuit*> circuits;
	std::vector<juggler*> jugglers;

	/**
	 * Private helper function for allocating the current juggler into appropriate circuit. 
	 * Jugglers in a circuit are sorted in increasing order of their match score to the current circuit.
	 *
     * (1) First we go through the preference of each juggler in order, if the preferred circuit
     * 		is not full yet, we simply put the juggler into that circuit.
     * 			(A)If the target circuit is empty, simply add the juggler into the circuit.
     *			(B)Otherwise if the target circuit is not empty, we iterate through the circuit
     *				to look for the appropriate spot to add the juggler.
     * (2) If the preferred circuit is already full, we compare the match score of the current 
     * 		juggler to the lowest match value of the jugglers in the circuit. If the current 
     *		juggler is a better match, add the current juggler to the appropriate place of the
     *		circuit, and recursively allocate again the juggler that is "exchanged out".
     * (3) If the preferred circuit is already full and the current juggler does not have a higher
     *		match score than any jugglers in that circuit, continue and check the next preferred 
     *		circuit.
     * (4) If after checking all the preferred circuits the juggler still doesn't have a fit, check
     * 		all the circuits again until we find a fit.
     *			(A)If the current juggler has a higher match score than the minimum match score of 
     *				that circuit, exhange those two jugglers and re-allocate the "exchanged" one.
     *			(B)Otherwise if a circuit is still not full, put this juggler into thta circuit.
     * @param the number representing the current juggler being allocated.
	 */
	void checkPreference(int jNum){
		// std::cout << "check preference " << jNum << std::endl;
		for(int i = 0 ; i < jugglers[jNum]->preference.size(); i++){	//First check which circuit to add this juggler based on preference

			if(jugglers[jNum]->allocated){
				return;
			}

			int currCircuit = jugglers[jNum]->preference[i];
			int cSize = circuits[currCircuit]->members.size();			
			int currMatch = jugglers[jNum]->match[currCircuit];

			if(cSize == 0){	//The circuit is currently empty, put the juggler in this circuit				
				circuits[currCircuit]->members.push_back(jNum);
				jugglers[jNum]->allocated = true;
				break;
			}

			else if(cSize < max_circuit_size){	//The circuit is not full yet, put the juggler in the circuit to maintain the increasing order
				for(int j = 0; j < cSize; j++){
					int nextJuggler = circuits[currCircuit]->members[j];
					int nextMatch = jugglers[nextJuggler]->match[currCircuit];
					if( currMatch < nextMatch){
						std::vector<unsigned int>::iterator iter = circuits[currCircuit]->members.begin();
						circuits[currCircuit]->members.insert(iter + j, jNum);
						jugglers[jNum]->allocated = true;
						break;
					}
					else if(j == cSize - 1){	//The current juggler has the highest match value
						circuits[currCircuit]->members.push_back(jNum);
						jugglers[jNum]->allocated = true;
						break;	
					}
				}
			}

			else if(cSize == max_circuit_size){ 	//The current circuit is full, check to see if the juggler fits the circuit better than those in it				
				int minJuggler = circuits[currCircuit]->members[0];
				int minMatch = jugglers[minJuggler]->match[currCircuit];
				if(currMatch > minMatch){
					circuits[currCircuit]->members.erase( circuits[currCircuit]->members.begin() );	//Erase the juggler with lowest match from current circuit

					for(int j = 0; j < cSize; j++){
						int nextJuggler = circuits[currCircuit]->members[j];
						int nextMatch = jugglers[nextJuggler]->match[currCircuit];
						if( currMatch < nextMatch){
							std::vector<unsigned int>::iterator iter = circuits[currCircuit]->members.begin();
							circuits[currCircuit]->members.insert(iter + j, jNum);
							jugglers[jNum]->allocated = true;
							break;					
						}
						else if(j == cSize - 1){	//The current juggler has the highest match value
						circuits[i]->members.push_back(jNum);
						jugglers[jNum]->allocated = true;
						break;	
						}
					}
					jugglers[minJuggler]->allocated = false;
					checkPreference(minJuggler);
					if(!jugglers[minJuggler]->allocated){
						checkAll(minJuggler);
					}
				}
			}
		}	//Preference for loop
	}

	void checkAll(int jNum){
		// std::cout << "check all " << jNum << std::endl;
		for(int i = 0 ; i < circuits.size(); i++){	//First check which circuit to add this juggler based on preference

			if(jugglers[jNum]->allocated){
				return;
			}
			
			int cSize = circuits[i]->members.size();		
			int currMatch = jugglers[jNum]->match[i];			

			if(cSize == 0){	//The circuit is currently empty, put the juggler in this circuit				
				circuits[i]->members.push_back(jNum);
				jugglers[jNum]->allocated = true;
				break;
			}

			else if(cSize < max_circuit_size){	//The circuit is not full yet, put the juggler in the circuit to maintain the increasing order
				for(int j = 0; j < cSize; j++){
					int nextJuggler = circuits[i]->members[j];
					int nextMatch = jugglers[nextJuggler]->match[i];
					if( currMatch < nextMatch){
						std::vector<unsigned int>::iterator iter = circuits[i]->members.begin();
						circuits[i]->members.insert(iter + j, jNum);
						jugglers[jNum]->allocated = true;
						break;
					}
					else if(j == cSize - 1){	//The current juggler has the highest match value
						circuits[i]->members.push_back(jNum);
						jugglers[jNum]->allocated = true;
						break;	
					}
				}
			}

			else if(cSize == max_circuit_size){ 	//The current circuit is full, check to see if the juggler fits the circuit better than those in it				
				int minJuggler = circuits[i]->members[0];
				int minMatch = jugglers[minJuggler]->match[i];
				if(currMatch > minMatch){
					circuits[i]->members.erase( circuits[i]->members.begin() );	//Erase the juggler with lowest match from current circuit

					for(int j = 0; j < cSize; j++){
						int nextJuggler = circuits[i]->members[j];
						int nextMatch = jugglers[nextJuggler]->match[i];
						if( currMatch < nextMatch){
							std::vector<unsigned int>::iterator iter = circuits[i]->members.begin();
							circuits[i]->members.insert(iter + j, jNum);
							jugglers[jNum]->allocated = true;
							break;					
						}
						else if(j == cSize - 1){	//The current juggler has the highest match value
						circuits[i]->members.push_back(jNum);
						jugglers[jNum]->allocated = true;
						break;	
						}
					}
					jugglers[minJuggler]->allocated = false;
					checkPreference(minJuggler);
					if(!jugglers[minJuggler]->allocated){
						checkAll(minJuggler);
					}
				}
			}

			
		}	//All for loop
	}


public:
	/**
	 * Parses and constructs a JugglerFest from the input file.
     * The input file is assumed to be valid and contains the information
     * in a particular format.
     * 
     * @param string representation of the name of the input file
	 */
	JugglerFest(const std::string& filename){
		std::ifstream input(filename);

		if(input.is_open()){
			std::istream_iterator<std::string> iter(input);

			while(!input.eof()){
				if(*iter == "C"){	//Reading and parsing the circuits

					iter++;	//Now the iterator is on circuit_num

					std::string circuitNumStr = *iter;
					unsigned int circuitNumStrUInt = 0;

					for(int i = 1; i < circuitNumStr.size(); i++){	//Convert the juggler number into an unsigned int
						circuitNumStrUInt = circuitNumStrUInt * 10 + ((unsigned int)circuitNumStr[i] - '0');						
					}

					circuit* currCircuit = new circuit(circuitNumStrUInt);
					
					iter++;	//Now the iterator is on H					
					std::string parseH = *iter;									
					int szH = parseH.size();										
					if(szH == 3){
						currCircuit->circuit_H = (unsigned int)(parseH[2] - '0');						
					}
					else if(szH == 4){
						currCircuit->circuit_H = (((unsigned int) (parseH[2] - '0') ) * 10) + (unsigned int) (parseH[3] - '0');
					}

					iter++;	//Now the iterator is on E
					std::string parseE = *iter;
					int szE = parseE.size();
					if(szE == 3){
						currCircuit->circuit_E = (unsigned int)(parseE[2] - '0');
					}
					else if(szE == 4){
						currCircuit->circuit_E = (((unsigned int) (parseE[2] - '0') ) * 10) + (unsigned int) (parseE[3] - '0');
					}

					iter++; //Now the iterator is on P					
					std::string parseP = *iter;
					int szP = parseP.size();
					if(szP == 3){
						currCircuit->circuit_P = (unsigned int)(parseP[2] - '0');						
					}
					else if(szP == 4){
						currCircuit->circuit_P = (((unsigned int) (parseP[2] - '0') ) * 10) + (unsigned int) (parseP[3] - '0');						
					}

					circuits.push_back(currCircuit);
				}

				if(*iter == "J"){	//Reading and parsing the jugglers

					iter++;		//Now the iterator is on juggler_num
					std::string jugglerNumStr = *iter;
					unsigned int jugglerNumStrUInt = 0;

					for(int i = 1; i < jugglerNumStr.size(); i++){	//Convert the juggler number into an unsigned int
						jugglerNumStrUInt = jugglerNumStrUInt * 10 + ((unsigned int)jugglerNumStr[i] - '0');						
					}

					juggler* currJuggler = new juggler(jugglerNumStrUInt);

					iter++;		//Now the iterator is on H
					std::string parseH = *iter;									
					int szH = parseH.size();										
					if(szH == 3){
						currJuggler->juggler_H = (unsigned int)(parseH[2] - '0');						
					}
					else if(szH == 4){
						currJuggler->juggler_H = (((unsigned int) (parseH[2] - '0') ) * 10) + (unsigned int) (parseH[3] - '0');
					}

					iter++;		//Now the iterator is on E
					std::string parseE = *iter;
					int szE = parseE.size();
					if(szE == 3){
						currJuggler->juggler_E = (unsigned int)(parseE[2] - '0');
					}
					else if(szE == 4){
						currJuggler->juggler_E = (((unsigned int) (parseE[2] - '0') ) * 10) + (unsigned int) (parseE[3] - '0');
					}

					iter++;		//Now the iterator is on P
					std::string parseP = *iter;
					int szP = parseP.size();
					if(szP == 3){
						currJuggler->juggler_P = (unsigned int)(parseP[2] - '0');						
					}
					else if(szP == 4){
						currJuggler->juggler_P = (((unsigned int) (parseP[2] - '0') ) * 10) + (unsigned int) (parseP[3] - '0');
					}

					iter++;		//Now the iterator is on the list of preference
					std::string preference = *iter;					
					unsigned int jugglerPreferenceStrUInt = 0;
					unsigned int circuitNumUInt;
					for(int i = 1; i < preference.size(); i++){	//Preference circuits are stored as int
						if(preference[i] == 'C'){
							continue;
						}
						else if(preference[i] == ','){
							(currJuggler->preference).push_back(jugglerPreferenceStrUInt);
							jugglerPreferenceStrUInt = 0;
							continue;
						}
						else if(i == (preference.size() - 1)){
							circuitNumUInt =  (unsigned int)(preference[i] - '0');
							jugglerPreferenceStrUInt = jugglerPreferenceStrUInt * 10 + circuitNumUInt;
							(currJuggler->preference).push_back(jugglerPreferenceStrUInt);
							continue;
						}
						circuitNumUInt =  (unsigned int)(preference[i] - '0');
						jugglerPreferenceStrUInt = jugglerPreferenceStrUInt * 10 + circuitNumUInt;						
					}

					jugglers.push_back(currJuggler);
					
					//Calculate the match of each circuit for this juggler
					for(int i = 0; i < circuits.size(); i++){
						int matchValue = circuits[i]->circuit_H * currJuggler->juggler_H +
										 circuits[i]->circuit_E * currJuggler->juggler_E +
										 circuits[i]->circuit_P * currJuggler->juggler_P;
						currJuggler->match.push_back(matchValue);
					}			
				}
				iter++;
			}
		}
		
		max_circuit_size = jugglers.size() / circuits.size();	//Get the size of each circuit
		input.close();
	}

	
	/**
	 * Public function for planning the juggler fest and outputting the result
	 * in the format as given in the example.
     * This function simply calls the private helper function for each juggler.     
     * The calling JugglerFest object is assumed to be valid.
	 */
	void allocate(){
		// std::cout << "__________TEST__________\n";

		// // std::cout << circuits.size() << std::endl;
		// // std::cout << jugglers.size() << std::endl;
		// for(int i = 0; i < jugglers.size(); i++){
		// 		std::cout << "J" << i << " ";
		// 		std::cout << "H = " << jugglers[i]->juggler_H << " ";
		// 		std::cout << "E = " << jugglers[i]->juggler_E << " ";
		// 		std::cout << "P = " << jugglers[i]->juggler_P << " ";
		// 	for(int j = 0; j < jugglers[i]->preference.size(); j++){
		// 		std::cout << jugglers[i]->preference[j] << " ";
		// 	}
		// 	std::cout << std::endl;
		// }

		// std::cout << "__________TEST__________\n";


		for(int i = jugglers.size() - 1; i >= 0; i--){
			// std::cout << jugglers[i]->juggler_num << std::endl;
			checkPreference(i);
			if(!jugglers[i]->allocated){				
				checkAll(i);
			}
		}

		// std::cout << "__________TEST__________\n";
		// for(int i = 0; i < circuits.size(); i++){
			
		// 		std::cout << circuits[i]->members.size() << std::endl;
		// 		// break;
			
		// }
		// std::cout << "__________TEST__________\n";

		// Output the result in required format
		for(int i = circuits.size() - 1; i >= 0; i--){
			std::cout << "C" << i << " "; 
			for(int j = circuits[i]->members.size() - 1; j >= 0; j--){
				int jNum = circuits[i]->members[j];
				std::cout << "J" << circuits[i]->members[j] << " ";
				for(int c = 0; c < jugglers[jNum]->preference.size(); c++){
					int preferredCircuit = jugglers[jNum]->preference[c];
					std::cout << "C" << preferredCircuit << ":" << jugglers[jNum]->match[preferredCircuit];
					if(c != jugglers[jNum]->preference.size() - 1){
						std::cout << " ";
					}
				}
				if(j != 0){
					std::cout << ", ";
				}
			}
			std::cout << std::endl;
		}
	}
};

int main(){
	// JugglerFest jf("input.txt");
	JugglerFest jf("jugglefest.txt");
	std::ofstream out("output.txt");
	std::cout.rdbuf(out.rdbuf());
	jf.allocate();

	return 0;
}