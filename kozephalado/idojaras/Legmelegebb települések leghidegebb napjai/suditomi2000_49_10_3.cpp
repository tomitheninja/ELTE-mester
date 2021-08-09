#include<iostream>
#if WIN32
    #include<fstream>
    #define FILEPATH "D:/OneDrive/Qt/Idojaras10LegmelegebbTelepulesLeghidegebbNap/minta/"
    std::fstream inFile(FILEPATH"be2.txt");
    std::fstream outFile(FILEPATH"out.txt");
    #define in inFile
    #define out outFile
    #undef FILEPATH
#else
    #define in std::cin
    #define out std::cout
#endif

int main()
{
    signed char max=-50;
    int cityLng, dayLng, dataLng, outArrLng=0;
    signed char *arr, *minOfCity, *maxOfCity;
    bool *outArr;
    in >> cityLng >> dayLng;
    dataLng = cityLng * dayLng;
    arr = new signed char[dataLng];
    minOfCity = new signed char[cityLng];
    maxOfCity = new signed char[cityLng];
    outArr = new bool[dayLng]();
    for(int city=0;city<cityLng;++city)
    {
        signed char cityMin=50, cityMax=-50;
        for(int day=0;day<dayLng;++day)
        {
            int data;
            in >> data;
            arr[city*dayLng+day]=data;
            if(cityMin > data )
                cityMin=data;
            if(cityMax < data)
                cityMax=data;
        }
        maxOfCity[city]=cityMax;
        minOfCity[city]=cityMin;
        if(max<cityMax)
            max=cityMax;
    }
    for(int city=0;city<cityLng;++city)
    {
        if(maxOfCity[city] == max)
        {
            int cityMin= minOfCity[city];
            for(int day=0;day<dayLng;++day)
            {
                if(!outArr[day])//no duplicate
                {
                    if(arr[city*dayLng+day]==cityMin)
                    {
                        outArr[day]=true;
                        ++outArrLng;
                    }
                }
            }
        }

    }
    out << outArrLng;
    for(int day=0;day<dayLng;++day)
    {
        if(outArr[day])
            out << ' ' << day+1;
    }
    return 0;
    #if WIN32
        inFile.close();
        outFile.close();
    #endif
}

#undef in
#undef out
