import random 


#get number of iterations
while True:
    try:
        n = int(input("Enter the number of iterations you would like to run: "))
    except ValueError:
        print("Please enter a valid positive integer: ")
        continue
    if(n<=0):
        print("Please enter a valid positive integer: ")
        continue
    else:
        break
i = 0
switch_wins = 0
stay_wins = 0
doors = ['Door1', 'Door2', 'Door3']

while(i<n):
    i+=1
    car = random.randint(0,2) #Car is behind a random door
    car_door = doors[car]
    select = random.randint(0,2) #Player selects a random door
    select_door = doors[select]
    
    opening_opts = list(set(doors) - set(car_door+select_door)) #possible doors to open such that its not the car-door or the player selected door
    opening = opening_opts[random.randint(0,len(opening_opts)-1)] #opening one dud-door
    opening_door = doors[opening]
    
    #which option wins?
    if(car == select):
        stay_wins+=1
        print("Iteration :",i," Selection:",select_door," Opening Door:",opening_door," Car is behind ",car_door," Stay wins")    
    else:
        switch_wins+=1
        print("Iteration :",i," Selection:",select_door," Opening Door:",opening_door," Car is behind ",car_door,"Switch wins")
        
win_p = stay_wins*100/n

print("\nAfter ",n," iterations, percentage of Stay wins = ",win_p,"% and percentage of Switch wins = ",100-win_p,'%')  
    
