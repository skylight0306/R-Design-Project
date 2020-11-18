// 10327247 舒一修 10327271 杜汶康  第8組

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<fstream>
using namespace std ;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int output_counter = 1 ;
int size = 0 ;
int str[4] = {0,0,0,0};
struct Rank{
	string pname ;
	int high ;
	int time ;
};
Rank rank[5] ;
string name ;
class Person{
	private :
      string guest_name ;
      int score_high ;
      int score ;
      int time ;
      int time_low ;

    public :

      int getscore(){
          return score ;
      }
	  void changename() {
	  	guest_name = name ;
	  } // 換名字

	  void changehigh(){
	  	if (score > score_high) {
	  		score_high = score ;
		  }
	  }

	  void changescore( int num ){
	  	score = num ;
	  }

	  void changetime() {
	  	time = gettime() ;
	  }

	  int gethigh() {
	  	return score_high ;
	  }


      int gettime_low(){
	  	return 3000 - gethigh()/2 ;
	  }

	  int gettime(){
	  	return 3000 - getscore()/2 ;
	  }

	  string getname() {
	  	return guest_name ;
	  }
};
class Sudoku{

	private :
	int sudoku[4][4] ;

    public :

	void initialize(){

		int i,j = 0 ;
		while( i < 4 ){
			while(j < 4){

				sudoku[i][j] = 0 ;

				j++ ;
			}
			if(j == 4) j = 0 ;

			i++ ;
		}



	} // 初始化

void print(){
      for( int i = 0 ; i < 4 ; i++ ){
        if ( i != 2 ) cout << "\n  ______________\n " ;
        else cout << "\n  ==============\n " ;
        for( int j = 0 ; j < 4 ; j++ ){
            if( sudoku[i][j] != 0) {
                cout << "｜" << sudoku[i][j]  ;
                if (j == 1) cout << "｜" ;
                if ( j == 3 ) cout << "｜" ;
            }
            else {
                cout << "｜" <<" "  ;
                if (j == 1) cout << "｜" ;
                if ( j == 3 ) cout << "｜" ;
            }
        }
      }

        cout << "\n  ______________\n" ;

} //印



	void checkColumns() {

	} // 確認直排是否符合規則
	void checkLines(){

	} //	確認橫排是否符合規則

	void checkGung(){

	} // 確認宮是否符合規則

	void change( int i ,int j , int num) {
		sudoku[i][j] = num ;
	}

	int getnum( int i, int j ){
		return sudoku[i][j] ;
	}
    int zero(){
        int i = 0 ;
		int j = 0 ;
		int num = 0 ;

		while( i < 4 ){

			while(j < 4){
				if( sudoku[i][j] == 0) {
				  num++ ;
				}

				j++ ;
			}
			if(j == 4) {
			  j = 0 ;
			}
			i++ ;
		}
		return num ;
	}
};
Sudoku sudoku[50] ;
void deleteSudoku() {
  	int num ;
	cout << "想刪除第幾個迷你數獨?\n" ;
	cin >> num ;

	if( num < 0 || num > 50 || num >= size+1 ){
		cout << "此數獨不存在" ;
	}
	else {
		if( size == 1 && num == 1 ){
			size = 0 ;
		} // 只有一個
		else if( num == size ){
			sudoku[size-1].initialize() ;
			size = size - 1 ;
		} // 刪除尾巴
		else{
			int count = 0 ;
			count = num ;
			while ( count < size) {
				sudoku[count-1] = sudoku[count] ;
				count++ ;
			}
			sudoku[size-1].initialize() ;
			size = size - 1 ;

		} // 刪除中間
	}
	return;

 }
bool Sudoku_equal( Sudoku now, Sudoku target) {
   int i = 0 ;
   int j = 0 ;
   int k = 0 ;

   while( i < 4 ){

     while(j < 4){
	    if( now.getnum(i,j) == target.getnum(i,j) ) {
	    	k++ ;
		}

		j++ ;
	 } // while
	 if(j == 4) {
      j = 0 ;
	 } // if
	i++ ;
   } // while

   if( k == 16){
   	return true ;
   }

   return false ;
 }
