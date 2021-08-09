#include <iostream>
int main()
{
    int cityLng,dataLng;
    short* outArr;
    short outLng=0;
    std::cin >> cityLng >> dataLng;
    outArr = new short[cityLng];
    for(short i=1;i<=cityLng;++i)
    {
        short* dataArr = new short[dataLng];
        int sum=0;
        for(short j=0;j<dataLng;++j)
        {
            short data;
            std::cin >> data;
            dataArr[j]=data;
            sum += data;
        }
        short biggerMinusSmaller=0;
        double avg=(double)sum/dataLng;
        for(short j=0;j<dataLng;++j)
        {
            if(avg < dataArr[j]) //bigger
               ++biggerMinusSmaller;
            else if(avg > dataArr[j]) //smaller
                --biggerMinusSmaller;
        }
        if(biggerMinusSmaller>0)
            outArr[outLng++]=i;
    }
    std::cout << outLng;
    for(short i=0;i<outLng;++i)
        std::cout << ' ' << outArr[i];
    return 0;
}
