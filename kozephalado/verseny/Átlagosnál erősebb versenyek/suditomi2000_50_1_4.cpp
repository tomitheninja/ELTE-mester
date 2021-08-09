#include<iostream>
#if WIN32
    #include<fstream>
    #define FILEPATH "D:/OneDrive/Qt/Verseny1AtlagosnalErosebbVersenyek/minta/"
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
    int UNUSED;
    int compLng;

    in >> UNUSED >> compLng;
    for(int comp=0;comp<compLng;++comp)
        in >> UNUSED;
    double* compAvg = new double[compLng];
    int sumOfAll=0,countOfAllLng=0;
    for(int comp=0;comp<compLng;++comp)
    {
        int howMany, sum=0;
        in >> howMany;
        for(int stud=0;stud<howMany;++stud)
        {
            int studScr;
            in >> UNUSED >> studScr;
            sum += studScr;
        }
        compAvg[comp] = (double)sum / howMany;
        sumOfAll += sum;
        countOfAllLng += howMany;
    }
    double avg = (double)sumOfAll / countOfAllLng;
    int *outArr = new int[compLng];
    int outArrLng=0;
    for(int comp=0;comp<compLng;++comp)
        if(avg < compAvg[comp])
            outArr[outArrLng++] = comp;
    out << outArrLng;
    for(int i=0;i<outArrLng;++i)
        out << ' ' << outArr[i]+1;
    #if 0
        inFile.close();
        outFile.close();
    #endif
    return 0;
}
#undef in
#undef out
