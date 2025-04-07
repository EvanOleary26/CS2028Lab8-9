#include<iostream>
#include <iomanip>
#include<fstream>
#include<string>

#include "Word.h"
#include "BinaryTree.h"

BinaryTree<Word> WordTree;

void setupTree();

int main() {
	int promptOption;
	
	setupTree();
	
	while(true) {
		try{

			std::cout << "What would you like to do?" << std::endl;
			std::cout << "1. Find a word\n" 
					  << "2. Get tree size\n"
					  << "3. Get all words in ascending order\n"
					  << "4. Get all words in descending order\n"
					  << "5. Empty the tree\n"
					  << "6. Remove a word\n"
					  << "7. Quit" << std::endl;

			std::cin >> promptOption;

			switch (promptOption) {
				case 1: {	//Find a word
					std::string searchWord;
					std::cout << "What word would you like to find?" << std::endl;
					std::cin >> searchWord;
					Word tempWord(searchWord);
					Word result = WordTree.Find(tempWord,WordTree.getRoot());
					std::cout << "Word: '" << result.getWord() << "' count: " << result.getCount() << std::endl;
					break;
				}
				case 2: {	//Get tree size
					std::cout << "The size of the tree is: " << WordTree.getSize() << std::endl;
					break;
				}
				case 3: {	//Get all words in ascending order
					int arrSpotCounter = 0;
					Word* ascendArr = new Word[WordTree.getSize()];
					Word *ascarray = WordTree.GetAllAscending(WordTree.getRoot(), arrSpotCounter, ascendArr);
					int maxWordSize{};
					for (int i{}; i < sizeof(ascarray); i++) {
						if (ascarray[i].getWord().length() > maxWordSize) {
							maxWordSize = ascarray[i].getWord().length();
						}
					}

					std::cout << std::left << std::setw(maxWordSize + 6) << "Word" << "\tCount\tBF\tHeight\n";
					for (int i = 0; i < WordTree.getSize(); i++) {
						std::cout << std::left << std::setw(maxWordSize + 6) << ascarray[i].getWord() << "\t" << ascarray[i].getCount() << "\t" << ascarray[i].getBF() << "\t" << ascarray[i].getHeight() << std::endl;
					}
					break;
				}
				case 4: {	//Get all words in descending order
					int arrSpotCounter = 0;
					Word* ascendArr = new Word[WordTree.getSize()];
					Word* ascarray = WordTree.GetAllDescending(WordTree.getRoot(), arrSpotCounter, ascendArr);
					int maxWordSize{};
					for (int i{}; i < sizeof(ascarray); i++) {
						if (ascarray[i].getWord().length() > maxWordSize) {
							maxWordSize = ascarray[i].getWord().length();
						}
					}

					std::cout << std::left << std::setw(maxWordSize + 6) << "Word" << "\tCount\tBF\tHeight\n";
					for (int i = 0; i < WordTree.getSize(); i++) {
						std::cout << std::left << std::setw(maxWordSize + 6) << ascarray[i].getWord() << "\t" << ascarray[i].getCount() << "\t" << ascarray[i].getBF() << "\t" << ascarray[i].getHeight() << std::endl;
					}
					break;
				}
				case 5: {	//Empty the tree
					WordTree.EmptyTree();
					std::cout << "Emptied the tree" << std::endl;
					break;
				}
				case 6: {	//Remove a word
					std::string searchWord;
					std::cout << "What word would you like to remove?" << std::endl;
					std::cin >> searchWord;
					Word tempWord{ searchWord };
					Word result = WordTree.Find(tempWord,WordTree.getRoot());
					WordTree.Remove(result,WordTree.getRoot());
					std::cout << "Removed: '" << result.getWord() << "' count: " << result.getCount() << std::endl;
					break;
				}
				case 7: {	//Quit
					return 0;
				}
				case 8: {	//Display tree
					WordTree.displayTree(WordTree.getRoot());
					break;
				}
			}
		}
		catch(Exception &e) {
			std::cout << e.errorMessage << " : " << e.errorNumber << std::endl;
		}
	}

	return 0;
}

void setupTree() {
	//This function will go through and add all words from the text documents to the tree
	//this function will before adding a word to the tree will make the word lowercase and remove any punctuation it has

	std::string curWord;
	std::ifstream textFile;

	for (int i{}; i < 2; i++) {
		if (i == 0) {
			textFile.open("MobyDick.txt");
		} else {
			if (textFile.is_open()) {
				textFile.close();
			}
			textFile.open("PeterPan.txt");
		}

		if (!textFile.is_open()) {
			throw Exception(0, "Failed to open file");
			continue;
		}

		while(textFile >> curWord) {
			if (!curWord.empty() || curWord != "\n") {	//Check if the current word is blank or newline
				for (int i = 0; i < curWord.length(); i++) {
					curWord[i] = std::tolower(curWord[i]);
				}
				curWord.erase(std::remove_if(curWord.begin(), curWord.end(), ispunct), curWord.end());
				if (!curWord.empty()) {	//Make sure word is not empty after removing punctuation
					Word tempWord(curWord);
					WordTree.Insert(tempWord, WordTree.getRoot());
				}
			}
		}
	}
	std::cout << "Removed all punctuation, made all words lowercase, added words to tree." << std::endl;
	textFile.close();
}