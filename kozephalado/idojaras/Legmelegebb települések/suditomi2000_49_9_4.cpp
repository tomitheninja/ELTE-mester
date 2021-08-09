#include <iostream>
#if WIN32
    #include<fstream>
    #define FILEPATH "D:/OneDrive/Qt/_94_Idojaras9LegmelegebbTelepules/minta/"
    std::ifstream infile(FILEPATH"be2.txt");
    std::ofstream outfile(FILEPATH"out.txt");
    #define in infile
    #define out outfile
    #undef FILEPATH
#else
    #define in std::cin
    #define out std::cout
#endif
int main()
{
    int cityLng, dayLng;
    signed char *arr;
    int max=-51;
    in >> cityLng >> dayLng;
    const int dataLng=cityLng*dayLng;
    arr = new signed char[dataLng];
    for(int i=0;i<dataLng;++i)
    {
        int data;
        in >> data;
        if(max < data)
            max = data;
        arr[i] = data;
    }
    short *outArr=new short[cityLng];
    int outArrLng=0;
    for(int y=0;y<cityLng;++y)
    {
        for(int x=0;x<dayLng;++x)
        {
            if(arr[y*dayLng+x]==max)
            {
                outArr[outArrLng++]=y;
                break;
            }
        }
    }
    out << outArrLng;
    for(int i=0;i<outArrLng;++i)
        out <<' '<< outArr[i]+1;
    #if WIN32
        infile.close();
        outfile.close();
    #endif
    return 0;
}
#undef in
#undef out
