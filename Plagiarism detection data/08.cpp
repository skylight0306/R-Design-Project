//*********************** ************************************************************************/
//程式簡介
//系級:資工二甲
//姓名: 郭靜    10327127
//      陳家康  10311138
//************************************************************************************************/

#include <iostream>															            //必要標頭檔, 盡量 勿移除！
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
#include <time.h>
#include <string.h>

using namespace std;

class dog{
    public :

        char aname[1000];
        char qname[1000];
};

vector<dog> sudo;                       //sudo裡面有很多dog
vector<int> point(20);                  //zero裡面有很多int

void getNewSudo(int[5][5]);
dog SaveSudo(int[5][5]);

void ShowSudo(char[]);
void RemoveSudo(char[]);
void PracticeSudo();
void Printzero(int[5][5]);
bool Lookforzero(int[5][5],int[5][5]);
bool Havezeroornot(int[5][5]);
void PlaySudo();
void LookPoints();


int cat[5][5] ;
int cat2[5][5] ; // 放解答用的
int points = 10;
int num = 1;
fstream file;                       //宣告檔案

int main(int argc, char *argv[])
{
    char thefirstcommand;
    cout << "***** 超級無敵迷你數獨小遊戲 *****\n";
    cout << "*****      Q. 遊戲結束       *****\n";
    cout << "*****      M. 管理           *****\n";
    cout << "*****      P. 遊戲           *****\n";
    cout << "**********************************\n";
    cout << "Input a command(Q, M, P): \n";
    cin >> thefirstcommand;
    int command = 0;

    while (thefirstcommand != 'Q') {
        if (thefirstcommand == 'M') {            // 進入管理

            cout << "***** 超級無敵迷你數獨小遊戲 *****\n";
            cout << "*****      0. 跳出管理       *****\n";
            cout << "*****      1. 新增題型       *****\n";
            cout << "*****      2. 顯示題型       *****\n";
            cout << "*****      3. 刪除題型       *****\n";
            cout << "**********************************\n";
            cout << "Input a command(0, 1, 2, 3): \n";
	        cin >> command;

         	char input[1000];

        	while ( command != 0 ) {

	            if ( command == 1 ) {
	                getNewSudo(cat);
	                sudo.push_back (SaveSudo(cat));
    	            cout << "→新增完成←\n" << "\n";

             	}
            	else if (command == 2 ) {
    	            cout << "請輸入[題號]+[Q]\n";
    	            cin >> input ;
        	        ShowSudo(input);
	            }
    	        else if ( command == 3 ) {
                    cout << "請輸入[題號]+[Q]\n";
	                cin >> input ;
	                RemoveSudo(input);
            	}

                cout << "***** 超級無敵迷你數獨小遊戲 *****\n";
                cout << "*****      0. 跳出管理       *****\n";
                cout << "*****      1. 新增題型       *****\n";
                cout << "*****      2. 顯示題型       *****\n";
                cout << "*****      3. 刪除題型       *****\n";
                cout << "**********************************\n";
	            cout << "Input a command(0, 1, 2, 3): \n";
                cin >> command;
	        } // while

        } //if
        else if (thefirstcommand == 'P') {            // 進入遊戲


            cout << "***** 超級無敵迷你數獨小遊戲 *****\n";
            cout << "*****      0. 跳出遊戲       *****\n";
            cout << "*****      1. 練習           *****\n";
            cout << "*****      2. 開始闖關       *****\n";
            cout << "*****      3. 觀看得分       *****\n";
            cout << "**********************************\n";
            cout << "Input a command(0, 1, 2, 3): \n";
	        cin >> command;

	        for (int i = 0 ; i < 10 ; i++){         //載入10題
                getNewSudo(cat);
                sudo.push_back (SaveSudo(cat));
            }

            while (command != 0) {

                if (command == 1){
                    cout << "→目前已有10題←\n" << "請輸入[題號1~10]+[Q]\n";
                    PracticeSudo();
                }
                else if (command == 2){
                    cout << "\n";
                    cout << "計分方式 : 滿分10分，答錯一次扣一分，扣完為止。\n" << "\n";
                    cout << "\n";
                    cout << "→目前已有10題←\n" << "請輸入[題號1~10]+[Q]\n";
                    PlaySudo();

                    int number = point.size(); //分數放進point裡
                    point.push_back(points);
                    points = 10;
                }
                else if (command == 3){
                    LookPoints();
                }

                cout << "***** 超級無敵迷你數獨小遊戲 *****\n";
                cout << "*****      0. 跳出遊戲       *****\n";
                cout << "*****      1. 練習           *****\n";
                cout << "*****      2. 開始闖關       *****\n";
                cout << "*****      3. 觀看得分       *****\n";
                cout << "**********************************\n";
                cout << "Input a command(0, 1, 2, 3): \n";

                cin >> command;
            }
        }
        cout << "***** 超級無敵迷你數獨小遊戲 *****\n";
        cout << "*****      Q. 遊戲結束       *****\n";
        cout << "*****      M. 管理           *****\n";
        cout << "*****      P. 遊戲           *****\n";
        cout << "**********************************\n";
        cout << "Input a command(Q, M, P): \n";
        cin >> thefirstcommand;
    }

    system("PAUSE");
    return 0;
}

