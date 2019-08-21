/* The game logic (no view code or direct user interaction)
A guessing game based on Mastermind */

#pragma once
#include <string>

// to make syntax Unreal Engine friendly
using FString = std::string;
using int32 = int;

struct FQueerStr8Count 
{
	int32 Queers = 0;
	int32 Str8s = 0;
};

enum class EGuessStatus 
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

enum class EWordLengthChoiceStatus
{
	Invalid_Status,
	OK,
	Not_Numerical, // new for choosing word length
	Invalid_Range // new for choosing word length
};


// Class definition
class FQueenGame 
{
	public:
		FQueenGame(); // constructor

		// getters
		int32 GetMaxTries() const;
		int32 GetCurrentTry() const;
		int32 GetHiddenWorthLength() const;

		EWordLengthChoiceStatus CheckWordLengthValidity(int32);
	void InitializeHiddenWord(int32);

		bool IsGameWon() const;
		EGuessStatus CheckGuessValidity(FString) const;

		void Reset();
		FQueerStr8Count SubmitValidGuess(FString);

	private:
		// see constructor for initialization
		bool IsNumber(int32);
		bool IsValidLength(int32);

		int32 MyCurrentTry;
		FString MyHiddenWord;
		bool bGameIsWon;

		bool IsIsogram(FString) const;
		bool IsLowerCase(FString) const;


};