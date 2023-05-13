#include<iostream>
using namespace std;

//CHECKING

 char space[3][3] = {{'1', '2', '3'},       // Declare the game grid as a 2D array
                     {'4', '5', '6'}, 
                     {'7', '8', '9'}};
 int row;
 int column;
 char token = 'X';
 string p1;
 string p2;
 bool tie;

// Function to display the game grid
void grid(){

    cout << "\n";
    cout << "        |       |   \n";
    cout << "    " << space[0][0] << "   |   " << space[0][1] << "   |   " << space[0][2] << "    \n";
    cout << " _______|_______|_______\n";
    cout << "        |       |        \n";
    cout << "    " << space[1][0] << "   |   " << space[1][1] << "   |   " << space[1][2] << "    \n";
    cout << " _______|_______|_______\n";
    cout << "        |       |   \n";
    cout << "    " << space[2][0] << "   |   " << space[2][1] << "   |   " << space[2][2] << "    \n";
    cout << "        |       |   \n";

}


// Function to get the player's move
void playersMove(){

int digit;

if(token == 'X'){
    cout<<p1<< " PLEASE ENTER: \n";
    cin>>digit; 
}

else if(token == 'O'){
    cout<<p2<< " PLEASE ENTER: \n";
    cin>>digit; 
}


// Convert the digit to row and column indices
if(digit == 1){
    row = 0;
    column = 0;
}

else if(digit == 2){
    row = 0;
    column = 1;
}

else if(digit == 3){
    row = 0;
    column = 2;
}

else if(digit == 4){
    row = 1;
    column = 0;
}

else if(digit == 5){
    row = 1;
    column = 1;
}

else if(digit == 6){
    row = 1;
    column = 2;
}

else if(digit == 7){
    row = 2;
    column = 0;
}

else if(digit == 8){
    row = 2;
    column = 1;
}

else if(digit == 9){
    row = 2;
    column = 2;
}

else{
    cout<< "INVALID ENTRY" <<endl;
    return;
}   

// Check if the chosen space is empty and assign the token
if(token == 'X' && space[row][column] != 'X' && space[row][column] != 'O'){
    space[row][column] = 'X';
    token = 'O';
}

else if(token == 'O' && space[row][column] != '0' && space[row][column] != 'X'){
    space[row][column] = 'O';
    token = 'X';
}

else {
    cout<<"THERE IS NO EMPTY SPACE."<<endl;
    return;
}

}

// Function to check if there is a win or draw
bool result(){
    for(int i = 0; i< 3; i++){
        // Check rows and columns for a win
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[0][2])
            return true;
    }

    //Check diagonals for a win
    if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
        return true;

    //Check for a draw
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            if(space[i][j] != 'X' && space[i][j] != 'O')
                return false;
        }
    }

    //If all spaces are filled, it's a tie
    tie = true;
    return false;
}



int main(){
    cout<<"ENTER PLAYER 1 NAME: \n";
    getline(cin, p1);
    cout<<"ENTER PLAYER 2 NAME: \n";
    getline(cin, p2);
    cout<<p1<< " WILL MOVE FIRST \n";
    cout<<p2<< " WILL MOVE SECOND \n";

    grid();     //Display the initial grid


    //Game loop
    while(!result()){
        playersMove();  // Get player's move
        grid(); // Display the updated grid
        result(); // Check for win or draw
    }

    // Print the result
    if(token == 'X' && tie == false){
        cout<<p1<<" WINS!"<<endl;
    }
    else if(token == 'O' && tie == false){
        cout<<p2<<" WINS!"<<endl;
    }
    else
        cout<<"ITS A DRAW."<<endl;
        return 0;
}
    