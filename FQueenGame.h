/* The game logic (no view code or direct user interaction)
A guessing game based on Mastermind */

#pragma once
#include <string>

// to make syntax Unreal Engine friendly
using FString = std::string;
using int32 = int;

struct FQueerStr8Count {
	int32 Queers = 0;
	int32 Str8s = 0;
};

enum class EGuessStatus 
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FQueenGame {
public:
	FQueenGame(); // constructor

	// getters
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWorthLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FQueerStr8Count SubmitValidGuess(FString);

private:
	// see constructor for initialization
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};