// ��T�G��10327125���x޳ 
# include<iostream>
# include<fstream> 
# include<ctime>
# include<cstdlib>
# include<string>
using namespace std ;

class Sudoku {
  public:
    bool repeatColumn( int j, int k, int n ) ; // �C�@��O�_������ 
    bool repeatRow( int j, int k, int n ) ; // �C�@�C�O�_������   
    void put() ; //  �N���ƪ��Ʀr�ק� 
    void ex() ; //  �����D�� 
    void PrintEx() ; // �L�X�D�� 
};

int board[10][10]; // �ƿW��� 
int count = 0 ; // �p�ƾ� 
int num1 = 0, num2 = 0 ; //��Ʀ�m 

bool Sudoku::repeatColumn( int j, int k, int n ) { // �C�@��O�_������
	
  for ( int i = 0 ; i < 4 ; i++ ) {
  	  
  	if ( board[j][k] == board[i][n] && j != i ) { 
	  	
  	  return true;
  	} // if
  	    
  } // for
	
  return false;	
} // repeat---------------------------------------// �C�@��O�_������ 

bool Sudoku::repeatRow( int i, int k, int n ) { // �C�@�C�O�_������ 
	
  	
  for ( int j = 0 ; j < 4 ; j++ ) {
  	     
  	if ( board[i][k] == board[n][j] && k != j ) {
  	  
  	  return true;
    } // if
      
  } // for

  return false;	
} // repeat -------------------------------------// �C�@�C�O�_������  

