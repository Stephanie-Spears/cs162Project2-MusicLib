#include <iostream>
#include <fstream>
#include <cstring> //need to include? VS compiles fine, does linux?

#define MAX_CHAR 200

using namespace std;

void GetFileName(char*); 
int CallMenu();
void UpdateFile(int&, struct Song*);
void GetSong(int&, struct Song*);
void RemoveSong(int&, struct Song*);
void SearchByArtist(int&, struct Song*);
void SearchByAlbum(int&, struct Song*);

struct Song
{
	char cTitle[MAX_CHAR];
	char cArtist[MAX_CHAR];
	char cDuration[MAX_CHAR];
	char cAlbum[MAX_CHAR];

};

int main()
{
	char cFileNamePath[MAX_CHAR];
	bool bRunCode;
	fstream inputFile;
	int i = 0;
	int iMenu_Result;
	Song songs[MAX_CHAR];
	int iArraySize = 0;
	int x = 0;

	GetFileName(cFileNamePath);
	cout << "File name '" << cFileNamePath << "'open for reading/writing." << endl << endl;
	inputFile.open(cFileNamePath, fstream::in);

	inputFile.getline(songs[i].cTitle, MAX_CHAR, ';');
	while (inputFile.good())
	{
		inputFile.getline(songs[i].cArtist, MAX_CHAR, ';');
		inputFile.getline(songs[i].cDuration, MAX_CHAR, ';');
		inputFile.getline(songs[i].cAlbum, MAX_CHAR, '\n');
		i++;
		inputFile.getline(songs[i].cTitle, MAX_CHAR, ';');
	}

	inputFile.close();

	bRunCode = true;

	iArraySize = i;

	while (bRunCode == true)
	{
		iMenu_Result = CallMenu();
		//get menu response

		if (iMenu_Result == 1)
		{
			GetSong(iArraySize, songs);
			//add song
		}
		else if (iMenu_Result == 2)
		{
			for (i = 0; i < iArraySize; i++)
			{
				cout << "Index: " << i << endl;
				cout << "Title: " << songs[i].cTitle << endl;
				cout << "Artist: " << songs[i].cArtist << endl;
				cout << "Duration: " << songs[i].cDuration << endl;
				cout << "Album: " << songs[i].cAlbum << endl;
				cout << endl;
			}
			//display all songs
		}

		else if (iMenu_Result == 3)
		{
			RemoveSong(iArraySize, songs);
			//remove song
		}
		else if (iMenu_Result == 4)
		{
			SearchByArtist(iArraySize, songs);
			//search song by artist
		}
		else if (iMenu_Result == 5)
		{
			SearchByAlbum(iArraySize, songs);
			//search song by album
		}
		else if (iMenu_Result == 6)
		{
			UpdateFile(iArraySize, songs);
			cout << "Saving changes and closing program. Goodbye." << endl;
			bRunCode = false;
		}
		else
		{
			cout << "Unknown Error. Exiting Program." << endl << endl;
			bRunCode = false;
		}
	}
	return 0;
}

void GetFileName(char* cFileName)
{	
	strcpy(cFileName, "songs.txt");
}

