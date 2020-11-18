#include<stdio.h>
#include <stdlib.h>
#include "windows.h" 
#include<iostream>
#include<fstream>
#include <time.h>

using namespace std ;

int count1 = 0, count2 = 0, saveloop = 1, xx = 0 ;  // 此為廢東東  // 此 save 為"保護"的意思 
int savecount = 1 ; // 題型數量 ( 第幾個 ) // 此 save 為"處存"的意思 

int k = 0 ; // 有無新增題型 

class Rank { // 排名  
    public :  
	int point = 0 ; // 得分 
	int time = 0 ; // 花了幾秒 
	char name[100] ; // 名字 
};

class Save {
    public :
	int play[50][50] ; 
};

Save save[50] ;

class Answer {
	public :
	char i = '\0' ; // 行
	char j = '\0' ; // 列
	char answer = '\0' ; // 答案 
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

bool Same( int i, int temp, int play[50][50], int j ) { // 不能有重複的 
	int a = 0 ; // 布林值                                 // i 為目前是第幾行 
	                                                      // j 為目前是第幾列 
	if ( j == 0 ) { // 如果是第 1 列 
		for ( int x = 0 ; x < i ; x++ ) {  // 檢查 行 有沒有一樣   
			if ( temp == play[x][j] ) a++ ;
		}
	}
	else { // 不是第 1 列 
	    
        for ( int k = j ; k > 0 ; k-- ) { // 檢查 列 有沒有一樣 
        	if ( temp == play[i][k-1] ) a++ ;
        }
		for ( int x = 0 ; x < i ; x++ ) {    // 檢查 行 有沒有一樣  
			if ( temp == play[x][j] ) a++ ;
		}
		
		if ( j % 2 == 1 ) { // 是偶數列 從0開始
		
		    if ( i % 2 == 0 && j % 2 == 1 ) {  //  偶行奇列  // 檢查 框框 有沒有一樣 ( 限 4 X 4 使用 ) 
		       if ( temp == play[i+1][j-1] ) a++ ;
            } 
		    if ( i % 2 == 1 && j % 2 == 1 ) {  // 偶行偶列  // 檢查 框框 有沒有一樣 ( 限 4 X 4 使用 ) 
		       if ( temp == play[i-1][j-1] ) a++ ;
		    } 
		}
	 	
	}
	
	if ( a == 0 ) return true ; // 沒重複的 
	else return false ; // 有重複的 
} 

void Game( int play[50][50], int number ) {
	int space1 = 0, space2 = 0, i = 0, j = 0 ;
	
	srand((unsigned)GetCurrentTime()); // 加這個才是真正隨機 標頭為 "windows.h"  
	int a = 1 + rand() % number ; // 產生 1 ~ number 的亂數 
	
	
	play[i][j] = 1 + rand() % number ;
	
	for ( j = 0 ; j < number ; j++ ) {
		xx = 0 ; // 把 break 指令恢復成初始值 
		
		for ( i = 0 ; i < number ; i++ ) {
			
			int temp = 0 ;
			temp = 1 + rand() % number ;
			
			while ( !Same( i, temp, play, j ) ) {
				temp = 1 + rand() % number ;
				count1++ ; // count 為計算找了幾次 
				
				if ( count1 > 1000 ) { // 萬一 一直找不到正確的數 o9i
				    if ( saveloop == 5 ) { // 當不能排時 ( 數字超過 4 ) 
				    	xx = 1 ; // break 的變數 
				    	break ;
				    } 
					temp = saveloop ; // 強制讓數字等於 1 2 3 4 其中一個 
					saveloop++ ;
				}
			
			}
			
			if( xx == 1 ) { // 當不能排時 while迴圈 break 了 再 break for迴圈 
				j-- ;  // 重跑這一列 
				break ;  
			}
			
			count1 = 0 ; 
			saveloop = 1 ;
			play[i][j] = temp ;
		    
		}
			
	}
	
	for ( int yy = 0 ; yy < 5 ; yy++ ) { // 挖空 
		space1 = rand() % number  ; // 0 ~ ( 4 - 1 ) 的亂數 
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

bool Check( int play[50][50] ) { // 判斷有沒有重複 
	int a = 0 ;
	
	for ( int j = 0 ; j < 4 ; j++ ) {
		for ( int i = 0 ; i < 3 ; i++ ) // 判斷一列一列有沒有重複到 
			if ( play[i][j] == play[i+1][j] ) 
				a++ ;	
		if ( play[0][j] == play[2][j] ) a++ ;
		if ( play[1][j] == play[3][j] ) a++ ;		
	}
	
	for ( int i = 0 ; i < 4 ; i++ ) {
		for ( int j = 0 ; j < 3 ; j++ ) // 判斷一行一行有沒有重複到 
			if ( play[i][j] == play[i][j+1] ) 
				a++ ; 		 
		if ( play[i][0] == play[i][2] ) a++ ;
		if ( play[i][1] == play[i][3] ) a++ ;		    	
	}
	
	if ( play[0][0] == play[1][1] || play[2][0] == play[3][0] || play[0][2] == play[1][3]
	     || play[2][2] == play[3][3] ) 
	     	a++ ;	     
	
	for ( int x = 0 ; x < 4 ; x++ ) { // 萬一有是 0 的 
		for ( int y = 0 ; y < 4 ; y++ ) {
			if ( play[x][y] == 0 ) a++ ;
		}
	}   
	   
	   
    if ( a == 0 ) return true ; // 沒錯 
    else return false ;
}

bool TrueorFalse( Save practice, Answer saveanswer[50], int trash ) { // 判斷答案正不正確 // trash為 
	int inti = 0, intj = 0, intanswer = 0 ; // int 的 行 列 答案                             幾組答案  
	
	for ( int  go = 1 ; go < trash ; go++ ) { // 答案一一放入 留一個 
		inti = saveanswer[go].i - '0' ; // char 轉 int 
		intj = saveanswer[go].j - '0' ; // char 轉 int
		intanswer = saveanswer[go].answer - '0' ; // char 轉 int
		inti-- ; // Game() 裡面 i 是從 0 開始跑 
		intj-- ; // Game() 裡面 i 是從 0 開始跑 
		
		practice.play[inti][intj] = intanswer ; // 把答案放到題目裡 
	}	
	
	if ( Check( practice.play ) ) return true ; // 沒重複的 ( 答對了 ) 
	else return false ; // 有重複的 ( 答錯了 ) 

}

bool IsNull( int play[50][50], Answer saveanswer ) { // 看填入的位子是不是空的 ( 是不是可以填入 ) 
	int a = 0 ;
	int x = saveanswer.i - '0' ;
	int y = saveanswer.j - '0' ;
	
	if ( play[x-1][y-1] == 1 || play[x-1][y-1] == 2 || play[x-1][y-1] == 3
	     || play[x-1][y-1] == 4 || ( x > 4 || y > 4 ) || ( x < 1 || y < 1 ) ) // 如果是數字 ( 不是空格 ) // 超出範圍 
        a++ ; 
	
	if ( a == 0 ) return true ; // 是空格 ( 可以填 )
	else return false ;  // 不能填 
}

void Order1( int number ) { // 指令 1 ( 進入管理指令 )
	char order1[100] = {""} ; // 指令 
	k = 0 ;
	
	FILE *fp ;
	FILE *newfp ;
	
	cout << "-------------------------" << "\n" ;
    cout << "輸入1 新增題型" << "\n" << "輸入2 顯示題型" << "\n" << "輸入3 刪除題型" << "\n" ;
    cout << "輸入0 回到主目錄" << "\n" ;
    cout << "-------------------------" << "\n" ;
    
    cin.getline( order1,100 ); // 輸入指令
    	
    while ( strcmp( order1, "0" ) != 0 ) { // 當沒說要回到主目錄時，就一直執行。 
    
		  if ( strcmp( order1, "1" ) == 0 ) {  // 指令 1 ( 新增題型 ) 
		  
		  	  fp = fopen("數獨Hw.txt","a"); // 存檔 
    	
    		  fprintf( fp,"第" );
    		  if ( k == 0 )
    		    fprintf( fp,"%d", savecount ); // 存檔( 第幾題 ) 
    		  else {
    		  	savecount++ ;
    		  	fprintf( fp,"%d", savecount );
    		  }  
	    	  fprintf( fp,"題\n\n" );
	    	  
	    	  Game( save[savecount].play, number ) ;
			    	
  			  for ( int j = 0 ; j < number ; j++ ) { // 存檔 
		      	  for ( int i = 0 ; i < number ; i++ ) {
		      	  	fprintf( fp,"%d",save[savecount].play[i][j] ); // 存檔  
		      	  }
	    	  	  	    
          		  fprintf( fp,"\n" );
              }
   	          fclose(fp); // 關閉檔案 
   	          
   	          if ( savecount == 1 && k == 0 ) {
   	          	cout << "已新增" << savecount << "道題型\n" ;
   	          	k++ ;
   	          } 
   	          else  {
   	          	//savecount++ ;
   	          	cout << "已新增" << savecount << "道題型\n" ;
   	          }
   	            
   	          

		  }
		  else if ( strcmp( order1, "2" ) == 0 ) { // 指令2 ( 顯示題型  ) 
		  	  cout << "請問要顯示第幾題\n" ;
		  	
		  	  char showtopic[100] = {""} ;
		  	  cin.getline( showtopic,100 ); // 輸入指令
    		  int intshowtopic = atoi( showtopic ) ; // 字串轉 int 
    		  
    		  if ( !Inputerror( showtopic ) ) {
    		  	while ( !Inputerror( showtopic ) ) { 
    		  	    cout << "輸入錯誤，請重新輸入\n" ; // 輸入有英文或符號 
			  		cin.getline( showtopic,100 ); // 輸入指令
			  	}	
			  } 
    		  
    		  intshowtopic = atoi( showtopic ) ; // 字串轉 int
    		  
    		  if ( intshowtopic == 0 ) cout << "沒第0題啦，別來亂\n" ;    		  	
    		  else if ( intshowtopic > savecount || k == 0 ) cout << "沒這麼多題目，請重新輸入\n" ;
    		  else {      // 因為 savecount 會多加一次 所以要 savecount - 1  
    		  	   for ( int j = 0 ; j < number ; j++ ) { // 存檔 
		    	   	   for ( int i = 0 ; i < number ; i++ ) 
		    		   	   cout << save[intshowtopic].play[i][j] << " " ;
  			           cout << "\n" ;
                   }
    		  }
	      
		  }
		  else if ( strcmp( order1, "3" ) == 0 ) {  // 指令3 ( 刪除題型  ) 
		      cout << "請問要刪除第幾題\n" ; 
		       
		  	  char deletetopic[100] = {""} ;
		  	  cin.getline( deletetopic,100 ); 
			  int intdeletetopic = atoi( deletetopic ) ; // 字串轉 int
			  
			  if ( !Inputerror( deletetopic ) ) {
			  	while ( !Inputerror( deletetopic ) ) { 
			  	    cout << "輸入錯誤，請重新輸入\n" ; // 輸入有英文或符號  
			  		cin.getline( deletetopic,100 ); 
			  	}  	
			  }
			  
			  intdeletetopic = atoi( deletetopic ) ; // 字串轉 int
			  
			  if ( intdeletetopic == 0 ) cout << "沒第0題啦，別來亂\n" ; 	
		  	  else if ( intdeletetopic > savecount || k == 0 ) cout << "沒這麼多題目，請重新輸入\n" ;
		  	  else {           // 因為 savecount 會多加一次 所以要 savecount - 1 
	             
             	 if ( intdeletetopic == savecount ) {  // 要刪的是最後一個
	                for ( int j = 0 ; j < number ; j++ ) { // 把最後一個變成 NULL 
	                   for ( int i = 0 ; i < number ; i++ ) 
    		   	   		   save[intdeletetopic].play[i][j] = NULL ;
       			    }
		            savecount-- ;
     	          }
				  else { // 要刪的不是最後一個 
				 	for ( int k = intdeletetopic ; k < savecount ; k++ ) {
				 		save[k] = save[k + 1] ; // 把原本的變成後一個 
				 	}
				 	for ( int j = 0 ; j < number ; j++ ) { // 把最後一個變成 NULL
	                   for ( int i = 0 ; i < number ; i++ ) 
    		   	   		   save[savecount].play[i][j] = NULL ;
       			    }
				 	savecount-- ;
				  } 
			  
				  //savecount-- ;	// 因為 savecount 會多加一次	
				   	    
				  // ---------- 再重存一個新的 -------------
				   
				  
				  for ( int newsave = 1 ; newsave <= savecount ; newsave++ ) {
				   	    
					  newfp = fopen("new數獨Hw.txt","a"); // 存檔 
    	
		    		  fprintf( newfp,"第" );
		    		  fprintf( newfp,"%d", newsave ); // 存檔( 第幾題 ) 
			    	  fprintf( newfp,"題\n\n" );
					    	
		  			  for ( int j = 0 ; j < number ; j++ ) { // 存檔 
				      	  for ( int i = 0 ; i < number ; i++ ) {
				      	  	fprintf( newfp,"%d",save[newsave].play[i][j] ); // 存檔  
				      	  }
			    	  	  	    
		          		  fprintf( newfp,"\n" );
		              }
		   	          fclose(fp); // 關閉檔案  	
	   	          
	   	          }
				  // ---------- 再重存一個新的 -------------
				  
				  remove("數獨Hw.txt") ; // 刪除此 File 
				  rename("new數獨Hw.txt","數獨Hw.txt");
				  
				  //if ( savecount == 1 ) remove("數獨Hw.txt") ; // 如果沒東西了 就刪掉整個檔案 
				  	  
				  
				  cout << "已刪除第" << intdeletetopic << "道題目\n" ;
		  	  	  cout << "還剩下" << savecount << "道題目\n" ;    
		  	   }
			  	  
			  
			 	  
		  }
		  else {
		  	cout << "輸入錯誤，請重新輸入\n" ;
		  }
		  
		  cout << "-------------------------" << "\n" ;
    	  cout << "輸入1 新增題型" << "\n" << "輸入2 顯示題型" << "\n" << "輸入3 刪除題型" << "\n" ;
    	  cout << "輸入0 回到主目錄" << "\n" ;
    	  cout << "-------------------------" << "\n" ;
		  
		  cout << "\n" ;
		  
		  cin.getline(order1,100); // 輸入指令	  
	}
	
}

void Order2( int number ) { // 指令 2 ( 進入遊戲 ) 
    Answer saveanswer[50] ; // 存答案用的 
	char order2[100] = {""}; // 指令   
	Save practice[50] ; // 練習用的  
	int practicecount = 1, intanswer = 0 ; // 練習用的  // 答案 
	char i[100] = {""}, j[100] = {""}, answer[100] = {""} ; // 輸入的 行 跟 列 跟 答案  
	int trash = 1 ; // 計算答案數量 ex. saveanswer[1] 為 行1列2答案3 ...... 
	char yesorno[100] = {""} ; // 是否想繼續作答 
	char finish[100] = {""} ; // 是否答完 
	char playwhich[100] = {""} ; // 要闖第幾題 
	int intplaywhich = 0 ; // int 的 要闖第幾題
	char name[100] = {""} ; // 闖關者的名字 
	time_t start, end ; // 計算時間 
	int rightorwrong = 0 ; // 答對或答錯 // 一開始為 0  0 為答錯 
	Rank rank[100] ; // 排名陣列 
	int countpeople = 0 ; // 計算幾個人闖關 
	
	cout << "-------------------------" << "\n" ;
    cout << "輸入1 練習" << "\n" << "輸入2 開始闖關" << "\n" << "輸入3 查看分數" << "\n" ;
    cout << "輸入0 回到主目錄" << "\n" ;
    cout << "-------------------------" << "\n" ;
	
	cin.getline( order2,100 ); // 輸入指令
	
	while ( strcmp( order2, "0" ) != 0 ) { // 當沒說要回到主目錄時，就一直執行。
	
		  if ( strcmp( order2, "1" ) == 0 ) {  // 指令 1 ( 練習 ) 
		     
		     practicecount = 1 ; // 初始化 
		     strcpy( finish, "Y" ) ; // 初始化 
		     strcpy( yesorno, "Y" ) ; // 初始化 
		     
		     
		     cout << "數字 0 為空格的意思\n" << "請依照先輸入行再輸入列的格式作答\n\n" ; 
		  
		     Game( practice[practicecount].play, number ) ;
		     for ( int j = 0 ; j < number ; j++ ) {
			 	 for ( int i = 0 ; i < number ; i++ ) 
	        	 	 cout << practice[practicecount].play[i][j] << " " ;
		 	     cout << "\n" ;
 	         }
 	         
 	         // --------作答------------------------------------------------------------------- 
 	         
 	         while ( strcmp( yesorno, "N" ) != 0 && strcmp( finish, "N" ) != 0 ) { // 想不想繼續作答 ( 第一次一定是想的 ) 
           	 
	 	         cout << "你(妳)的答案是 : \n" ;
	 	         
	 	         cout << "第幾行 : " ;
				 cin.getline( i,100 );  // 輸入行
				 while ( !isdigit(i[0]) || strlen(i) != 1 ) {
				 	cout << "輸入錯誤，請重新輸入\n" ;
				 	cout << "第幾行 : " ;
				 	cin.getline( i,100 );  // 輸入行
				 } 
				 
				 saveanswer[trash].i = i[0] ; // 存行 
				 
				 cout << "第幾列 : " ;
				 cin.getline( j,100 ); // 輸入列
				 while ( !isdigit(j[0]) || strlen(j) != 1 ) {
				 	cout << "輸入錯誤，請重新輸入\n" ;
				 	cout << "第幾行 : " ;
				 	cin.getline( j,100 ); // 輸入列
				 } 
				 
				 saveanswer[trash].j = j[0] ; // 存行
				 
				 while ( !IsNull( practice[practicecount].play, saveanswer[trash] ) ) { // 如果不是空格
				     cout << "那裡不能填啦傻喔，請重新輸入\n" ;
				 	 cout << "你(妳)的答案是 : \n" ;                             // ( 不能輸入 ) 
	 	         
		 	         cout << "第幾行 : " ;
					 cin.getline( i,100 );  // 輸入行
					 while ( !isdigit(i[0]) || strlen(i) != 1 ) {
					 	cout << "輸入錯誤，請重新輸入\n" ;
					 	cout << "第幾行 : " ;
					 	cin.getline( i,100 );  // 輸入行
					 } 
					 saveanswer[trash].i = i[0] ; // 存行 
					 
					 cout << "第幾列 : " ;
					 cin.getline( j,100 ); // 輸入列
					 while ( !isdigit(j[0]) || strlen(j) != 1 ) {
					 	cout << "輸入錯誤，請重新輸入\n" ;
					 	cout << "第幾行 : " ;
					 	cin.getline( j,100 ); // 輸入列
					 } 
					 
					 saveanswer[trash].j = j[0] ; // 存行
				 }
				 
				 
					 
				 cout << "數字是 : " ;
				 cin.getline( answer,100 ) ; 
				 
			 
				 if ( strlen(answer) != 1 || ( answer[0] != '1' && answer[0] != '2'
                      && answer[0] != '3' && answer[0] != '4' ) ) {  // 輸入有英文或符號
				    cout << "只能輸1到4啦笨蛋，請重新輸入\n" ;
				    cout << "數字是 : " ;
				    cin.getline( answer,100 ) ;
				 	while ( strlen(answer) != 1 || ( answer[0] != '1' & answer[0] != '2'
                            & answer[0] != '3' & answer[0] != '4' ) ) {
  	                      cout << "只能輸1到4啦笨蛋，請重新輸入\n" ;
				          cout << "數字是 : " ; 
				 		  cin.getline( answer,100 ) ;				 		  
	                }
                 }
	             
	             saveanswer[trash].answer = answer[0] ; // 存行
	             
	             for ( int j = 0 ; j < number ; j++ ) { // 印出當下的數獨  // 之前的會不見 
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
	             
                 cout << "想不想繼續作答，想請輸入 Y ，不想請輸入 N\n" ;
				 cin.getline( yesorno,100 ) ; // 輸入意願
				 
				 if ( strcmp( yesorno, "Y" ) != 0 && strcmp( yesorno, "N" ) != 0  ) {
				 	cout << "輸入錯誤，請重新輸入\n" ;
				 	cin.getline( yesorno,100 ) ; // 輸入意願
				 	
				 	while ( strcmp( yesorno, "Y" ) != 0 && strcmp( yesorno, "N" ) != 0 ) {
				 		cout << "輸入錯誤，請重新輸入\n" ;
				 	    cin.getline( yesorno,100 ) ; // 輸入意願
				 	}
				 }
				 
				 if ( strcmp( yesorno, "N" ) == 0 ) { // 如果不想繼續作答 
				 
				      for ( int j = 0 ; j < number ; j++ ) { // 此參迴圈是在 如果空格有被填過數字 
					 	  for ( int i = 0 ; i < number ; i++ ) { // 我的程式碼會自動把空隔空回來，讓那個空格能再次被輸入							 	  	  							 	  	  
				 		      if ( save[intplaywhich].play[i][j] == NULL ) { // 所以萬一那個空格沒再被輸入時，空格將會變成最後輸入的那個數字	
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
				 
				 
			 	     if ( TrueorFalse( practice[practicecount], saveanswer, trash ) ) {// 如果答對
					     cout << "恭喜你答對了，你好棒棒\n" ;
					     strcpy( finish, "Y" ) ;
                     } 
					 else { // 如果答錯 
					 	cout << "你答錯囉!是否想再作答，請填 N 或 Y \n" ;
					 	
					 	cin.getline( finish,100 ) ; // 輸入意願
					 	if ( strcmp( finish, "Y" ) != 0 && strcmp( finish, "N" ) != 0  ) {
						 	cout << "輸入錯誤，請重新輸入\n" ;
						 	cin.getline( finish,100 ) ; // 輸入意願
						 	
						 	while ( strcmp( finish, "Y" ) != 0 && strcmp( finish, "N" ) != 0 ) {
						 		cout << "輸入錯誤，請重新輸入\n" ;
						 	    cin.getline( finish,100 ) ; // 輸入意願
						 	}
				 		}
				     } 
				 }
				 
		      }
		      
		      // --------作答-------------------------------------------------------------------
		      
		      cout << "-------------------------" << "\n" ;
              cout << "輸入1 練習" << "\n" << "輸入2 開始闖關" << "\n" << "輸入3 查看分數" << "\n" ;
              cout << "輸入0 回到主目錄" << "\n" ;
              cout << "-------------------------" << "\n" ;
		        
		  }
		  else if ( strcmp( order2, "2" ) == 0 ) { // 指令 2 ( 開始闖關 )  
		      
			  countpeople++ ; // 計算闖關的人數 

              if ( savecount < 2 && k == 0 ) {
              	 cout << "請先新增題型，沒題目是要怎麼寫啦白癡!\n" ;
              	 strcpy( yesorno, "N" ) ;
              	 strcpy( finish, "Y" ) ;
			  }
			  else {
			  	  strcpy( finish, "Y" ) ; 
			  	  while ( strcmp( finish, "N" ) != 0 ) { // 想不想再繼續闖關 
	                  strcpy( yesorno, "Y" ) ; // 初始化 
				  	  cout << "請輸入要闖第幾題\n" ;
	       	   		  cin.getline( playwhich,100 ) ; // 輸入要闖的題號
					  while ( !isdigit( playwhich[0]) || strlen(playwhich) != 1 ) {
	 				  		cout << "輸入錯誤，請重新輸入\n" ;
						 	cout << "請輸入要闖第幾題\n" ;
						 	cin.getline( playwhich,100 ) ; // 輸入要闖的題號
	                  }  
					       
	   	              intplaywhich = atoi( playwhich ) ; // char字串 轉 int				  	
				  	
				  	  if ( intplaywhich > savecount ) { // 沒那麼多題目 
				  	  	cout << "沒那麼多題是要闖什麼關?\n" ;
				  	  	strcpy( yesorno, "N" ) ;
	              	    strcpy( finish, "Y" ) ;
				  	  }
				  
			          else { // 有題目 		          
             			          
			               trash = 1 ;
			               while ( strcmp( yesorno, "N" ) != 0 ) { // 想不想繼續作答 ( 第一次一定是想的 )
		       	       
				              for ( int j = 0 ; j < number ; j++ ) { // 印出要闖的題目
				                   for ( int i = 0 ; i < number ; i++ ) 
								   	   cout << save[intplaywhich].play[i][j] << " " ;
			   	                   cout << "\n" ;
			                  }
			                  if ( trash == 1 )			                  
	                    		 start = time(NULL); // 計時開始 
		      
			     		      // --------作答-------------------------------------------------------------------
			           	 
				 	          cout << "你(妳)的答案是 : \n" ;
				 	         
				 	          cout << "第幾行 : " ;
							  cin.getline( i,100 ) ; // 輸入行
							  while ( !isdigit(i[0]) || strlen(i) != 1 ) {
							 	 cout << "輸入錯誤，請重新輸入\n" ;
							 	 cout << "第幾行 : " ;
							 	 cin.getline( i,100 ) ; // 輸入行
							  } 
							 
							  saveanswer[trash].i = i[0] ; // 存行 
							 
							  cout << "第幾列 : " ;
							  cin.getline( j,100 ) ;  // 輸入列
							  while ( !isdigit(j[0]) || strlen(j) != 1 ) {
							  	 cout << "輸入錯誤，請重新輸入\n" ;
							 	 cout << "第幾行 : " ;
							 	 cin.getline( j,100 ) ;  // 輸入列
							  } 
							 
							  saveanswer[trash].j = j[0] ; // 存行
							 
							  while ( !IsNull( save[intplaywhich].play, saveanswer[trash] ) ) { // 如果不是空格
							      cout << "那裡不能填啦傻喔，請重新輸入\n" ;
							 	  cout << "你(妳)的答案是 : \n" ;                             // ( 不能輸入 ) 
				 	         
					 	          cout << "第幾行 : " ;
								  cin.getline( i,100 ) ; // 輸入行
								  while ( !isdigit(i[0]) || strlen(i) != 1 ) {
								 	 cout << "輸入錯誤，請重新輸入\n" ;
								 	 cout << "第幾行 : " ;
								 	 cin.getline( i,100 ) ; // 輸入行
								  } 
								  saveanswer[trash].i = i[0] ; // 存行 
								 
								  cout << "第幾列 : " ;
								  cin.getline( j,100 ) ;  // 輸入列
								  while ( !isdigit(j[0]) || strlen(j) != 1 ) {
								 	 cout << "輸入錯誤，請重新輸入\n" ;
								 	 cout << "第幾行 : " ;
								 	 cin.getline( j,100 ) ;  // 輸入列
								  } 
								 
								  saveanswer[trash].j = j[0] ; // 存行
							  }
						  
								 
							  cout << "數字是 : " ;
							  cin.getline( answer,100 ) ;
							 
						 
							  if ( strlen(answer) != 1 || ( answer[0] != '1' && answer[0] != '2'
			                       && answer[0] != '3' && answer[0] != '4' ) ) {  // 輸入有英文或符號
							     cout << "只能輸1到4啦笨蛋，請重新輸入\n" ;
							     cout << "數字是 : " ;
							     cin.getline( answer,100 ) ;
							 	 while ( strlen(answer) != 1 || ( answer[0] != '1' & answer[0] != '2'
			                             & answer[0] != '3' & answer[0] != '4' ) ) {
			  	                       cout << "只能輸1到4啦笨蛋，請重新輸入\n" ;
							           cout << "數字是 : " ; 
							 		   cin.getline( answer,100 ) ;
				                 }
			                  }
				             
				              saveanswer[trash].answer = answer[0] ; // 存行
				             
				              for ( int j = 0 ; j < number ; j++ ) { // 印出當下的數獨 
					    	   	   for ( int i = 0 ; i < number ; i++ ) {
					    	   	   	   if ( i == ( saveanswer[trash].i - '0' ) - 1 && j == ( saveanswer[trash].j - '0' ) - 1 )
					    	   	   	  	  save[intplaywhich].play[i][j] = saveanswer[trash].answer - '0' ;  	  	   
					    	   	   	   cout << save[intplaywhich].play[i][j] << " " ;  
					    	   	   	   if ( i == ( saveanswer[trash].i - '0' ) - 1 && j == ( saveanswer[trash].j - '0' ) - 1 )
					    	   	   	       save[intplaywhich].play[i][j] = NULL ;
					    	   	   }   
			  			           cout << "\n" ;
			                  }			                 	                  
				             
			                  cout << "想不想繼續作答，想請輸入 Y ，不想請輸入 N\n" ;
							  cin.getline( yesorno,100 ) ; // 輸入意願
							 
							  if ( strcmp( yesorno, "Y" ) != 0 && strcmp( yesorno, "N" ) != 0  ) {
							 	 cout << "輸入錯誤，請重新輸入\n" ;
							 	 cin.getline( yesorno,100 ) ; // 輸入意願
							 	
							 	 while ( strcmp( yesorno, "Y" ) != 0 && strcmp( yesorno, "N" ) != 0 ) {
							 		 cout << "輸入錯誤，請重新輸入\n" ;
							 	     cin.getline( yesorno,100 ) ; // 輸入意願
							 	 }
							  }
							 
							  if ( strcmp( yesorno, "N" ) == 0 ) { // 如果不想繼續作答 
							  
							      for ( int j = 0 ; j < number ; j++ ) { // 此參迴圈是在 如果空格有被填過數字 
								 	  for ( int i = 0 ; i < number ; i++ ) { // 我的程式碼會自動把空隔空回來，讓那個空格能再次被輸入							 	  	  							 	  	  
							 		      if ( save[intplaywhich].play[i][j] == NULL ) { // 所以萬一那個空格沒再被輸入時，空格將會變成最後輸入的那個數字	
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
    	   	                                                      
		       							 
						 	      if ( TrueorFalse( save[intplaywhich], saveanswer, trash ) ) {// 如果答對
								      cout << "恭喜你答對了，你好棒棒\n" ;
								      end = time(NULL); // 計時結束 
								      rightorwrong = 1 ; // 答對了 
								      rank[countpeople].time = end - start ; // 排名 
								      rank[countpeople].point = 100 - ( end - start )  ;
								      strcpy( finish, "N" ) ;
			                      } 
								  else { // 如果答錯 
								 	 cout << "你答錯囉!是否想再闖關，請填 N 或 Y \n" ;
								 	 end = time(NULL);
								 	 rank[countpeople].time = end - start ; // 排名 
								 	 rank[countpeople].point = 60 - ( end - start ) ;
								 	 cin.getline( finish,100 ) ; // 輸入意願
								 	 if ( strcmp( finish, "Y" ) != 0 && strcmp( finish, "N" ) != 0  ) {
									 	 cout << "輸入錯誤，請重新輸入\n" ;
									 	 cin.getline( finish,100 ) ; // 輸入意願
									 	
									 	 while ( strcmp( finish, "Y" ) != 0 && strcmp( finish, "N" ) != 0 ) {
									 		 cout << "輸入錯誤，請重新輸入\n" ;
									 	     cin.getline( finish,100 ) ; // 輸入意願
									 	 }
							 		 }
							      } 
							  }							  
							  
							  for ( int j = 0 ; j < number ; j++ ) { // 初始化題目							      
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
      
		      cout << "請輸入你的名字 : " ;
	          cin.getline( name,100 ) ; //輸入名字 
	          strcpy( rank[countpeople].name, name ) ; // 名字 // 排名跟名子都從0開始 
	          
	          // --------作答-------------------------------------------------------------------
	          
	          cout << "-------------------------" << "\n" ;
              cout << "輸入1 練習" << "\n" << "輸入2 開始闖關" << "\n" << "輸入3 查看分數" << "\n" ;
              cout << "輸入0 回到主目錄" << "\n" ;
              cout << "-------------------------" << "\n" ;
	       }

		  else if ( strcmp( order2, "3" ) == 0 ) { // 指令 3 ( 查看分數 )
		       if ( savecount < 2 && k == 0 ) { // 沒題目 
              	 cout << "請先新增題型，沒題目是要怎麼排名啦問號!\n" ;
              	 
              	 cout << "-------------------------" << "\n" ;
                 cout << "輸入1 練習" << "\n" << "輸入2 開始闖關" << "\n" << "輸入3 查看分數" << "\n" ;
                 cout << "輸入0 回到主目錄" << "\n" ;
                 cout << "-------------------------" << "\n" ;
			   } 
		       else { // 有題目 
			        
			  	   if ( countpeople > 0 ) { // 有人玩
			  	      int temp = 0 ;
			  	      char nametemp[100] = {""} ;
			  	      cout << "-------分數排名-------\n" ;
			  	   
					  for ( int k = 1 ; k < countpeople + 1 ; k++ ) { // 印出排名 
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
					  
					  int kk = 1 ; // 排名 
					  for ( int s = 1 ; s < countpeople + 1 ; s++ ) { // countpeople 從 1 開始 
					    cout << kk << " " ; 
					  	cout << "名字 : " << rank[s].name << "  花的時間 :  " << rank[s].time << "秒 " ;
					  	cout << "分數 : " << rank[s].point << "分\n" ; 
					  	kk++ ;
					  }
			  	   } 
				   else { // 沒人玩
				      cout << "沒有人玩是要怎麼列排名??\n" ; 
			       }
			       
			       cout << "-------------------------" << "\n" ;
	               cout << "輸入1 練習" << "\n" << "輸入2 開始闖關" << "\n" << "輸入3 查看分數" << "\n" ;
	               cout << "輸入0 回到主目錄" << "\n" ;
	               cout << "-------------------------" << "\n" ;
		       }
		  }
		  else {
		  	cout << "輸入錯誤，請重新輸入\n" ;
		  }
		  
		  cin.getline( order2,100 ); // 輸入指令
	
	}
	
}


int main() {
	int number = 4, play[50][50] = {} ; // ( 4 X 4 的數獨 )
	
	cout << "-------------------------" << "\n" ;
	cout << "輸入1 進入管理指令" << "\n" << "輸入2 進入遊戲" << "\n" << "輸入3 結束本程式" << "\n" ;
	cout << "-------------------------" << "\n" ;
	
	char order[100] = {""} ;
	
	cin.getline( order ,100 ) ;
	
	while ( strcmp( order, "3" ) != 0 ) {
	
		if ( strcmp( order, "1" ) == 0 || strcmp( order, "2" ) == 0 ) {
			
			while ( strcmp( order, "3" ) != 0 ) {
			
				  if ( strcmp( order, "1" ) == 0 ) { // 當輸入為 1 ( 進入管理指令 ) 時
		          	 Order1( number ) ;
		          	 cout << "-------------------------" << "\n" ;
					 cout << "輸入1 進入管理指令" << "\n" << "輸入2 進入遊戲" << "\n" << "輸入3 結束本程式" << "\n" ;
					 cout << "-------------------------" << "\n" ;
	 			  }
	 			  else if ( strcmp( order, "2" ) == 0 ) { // 當輸入為 2 ( 進入遊戲 ) 時
	 			  	 Order2( number ) ;
	 			  	 cout << "-------------------------" << "\n" ;
					 cout << "輸入1 進入管理指令" << "\n" << "輸入2 進入遊戲" << "\n" << "輸入3 結束本程式" << "\n" ;
					 cout << "-------------------------" << "\n" ;
	 			  } 
	 			  else {
	 			  	cout << "輸入錯誤，請重新輸入\n" ;
	 			  	
	 			  	cout << "-------------------------" << "\n" ;
		            cout << "輸入1 進入管理指令" << "\n" << "輸入2 進入遊戲" << "\n" << "輸入3 結束本程式" << "\n" ;
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
			cout << "輸入錯誤，請重新輸入\n" ;
			
			cout << "-------------------------" << "\n" ;
	        cout << "輸入1 進入管理指令" << "\n" << "輸入2 進入遊戲" << "\n" << "輸入3 結束本程式" << "\n" ;
	        cout << "-------------------------" << "\n" ;
	        
	        //cin >> order ;
	        cin.getline( order ,100 ) ;
		}
	
    }
		 
	system("pause") ;	 
		 
    return 0 ;
}
