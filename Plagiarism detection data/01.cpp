#include<stdio.h>
#include <stdlib.h>
#include "windows.h" 
#include<iostream>
#include<fstream>
#include <time.h>

using namespace std ;

int count1 = 0, count2 = 0, saveloop = 1, xx = 0 ;  // �����o�F�F  // �� save ��"�O�@"���N�� 
int savecount = 1 ; // �D���ƶq ( �ĴX�� ) // �� save ��"�B�s"���N�� 

int k = 0 ; // ���L�s�W�D�� 

class Rank { // �ƦW  
    public :  
	int point = 0 ; // �o�� 
	int time = 0 ; // ��F�X�� 
	char name[100] ; // �W�r 
};

class Save {
    public :
	int play[50][50] ; 
};

Save save[50] ;

class Answer {
	public :
	char i = '\0' ; // ��
	char j = '\0' ; // �C
	char answer = '\0' ; // ���� 
};
/* 
bool Space( int play[50][50], int number ) {
                                 // number = 4
    int a = 0 ;                            
                                
	for ( int j = 0 ; j < number ; j++ ) {
		for ( int i = 0 ; i < number ; i++ ) {
			if ( play[i][j] == NULL  ) a++ ;
		}
	}
	
	if ( a == 0 ) return true ;
	else return false ;
}
*/ 
bool Inputerror( char input[100] ) {
	int a = 0 ;
	for ( int i = 0 ; i < strlen(input) ; i++ ) {
		if ( !isdigit( input[i] ) ) a++ ;
		if ( input[i] == ' ' ) a++ ;
		if ( input[i] == '\t' ) a++ ;
		if ( input[i] == '\n' ) a++ ;
	}
	
	if ( a == 0 ) return true ;
	else return false ;
}

bool Same( int i, int temp, int play[50][50], int j ) { // ���঳���ƪ� 
	int a = 0 ; // ���L��                                 // i ���ثe�O�ĴX�� 
	                                                      // j ���ثe�O�ĴX�C 
	if ( j == 0 ) { // �p�G�O�� 1 �C 
		for ( int x = 0 ; x < i ; x++ ) {  // �ˬd �� ���S���@��   
			if ( temp == play[x][j] ) a++ ;
		}
	}
	else { // ���O�� 1 �C 
	    
        for ( int k = j ; k > 0 ; k-- ) { // �ˬd �C ���S���@�� 
        	if ( temp == play[i][k-1] ) a++ ;
        }
		for ( int x = 0 ; x < i ; x++ ) {    // �ˬd �� ���S���@��  
			if ( temp == play[x][j] ) a++ ;
		}
		
		if ( j % 2 == 1 ) { // �O���ƦC �q0�}�l
		
		    if ( i % 2 == 0 && j % 2 == 1 ) {  //  ����_�C  // �ˬd �خ� ���S���@�� ( �� 4 X 4 �ϥ� ) 
		       if ( temp == play[i+1][j-1] ) a++ ;
            } 
		    if ( i % 2 == 1 && j % 2 == 1 ) {  // ���永�C  // �ˬd �خ� ���S���@�� ( �� 4 X 4 �ϥ� ) 
		       if ( temp == play[i-1][j-1] ) a++ ;
		    } 
		}
	 	
	}
	
	if ( a == 0 ) return true ; // �S���ƪ� 
	else return false ; // �����ƪ� 
} 

void Game( int play[50][50], int number ) {
	int space1 = 0, space2 = 0, i = 0, j = 0 ;
	
	srand((unsigned)GetCurrentTime()); // �[�o�Ӥ~�O�u���H�� ���Y�� "windows.h"  
	int a = 1 + rand() % number ; // ���� 1 ~ number ���ü� 
	
	
	play[i][j] = 1 + rand() % number ;
	
	for ( j = 0 ; j < number ; j++ ) {
		xx = 0 ; // �� break ���O��_����l�� 
		
		for ( i = 0 ; i < number ; i++ ) {
			
			int temp = 0 ;
			temp = 1 + rand() % number ;
			
			while ( !Same( i, temp, play, j ) ) {
				temp = 1 + rand() % number ;
				count1++ ; // count ���p���F�X�� 
				
				if ( count1 > 1000 ) { // �U�@ �@���䤣�쥿�T���� o9i
				    if ( saveloop == 5 ) { // ����Ʈ� ( �Ʀr�W�L 4 ) 
				    	xx = 1 ; // break ���ܼ� 
				    	break ;
				    } 
					temp = saveloop ; // �j�����Ʀr���� 1 2 3 4 �䤤�@�� 
					saveloop++ ;
				}
			
			}
			
			if( xx == 1 ) { // ����Ʈ� while�j�� break �F �A break for�j�� 
				j-- ;  // ���]�o�@�C 
				break ;  
			}
			
			count1 = 0 ; 
			saveloop = 1 ;
			play[i][j] = temp ;
		    
		}
			
	}
	
	for ( int yy = 0 ; yy < 5 ; yy++ ) { // ���� 
		space1 = rand() % number  ; // 0 ~ ( 4 - 1 ) ���ü� 
		space2 = rand() % number  ;
		while ( play[space1][space2] == NULL ) {
			space1 = rand() % number  ;
		    space2 = rand() % number  ;
		    count2++ ;
		    if ( count2 > 1000 ) break ;
		}
		play[space1][space2] = NULL ;
	}
	
}

