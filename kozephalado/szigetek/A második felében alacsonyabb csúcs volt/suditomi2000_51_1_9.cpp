#include <iostream>
//#define WIN32 0
#if WIN32
    #include<fstream>
    #define FILEPATH "D:/OneDrive/Qt/Szigetek1masodikFelebenAlacsonyabbCsucs/minta/"
    std::ifstream inFile(FILEPATH"be2.txt");
    std::ofstream outFile(FILEPATH"out.txt");
    #define in inFile
    #define out outFile
    #undef FILEATH
#else
    #define in std::cin
    #define out std::cout
#endif


int main()
{
    bool found=false;
    int Lng, smallestTop=99999;
    in >> Lng;
    if(Lng==2)
    {
        int num1,num2;
        in >> num1>>num2;
        out << (num1>num2);
        return 0;
    }
    if(Lng==3)
    {
        int num1,num2,num3;
        in >> num1 >> num2 >> num3;
        out << (num1>num2 || num1>num3);
        return 0;
    }
    int i;
    int data,lastData;
    in >> lastData;
    bool foundTaller=true;
    for(i=1;i<Lng/2;++i)
    {
        in >> data;
        if(foundTaller)
        {
            if(data < lastData)
            {
                if(lastData<smallestTop)
                    smallestTop=lastData;
                foundTaller=false;
            }
        }
        else foundTaller = lastData <= data;
        lastData=data;
    }
    if(foundTaller && lastData < data)
        smallestTop=data;
    ////////////////////////////
    data=0;
    foundTaller=true;
    in >> lastData;
    for(++i;i<Lng;++i)
    {
        in >> data;
        if(found)continue;
        if(foundTaller)
        {
            if(data < lastData)
            {
                if(lastData<smallestTop)
                    found=lastData<smallestTop;
                else foundTaller=false;
            }
        }
        else foundTaller = lastData < data;
        lastData=data;
    }
    if(!found && foundTaller)//end of island, but also stream's end
        found=lastData < smallestTop;
    std::cout << !found;
    #if WIN32
        inFile.close();
        outFile.close();
    #endif
    return 0;
}
#undef in
#undef out
