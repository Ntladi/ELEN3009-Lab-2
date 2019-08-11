// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"

Line::Line(const string &line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.

	auto ss = stringstream { line };
	auto temp = string { "" };

	while (getline(ss, temp, ' '))
	{
		auto new_word = Word { temp };

		if (new_word.isQueryable())
			wordsInLine_.push_back(new_word);
	}
}

bool Line::contains(const Word &search_word) const
{
	for (auto i = 0u; i < wordsInLine_.size(); i++)
		if (wordsInLine_.at(i) == search_word)
			return true;

	return false;
}