bool Check( int play[50][50] ) { // �P�_���S������ 
	int a = 0 ;
	
	for ( int j = 0 ; j < 4 ; j++ ) {
		for ( int i = 0 ; i < 3 ; i++ ) // �P�_�@�C�@�C���S�����ƨ� 
			if ( play[i][j] == play[i+1][j] ) 
				a++ ;	
		if ( play[0][j] == play[2][j] ) a++ ;
		if ( play[1][j] == play[3][j] ) a++ ;		
	}
	
	for ( int i = 0 ; i < 4 ; i++ ) {
		for ( int j = 0 ; j < 3 ; j++ ) // �P�_�@��@�榳�S�����ƨ� 
			if ( play[i][j] == play[i][j+1] ) 
				a++ ; 		 
		if ( play[i][0] == play[i][2] ) a++ ;
		if ( play[i][1] == play[i][3] ) a++ ;		    	
	}
	
	if ( play[0][0] == play[1][1] || play[2][0] == play[3][0] || play[0][2] == play[1][3]
	     || play[2][2] == play[3][3] ) 
	     	a++ ;	     
	
	for ( int x = 0 ; x < 4 ; x++ ) { // �U�@���O 0 �� 
		for ( int y = 0 ; y < 4 ; y++ ) {
			if ( play[x][y] == 0 ) a++ ;
		}
	}   
	   
	   
    if ( a == 0 ) return true ; // �S�� 
    else return false ;
}

bool TrueorFalse( Save practice, Answer saveanswer[50], int trash ) { // �P�_���ץ������T // trash�� 
	int inti = 0, intj = 0, intanswer = 0 ; // int �� �� �C ����                             �X�յ���  
	
	for ( int  go = 1 ; go < trash ; go++ ) { // ���פ@�@��J �d�@�� 
		inti = saveanswer[go].i - '0' ; // char �� int 
		intj = saveanswer[go].j - '0' ; // char �� int
		intanswer = saveanswer[go].answer - '0' ; // char �� int
		inti-- ; // Game() �̭� i �O�q 0 �}�l�] 
		intj-- ; // Game() �̭� i �O�q 0 �}�l�] 
		
		practice.play[inti][intj] = intanswer ; // �⵪�ש���D�ظ� 
	}	
	
	if ( Check( practice.play ) ) return true ; // �S���ƪ� ( ����F ) 
	else return false ; // �����ƪ� ( �����F ) 

}

bool IsNull( int play[50][50], Answer saveanswer ) { // �ݶ�J����l�O���O�Ū� ( �O���O�i�H��J ) 
	int a = 0 ;
	int x = saveanswer.i - '0' ;
	int y = saveanswer.j - '0' ;
	
	if ( play[x-1][y-1] == 1 || play[x-1][y-1] == 2 || play[x-1][y-1] == 3
	     || play[x-1][y-1] == 4 || ( x > 4 || y > 4 ) || ( x < 1 || y < 1 ) ) // �p�G�O�Ʀr ( ���O�Ů� ) // �W�X�d�� 
        a++ ; 
	
	if ( a == 0 ) return true ; // �O�Ů� ( �i�H�� )
	else return false ;  // ����� 
}

