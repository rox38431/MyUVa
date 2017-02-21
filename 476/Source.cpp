#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void test_contain(int, float, float, float[][4], int);

int main()	{
	string sRecInput;
	float fRecPos[10][4];
	int iRecCount = 0;
	

	while (getline(cin, sRecInput))	{
		if (sRecInput != "*")	{
			istringstream ss(sRecInput);
			string sTrash;
			ss >> sTrash;
			ss >> fRecPos[iRecCount][0];
			ss >> fRecPos[iRecCount][1];
			ss >> fRecPos[iRecCount][2];
			ss >> fRecPos[iRecCount][3];

			++iRecCount;
		}
		else
			break;
	}

	string sPointInput;
	float fPointX, fPointY;
	int iPointCount = 0;

	while (getline(cin, sPointInput))	{
		string sPointX, sPointY;
		istringstream sss(sPointInput);
		sss >> sPointX;
		sss >> sPointY;

		if (sPointX == "9999.9" && sPointY == "9999.9")
			break;

		istringstream fss(sPointInput);
		fss >> fPointX;
		fss >> fPointY;
		
		test_contain(iPointCount, fPointX, fPointY, fRecPos, iRecCount);

		++iPointCount;
	}

	return 0;
}

void test_contain(int iPointCount, float fPointX, float fPointY, float fRecPos[][4], int iRecCount)	{

	bool bContained = false;

	for (int i = 0; i < iRecCount; i++)	{
		if (fPointX > fRecPos[i][0] && fPointX < fRecPos[i][2] &&
			fPointY < fRecPos[i][1] && fPointY > fRecPos[i][3]) {
			cout << "Point " << iPointCount + 1 << " is contained in figure " << i + 1 << endl;
			bContained = true;
		}
	}

	if (bContained == false)
		cout << "Point " << iPointCount + 1 << " is not contained in any figure" << endl;
}