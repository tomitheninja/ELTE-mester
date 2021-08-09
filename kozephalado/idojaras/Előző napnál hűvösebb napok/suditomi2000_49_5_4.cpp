#include <iostream>

unsigned short cityLng, dayLng,howMany=0,i=0,j;
bool *arr;
short data,lastData;
int main()
{
    std::cin >> cityLng >> dayLng;
    arr = new bool[dayLng]();
    for(;i<cityLng;++i)
    {
        std::cin >> lastData;
        for(j=1;j<dayLng;++j)
        {
            std::cin >> data;
            if(lastData > data)
            {
                if(!*(arr+j))++howMany;
                *(arr+j)=true;
            }
            lastData = data;
        }
    }
    std::cout << howMany;
    for(i=1;i<dayLng;++i)
        if(*(arr+i))
            std::cout << ' ' << i+1;
    return 0;
}
