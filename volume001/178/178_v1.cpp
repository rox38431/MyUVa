#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


int main() {
	int caseCount = 1;
	int inputCard[52];		// 將輸入的 52 張牌的輸入順序
	int posCard[16];		// 4 x 4 陣列每個位置為什麼牌
	int coverCount[16];		// 4 x 4 陣列每個位置已有多少牌


	while (true) {
		string inputWord;

		card *cardList = new card[13];	// 紀錄每個號碼的牌目前有在哪些位置
		for (int i = 0; i < 13; i++)
			cardList[i].next == NULL;

		for (int i = 0; i < 16; i++) {
			posCard[i] = -1;
			coverCount[i] = 0;
		}

		//---------- 接收 52 張牌的輸入 ---------- 
		for (int i = 0; i < 52; i++) {
			cin >> inputWord;
			if (i == 0 && inputWord == "#")
				return 0;
			else if (inputWord[0] <= 57 && inputWord[0] >= 49)
				inputCard[i] = inputWord[0] - 48;
			else if (inputWord[0] == 'A')
				inputCard[i] = 1;
			else if (inputWord[0] == 'T')
				inputCard[i] = 10;
			else if (inputWord[0] == 'J')
				inputCard[i] = 11;
			else if (inputWord[0] == 'Q')
				inputCard[i] = 12;
			else if (inputWord[0] == 'K')
				inputCard[i] = 13;
		}
		//---------- 接收 52 張牌的輸入 END ---------- 

		/*for (int i = 0; i < 52; i++)	{
			cout << inputCard[i] << "\t";
			if ((i + 1) % 13 == 0)
				cout << endl; 
		}*/

		int cardCount = 0;
		int posCount = 0;
		int findPair = 0, pairPos[2];
		int findTriple = 0, triplePos[3];
		bool overflow = false;
		//---------- 處理 ----------
		while (cardCount != 52) {
			
			if (findPair == 1)	{										// 若有找到一組 pair cover
				//cout << "Find pair: " << pairPos[0] << " " << pairPos[1] << endl; // <--------------------------------------------------------
				//cout << "Insert new card: "; // <--------------------------------------------------------
				for (int i = 0; cardCount < 52 && i < 2; ++i, ++cardCount) {
					//cout << inputCard[cardCount] << " ";
					posCard[pairPos[i]] = inputCard[cardCount];			// 更新 pairPos[i] 的牌
					coverCount[pairPos[i]]++;							// pairPosp[i] 位置牌數加一
				}
				//cout << endl << endl; // <--------------------------------------------------------

				findPair = 0;
			}
			else if (findTriple == 1) {									// 若有找到一組 triple cover
				//cout << "Find triple: " << triplePos[0] << " " << triplePos[1] << " " << triplePos[2] << endl; // <--------------------------------------------------------
				//cout << "Insert new card: "; // <--------------------------------------------------------
				for (int i = 0; cardCount < 52 && i < 3; ++i, ++cardCount) {
					//cout << inputCard[cardCount] << " "; // <--------------------------------------------------------
					posCard[triplePos[i]] = inputCard[cardCount];		// 更新 triplePos[i] 的牌
					coverCount[triplePos[i]]++;							// triplePosp[i] 位置牌數加一
				}
				//cout << endl << endl; // <--------------------------------------------------------

				findTriple = 0;
			}
			else {
				if (posCount > 15) {											// 新放的牌超過 4 x 4 矩陣的大小
					overflow = true;
					cout << setfill(' ') << setw(3) << caseCount++ << ": Overflowed on card no " << cardCount + 1 << endl;	// 輸出造成錯誤的是第幾張牌
					break;
				}
				else {															// 新放的牌自成一疊且不超過 4 x 4 矩陣
					//cout << inputCard[cardCount] << " 自成一疊" << endl << endl; // <--------------------------------------------------------
					posCard[posCount] = inputCard[cardCount];
					coverCount[posCount]++;

					++posCount;
					++cardCount;
				}
			}

			/*cout << "目前 4 x 4 矩陣地圖: " << endl;
			for (int i = 0; i < posCount; i++)	{
				cout << posCard[i] << "\t";
				if ((i + 1) % 4 == 0)
					cout << endl;
			}
			cout << endl << endl;

			cout << "目前 4 x 4 矩陣計數: " << endl;
			for (int i = 0; i < posCount; i++)	{
				cout << coverCount[i] << "\t";
				if ((i + 1) % 4 == 0)
					cout << endl;
			}
			cout << endl << endl;*/

			if (cardCount == 52)	// 已全部放完 52 張牌
				break;

			for (int i = 0; i < posCount; i++)	{
				if (posCard[i] <= 10)	{
					pairPos[0] = i;

					for (int j = i + 1; j < posCount; j++)	{
						if (posCard[i] + posCard[j] == 11) {
							//cout << "幫 " << posCard[i] << "找 cover" << endl; //<--------------------------------------------------------
							//cout << "   找到 " << posCard[j] << " 可以和它組成 pair cover" << endl << endl;
							pairPos[1] = j;
							findPair = 1; 
							break;
						}
					}

					if (findPair == 1)
						break;
				}
				else {
					int possibleSum[2];

					if (posCard[i] == 11) {
						possibleSum[0] = 23;
						possibleSum[1] = 24;
					}
					else if (posCard[i] == 12)	{
						possibleSum[0] = 23;
						possibleSum[1] = 25;
					}
					else {
						possibleSum[0] = 24;
						possibleSum[1] = 25;
					}

					triplePos[0] = i;
					int tempSum = posCard[i];
					for (int j = i + 1; j < posCount; j++)	{
						if ((tempSum + posCard[j] == possibleSum[0] || tempSum + posCard[j] == possibleSum[1]) && tempSum <= 13) {
							tempSum = tempSum + posCard[j];
							triplePos[1] = j;
						}
						else if (tempSum + posCard[j] == 36)	{
							//cout << "幫 " << posCard[i] << "找 cover" << endl; //<--------------------------------------------------------
							//cout << "   找到 " << posCard[triplePos[1]] << " 和 " << posCard[j] << " 可以和它組成 triple cover" << endl << endl;
							triplePos[2] = j;
							findTriple = 1;
							break;
						}
					}

					if (findTriple == 1)
						break;
				}


			}
		}
		//---------- 處理 ----------

		if (overflow == false)	{
			cout << setfill(' ') << setw(3) << caseCount++ << ":";
			for (int i = 0; i < posCount; i++)
				cout << setfill(' ') << setw(3) << coverCount[i];
			cout << endl;
		}
	}

	return 0;
}
