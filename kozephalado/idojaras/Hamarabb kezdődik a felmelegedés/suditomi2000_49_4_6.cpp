#include <iostream>

int main()
{
    #define UNDEFINED 1001
    int cityLng, dayLng;
    std::cin >> cityLng >> dayLng;
    int warm1st_city=UNDEFINED,warm1st_day=UNDEFINED;
    int warm2nd_day=-1;
    for(int curCity=0;curCity<cityLng;++curCity)
    {
        int lastData;
        bool foundCold=false,foundWarm=false;
        for(int curDay=0;curDay<dayLng;++curDay)
        {
            int data;
            std::cin >> data;
            if(!foundWarm) //until not found warm
            {
                if(curDay)// day > 0
                    if(!foundCold)
                        foundCold = data < lastData; // Found Cold???
                    else if(data > lastData) //Found Warm
                    {
                        foundWarm=true;
                        if(curDay < warm1st_day)
                                warm1st_day=curDay,
                                warm1st_city=curCity;
                        else if(warm2nd_day <= curDay)
                            //warm1 != warm2;warm2 = 2nd smallest day
                            warm2nd_day=curDay;
                    }
                lastData=data;
            }
        }
    }
    std::cout << (warm1st_city != UNDEFINED && ( warm1st_day+1 <= warm2nd_day || warm2nd_day==-1&&warm1st_city>=0) ? warm1st_city+1 : -1 );
    return 0;
}
