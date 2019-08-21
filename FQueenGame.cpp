#pragma once
#include "FQueenGame.h"
#include <map>

// to make syntax Unreal Engine friendly
#define TMap std::map
using int32 = int;

FQueenGame::FQueenGame() { Reset(); } // default constructor

// getters
int32 FQueenGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FQueenGame::GetHiddenWorthLength() const { return MyHiddenWord.length(); }
bool FQueenGame::IsGameWon() const { return bGameIsWon; }

int32 FQueenGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FQueenGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; // this must be an isogram

	MyHiddenWord = HIDDEN_WORD;
	
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

EGuessStatus FQueenGame::CheckGuessValidity(FString Guess) const
{

	if (!IsIsogram(Guess)) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	} 
	else if (!IsLowerCase(Guess)) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase; // TODO write function
	}
	else if (Guess.length() != GetHiddenWorthLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, increments turn, and returns count
FQueerStr8Count FQueenGame::SubmitValidGuess(FString Guess)
{

	MyCurrentTry++;
	FQueerStr8Count QueerStr8Count;
	int32 WordLength = MyHiddenWord.length();

	// loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
		// compare letters again in the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{
				if (MHWChar == GChar) 
				{
					QueerStr8Count.Queers++;
				}
				else 
				{
					QueerStr8Count.Str8s++;
				}
			}

		}
	}
	if (QueerStr8Count.Queers == WordLength) {
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return QueerStr8Count;
}

bool FQueenGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) { 
			return false; 
		}
		else {
			LetterSeen[Letter] = true;
		}

	}

	return true;
}

bool FQueenGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{ 
			return false; 
		}	
	} 
	return true;
}