void Order1( int number ) { // ���O 1 ( �i�J�޲z���O )
	char order1[100] = {""} ; // ���O 
	k = 0 ;
	
	FILE *fp ;
	FILE *newfp ;
	
	cout << "-------------------------" << "\n" ;
    cout << "��J1 �s�W�D��" << "\n" << "��J2 ����D��" << "\n" << "��J3 �R���D��" << "\n" ;
    cout << "��J0 �^��D�ؿ�" << "\n" ;
    cout << "-------------------------" << "\n" ;
    
    cin.getline( order1,100 ); // ��J���O
    	
    while ( strcmp( order1, "0" ) != 0 ) { // ��S���n�^��D�ؿ��ɡA�N�@������C 
    
		  if ( strcmp( order1, "1" ) == 0 ) {  // ���O 1 ( �s�W�D�� ) 
		  
		  	  fp = fopen("�ƿWHw.txt","a"); // �s�� 
    	
    		  fprintf( fp,"��" );
    		  if ( k == 0 )
    		    fprintf( fp,"%d", savecount ); // �s��( �ĴX�D ) 
    		  else {
    		  	savecount++ ;
    		  	fprintf( fp,"%d", savecount );
    		  }  
	    	  fprintf( fp,"�D\n\n" );
	    	  
	    	  Game( save[savecount].play, number ) ;
			    	
  			  for ( int j = 0 ; j < number ; j++ ) { // �s�� 
		      	  for ( int i = 0 ; i < number ; i++ ) {
		      	  	fprintf( fp,"%d",save[savecount].play[i][j] ); // �s��  
		      	  }
	    	  	  	    
          		  fprintf( fp,"\n" );
              }
   	          fclose(fp); // �����ɮ� 
   	          
   	          if ( savecount == 1 && k == 0 ) {
   	          	cout << "�w�s�W" << savecount << "�D�D��\n" ;
   	          	k++ ;
   	          } 
   	          else  {
   	          	//savecount++ ;
   	          	cout << "�w�s�W" << savecount << "�D�D��\n" ;
   	          }
   	            
   	          

		  }
		  else if ( strcmp( order1, "2" ) == 0 ) { // ���O2 ( ����D��  ) 
		  	  cout << "�аݭn��ܲĴX�D\n" ;
		  	
		  	  char showtopic[100] = {""} ;
		  	  cin.getline( showtopic,100 ); // ��J���O
    		  int intshowtopic = atoi( showtopic ) ; // �r���� int 
    		  
    		  if ( !Inputerror( showtopic ) ) {
    		  	while ( !Inputerror( showtopic ) ) { 
    		  	    cout << "��J���~�A�Э��s��J\n" ; // ��J���^��βŸ� 
			  		cin.getline( showtopic,100 ); // ��J���O
			  	}	
			  } 
    		  
    		  intshowtopic = atoi( showtopic ) ; // �r���� int
    		  
    		  if ( intshowtopic == 0 ) cout << "�S��0�D�աA�O�Ӷ�\n" ;    		  	
    		  else if ( intshowtopic > savecount || k == 0 ) cout << "�S�o��h�D�ءA�Э��s��J\n" ;
    		  else {      // �]�� savecount �|�h�[�@�� �ҥH�n savecount - 1  
    		  	   for ( int j = 0 ; j < number ; j++ ) { // �s�� 
		    	   	   for ( int i = 0 ; i < number ; i++ ) 
		    		   	   cout << save[intshowtopic].play[i][j] << " " ;
  			           cout << "\n" ;
                   }
    		  }
	      
		  }
		  else if ( strcmp( order1, "3" ) == 0 ) {  // ���O3 ( �R���D��  ) 
		      cout << "�аݭn�R���ĴX�D\n" ; 
		       
		  	  char deletetopic[100] = {""} ;
		  	  cin.getline( deletetopic,100 ); 
			  int intdeletetopic = atoi( deletetopic ) ; // �r���� int
			  
			  if ( !Inputerror( deletetopic ) ) {
			  	while ( !Inputerror( deletetopic ) ) { 
			  	    cout << "��J���~�A�Э��s��J\n" ; // ��J���^��βŸ�  
			  		cin.getline( deletetopic,100 ); 
			  	}  	
			  }
			  
			  intdeletetopic = atoi( deletetopic ) ; // �r���� int
			  
			  if ( intdeletetopic == 0 ) cout << "�S��0�D�աA�O�Ӷ�\n" ; 	
		  	  else if ( intdeletetopic > savecount || k == 0 ) cout << "�S�o��h�D�ءA�Э��s��J\n" ;
		  	  else {           // �]�� savecount �|�h�[�@�� �ҥH�n savecount - 1 
	             
             	 if ( intdeletetopic == savecount ) {  // �n�R���O�̫�@��
	                for ( int j = 0 ; j < number ; j++ ) { // ��̫�@���ܦ� NULL 
	                   for ( int i = 0 ; i < number ; i++ ) 
    		   	   		   save[intdeletetopic].play[i][j] = NULL ;
       			    }
		            savecount-- ;
     	          }
				  else { // �n�R�����O�̫�@�� 
				 	for ( int k = intdeletetopic ; k < savecount ; k++ ) {
				 		save[k] = save[k + 1] ; // ��쥻���ܦ���@�� 
				 	}
				 	for ( int j = 0 ; j < number ; j++ ) { // ��̫�@���ܦ� NULL
	                   for ( int i = 0 ; i < number ; i++ ) 
    		   	   		   save[savecount].play[i][j] = NULL ;
       			    }
				 	savecount-- ;
				  } 
			  
				  //savecount-- ;	// �]�� savecount �|�h�[�@��	
				   	    
				  // ---------- �A���s�@�ӷs�� -------------
				   
				  
				  for ( int newsave = 1 ; newsave <= savecount ; newsave++ ) {
				   	    
					  newfp = fopen("new�ƿWHw.txt","a"); // �s�� 
    	
		    		  fprintf( newfp,"��" );
		    		  fprintf( newfp,"%d", newsave ); // �s��( �ĴX�D ) 
			    	  fprintf( newfp,"�D\n\n" );
					    	
		  			  for ( int j = 0 ; j < number ; j++ ) { // �s�� 
				      	  for ( int i = 0 ; i < number ; i++ ) {
				      	  	fprintf( newfp,"%d",save[newsave].play[i][j] ); // �s��  
				      	  }
			    	  	  	    
		          		  fprintf( newfp,"\n" );
		              }
		   	          fclose(fp); // �����ɮ�  	
	   	          
	   	          }
				  // ---------- �A���s�@�ӷs�� -------------
				  
				  remove("�ƿWHw.txt") ; // �R���� File 
				  rename("new�ƿWHw.txt","�ƿWHw.txt");
				  
				  //if ( savecount == 1 ) remove("�ƿWHw.txt") ; // �p�G�S�F��F �N�R������ɮ� 
				  	  
				  
				  cout << "�w�R����" << intdeletetopic << "�D�D��\n" ;
		  	  	  cout << "�ٳѤU" << savecount << "�D�D��\n" ;    
		  	   }
			  	  
			  
			 	  
		  }
		  else {
		  	cout << "��J���~�A�Э��s��J\n" ;
		  }
		  
		  cout << "-------------------------" << "\n" ;
    	  cout << "��J1 �s�W�D��" << "\n" << "��J2 ����D��" << "\n" << "��J3 �R���D��" << "\n" ;
    	  cout << "��J0 �^��D�ؿ�" << "\n" ;
    	  cout << "-------------------------" << "\n" ;
		  
		  cout << "\n" ;
		  
		  cin.getline(order1,100); // ��J���O	  
	}
	
}

