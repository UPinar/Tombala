#include <iostream>
#include <vector>
#include <array>
#include <cstdlib> //for using rand()
#include <stdlib.h> // for cleaning console.
#include <windows.h> // for sleep()


namespace constants 
{
	constexpr int numberCountInCard{ 15 };

	constexpr int divide1s{ 0 };
	constexpr int divide10s{ 1 };
	constexpr int divide20s{ 2 };
	constexpr int divide30s{ 3 };
	constexpr int divide40s{ 4 };
	constexpr int divide50s{ 5 };
	constexpr int divide60s{ 6 };
	constexpr int divide70s{ 7 };
	constexpr int divide80s{ 8 };
	constexpr int divide90s{ 9 };

	constexpr int rowCountCard{ 3 };
	constexpr int columnCountCard{ 9 };

	constexpr int rowCountBingo{ 9 };
	constexpr int columnCountBingo{ 10 };

	constexpr int totalBingoDeckNumbers{ 90 };

	constexpr int winnerCount{ 3 };
}

using basicCardType = std::array<int, constants::numberCountInCard>;
using advancedCardType = std::array <std::array<int, constants::columnCountCard>, constants::rowCountCard>;
using bingoDeckType = std::array <std::array<int, constants::columnCountBingo>, constants::rowCountBingo>;
using winnerType = std::array<int, constants::winnerCount>;

bingoDeckType createBingoDeck()
{
	bingoDeckType bingoDeckArr{};

	int counter{ 1 };
	for (int i = 0; i < constants::rowCountBingo; i++)
	{
		for (int j = 0; j < constants::columnCountBingo; j++)
		{
			bingoDeckArr[i][j] = counter;
			++counter;
		}
	}
	return bingoDeckArr;
}

// bingoNumber = 0 and gameStarted = false because they are optional. When the game started bingoNumber will come.
void printBingoDeck(bingoDeckType bingoDeck, int bingoNumber = 0, bool gameStarted = false)
{
	// when gameStarts first Console Line replace with random Number from bingoDeck.
	if (!gameStarted)
		std::cout << "Bingo game is ready!" << '\n' << '\n';
	else
		std::cout << "Bingo number is: " << bingoNumber << '\n' << '\n';


	for (int i = 0; i < constants::rowCountBingo; i++)
	{
		for (int j = 0; j < constants::columnCountBingo; j++)
		{
			// in gameplay stage, set value to 0 in bingoDeck which equals to bingoNumber.
			if (gameStarted && bingoDeck[i][j] == bingoNumber)
			{
				bingoDeck[i][j] = 0;
			}
			// for aligning purpose 7 and 17 needs both 2 space in Console.
			if (bingoDeck[i][j] < 10)
				std::cout << ' ' << bingoDeck[i][j] << ' ';
			else
				std::cout << bingoDeck[i][j] << ' ';
			// column end go to next line.
			if (j == constants::columnCountBingo - 1)
			{
				std::cout << '\n';
			}
		}
	}
	std::cout << '\n';
}

int userInputGetCardCount()
{
	std::cout << "How many cards do you want: ";
	int cardCount{};
	std::cin >> cardCount;
	return cardCount;
}

// get an Index value from vector which equals to startingNumber
int getIndexValueFromVector(std::vector<int> numberVector, int startingNumber)
{

	for (int i = 0; i < numberVector.size(); i++)
	{
		if (numberVector[i] == startingNumber)
			return i;
		else
			continue;
	}
	/*
	std::vector<int>::iterator it;
	it = std::find(numberVector.begin(), numberVector.end(), startingNumber);
	return static_cast<int>(it - numberVector.begin());
	
	//OR 

	std::vector<int>::iterator it;
	it = std::find(numberVector.begin(), numberVector.end(), startingNumber);
	int indexValue{ static_cast<int>(std::distance(numberVector.begin(), it)) };
	return indexValue;
	*/
}

