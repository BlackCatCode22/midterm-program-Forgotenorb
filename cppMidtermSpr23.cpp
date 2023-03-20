// cppMidtermSpr23.cpp : midterm for C++ Spring 2023
//

// dH 3/7/23 - file io, create an array from the input file, write the calcBirthdate() function
//   write the genUniqueID() function. Select a line in the array to test various input values.

// References:
// https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/ 
// https://www.geeksforgeeks.org/substring-in-cpp/ 
// https://www.w3schools.com/cpp/cpp_functions.asp
// https://www.w3schools.com/cpp/cpp_switch.asp
// 

#include <iostream>
// #include <sstream>
#include <fstream>
#include <string>

using namespace std;


string genUniqueID(string species, int numOfSpecies) {
    
    string uniqueID;
    
    if (species == "hyena") {
        uniqueID = "hy0" + to_string(numOfSpecies);
    }
    else if (species == "lion") {
        uniqueID = "li0" + to_string(numOfSpecies);
    }
    else if (species == "tiger") {
        uniqueID = "ti0" + to_string(numOfSpecies);
    }
    else if (species == "bear") {
        uniqueID = "be0" + to_string(numOfSpecies);
    }
    else {
        uniqueID = "error";
    }

    return uniqueID;
}



// calcBirthdate() accepts an integer for years and a string for season
// returns birthdate as Month Day, Year
string calcBirthdate(int years, string season) {
    int birthYear = 0;
    string birthDate;
    birthYear = 2023 - years;
    string monthDay;
    if (season == "spri") {
        monthDay = "Mar 21";
    }
    else if (season == "summ") {
        monthDay = "Jun 21";
    }
    else if (season == "fall") {
        monthDay = "Sep 21";
    }
    else if (season == "wint") {
        monthDay = "Dec 21";
    }
    else {
        monthDay = "Jan 1";
    }
    birthDate = monthDay + ", " + to_string(birthYear);
    return birthDate;
}


int main()
{
    // Open a file and read from it
    string myTextStr;

    // Create a one-dimensional array
    string lines[4];

    // Initialize variables used to find data elements in text string
    int lineNum = 0;
    int position = 0;
    int startPos = 0;
    int endPos = 0;
    int numOfHyenas = 0;
    int numOfLions = 0;
    int numOfTigers = 0;
    int numOfBears = 0;

    lineNum = 0;
    try {
        // Create a text string, used to output the text file
        ifstream myFile("/Users/forgotenorb/Documents/Midterm/midterm-program-Forgotenorb/arrivingAnimals.txt");

        // Read the file line by line
        cout << "\n\n Contents of /Users/forgotenorb/Documents/Midterm/midterm-program-Forgotenorb/arrivingAnimals.txt ...";
        while (getline(myFile, myTextStr)) {
            // Output one line at a time
            cout << "\n" << myTextStr;
            // Create an array line by line
            lines[lineNum] = myTextStr;
            lineNum++;
        }
        cout << "\n  End of /Users/forgotenorb/Documents/Midterm/midterm-program-Forgotenorb/arrivingAnimals.txt ...\n\n";
        // Close the file
        myFile.close();
    }
    catch (...) {
        cout << "\nException caught! \n";
    }

    // The input file was opened, read into an array, and closed
    // Process a single element of the array
    // process each line, one at a time, until you have resolved all issues from the input file
    string oneLine = lines[3];

    cout << "\n\n" << oneLine << "\n\n";
    // First line of arrivingAnimals...
    // 4 year old female hyena, born in spring, tan color, 70 pounds, from Friguia park, Tunisia
    // Parse the above line into birthday, species, sex, color, weight, origin.
    
    // Variables needed to process input data into output information.
    int numYears = 0;
    string sex;
    string species;
    string uniqueID;
    string birthSeason;
    string color;
    int weight = 0;
    string origin;

    // Get numYears to calculate birthdate
    // 2 chars starting at index 0, stoi(): string to int
    numYears = stoi(oneLine.substr(0, 2));
    cout << "\n numYears = " << numYears;

    // Find birthSeason
    // What will find() return if "born in" is not found?
    //   how will you handle this?
    position = oneLine.find("born in");
    if(position == -1) {
	    position = oneLine.find("unknown birth season");
	    cout << "\n position = " << position;
	    position = oneLine.find(",");
	    birthSeason = oneLine.substr(position + 1, 21);
	    cout << "\n birthSeason = " << birthSeason;
	    cout << "\n Birth Date is..." << calcBirthdate(numYears, birthSeason);

    }else{
    cout << "\n position = " << position;
    birthSeason = oneLine.substr(position + 8, 4);
    cout << "\n birthSeason = " << birthSeason;

    // Call the calcBirthdate() function 
    cout << "\n Birth Date is... " << calcBirthdate(numYears, birthSeason);
    }

    // Find sex 
    // How many char spaces?
    position = oneLine.find(" ");
    position = oneLine.find(" ", position+1);
    position = oneLine.find(" ", position+1);
    startPos = position + 1;
    // find the end position
    endPos = oneLine.find(" ", startPos);
    sex = oneLine.substr(startPos, endPos - startPos);
    cout << "\n sex is..." << sex;

    // Find species
    // Notice that species follows sex, and is terminated with a comma, so we are already there!
    startPos = endPos + 1;
    endPos = oneLine.find("," , startPos);
    species = oneLine.substr(startPos, endPos - startPos);
    cout << "\n species is..." << species;

    // Now that we have a species, update the global variable for the species count (we will get rid 
    // of this when we code this up with classes and lists) and get a uniqueID.
    if (species == "hyena") {
        numOfHyenas++;
        uniqueID = genUniqueID("hyena", numOfHyenas);
	cout << "Hyena Habitat:" << endl;
    }
    else if (species == "lion") {
        numOfLions++;
        uniqueID = genUniqueID("lion", numOfLions);
    }
    else if (species == "tiger") {
        numOfTigers++;
        uniqueID = genUniqueID("tiger", numOfTigers);
    }
    else if (species == "bear") {
        numOfBears++;
        uniqueID = genUniqueID("bear", numOfBears);
    }
    else {
        cout << " error " << endl;
    }

    cout << "\n uniqueID is..." << uniqueID;


}
