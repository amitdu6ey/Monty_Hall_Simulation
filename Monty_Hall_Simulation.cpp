#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<iomanip>

int main(int argc, const char * argv[])
{
    freopen("./Outputs/<insert_file_name_here>.txt","w",stdout);
    int prize, choice, goat,totalTrials;    // choice is actually Gate selected. 
    double win=0, loose=0;
    srand(time(NULL));
    for(totalTrials=10;totalTrials<=1000000000;totalTrials*=10){
        win=0;
        loose=0;
        for(int i=0;i<totalTrials;i++){

            /*
                below if we fix 'only' one of choice or Prize then also we will get same result.
                choice=1;
                prize=1;
            */
            // Randomly choosing Gate and Prize value

            prize = rand()%3;
            choice = rand()%3;
            
            //one door is opened now which has Goat behind it.            
            
            for(int i=0;i<3;i++){
                if(i!=choice&&i!=prize){
                    goat=i;
                    break;
                }
            }
            /*
             and now we will change our choice of Gate.
            */
            for(int i=0;i<3;i++){
                if(i!=goat&&i!=choice){
                    choice=i;
                    break;
                }
            }
            if(choice==prize){
                win+=1;
            }
            else{
                loose+=1;
            }
        }
        std::cout<<"for Total trials = "<<std::setfill('0')<<std::setw(10)<<totalTrials<<" Probability of winning if we switch our choice is "<<" = "<<(double)win/totalTrials<<std::endl;
    }
    return 0;
}
