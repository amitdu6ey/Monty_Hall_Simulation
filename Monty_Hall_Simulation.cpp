#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<iomanip>

int main(int argc, const char * argv[])
{
    freopen("Observations.txt","w",stdout);
    int prize, door, goat, totalTrials;
    double win = 0, loose = 0;
    srand(time(NULL));
    for(totalTrials = 10;totalTrials <= 1000000000;totalTrials *= 10){
        win = 0;
        loose = 0;
        for(int i = 0;i < totalTrials;i++){

            /*
                below if we fix 'only' one of door or Prize then also we will get same result.
                door=1;
                prize=1;
            */
            
            // Randomly choosing Gate and Prize value

            prize = rand()%3;
            door = rand()%3;

            //one door is opened now which has Goat behind it.

            for(int i = 0;i < 3;i++){
                if(i != door&&i != prize){
                    goat=i;
                    break;
                }
            }
            
            // and now we will change our door
            
            for(int i = 0;i < 3;i++){
                if(i != goat&&i != door){
                    door=i;
                    break;
                }
            }
            if(door == prize){
                win += 1;
            }
            else{
                loose += 1;
            }
        }
        std::cout<<"for Total trials = "<<std::setfill('0')<<std::setw(10)<<totalTrials<<" Probability of winning if we switch our door is "<<" = "<<(double)win/totalTrials<<std::endl;
    }
    return 0;
}
