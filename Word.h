#ifndef __WORD__H
#define __WORD__H

#include <string>

class Word {
	private:
		std::string word;
		int count;

    public:

    //Constructor
    Word() : word(""), count(1) {}
    Word(std::string inWord) : word(inWord), count(1) {}

    //Getters
    std::string getWord() { return word; }
    int getCount() { return count; }

    //Operator Overload
    bool operator>(const Word& right) {
        return this->word > right.word;
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

    friend std::ostream& operator<<(std::ostream& os, const Word& w) {
        os << w.word;
        return os;
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