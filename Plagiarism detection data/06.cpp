/*��Ƶ��c�ĤG���@�~
    10327217 ��T�G�A �����m
    10327234 ��T�G�A ���廷
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

Game total;          // total���s��F�Ҧ����ͪ��D��
Game thepractice ;   // thepractice���s��F�m���D

int main() {
  srand (time(NULL));
  int i = 0, a = 0, b = 0 ;
  char first ;
  while ( first != '1' ) {
    printf( "~~~~~~~~~~~~~~~~~~~���O���~~~~~~~~~~~~~~~~~~~\n" ) ;
    printf( " 1.Quit.����    2.Manage.�޲z    3.Play.�C��  \n" ) ;
    printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ) ;
    printf( "�п�J�Ʊ���檺���O :" ) ;
    cin>>first ;

    if ( first != '2' && first != '3' )
      printf( "�Ы����@�����}\n" ) ;

    if ( first == '2' ) {
      Manage() ;
    } // if

    if ( first == '3' ) {
      Play() ;
    } // if

  } // while

  return 0;

} // main()

//--------------------------------------------------------------------------�H�U��"�޲z"���Ҧ�function

void Manage() {
  char second ;
  printf( "~~~~~~~~~~~~~~~~~~~���O���~~~~~~~~~~~~~~~~~~~\n" ) ;
  printf( "    0.�s�W�D��    1.����D��    2.�R���D��    \n" ) ;
  printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ) ;
  printf( "�п�J�Ʊ���檺���O :" ) ;
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
    num = ( rand() % 4 ) + 1 ;    // �H�����ͤ@��1~4�����
    find = 0 ;
    for( i = 0; i < cnt; i++ ) {
      if( player[i] == num ) {    // ��ܵo�{�즳���ƪ��Ʀr
        find = 1 ;
        break ;                   // ���}�j�魫�s���ͼƦr
      } // if
    }
    if( find == 0 ) {             // ��ܨS�����ƪ��Ʀr
      player[cnt] = num ;         // �N�Ʀr�s�J
      cnt++ ;
    } // if
  }
} // Plus()

//-----------------------------------------------------�H�U�T��Change��function�O�ΨӱN�H���ͪ��ƿW�D�ث���

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
  while ( x == 5000 ) {                 // �o�Ӱj��O�ΨӧP�w���ƬO�_�����ƪ��Ʀr
    x = 0, i = 0 ;
    Plus( player1 ) ;
    Plus( player2 ) ;
    while ( i < 4 ) {
      if ( player1[i] == player2[i] ) {     // �C�@���Ƴ��������@�ˡA�Y���@�˪��h���s����
        Plus( player2 ) ;
        i = 0 ;
      } // if

      i++ ;
      x++ ;               // x�O�ΨӬ������ͪ����ơA�Y�W�L5000���h���s���͡A����{���]�Ӥ[
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

//------------------------------------------------------------------�H�U�O�ΨӧP�w�ƿW���|�Ӱ϶��O�_�����ƪ��Ʀr

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

  if ( practice == 1 )                                    // ��prctice��1���ɭԪ�ܥ��brun�m���D��function
    Prg( player1, player2, player3, player4  ) ;
  else                                                    // ���O1���ɭԴN�N�D����ܥX�Өæs��
    Save( player1, player2, player3, player4 ) ;

} // Add()

void Save( int* player1, int* player2, int* player3, int* player4  ) {
  int i = 0, k = 0, l = 0 ;
  i = 0 ;

//-------------------------------------------------�H�U�|��for�j��O�ΨӱN�D�ئs�Jtotal��

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

  l = ( rand()%3 ) + 1 ;           // �H����ܤ@�ث��Ūk
  if ( l == 1 )
    Change() ;
  if ( l == 2 )
    Change1() ;
  if ( l == 3 )
    Change2() ;

//----------------------------------------------------------------------�H�U�O�ΨӱN�D�ئL�X��

  i = 0 ;
  printf( "��������������\n" ) ;
  while ( i < 16 ) {
    if ( i % 4 == 0 )
      printf( "��" ) ;

    if ( total.thegame[m][i] == 0 )
      printf( " " ) ;
    else
      printf( "%d", total.thegame[m][i] ) ;


    if( i == 1 || i == 5 || i == 9 || i == 13 )
      printf( "��" ) ;
    if ( i == 0 || i == 4 || i == 8 || i == 12 || i ==2 || i == 6 || i == 10 || i == 14 )
      printf( "��" ) ;
    if ( i == 3 || i == 7 || i == 11 || i == 15 )
      printf( "��\n" ) ;
    if ( i == 3 || i == 11 )
      printf( "��������������\n" ) ;

    if ( i == 7 )
      printf( "��������������\n" ) ;

    i++ ;
  } // while
  printf( "��������������\n" ) ;

// ------------------------------------------------------------------�H�U�N�D�ئs�JGame.txt

  i = 0 ;
  if ( p == 1 )
    fp.open( gamename, ios::out|ios::trunc ) ;
  else
    fp.open( gamename, ios::out|ios::app ) ;
  fp<<"��"<<m+1<<"�����:"<<endl ;
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
    printf( "�п�J�Q�ݪ��D��,�ο�J0���}\n" ) ;
    printf( "�D��:") ;
    scanf( "%d", &j ) ;
    if ( j == 0 )
      break ;
    j = j - 1 ;
    printf( "��������������\n" ) ;
    while ( i < 16 ) {
      if ( i % 4 == 0 )
        printf( "��" ) ;

      if ( total.thegame[j][i] == 0 )
        printf( " " ) ;
      else
        printf( "%d", total.thegame[j][i] ) ;

      if( i == 1 || i == 5 || i == 9 || i == 13 )
        printf( "��" ) ;
      if ( i == 0 || i == 4 || i == 8 || i == 12 || i ==2 || i == 6 || i == 10 || i == 14 )
        printf( "��" ) ;
      if ( i == 3 || i == 7 || i == 11 || i == 15 )
        printf( "��\n" ) ;
      if ( i == 3 || i == 11 )
       printf( "��������������\n" ) ;

      if ( i == 7 )
        printf( "��������������\n" ) ;

      i++ ;
    } // while

    printf( "��������������\n" ) ;
  } // while
} // View()


void Delete() {
  int i = 0, j = 0 ;
  while ( j != 5000 ) {
  printf( "�п�J�Ʊ�R�����D�ءA�ο�J0���}\n" ) ;
  printf( "�D��:" ) ;
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
  printf( "�w�M������\n" ) ;
  printf( "\n" ) ;

  } // while
} // Delete()

//--------------------------------------------------------------------------�H�U��"�C��"���Ҧ�function

void Play() {
  printf( "~~~~~~~~~~~~~~~~~~~���O���~~~~~~~~~~~~~~~~~~~\n" ) ;
  printf( "     0.�m��    1.�}�l����    2.�[�ݱo��       \n" ) ;
  printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ) ;
  char third ;
  printf( "�п�J�Ʊ���檺���O:" ) ;
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
  Add( ) ;                     // ���ͽm���D
} // Practice()

void Prg( int* player1, int* player2, int* player3, int* player4  ) {
  int i = 0, k = 0, l = 0 ;
  int game3[16] ;
  i = 0 ;

//---------------------------------------------------------------�H�U�O�ΨӱN�m���D�s�Jthepractice

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
      Game2( game3 ) ;                       // �i�J�C��
    } // if
    i++ ;
  } // while

  practice = 0 ;

} // Prg()

void Prc() {                                     // �o��function�O�ΨӱN�m���D���Ū�
  int i = 0 ;
  while( i < 16 ) {
    if ( i == 0 || i == 3 || i == 4 || i == 5 || i == 9 || i == 10 || i == 14 || i == 15 )
      thepractice.thegame[0][i] = 0 ;
    i++ ;
  } // while

} // Prc()

//---------------------------------------------------------------------------------------------

void Game2( int* game3 ) {                          // �o��function�O�ΨӰ���C����
  bool y = false ;
  int i = 0 ;
  int x = 1 ;
  int game4[16] ;
  for ( int s = 0 ; s < 16 ; s++ )
    game4[s] = game3[s] ;                           // �ƻs�@�Ӥ@�Ҥ@�˪��D�ءA�����ɥγo�Ӱ}�C���٭��D��

//------------------------------------------------------------------------------�H�U�O�ΨӦL�X�D�ت�

  printf( "��������������\n" ) ;
  while ( i < 16 ) {
    if ( i % 4 == 0 )
      printf( "��" ) ;

    if ( game3[i] == 0 )
      printf( " " ) ;
    else
      printf( "%d", game3[i] ) ;

    if( i == 1 || i == 5 || i == 9 || i == 13 )
      printf( "��" ) ;
    if ( i == 0 || i == 4 || i == 8 || i == 12 || i ==2 || i == 6 || i == 10 || i == 14 )
      printf( "��" ) ;
    if ( i == 3 || i == 7 || i == 11 || i == 15 )
      printf( "��\n" ) ;
    if ( i == 3 || i == 11 )
      printf( "��������������\n" ) ;

    if ( i == 7 )
      printf( "��������������\n" ) ;

    i++ ;
  } // while
  printf( "��������������\n" ) ;

  i = 0 ;
  while ( y == false ) {
    while ( i < 16 ) {                       // �o��while�j��O�ΨӱN���פ@��@���J
      if( game3[i] == 0 ) {
        printf( "�п�J��" ) ;
        printf( "%d", x ) ;
        printf( "�浪��:" ) ;
        cin>>game3[i] ;
        x++ ;
      } // if

      i++ ;
    } // while

    if ( Answer( game3 ) == true ) {              // �Y���׬O�諸�A�K�Ny�]��true�Ӹ��X�j��
      y = true ;
      printf( "���ߵ���\n" ) ;
    } // if
    else {
      printf( "�����F!!!���~��V�O\n" ) ;          // �Y�O�����A�K�N�D�ث�_���~��j��
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
  start1 = clock();            // �}�l�p��
  while ( f < m ) {            // �@�D�@�D�N�D�ؿ�J����C����function
    if ( i == 0 ) {
      printf( "\n" ) ;
      printf( "��" ) ;
      printf( "%d", x ) ;
      printf( "�D:\n" ) ;
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

  stop1 = clock();            // ����p��

} // Go()

bool Answer( int* game2 ) {                              // �o��function�O�Ψ��˴����׬O�_���T��
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

  if ( t == 10 && t1 == 10 && t2 == 10 && t3 == 10 && t4 == 10 && t5 == 10 && t6 == 10 && t7 == 10 )  // ��ܩҦ����ƾ�ƥ[�_�ӳ��O10
    return true ;
  else
    return false ;

} // Answer()

void Look() {                                     // �L�X�������`���
  printf( "�����`�@��O:" ) ;
  cout << double(stop1 - start1) / CLOCKS_PER_SEC ;
  printf( "��\n" ) ;
} // Look()