void getNewSudo(int cat[5][5]){              //創造新數獨

    for (int i = 0 ; i < 5 ; i++) {         //初始化
        for (int j = 0 ; j < 5 ; j++) {
            cat[i][j] = 0;
        }
    }

    for (int i = 0 ; i < 5 ; i++) {          //初始化
        for (int j = 0 ; j < 5 ; j++) {
            cat2[i][j] = 0;
        }
    }

    int temp,count = 0;
    bool repeatornot = false ;
    srand(time(NULL));

    for (int i = 1 ; i <= 4 ; i ++){
        for (int j = 1 ; j <= 4 ; j++){
            if (count > 50) {
                j = 1;
                count = 0 ;
            }

            temp = rand()%4 + 1;               //取亂數
            cat[i][j] = temp;

            if (j >= 2) {
                for (int z = j-1 ; z >= 1 ; z--)
                    if (cat[i][j] == cat[i][z]) repeatornot = true ; //如果重複到了
            }

            if (i >= 2) {
                for (int z = i-1 ; z >= 1 ; z--)
                    if (cat[i][j] == cat[z][j]) repeatornot = true ; //如果重複到了
            }

            if ( i == 2 ) {
                if (cat[2][1] == cat[1][2] || cat[2][2] == cat[1][1] ||
                    cat[2][3] == cat[1][4] || cat[2][4] == cat[1][3]) repeatornot = true ; // 左邊2x2
            }

            if ( i == 4 ) {
                if (cat[4][1] == cat[3][2] || cat[4][2] == cat[3][1] ||
                    cat[4][3] == cat[3][4] || cat[4][4] == cat[3][3]) repeatornot = true ; // 右邊2x2
            }


            if (repeatornot){ //如果重複
                j--;
                count++;
            }
            repeatornot = false;
        }
    }
}

dog SaveSudo(int cat[5][5]){            //儲存數獨

    dog tiger;
    int i = 0;
    char buffer[5];                     //為了印出存在
    itoa(num,tiger.aname,10);                  // int to string

    for (i = 0 ; tiger.aname[i] != '\0' ; i++ );
    tiger.aname[i] = 'A';
    tiger.aname[i+1] = '\0';

    file.open(tiger.aname, ios::out);                    // 存入數獨
    for(int j = 1 ; j <= 4 ; j++) {
        for (int i = 1 ; i <= 4 ; i ++) file << cat[i][j];
        file << "\n";
    }

    file.close();       //關閉檔案

    //-------------------------------------------------------------

    itoa(num,tiger.qname,10);                  // int to string

    for (i = 0 ; tiger.qname[i] != '\0' ; i++ );
    tiger.qname[i] = 'Q';
    tiger.qname[i+1] = '\0';

    file.open(tiger.qname, ios::out);                    // 存題目
    for (int x = 0 ; x < 5 ; x++) {
         int a = rand()%4 + 1;
         int b = rand()%4 + 1;
         cat[a][b] = 0;
    }

    for(int j = 1 ; j <= 4 ; j++) {
        for (int i = 1 ; i <= 4 ; i ++) file << cat[i][j];
        file << "\n";
    }

    file.close();       //關閉檔案

    num++;
    return tiger;

}