void createSudoku( Sudoku &sudoku ) {
  int temp = 0 ;


  for ( int i = 0 ; i < 4 ; i++ ) {

    for (int j = 0 ; j < 4 ; j++ ) {
	  sudoku.change( i , j , str[j] ) ;
	    }    // 複製進數獨的資料
        for ( int j = 0 ; j < 4-1 ; j++ ){
          temp = str[j] ;
          str[j] = str[j+1] ;
          str[j+1] = temp ;
        } // for
      } // for
      for ( int i = 0 ; i < 4 ; i++ ) {                     // 把第二行和第三行互換
       temp = sudoku.getnum(1,i) ;
       sudoku.change(1,i,sudoku.getnum(2,i)) ;
       sudoku.change(2,i,temp) ;
      } // for

 } // create
 int random(){         // 1~4的亂數
 str[0] = 0;
 str[1] = 0;
 str[2] = 0;
 str[3] = 0;
 int temp = 0 ;
 bool next = false ;
 unsigned seed;
 seed = (unsigned)time(NULL);             // 取得時間序列
 srand(seed);                            // 以時間序列當亂數種子 (這樣每次開temp才會不同)
 for (int i = 0 ; i < 4 ; i++ ) str[i] = 0 ;                 // str要初始化
 for (int i = 0 ; i < 4 ; i++ ) {
   while ( next == false ) {
     temp = rand() % 4 + 1 ;                          // 自動填入1~4的亂數
     if ( temp != str[0] && temp != str[1] && temp != str[2] && temp != str[3] ) {
       str[i] = temp ;
       next = true ;
     } // if
   } // while
    next = false ;
 }
} // random
void makeminisudo(){
	Sudoku newone ;
	random() ;
	createSudoku(newone) ;
	  if ( size == 0 ) {
        sudoku[size] = newone ;
        size++ ;
	  } // 第一個
	  else {
	  	int count = 0 ;
	  	bool again = false ;
	  	while(count < size){
	  		if(Sudoku_equal( newone,sudoku[count])){
	  			again = true ;
			  } // 判斷有沒有重複
			  count++ ;
		  } //去跟每一個比較
	  	  if (!again) {
	  	  	  sudoku[size] = newone ;
              size++ ;
			}
	  } //需先判斷有沒有與之前重複

	  cout << "是否需要顯示?(Y/N)" ;
	  char a;
	  cin >> a ;
	  if (a == 'y') {
	  	newone.print() ;
	  }
	  else if ( a == 'n'){
	  	return ;
	  }
	  else{
	  	cout << "指令不存在" ;
	  }
}
void Print(){
	int num ;
	cout << size << "想看第幾個迷你數獨?\n" ;

	cin >> num ;

	if( num <= 0 || num > 50 || num > size ){
		cout << "此數獨不存在" ;
	}
	else {
		sudoku[num - 1].print();
	}
	return;
}
int BlankSpace( Sudoku &sudoku, int level ){
    int some = 0;
    if (level == 1 )  some = 3;
    else if (level == 2 ) some = 6 ;
    srand(time(NULL));
    bool next = false ;
    for ( int k = 0 ; k < some ; k++ ) {
      while( next == false ) {
        int j = rand() % 4 ;               // 自動填入亂數
        int i = rand() % 4 ;
        if( sudoku.getnum( i, j ) != 0 ) {       // 不是空白
          sudoku.change( i ,j ,0 ) ;             // 換成空白
          next = true ;
        } // if
      } // while

       next = false ;
    } // for

} // BlankSpace()
bool check( char num[200] ){
	int length = strlen( num ) ;
	int i = 0 ;
	while ( i < length ){
		if(num[i]>='0' && num[i] <= '9') {
			i++ ;
		}
		else{
			return false ;
		}
	}
	return true ;
}
void outputfile() {
	    fstream file;

        file.open("sudoku.txt", ios::out);      //開啟檔案
        if(!file)     //檢查檔案是否成功開啟
        {
                cout << "無法讀入檔案\n";
                exit(1);     //在不正常情形下，中斷程式的執行
        }
	    int i = 0 ;
		int j = 0 ;

		while ( output_counter < size+1 ) {
	      file << output_counter << "\n" ;
	      i = 0 ;
	      j = 0 ;
		  while( i < 4 ){

		    while(j < 4){

				  file << sudoku[output_counter-1].getnum(i,j) << " " ;
			      j++ ;
			}
			  if(j == 4) {
			    j = 0 ;
			    file << "\n" ;
			  }
			i++ ;
		  }
		  output_counter++ ;
	    }
	    file << "-1" ;
} // 輸出寫檔
void readfile(){
	int count = 0 ;
	int num ;
	ifstream fin("sudoku.txt");
    if(!fin) {
        cout << "無法讀入檔案\n";
        exit(1);

    }
    fin >> count ;
    while(count != -1) {
      for(int i=0;i<4;i++) {
    	for(int j=0;j<4;j++) {
    	  fin >> num ;
    	  sudoku[count-1].change(i,j,num) ;
		}
	  }
	  size++ ;
	  fin >> count ;
	}

    fin.close();

} //讀檔
void practice(){

  Sudoku ans ;
  Sudoku question ;
  srand(time(NULL)) ;
  int level = 0 ;
  int target = 0 ;
  char cnum[200] ;
  if(size == 1) {

  	target = 0 ;
  }
  else{
  	 target = rand() % size;
  }
  question = sudoku[target] ;

  cout << endl << "************* 難度選單 ************";
  cout << endl << "* 1. 初級迷你數獨                 *";
  cout << endl << "* 2. 高級迷你數獨                 *";
  cout << endl << "***********************************";
  cout << "\n請重新輸入難度:" ;
  cin >> cnum ;
  if (check(cnum) )
    level = atoi(cnum) ; //嘗試讀取操作指令
  while (  level != 1 && level != 2 ) {
  	cout << "請重新新輸入:" ;
    cin >> cnum ;
    if (check(cnum) )
      level = atoi(cnum) ; //嘗試讀取操作指令
  }
  BlankSpace(question,level) ;
  ans = question ;
  int i = 0 ;
  int j = 0 ;
  int num = 0 ;

  while( !Sudoku_equal(sudoku[target],ans)  ){
  ans = question ;
  do{
  ans.print() ;
  cout << "請輸入想填的行數:" ;
  cin >> cnum ;
    if (check(cnum) )
      i = atoi(cnum) ; //嘗試讀取操作指令
  while ( i < 1 || i > 4) {
  	cout << "超出範圍請重新輸入\n" ;
  	cout << "請輸入想填的行數:";
    cin >> cnum ;
    if (check(cnum) )
      i = atoi(cnum) ; //嘗試讀取操作指令
  }

  cout << "請輸入想填的列數:";
  cin >> cnum ;
    if (check(cnum) )
      j = atoi(cnum) ; //嘗試讀取操作指令;
  while ( j < 1 || j > 4) {
  	cout << "超出範圍請重新輸入\n" ;
  	cout << "請輸入想填的列數";
    cin >> cnum ;
    if (check(cnum) )
      j = atoi(cnum) ; //嘗試讀取操作指令
  }
  if(question.getnum(i-1,j-1 )== 0 ){
  	cout << "請輸入想填之數字:" ;
  	cin >> num ;
  	ans.change(i-1,j-1,num) ;
  }
  else {
  	cout << "非可填之格數\n";
  }
  }while( ans.zero() != 0 ) ;
    if (!Sudoku_equal(sudoku[target],ans)) {
    	cout << "答案有誤再試一次吧~\n" ;
	}
  } //判斷跟答案一不一樣

  ans.print() ;
  cout << "恭喜答對!!\n" ;

}

