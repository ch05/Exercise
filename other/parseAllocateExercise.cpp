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
#include <algorithm>
#include <climits>

/**
 * A class that contains the information of circuits and jugglers from the input file parsed into objects,
 * and a method to allocate each juggler into the circuits.
 */
class JugglerFest{

	struct circuit{
		int circuit_num;

		int circuit_H;
		int circuit_E;
		int circuit_P;

		std::vector<int> members;	//juggler_num of jugglers assigned to this circuit, sorted in increasing order of match value

		circuit(int num){
			circuit_num = num;
		}
	};

	struct juggler{
		int juggler_num;

		int juggler_H;
		int juggler_E;
		int juggler_P;

		std::vector<int> preference;	//Ordered as read from the input
		std::vector<int> match;		//In increasing order, index corresponds to the circuit_num

		bool allocated;
		juggler(int num){
			juggler_num = num;
			allocated = false;
		}
	};

	int max_circuit_size;

	std::vector<circuit*> circuits;
	std::vector<juggler*> jugglers;

	/**
	 * Look for the juggler with the minimum match value in the current circuit
     * 
     * @param int representation of the circuit being examined
     * @return int representation of the juggler with minimum match value
	 */
	int findMinMatch(int cNum){
		int min = INT_MAX;
		int juggler = -1;

		for(int i = 0; i < circuits[cNum]->members.size(); i++){
			int currJuggler = circuits[cNum]->members[i];
			int currMatch = jugglers[currJuggler]->match[cNum];
			
			if(currMatch < min){
				min = currMatch;
				juggler = currJuggler;
			}
		}
		return juggler;
	}

	/**
	 * Add juggler jNum into circuit cNum, maintaining the increasing 
	 * order of the members vector
     * 
     * @param int representation of the circuit to add the juggler
     * @param int representation of the juggler being added
	 */
	void addJuggler(int cNum, int jNum){
		bool added = false;
		int jMatch = jugglers[jNum]->match[cNum];
		std::vector<int>::iterator iter = circuits[cNum]->members.begin();

		int cSize = circuits[cNum]->members.size();

		int currJuggler, currMatch;

		for(int i = 0; i < cSize; i++){
			currJuggler = circuits[cNum]->members[i];
			currMatch = jugglers[currJuggler]->match[cNum];
			if(currMatch > jMatch){
				circuits[cNum]->members.insert(iter + i, jNum);
				added = true;
				break;
			}
		}
		if(!added){
			circuits[cNum]->members.push_back(jNum);
		}
		jugglers[jNum]->allocated = true;
	}

	/**
	 * Try allocating juggler jNum based on preference	 
     * 
     * @param int representation of the juggler being allocated
	 */
	void checkPreference(int jNum){
		
		if(jugglers[jNum]->allocated){
				return;
		}
		
		for(int i = 0 ; i < jugglers[jNum]->preference.size(); i++){
						
			int currCircuit = jugglers[jNum]->preference[i];
			int cSize = circuits[currCircuit]->members.size();			
			int currMatch = jugglers[jNum]->match[currCircuit];
			int minJuggler, minMatch;

			if(cSize == max_circuit_size){
				minJuggler = findMinMatch(currCircuit);
				minMatch = jugglers[minJuggler]->match[currCircuit];
				if(minMatch < currMatch){
					circuits[currCircuit]->members.erase(circuits[currCircuit]->members.begin());
					addJuggler(currCircuit, jNum);
					jugglers[minJuggler]->allocated = false;
					checkPreference(minJuggler);
					break;
					if(!jugglers[minJuggler]->allocated){
						checkAll(minJuggler);
					}
				}
				
			}
			else{
				addJuggler(currCircuit, jNum);
				break;				
			}		
		}
	}
	
