#ifndef __WORD__H
#define __WORD__H

#include <string>

class Word {
	public:
		std::string word;
		int count;
        int height;
        int balanceFactor;

    //public:

    //Constructor -- may need updates
    Word() : word(), count(), height(), balanceFactor() {}
    Word(std::string inWord) : word(inWord), count(1), height(1), balanceFactor(0) {}

    //setters
	void setBF(int bf) { balanceFactor = bf; }
	void setHeight(int h) { height = h; }

    //Getters
    std::string getWord() { return word; }
    int getCount() { return count; }
    int getHeight() { return height; }
    int getBF() { return balanceFactor; }

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