void Sudoku::put() { // -----------------------------------------------------�N���ƪ��Ʀr�ק� 
  int k = 0 ;
  int numtmp[4] = {1,2,3,4} ;
  while ( board[0][0] == board[0][1] || board[0][0] == board[1][0] || board[0][0] == board[1][1] || repeatColumn(0,0,0) == true || repeatRow(0,0,0) == true && k < 4 ) {
  	
  	board[0][0] = numtmp[k] ;
  	if ( board[0][0] != board[0][1] && board[0][0] != board[1][0] && board[0][0] != board[1][1] && repeatColumn(0,0,0) == false && repeatRow(0,0,0) == false && k < 4 ) {
  	  k=4;
  	  
    } // if
    k++;
  } // while
  
  k = 0 ;
  while ( board[0][1] == board[0][0] || board[0][1] == board[1][0] || board[0][1] == board[1][1] || repeatColumn(0,1,1) == true || repeatRow(0,1,0) == true && k < 4 ) {
	  
  	board[0][1] = numtmp[k] ;
  	if( board[0][1] != board[0][0] && board[0][1] != board[1][0] && board[0][1] != board[1][1] && repeatColumn(0,1,1) == false && repeatRow(0,1,0) == false && k < 4 ) {
  	  k=4 ;
  	  
	} // if
  	
    k++ ;
  } // while
  
  k = 0 ;
  while ( board[1][0] == board[0][0] || board[1][0] == board[0][1] || board[1][0] == board[1][1] || repeatColumn(1,0,0) == true || repeatRow(1,0,1) == true && k < 4 ) {
	  
  	board[1][0] = numtmp[k] ;
  	if ( board[1][0] != board[0][0] && board[1][0] != board[0][1] && board[1][0] != board[1][1] && repeatColumn(1,0,0) == false && repeatRow(1,0,1) == false && k < 4 ) {
  	  k=4;
  	  cout << k ;
	} // if
  	k++;
    
  } // while
  
  k = 0 ;
  while ( board[1][1] == board[0][0] || board[0][0] == board[0][1] || board[0][0] == board[1][0] || repeatColumn(1,1,1) == true || repeatRow(1,1,1) == true && k < 4 ) {
  	
  	board[1][1] = numtmp[k] ;
  	if ( board[1][1] != board[0][0] && board[0][0] != board[0][1] && board[0][0] != board[1][0] && repeatColumn(1,1,1) == false && repeatRow(1,1,1) == false && k < 4 ) {
  	  k = 4 ;
	}
    k++;
    
  } // while
  
  k = 0 ;
  while ( board[0][2] == board[0][3] || board[0][2] == board[1][2] || board[0][2] == board[1][3] || repeatColumn(0,2,2) == true || repeatRow(0,2,0) == true && k < 4 ) {
  	  
  	board[0][2] = numtmp[k] ;
  	if ( board[0][2] != board[0][3] && board[0][2] != board[1][2] && board[0][2] != board[1][3] && repeatColumn(0,2,2) == false && repeatRow(0,2,0) == false && k < 4 ) {
  	  k = 4 ;
	}
  	k++;
    
  } // while
  
  k = 0 ;
  while ( board[0][3] == board[0][2] || board[0][3] == board[1][2] || board[0][3] == board[1][3] || repeatColumn(0,3,3) == true || repeatRow(0,3,0) == true && k < 4 ) {
  	
  	board[0][3] = numtmp[k] ;
  	if ( board[0][3] != board[0][2] && board[0][3] != board[1][2] && board[0][3] != board[1][3] && repeatColumn(0,3,3) == false && repeatRow(0,3,0) == false && k < 4 ) {
  	  k=4;
	}
  	k++;
    
  } // while
  
  while ( board[1][2] == board[0][2] || board[1][2] == board[0][3] || board[1][2] == board[1][3] || repeatColumn(1,2,2) == true || repeatRow(1,2,1) == true && k < 4 ) {
  	
  	board[1][2] = numtmp[k] ;
  	if ( board[1][2] != board[0][2] && board[1][2] != board[0][3] && board[1][2] != board[1][3] && repeatColumn(1,2,2) == false && repeatRow(1,2,1) == false && k < 4 ) {
  	  k=4;
	}
  	k++;
    
  } // while
  
  k = 0 ;
  while ( board[1][3] == board[0][2] || board[1][3] == board[0][3] || board[1][3] == board[1][2] || repeatColumn(1,3,3) == true || repeatRow(1,3,1) == true && k < 4 ) {
  	
  	board[1][3] = numtmp[k] ;
  	if ( board[1][3] != board[0][2] && board[1][3] != board[0][3] && board[1][3] != board[1][2] && repeatColumn(1,3,3) == false && repeatRow(1,3,1) == false && k < 4 ) {
  	  k=4;
	}
  	k++;
  
  } // while
  
  k = 0 ;
  while ( board[2][0] == board[2][1] || board[2][0] == board[3][0] || board[2][0] == board[3][1] || repeatColumn(2,0,0) == true || repeatRow(2,0,2) == true && k < 4 ) {
  	
  	board[2][0] = numtmp[k] ;
  	if ( board[2][0] != board[2][1] && board[2][0] != board[3][0] && board[2][0] != board[3][1] && repeatColumn(2,0,0) == false && repeatRow(2,0,2) == false && k < 4 ) {
      k=4;
	}
  	k++;
    
  } // while
  
  k = 0 ;
  while ( board[2][1] == board[2][0] || board[2][1] == board[3][0] || board[2][1] == board[3][1] || repeatColumn(2,1,1) == true || repeatRow(2,1,2) == true && k < 4 ) {
  
  	board[2][1] = numtmp[k] ;
  	if ( board[2][1] != board[2][0] && board[2][1] != board[3][0] && board[2][1] != board[3][1] && repeatColumn(2,1,1) == false && repeatRow(2,1,2) == false && k < 4 ) {
  	  k=4;
	}
  	k++;
    
  } // while
  
  k = 0 ;
  while ( board[3][0] == board[2][0] || board[3][0] == board[2][1] || board[3][0] == board[3][1] || repeatColumn(3,0,0) == true || repeatRow(3,0,3) == true && k < 4 ) {
  	
  	board[3][0] = numtmp[k] ;
  	if ( board[3][0] != board[2][0] && board[3][0] != board[2][1] && board[3][0] != board[3][1] && repeatColumn(3,0,0) == false && repeatRow(3,0,3) == false && k < 4 ) {
  	  k=4;
	}
  	k++;
  
  } // while
  
  k = 0 ;
  while ( board[3][1] == board[2][0] || board[3][1] == board[2][1] || board[3][1] == board[3][0] || repeatColumn(3,1,1) == true || repeatRow(3,1,3) == true && k < 4 ) {
  	
  	board[3][1] = numtmp[k] ;
  	if ( board[3][1] != board[2][0] && board[3][1] != board[2][1] && board[3][1] != board[3][0] && repeatColumn(3,1,1) == false && repeatRow(3,1,3) == false && k < 4 ) {
  	  k=4;
	} 
  	k++;
    
  } // while
  
  k = 0 ;
  while ( board[2][2] == board[2][3] || board[2][2] == board[3][2] || board[2][2] == board[3][3] || repeatColumn(2,2,2) == true || repeatRow(2,2,2) == true && k < 4 ) {
  	
  	board[2][2] = numtmp[k] ;
  	if ( board[2][2] != board[2][3] && board[2][2] != board[3][2] && board[2][2] != board[3][3] && repeatColumn(2,2,2) == false && repeatRow(2,2,2) == false && k < 4 ) {
  	  k=4;
	}
  	k++;
    
  } // while
  
  k = 0 ;
  while ( board[2][3] == board[2][2] || board[2][3] == board[3][2] || board[2][3] == board[3][3] || repeatColumn(2,3,3) == true || repeatRow(2,3,2) == true && k < 4 ) {
  	
  	board[2][3] = numtmp[k] ;
  	if ( board[2][3] != board[2][2] && board[2][3] != board[3][2] && board[2][3] != board[3][3] && repeatColumn(2,3,3) == false && repeatRow(2,3,2) == false && k < 4 ) {
  	  k=4;
	}
  	k++;
   
  } // while
  
  k = 0 ;
  while ( board[3][2] == board[2][2] || board[3][2] == board[2][3] || board[3][2] == board[3][3] || repeatColumn(3,2,2) == true || repeatRow(3,2,3) == true && k < 4 ) {
  	
  	board[3][2] = numtmp[k] ;
  	if ( board[3][2] != board[2][2] && board[3][2] != board[2][3] && board[3][2] != board[3][3] && repeatColumn(3,2,2) == false && repeatRow(3,2,3) == false && k < 4 ) {
  	  k=4;
	}
  	k++;
    
  } // while
  
  k = 0 ;
  while ( board[3][3] == board[2][2] || board[3][3] == board[2][3] || board[3][3] == board[3][2] || repeatColumn(3,3,3) == true || repeatRow(3,3,3) == true && k < 4 ) {
	  
  	board[3][3] = numtmp[k] ;
  	if ( board[3][3] != board[2][2] && board[3][3] != board[2][3] && board[3][3] != board[3][2] && repeatColumn(3,3,3) == false && repeatRow(3,3,3) == false && k < 4 ) {
  	  k=4;
	}
  	k++;
    
  } // while
  
} // put()// -----------------------------------------------------------------�N���ƪ��Ʀr�ק�

