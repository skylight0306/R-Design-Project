// 10327247 ��һ�� 10327271 ���뿵  ��8�M

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
	  } // �Q����

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



	} // ��ʼ��

void print(){
      for( int i = 0 ; i < 4 ; i++ ){
        if ( i != 2 ) cout << "\n  ______________\n " ;
        else cout << "\n  ==============\n " ;
        for( int j = 0 ; j < 4 ; j++ ){
            if( sudoku[i][j] != 0) {
                cout << "��" << sudoku[i][j]  ;
                if (j == 1) cout << "��" ;
                if ( j == 3 ) cout << "��" ;
            }
            else {
                cout << "��" <<" "  ;
                if (j == 1) cout << "��" ;
                if ( j == 3 ) cout << "��" ;
            }
        }
      }

        cout << "\n  ______________\n" ;

} //ӡ



	void checkColumns() {

	} // �_�Jֱ���Ƿ����Ҏ�t
	void checkLines(){

	} //	�_�J�M���Ƿ����Ҏ�t

	void checkGung(){

	} // �_�J�m�Ƿ����Ҏ�t

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
	cout << "��h���ڎׂ����㔵��?\n" ;
	cin >> num ;

	if( num < 0 || num > 50 || num >= size+1 ){
		cout << "�˔���������" ;
	}
	else {
		if( size == 1 && num == 1 ){
			size = 0 ;
		} // ֻ��һ��
		else if( num == size ){
			sudoku[size-1].initialize() ;
			size = size - 1 ;
		} // �h��β��
		else{
			int count = 0 ;
			count = num ;
			while ( count < size) {
				sudoku[count-1] = sudoku[count] ;
				count++ ;
			}
			sudoku[size-1].initialize() ;
			size = size - 1 ;

		} // �h�����g
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
	    }    // �}�u�M�������Y��
        for ( int j = 0 ; j < 4-1 ; j++ ){
          temp = str[j] ;
          str[j] = str[j+1] ;
          str[j+1] = temp ;
        } // for
      } // for
      for ( int i = 0 ; i < 4 ; i++ ) {                     // �ѵڶ��к͵����л��Q
       temp = sudoku.getnum(1,i) ;
       sudoku.change(1,i,sudoku.getnum(2,i)) ;
       sudoku.change(2,i,temp) ;
      } // for

 } // create
 int random(){         // 1~4�āy��
 str[0] = 0;
 str[1] = 0;
 str[2] = 0;
 str[3] = 0;
 int temp = 0 ;
 bool next = false ;
 unsigned seed;
 seed = (unsigned)time(NULL);             // ȡ�Õr�g����
 srand(seed);                            // �ԕr�g���Ю��y���N�� (�@��ÿ���_temp�ŕ���ͬ)
 for (int i = 0 ; i < 4 ; i++ ) str[i] = 0 ;                 // strҪ��ʼ��
 for (int i = 0 ; i < 4 ; i++ ) {
   while ( next == false ) {
     temp = rand() % 4 + 1 ;                          // �Ԅ�����1~4�āy��
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
	  } // ��һ��
	  else {
	  	int count = 0 ;
	  	bool again = false ;
	  	while(count < size){
	  		if(Sudoku_equal( newone,sudoku[count])){
	  			again = true ;
			  } // �Д��Л]�����}
			  count++ ;
		  } //ȥ��ÿһ�����^
	  	  if (!again) {
	  	  	  sudoku[size] = newone ;
              size++ ;
			}
	  } //�����Д��Л]���c֮ǰ���}

	  cout << "�Ƿ���Ҫ�@ʾ?(Y/N)" ;
	  char a;
	  cin >> a ;
	  if (a == 'y') {
	  	newone.print() ;
	  }
	  else if ( a == 'n'){
	  	return ;
	  }
	  else{
	  	cout << "ָ�����" ;
	  }
}
void Print(){
	int num ;
	cout << size << "�뿴�ڎׂ����㔵��?\n" ;

	cin >> num ;

	if( num <= 0 || num > 50 || num > size ){
		cout << "�˔���������" ;
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
        int j = rand() % 4 ;               // �Ԅ�����y��
        int i = rand() % 4 ;
        if( sudoku.getnum( i, j ) != 0 ) {       // ���ǿհ�
          sudoku.change( i ,j ,0 ) ;             // �Q�ɿհ�
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

        file.open("sudoku.txt", ios::out);      //�_���n��
        if(!file)     //�z��n���Ƿ�ɹ��_��
        {
                cout << "�o���x��n��\n";
                exit(1);     //�ڲ����������£��Д��ʽ�Ĉ���
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
} // ݔ�����n
void readfile(){
	int count = 0 ;
	int num ;
	ifstream fin("sudoku.txt");
    if(!fin) {
        cout << "�o���x��n��\n";
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

} //�x�n
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

  cout << endl << "************* �y���x�� ************";
  cout << endl << "* 1. �������㔵��                 *";
  cout << endl << "* 2. �߼����㔵��                 *";
  cout << endl << "***********************************";
  cout << "\nՈ����ݔ���y��:" ;
  cin >> cnum ;
  if (check(cnum) )
    level = atoi(cnum) ; //�Lԇ�xȡ����ָ��
  while (  level != 1 && level != 2 ) {
  	cout << "Ո������ݔ��:" ;
    cin >> cnum ;
    if (check(cnum) )
      level = atoi(cnum) ; //�Lԇ�xȡ����ָ��
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
  cout << "Ոݔ��������Д�:" ;
  cin >> cnum ;
    if (check(cnum) )
      i = atoi(cnum) ; //�Lԇ�xȡ����ָ��
  while ( i < 1 || i > 4) {
  	cout << "��������Ո����ݔ��\n" ;
  	cout << "Ոݔ��������Д�:";
    cin >> cnum ;
    if (check(cnum) )
      i = atoi(cnum) ; //�Lԇ�xȡ����ָ��
  }

  cout << "Ոݔ��������Д�:";
  cin >> cnum ;
    if (check(cnum) )
      j = atoi(cnum) ; //�Lԇ�xȡ����ָ��;
  while ( j < 1 || j > 4) {
  	cout << "��������Ո����ݔ��\n" ;
  	cout << "Ոݔ��������Д�";
    cin >> cnum ;
    if (check(cnum) )
      j = atoi(cnum) ; //�Lԇ�xȡ����ָ��
  }
  if(question.getnum(i-1,j-1 )== 0 ){
  	cout << "Ոݔ������֮����:" ;
  	cin >> num ;
  	ans.change(i-1,j-1,num) ;
  }
  else {
  	cout << "�ǿ���֮��\n";
  }
  }while( ans.zero() != 0 ) ;
    if (!Sudoku_equal(sudoku[target],ans)) {
    	cout << "�����`��ԇһ�ΰ�~\n" ;
	}
  } //�Д����һ��һ��

  ans.print() ;
  cout << "��ϲ����!!\n" ;

}

Person person ;

void outputrank() {
	    fstream file;

        file.open("rank.txt", ios::out);      //�_���n��
        if(!file)     //�z��n���Ƿ�ɹ��_��
        {
                cout << "�o���x��n��\n";
                exit(1);     //�ڲ����������£��Д��ʽ�Ĉ���
        }
	    int i = 0 ;


		while ( i < 5 ) {
			file << rank[i].pname << " "<< rank[i].high << " "<< rank[i].time << endl ;
			i++ ;
	    }
	    file << "-1" ;
} // ���а񌑙n

void readrank(){
	int count = 0 ;
	int num ;
	ifstream fin("rank.txt");
    if(!fin) {
        cout << "�o���x��n��\n";
        exit(1);

    }
    while(count < 5){
    	fin >> rank[count].pname >> rank[count].high >> rank[count].time ;
    	count++ ;
	}
	fin.close();

} //���а��x�n

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
  cout << "Ոݔ��������Д�:" ;
  cin >> cnum ;
    if (check(cnum) )
      i = atoi(cnum) ; //�Lԇ�xȡ����ָ��
  while ( i < 1 || i > 4) {
  	cout << "��������Ո����ݔ��\n" ;
  	cout << "Ոݔ��������Д�:";
    cin >> cnum ;
    if (check(cnum) )
      i = atoi(cnum) ; //�Lԇ�xȡ����ָ��
  }

  cout << "Ոݔ��������Д�:";
  cin >> cnum ;
    if (check(cnum) )
      j = atoi(cnum) ; //�Lԇ�xȡ����ָ��;
  while ( j < 1 || j > 4) {
  	cout << "��������Ո����ݔ��\n" ;
  	cout << "Ոݔ��������Д�:";
    cin >> cnum ;
    if (check(cnum) )
      j = atoi(cnum) ; //�Lԇ�xȡ����ָ��
  }
  if(question.getnum(i-1,j-1 )== 0 ){
  	cout << "Ոݔ������֮����:" ;
  	cin >> num ;
  	ans.change(i-1,j-1,num) ;
  }
  else {
  	cout << "�ǿ���֮��\n";
  }
  }while( ans.zero() != 0 ) ;
    if (!Sudoku_equal(sudoku[target],ans)) {
    	cout << "�����`��ԇһ�ΰ�~\n" ;
	}
  } //�Д����һ��һ��
  int t2 = time(NULL) ;
  ans.print() ;
  time2 = t2 - t1 ;
  s2 = (1000 * ( k +1 ) ) - time2 ;
  cout << "�r�g:" << time2 << "��\n" ;
  cout << "�֔�:" << s2 * 2<< "��\n" ;
  cout << "��ϲ����!!\n" ;
  level = 2 ;
  target = target2 ;

  }
  int tottime = time1 + time2 ;
  int tots = (s1+s2)*2 ;
  cout << "���Õr�g:" << tottime << "��\n" ;
  cout << "��ȡ��:" << tots << "��\n" ;
  person.changescore( tots ) ;
  person.changehigh() ;
   ranklist(person);
}
void admin() {

  int command ;
  do {
    cout << endl << "************* ָ���x�� ************";
    cout << endl << "* 0. �Y����ʽ                     *";
    cout << endl << "* 1. �������㔵��                 *";
    cout << endl << "* 2. �h�����㔵��                 *";
    cout << endl << "* 3. �@ʾ���㔵��                 *";
    cout << endl << "***********************************";
    cout << endl << "Ոݔ��ָ��(0, 1-3): ";


    char num[200] ;
    cin >> num ;
    if (check(num) ){
      command = atoi(num) ; //�Lԇ�xȡ����ָ��
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
      	cout << "���ĽY��!\n" ;
        outputfile() ;
      }
      else{
    	cout << endl << "ָ�����!" << endl;
      } // illegal
    } // if
    else cout << endl << "ָ�����!" << endl;
  } while( command != 0 ) ;
} //admin

