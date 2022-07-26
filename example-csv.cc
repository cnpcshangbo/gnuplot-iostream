#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
class CSVPlotter{
    public:
    string filepath;
    CSVPlotter(string filepath);
    CSVPlotter();
    void createCSV();
    void read_record();
    void plot3DTrajectory();
    void plotInputs();
};
CSVPlotter::CSVPlotter(){
    cout << "instance created." << endl;
}
void CSVPlotter::createCSV(){
    // file pointer
    fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("reportcard.csv", ios::out | ios::app);
  
    cout << "Enter the details of 5 students:"
         << " roll name maths phy chem bio" << endl;
  
    int i, roll, phy, chem, math, bio;
    string name;
  
    // Read the input
    for (i = 0; i < 5; i++) {
  
        cin >> roll
            >> name
            >> math
            >> phy
            >> chem
            >> bio;
  
        // Insert the data to file
        fout << roll << ", "
             << name << ", "
             << math << ", "
             << phy << ", "
             << chem << ", "
             << bio
             << "\n";
    }
}

void CSVPlotter::read_record()
{

	// File pointer
	fstream fin;

	// Open an existing file
	fin.open("reportcard.csv", ios::in);

	// Get the roll number
	// of which the data is required
	int rollnum, roll2, count = 0;
	cout << "Enter the roll number "
		<< "of the student to display details: ";
	cin >> rollnum;

	// Read the Data from the file
	// as String Vector
	vector<string> row;
	string line, word, temp;

	while (!fin.eof( )) {

		row.clear();

		// read an entire row and
		// store it in a string variable 'line'
		getline(fin, line);

		// used for breaking words
		stringstream s(line);


        cout << "porting  .. " << endl;
		// read every column data of a row and
		// store it in a string variable, 'word'
		while (std::getline(s, word, ',')) {
            
            cout<< word << " ";
			// add all the column data
			// of a row to a vector
			row.push_back(word);
		}

		// convert string to integer for comparision
		roll2 = stoi(row[0]);
        cout << "checking current row: " << roll2 << endl;
        // cout rollnum

		// Compare the roll number
		if (roll2 == rollnum) {

			// Print the found data
			count = 1;
			cout << "Details of Roll " << row[0] << " : \n";
			cout << "Name: " << row[1] << "\n";
			cout << "Maths: " << row[2] << "\n";
			cout << "Physics: " << row[3] << "\n";
			cout << "Chemistry: " << row[4] << "\n";
			cout << "Biology: " << row[5] << "\n";
			break;
		}
	}
	if (count == 0)
		cout << "Record not found\n";
}



int main(){
    CSVPlotter plotter;
    // plotter.createCSV();
    plotter.read_record();
}