#include <iostream>
#include <vector>
#include <array>
#include <cstdlib> //for using rand()


void createBingo()
{
	constexpr int rowCount = 9;
	constexpr int columnCount = 10;

	int bingoArr[rowCount][columnCount]{};
	int counter{ 1 };
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			bingoArr[i][j] = counter;

			if (bingoArr[i][j] < 10)
				std::cout << ' ' << bingoArr[i][j] << ' ';
			else
				std::cout << bingoArr[i][j] << ' ';

			if (bingoArr[i][j] % 10 == 0)
			{
				std::cout << '\n';
			}
			++counter;
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

std::array<int,15> createCard()
{

	constexpr int numberCountInCard{ 15 };

	std::array<int, numberCountInCard> cardArr{};

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


	for (int i = 0; i < numberCountInCard; i++)
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
		for (int j = 0; j < numberCountInCard; j++)
		{
			//for values from 1 to 9
			if (cardArr[j] != 0 && cardArr[j] / 10 == 0)
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
			else if (cardArr[j] != 0 && cardArr[j] / 10 == 1)
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
			else if (cardArr[j] != 0 && cardArr[j] / 10 == 2)
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
			else if (cardArr[j] != 0 && cardArr[j] / 10 == 3)
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
			else if (cardArr[j] != 0 && cardArr[j] / 10 == 4)
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
			else if (cardArr[j] != 0 && cardArr[j] / 10 == 5)
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
			else if (cardArr[j] != 0 && cardArr[j] / 10 == 6)
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
			else if (cardArr[j] != 0 && cardArr[j] / 10 == 7)
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
			else if (cardArr[j] != 0 && (cardArr[j] / 10 == 8 || cardArr[j] / 10 == 9))
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

			for (int i = 0; i < numberCountInCard; i++)
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

std::array<int, 15> sortCard(std::array<int, 15> unsortedArray)
{

	int tempInt{};
	for (int i = 0; i < 14; i++) {
		for (int j = i + 1; j < 15; j++) {
			if (unsortedArray[i] > unsortedArray[j]) {
				//swapping with smallest element of array.
				tempInt = unsortedArray[j];
				unsortedArray[j] = unsortedArray[i];
				unsortedArray[i] = tempInt;
			}
		}
	}

	return unsortedArray;
}

void printCards(int cardCount )
{
	constexpr int numberCountInCard{ 15 };
	std::array<int, numberCountInCard> cardArray{};

	for (int i = 0;i < cardCount; i++)
	{
		cardArray = createCard();

		cardArray = sortCard(cardArray);

		for (int j = 0; j < numberCountInCard; j++)
		{
			std::cout << cardArray[j] << ' ';
		}

		std::cout << '\n';
	}
}

int main() {

	createBingo();

	int cardCount{ howManyCards() };

	printCards(cardCount);

}




