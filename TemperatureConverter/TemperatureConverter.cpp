//Linkhon Hasan
//6/8/2024
//Please ensure FarenheitTemperature.txt exists in the same folder as the cpp
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	//variables to hold data from the input file
	string city;
	int temp;

	//program expects the input file to exists and opens it
	ifstream inputFile;
	inputFile.open("FahrenheitTemperature.txt");

	//program expects the output file to not exists so creates it
	ofstream outputFile("CelsiusTemperature.txt");

	//loops as long as there is data in the file
	while (inputFile >> city >> temp) {
		//5.0 and 9.0 for accurate division and print a float value for celcius
		outputFile << city << " " << ((temp-32)*(5.0/9.0)) << endl;
	}

	cout << "Please check program root folder for the files!" << endl;

	inputFile.close();
	outputFile.close();
	return 1;
}