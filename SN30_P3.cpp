// Name: 30
// Project: Project #3
// Project Description: This code is to take in as many number of students and ther respective ACT scores as the user enters,
// and output the ACT score values to respepctive files based on what their score is. At the end, the average of the 3 ACT scores categories
// are to be output.
// Due Date: 10/26/2023

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main (){
	
	string firstName, lastName;
	
	double studentNum, score;
	double sumCR = 0, sumCAR = 0, sumOther = 0;
	double aveCR = 0, aveCAR = 0, aveOther = 0;
	double countCR = 0, countCAR = 0, countOther = 0, count = 0;
	
	// Lines 11 - 14 are all variables for the averages of the 3 ACT categories, the number of students / scores being evaluated,
	// counters for caluclations, and summations
	
	ofstream ofileCR;
	ofstream ofileCAR;
	ofstream ofileOther;
	
	// Lines 19 - 21 above and lines 25 - 27 below declare and open the "CR.txt," "CAR.txt," and "Other.txt" files
	
	ofileCR.open("CR.txt");
	ofileCAR.open("CAR.txt");
	ofileOther.open("Other.txt");
	
	// Tutor Lukas helped me with lines 18 - 20. I was having issues getting scores and names that
	// fall under the same file to all save under that file because I had opened my files in the wrong place in my code (inside the while loop)
	
	ofileCR << "SN30: Calculus Ready" << endl;
	ofileCAR << "SN30: College Algebra Ready" << endl;
	ofileOther << "SN30: Other" << endl;
	
	// Lines 32 - 34 above print to the directed files
	
	cout << "How many students' ACT scores are being evaluated?: ";
	cin >> studentNum;
	
	// Lines 43 - 79 iterate until all students and their respective scores have been entered
	
	while (count < studentNum) {
		
		cout << "Enter student first name: ";
		cin.ignore();
		getline(cin, firstName);
		
		cout << "Enter student last name: ";
		cin >> lastName;
		
		cout << "Enter student's ACT score: " << endl;
		cin >> score;
		
		count ++;
		
		if (score >= 28 && score <= 36) {
			ofileCR << firstName << " " << lastName << ", " << score << endl;
			sumCR += score;
			countCR++;
		}
			
		else if (score >= 22 && score < 28) {
			ofileCAR << firstName << " " << lastName << ", " << score << endl;
			sumCAR += score;
			countCAR++;
		}
		
		else if (score > 0 && score < 22) {
			ofileOther << firstName << " " << lastName << ", " << score << endl;
			sumOther += score;
			countOther++;
		}
		
		else {
			cout << "Error: ACT score entered for " << firstName << " " << lastName << " is invalid." << endl;
		}

	}

// Lines 83 - 93 carry out the average formula so long as not dividing by a zero

	if (countCR != 0){
		aveCR = sumCR / countCR;
	}
	
	if (countCAR != 0){
		aveCAR = sumCAR / countCAR;
	}
	
	if (countOther != 0){
		aveOther = sumOther / countOther;
	}
	
	// Lines 97 - 101 output the final averages
	
	cout << "Calculus Ready Average: " << setw(15) << fixed << setprecision(2) << aveCR << endl;

	cout << "College Algebra Ready Average: " << setw(8) << fixed << setprecision(2) << aveCAR << endl;
	
	cout << "Other Average: " << setw(24) << fixed << setprecision(2) << aveOther << endl;

return 0;
}
