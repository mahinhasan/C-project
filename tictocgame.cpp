#include<bits\stdc++.h>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<fstream>
char box[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row,col;
bool draw= false;

void display_box(){
    system("cls");
    std::cout<<"\tT I C k   C R O S S  G A M E\n"<<std::endl;
    std::cout<<"\tPlayer1 [X]\n\tplayer2 [0]\n"<<std::endl;

    std::cout<<"\t\t|-----|-----|-----|"<<std::endl;
    std::cout<<"\t\t|  "<<box[0][0]<<"  |   "<<box[0][1]<<" |  "<<box[0][2]<<"  |"<<std::endl;
    std::cout<<"\t\t|_____|_____|_____|"<<std::endl;
    std::cout<<"\t\t|     |     |     |"<<std::endl;
    std::cout<<"\t\t|  "<<box[1][0]<<"  |   "<<box[1][1]<<" |  "<<box[1][2]<<"  |"<<std::endl;
    std::cout<<"\t\t|_____|_____|_____|"<<std::endl;
    std::cout<<"\t\t|     |     |     |"<<std::endl;
    std::cout<<"\t\t|  "<<box[2][0]<<"  |   "<<box[2][1]<<" |  "<<box[2][2]<<"  |"<<std::endl;
    std::cout<<"\t\t|-----|-----|-----|"<<std::endl;
    std::cout<<std::endl;

}
void player_turn(){
    if(turn == 'X')
        std::cout<<"\n\tPlayer1 [X] turn:";
    else if(turn == '0')
     std::cout<<"\n\tPlayer2 [0] turn :";
    int choice;
    std::cin >> choice;

    switch(choice){
        case 1:
        row = 0;col = 0;break;
         case 2:
        row = 0;col = 1;break;
         case 3:
        row = 0;col = 2;break;
         case 4:
        row = 1;col = 0;break;
         case 5:
        row = 1;col = 1;break;
         case 6:
        row = 1;col = 2;break;
         case 7:
        row = 2;col = 0;break;
         case 8:
        row = 2;col = 1;break;
         case 9:
        row = 2;col = 2;break;

        default:
        std::cout<<"Try again"<<std::endl;
        break;

    }
    if(turn == 'X' && box[row][col]!= 'X'&& box[row][col]!= '0'){
        box[row][col]='X';
        turn = '0';
    }
     else if(turn == '0'&& box[row][col]!= 'X'&& box[row][col]!= '0'){
        box[row][col]='0';
        turn = 'X';
    }
    else{

        std::cout<<"You entered wrong Please try again:"<<std::endl;
        player_turn();
    }
    display_box();
}

bool game_over(){
    for(int i= 0;i<3;i++)
        if(box[i][0]==box[i][1]&&box[i][0]==box[i][2] ||box[0][i]==box[1][i]&&box[0][i]==box[2][i])
            return false;
        if(box[0][0]==box[1][1]&&box[0][0]==box[2][2]&&box[0][2]==box[1][1]&&box[0][2]==box[2][0])
            return false;
    for(int i =0;i<3;i++)
        for(int j = 0;j<3;j++)
            if(box[i][j]!='X'&&box[i][j]!='0')
            return true;
    draw = true;
    return false;

}


int main(){


while(game_over()){
display_box();
player_turn();
game_over();

}
if(turn=='X'&& draw==false)
    std::cout<<"Player2 [0] WInS"<<std::endl;
if(turn=='0'&& draw==false)
    std::cout<<"Player1 [X] WInS"<<std::endl;
else
    std::cout<<"GaMe Draw"<<std::endl;

return 0;
}