Person person ;

void outputrank() {
	    fstream file;

        file.open("rank.txt", ios::out);      //開啟檔案
        if(!file)     //檢查檔案是否成功開啟
        {
                cout << "無法讀入檔案\n";
                exit(1);     //在不正常情形下，中斷程式的執行
        }
	    int i = 0 ;


		while ( i < 5 ) {
			file << rank[i].pname << " "<< rank[i].high << " "<< rank[i].time << endl ;
			i++ ;
	    }
	    file << "-1" ;
} // 排行榜寫檔

void readrank(){
	int count = 0 ;
	int num ;
	ifstream fin("rank.txt");
    if(!fin) {
        cout << "無法讀入檔案\n";
        exit(1);

    }
    while(count < 5){
    	fin >> rank[count].pname >> rank[count].high >> rank[count].time ;
    	count++ ;
	}
	fin.close();

} //排行榜讀檔

void ranklist( Person person ) {

    bool over = false ;
    int num = 0 ;
    for( int i = 0 ; i < 5 ; i++ ) {
      if ( rank[i].high <= person.getscore()) {
        over = true ;
        num = i ;
        break;
      }
    }

     if (over) {
       if (num == 4) {
        rank[num].pname = person.getname() ;
        rank[num].high = person.getscore() ;
        rank[num].time = person.gettime() ;
       }
      else {
         for ( int i = 3 ; i >= num ; i-- ){
            rank[i+1] = rank[i] ;
            if ( i == num ) {
              rank[num].pname = person.getname() ;
              rank[num].high = person.getscore() ;
              rank[num].time = person.gettime() ;
            }
         }

        }

     }

 }