void Sudoku::ex() { //---------------------------------------------------------�����D�� 
  int j = 0, tmp = 0;
  int numtmp[4] = {1,2,3,4} ;
  for ( int i = 0 ; i < 4 ; i++ ) {  
    j = rand() % 4 ;
    tmp = numtmp[i];
    numtmp[i] = numtmp[j];
    numtmp[j] = tmp ;

  } // for
   
  for ( int k = 0 ; k < 4 ; k++ ) {
  	
  	board[num1][num2] = numtmp[k] ;
    num2++ ;
    
  	if ( ( k + 1 ) % 4 == 0 && count < 3 ) {
  	  num1++ ;
  	  num2 = 0 ;
  	  count++;
  	  ex() ;
	} // if
	
  } // for
  
  count = 0 ;
  num1 = 0 ;
  num2 = 0 ;     
} // ex    ---------------------------------------------------------------�����D��



void Sudoku::PrintEx() { // ------------------------------------------------�L�X�ƿW 
  
  for ( int j = 0 ; j < 4 ; j++ ) {
  	if ( board[num1][j] > 4 || board[num1][j] < 1 ) {
  	  
  	  cout << "? " ;
	}
	else {
	  cout << board[num1][j] << " " ;
	}
    
       
    if ( ( j + 1 ) % 4 == 0 && count < 3 ) {
      cout << endl ; 	  
      num1++ ;
      count++ ;
      PrintEx() ;
    } // if
	  
  } // for
    
  num1 = 0 ;
  count = 0 ;
} // PrintEx // -----------------------------------------------------�L�X�ƿW 

