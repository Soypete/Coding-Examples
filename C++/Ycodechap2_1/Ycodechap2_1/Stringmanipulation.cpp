#include <iostream>
#include <string>

using namespace std;

int main()
{
	string userEnteredWord;
	int letters;
	string shortenedWord;
	//cout << "please type a word" << endl;		//prompt user to type a word
	cin >> userEnteredWord;
	//prompt user to give number of letter's printed
	//cout << "Please enter a number: " << endl;
	cin >> letters;
	shortenedWord = userEnteredWord.substr(0, letters);
	//print out shortened word
	cout << shortenedWord

	return 0;
}