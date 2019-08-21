// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
	linesInParagraph_.push_back(line); //adding lines into a paragraph
}

tuple<bool, vector<int>> Paragraph::contains(const Word& search_word) const
{

	auto isPresent = false;
	auto occurences = vector<int> { };

	for (auto i=0u; i < linesInParagraph_.size(); i++)
	{
		if (linesInParagraph_.at(i).contains(search_word))
		{
			isPresent = true;
			occurences.push_back(i+1);
		}
	}

	return {isPresent, occurences};
}
