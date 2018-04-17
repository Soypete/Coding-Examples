#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

double initialSurfaceTemp[20][20];							//initializing the array
double surfaceTemp[20][20];									//intializing the other array

void Initialize_Hot_Plate(){
	for (int row = 0; row < 20; row++){						//set initial values of thearray
		for (int col = 0; col < 20; col++){
			initialSurfaceTemp[row][col] = 0;
		}
	}

	for (int i = 1; i < 19; i++){						//intializing the constant temperatures in the array
		initialSurfaceTemp[0][i] = 100;
		initialSurfaceTemp[19][i] = 100;

	}

	for (int i = 0; i < 20; i++){
		for (int k = 0; k < 20; k++){
			surfaceTemp[i][k] = initialSurfaceTemp[i][k];
		}
	}														//tranfers the values to the changing array
	
}
void Average_Hot_Plate(){								//find the average values according to the formula

	for (int i = 0; i < 20; i++){
		for (int k = 0; k < 20; k++){
			initialSurfaceTemp[i][k] = surfaceTemp[i][k];
		}
	}

	for (int row = 1; row < 19; row++){
		for (int col = 1; col < 19; col++){
			surfaceTemp[row][col] = (initialSurfaceTemp[row - 1][col] + initialSurfaceTemp[row + 1][col] + initialSurfaceTemp[row][col - 1] + initialSurfaceTemp[row][col + 1]) / 4;
		}
	}

	
}
void print_Hot_Plate(){
	for (int row = 0; row < 20; row++){				//print out the array
		for (int col = 0; col < 20; col++){
		cout << surfaceTemp[row][col] << " ";
		}
		cout << endl;
	}
}
void export_Hot_Plate(){
	ofstream labOutput("lab6output.csv");			//file for export
	for (int row = 0; row < 20; row++){				//export out the array
		for (int col = 0; col < 20; col++){
			labOutput << initialSurfaceTemp[row][col] << ",";
		}
		labOutput << endl;
	}
}


int main(){
	
	bool noChange = false;						//values of stabilizations
	Initialize_Hot_Plate();						//initialize the original hotplate
	print_Hot_Plate();							// print out he original hotplate
	Average_Hot_Plate();						//runs first iteration
	print_Hot_Plate();							//print out first iteration

		while (!noChange){						//while the change is more that .1 evaluates the average temp
			int counter = 0;
			Average_Hot_Plate();		//averages temp
			for (int row = 1; row < 19; row++){
				for (int col = 1; col < 19; col++){
					
					if ((initialSurfaceTemp[row][col] - surfaceTemp[row][col]) < .1 && (initialSurfaceTemp[row][col] - surfaceTemp[row][col]) > -.1){
						counter++;				//counts how many values are changing
					}
				}
			}	
			if (counter == 324){			//if all of the values stopped changing
				noChange = true;
			}
			else{
				noChange = false;
			}
		}
		export_Hot_Plate();						//exports the values to the CSV file
	system("pause");
	return 0;
}