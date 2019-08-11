// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"

Word::Word(const string &word) : word_ { word }
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (word_.empty())
		throw WordContainsNoLetters { };
	if (isPurePunctuation())
		throw WordContainsNoLetters { };
	if (containsSpace())
		throw WordContainsSpace { };

	convertAlltoLowerCase();
	stripPunctuation();
	stripNumbers();
	removeNewLine();

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word &rhs) const
{
	if (word_ == rhs.word_)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
	if (word_.length() >= MIN_SIZE_FOR_QUERY)
		return true;

	return false;
}

void Word::convertAlltoLowerCase()
{
	auto temp = string { "" };

	for (auto i = 0u; i < word_.length(); i++)
		temp += tolower(word_.at(i));

	word_ = temp;

}

void Word::stripPunctuation()
{
	auto temp = string { "" };

	for (auto i = 0u; i < word_.length(); i++)
		if (!ispunct(word_.at(i)))
			temp += word_.at(i);

	word_ = temp;

}

void Word::stripNumbers()
{
	auto temp = string { "" };

	for (auto i = 0u; i < word_.length(); i++)
		if (!isdigit(word_.at(i)))
			temp += word_.at(i);

	word_ = temp;

}

bool Word::isPurePunctuation() const
{
	for (auto i = 0u; i < word_.length(); i++)
		if (isalpha(word_.at(i)))
			return false;

	return true;
}

bool Word::containsSpace() const
{
	for (auto i = 0u; i < word_.length(); i++)
		if (word_.at(i) == ' ')
			return true;

	return false;
}

void Word::removeNewLine()
{
	auto temp = string { "" };

	for (auto i = 0u; i < word_.length(); i++)
	{
		if (!isspace(word_.at(i)))
			temp += word_.at(i);
	}

	word_ = temp;
}
