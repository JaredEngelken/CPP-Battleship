#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int columns = 10;
int maxships = 10;

char matrix[rows][columns];//Game board with all ships
char matrixDisp[rows][columns];//Game board with only sunken ships

void Clear(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            matrix[i][j]='O';//Make an empty sea grid
            matrixDisp[i][j]='O';
        }
    }
}

void Show(bool gameOver){
    if(gameOver){
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                cout<<matrix[i][j]<<" ";//Show to the game board with all floating and sunken ships
            }
        cout<<endl;
        }
    }
    else{
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                cout<<matrixDisp[i][j]<<" ";//Show to the game board with all floating and sunken ships
            }
        cout<<endl;
        }
    }
}

int NumberOfShips(){
    int c = 0;

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(matrix[i][j]=='0'){//If the current position is a ship
                c++;//Add the ship to the tally
            }
        }
    }
    return c;
}

void SetShips(){
    int s = 0;
    while(s<maxships){//Make 'maxships' number of ships at random positions
        int x=rand()%rows;
        int y=rand()%columns;
        if(matrix[x][y]!='0'){//If the current position is not already a ship
            s++;
            matrix[x][y] = '0';//Make the current position a ship
        }
    }
}

bool attack(int x, int y){
    if (matrix[x][y]=='0'){//If the coordinates are a ship
        matrix[x][y] = 'X';//The ship was hit
        matrixDisp[x][y] = 'X';
        return true;
    }
    return false;//Otherwise the ship was missed
}

int main(){
    srand(time(NULL));
    Clear();
    SetShips();

    int pos1, pos2;
    cout<<"Welcome to the game of Battleship! \nGuess the coordinates of the enemy ships by typing (x y) to eliminate them.\nType (100 100) to surrender."<<endl;
    while(1){
        cout<<"Input target location: "; cin>> pos1 >> pos2;
        system("CLS");
        if(pos1==100 && pos2==100){
            break;
        }
        if(attack(pos1,pos2)){
            cout<<"Target Hit!"<<endl;
            Show(0);
        }
        else{
            cout<<"Target missed..."<<endl;
            Show(0);
        }
        cout<<"Number of ships remaining: "<<NumberOfShips()<<endl;
        if(NumberOfShips()==0){
            cout<<"Congratulations! You sunk every enemy ship!"<<endl;
            system("pause");
            break;
        }
    }
    system("CLS");
    cout<<"Game Over!"<<endl;
    Show(1);
    system("pause");
    return(0);
}