#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int board [ 4 ] [ 4 ];
int question [ 16 ] ;
int same = 0 ;
int total = 0 ;
char input = '\0' ;  

bool CheckLine ( int a, int b, int run ) { //檢查直行 
  for ( int i = 0 ; i < a ; i ++ ) {
  	if( run == board[i][b] )
  	  same ++ ;
  }
  
  if ( same == 0 )
    return true ;
  else {
    same = 0 ;
	return false ;	
  }
} ;

bool CheckSquare ( int a, int b, int run ) { //檢查4宮格 
  if ( a == 1 ) {
  	if ( b == 0 ){
  	  if ( run == board[0][1] ) return false ;
    }
    
    else if ( b == 1 ){
  	  if ( run == board[0][0] ) return false ;
    }
    
    else if ( b == 2 ){
  	  if ( run == board[0][3] ) return false ;
    }
    
    else if ( b == 3 ){
  	  if ( run == board[0][2] ) return false ;
    }
  }
  
  if ( a == 3 ) {
  	if ( b == 0 ) {
  	  if ( run == board[2][1] ) return false ;
    }
    
    else if ( b == 1 ) {
  	  if ( run == board[2][0] ) return false ;
    }
    
    else if ( b == 2 ) {
  	  if ( run == board[2][3] ) return false ;
    }
    
    else if ( b == 3 ) {
  	  if ( run == board[2][2] ) return false ;
    }
  }
  
  return true ;
} ;

AddQ() {
  int a = 0, b = 0 ;
  for ( int i = 0 ; i < 16 ; i ++ ) {
    question[i] = board[a][b] ;
    b ++ ;
    if ( a < 2 && b == 3 ) {
      a ++ ;
      b = 0 ;
	}
  }
}

Create( int a, int b, int run ) { //新增題型 
  b = ( rand() % 4 ) ;
  if ( run < 5 ) {
    if ( board[a][b] == 0 && CheckLine( a, b ,run ) == true && CheckSquare ( a, b ,run ) == true ) {
      board[a][b] = run ;
      run ++ ;
      Create( a, b, run ) ;  
    }
    
    else 
      Create( a, b, run ) ;
  }
  
  else if ( a < 3 ) {
  	a ++ ;
  	Create( a, b, 1 ) ;
  }
  
  AddQ() ;
}

Ques ( int havedo, int i ) {
  if ( havedo < 4 ) {
  	i = ( rand() % 10 ) ;
	if ( question[i] != 0 ){
	  question[i] = 0 ;
	  havedo ++ ;
	} 
	
	Ques( havedo, 0 ) ;
  }
}

Pro1Print( int i ) {
  if ( question[i] == 0 )
    cout << " " ;
  else  
    cout << question[i] ;
  if ( i < 15 ) {
  	i ++ ;
  	if ( i % 4 == 0 && i != 0 )
  	  cout  << "\n" ;
    Pro1Print( i ) ;
  }
}

Delete() {
  for ( int i = 0 ; i < 16 ; i ++  )
    question[i] = 0 ;
}

int main() ;

int Project1() {
  while ( 1 ) {
    cout << "*******************************\n" ;
    cout << "0,新增題型\n"  ;
    cout << "1,顯示題型\n"  ;
    cout << "2,刪除題型\n"  ;
    cout << "B)ack,返回\n"  ;
    cout << "*******************************\n" ;
    srand( time(NULL) ) ;
    for ( int a = 0 ; a < 4 ; a ++ )
      for ( int b = 0 ; b < 4 ; b ++ )
        board[a][b] = 0 ;
    cin >> input ; 
    if ( input == '0' )
      Create( 0, 0, 1 ) ; // 新增題型 
    else if ( input == '1' )
      Pro1Print( 0 ) ;
    else if ( input == '2' )
      Delete( ) ;
    else if ( input == 'B' )
      return 0 ;
    for ( int a = 0 ; a < 4 ; a ++ ) {
      for ( int b = 0 ; b < 4 ; b ++ ) {
        if ( board[a][b] != 0 )
          cout << board[a][b] ;
        else
          cout << " " ;
      }    
      
	  cout << "\n" ;
    }
  }
}

int main() {
  cout << "10327137 吳佳旻, 10327149 李亮誼\n" ; 
  string _project ;
  while( 1 ) {
    cout << "*******************************\n" ;
    cout << "Q)uite,結束\n"  ;
    cout << "M)anage,管理\n" ;
    cout << "P)lay,遊戲\n" ;
    cout << "*******************************\n" ;
	cin >> _project ;
  	if ( _project == "M" ) 
  	  Project1() ;
    
    else if ( _project == "P" ) {
    }
    
    else  if ( _project == "Q" ) {
    	cout << "Bye！" << endl ;
    	break ;
    }
    
    else
        cout << "\nCommand does not exist！" ;
    cout << "\n\n\n" ; 
  }
  
  
}
