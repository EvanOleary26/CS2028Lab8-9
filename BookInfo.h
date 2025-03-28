#ifndef __BOOKINFO__H
#define __BOOKINFO__H

#include <string>

class BookInfo {
	public:
		std::string title;
		std::string firstName;
		std::string lastName;
		int wordCount;
		double letterFrequency;
		int lineCount;
		
	public:
		void displayBookInfo() {
			
		}
};

#endif