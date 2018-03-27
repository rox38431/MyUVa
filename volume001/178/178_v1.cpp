#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


int main() {
	int caseCount = 1;
	int inputCard[52];		// �N��J�� 52 �i�P����J����
	int posCard[16];		// 4 x 4 �}�C�C�Ӧ�m������P
	int coverCount[16];		// 4 x 4 �}�C�C�Ӧ�m�w���h�ֵP


	while (true) {
		string inputWord;

		card *cardList = new card[13];	// �����C�Ӹ��X���P�ثe���b���Ǧ�m
		for (int i = 0; i < 13; i++)
			cardList[i].next == NULL;

		for (int i = 0; i < 16; i++) {
			posCard[i] = -1;
			coverCount[i] = 0;
		}

		//---------- ���� 52 �i�P����J ---------- 
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
		//---------- ���� 52 �i�P����J END ---------- 

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
		//---------- �B�z ----------
		while (cardCount != 52) {
			
			if (findPair == 1)	{										// �Y�����@�� pair cover
				//cout << "Find pair: " << pairPos[0] << " " << pairPos[1] << endl; // <--------------------------------------------------------
				//cout << "Insert new card: "; // <--------------------------------------------------------
				for (int i = 0; cardCount < 52 && i < 2; ++i, ++cardCount) {
					//cout << inputCard[cardCount] << " ";
					posCard[pairPos[i]] = inputCard[cardCount];			// ��s pairPos[i] ���P
					coverCount[pairPos[i]]++;							// pairPosp[i] ��m�P�ƥ[�@
				}
				//cout << endl << endl; // <--------------------------------------------------------

				findPair = 0;
			}
			else if (findTriple == 1) {									// �Y�����@�� triple cover
				//cout << "Find triple: " << triplePos[0] << " " << triplePos[1] << " " << triplePos[2] << endl; // <--------------------------------------------------------
				//cout << "Insert new card: "; // <--------------------------------------------------------
				for (int i = 0; cardCount < 52 && i < 3; ++i, ++cardCount) {
					//cout << inputCard[cardCount] << " "; // <--------------------------------------------------------
					posCard[triplePos[i]] = inputCard[cardCount];		// ��s triplePos[i] ���P
					coverCount[triplePos[i]]++;							// triplePosp[i] ��m�P�ƥ[�@
				}
				//cout << endl << endl; // <--------------------------------------------------------

				findTriple = 0;
			}
			else {
				if (posCount > 15) {											// �s�񪺵P�W�L 4 x 4 �x�}���j�p
					overflow = true;
					cout << setfill(' ') << setw(3) << caseCount++ << ": Overflowed on card no " << cardCount + 1 << endl;	// ��X�y�����~���O�ĴX�i�P
					break;
				}
				else {															// �s�񪺵P�ۦ��@�|�B���W�L 4 x 4 �x�}
					//cout << inputCard[cardCount] << " �ۦ��@�|" << endl << endl; // <--------------------------------------------------------
					posCard[posCount] = inputCard[cardCount];
					coverCount[posCount]++;

					++posCount;
					++cardCount;
				}
			}

			/*cout << "�ثe 4 x 4 �x�}�a��: " << endl;
			for (int i = 0; i < posCount; i++)	{
				cout << posCard[i] << "\t";
				if ((i + 1) % 4 == 0)
					cout << endl;
			}
			cout << endl << endl;

			cout << "�ثe 4 x 4 �x�}�p��: " << endl;
			for (int i = 0; i < posCount; i++)	{
				cout << coverCount[i] << "\t";
				if ((i + 1) % 4 == 0)
					cout << endl;
			}
			cout << endl << endl;*/

			if (cardCount == 52)	// �w������ 52 �i�P
				break;

			for (int i = 0; i < posCount; i++)	{
				if (posCard[i] <= 10)	{
					pairPos[0] = i;

					for (int j = i + 1; j < posCount; j++)	{
						if (posCard[i] + posCard[j] == 11) {
							//cout << "�� " << posCard[i] << "�� cover" << endl; //<--------------------------------------------------------
							//cout << "   ��� " << posCard[j] << " �i�H�M���զ� pair cover" << endl << endl;
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
							//cout << "�� " << posCard[i] << "�� cover" << endl; //<--------------------------------------------------------
							//cout << "   ��� " << posCard[triplePos[1]] << " �M " << posCard[j] << " �i�H�M���զ� triple cover" << endl << endl;
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
		//---------- �B�z ----------

		if (overflow == false)	{
			cout << setfill(' ') << setw(3) << caseCount++ << ":";
			for (int i = 0; i < posCount; i++)
				cout << setfill(' ') << setw(3) << coverCount[i];
			cout << endl;
		}
	}

	return 0;
}
