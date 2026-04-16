#include <iostream>
#include <ctime>
void drawboard(char *spaces);
void Player(char player,char *spaces);
void Computer(char player,char Computer,char *spaces);
bool win(char *spaces,char player);
bool tie(char *spaces,char computer,char player);
int main(){
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char C='O';
    char P='X';
    bool k=true;
    while(k){
        drawboard(spaces);
        Player(P,spaces);
        Computer(P,C,spaces);
        std::cout<<'\n';
        if(win(spaces,P)){
            std::cout<<"YOU WIN";
            drawboard(spaces);
            break;
        }
        else if(tie(spaces,C,P)){
            std::cout<<"IT'S A TIE!!";
            drawboard(spaces);
            break;
        }
        else{
            continue;
        }        
    }
    return 0;
}
void drawboard(char *spaces){
    std::cout<<"     "<<"|     "<<"|     \n";
    std::cout<<"  "<<spaces[0]<<"  "<<"|  "<<spaces[1]<<"  |"<<"  "<<spaces[2]<<"  \n";
    std::cout<<"_____"<<"|_____"<<"|_____\n";
    std::cout<<"     "<<"|     "<<"|     \n";
    std::cout<<"  "<<spaces[3]<<"  "<<"|  "<<spaces[4]<<"  |"<<"  "<<spaces[5]<<"  \n";
    std::cout<<"_____"<<"|_____"<<"|_____\n";
    std::cout<<"     "<<"|     "<<"|     \n";
    std::cout<<"  "<<spaces[6]<<"  "<<"|  "<<spaces[7]<<"  |"<<"  "<<spaces[8]<<"  \n";
    std::cout<<"     "<<"|     "<<"|     \n";
}
void Player(char player,char *spaces){
    int playermove;
    std::cout<<"Enter the place you want to place the pointer(1-9): "<<'\n';
    std::cin>>playermove;
    if(playermove>9){
        std::cout<<"Enter number between 1 to 9!!\n";
    }
    else if(playermove==1&&spaces[0]==' '){
        spaces[0]=player;
    }
    else if(playermove==2&&spaces[1]==' '){
        spaces[1]=player;
    }
    else if(playermove==3&&spaces[2]==' '){
        spaces[2]=player;
    }
    else if(playermove==4&&spaces[3]==' '){
        spaces[3]=player;
    }
    else if(playermove==5&&spaces[4]==' '){
        spaces[4]=player;
    }
    else if(playermove==6&&spaces[5]==' '){
        spaces[5]=player;
    }
    else if(playermove==7&&spaces[6]==' '){
        spaces[6]=player;
    }
    else if(playermove==8&&spaces[7]==' '){
        spaces[7]=player;
    }
    else if(playermove==9&&spaces[8]==' '){
        spaces[8]=player;
    }
    else{
        std::cout<<"Please enter the move properly\n";
    }
}
void Computer(char player,char Computer,char *spaces){
    int computermove;
    srand(time(0));
    computermove=rand()%9;
    for(int i=0;i<9;i++){
        if(computermove!=player){
            if(spaces[computermove]==' '){
                spaces[computermove]=Computer;
                break;
            }
            else{
                continue;
            }
        }
        else{
            computermove=rand()%9;
            continue;
        }
    }
}
bool win(char *spaces,char player){
    bool d=false;
    for(int i=0;i<9;i++){
        if(spaces[i]==player){
            if(spaces[i]==spaces[i+1]&&spaces[i+1]==spaces[i+2]){
                d=true;
            }
            else if(spaces[i]==spaces[i+3]&&spaces[i+3]==spaces[i+6]){
                d=true;
            }
            else if(spaces[i]==spaces[i+4]&&spaces[i+4]==spaces[i+8]){
                d=true;
            }
            else if(spaces[i]==spaces[i+2]&&spaces[i+2]==spaces[i+4]){
                d=true;
            }
        }
    }
    return d;
}
bool tie(char *spaces,char computer,char player){
    bool k=false;
    for(int i=0;i<9;i++){
        if(spaces[i]==computer||spaces[i]==player){
            if(i==8){
                k=true;
                break;
            }
            else{
                continue;
            }
        }
    }
    return k;
}