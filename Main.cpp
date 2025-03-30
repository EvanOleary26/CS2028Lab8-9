#include<iostream>
#include<fstream>
#include<string>

#include "Word.h"
#include "BinaryTree.h"

void setupTree() {
	//This function will go through and add all words from the text documents to the tree
	//this function will before adding a word to the tree will make the word lowercase and remove any punctuation it has
}


int main() {
	int promptOption;
	BinaryTree<Word> WordTree;

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
					std::cout << "Found: " << result.getWord() << ", count: " << result.getCount() << std::endl;
					break;
				}
				case 2: {	//Get tree size
					std::cout << "The size of the tree is: " << WordTree.returnSize() << std::endl;
					break;
				}
				case 3: {	//Get all words in ascending order

					break;
				}
				case 4: {	//Get all words in descending order

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
					Word tempWord(searchWord);
					Word result = WordTree.Find(tempWord,WordTree.getRoot());
					std::cout << "Removed: " << result.getWord() << ", count: " << result.getCount() << std::endl;
					break;
				}
				case 7: {	//Quit
					return 0;
				}
			}
		}
		catch(Exception &e) {
			std::cout << e.errorMessage << " : " << e.errorNumber << std::endl;
		}
	}

	
	return 0;
}