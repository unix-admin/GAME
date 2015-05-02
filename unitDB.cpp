#include "unitDB.h"

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

const string FILE_UNITDB = "c:\\qt\\unitsdb.db";


sUnit *readUnitsData(int &outSize)
{
    sUnit *res = NULL;
    outSize = 0;

    fstream inFile;
    inFile.open(FILE_UNITDB.c_str(), ios_base::in);

    string readLine;
    bool isReadSize = false;

    int index = 0;

	while(!inFile.eof())
    { 
		
		getline(inFile, readLine);	
		
		if(readLine[0] == COMMENT_CHAR || readLine.empty())
            continue;

        if(isReadSize == false)
        {
            outSize = atoi(readLine.c_str());
            res = new sUnit[outSize];
            isReadSize = true;
			continue;
        }

        cout << readLine << " ";
        res[index].meType = (eUnitType)atoi(readLine.c_str());

        getline(inFile, readLine);
        cout << readLine << " ";
        res[index].miInithealth = atoi(readLine.c_str());

        getline(inFile, readLine);
        cout << readLine << " ";
        res[index].miMaxhealth = atoi(readLine.c_str());

        getline(inFile, readLine);
        cout << readLine << " ";
        res[index].miPoints = atoi(readLine.c_str());

        getline(inFile, readLine);
        cout << readLine << " ";
        res[index].miRange = atoi(readLine.c_str());

        getline(inFile, readLine);
        cout << readLine << " ";
        res[index].miPower = atoi(readLine.c_str());

        getline(inFile, readLine);
        cout << readLine << " ";
        res[index].miHealingrange = atoi(readLine.c_str());
        cout << "\n";
        res[index].x = index;
        res[index].y = index;
        ++index;
    }

    inFile.close();
    return res;
}