void Play1() { // ------------------------------------------------------------ �m�� 
  Sudoku check ;	
  check.ex() ;
  check.put() ;
  check.PrintEx();

	
} // Play1 --------------------------------------------------------------------�m�� 

int Play2() {  //-------------------------------------------------------------���� 
  clock_t start, stop;	
  Sudoku check ;
  srand(time(NULL));
  start = clock(); //�}�l�ɶ�	
  fstream file ;
  file.open( "point.txt", ios::out ) ;
  check.ex() ;
  check.put() ;
  check.PrintEx();
  
  stop = clock(); //�����ɶ�
  
  if ( ! file ) {
    cout << "�ɮ׵L�k�}��" ;   	
  } // if
  
  else {
  	file << double(stop - start) / CLOCKS_PER_SEC ;
  	cout << endl ;
    cout << "���Z : " ;
    cout << double(stop - start) / CLOCKS_PER_SEC << "��\n" ; // ���Z 
  } // else  
  

  return double(stop - start) / CLOCKS_PER_SEC ;
} // Play2  ---------------------------------------------------------------------���� 

void Play3() {  //   -----------------------------------------------------------------�[�ݱo�� 
	
  fstream file ;
  char data[99] ;
  file.open( "point.txt", ios::in ) ;
  	
  if ( ! file ) {
    cout << "�ɮ׵L�k�}��" ;   	
  } // if
  
  else {
    file.read( data, sizeof( data ) ) ;
    cout << "�̪�@�����Z : " ; 
    cout << data << "��\n";  	
  } // else 
  	
} // Play3 --------------------------------------------------------------------------- �[�ݱo��  

int main() {
  fstream file ;
  char command ;
  //Sudoku check ;
  while ( command != 'Q' ) {  	
    
    cout << endl << "************* ���O��� ************";
    cout << endl << "* Q)uit. ����                     *";
    cout << endl << "* M)anage. �޲z                   *";
    cout << endl << "* P)lay. �C��                     *";
    cout << endl << "***********************************";
    cout << endl << "Input a command : " ;
    cin >> command;
    
    if ( command == 'M') {
      cout << endl << "0. �s�W�D��" ;
      cout << endl << "1. ����D��" ;
      cout << endl << "2. �R���D��" ;
      cout << endl << "3. ��^" ;
      cout << endl << "Input a command : " ;
      cin >> command ; 
	  if ( command == '0' ) {
	  	file.open( "test.txt", ios::out ) ;
        check.ex() ;
        check.put() ;
        file << board ; 
	  } // if
	  
	  else if ( command == '1' ) {
	  	check.PrintEx();
	  } // else if
	} // if
	
	else if ( command == 'P') {
	 
      cout << endl << "0. �m��" ;
      cout << endl << "1. �}�l����" ;
      cout << endl << "2. �[�ݱo��" ;
      cout << endl << "3. ��^" ;
      cout << endl << "Input a command : " ;
      cin >> command ;  
	  if ( command == '0' ) {
	  	Play1() ;
        
	  }	// if

	  else if ( command == '1' ) {
	    Play2();
	    
	  } // else if ( command=1 )
	  
	  else if ( command == '2' ) {
	    Play3() ;
 	      
	  } // else if ( command=2 )
	  
	  
	} // else if ( command == 'P')
	
  } // while
  
  	
} // main()