advancedCardType createAdvancedCard(basicCardType basicCard)
{
	// because of every row needs to have 5 number. 
	//modThreeCounter seperates numbers between 3 rows. [0, 1, 2]
	int modThreeCounter{ 0 };
	int counter{ 0 };

	advancedCardType advancedCard{};
	// put numbers to columns and rows in advancedCard.
	for (int i = 0; i < constants::numberCountInCard;i++)
	{
		modThreeCounter = counter % 3;

		// if number is between 0 - 10
		if (basicCard[i] / 10 == constants::divide1s)
		{
			advancedCard[modThreeCounter][constants::divide1s] = basicCard[i];
			++counter;
		}
		// if number is between 10 - 20
		else if (basicCard[i] / 10 == constants::divide10s)
		{
			advancedCard[modThreeCounter][constants::divide10s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide20s)
		{
			advancedCard[modThreeCounter][constants::divide20s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide30s)
		{
			advancedCard[modThreeCounter][constants::divide30s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide40s)
		{
			advancedCard[modThreeCounter][constants::divide40s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide50s)
		{
			advancedCard[modThreeCounter][constants::divide50s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide60s)
		{
			advancedCard[modThreeCounter][constants::divide60s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide70s)
		{
			advancedCard[modThreeCounter][constants::divide70s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide80s || basicCard[i] / 10 == constants::divide90s)
		{
			advancedCard[modThreeCounter][constants::divide80s] = basicCard[i];
			++counter;
		}
	}

	
	int howManyNumberInSameColumn{ 0 };
	int firstNumbersRowIndex{};
	int firstNumberInSameColumn{};
	int secondNumberInSameColumn{};
	int tempInt{};
	// ordering numbers in same column from top to bottom in ASC order.
	for (int i = 0; i < constants::columnCountCard; i++)
	{
		howManyNumberInSameColumn = 0;

		for (int j = 0; j < constants::rowCountCard; j++)
		{
			if (advancedCard[j][i] != 0)
			{
				++howManyNumberInSameColumn;
				if (howManyNumberInSameColumn == 1)
				{
					firstNumbersRowIndex = j;
					firstNumberInSameColumn = advancedCard[j][i];
				}
				else if (howManyNumberInSameColumn == 2)
				{
					secondNumberInSameColumn = advancedCard[j][i];

					if (firstNumberInSameColumn > secondNumberInSameColumn)
					{
						tempInt = secondNumberInSameColumn;
						advancedCard[j][i] = firstNumberInSameColumn;
						advancedCard[firstNumbersRowIndex][i] = tempInt;
					}
				}

			}
		}
	}

	return advancedCard;
}

// sorting numbers inside basicCard
basicCardType sortBasicCardNumbers(basicCardType basicCard)
{
	int tempInt{};
	for (int i = 0; i < constants::numberCountInCard - 1; i++) {
		for (int j = i + 1; j < constants::numberCountInCard; j++) {
			if (basicCard[i] > basicCard[j]) {
				//swapping with smallest element of array.
				tempInt = basicCard[j];
				basicCard[j] = basicCard[i];
				basicCard[i] = tempInt;
			}
		}
	}
	return basicCard;
}


class controlNumbersInColumn
{
public:
	bool isDeleted = false;
	int howManyNumberPickedInColumn = 0;
	std::vector<int> valueWhenDividedTen{};
	int startingNumber {};
	int startingIndex {};
	bool twoOrMore = false;
	bool isFirstColumn = false;
	bool isLastColumn = false;
	std::vector<int> valuesInColumn{};
	int howManyWillDeleteFromDeck{};
};

basicCardType createBasicCard()
{

	basicCardType basicCard{};

	// creates a vector numbers from 1 to 90.
	// type is vector because for example we need to delete 9 numbers inside vector from the middle.
	std::vector<int> allNumbersInDeck{};
	allNumbersInDeck.reserve(constants::totalBingoDeckNumbers);
	for (int i = 0; i < constants::totalBingoDeckNumbers; i++)
	{
		allNumbersInDeck.push_back(i + 1);
	}

	std::vector<controlNumbersInColumn> conVec{};
	//MAKING CONTROL CLASS READY START
	for (int i = 0; i < constants::columnCountCard; i++)
	{
		controlNumbersInColumn control;

		control.isDeleted = false;
		control.twoOrMore = false;

		if (i == 0)
			control.isFirstColumn = true;

		if (control.isFirstColumn)
		{
			control.startingNumber = 1;
			control.howManyWillDeleteFromDeck = 9;
		}
		else
			control.startingNumber = i * 10;

		if (i == constants::columnCountCard - 1)
			control.isLastColumn = true;

		if (control.isLastColumn)
		{
			control.valueWhenDividedTen.push_back(i);
			control.valueWhenDividedTen.push_back(i + 1);

			control.howManyWillDeleteFromDeck = 11;
		}
		else
			control.valueWhenDividedTen.push_back(i);

		if (!control.isFirstColumn && !control.isLastColumn)
			control.howManyWillDeleteFromDeck = 10;

		control.howManyNumberPickedInColumn = 0;

		conVec.push_back(control);
	}

	bool randomNumberAvailable{};
	int randomIndex{};

	for (int i = 0; i < constants::numberCountInCard;i++)
	{
		for (int j = 0; j < constants::numberCountInCard;j++)
		{
			for (int k = 0; k < conVec.size(); k++)
			{
				if(basicCard[j] != 0 && std::find(conVec[k].valueWhenDividedTen.begin(), conVec[k].valueWhenDividedTen.end(), basicCard[j] / 10) != conVec[k].valueWhenDividedTen.end())
				{
					
					if (!conVec[k].isDeleted)
					{
						// if its size is 0, or contains the number.
						if (std::find(conVec[k].valuesInColumn.begin(), conVec[k].valuesInColumn.end(), basicCard[j]) != conVec[k].valuesInColumn.end())
							continue;
						else
							conVec[k].valuesInColumn.push_back(basicCard[j]);
						
						++conVec[k].howManyNumberPickedInColumn;

						if (conVec[k].howManyNumberPickedInColumn >= 2)
							conVec[k].twoOrMore = true;

						if (conVec[k].twoOrMore)
						{
							conVec[k].startingIndex = getIndexValueFromVector(allNumbersInDeck, conVec[k].startingNumber);

							
							for (int l = 0; l < conVec[k].howManyWillDeleteFromDeck; l++)
							{
								allNumbersInDeck.erase(allNumbersInDeck.begin() + conVec[k].startingIndex);
							}

							conVec[k].isDeleted = true;
							continue;
						}
					}
					else
						continue;
				}
			}
			
		}
		
		// this part sets card numbers one by one.
		randomNumberAvailable = false;

		while (!randomNumberAvailable)
		{
			randomNumberAvailable = true;
			randomIndex = rand() % allNumbersInDeck.size();

			for (int k = 0; k < constants::numberCountInCard; k++)
			{
				// controlling if any other card get that same value before.
				if (basicCard[k] != 0 && basicCard[k] == allNumbersInDeck[randomIndex])
					randomNumberAvailable = false;
			}

			if (randomNumberAvailable)
				basicCard[i] = allNumbersInDeck[randomIndex];

		}
	}

	return basicCard;
}

void createAdvancedCardStorage(int cardCount, std::vector<advancedCardType>& allCardsStorage)
{
	basicCardType basicCard{};
	allCardsStorage.reserve(cardCount);

	for (int i = 0;i < cardCount; i++)
	{
		basicCard = sortBasicCardNumbers(createBasicCard());
		allCardsStorage.push_back(createAdvancedCard(basicCard));
	}
}

void printCardToConsole(const advancedCardType& card)
{
	for (int i = 0; i < constants::rowCountCard; i++)
	{
		for (int j = 0; j < constants::columnCountCard; j++)
		{
			if (card[i][j] / 10 == constants::divide1s && card[i][j] != 0)
			{
				std::cout << ' ' << card[i][j] << " |";
			}
			else if (card[i][j] == 0)
			{
				std::cout << "-- |";
			}
			else
			{
				std::cout << card[i][j] << " |";
			}

		}
		std::cout << '\n';
	}
}

void printCards(const std::vector<advancedCardType>& cards)
{
	for (const advancedCardType& card : cards)
	{
		std::cout << '\n';
		printCardToConsole(card);
	}
}

std::vector<int> createBingoNumbersVector()
{
	std::vector<int> bingoNumbersVector{};

	for (int i = 0; i < constants::totalBingoDeckNumbers; i++)
	{
		bingoNumbersVector.push_back(i + 1);
	}
	return bingoNumbersVector;
}

int randomBingoNumberGenerator(std::vector<int>& bingoNumbersVector)
{
	int randomIndex{ static_cast<int>(rand() % bingoNumbersVector.size()) };
	int randomNumber{ bingoNumbersVector[randomIndex] };

	bingoNumbersVector.erase(bingoNumbersVector.begin() + randomIndex);
	return randomNumber;
}

void updateBingoDeck(bingoDeckType& mainBingoDeck ,int bingoNumber)
{
	for (int i = 0; i < constants::rowCountBingo; i++)
	{
		for (int j = 0; j < constants::columnCountBingo; j++)
		{
			if (mainBingoDeck[i][j] == bingoNumber)
			{
				mainBingoDeck[i][j] = 0;
			}
		}
	}
}

void updateCards(std::vector<advancedCardType>& cards, int bingoNumber)
{

	for (auto& card : cards)
	{
		for (int i = 0; i < constants::rowCountCard; i++)
		{
			for (int j = 0; j < constants::columnCountCard; j++)
			{
				if (card[i][j] == bingoNumber)
				{
					card[i][j] = 0;
				}
			}
		}
	}
}

bool startGame(bool& gameStarted)
{
	std::cout << '\n' << "Do you want to start game?: type [y/n]: ";
	char yesOrNo{};
	std::cin >> yesOrNo;

	if (yesOrNo == 'y') 
	{
		gameStarted = true;
		return gameStarted;
	}	
	else
	{
		gameStarted = false;
		return gameStarted;
	}
}

winnerType controlWinners(std::vector<advancedCardType>& updatedCards, winnerType& winners)
{

	int winnerRowCounter = 0;
	int totalZerosInColumn = 0;

	for (int c = 0; c < updatedCards.size(); c++)
	{
		winnerRowCounter = 0;
		for (int i = 0; i < constants::rowCountCard; i++)
		{
			totalZerosInColumn = 0;
			for (int j = 0; j < constants::columnCountCard; j++)
			{
				if (updatedCards[c][i][j] == 0) 
					++totalZerosInColumn;

				if (totalZerosInColumn == constants::columnCountCard)
					++winnerRowCounter;

				// winner of 1st cinko.
				if (totalZerosInColumn == constants::columnCountCard && winners[0] == 0)
					winners[0] = c + 1; // if c = 0, 1st card wins 1st cinko.

				// winner of 2nd cinko
				if (totalZerosInColumn == constants::columnCountCard && winnerRowCounter == 2 && winners[1] == 0)
					winners[1] = c + 1; // if c = 0, 1st card wins 2st cinko.
				
				// winner of Tombala
				if (totalZerosInColumn == constants::columnCountCard && winnerRowCounter == 3)
					winners[2] = c + 1; // if c = 0, 1st card wins tombala.
				
			}
		}
	}

	return winners;
}

void printWinners(const winnerType& winners)
{
	std::cout << '\n';

	if (winners[0] != 0)
		std::cout << "Card " << winners[0] << " wins 1st cinko.\n";
	if (winners[1] != 0)
		std::cout << "Card " << winners[1] << " wins 2nd cinko.\n";
	if (winners[2] != 0)
		std::cout << "Card " << winners[2] << " wins Tombala. Congratulations\n";
}

int main() {


	srand(time(0)); // seed for rand() function.

	//beginning of the game
	bingoDeckType mainBingoDeck = createBingoDeck();
	printBingoDeck(mainBingoDeck);

	int cardCount{ userInputGetCardCount()};

	std::vector<advancedCardType> allCards{};
	createAdvancedCardStorage(cardCount, allCards);
	printCards(allCards);

	// game starts
	bool gameStarted{ false };
	if (startGame(gameStarted))
	{
		std::vector<int> bingoNumbersVector = createBingoNumbersVector();
		winnerType winnersArray{};
		bool isThereAnyWinner{false};
		
		while (!isThereAnyWinner)
		{
			Sleep(250);
			system("CLS");
			int randomNumber = randomBingoNumberGenerator(bingoNumbersVector);
			updateBingoDeck(mainBingoDeck, randomNumber);
			printBingoDeck(mainBingoDeck, randomNumber, gameStarted);
			updateCards(allCards, randomNumber);
			printCards(allCards);
			printWinners(controlWinners(allCards, winnersArray));

			// winnersArray[0] 1st Cinko, winnersArray[1] 2nd Cinko, winnersArray[2] is Tombala
			if (winnersArray[2] != 0)
				isThereAnyWinner = true;
		}
	}
	return 0;
}

