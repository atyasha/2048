
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 2048;
int board [4][4]={0};
static int sequence;
static int score_board;

int ranIndGen(){
    int rand_Ind = rand() % 4;
    return rand_Ind;
}

int new_ran_ind(){
    int rand_Elem = rand() % 10;
    rand_Elem = (rand_Elem==0) ? 4 : 2;
    return rand_Elem;
}

int to_win(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(board[i][j]==MAX){
                return 1;
            }
        }
    }
    return 0;
}

int game_over(){
    int the_game_is_over = 1;
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]==0 || board[i][j+1]==0 || board[i][j] == board[i][j+1]){
                the_game_is_over = 0;
                break;
            }
        }
    }
    for(int j=0; j<4; j++){
        for(int i=0; i<3; i++){
            if(board[i][j]==0 || board[i+1][j]==0 || board[i][j] == board[i+1][j]){
                the_game_is_over = 0;
                break	;
            }
        }
    }
    return the_game_is_over;
}

void display(){
    int index_ado, index_john, index_jude, index_jenny;
    
    while(1){
        index_ado = ranIndGen();
        index_john = ranIndGen();
        index_jude = ranIndGen();
        index_jenny = ranIndGen();
        if(index_ado==index_jude && index_john==index_jenny){
            continue;
        }
        else
            break;
    }
    
    if(sequence == 0){
        cout<<"##################"<<endl;
        cout<<"#    2048  GAME  #"<<endl;
        cout<<"##################"<<endl;
        cout<<"WELCOME TO MOST EXCITING GAME THAT CAN BLOW YOUR MIND"<<endl<<endl;
        cout<<"The Rules of the Game:"<<endl;
        cout<<"Use w(up), s(down), a(left), d(right) keys to move the tiles in certain direction"<<endl;
        cout<<"Double up and merge titles with the same number touch"<<endl<<endl;
        for(int i=0; i<4; i++){
            cout<<"|-----------------------|"<<endl;
            for(int j=0; j<4; j++){
                cout<<"|";
                if(i==index_ado && j==index_john){
                    board[i][j]=2;
                    cout<<"  "<<2<<"  ";
                }
                else if(i==index_jude && j==index_jenny){
                    int temp = new_ran_ind();
                    board[i][j] = temp;
                    cout<<"  "<<temp<<"  ";
                }
                    else
                        cout<<"     ";
            }
            cout<<"|"<<endl;
        }
        cout<<"|-----------------------|"<<endl;
    }
    
    else{
        for(int i=0; i<4; i++){
            cout<<"|-----------------------|"<<endl;
            for(int j=0; j<4; j++){
                cout<<"|";
                if(board[i][j]!=0){
                    if(board[i][j]==1024 || board[i][j]==2048)
                        cout<<" "<<board[i][j];
                    if(board[i][j]==128 || board[i][j]==256 || board[i][j]==512)
                        cout<<" "<<board[i][j]<<" ";
                    if(board[i][j]==16 || board[i][j]==32 || board[i][j]==64)
                        cout<<"  "<<board[i][j]<<" ";
                    if(board[i][j]==2 || board[i][j]==4 || board[i][j]==8)
                        cout<<"  "<<board[i][j]<<"  ";
                }
                else
                    cout<<"     ";
            }
            cout<<"|"<<endl;
        }
        cout<<"|-----------------------|"<<endl;
    }
   
}

void adding_element(){
    int index_jomel, index_jerimy;
    int flag=0;
    while(1){
        if(flag==1)break;
        index_jomel = ranIndGen();
        index_jerimy = ranIndGen();
        if(board[index_jomel][index_jerimy]==0){
            board[index_jomel][index_jerimy] = new_ran_ind();
            flag=1;
        }
    }
}