void ShowSudo(char input[]) {                //顯示數獨

    int n = sudo.size();
    bool repeat = false;
    for (int i = 0 ; i < n ; i++){      //找到一樣的檔名即true
        if (strcmp(input,sudo[i].qname) == 0 )repeat = true;
    }

    char buffer[5];                     //為了印出存在
    if (repeat){
        file.open(input, ios::in); //所需檔名的數獨成讀取狀態
        for(int a = 1 ; a <= 4 ; a++) {
            file.getline(buffer,sizeof(buffer));      //印出數獨
            cout << buffer << "\n";
        }
    }
    else cout << "尚未有此數獨!\n" ;              //否則

    file.close();    //關閉檔案
}

void RemoveSudo(char input[]) {
    int n = sudo.size();
    int i = 0;
    bool repeat = false;
    for (i = 0 ; i < n ; i++){                 //找到一樣的檔名即true
        if (strcmp(input,sudo[i].qname) == 0 )repeat = true;
        cout << sudo[i].qname << "\n";
        cout << "\n";
    }

    int a = i - 1;
    if (repeat){
        sudo.erase(sudo.begin()+a);
    }
    else cout << "尚未有此數獨!\n" ;              //否則

    repeat = false;

}

void PracticeSudo() {               //練習開始

    for (int i = 0 ; i < 5 ; i++) {      //初始化
        for (int j = 0 ; j < 5 ; j++) {
            cat[i][j] = 0;
        }
    }

    for (int i = 0 ; i < 5 ; i++) {       //初始化
        for (int j = 0 ; j < 5 ; j++) {
            cat2[i][j] = 0;
        }
    }

    cout << "練習開始\n";
    int fish;
    char input2[1000];
    cin >> input2;
    bool finish = false;
    int aa = 0 ; // 練習題在vector的位置

    int n = sudo.size();
    bool repeat = false;
    for (aa = 0 ; aa < n ; aa++){      //找到一樣的檔名即true
        if (strcmp(input2,sudo[aa].qname) == 0 ){
            fish = aa;
            repeat = true;
        }
    }

    char temp;                     //為了印出存在
    if (repeat){
        file.open(input2, ios::in); //所需檔名的數獨成讀取狀態
        for(int i = 1 ; i < 5 ; i++) {
            for (int j = 1 ; j < 5 ; j++){
                file.get(temp);      //印出數獨
                cout << temp ;
                cat[i][j] = (int)temp - 48;
            }
            file.get(temp); // 讀掉換行
            cout << "\n";
        }
    }
    else cout << "尚未有此數獨!\n" ;              //否則

    file.close();    //關閉檔案

    file.open(sudo[fish].aname, ios::in); //所需檔名的數獨成讀取狀態
    for(int i = 1 ; i < 5 ; i++) {
        for (int j = 1 ; j < 5 ; j++){
            file.get(temp);      //印出數獨
            cat2[i][j] = (int)temp - 48;
        }
        file.get(temp); // 讀掉換行
        cout << "\n";

    }

    file.close();    //關閉檔案

    //------------------------------------------------------------------------

    while (!finish){ // 未完成
      cout << "請輸入你要做答的位置 : ";
      Printzero(cat); //找0並印出位置

      if ( Lookforzero(cat,cat2) ) { // 如果輸入的那格是0

          if (Havezeroornot(cat)) {  // 如果還有0
            for(int i = 1 ; i < 5 ; i++) {
                for (int j = 1 ; j < 5 ; j++) cout << cat[i][j];
                cout << "\n";
            }
            cout << "\n";

          }
          else finish = true; // 題目沒有0了 就結束迴圈

      } // if
      else cout << "→你輸入的位置錯誤!!←\n";   //如果輸入的那格不是0
    } // while

    cout << "→恭喜你答對了!!!←\n";
    cout << "\n";

}