void Order2( int number ) { // ���O 2 ( �i�J�C�� ) 
    Answer saveanswer[50] ; // �s���ץΪ� 
	char order2[100] = {""}; // ���O   
	Save practice[50] ; // �m�ߥΪ�  
	int practicecount = 1, intanswer = 0 ; // �m�ߥΪ�  // ���� 
	char i[100] = {""}, j[100] = {""}, answer[100] = {""} ; // ��J�� �� �� �C �� ����  
	int trash = 1 ; // �p�⵪�׼ƶq ex. saveanswer[1] �� ��1�C2����3 ...... 
	char yesorno[100] = {""} ; // �O�_�Q�~��@�� 
	char finish[100] = {""} ; // �O�_���� 
	char playwhich[100] = {""} ; // �n���ĴX�D 
	int intplaywhich = 0 ; // int �� �n���ĴX�D
	char name[100] = {""} ; // �����̪��W�r 
	time_t start, end ; // �p��ɶ� 
	int rightorwrong = 0 ; // ����ε��� // �@�}�l�� 0  0 ������ 
	Rank rank[100] ; // �ƦW�}�C 
	int countpeople = 0 ; // �p��X�ӤH���� 
	
	cout << "-------------------------" << "\n" ;
    cout << "��J1 �m��" << "\n" << "��J2 �}�l����" << "\n" << "��J3 �d�ݤ���" << "\n" ;
    cout << "��J0 �^��D�ؿ�" << "\n" ;
    cout << "-------------------------" << "\n" ;
	
	cin.getline( order2,100 ); // ��J���O
	
	while ( strcmp( order2, "0" ) != 0 ) { // ��S���n�^��D�ؿ��ɡA�N�@������C
	
		  if ( strcmp( order2, "1" ) == 0 ) {  // ���O 1 ( �m�� ) 
		     
		     practicecount = 1 ; // ��l�� 
		     strcpy( finish, "Y" ) ; // ��l�� 
		     strcpy( yesorno, "Y" ) ; // ��l�� 
		     
		     
		     cout << "�Ʀr 0 ���Ů檺�N��\n" << "�Ш̷ӥ���J��A��J�C���榡�@��\n\n" ; 
		  
		     Game( practice[practicecount].play, number ) ;
		     for ( int j = 0 ; j < number ; j++ ) {
			 	 for ( int i = 0 ; i < number ; i++ ) 
	        	 	 cout << practice[practicecount].play[i][j] << " " ;
		 	     cout << "\n" ;
 	         }
 	         
 	         // --------�@��------------------------------------------------------------------- 
 	         
 	         while ( strcmp( yesorno, "N" ) != 0 && strcmp( finish, "N" ) != 0 ) { // �Q���Q�~��@�� ( �Ĥ@���@�w�O�Q�� ) 
           	 
	 	         cout << "�A(�p)�����׬O : \n" ;
	 	         
	 	         cout << "�ĴX�� : " ;
				 cin.getline( i,100 );  // ��J��
				 while ( !isdigit(i[0]) || strlen(i) != 1 ) {
				 	cout << "��J���~�A�Э��s��J\n" ;
				 	cout << "�ĴX�� : " ;
				 	cin.getline( i,100 );  // ��J��
				 } 
				 
				 saveanswer[trash].i = i[0] ; // �s�� 
				 
				 cout << "�ĴX�C : " ;
				 cin.getline( j,100 ); // ��J�C
				 while ( !isdigit(j[0]) || strlen(j) != 1 ) {
				 	cout << "��J���~�A�Э��s��J\n" ;
				 	cout << "�ĴX�� : " ;
				 	cin.getline( j,100 ); // ��J�C
				 } 
				 
				 saveanswer[trash].j = j[0] ; // �s��
				 
				 while ( !IsNull( practice[practicecount].play, saveanswer[trash] ) ) { // �p�G���O�Ů�
				     cout << "���̤����ն̳�A�Э��s��J\n" ;
				 	 cout << "�A(�p)�����׬O : \n" ;                             // ( �����J ) 
	 	         
		 	         cout << "�ĴX�� : " ;
					 cin.getline( i,100 );  // ��J��
					 while ( !isdigit(i[0]) || strlen(i) != 1 ) {
					 	cout << "��J���~�A�Э��s��J\n" ;
					 	cout << "�ĴX�� : " ;
					 	cin.getline( i,100 );  // ��J��
					 } 
					 saveanswer[trash].i = i[0] ; // �s�� 
					 
					 cout << "�ĴX�C : " ;
					 cin.getline( j,100 ); // ��J�C
					 while ( !isdigit(j[0]) || strlen(j) != 1 ) {
					 	cout << "��J���~�A�Э��s��J\n" ;
					 	cout << "�ĴX�� : " ;
					 	cin.getline( j,100 ); // ��J�C
					 } 
					 
					 saveanswer[trash].j = j[0] ; // �s��
				 }
				 
				 
					 
				 cout << "�Ʀr�O : " ;
				 cin.getline( answer,100 ) ; 
				 
			 
				 if ( strlen(answer) != 1 || ( answer[0] != '1' && answer[0] != '2'
                      && answer[0] != '3' && answer[0] != '4' ) ) {  // ��J���^��βŸ�
				    cout << "�u���1��4�ղ³J�A�Э��s��J\n" ;
				    cout << "�Ʀr�O : " ;
				    cin.getline( answer,100 ) ;
				 	while ( strlen(answer) != 1 || ( answer[0] != '1' & answer[0] != '2'
                            & answer[0] != '3' & answer[0] != '4' ) ) {
  	                      cout << "�u���1��4�ղ³J�A�Э��s��J\n" ;
				          cout << "�Ʀr�O : " ; 
				 		  cin.getline( answer,100 ) ;				 		  
	                }
                 }
	             
	             saveanswer[trash].answer = answer[0] ; // �s��
	             
	             for ( int j = 0 ; j < number ; j++ ) { // �L�X��U���ƿW  // ���e���|���� 
		    	   	   for ( int i = 0 ; i < number ; i++ ) {
		    	   	   	  if ( i == ( saveanswer[trash].i - '0' ) - 1 && j == ( saveanswer[trash].j - '0' ) - 1 )
		    	   	   	  	 practice[practicecount].play[i][j] = saveanswer[trash].answer - '0' ;  	  	   
		    	   	   	  cout << practice[practicecount].play[i][j] << " " ;  
		    	   	   	  if ( i == ( saveanswer[trash].i - '0' ) - 1 && j == ( saveanswer[trash].j - '0' ) - 1 )
		    	   	   	      practice[practicecount].play[i][j] = NULL ;
		    	   	   }   
  			           cout << "\n" ;
                 }
	             
	             trash++ ;
	             
                 cout << "�Q���Q�~��@���A�Q�п�J Y �A���Q�п�J N\n" ;
				 cin.getline( yesorno,100 ) ; // ��J�N�@
				 
				 if ( strcmp( yesorno, "Y" ) != 0 && strcmp( yesorno, "N" ) != 0  ) {
				 	cout << "��J���~�A�Э��s��J\n" ;
				 	cin.getline( yesorno,100 ) ; // ��J�N�@
				 	
				 	while ( strcmp( yesorno, "Y" ) != 0 && strcmp( yesorno, "N" ) != 0 ) {
				 		cout << "��J���~�A�Э��s��J\n" ;
				 	    cin.getline( yesorno,100 ) ; // ��J�N�@
				 	}
				 }
				 
				 if ( strcmp( yesorno, "N" ) == 0 ) { // �p�G���Q�~��@�� 
				 
				      for ( int j = 0 ; j < number ; j++ ) { // ���Ѱj��O�b �p�G�Ů榳�Q��L�Ʀr 
					 	  for ( int i = 0 ; i < number ; i++ ) { // �ڪ��{���X�|�۰ʧ�Źj�Ŧ^�ӡA�����ӪŮ��A���Q��J							 	  	  							 	  	  
				 		      if ( save[intplaywhich].play[i][j] == NULL ) { // �ҥH�U�@���ӪŮ�S�A�Q��J�ɡA�Ů�N�|�ܦ��̫��J�����ӼƦr	
							    for ( int w = 1 ; w < trash ; w++ )	{									    				 		      	
					 		      	if ( i == ( saveanswer[w-1].i - '0' ) - 1 && j == ( saveanswer[w-1].j - '0' ) - 1 ) {											    				 		      	
					 		      		save[intplaywhich].play[i][j] = saveanswer[w-1].answer - '0' ;
					 		        }
				 		      	}
				 		      }
				 	      }
			          }
							      
				      for ( int j = 0 ; j < number ; j++ ) { 
		    	   	     for ( int i = 0 ; i < number ; i++ ) {
		    	   	   	    if ( i == ( saveanswer[trash].i - '0' ) - 1 && j == ( saveanswer[trash].j - '0' ) - 1 )
		    	   	   	  	   save[intplaywhich].play[i][j] = saveanswer[trash].answer - '0' ;  
					     }
                      }
				 
				 
			 	     if ( TrueorFalse( practice[practicecount], saveanswer, trash ) ) {// �p�G����
					     cout << "���ߧA����F�A�A�n�δ�\n" ;
					     strcpy( finish, "Y" ) ;
                     } 
					 else { // �p�G���� 
					 	cout << "�A�����o!�O�_�Q�A�@���A�ж� N �� Y \n" ;
					 	
					 	cin.getline( finish,100 ) ; // ��J�N�@
					 	if ( strcmp( finish, "Y" ) != 0 && strcmp( finish, "N" ) != 0  ) {
						 	cout << "��J���~�A�Э��s��J\n" ;
						 	cin.getline( finish,100 ) ; // ��J�N�@
						 	
						 	while ( strcmp( finish, "Y" ) != 0 && strcmp( finish, "N" ) != 0 ) {
						 		cout << "��J���~�A�Э��s��J\n" ;
						 	    cin.getline( finish,100 ) ; // ��J�N�@
						 	}
				 		}
				     } 
				 }
				 
		      }
		      
		      // --------�@��-------------------------------------------------------------------
		      
		      cout << "-------------------------" << "\n" ;
              cout << "��J1 �m��" << "\n" << "��J2 �}�l����" << "\n" << "��J3 �d�ݤ���" << "\n" ;
              cout << "��J0 �^��D�ؿ�" << "\n" ;
              cout << "-------------------------" << "\n" ;
		        
		  }
		  else if ( strcmp( order2, "2" ) == 0 ) { // ���O 2 ( �}�l���� )  
		      
			  countpeople++ ; // �p���������H�� 

              if ( savecount < 2 && k == 0 ) {
              	 cout << "�Х��s�W�D���A�S�D�جO�n���g�ե�è!\n" ;
              	 strcpy( yesorno, "N" ) ;
              	 strcpy( finish, "Y" ) ;
			  }
			  else {
			  	  strcpy( finish, "Y" ) ; 
			  	  while ( strcmp( finish, "N" ) != 0 ) { // �Q���Q�A�~������ 
	                  strcpy( yesorno, "Y" ) ; // ��l�� 
				  	  cout << "�п�J�n���ĴX�D\n" ;
	       	   		  cin.getline( playwhich,100 ) ; // ��J�n�����D��
					  while ( !isdigit( playwhich[0]) || strlen(playwhich) != 1 ) {
	 				  		cout << "��J���~�A�Э��s��J\n" ;
						 	cout << "�п�J�n���ĴX�D\n" ;
						 	cin.getline( playwhich,100 ) ; // ��J�n�����D��
	                  }  
					       
	   	              intplaywhich = atoi( playwhich ) ; // char�r�� �� int				  	
				  	
				  	  if ( intplaywhich > savecount ) { // �S����h�D�� 
				  	  	cout << "�S����h�D�O�n��������?\n" ;
				  	  	strcpy( yesorno, "N" ) ;
	              	    strcpy( finish, "Y" ) ;
				  	  }
				  
			          else { // ���D�� 		          
             			          
			               trash = 1 ;
			               while ( strcmp( yesorno, "N" ) != 0 ) { // �Q���Q�~��@�� ( �Ĥ@���@�w�O�Q�� )
		       	       
				              for ( int j = 0 ; j < number ; j++ ) { // �L�X�n�����D��
				                   for ( int i = 0 ; i < number ; i++ ) 
								   	   cout << save[intplaywhich].play[i][j] << " " ;
			   	                   cout << "\n" ;
			                  }
			                  if ( trash == 1 )			                  
	                    		 start = time(NULL); // �p�ɶ}�l 
		      
			     		      // --------�@��-------------------------------------------------------------------
			           	 
				 	          cout << "�A(�p)�����׬O : \n" ;
				 	         
				 	          cout << "�ĴX�� : " ;
							  cin.getline( i,100 ) ; // ��J��
							  while ( !isdigit(i[0]) || strlen(i) != 1 ) {
							 	 cout << "��J���~�A�Э��s��J\n" ;
							 	 cout << "�ĴX�� : " ;
							 	 cin.getline( i,100 ) ; // ��J��
							  } 
							 
							  saveanswer[trash].i = i[0] ; // �s�� 
							 
							  cout << "�ĴX�C : " ;
							  cin.getline( j,100 ) ;  // ��J�C
							  while ( !isdigit(j[0]) || strlen(j) != 1 ) {
							  	 cout << "��J���~�A�Э��s��J\n" ;
							 	 cout << "�ĴX�� : " ;
							 	 cin.getline( j,100 ) ;  // ��J�C
							  } 
							 
							  saveanswer[trash].j = j[0] ; // �s��
							 
							  while ( !IsNull( save[intplaywhich].play, saveanswer[trash] ) ) { // �p�G���O�Ů�
							      cout << "���̤����ն̳�A�Э��s��J\n" ;
							 	  cout << "�A(�p)�����׬O : \n" ;                             // ( �����J ) 
				 	         
					 	          cout << "�ĴX�� : " ;
								  cin.getline( i,100 ) ; // ��J��
								  while ( !isdigit(i[0]) || strlen(i) != 1 ) {
								 	 cout << "��J���~�A�Э��s��J\n" ;
								 	 cout << "�ĴX�� : " ;
								 	 cin.getline( i,100 ) ; // ��J��
								  } 
								  saveanswer[trash].i = i[0] ; // �s�� 
								 
								  cout << "�ĴX�C : " ;
								  cin.getline( j,100 ) ;  // ��J�C
								  while ( !isdigit(j[0]) || strlen(j) != 1 ) {
								 	 cout << "��J���~�A�Э��s��J\n" ;
								 	 cout << "�ĴX�� : " ;
								 	 cin.getline( j,100 ) ;  // ��J�C
								  } 
								 
								  saveanswer[trash].j = j[0] ; // �s��
							  }
						  
								 
							  cout << "�Ʀr�O : " ;
							  cin.getline( answer,100 ) ;
							 
						 
							  if ( strlen(answer) != 1 || ( answer[0] != '1' && answer[0] != '2'
			                       && answer[0] != '3' && answer[0] != '4' ) ) {  // ��J���^��βŸ�
							     cout << "�u���1��4�ղ³J�A�Э��s��J\n" ;
							     cout << "�Ʀr�O : " ;
							     cin.getline( answer,100 ) ;
							 	 while ( strlen(answer) != 1 || ( answer[0] != '1' & answer[0] != '2'
			                             & answer[0] != '3' & answer[0] != '4' ) ) {
			  	                       cout << "�u���1��4�ղ³J�A�Э��s��J\n" ;
							           cout << "�Ʀr�O : " ; 
							 		   cin.getline( answer,100 ) ;
				                 }
			                  }
				             
				              saveanswer[trash].answer = answer[0] ; // �s��
				             
				              for ( int j = 0 ; j < number ; j++ ) { // �L�X��U���ƿW 
					    	   	   for ( int i = 0 ; i < number ; i++ ) {
					    	   	   	   if ( i == ( saveanswer[trash].i - '0' ) - 1 && j == ( saveanswer[trash].j - '0' ) - 1 )
					    	   	   	  	  save[intplaywhich].play[i][j] = saveanswer[trash].answer - '0' ;  	  	   
					    	   	   	   cout << save[intplaywhich].play[i][j] << " " ;  
					    	   	   	   if ( i == ( saveanswer[trash].i - '0' ) - 1 && j == ( saveanswer[trash].j - '0' ) - 1 )
					    	   	   	       save[intplaywhich].play[i][j] = NULL ;
					    	   	   }   
			  			           cout << "\n" ;
			                  }			                 	                  
				             
			                  cout << "�Q���Q�~��@���A�Q�п�J Y �A���Q�п�J N\n" ;
							  cin.getline( yesorno,100 ) ; // ��J�N�@
							 
							  if ( strcmp( yesorno, "Y" ) != 0 && strcmp( yesorno, "N" ) != 0  ) {
							 	 cout << "��J���~�A�Э��s��J\n" ;
							 	 cin.getline( yesorno,100 ) ; // ��J�N�@
							 	
							 	 while ( strcmp( yesorno, "Y" ) != 0 && strcmp( yesorno, "N" ) != 0 ) {
							 		 cout << "��J���~�A�Э��s��J\n" ;
							 	     cin.getline( yesorno,100 ) ; // ��J�N�@
							 	 }
							  }
							 
							  if ( strcmp( yesorno, "N" ) == 0 ) { // �p�G���Q�~��@�� 
							  
							      for ( int j = 0 ; j < number ; j++ ) { // ���Ѱj��O�b �p�G�Ů榳�Q��L�Ʀr 
								 	  for ( int i = 0 ; i < number ; i++ ) { // �ڪ��{���X�|�۰ʧ�Źj�Ŧ^�ӡA�����ӪŮ��A���Q��J							 	  	  							 	  	  
							 		      if ( save[intplaywhich].play[i][j] == NULL ) { // �ҥH�U�@���ӪŮ�S�A�Q��J�ɡA�Ů�N�|�ܦ��̫��J�����ӼƦr	
										    for ( int w = 1 ; w < trash ; w++ )	{									    				 		      	
								 		      	if ( i == ( saveanswer[w-1].i - '0' ) - 1 && j == ( saveanswer[w-1].j - '0' ) - 1 ) {											    				 		      	
								 		      		save[intplaywhich].play[i][j] = saveanswer[w-1].answer - '0' ;
								 		        }
							 		      	}
							 		      }
							 	      }
								  }
							      
							      for ( int j = 0 ; j < number ; j++ ) { 
					    	   	     for ( int i = 0 ; i < number ; i++ ) {
					    	   	   	    if ( i == ( saveanswer[trash].i - '0' ) - 1 && j == ( saveanswer[trash].j - '0' ) - 1 )
					    	   	   	  	   save[intplaywhich].play[i][j] = saveanswer[trash].answer - '0' ;  
								     }
    	   	                      }
    	   	                                                      
		       							 
						 	      if ( TrueorFalse( save[intplaywhich], saveanswer, trash ) ) {// �p�G����
								      cout << "���ߧA����F�A�A�n�δ�\n" ;
								      end = time(NULL); // �p�ɵ��� 
								      rightorwrong = 1 ; // ����F 
								      rank[countpeople].time = end - start ; // �ƦW 
								      rank[countpeople].point = 100 - ( end - start )  ;
								      strcpy( finish, "N" ) ;
			                      } 
								  else { // �p�G���� 
								 	 cout << "�A�����o!�O�_�Q�A�����A�ж� N �� Y \n" ;
								 	 end = time(NULL);
								 	 rank[countpeople].time = end - start ; // �ƦW 
								 	 rank[countpeople].point = 60 - ( end - start ) ;
								 	 cin.getline( finish,100 ) ; // ��J�N�@
								 	 if ( strcmp( finish, "Y" ) != 0 && strcmp( finish, "N" ) != 0  ) {
									 	 cout << "��J���~�A�Э��s��J\n" ;
									 	 cin.getline( finish,100 ) ; // ��J�N�@
									 	
									 	 while ( strcmp( finish, "Y" ) != 0 && strcmp( finish, "N" ) != 0 ) {
									 		 cout << "��J���~�A�Э��s��J\n" ;
									 	     cin.getline( finish,100 ) ; // ��J�N�@
									 	 }
							 		 }
							      } 
							  }							  
							  
							  for ( int j = 0 ; j < number ; j++ ) { // ��l���D��							      
							 	  for ( int i = 0 ; i < number ; i++ ) {		 	  	  							 	  	  
								      for ( int w = 1 ; w <= trash + 1 ; w++ ){									     								    				 		      	
						 		      	 if ( i == ( saveanswer[w-1].i - '0' ) - 1 && j == ( saveanswer[w-1].j - '0' ) - 1 ) {												    				 		      	
						 		      		save[intplaywhich].play[i][j] = NULL ;
						 		         }
					 		      	  }
						 		      
						 	      }
							  }
							  trash++ ;	  
						  }
				      }
			      } 
		      }
      
		      cout << "�п�J�A���W�r : " ;
	          cin.getline( name,100 ) ; //��J�W�r 
	          strcpy( rank[countpeople].name, name ) ; // �W�r // �ƦW��W�l���q0�}�l 
	          
	          // --------�@��-------------------------------------------------------------------
	          
	          cout << "-------------------------" << "\n" ;
              cout << "��J1 �m��" << "\n" << "��J2 �}�l����" << "\n" << "��J3 �d�ݤ���" << "\n" ;
              cout << "��J0 �^��D�ؿ�" << "\n" ;
              cout << "-------------------------" << "\n" ;
	       }

		  else if ( strcmp( order2, "3" ) == 0 ) { // ���O 3 ( �d�ݤ��� )
		       if ( savecount < 2 && k == 0 ) { // �S�D�� 
              	 cout << "�Х��s�W�D���A�S�D�جO�n���ƦW�հݸ�!\n" ;
              	 
              	 cout << "-------------------------" << "\n" ;
                 cout << "��J1 �m��" << "\n" << "��J2 �}�l����" << "\n" << "��J3 �d�ݤ���" << "\n" ;
                 cout << "��J0 �^��D�ؿ�" << "\n" ;
                 cout << "-------------------------" << "\n" ;
			   } 
		       else { // ���D�� 
			        
			  	   if ( countpeople > 0 ) { // ���H��
			  	      int temp = 0 ;
			  	      char nametemp[100] = {""} ;
			  	      cout << "-------���ƱƦW-------\n" ;
			  	   
					  for ( int k = 1 ; k < countpeople + 1 ; k++ ) { // �L�X�ƦW 
					     for ( int j = k ; j < countpeople + 1 ; j++ ) {
					     	if ( rank[j].point > rank[k].point ) { // 
					     	   temp = rank[j].point ;
					     	   rank[j].point = rank[k].point ;
					     	   rank[k].point = temp ;
					     	   strcpy( nametemp, rank[j].name ) ;
					     	   strcpy( rank[j].name, rank[k].name ) ;
					     	   strcpy( rank[k].name, nametemp ) ;
					     	}
					     }
					  	     
					  }
					  
					  int kk = 1 ; // �ƦW 
					  for ( int s = 1 ; s < countpeople + 1 ; s++ ) { // countpeople �q 1 �}�l 
					    cout << kk << " " ; 
					  	cout << "�W�r : " << rank[s].name << "  �᪺�ɶ� :  " << rank[s].time << "�� " ;
					  	cout << "���� : " << rank[s].point << "��\n" ; 
					  	kk++ ;
					  }
			  	   } 
				   else { // �S�H��
				      cout << "�S���H���O�n���C�ƦW??\n" ; 
			       }
			       
			       cout << "-------------------------" << "\n" ;
	               cout << "��J1 �m��" << "\n" << "��J2 �}�l����" << "\n" << "��J3 �d�ݤ���" << "\n" ;
	               cout << "��J0 �^��D�ؿ�" << "\n" ;
	               cout << "-------------------------" << "\n" ;
		       }
		  }
		  else {
		  	cout << "��J���~�A�Э��s��J\n" ;
		  }
		  
		  cin.getline( order2,100 ); // ��J���O
	
	}
	
}


