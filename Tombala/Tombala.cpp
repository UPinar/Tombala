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

// get an Index value from vector which equals to startingValue
int getIndexValueFromVector(std::vector<int> numberVector, int startingValue)
{
	std::vector<int>::iterator it;
	it = find(numberVector.begin(), numberVector.end(), startingValue);
	int indexValue{ static_cast<int>(std::distance(numberVector.begin(), it)) };
	return indexValue;
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

basicCardType createBasicCard()
{

	basicCardType basicCard{};

	// creates a vector numbers from 1 to 90.
	// type is vector because for example we need to delete 9 numbers inside vector from the middle.
	std::vector<int> allNumbersInDeck{};
	for (int i = 0; i < constants::totalBingoDeckNumbers; i++)
	{
		allNumbersInDeck.push_back(i + 1);
	}

	// checking if values from that column are deleted from deck
	bool deleted_1s {};
	bool deleted_10s{};
	bool deleted_20s{};
	bool deleted_30s{};
	bool deleted_40s{};
	bool deleted_50s{};
	bool deleted_60s{};
	bool deleted_70s{};
	bool deleted_80s{};
	// for checking how many numbers in that column
	int control_1s  {};
	int control_10s {};
	int control_20s {};
	int control_30s {};
	int control_40s {};
	int control_50s {};
	int control_60s {};
	int control_70s {};
	int control_80s {};
	bool twoOrMore{};
	int startingNumber{};
	int startingIndex{};

	bool randomNumberAvailable{};
	int randomNumber{};

	for (int i = 0; i < constants::numberCountInCard; i++)
	{
		twoOrMore = false;
		control_1s = 0;
		control_10s = 0;
		control_20s = 0;
		control_30s = 0;
		control_40s = 0;
		control_50s = 0;
		control_60s = 0;
		control_70s = 0;
		control_80s = 0;

		// every column in advancedCard can have max 2 numbers.
		// example : in 3rd column [21,27] is possible, [21,27,29] is not possible.
		// if we have [21,27] we need to delete values from 20 - 29 from from deckNumbers
		for (int j = 0; j < constants::numberCountInCard; j++)
		{
			//for values from 1 to 9
			if (basicCard[j] != 0 && basicCard[j] / 10 == constants::divide1s)
			{

				if (deleted_1s)
					continue;

				++control_1s;

				if (control_1s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					startingNumber = 1;
					startingIndex = getIndexValueFromVector(allNumbersInDeck,startingNumber);

					// from 1 to 9 there are 9 numbers.
					for (int k = 8; k >= 0; k--)
					{
						allNumbersInDeck.erase(allNumbersInDeck.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_1s = true;
					continue;
				}

			}
			//for values from 10 to 19
			else if (basicCard[j] != 0 && basicCard[j] / 10 == constants::divide10s)
			{

				if (deleted_10s)
					continue;

				++control_10s;

				if (control_10s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					startingNumber = 10;
					startingIndex = getIndexValueFromVector(allNumbersInDeck,startingNumber);

					// from 10 to 19 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersInDeck.erase(allNumbersInDeck.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_10s = true;
					continue;
				}

			}
			else if (basicCard[j] != 0 && basicCard[j] / 10 == constants::divide20s)
			{

				if (deleted_20s)
					continue;

				++control_20s;

				if (control_20s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					startingNumber = 20;
					startingIndex = getIndexValueFromVector(allNumbersInDeck,startingNumber) ;

					// from 20 to 29 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersInDeck.erase(allNumbersInDeck.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_20s = true;
					continue;
				}

			}
			else if (basicCard[j] != 0 && basicCard[j] / 10 == constants::divide30s)
			{
				if (deleted_30s)
					continue;

				++control_30s;

				if (control_30s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					startingNumber = 30;
					startingIndex = getIndexValueFromVector(allNumbersInDeck,startingNumber);

					// from 30 to 39 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersInDeck.erase(allNumbersInDeck.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_30s = true;
					continue;
				}

			}
			else if (basicCard[j] != 0 && basicCard[j] / 10 == constants::divide40s)
			{

				if (deleted_40s)
					continue;

				++control_40s;

				if (control_40s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					startingNumber = 40;
					startingIndex = getIndexValueFromVector(allNumbersInDeck,startingNumber);

					// from 40 to 49 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersInDeck.erase(allNumbersInDeck.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_40s = true;
					continue;
				}

			}
			else if (basicCard[j] != 0 && basicCard[j] / 10 == constants::divide50s)
			{

				if (deleted_50s)
					continue;

				++control_50s;

				if (control_50s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					startingNumber = 50;
					startingIndex = getIndexValueFromVector(allNumbersInDeck,startingNumber);

					// from 50 to 59 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersInDeck.erase(allNumbersInDeck.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_50s = true;
					continue;
				}

			}
			else if (basicCard[j] != 0 && basicCard[j] / 10 == constants::divide60s)
			{
				if (deleted_60s)
					continue;

				++control_60s;

				if (control_60s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					startingNumber = 60;
					startingIndex = getIndexValueFromVector(allNumbersInDeck,startingNumber);

					// from 60 to 69 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersInDeck.erase(allNumbersInDeck.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_60s = true;
					continue;
				}

			}
			else if (basicCard[j] != 0 && basicCard[j] / 10 == constants::divide70s)
			{

				if (deleted_70s)
					continue;

				++control_70s;

				if (control_70s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					startingNumber = 70;
					startingIndex = getIndexValueFromVector(allNumbersInDeck,startingNumber);

					// from 70 to 79 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersInDeck.erase(allNumbersInDeck.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_70s = true;
					continue;
				}

			}
			else if (basicCard[j] != 0 && (basicCard[j] / 10 == constants::divide80s || basicCard[j] / 10 == constants::divide90s))
			{
				if (deleted_80s)
					continue;

				++control_80s;

				if (control_80s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					startingNumber = 80 ;
					startingIndex = getIndexValueFromVector(allNumbersInDeck,startingNumber);

					// from 80 to 90 there are 11 numbers.
					for (int k = 10; k >= 0; k--)
					{
						allNumbersInDeck.erase(allNumbersInDeck.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_80s = true;
					continue;
				}

			}
		}


		// this part sets card numbers one by one.
		randomNumberAvailable = false;

		while (!randomNumberAvailable)
		{
			randomNumberAvailable = true;
			randomNumber = rand() % allNumbersInDeck.size();

			for (int k = 0; k < constants::numberCountInCard; k++)
			{
				if (basicCard[k] != 0 && basicCard[k] == allNumbersInDeck[randomNumber])
					randomNumberAvailable = false;
			}

			if (randomNumberAvailable)
				basicCard[i] = allNumbersInDeck[randomNumber];
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
		
		// winnersArray[0] 1st Cinko, winnersArray[1] 2nd Cinko, winnersArray[2] is Tombala
		while (winnersArray[2] == 0)
		{
			Sleep(250);
			system("CLS");
			int randomNumber = randomBingoNumberGenerator(bingoNumbersVector);
			updateBingoDeck(mainBingoDeck, randomNumber);
			printBingoDeck(mainBingoDeck, randomNumber, gameStarted);
			updateCards(allCards, randomNumber);
			printCards(allCards);
			printWinners(controlWinners(allCards, winnersArray));
		}
	}

}