void play() {
  Sudoku ans ;
  Sudoku question ;
  srand(time(NULL)) ;
  int time1 = 0 ;
  int time2 = 0 ;
  int level = 1 ;
  int target1 = 0 ;
  int target2 = 0 ;
  char cnum[200] ;
  int s1 = 0 ;
  int s2 = 0;

  if(size == 1) {

  	target1 = 0 ;
  	target2 = 0 ;
  }
  else{
  	 target1 = rand() % size;
  	 target2 = target1 ;
     while (target1 == target2 )
        target2 = rand() % size;
  }

  int target = target1 ;
   for (int k = 0 ; k < 2 ; k++ ){
   time1 = time2 ;
   s1 = s2 ;
   question = sudoku[target] ;


  int t1 = time(NULL) ;
  BlankSpace(question,level) ;
  ans = question ;
  int i = 0 ;
  int j = 0 ;
  int num = 0 ;

  while( !Sudoku_equal(sudoku[target],ans)  ){
  ans = question ;
  do{
  ans.print() ;
  cout << "請輸入想填的行數:" ;
  cin >> cnum ;
    if (check(cnum) )
      i = atoi(cnum) ; //嘗試讀取操作指令
  while ( i < 1 || i > 4) {
  	cout << "超出範圍請重新輸入\n" ;
  	cout << "請輸入想填的行數:";
    cin >> cnum ;
    if (check(cnum) )
      i = atoi(cnum) ; //嘗試讀取操作指令
  }

  cout << "請輸入想填的列數:";
  cin >> cnum ;
    if (check(cnum) )
      j = atoi(cnum) ; //嘗試讀取操作指令;
  while ( j < 1 || j > 4) {
  	cout << "超出範圍請重新輸入\n" ;
  	cout << "請輸入想填的列數:";
    cin >> cnum ;
    if (check(cnum) )
      j = atoi(cnum) ; //嘗試讀取操作指令
  }
  if(question.getnum(i-1,j-1 )== 0 ){
  	cout << "請輸入想填之數字:" ;
  	cin >> num ;
  	ans.change(i-1,j-1,num) ;
  }
  else {
  	cout << "非可填之格數\n";
  }
  }while( ans.zero() != 0 ) ;
    if (!Sudoku_equal(sudoku[target],ans)) {
    	cout << "答案有誤再試一次吧~\n" ;
	}
  } //判斷跟答案一不一樣
  int t2 = time(NULL) ;
  ans.print() ;
  time2 = t2 - t1 ;
  s2 = (1000 * ( k +1 ) ) - time2 ;
  cout << "時間:" << time2 << "秒\n" ;
  cout << "分數:" << s2 * 2<< "分\n" ;
  cout << "恭喜答對!!\n" ;
  level = 2 ;
  target = target2 ;

  }
  int tottime = time1 + time2 ;
  int tots = (s1+s2)*2 ;
  cout << "共用時間:" << tottime << "秒\n" ;
  cout << "共取得:" << tots << "分\n" ;
  person.changescore( tots ) ;
  person.changehigh() ;
   ranklist(person);
}
void admin() {

  int command ;
  do {
    cout << endl << "************* 指令選單 ************";
    cout << endl << "* 0. 結束程式                     *";
    cout << endl << "* 1. 增加迷你數獨                 *";
    cout << endl << "* 2. 刪除迷你數獨                 *";
    cout << endl << "* 3. 顯示迷你數獨                 *";
    cout << endl << "***********************************";
    cout << endl << "請輸入指令(0, 1-3): ";


    char num[200] ;
    cin >> num ;
    if (check(num) ){
      command = atoi(num) ; //嘗試讀取操作指令
      if(command == 1 ) {
        makeminisudo() ;
      } // case1
      else if(command == 2 ) {
        deleteSudoku() ;
      } // case2
      else if(command == 3 ) {
        Print() ;
      } // case3
      else if(command == 0  ){
      	cout << "更改結束!\n" ;
        outputfile() ;
      }
      else{
    	cout << endl << "指令不存在!" << endl;
      } // illegal
    } // if
    else cout << endl << "指令不存在!" << endl;
  } while( command != 0 ) ;
} //admin

