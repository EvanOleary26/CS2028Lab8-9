#ifndef __WORD__H
#define __WORD__H

#include <string>

class Word {
	private:
		std::string word;
		int count;

    public:

    //Constructor
    Word() : word(""), count(0) {}
    Word(std::string inWord) : word(inWord), count(0) {}

    //Getters
    std::string getWord() { return word; }
    int getCount() { return count; }

    //Operator Overload
    bool operator>(const std::string& right) {
        return this->word > right;
    }

    bool operator<(const Word& right) {
        return this->word < right.word;
    }

    bool operator==(const Word& right) {
        return this->word == right.word;
    }

    bool operator!=(const Word& right) {
        return this->word != right.word;
    }

    Word operator++(int) {
        Word temp = *this;
        count++;
        return temp;
    }

    Word operator--(int) {
        Word temp = *this;
        count--;
        return temp;
    }

};

#endif