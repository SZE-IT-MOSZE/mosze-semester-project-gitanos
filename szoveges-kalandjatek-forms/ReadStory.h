#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <sstream>

#pragma once
public ref class nextStory { // C++/CLI -> managed classes -> ref

public: 
	nextStory(System::String^ fileName) { filePath = L"../story/" + fileName; openFile(); }
	System::String^ baseText; // text to display in the label
	System::String^ filePath; // let the caller tell which file to open

	void openFile() {

		std::ifstream inFile;
		inFile.open("../story/_start.game"); // open the input file
		std::stringstream strStream;
		strStream << inFile.rdbuf(); // read the file

		// convert std::string to System::String
		System::String^ fullText = gcnew System::String(strStream.str().c_str()); // str holds the content of the file

		array<System::String^>^ fullTextArray = fullText->Split('|');

		baseText = fullTextArray[0];
	}
};