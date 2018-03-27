#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

void fnTestContain(int, float, float, int, float[][5]);

int main() {
	string sInput;
	float fFigurePos[10][5];
	int iFigureCount = 0;

	while (getline(cin, sInput)) {
		if (sInput == "*") {
			break;
		}
		else {
			string sTag;
			istringstream ss(sInput);

			ss >> sTag;
			if (sTag == "r")	{
				fFigurePos[iFigureCount][0] = 0;	// 表示此 Figure 的 type 為矩形
				for (int i = 1; i <= 4; i++)
					ss >> fFigurePos[iFigureCount][i];
			}
			else if (sTag == "c")
			{
				fFigurePos[iFigureCount][0] = 1; //表示此 FIgure 的 type 為圓形
				for (int i = 1; i <= 3; i++)
					ss >> fFigurePos[iFigureCount][i];
			}
			++iFigureCount;
		}
	}

	int iPointCount = 0;
	string sPointInput;
	while (getline(cin, sPointInput))	{
		string sPosX, sPosY;
		istringstream issTest(sPointInput);
		
		issTest >> sPosX >> sPosY;
		if (sPosX == "9999.9" && sPosY == "9999.9")
			break;
		else
		{
			float fPointPosX, fPointPosY;
			istringstream ss(sPointInput);

			ss >> fPointPosX >> fPointPosY;
			fnTestContain(iPointCount, fPointPosX, fPointPosY, iFigureCount, fFigurePos);
			++iPointCount;
		}
	}
	//system("pause");
	return 0;
}

void fnTestContain(int iPointCount, float fPointPosX, float fPointPosY, int iFigureCount, float fFigurePos[][5])	{

	bool bNotContain = true;
	for (int i = 0; i < iFigureCount; i++)	{
		if (fFigurePos[i][0] == 0)	{	// 矩形
			if (fPointPosX > fFigurePos[i][1] && fPointPosX < fFigurePos[i][3] && fPointPosY < fFigurePos[i][2] && fPointPosY > fFigurePos[i][4])	{
				cout << "Point " << iPointCount + 1 << " is contained in figure " << i + 1 << endl;
				bNotContain = false;
			}
		}
		else if (fFigurePos[i][0] == 1)	{	// 圓形 
			float fRadius, fXaxisDistance, fYaxisDistance;
			fXaxisDistance = fPointPosX - fFigurePos[i][1];
			fYaxisDistance = fPointPosY - fFigurePos[i][2];
			fRadius = sqrt(fXaxisDistance * fXaxisDistance + fYaxisDistance * fYaxisDistance);
			if (fRadius < fFigurePos[i][3])	{
				cout << "Point " << iPointCount + 1 << " is contained in figure " << i + 1 << endl;
				bNotContain = false;
			}
		}
	}
	
	if (bNotContain)
		cout << "Point " << iPointCount + 1 << " is not contained in any figure" << endl;
}