#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row;
int column;
bool draw=false;

void display_board(){
  system("cls");
  cout<<"\n\n           T I C  T A C  T O E \n\n"<<endl;
  cout<<"\t Player 1 [X] \n\t Player 2 [O]\n\n";
  cout<<"\t\t     |     |     \n";
  cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
  cout<<"\t\t_____|_____|_____\n";
  cout<<"\t\t     |     |     \n";
  cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
  cout<<"\t\t_____|_____|_____\n";
  cout<<"\t\t     |     |     \n";
  cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
  cout<<"\t\t     |     |     \n";
}

void player_turn(){
  int choice;
  if(turn=='X'){
    cout<<"\n\t Player 1 [X] turn:";
    cin>>choice;
    cout<<endl;
  }
  if (turn=='O'){
    cout<<"\n\t Player 2 [O] turn:";
    cin>>choice;
    cout<<endl;
  }

switch(choice){
  case 1:
      row=0;
      column=0;
      break;
  case 2:
      row=0;
      column=1;
      break;
  case 3:
      row=0;
      column=2;
      break;
  case 4:
      row=1;
      column=0;
      break;
  case 5:
      row=1;
      column=1;
      break;
  case 6:
      row=1;
      column=2;
      break;
  case 7:
      row=2;
      column=0;
      break;
  case 8:
      row=2;
      column=1;
      break;
  case 9:
      row=2;
      column=2;
      break;
  default:
      cout<<"\n\t INVALID INPUT \n";
      break;
  }
  if(turn=='X' && board[row][column]!='X' && board[row][column]!='O'){
    board[row][column]= 'X';
    turn='O';
  }
  else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O'){
    board[row][column]='O';
    turn='X';
  }
  else{
    cout<<"\t BOX ALREADY FILLED..\n\t PLEASE TRY AGAIN\n\n";
    player_turn();
  }
display_board();
}

bool game_over(){
 //checking if player wins
for(int i=0;i<3;i++){
 if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
 return false;
 }
 if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
 {return false;}
//if there's any box not filled
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(board[i][j]!='X' && board[i][j]!='O')
            return true;
    }
 }
//game draw
draw=true;
return false;
}

int main(){

  while(game_over()){
    display_board();
    player_turn();
    game_over();
  }

if(turn=='X' && draw==false){
    cout<<"\t PLAYER 2[O] WINS!! CONGRATULATIONS\n";
}
else if(turn=='O' && draw==false){
    cout<<"\t PLAYER 1[X] WINS!! CONGRATULATIONS\n";
}
else{
    cout<<"\t GAME DRAW!! \n";
}

}