int CallMenu()
{
	bool bValidInput;
	int iMenu_Result;

	bValidInput = true;

	while (bValidInput == true)
	{
		cout << "1) Add new song" << endl;
		cout << "2) Display all songs" << endl;
		cout << "3) Remove song" << endl;
		cout << "4) Search song by artist" << endl;
		cout << "5) Search song by album" << endl;
		cout << "6) Save all and Quit" << endl << endl;
		cout << "Enter Choice: ";
		cin >> iMenu_Result;
		cin.clear();
		cin.ignore(100, '\n');

		if (iMenu_Result == 1)
		{
			cout << "You Chose Option 1. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 2)
		{
			cout << "You Chose Option 2. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 3)
		{
			cout << "You Chose Option 3. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 4)
		{
			cout << "You Chose Option 4. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 5)
		{
			cout << "You Chose Option 5. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 6)
		{
			cout << "You Chose Option 6. " << endl << endl;
			return iMenu_Result;
		}
		else
		{
			cout << "Input error. Please choose an option from the menu." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	return (0);
}

void GetSong(int &iArraySize, struct Song *songs)
{
	iArraySize = iArraySize + 1;

	cout << "Please enter the song title: ";

	cin.get(songs[iArraySize - 1].cTitle, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter the artist name: ";
	cin.get(songs[iArraySize - 1].cArtist, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter the song duration: ";
	cin.get(songs[iArraySize - 1].cDuration, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter the album title: ";
	cin.get(songs[iArraySize - 1].cAlbum, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');
}

void RemoveSong(int &iArraySize, struct Song *songs)
{
	bool bCheckInput;
	int iIndexNum;
	int i;

	bCheckInput = false;
	while (bCheckInput == false)
	{
		cout << "Enter the song index you would like to remove: ";
		cin >> iIndexNum;
		cin.clear();
		cin.ignore(100, '\n');

		if (0 > iIndexNum || iIndexNum > (iArraySize - 1))
		{
			cout << "Input error. Select an index number between 0 and " << (iArraySize - 1) << "." << endl;
		}
		else
		{
			bCheckInput = true;
		}
	}

	for (i = 0; i < iArraySize; i++) // Loop to find the item to delete.
	{
		if (i == iIndexNum) // If we find the item to delete...
		{
			for (int j = i; j < iArraySize - 1; j++) // Iterate through the remaining elements, stopping one before the end.
			{
				strcpy(songs[j].cTitle, songs[j + 1].cTitle);
				strcpy(songs[j].cArtist, songs[j + 1].cArtist);
				strcpy(songs[j].cDuration, songs[j + 1].cDuration);
				strcpy(songs[j].cAlbum, songs[j + 1].cAlbum);
			}
			memset(songs[iArraySize - 1].cTitle, 0, strlen(songs[iArraySize - 1].cTitle));
			memset(songs[iArraySize - 1].cArtist, 0, strlen(songs[iArraySize - 1].cArtist));
			memset(songs[iArraySize - 1].cDuration, 0, strlen(songs[iArraySize - 1].cDuration));
			memset(songs[iArraySize - 1].cAlbum, 0, strlen(songs[iArraySize - 1].cAlbum));
			iArraySize--;
		}
	}
}

void SearchByArtist(int &iArraySize, struct Song *songs)
{
	char cFindArtist[MAX_CHAR];
	int i;
	int x = 0;

	cout << "Search Artist Name: ";
	cin.get(cFindArtist, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');

	for (i = 0; i <= iArraySize; i++)
	{
		if (strcmp(songs[i].cArtist, cFindArtist) == 0)
		{
			cout << endl << i << endl;
			cout << songs[i].cArtist << ";" << endl;
			cout << songs[i].cTitle << ";" << endl;
			cout << songs[i].cDuration << ";" << endl;
			cout << songs[i].cAlbum << endl << endl;
			x++;
		}
		else if (i == iArraySize)
		{
			cout << "Found " << x << " instances of artist '" << cFindArtist << "'" << endl;
		}
	}
}

void SearchByAlbum(int &iArraySize, struct Song *songs)
{
	char cFindAlbum[MAX_CHAR];
	int i;
	int x = 0;

	cout << "Search Album Name: ";
	cin.get(cFindAlbum, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');
	x = 0;
	for (i = 0; i <= iArraySize; i++)
	{
		if (strcmp(songs[i].cAlbum, cFindAlbum) == 0)
		{
			cout << endl << i << endl;
			cout << songs[i].cAlbum << ";" << endl;
			cout << songs[i].cArtist << ";" << endl;
			cout << songs[i].cTitle << ";" << endl;
			cout << songs[i].cDuration << endl << endl;
			x++;
		}
		else if (i == iArraySize)
		{
			cout << "Found " << x << " instances of album '" << cFindAlbum << "'" << endl;
		}
	}
}

void UpdateFile(int &iArraySize, struct Song *songs)
{
	fstream fOutputFile;
	int i;
	char cDelim[2] = ";";

	fOutputFile.open("songs.txt", fstream::out | fstream::trunc);
	for (i = 0; i < iArraySize; i++)
	{
		if (i != (iArraySize - 1))
		{
			strcat(songs[i].cTitle, cDelim);
			strcat(songs[i].cArtist, cDelim);
			strcat(songs[i].cDuration, cDelim);
			strcat(songs[i].cAlbum, "\n");
			fOutputFile << songs[i].cTitle << songs[i].cArtist << songs[i].cDuration << songs[i].cAlbum;
		}
		else if (i == (iArraySize - 1))
		{
			strcat(songs[i].cTitle, cDelim);
			strcat(songs[i].cArtist, cDelim);
			strcat(songs[i].cDuration, cDelim);
			fOutputFile << songs[i].cTitle << songs[i].cArtist << songs[i].cDuration << songs[i].cAlbum;
		}
	}
		fOutputFile.close();
}



/*
void GetFileName(char* cFileName)
{
	char cFileType[5] = ".txt"; //changes the user input of file name to a text file link. Just for convenience
	fstream inputFile;
	bool bValidFile;

	bValidFile = false;

	while (bValidFile == false)
	{
	cout << "Enter the input file name: ";
	cin.get(cFileName, '\n');  //use delim in case they use spaces?
	strcat(cFileName, cFileType);
	cin.clear();
	cin.ignore(100, '\n');
	inputFile.open(cFileName, fstream::in);

	if (inputFile.fail())
	{
	cout << "Input file name '" << cFileName << "' does not exist. Please try again." << endl;
	inputFile.close();
	}
	else
	{
	cout << endl << "Input file name '" << cFileName << "' found." << endl;
	inputFile.close();
	bValidFile = true;

	}
}
*/