#include <iostream>
#include <ctime>
using namespace std;
class date {
private:
    tm timeInfo = {};
public:
    date( int tag, int monat, int jahr) {
        timeInfo.tm_year = jahr;
        timeInfo.tm_mon = monat;
        timeInfo.tm_mday = tag;
    };
    tm newdifftime(tm time){
        tm result = {};
        if (timeInfo.tm_mday >= time.tm_mday){
            result.tm_mday = timeInfo.tm_mday - time.tm_mday;
        } else {
            result.tm_mday = time.tm_mday - timeInfo.tm_mday;
        }
        if (timeInfo.tm_mon >= time.tm_mon){
            result.tm_mon = timeInfo.tm_mon - time.tm_mon;
        } else {
            result.tm_mon = time.tm_mon - timeInfo.tm_mon;
        }
        if (timeInfo.tm_year >= time.tm_year){
            result.tm_year = timeInfo.tm_year - time.tm_year;
        } else {
            result.tm_year = time.tm_year - timeInfo.tm_year;
        }
        return result;
    };
    time_t newmktime(){
        
    };
};

tm aktuell(){
    time_t currentTime = time(nullptr);
    tm result = *std::localtime(&currentTime);
    return result;
}

int main() {

    return 0;
}
