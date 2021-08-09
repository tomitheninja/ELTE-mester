#include <iostream>


int main()
{
    #define schar signed char
    short cityLng, dayLng;
    int dataLng;
    schar *arr;
    std::cin >> cityLng >> dayLng;
    dataLng = cityLng*dayLng;
    arr = new schar[dataLng];
    schar max=-50;
    short howManyOfMax=0;
    for(int i=0;i<dataLng;++i)
    {
        short data;
        std::cin >> data;
        arr[i]=data;
        if(max < data)
            howManyOfMax=1,
            max = data;
        else if(max == data)
            ++howManyOfMax;
    }
    short* maxindexes=new short[dayLng];
    short maxindexesLng=0;
    for(short x=0;x<dayLng;++x)
    {

        for(short y=0;y<cityLng;++y)
        {
            schar data = arr[y*dayLng+x];
            if(data == max)
            {
                maxindexes[maxindexesLng++]=x;
                break;
            }
        }
    }
    std::cout << maxindexesLng;
    for(short i=0;i<maxindexesLng;++i)
        std::cout << ' ' << maxindexes[i]+1;
    return 0;
}