void leftkey_arrow(){
    int flag=0;
    for(int i=0; i<4; i++){
        int n=0;
        int prev=0;
        for (int j=0; j<4; j++)
        {
            if (n==board[i][j] && n!=0){
                board[i][prev] = 2*n;
                board[i][j] = 0;
                score_board+=2*n;
                n = 0;
                flag++;
                continue;
            }
            if (board[i][j]!=0){
                n = board[i][j];
                prev = j;
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<3; k++){
                if(board[i][k]==0 && board[i][k+1]!=0){
                    board[i][k]=board[i][k]^board[i][k+1];
                    board[i][k+1]=board[i][k]^board[i][k+1];
                    board[i][k]=board[i][k]^board[i][k+1];
                    flag++;
                }
            }
        }
    }
    if(flag!=0){
        adding_element();
        sequence++;
    }
    display();
}

void rightkey_arrow(){
    int flag=0;
    for(int i=0; i<4; i++){
        int n=0;
        int prev=0;
        for (int j=3; j>=0; j--)
        {
            if (n==board[i][j] && n!=0){
                board[i][prev] = 2*n;
                board[i][j] = 0;
                score_board+=2*n;
                n = 0;
                flag++;
                continue;
            }
            if (board[i][j]!=0){
                n = board[i][j];
                prev = j;
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=3; k>0; k--){
                if(board[i][k]==0 && board[i][k-1]!=0){
                    board[i][k]=board[i][k]^board[i][k-1];
                    board[i][k-1]=board[i][k]^board[i][k-1];
                    board[i][k]=board[i][k]^board[i][k-1];
                    flag++;
                }
            }
        }
    }
    if(flag!=0){
        adding_element();
        sequence++;
    }
    display();
}

void upkey_arrow(){
    int flag=0;
    for(int i=0; i<4; i++){
        int n=0;
        int prev=0;
        for (int j=0; j<4; j++)
        {
            if (n==board[j][i] && n!=0){
                board[prev][i] = 2*n;
                board[j][i] = 0;
                score_board+=2*n;
                n = 0;
                flag++;
                continue;
            }
            if (board[j][i]!=0){
                n = board[j][i];
                prev = j;
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<3; k++){
                if(board[k][i]==0 && board[k+1][i]!=0){
                    board[k][i]=board[k][i]^board[k+1][i];
                    board[k+1][i]=board[k][i]^board[k+1][i];
                    board[k][i]=board[k][i]^board[k+1][i];
                    flag++;
                }
            }
        }
    }
    if(flag!=0){
        adding_element();
        sequence++;
    }
    display();
}

void downkey_arrow(){
    int flag=0;
    for(int i=0; i<4; i++){
        int n=0;
        int prev=0;
        for (int j=3; j>=0; j--)
        {
            if (n==board[j][i] && n!=0){
                board[prev][i] = 2*n;
                board[j][i] = 0;
                score_board+=2*n;
                n = 0;
                flag++;
                continue;
            }
            if (board[j][i]!=0){
                n = board[j][i];
                prev = j;
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=3; k>0; k--){
                if(board[k][i]==0 && board[k-1][i]!=0){
                    board[k][i]=board[k][i]^board[k-1][i];
                    board[k-1][i]=board[k][i]^board[k-1][i];
                    board[k][i]=board[k][i]^board[k-1][i];
                    flag++;
                }
            }
        }
    }
    if(flag!=0){
        adding_element();
        sequence++;
    }
    display();
}

int main(){
    srand((unsigned)time(NULL));
    char ch, c;
    int tanong = 0;
    
    display();
    while(1){
        if(to_win() && !tanong){
            tanong = !tanong;
            cout<<sequence<<" steps"<<endl;
            cout<<"!!!YOU WIN!!!"<<endl;
            cout<<"Continue? (y/n)"<<endl;
            cin>>c;
            if(c=='n')
                exit(1);
        }
        if(game_over()){
            cout<<"~~~GAME OVER~~~"<<endl;
            exit(2);
        }
        cin>>ch;
        switch (ch) {
            case 'w':
                upkey_arrow();
                break;
            case 's':
                downkey_arrow();
                break;
            case 'a':
                leftkey_arrow();
                break;
            case 'd':
                rightkey_arrow();
                break;
            case 'q':
                exit(1);
            default:
                break;
        }
        
        cout<<"score: "<<score_board<<endl;
    }
    return 0;
}

