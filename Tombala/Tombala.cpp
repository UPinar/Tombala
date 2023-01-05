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

	constexpr int totalBingoNumbers{ 90 };

	constexpr int winnerCount{ 3 };
}



bool gameStarted{ false };

using basicCardType = std::array<int, constants::numberCountInCard>;
using advancedCardType = std::array <std::array<int, constants::columnCountCard>, constants::rowCountCard>;
using bingoType = std::array <std::array<int, constants::columnCountBingo>, constants::rowCountBingo>;
using winnerType = std::array<int, constants::winnerCount>;



bingoType createBingo()
{
	bingoType bingoArr{};
	int counter{ 1 };

	for (int i = 0; i < constants::rowCountBingo; i++)
	{
		for (int j = 0; j < constants::columnCountBingo; j++)
		{
			bingoArr[i][j] = counter;
			++counter;
		}
	}
	return bingoArr;
}

// bingoNumber set to 0 because it is optional. When the game started bingoNumber will come.
void printBingo(bingoType bingoArr, int bingoNumber = 0)
{
	if (!gameStarted)
		std::cout << "Bingo game is ready!" << '\n' << '\n';
	else
		std::cout << "Bingo number is: " << bingoNumber << '\n' << '\n';


	for (int i = 0; i < constants::rowCountBingo; i++)
	{
		for (int j = 0; j < constants::columnCountBingo; j++)
		{
			if (gameStarted && bingoNumber != 0 && bingoArr[i][j] == bingoNumber)
			{
				bingoArr[i][j] = 0;
			}

			if (bingoArr[i][j] < 10)
				std::cout << ' ' << bingoArr[i][j] << ' ';
			else
				std::cout << bingoArr[i][j] << ' ';

			// bingoArr[i][j] != 0 for update process.
			if (j == constants::columnCountBingo - 1)
			{
				std::cout << '\n';
			}
		}
	}
	std::cout << '\n';
}

int howManyCards()
{
	std::cout << "How many cards do you want: ";
	int cardCount{};
	std::cin >> cardCount;
	return cardCount;
}

int getIndexInVector(std::vector<int> numberVector, int startingValue)
{
	std::vector<int>::iterator it;
	it = find(numberVector.begin(), numberVector.end(), startingValue);
	int indexValue{ static_cast<int>(std::distance(numberVector.begin(), it)) };
	return indexValue;
}

