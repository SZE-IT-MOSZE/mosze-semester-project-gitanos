#include <string>
#include<fstream>
#include <iostream>
#include <streambuf>
#include <sstream>

#pragma once
class nextStory {
public: 

	nextStory() { openFile(); }
	System::String^ *baseText;
	//std::string options[3] = { "option1", "option2", "" };

	void openFile() {
		//std::fstream storyTxt;
		//std::ifstream t("../Story/Text.txt");
		//std::string str((std::istreambuf_iterator<char>(t)),
		//	std::istreambuf_iterator<char>());

		std::ifstream inFile;
		inFile.open("../story/Text.txt"); //open the input file

		std::stringstream strStream;
		strStream << inFile.rdbuf(); //read the file
		System::String^ pBaseText = gcnew System::String(strStream.str().c_str()); //str holds the content of the file
		baseText = &pBaseText;

	}
};