void printhigh(){
	cout << "最高取得" << person.gethigh() << "分" << endl ;
}

void printrank() {
  int i = 0 ;
  cout << "姓名    分數    時間    \n" ;
  while ( i < 5 ) {
    cout << "" << rank[i].pname << "   "<< rank[i].high << "     "<< rank[i].time << endl ;
    i++ ;
  }
}

void guest() {
  readrank() ;
  cout << "歡迎來玩迷你數獨  " << name << endl ;
  person.changename() ;
  int command = 0 ;
  do{
    cout << endl << "*************** MENU **************";
    cout << endl << "* 0.結束程式                      *";
    cout << endl << "* 1.練習                          *";
    cout << endl << "* 2.闖關                          *";
    cout << endl << "* 3.觀看本次最高得分              *";
    cout << endl << "* 4.觀看排行榜                    *";
    cout << endl << "***********************************\n";
    cout << endl << "請輸入指令(0, 1-4): ";


    char num[200] ;
    cin >> num ;
    if (check(num) ){
      command = atoi(num) ; //嘗試讀取操作指令
      if(command == 1 ) {
        practice() ;
      } // case1
      else if(command == 2 ) {
        play();
      } // case2
      else if(command == 3 ) {
        printhigh() ;
      } // case3
      else if(command == 4 ) {
        printrank() ;
      } // case3
      else if(command == 0  ){
        outputrank() ;
      	cout << "感謝使用!\n" ;
      }
      else{
    	cout << endl << "指令不存在!" << endl;
      } // illegal
    } // if
    else cout << endl << "指令不存在!" << endl;
  } while( command != 0 ) ;

}
int main(int argc, char** argv) {
  cout << endl << "*************** MENU **************";
  cout << endl << "* 歡迎來玩                        *";
  cout << endl << "*         迷          1 2 3 4     *";
  cout << endl << "*           你        3 4 1 2     *";
  cout << endl << "*             數      2 1 4 3     *";
  cout << endl << "*               獨    4 3 2 1     *";
  cout << endl << "***********************************\n";
  readfile() ;
  cout << "請輸入您的名稱:" ;
  cin >> name ;
  if (name == "admin") {
  	admin() ;
  }
  else {
  	guest() ;
  }




  system("Pause") ;

}