advancedCardType prepareCardsForBingo(basicCardType basicCard)
{
	int indexCount{ 0 };

	int counter{ 0 };

	int modThreeCounter{ };

	std::array <std::array<int, constants::columnCountCard>, constants::rowCountCard> preparedArray{};

	for (int i = 0; i < constants::numberCountInCard;i++)
	{
		modThreeCounter = counter % 3;

		if (basicCard[i] / 10 == constants::divide1s)
		{
			preparedArray[modThreeCounter][constants::divide1s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide10s)
		{
			preparedArray[modThreeCounter][constants::divide10s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide20s)
		{
			preparedArray[modThreeCounter][constants::divide20s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide30s)
		{
			preparedArray[modThreeCounter][constants::divide30s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide40s)
		{
			preparedArray[modThreeCounter][constants::divide40s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide50s)
		{
			preparedArray[modThreeCounter][constants::divide50s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide60s)
		{
			preparedArray[modThreeCounter][constants::divide60s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide70s)
		{
			preparedArray[modThreeCounter][constants::divide70s] = basicCard[i];
			++counter;
		}
		else if (basicCard[i] / 10 == constants::divide80s || basicCard[i] / 10 == constants::divide90s)
		{
			preparedArray[modThreeCounter][constants::divide80s] = basicCard[i];
			++counter;
		}
	}

	// order values in same column in descending order.

	int howManyInColumn{ 0 };
	int firstValueInColumn{};
	int firstValueRowNumber{};
	int secondValueInColumn{};

	int tempInt{};

	for (int i = 0; i < constants::columnCountCard; i++)
	{
		howManyInColumn = 0;

		for (int j = 0; j < constants::rowCountCard; j++)
		{
			if (preparedArray[j][i] != 0)
			{
				++howManyInColumn;
				if (howManyInColumn == 1)
				{
					firstValueRowNumber = j;
					firstValueInColumn = preparedArray[j][i];
				}
				else if (howManyInColumn == 2)
				{
					secondValueInColumn = preparedArray[j][i];

					if (firstValueInColumn > secondValueInColumn)
					{
						tempInt = secondValueInColumn;
						preparedArray[j][i] = firstValueInColumn;
						preparedArray[firstValueRowNumber][i] = tempInt;
					}
				}

			}
		}
	}

	return preparedArray;
}

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

	basicCardType cardArr{};

	std::vector<int> allNumbersVector{};

	for (int i = 0; i < 90; i++)
	{
		allNumbersVector.push_back(i + 1);
	}


	int randomNumber{};

	bool deleted_1s{ 0 };
	bool deleted_10s{ 0 };
	bool deleted_20s{ 0 };
	bool deleted_30s{ 0 };
	bool deleted_40s{ 0 };
	bool deleted_50s{ 0 };
	bool deleted_60s{ 0 };
	bool deleted_70s{ 0 };
	bool deleted_80s{ 0 };


	for (int i = 0; i < constants::numberCountInCard; i++)
	{
		bool twoOrMore{};
		int control_1s{ 0 };
		int control_10s{ 0 };
		int control_20s{ 0 };
		int control_30s{ 0 };
		int control_40s{ 0 };
		int control_50s{ 0 };
		int control_60s{ 0 };
		int control_70s{ 0 };
		int control_80s{ 0 };

		// array'in butun degerleri kontrol edilecek.
		// 2 den fazla ayni kolonda bulunan deger varsa o 10 deger vectorden cikartilacak.
		for (int j = 0; j < constants::numberCountInCard; j++)
		{
			//for values from 1 to 9
			if (cardArr[j] != 0 && cardArr[j] / 10 == constants::divide1s)
			{

				if (deleted_1s)
					continue;

				++control_1s;

				if (control_1s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					int startingNumber{ 1 };
					int startingIndex{ getIndexInVector(allNumbersVector,startingNumber) };

					// from 1 to 9 there are 9 numbers.
					for (int k = 8; k >= 0; k--)
					{
						allNumbersVector.erase(allNumbersVector.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_1s = true;
					continue;
				}

			}
			//for values from 10 to 19
			else if (cardArr[j] != 0 && cardArr[j] / 10 == constants::divide10s)
			{

				if (deleted_10s)
					continue;

				++control_10s;

				if (control_10s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					int startingNumber{ 10 };
					int startingIndex{ getIndexInVector(allNumbersVector,startingNumber) };

					// from 10 to 19 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersVector.erase(allNumbersVector.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_10s = true;
					continue;
				}

			}
			//for values from 20 to 29
			else if (cardArr[j] != 0 && cardArr[j] / 10 == constants::divide20s)
			{

				if (deleted_20s)
					continue;

				++control_20s;

				if (control_20s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					int startingNumber{ 20 };
					int startingIndex{ getIndexInVector(allNumbersVector,startingNumber) };

					// from 20 to 29 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersVector.erase(allNumbersVector.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_20s = true;
					continue;
				}

			}
			//for values from 30 to 39
			else if (cardArr[j] != 0 && cardArr[j] / 10 == constants::divide30s)
			{
				if (deleted_30s)
					continue;

				++control_30s;

				if (control_30s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					int startingNumber{ 30 };
					int startingIndex{ getIndexInVector(allNumbersVector,startingNumber) };

					// from 30 to 39 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersVector.erase(allNumbersVector.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_30s = true;
					continue;
				}

			}
			//for values from 40 to 49
			else if (cardArr[j] != 0 && cardArr[j] / 10 == constants::divide40s)
			{

				if (deleted_40s)
					continue;

				++control_40s;

				if (control_40s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					int startingNumber{ 40 };
					int startingIndex{ getIndexInVector(allNumbersVector,startingNumber) };

					// from 40 to 49 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersVector.erase(allNumbersVector.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_40s = true;
					continue;
				}

			}
			//for values from 50 to 59
			else if (cardArr[j] != 0 && cardArr[j] / 10 == constants::divide50s)
			{

				if (deleted_50s)
					continue;

				++control_50s;

				if (control_50s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					int startingNumber{ 50 };
					int startingIndex{ getIndexInVector(allNumbersVector,startingNumber) };

					// from 50 to 59 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersVector.erase(allNumbersVector.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_50s = true;
					continue;
				}

			}
			//for values from 60 to 69
			else if (cardArr[j] != 0 && cardArr[j] / 10 == constants::divide60s)
			{
				if (deleted_60s)
					continue;

				++control_60s;

				if (control_60s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					int startingNumber{ 60 };
					int startingIndex{ getIndexInVector(allNumbersVector,startingNumber) };

					// from 60 to 69 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersVector.erase(allNumbersVector.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_60s = true;
					continue;
				}

			}
			//for values from 70 to 79
			else if (cardArr[j] != 0 && cardArr[j] / 10 == constants::divide70s)
			{

				if (deleted_70s)
					continue;

				++control_70s;

				if (control_70s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					int startingNumber{ 70 };
					int startingIndex{ getIndexInVector(allNumbersVector,startingNumber) };

					// from 70 to 79 there are 10 numbers.
					for (int k = 9; k >= 0; k--)
					{
						allNumbersVector.erase(allNumbersVector.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_70s = true;
					continue;
				}

			}
			//for values from 80 to 90
			else if (cardArr[j] != 0 && (cardArr[j] / 10 == constants::divide80s || cardArr[j] / 10 == constants::divide90s))
			{
				if (deleted_80s)
					continue;

				++control_80s;

				if (control_80s >= 2)
					twoOrMore = true;

				if (twoOrMore == true)
				{
					int startingNumber{ 80 };
					int startingIndex{ getIndexInVector(allNumbersVector,startingNumber) };

					// from 80 to 90 there are 10 numbers.
					for (int k = 10; k >= 0; k--)
					{
						allNumbersVector.erase(allNumbersVector.begin() + startingIndex + k);
					}

					twoOrMore = false;
					deleted_80s = true;
					continue;
				}

			}
		}


		bool randomNumberAvailable{ false };

		while (!randomNumberAvailable)
		{
			randomNumberAvailable = true;
			randomNumber = rand() % allNumbersVector.size();

			for (int i = 0; i < constants::numberCountInCard; i++)
			{
				if (cardArr[i] != 0 && cardArr[i] == allNumbersVector[randomNumber])
					randomNumberAvailable = false;
			}

			if (randomNumberAvailable)
				cardArr[i] = allNumbersVector[randomNumber];
		}
	}
	return cardArr;
}

void createCards(int cardCount, std::vector<advancedCardType>& allCards)
{
	basicCardType cardArray{};
	advancedCardType preparedCardArray{};

	
	allCards.reserve(cardCount);

	for (int i = 0;i < cardCount; i++)
	{
		cardArray = sortBasicCardNumbers(createBasicCard());
		allCards.push_back(prepareCardsForBingo(cardArray));
	}
}

void cardToConsole(const advancedCardType& card)
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
		cardToConsole(card);
	}
}

std::vector<int> createBingoDeck()
{
	std::vector<int> bingoNumbersVector{};

	for (int i = 0; i < 90; i++)
	{
		bingoNumbersVector.push_back(i + 1);
	}
	return bingoNumbersVector;
}

// referans gonderince sayi azaliyor.
int randomBingoNumberGenerator(std::vector<int>& bingoNumbersVector)
{
	int randomIndex{ static_cast<int>(rand() % bingoNumbersVector.size()) };
	int randomNumber{ bingoNumbersVector[randomIndex] };

	bingoNumbersVector.erase(bingoNumbersVector.begin() + randomIndex);
	return randomNumber;
}

void updateBingo(bingoType& mainBingoArray ,int bingoNumber)
{
	for (int i = 0; i < constants::rowCountBingo; i++)
	{
		for (int j = 0; j < constants::columnCountBingo; j++)
		{
			if (mainBingoArray[i][j] == bingoNumber)
			{
				mainBingoArray[i][j] = 0;
			}
		}
	}
}

void updateCards(std::vector<advancedCardType>& cards, int bingoNumber)
{
	// yeni sayi degistiginde (bingoNumber) cardlari update et.
	// update edilen cardlari printCards() fonksiyonuna yolla.

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

bool startGame() 
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
	if (winners[0] != 0)
		std::cout << winners[0] << " card wins 1. cinko." << '\n';
	if (winners[1] != 0)
		std::cout << winners[1] << " card wins 2. cinko." << '\n';
	if (winners[2] != 0)
		std::cout << winners[2] << " card wins Tombala. Congratulations" << '\n';
}

int main() {

	//beginning of the game
	bingoType mainBingoArray = createBingo();
	printBingo(mainBingoArray);

	int cardCount{ howManyCards()};

	std::vector<advancedCardType> allCards{};
	createCards(cardCount, allCards);
	printCards(allCards);


	// gameplay
	if (startGame())
	{
		std::vector<int> bingoNumbersVector{ createBingoDeck() };
		winnerType winnersArray{};
		
		while (winnersArray[2] == 0)
		{
			Sleep(400);
			system("CLS");
			int randomNumber = randomBingoNumberGenerator(bingoNumbersVector);
			updateBingo(mainBingoArray, randomNumber);
			printBingo(mainBingoArray, randomNumber);
			updateCards(allCards,randomNumber);
			printCards(allCards);
			printWinners(controlWinners(allCards, winnersArray));
		}
	}

}

