/*資料結構第二次作業
    10327217 資訊二乙 陳易煒
    10327234 資訊二乙 陳文遠
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#define size 16
using namespace std;
void Add() ;
void Manage() ;
void View() ;
void Change() ;
void Change1() ;
void Change2() ;
void Plus( int* ) ;
void Save( int*, int*, int*, int* ) ;
void Delete() ;
void Play() ;
void Prc() ;
void Practice() ;
void Go() ;
void Prg( int*, int*, int*, int* ) ;
void Game2( int* ) ;
void Look() ;
bool Answer( int* ) ;
fstream fp ;
char gamename[]= "Game.txt" ;
int m = 0, p = 1, practice = 0 ;
clock_t start1, stop1 ;

class Game{
  public:
    int thegame[20][16];
} ;

Game total;          // total內存放了所有產生的題目
Game thepractice ;   // thepractice內存放了練習題

int main() {
  srand (time(NULL));
  int i = 0, a = 0, b = 0 ;
  char first ;
  while ( first != '1' ) {
    printf( "~~~~~~~~~~~~~~~~~~~指令選單~~~~~~~~~~~~~~~~~~~\n" ) ;
    printf( " 1.Quit.結束    2.Manage.管理    3.Play.遊戲  \n" ) ;
    printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ) ;
    printf( "請輸入希望執行的指令 :" ) ;
    cin>>first ;

    if ( first != '2' && first != '3' )
      printf( "請按任一鍵離開\n" ) ;

    if ( first == '2' ) {
      Manage() ;
    } // if

    if ( first == '3' ) {
      Play() ;
    } // if

  } // while

  return 0;

} // main()

//--------------------------------------------------------------------------以下為"管理"的所有function

void Manage() {
  char second ;
  printf( "~~~~~~~~~~~~~~~~~~~指令選單~~~~~~~~~~~~~~~~~~~\n" ) ;
  printf( "    0.新增題型    1.顯示題型    2.刪除題型    \n" ) ;
  printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ) ;
  printf( "請輸入希望執行的指令 :" ) ;
  cin>>second ;

  if ( second == '0' ) {
    Add() ;
  } // if

  if ( second == '1' ) {
    View() ;
  } // if

  if ( second == '2' ) {
    Delete() ;
  } // if

} // Manage()

void Plus( int* player ) {
  int n = 4 ;
  int i, cnt, num ;
  int find ;
  cnt = 0 ;
  while ( cnt < n ) {
    num = ( rand() % 4 ) + 1 ;    // 隨機產生一個1~4的整數
    find = 0 ;
    for( i = 0; i < cnt; i++ ) {
      if( player[i] == num ) {    // 表示發現到有重複的數字
        find = 1 ;
        break ;                   // 離開迴圈重新產生數字
      } // if
    }
    if( find == 0 ) {             // 表示沒有重複的數字
      player[cnt] = num ;         // 將數字存入
      cnt++ ;
    } // if
  }
} // Plus()

//-----------------------------------------------------以下三個Change的function是用來將以產生的數獨題目挖空

void Change( ) {
  int i = 0 ;
  while( i < 16 ) {
    if ( i == 0 || i == 4 || i == 5 || i == 6 || i == 9 || i == 10 || i == 11 || i == 12 )
      total.thegame[m][i] = 0 ;
    i++ ;
  } // while
} // Change

void Change1( ) {
  int i = 0 ;
  while( i < 16 ) {
    if ( i == 1 || i == 3 || i == 4 || i == 7 || i == 8 || i == 10 || i == 15 || i == 12 )
      total.thegame[m][i] = 0 ;
    i++ ;
  } // while
} // Change1

void Change2( ) {
  int i = 0 ;
  while( i < 16 ) {
    if ( i == 0 || i == 3 || i == 4 || i == 5 || i == 9 || i == 10 || i == 14 || i == 15 )
      total.thegame[m][i] = 0 ;
    i++ ;
  } // while
} // Change2

void Add() {
  int i = 0, k = 0, l = 0 ;
  int x = 5000 ;
  int one = 0 ;
  int two = 0 ;
  int three = 0 ;
  int four = 0 ;
  int player1[4] ;
  int player2[4] ;
  int player3[4] ;
  int player4[4] ;
  while ( x == 5000 ) {                 // 這個迴圈是用來判定直排是否有重複的數字
    x = 0, i = 0 ;
    Plus( player1 ) ;
    Plus( player2 ) ;
    while ( i < 4 ) {
      if ( player1[i] == player2[i] ) {     // 每一直排都必須不一樣，若有一樣的則重新產生
        Plus( player2 ) ;
        i = 0 ;
      } // if

      i++ ;
      x++ ;               // x是用來紀錄產生的次數，若超過5000次則重新產生，防止程式跑太久
      if ( x == 5000 )
        break ;
    } // while

    Plus( player3 ) ;
    i = 0, x = 0 ;
    while ( i < 4 ) {
      if ( player3[i] == player2[i] || player3[i] == player1[i] ) {
        Plus( player3 ) ;
        i = 0 ;
      } // if

      i++ ;
      x++ ;
      if ( x == 5000 )
        break ;
    } // while

    Plus( player4 ) ;
    i = 0, x = 0 ;
    while ( i < 4 ) {
      if ( player4[i] == player3[i] || player4[i] == player2[i] || player4[i] == player1[i] ) {
        Plus( player4 ) ;
        i = 0 ;
      } // if

      i++ ;
      x++ ;
      if ( x == 5000 )
        break ;
    } // while

//------------------------------------------------------------------以下是用來判定數獨的四個區塊是否有重複的數字

    one = player1[0] + player2[0] + player1[1] + player2[1] ;
    two = player1[2] + player2[2] + player1[3] + player2[3] ;
    three = player1[0] + player2[0] + player1[1] + player2[1] ;
    four = player1[2] + player2[2] + player1[3] + player2[3] ;

    if ( one != 10 || two != 10 || three != 10 || four != 10 )
      x = 5000 ;
    if ( player1[0] == player2[1] || player1[2] == player2[3] ||  player3[0] == player4[1] || player3[2] == player4[3] )
      x = 5000 ;
    if ( x != 5000 )
      break ;

  } // while

  if ( practice == 1 )                                    // 當prctice為1的時候表示正在run練習題的function
    Prg( player1, player2, player3, player4  ) ;
  else                                                    // 不是1的時候就將題目顯示出來並存檔
    Save( player1, player2, player3, player4 ) ;

} // Add()

void Save( int* player1, int* player2, int* player3, int* player4  ) {
  int i = 0, k = 0, l = 0 ;
  i = 0 ;

//-------------------------------------------------以下四個for迴圈是用來將題目存入total內

  for ( k = 0 ; k < 4 ; k++ ) {
    total.thegame[m][i] = player1[k] ;
    i++;
  }
  for ( k = 0 ; k < 4 ; k++ ) {
    total.thegame[m][i] = player2[k] ;
    i++ ;
  }
  for ( k = 0 ; k < 4 ; k++ ) {
    total.thegame[m][i] = player3[k] ;
    i++ ;
  }
  for ( k = 0 ; k < 4 ; k++ ) {
    total.thegame[m][i] = player4[k] ;
    i++ ;
  }

  l = ( rand()%3 ) + 1 ;           // 隨機選擇一種挖空法
  if ( l == 1 )
    Change() ;
  if ( l == 2 )
    Change1() ;
  if ( l == 3 )
    Change2() ;

//----------------------------------------------------------------------以下是用來將題目印出來

  i = 0 ;
  printf( "╔══╦══╗\n" ) ;
  while ( i < 16 ) {
    if ( i % 4 == 0 )
      printf( "║" ) ;

    if ( total.thegame[m][i] == 0 )
      printf( " " ) ;
    else
      printf( "%d", total.thegame[m][i] ) ;


    if( i == 1 || i == 5 || i == 9 || i == 13 )
      printf( "║" ) ;
    if ( i == 0 || i == 4 || i == 8 || i == 12 || i ==2 || i == 6 || i == 10 || i == 14 )
      printf( "║" ) ;
    if ( i == 3 || i == 7 || i == 11 || i == 15 )
      printf( "║\n" ) ;
    if ( i == 3 || i == 11 )
      printf( "╠══╬══╣\n" ) ;

    if ( i == 7 )
      printf( "╠══╬══╣\n" ) ;

    i++ ;
  } // while
  printf( "╚══╩══╝\n" ) ;

// ------------------------------------------------------------------以下將題目存入Game.txt

  i = 0 ;
  if ( p == 1 )
    fp.open( gamename, ios::out|ios::trunc ) ;
  else
    fp.open( gamename, ios::out|ios::app ) ;
  fp<<"第"<<m+1<<"筆資料:"<<endl ;
  while ( i < 16 ) {
    fp<<total.thegame[m][i]<<" " ;
    if ( i == 3 || i == 7 || i == 11 || i == 15 )
      fp<<endl ;
    i++ ;
  }
  fp.close();

  m++ ;
  p++ ;
} // Save()


void View() {
  int i = 0, j = 0, k = 0 ;
  while ( j != 5000 ) {
    i = 0 ;
    printf( "請輸入想看的題目,或輸入0離開\n" ) ;
    printf( "題目:") ;
    scanf( "%d", &j ) ;
    if ( j == 0 )
      break ;
    j = j - 1 ;
    printf( "╔══╦══╗\n" ) ;
    while ( i < 16 ) {
      if ( i % 4 == 0 )
        printf( "║" ) ;

      if ( total.thegame[j][i] == 0 )
        printf( " " ) ;
      else
        printf( "%d", total.thegame[j][i] ) ;

      if( i == 1 || i == 5 || i == 9 || i == 13 )
        printf( "║" ) ;
      if ( i == 0 || i == 4 || i == 8 || i == 12 || i ==2 || i == 6 || i == 10 || i == 14 )
        printf( "║" ) ;
      if ( i == 3 || i == 7 || i == 11 || i == 15 )
        printf( "║\n" ) ;
      if ( i == 3 || i == 11 )
       printf( "╠══╬══╣\n" ) ;

      if ( i == 7 )
        printf( "╠══╬══╣\n" ) ;

      i++ ;
    } // while

    printf( "╚══╩══╝\n" ) ;
  } // while
} // View()


void Delete() {
  int i = 0, j = 0 ;
  while ( j != 5000 ) {
  printf( "請輸入希望刪除的題目，或輸入0離開\n" ) ;
  printf( "題目:" ) ;
  scanf( "%d", &j ) ;
  if ( j == 0 )
    break ;
  j = j - 1 ;
  while ( i < 16 ) {
    total.thegame[j][i] = 0 ;
    i++ ;
  } // while

  printf( "\n" ) ;
  printf( "\n" ) ;
  printf( "已清除完成\n" ) ;
  printf( "\n" ) ;

  } // while
} // Delete()

//--------------------------------------------------------------------------以下為"遊戲"的所有function

void Play() {
  printf( "~~~~~~~~~~~~~~~~~~~指令選單~~~~~~~~~~~~~~~~~~~\n" ) ;
  printf( "     0.練習    1.開始闖關    2.觀看得分       \n" ) ;
  printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ) ;
  char third ;
  printf( "請輸入希望執行的指令:" ) ;
  cin>>third ;
  if ( third == '0' ) {
    Practice() ;
  } // if

  if ( third == '1' ) {
    Go() ;
  } // if

  if ( third == '2' ) {
    Look() ;
  } // if

} // Play()

void Practice() {
  practice = 1 ;
  Add( ) ;                     // 產生練習題
} // Practice()

void Prg( int* player1, int* player2, int* player3, int* player4  ) {
  int i = 0, k = 0, l = 0 ;
  int game3[16] ;
  i = 0 ;

//---------------------------------------------------------------以下是用來將練習題存入thepractice

  for ( k = 0 ; k < 4 ; k++ ) {
    thepractice.thegame[0][i] = player1[k] ;
    i++;
  }
  for ( k = 0 ; k < 4 ; k++ ) {
    thepractice.thegame[0][i] = player2[k] ;
    i++ ;
  }
  for ( k = 0 ; k < 4 ; k++ ) {
    thepractice.thegame[0][i] = player3[k] ;
    i++ ;
  }
  for ( k = 0 ; k < 4 ; k++ ) {
    thepractice.thegame[0][i] = player4[k] ;
    i++ ;
  }
  l = ( rand()%3 ) + 1 ;
  Prc( ) ;

  i = 0 ;
  while ( i < 16 ) {
    game3[i] = thepractice.thegame[0][i] ;
    if ( i == 15 ) {
      Game2( game3 ) ;                       // 進入遊戲
    } // if
    i++ ;
  } // while

  practice = 0 ;

} // Prg()

void Prc() {                                     // 這個function是用來將練習題挖空的
  int i = 0 ;
  while( i < 16 ) {
    if ( i == 0 || i == 3 || i == 4 || i == 5 || i == 9 || i == 10 || i == 14 || i == 15 )
      thepractice.thegame[0][i] = 0 ;
    i++ ;
  } // while

} // Prc()

//---------------------------------------------------------------------------------------------

void Game2( int* game3 ) {                          // 這個function是用來執行遊戲的
  bool y = false ;
  int i = 0 ;
  int x = 1 ;
  int game4[16] ;
  for ( int s = 0 ; s < 16 ; s++ )
    game4[s] = game3[s] ;                           // 複製一個一模一樣的題目，答錯時用這個陣列來還原題目

//------------------------------------------------------------------------------以下是用來印出題目的

  printf( "╔══╦══╗\n" ) ;
  while ( i < 16 ) {
    if ( i % 4 == 0 )
      printf( "║" ) ;

    if ( game3[i] == 0 )
      printf( " " ) ;
    else
      printf( "%d", game3[i] ) ;

    if( i == 1 || i == 5 || i == 9 || i == 13 )
      printf( "║" ) ;
    if ( i == 0 || i == 4 || i == 8 || i == 12 || i ==2 || i == 6 || i == 10 || i == 14 )
      printf( "║" ) ;
    if ( i == 3 || i == 7 || i == 11 || i == 15 )
      printf( "║\n" ) ;
    if ( i == 3 || i == 11 )
      printf( "╠══╬══╣\n" ) ;

    if ( i == 7 )
      printf( "╠══╬══╣\n" ) ;

    i++ ;
  } // while
  printf( "╚══╩══╝\n" ) ;

  i = 0 ;
  while ( y == false ) {
    while ( i < 16 ) {                       // 這個while迴圈是用來將答案一格一格輸入
      if( game3[i] == 0 ) {
        printf( "請輸入第" ) ;
        printf( "%d", x ) ;
        printf( "格答案:" ) ;
        cin>>game3[i] ;
        x++ ;
      } // if

      i++ ;
    } // while

    if ( Answer( game3 ) == true ) {              // 若答案是對的，便將y設為true來跳出迴圈
      y = true ;
      printf( "恭喜答對\n" ) ;
    } // if
    else {
      printf( "答錯了!!!請繼續努力\n" ) ;          // 若是錯的，便將題目恢復並繼續迴圈
      i = 0 ;
      x = 1 ;
      for ( int w = 0 ; w < 16 ; w++ )
        game3[w] = game4[w] ;
    } // else

  } // while
} // Game2()


void Go() {
  int i = 0 ;
  int x = 1 ;
  int y = 0 ;
  int f = 0 ;
  int game3[ 16 ] ;
  start1 = clock();            // 開始計時
  while ( f < m ) {            // 一題一題將題目輸入執行遊戲的function
    if ( i == 0 ) {
      printf( "\n" ) ;
      printf( "第" ) ;
      printf( "%d", x ) ;
      printf( "題:\n" ) ;
      x++ ;
    } // if

    game3[y] = total.thegame[f][i] ;

    y++ ;
    i++ ;

    if ( i == 16 ) {
      Game2( game3 ) ;
      y = 0 ;
      i = 0 ;
      f++ ;
    } // if

  } // while

  stop1 = clock();            // 停止計時

} // Go()

bool Answer( int* game2 ) {                              // 這個function是用來檢測答案是否正確的
  int t = 0, t1 = 0, t2 = 0, t3 = 0 ;
  int t4 = 0, t5 = 0, t6 = 0, t7 = 0 ;
  t = game2[0] + game2[1] + game2[2] + game2[3] ;
  t1 = game2[5] + game2[6] + game2[7] + game2[4] ;
  t2 = game2[10] + game2[11] + game2[8] + game2[9] ;
  t3 = game2[15] + game2[14] + game2[13] + game2[12] ;
  t4 = game2[0] + game2[4] + game2[8] + game2[12] ;
  t5 = game2[1] + game2[5] + game2[9] + game2[13] ;
  t6 = game2[2] + game2[6] + game2[10] + game2[14] ;
  t7 = game2[3] + game2[7] + game2[11] + game2[15] ;

  if ( t == 10 && t1 == 10 && t2 == 10 && t3 == 10 && t4 == 10 && t5 == 10 && t6 == 10 && t7 == 10 )  // 表示所有直排橫排加起來都是10
    return true ;
  else
    return false ;

} // Answer()

void Look() {                                     // 印出闖關的總秒數
  printf( "闖關總共花費:" ) ;
  cout << double(stop1 - start1) / CLOCKS_PER_SEC ;
  printf( "秒\n" ) ;
} // Look()



