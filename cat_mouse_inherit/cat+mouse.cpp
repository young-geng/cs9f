#include <iostream>
using namespace std;
#include "park.h"
void RunChase (Scene allAnimals) {
	for (int time=1; time<=30; time++) {
		for (int k=0; k<allAnimals.Length (); k++) {
			if (allAnimals[k]->Chase ()) {
				cout << allAnimals[k]->Name() << " caught its target in step " << time << endl;
				return;
			}
			cout << allAnimals[k]->Name() << " position: " << allAnimals[k]->Pos() << endl;
		}
		cout << endl;
	}
	cout << "Chase took too long; all animals drifted away." 
		  << endl;
}
int main () {
	Scene allAnimals;
	RunChase (allAnimals);
	return 0;
}