void Printzero(int cat[5][5]){  // 印0的位置

    for (int i = 1 ; i < 5 ; i++){
       for (int j = 1 ; j < 5 ; j++){
           if (cat[i][j] == 0 ) {
               cout << "(" << i << "," << j << ") ";
           }
       }
    }
    cout << "。\n";
    cout << "\n";
}

bool Lookforzero(int cat[5][5],int cat2[5][5]){  // 看是不是0的位置並檢查答案正不正確
    int x,y;
    int input3;
    cout << "x = ";
    cin >> x;
    cout << "\n";

    cout << "y = ";
    cin >> y;
    cout << "\n";

    if (cat[x][y] == 0 ) {
        cout << "答案是 : ";
        cin >> input3 ;
        cout << "\n";

        if ( cat2[x][y] == input3 ) {
            cout << "此格答對了!!\n" ;
            cout << "\n";
            cat[x][y] = input3; // 正確答案換上去
        }
        else {
            points--;
            cout << "此格答錯了!!\n";
        }

        return true;
    }
    else return false ;
}

bool Havezeroornot(int cat[5][5]){
    for(int i = 1 ; i < 5 ; i++) {
        for (int j = 1 ; j < 5 ; j++) {
            if (cat[i][j] == 0) return true;     //只要有看到0就回傳true
        }
    }
    return false;
}

void PlaySudo() {
    time_t start_time, end_time;      //計算秒數
    start_time = time(NULL);

    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            cat[i][j] = 0;
        }
    }

    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            cat2[i][j] = 0;
        }
    }

    cout << "闖關開始\n";
    int fish;
    char input2[1000];
    cin >> input2;
    bool finish = false;
    int aa = 0 ; // 練習題在vector的位置

    int n = sudo.size();
    bool repeat = false;
    for (aa = 0 ; aa < n ; aa++){      //找到一樣的檔名即true
        if (strcmp(input2,sudo[aa].qname) == 0 ){
            fish = aa;
            repeat = true;
        }
    }

    char temp;                     //為了印出存在
    if (repeat){
        file.open(input2, ios::in); //所需檔名的數獨成讀取狀態
        for(int i = 1 ; i < 5 ; i++) {
            for (int j = 1 ; j < 5 ; j++){
                file.get(temp);      //印出數獨
                cout << temp ;
                cat[i][j] = (int)temp - 48;
            }
            file.get(temp); // 讀掉換行
            cout << "\n";
        }
    }
    else cout << "尚未有此數獨!\n" ;              //否則

    file.close();    //關閉檔案

    file.open(sudo[fish].aname, ios::in); //所需檔名的數獨成讀取狀態
    for(int i = 1 ; i < 5 ; i++) {
        for (int j = 1 ; j < 5 ; j++){
            file.get(temp);      //印出數獨
            cat2[i][j] = (int)temp - 48;
        }
        file.get(temp); // 讀掉換行
        cout << "\n";

    }

    file.close();    //關閉檔案

    //------------------------------------------------------------------------

    while (!finish){ // 未完成
      cout << "請輸入你要做答的位置 : ";
      Printzero(cat); //找0並印出位置

      if ( Lookforzero(cat,cat2) ) { // 如果輸入的那格是0

          if (Havezeroornot(cat)) {  // 如果還有0
            for(int i = 1 ; i < 5 ; i++) {
                for (int j = 1 ; j < 5 ; j++) cout << cat[i][j];
                cout << "\n";
            }
            cout << "\n";

          }
          else finish = true; // 題目沒有0了 就結束迴圈

      } // if
      else cout << "→你輸入的位置錯誤!!←\n";   //如果輸入的那格不是0
    } // while

    end_time = time(NULL);
    int min = difftime(end_time,start_time);

    cout << "→恭喜你答對了!!!←\n";
    cout << "\n";
    cout << "你的得分 : " << points << "分\n";
    cout << "\n";
    cout << "時間共花了 : " << min << "秒\n";
    cout << "\n";
}

void LookPoints() {
    int many = 1 ;
    for (int i = 0 ; i < point.size() ; i++) {    //印出分數
        if (point[i] != 0) {
            cout << "第" << many << "次得分 : " << point[i] << "\n";
            many++;
        }
    }
}
