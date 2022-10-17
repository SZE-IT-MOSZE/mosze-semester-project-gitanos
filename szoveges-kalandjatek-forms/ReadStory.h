#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <sstream>

#pragma once

public value class nextStory { // C++/CLI -> managed classes -> ref

public: 
	int instances;
	nextStory(System::String^ fileName) { filePath = L"../story/" + fileName; openFile(); }

	System::String^ baseText; // text to display in the label

	array<System::String^>^ btn1Attr; System::String^ btn1Text, ^ btn1Action; // attr = [text;action]
	array<System::String^>^ btn2Attr; System::String^ btn2Text, ^ btn2Action; // attr = [text;action]
	array<System::String^>^ btn3Attr; System::String^ btn3Text, ^ btn3Action; // attr = [text;action]

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
		btn1Attr = fullTextArray[1]->Split('>'); btn1Text = btn1Attr[0]; btn1Action = btn1Attr[1];
		btn2Attr = fullTextArray[2]->Split('>'); btn2Text = btn2Attr[0]; btn2Action = btn2Attr[1];
		btn3Attr = fullTextArray[3]->Split('>'); btn3Text = btn3Attr[0]; btn3Action = btn3Attr[1];
		
	}
};
