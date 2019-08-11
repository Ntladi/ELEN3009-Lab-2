#include "Paragraph.h"
#include "Word.h"
#include "Line.h"
#include "FileReader.h"
#include <iostream>
#include <string>
using namespace std;

bool fileDoesNotExist(string &fileName);
string fileName();
bool isValidWord(string &word);
void outputResult(bool &isPresent, vector<int> &occurs);

int main()
{
	auto file = FileReader { fileName() };
	auto paragraph = Paragraph { };

	file.readFileInto(paragraph);

	while (1)
	{
		cout << "Please enter a word to search for or \".\" to quit: ";
		auto input = string { "" };
		getline(cin, input);

		if (input == ".")
			break;

		if (isValidWord(input))
		{
			auto search_word = Word { input };
			auto searchResult = paragraph.contains(search_word);

			auto isPresent = get<0>(searchResult);
			auto occurs = get<1>(searchResult);

			outputResult(isPresent,occurs);
		}

	}

	return 0;
}

bool fileDoesNotExist(string &fileName)
{
	try
	{
		auto file = FileReader { fileName };
	}
	catch (FileCannotBeOpened &e)
	{
		cout << "\"" << fileName << "\"" << " does not exist" << endl;
		return true;
	}

	return false;
}

string fileName()
{
	auto fileString = string { "" };
	do
	{
		cout << "Please enter file name: " << flush;
		getline(cin, fileString);
	}
	while (fileDoesNotExist(fileString));

	return fileString;
}

bool isValidWord(string &word)
{
	try
	{
		auto newWord = Word { word };

		if (!newWord.isQueryable())
		{
			cout << "Invalid word: Minimum length must be 3." << endl;
			return false;
		}
	}
	catch (WordContainsNoLetters &l)
	{
		cout << "Invalid word: Does not contain any letters." << endl;
		return false;
	}
	catch (WordContainsSpace &s)
	{
		cout << "Invalid word: Word contains spaces." << endl;
		return false;
	}

	return true;
}

void outputResult(bool &isPresent, vector<int> &occurs)
{
	if (isPresent)
	{
		cout << endl << "Word found: line " << occurs.at(0) << endl;

		for (auto i = 1u; i < occurs.size(); i++)
			cout << " \t    line " << occurs.at(i) << endl;
		cout << endl;

	}
	else
		cout << "Word not found" << endl << endl;

}

// If a word appears twice in one line it counts as one occurrence
// If one wanted to change this behavior so that it counts the occurrences per line,
// one would have to change the contains method within the line implementation so that
// it returns a tuple which consists of a boolean variable and a vector counting the occurrences
// per line.