void printhigh(){
	cout << "���ȡ��" << person.gethigh() << "��" << endl ;
}

void printrank() {
  int i = 0 ;
  cout << "����    �֔�    �r�g    \n" ;
  while ( i < 5 ) {
    cout << "" << rank[i].pname << "   "<< rank[i].high << "     "<< rank[i].time << endl ;
    i++ ;
  }
}

void guest() {
  readrank() ;
  cout << "�gӭ�������㔵��  " << name << endl ;
  person.changename() ;
  int command = 0 ;
  do{
    cout << endl << "*************** MENU **************";
    cout << endl << "* 0.�Y����ʽ                      *";
    cout << endl << "* 1.����                          *";
    cout << endl << "* 2.�J�P                          *";
    cout << endl << "* 3.�^��������ߵ÷�              *";
    cout << endl << "* 4.�^�����а�                    *";
    cout << endl << "***********************************\n";
    cout << endl << "Ոݔ��ָ��(0, 1-4): ";


    char num[200] ;
    cin >> num ;
    if (check(num) ){
      command = atoi(num) ; //�Lԇ�xȡ����ָ��
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
      	cout << "���xʹ��!\n" ;
      }
      else{
    	cout << endl << "ָ�����!" << endl;
      } // illegal
    } // if
    else cout << endl << "ָ�����!" << endl;
  } while( command != 0 ) ;

}
int main(int argc, char** argv) {
  cout << endl << "*************** MENU **************";
  cout << endl << "* �gӭ����                        *";
  cout << endl << "*         ��          1 2 3 4     *";
  cout << endl << "*           ��        3 4 1 2     *";
  cout << endl << "*             ��      2 1 4 3     *";
  cout << endl << "*               ��    4 3 2 1     *";
  cout << endl << "***********************************\n";
  readfile() ;
  cout << "Ոݔ���������Q:" ;
  cin >> name ;
  if (name == "admin") {
  	admin() ;
  }
  else {
  	guest() ;
  }




  system("Pause") ;

}