int main() {
	int number = 4, play[50][50] = {} ; // ( 4 X 4 ���ƿW )
	
	cout << "-------------------------" << "\n" ;
	cout << "��J1 �i�J�޲z���O" << "\n" << "��J2 �i�J�C��" << "\n" << "��J3 �������{��" << "\n" ;
	cout << "-------------------------" << "\n" ;
	
	char order[100] = {""} ;
	
	cin.getline( order ,100 ) ;
	
	while ( strcmp( order, "3" ) != 0 ) {
	
		if ( strcmp( order, "1" ) == 0 || strcmp( order, "2" ) == 0 ) {
			
			while ( strcmp( order, "3" ) != 0 ) {
			
				  if ( strcmp( order, "1" ) == 0 ) { // ���J�� 1 ( �i�J�޲z���O ) ��
		          	 Order1( number ) ;
		          	 cout << "-------------------------" << "\n" ;
					 cout << "��J1 �i�J�޲z���O" << "\n" << "��J2 �i�J�C��" << "\n" << "��J3 �������{��" << "\n" ;
					 cout << "-------------------------" << "\n" ;
	 			  }
	 			  else if ( strcmp( order, "2" ) == 0 ) { // ���J�� 2 ( �i�J�C�� ) ��
	 			  	 Order2( number ) ;
	 			  	 cout << "-------------------------" << "\n" ;
					 cout << "��J1 �i�J�޲z���O" << "\n" << "��J2 �i�J�C��" << "\n" << "��J3 �������{��" << "\n" ;
					 cout << "-------------------------" << "\n" ;
	 			  } 
	 			  else {
	 			  	cout << "��J���~�A�Э��s��J\n" ;
	 			  	
	 			  	cout << "-------------------------" << "\n" ;
		            cout << "��J1 �i�J�޲z���O" << "\n" << "��J2 �i�J�C��" << "\n" << "��J3 �������{��" << "\n" ;
		            cout << "-------------------------" << "\n" ;
	 			  }
 			  
	 			  cin.getline( order ,100 ) ;
			}
			
		}
		else if ( strcmp( order, "3" ) == 0 ) {
			system("pause") ;	 
	 	    return 0 ;
		}
		else {
			cout << "��J���~�A�Э��s��J\n" ;
			
			cout << "-------------------------" << "\n" ;
	        cout << "��J1 �i�J�޲z���O" << "\n" << "��J2 �i�J�C��" << "\n" << "��J3 �������{��" << "\n" ;
	        cout << "-------------------------" << "\n" ;
	        
	        //cin >> order ;
	        cin.getline( order ,100 ) ;
		}
	
    }
		 
	system("pause") ;	 
		 
    return 0 ;
}
