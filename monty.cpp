#include<iostream>
#include<limits>
#include<string>
#include<vector>


using namespace std;

int main()
{
    cout<<"Enter number of iterations:";
    int n;
    while(!(cin >> n) || n < 1){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter positive int:";
    }
    
    string Doors[3] = { "Door1", "Door2", "Door3" };
    int switching = 0, stay = 0;

    for(int i = 0; i<n ; i++) {
        //car is placed behind random Door
        string car_door = Doors[rand()%3];
        //player needs to make random initial selection
        string player_door = Doors[rand()%3];
        
        //list of doors that can be opened without revealing car
        vector<string> open_doors;
        int t = 0;
        for(int k = 0; k<3; k++) {
            if(Doors[k].compare(car_door) && Doors[k].compare(player_door)) {
                open_doors.push_back(Doors[k]);
                t++;
            }
        }
        //opening random door from opening list
        string opening_door = open_doors[rand()%t];
        cout<<"Iteration: "<<i+1<<" Car is behind: "<<car_door<<", Player has picked: "<<player_door<<", Open door is: "<<opening_door;
        //if player has not picked car_door, then switching would make them win
        if(car_door.compare(player_door)){
            switching++;
            cout<<", switching would make them win!\n\n";
        }
        else {
            stay++;
            cout<<", staying with their selection would make them win!\n\n";
        }
        
    }
    float sw_perc = (float)switching / (float)n;
    sw_perc*=100;
    cout<<"At the end, switching won "<<sw_perc<<"% and staying won "<<100-sw_perc<<"%";
    return 0;
}
