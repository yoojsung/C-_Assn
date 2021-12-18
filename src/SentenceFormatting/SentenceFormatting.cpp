/*
* SentenceFormatting.cpp - takes in a string which is a sentence, then formats so that whitespace becomes space and 
*						it doesn't have multiple spaces in a row. It also capitalizes the first character
*						of the sentence, then changes the rest to lowercase
* Jaesung Yoo
* CIS54 C/C++ programming
* June 25th, 2021
*/

#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char* argv[])
{
	int i = 0;
	char sentence[200];
	cout << "Enter a sentence: " << endl;
	cin.getline(sentence, 200);
	//changes all the whitespace into just spaces using the function isspace
	for (i = 0; sentence[i]; i++)
		if (isspace(sentence[i]))
			sentence[i] = ' ';
	//shifts to the left when there are more than 2 spaces, so only one space can be left
	i = 0;
	while (sentence[i] != '\0')
	{
		if (sentence[i] == ' ' && sentence[i + 1] == ' ')
			for (int j = i; sentence[j]; j++)
			{
				sentence[j] = sentence[j + 1];
			}
		else
			i++;
	}
	//changes the first character of the sentence to uppercase
	sentence[0] = toupper(sentence[0]);
	//changes the rest of the characters of the sentence to lowercase
	for (i = 1; sentence[i]; i++)
		sentence[i] = tolower(sentence[i]);

	cout << sentence << endl;
	return 0;
}