	/**
	 * Try allocating juggler jNum by iterating through all the circuits
     * 
     * @param int representation of the juggler being allocated
	 */
	void checkAll(int jNum){		
		if(jugglers[jNum]->allocated){
				return;
		}
		
		for(int i = 0 ; i < circuits.size(); i++){
						
			int currCircuit = i;
			int cSize = circuits[currCircuit]->members.size();			
			int currMatch = jugglers[jNum]->match[currCircuit];
			int minJuggler, minMatch;

			if(cSize == max_circuit_size){
				minJuggler = findMinMatch(currCircuit);
				minMatch = jugglers[minJuggler]->match[currCircuit];
				if(minMatch < currMatch){
					circuits[currCircuit]->members.erase(circuits[currCircuit]->members.begin());
					addJuggler(currCircuit, jNum);
					jugglers[minJuggler]->allocated = false;
					checkPreference(minJuggler);
					break;
					if(!jugglers[minJuggler]->allocated){
						checkAll(minJuggler);
					}
				}
				
			}
			else{
				addJuggler(currCircuit, jNum);
				break;				
			}		
		}
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
					int circuitNumStrUInt = 0;

					for(int i = 1; i < circuitNumStr.size(); i++){	//Convert the juggler number into an int
						circuitNumStrUInt = circuitNumStrUInt * 10 + ((int)circuitNumStr[i] - '0');						
					}

					circuit* currCircuit = new circuit(circuitNumStrUInt);
					
					iter++;	//Now the iterator is on H					
					std::string parseH = *iter;									
					int szH = parseH.size();										
					if(szH == 3){
						currCircuit->circuit_H = (int)(parseH[2] - '0');						
					}
					else if(szH == 4){
						currCircuit->circuit_H = (((int) (parseH[2] - '0') ) * 10) + (int) (parseH[3] - '0');
					}

					iter++;	//Now the iterator is on E
					std::string parseE = *iter;
					int szE = parseE.size();
					if(szE == 3){
						currCircuit->circuit_E = (int)(parseE[2] - '0');
					}
					else if(szE == 4){
						currCircuit->circuit_E = (((int) (parseE[2] - '0') ) * 10) + (int) (parseE[3] - '0');
					}

					iter++; //Now the iterator is on P					
					std::string parseP = *iter;
					int szP = parseP.size();
					if(szP == 3){
						currCircuit->circuit_P = (int)(parseP[2] - '0');						
					}
					else if(szP == 4){
						currCircuit->circuit_P = (((int) (parseP[2] - '0') ) * 10) + (int) (parseP[3] - '0');						
					}

					circuits.push_back(currCircuit);
				}

				if(*iter == "J"){	//Reading and parsing the jugglers

					iter++;		//Now the iterator is on juggler_num
					std::string jugglerNumStr = *iter;
					int jugglerNumStrUInt = 0;

					for(int i = 1; i < jugglerNumStr.size(); i++){	//Convert the juggler number into an int
						jugglerNumStrUInt = jugglerNumStrUInt * 10 + ((int)jugglerNumStr[i] - '0');						
					}

					juggler* currJuggler = new juggler(jugglerNumStrUInt);

					iter++;		//Now the iterator is on H
					std::string parseH = *iter;									
					int szH = parseH.size();										
					if(szH == 3){
						currJuggler->juggler_H = (int)(parseH[2] - '0');						
					}
					else if(szH == 4){
						currJuggler->juggler_H = (((int) (parseH[2] - '0') ) * 10) + (int) (parseH[3] - '0');
					}

					iter++;		//Now the iterator is on E
					std::string parseE = *iter;
					int szE = parseE.size();
					if(szE == 3){
						currJuggler->juggler_E = (int)(parseE[2] - '0');
					}
					else if(szE == 4){
						currJuggler->juggler_E = (((int) (parseE[2] - '0') ) * 10) + (int) (parseE[3] - '0');
					}

					iter++;		//Now the iterator is on P
					std::string parseP = *iter;
					int szP = parseP.size();
					if(szP == 3){
						currJuggler->juggler_P = (int)(parseP[2] - '0');						
					}
					else if(szP == 4){
						currJuggler->juggler_P = (((int) (parseP[2] - '0') ) * 10) + (int) (parseP[3] - '0');
					}

					iter++;		//Now the iterator is on the list of preference
					std::string preference = *iter;					
					int jugglerPreferenceStrUInt = 0;
					int circuitNumUInt;
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
							circuitNumUInt =  (int)(preference[i] - '0');
							jugglerPreferenceStrUInt = jugglerPreferenceStrUInt * 10 + circuitNumUInt;
							(currJuggler->preference).push_back(jugglerPreferenceStrUInt);
							continue;
						}
						circuitNumUInt =  (int)(preference[i] - '0');
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
		for(int i = jugglers.size() - 1; i >= 0; i--){
			checkPreference(i);
			if(!jugglers[i]->allocated){				
				checkAll(i);
			}
		}

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

	JugglerFest jf("jugglefest.txt");

	std::ofstream out("output.txt");
	std::cout.rdbuf(out.rdbuf());

	jf.allocate();
	
	return 0;
}