/*
資料結構第二次作業 
資訊工程二年乙班
林函緯 10327216
黃朝玄 10327207 
*/

#include <iostream>
#include <stdio.h> 
#include <string>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct allS {                                                           // 用來儲存迷你數獨的題目 
    string save;
} allS;

typedef struct allAS {                                                          // 用來儲存標準數獨的題目 
    string pro;
    string ans;
} allAS;

typedef struct SB {                                                             // 用來儲存迷你數獨的記分板 
    string score;
} SB;

typedef struct ASB {                                                            // 用來儲存標準數獨的記分板
    string name; 
    string score;
} ASB;

vector<SB> ScoreBoard;                                                          // 記分板陣列 

vector<ASB> AScoreBoard;                                                        // 同上 

class AllOthers {
    string int2str( int &i ) {                                                  // 將數字轉字串以便儲存及比較 
        string s;
        stringstream ss(s);
        ss << i;
        return ss.str();
    }

    public:string db2str( double &i ) {                                         // 將小數轉字串以便儲存 
        string s;
        stringstream ss(s);
        ss << i;
        return ss.str();
    }
    
    public:void Convert(string itemp, string &otemp, int &FTC1, int &FTC2, int &STC1, int &STC2 ) {
        otemp = itemp.substr(0, 16);                                            // 將儲存的題目轉成方便顯示的格式 
        FTC1 = itemp[16] - '0';
        FTC2 = itemp[17] - '0';
        STC1 = itemp[18] - '0';
        STC2 = itemp[19] - '0';
    }
    
    public:void CreateOneSudoku(allS &save) {                                   //新增題型_________
        save.save = ""; 
	    int a[4][4] = {0},aline=0,bline=0,num=0,num1 = 0,num2 = 0;              // aline代表縱列，bline代表橫列 ，a[1][2]代表縱列為1橫列為2的那個數字 ,num1,num2為跑回圈所需的變數工具
        int FTC1, FTC2, STC1, STC2;                                             // FTC等等的是用來挖空格做為題目用的，用來紀錄挖的位置 
        srand((unsigned)time(NULL));                                            // 以時間序列當亂數種子	 
	    int number ;                                                            // 讀取亂數的變數 
	    int atrue = 0,btrue = 0,abtrue = 0;                                     // 判斷行，列，方格內是否有重複的數字 
	    int runtime=0;                                                          // runtime為迴圈跑的次數 
	    FTC1 = rand()%4 ;                                                       // 為挖空格所需的亂數摻數 
	    FTC2 = rand()%4 ;
	    STC1 = rand()%4 ;
	    STC2 = rand()%4 ;
	    while(STC1==FTC1&&STC2==FTC2){                                          // 如果挖到同一個格就重挖 
			STC1 = rand()%4 ;
	        STC2 = rand()%4 ;
        }
	    while(aline < 4){                                                       //當超過第4行的時候就停止 
		    while(a[aline][bline] == 0 ){                                       //當這個陣列裡的數為0時，就一直重複做這事 
	  	        number = rand()%4 + 1;                                          //讀取變數 
		        while(num<4){
			        if(number == a[aline][num])                                 //判斷同一行裡的數字是否有重複 
			            atrue = 1;                                              //是的話就等於1
                    if(number == a[num][bline])                                 //判斷同一列裡的數字是否有重複  
			            btrue = 1;
                    while(num1 < 4){                                            //判斷角落方格裡是否有重複的數
			            if(aline/2 == num1/2 ){                                 //把左右方格屬於同一邊找出來 
			     	        while(num2 < 4){                 
				                if(bline/2 == num2/2)                           //把上下方格屬於同一邊找出來  
			                        if(number == a[num1][num2])
				                        abtrue = 1;                             //進到這裡代表四個角落裡有重複數字 
                                num2++;
	                        }
			                num2=0;
		                }
				        num1++;
		            }
		            num1 = 0;
			        num++;
	            }
		        if(!atrue && !btrue && !abtrue){                                //當判斷都為否時代表上述三種規則都符合，因此把number存在陣列裡 
		  	        a[aline][bline] =number;
		  	        runtime = 0;
		        }
		        else
		            runtime++;
 	            atrue =0;
	 	        btrue=0;
  	            abtrue=0;
                num=0;
	            if(runtime>=100){                                               //如果同一格數找了100遍都沒結果，代表能用的數字有很大機率都被用完了，因此重新找這行 
		            for(int i = 0;i<4;i++)
		                a[aline][i] = 0;
		            bline = 0;
		            runtime = 0;
	            }
		    }
		    bline++;
		    if(bline>=4){                                                       //代表現在這行已經填滿4個數字了，要換下一行了 
			    aline++;
			    bline = 0; 
		    }
	    }
	    int i = 0;
	    string t;
	    for ( aline = 0 ; aline < 4 ; aline++ )                                 // 存成字串方便存檔 
            for ( bline = 0, t = "" ; bline < 4 ; bline++, t = "" ) {
                t = int2str(a[aline][bline]);
                save.save += t;
            }
        t = int2str(FTC1);                                                      //存進一個字串中 
        save.save += t;
        t = int2str(FTC2);
        save.save += t;
        t = int2str(STC1);
        save.save += t;
        t = int2str(STC2);
        save.save += t;
    }
    
    public:void DisplayOneSudokuProblem(string iSave) {                         //顯示一個題型 
        int a[4][4] = {0}, FTC1, FTC2, STC1, STC2;
        string oSave;
        Convert( iSave, oSave, FTC1, FTC2, STC1, STC2 );
        for(int y = 0, i = 0; y < 4 ; y++ )                                     //將所儲存的數獨從字串型式轉回陣列型式 
            for( int z = 0 ; z < 4 ; z++, i++ )
                a[y][z] = oSave[i] - '0';
	    for(int i =0;i<4;i++){                                                  //把預先選好的位置遮住 
		    for(int q=0;q<4;q++){
			    if(i == FTC1 && q == FTC2 )
		  	        printf(" x");
		  	    else if(i == STC1 && q == STC2 )
		  	        printf(" y");
		  	    else
			        printf(" %d",a[i][q]);
		    }
		    printf("\n");
	    }
    }

    public:void DisplayAllSudokuProblem( vector<allS> sSet ) {                  // 顯示題庫中所有題型 
        int i = 0;
        for (vector<allS>::iterator it = sSet.begin(); it < sSet.end(); ++it) {
            cout << "( " << ++i << " )\n";
            DisplayOneSudokuProblem( it->save );
            cout << "\n";
        }
    }
};

class PracticeModeProcess {                                                     // 與題庫、練習有關的FUNCTION集中在這個CLASS 
    AllOthers Ins;
    public:void ReadSavedProblem( vector<allS> &sSet) {                         // 讀取題庫檔 
        fstream inFile;
        string fileName = "SavedProblem.txt";
        char temp[21];
        inFile.clear();
        inFile.open( fileName.c_str(), fstream::in );
        if ( inFile.is_open() ) {
            while ( inFile.getline( temp, 21, '\n' ) ) {
                string temps;
                allS ftemp;
                temps.assign(temp);
                ftemp.save = temps.substr(0, 20);
                sSet.push_back(ftemp);                                          // 讀到之後存進題庫陣列 
            }
            inFile.close();
        }
    }
    
    public:void OutputProblem( vector<allS> sSet ) {                            // 將題庫寫檔 
        ofstream outFile;
        string fileName = "SavedProblem.txt";
        outFile.open(fileName.c_str(), fstream::out);
        for (vector<allS>::iterator it = sSet.begin(); it < sSet.end(); it++) {
            outFile << it->save << endl;
        }
    }
    
    public:void SaveProblem( vector<allS> &sSet, allS temp ) {                  // 將一個題目存入題庫陣列中 
        sSet.push_back(temp);
    }

    public:bool CheckIfItExist( vector<allS> sSet, string temp ) {              //檢查一個題目是否已經在題庫陣列中 
        bool check = false;
        for (vector<allS>::iterator it = sSet.begin(); it < sSet.end(); it++) {
            if ( it->save.compare(temp) == 0 )
                check = true;
        }
        return check;
    }

    public:void DeleteOneSudokuProblem( vector<allS> &sSet, int i ) {           // 刪除題庫中第i題 
        sSet.erase( sSet.begin() + i );
    }

    void PracticeWrite( string it, bool &quit){                                 // 練習模式 
        string oSave;
        int FTC1, FTC2, STC1, STC2;
        Ins.Convert( it, oSave, FTC1, FTC2, STC1, STC2 );                       // 將圖目字串轉成方便顯示的格式 
        Ins.DisplayOneSudokuProblem( it );                                      // 顯示一題 
        int ans1, ans2, i = 0, j = 0;
        ans1 = oSave[FTC1*4+FTC2] - '0';
        ans2 = oSave[STC1*4+STC2] - '0';
        cout << " x=";                                                          // 開始作答 
        cin >> i;
        if( i != 0 ){
            cout << " y=";
            cin >> j;
            if ( j != 0 ) {
                while ( i != ans1 || j != ans2 ) {
                    cout << "你答錯了!請重新作答\n x=";
                    cin >> i;
                    if( i == 0 ) {
                        quit = true;
                        break;
                    }
                    cout << " y=";
                    cin >> j;
                    if( j == 0 ) {
                        quit = true;
                        break;
                    }
                }
                if ( !quit )
                    cout << "你答對了!\n";
            }
            else
                quit = true;
        }
        else
            quit = true;
    }

    public:void Practice( vector<allS> sSet ) {                                 // 在練習模式跑過題庫中每一題 
        bool quit = false;
        cout << "如要離開練習模式請輸入'0'\n"; 
        for (vector<allS>::iterator it = sSet.begin(); it < sSet.end() && !quit; it++) {
            PracticeWrite( it->save, quit );
        }
    }
};

class StandardModeProcess {                                                     // 闖關模式有關的FUNCTION集中在此CLASS 
    AllOthers Ins;
    public:void SaveScore( double timeUsed ) {                                  // 將一次分數存入全域記分板中 
        SB ftemp;
        ftemp.score = Ins.db2str( timeUsed );
        ScoreBoard.push_back(ftemp);
    }

    public:void Standard() {                                                    // 闖關模式 
        int x = 1;
        clock_t t1, t2;
        allS temp;
        int a[4][4] = {0}, FTC1, FTC2, STC1, STC2, ans1 = 0, ans2 = 0;
        string problem;
        t1 = clock();
        while ( x < 5 ) {
            Ins.CreateOneSudoku(temp);
            Ins.Convert( temp.save, problem, FTC1, FTC2, STC1, STC2 );
            for(int y = 0, i = 0; y < 4 ; y++ )                                 //將所儲存的數獨從字串型式轉回陣列型式 
                for( int z = 0 ; z < 4 ; z++, i++ )
                    a[y][z] = problem[i] - '0';
            cout << " (" << x << ")\n";
            for(int i =0;i<4;i++){                                              //把預先選好的位置遮住 
                for(int q=0;q<4;q++){                                           // 以下同練習模式 
                    if(i == FTC1 && q == FTC2 ) 
		  	            printf(" x");
		  	        else if(i == STC1 && q == STC2 && x > 2 )
		  	            printf(" y");
		  	        else
			            printf(" %d",a[i][q]);
		        }
		        printf("\n");
	        }
	        cout << " x=";
	        cin >> ans1;
	        if ( x > 2 ) {                                                      // 闖關模式因為必須有難度差別，因此前兩題挖的空格較少，後兩題才開放第二空格 
                cout << " y=";
                cin >> ans2;
            }
            while ( ans1 != a[FTC1][FTC2] || (ans2 != a[STC1][STC2] && x > 2 ) ) {
	            cout << "你答錯了，請重新作答!\n x=";
	            cin >> ans1;
	            if ( x > 2 ) {
                    cout << " y=";
                    cin >> ans2;
                }
            }
            cout << "你答對了!\n"; 
            x++;
        }
        t2 = clock();
        cout << "恭喜作答完成!! 耗時:" << double(t2 - t1)/CLOCKS_PER_SEC << "秒" << endl;
        SaveScore( double(t2 - t1)/CLOCKS_PER_SEC );
    }

    public:void ReadScoreboard() {                                              // 讀取記分板檔案 
        fstream inFile;
        string fileName = "Scoreboard.txt";
        string temp;
        inFile.clear();
        inFile.open( fileName.c_str(), fstream::in );
        if ( inFile.is_open() ) {
            while( getline(inFile, temp) ) {
                SB ftemp;
                ftemp.score = temp;
                ScoreBoard.push_back(ftemp);
            }
            inFile.close();
        }
    }

    public:void DisplayScoreboard() {                                           // 顯示記分板 
        int c = 0;
        for (vector<SB>::iterator it = ScoreBoard.begin(); it < ScoreBoard.end(); it++) {
            cout << "(" << ++c << ") " << it->score << "秒" << endl;
        }
    }

    public:void OutputScoreBoard() {                                            // 將全域記分板變數存檔 
        ofstream outFile;
        string fileName = "Scoreboard.txt";
        outFile.open(fileName.c_str(), fstream::out);
        for (vector<SB>::iterator it = ScoreBoard.begin(); it < ScoreBoard.end(); it++) {
            outFile << it->score << endl;
        }
    }
};

class AdvancedModeProcess {
    vector<allAS> asSet;                                                        //標準數獨題庫 
    allAS temp;                                                                 //暫存題庫中其中一題 
    AllOthers Ins;
    
    void ReadStandardProblemsFile() {                                           //建立9*9數讀題庫 
        allAS ftemp;
        ftemp.pro = "- 1 - - 5 3 7 9 8 7 5 3 1 - 9 - - - - 2 - 4 - 7 - - 3 1 - 4 9 - - - 8 - - 8 - 6 - 4 - 7 - - 6 - - - 8 4 - 2 3 - - 8 - 5 - 6 - - - - 7 - 1 3 5 9 5 9 1 3 4 - - 2 -";
        ftemp.ans = "462824689651372652539197513729146482687";
        asSet.push_back(ftemp);
        ftemp.pro = "3 9 1 4 2 - 6 8 - - - 2 3 - 8 - - 9 6 - 5 - - 9 - - 4 - - - 8 - 6 4 1 5 4 - - - - - - - 3 1 5 9 2 - 3 - - - 8 - - 5 - - 9 - 1 5 - - 9 - 2 8 - - - 7 4 - 8 1 5 3 2";
        ftemp.ans = "577461587132237968157294768263471374696";
        asSet.push_back(ftemp);
        ftemp.pro = "7 6 5 1 2 - 9 4 - 8 1 9 - 6 - - - - - 2 - 8 - - 1 6 5 1 - 6 2 3 - - - 4 - 7 - - - - - 2 - 2 - - - 8 4 6 - 1 5 8 1 - - 2 - 9 - - - - - 5 - 8 7 6 - 3 7 - 4 8 5 1 2";
        ftemp.ans = "3845237349759784851639937567439423169";
        asSet.push_back(ftemp);
        ftemp.pro = "- 8 - - 3 - - 6 - - - 3 - - 1 5 - 2 6 5 - 8 - 9 1 4 3 - 9 5 3 - - - 7 4 - 4 6 - - - 8 9 - 7 2 - - - 4 3 5 - 5 3 7 9 - 2 - 1 8 8 - 4 6 - - 9 - - - 6 - - 1 - - 3 -";
        ftemp.ans = "412579974682718623527181964615327297845";
        asSet.push_back(ftemp);
        ftemp.pro = "- - 3 2 - - - 9 8 - - - 7 - 6 1 3 - 4 - 1 3 8 5 - 2 6 1 - 9 - - 7 4 - - - 4 - 1 - 9 - 8 - - - 7 6 - - 9 - 1 3 1 - 9 7 8 2 - 5 - 7 4 5 - 2 - - - 9 5 - - - 1 8 - -";
        ftemp.ans = "761455289497385626523728435648361924673";
        asSet.push_back(ftemp);
        ftemp.pro = "- - 8 - - - - 7 4 - 9 7 5 4 - 1 2 - 4 2 - 3 - 7 9 5 6 - - 5 - 6 - - 8 - 7 - - 2 - 5 - - 3 - 3 - - 9 - 7 - - 8 1 2 6 - 4 - 9 7 - 6 4 - 7 2 8 3 - 9 7 - - - - 6 - -";
        ftemp.ans = "651293368181473298914626481535591385142";
        asSet.push_back(ftemp);
        ftemp.pro = "- 1 - 2 3 - - 7 - - 2 9 - 1 8 3 - 4 3 - 7 4 9 5 - 6 - - - 4 - - - - 2 - 9 3 - 1 - 2 - 8 5 - 7 - - - - 9 - - - 6 - 5 4 1 7 - 2 7 - 1 8 2 - 5 3 - - 9 - - 6 7 - 4 -";
        ftemp.ans = "456896758211598367674286541383949652318";
        asSet.push_back(ftemp);
        ftemp.pro = "5 - - - 3 4 - - 7 9 - 8 5 - 7 2 - 3 - 7 - - - 9 1 5 4 - - - 1 5 - 9 - - 2 1 5 8 - 3 4 7 6 - - 9 - 7 2 - - - 1 5 4 7 - - - 3 - 8 - 6 3 - 5 7 - 1 7 - - 9 6 - - - 8";
        ftemp.ans = "6128941632684376829684315286994223154";
        asSet.push_back(ftemp);
        ftemp.pro = "- 1 - - 3 - - - - 3 - 5 1 6 9 2 - 8 4 9 - 5 - - - - 3 2 6 3 - 8 - 7 - - 1 4 8 7 - 3 6 2 5 - - 9 - 1 - 3 8 4 6 - - - - 7 - 1 2 5 - 7 8 4 1 9 - 6 - - - - 2 - - 5 -";
        ftemp.ans = "8624579742781645919756234958239813647";
        asSet.push_back(ftemp);
        ftemp.pro = "6 - 8 1 - - - - - 4 1 - 5 - - - 7 3 - 3 - 7 - - 8 1 6 - 6 3 4 - - 9 8 7 8 5 - - - - - 2 4 9 4 2 - - 3 5 6 - 5 2 6 - - 1 - 3 - 3 9 - - - 7 - 4 5 - - - - - 6 1 - 2";
        ftemp.ans = "732459968225941257619387194781286784359";
        asSet.push_back(ftemp);
        ftemp.pro = "- - 1 4 2 - - 6 8 4 6 3 - 8 - 1 - 9 5 - - 6 - 9 4 3 7 - - 7 - - 8 - 9 5 - - - - - - - - - 3 5 - 2 - - 6 - - 8 2 9 1 - 7 - - 6 6 - 5 - 3 - 7 8 4 7 3 - - 5 6 9 - -";
        ftemp.ans = "973575282114362296571843894714351924812";
        asSet.push_back(ftemp);
        ftemp.pro = "3 8 9 - 2 - 6 - 7 - - 2 - 3 - 1 4 9 - - 6 - - - - 2 - 4 1 - - 8 - 7 9 - - 9 3 5 - 6 8 1 - - 6 8 - 4 - - 3 2 - 5 - - - - 9 - - 6 3 7 - 9 - 2 - - 9 - 1 - 6 - 4 7 5";
        ftemp.ans = "145576814759385326274791584217634581283";
        asSet.push_back(ftemp);
        ftemp.pro = "- 3 9 1 - - 6 7 - 1 - 8 - - - 2 - 9 - - 7 - 3 - 1 5 4 - - - 9 5 - 3 1 7 3 9 - 7 - 1 - 4 2 7 1 5 - 2 4 - - - 9 6 2 - 1 - 7 - - 8 - 1 - - - 4 - 3 - 5 3 - - 8 9 6 -";
        ftemp.ans = "5428456736289284668538964385769524271";
        asSet.push_back(ftemp);
        ftemp.pro = "2 - 6 - - 7 - 5 - 4 7 5 - 8 9 3 - 6 9 3 - 5 6 2 - - - - - - - 1 - 4 - 5 1 8 - - - - - 7 3 5 - 7 - 3 - - - - - - - 2 9 3 - 6 4 6 - 2 8 7 - 5 3 9 - 9 - 6 - - 7 - 2";
        ftemp.ans = "134981281473297684925664829175184183541";
        asSet.push_back(ftemp);
        ftemp.pro = "4 - 3 - 2 6 - 7 - - 8 7 3 5 - - 2 - - - 5 8 9 - - 3 4 - 2 - - 4 3 8 9 - - 3 - - - - - 4 - - 4 9 6 8 - - 1 - 3 7 - - 6 2 9 - - - 6 - - 3 1 4 5 - - 5 - 4 7 - 3 - 2";
        ftemp.ans = "915864192176167558219767523458182979186";
        asSet.push_back(ftemp);
        ftemp.pro = "- 5 - 6 - - - 7 - 9 - 4 1 - 2 5 - 6 - 6 3 - 8 4 1 - - - - - - 6 1 - 9 - 4 9 6 3 - 8 2 1 7 - 1 - 2 9 - - - - - - 7 8 1 - 9 4 - 8 - 1 9 - 6 7 - 2 - 4 - - - 3 - 6 -";
        ftemp.ans = "123948873752927843553576846253345597281";
        asSet.push_back(ftemp);
        ftemp.pro = "5 8 2 - - - 9 - 7 - 3 - - 2 7 1 - 5 - - 6 - - 8 2 4 3 - 4 8 1 - - - - 6 - - 7 3 - 5 4 - - 2 - - - - 4 3 7 - 8 1 3 7 - - 6 - - 7 - 4 2 5 - - 3 - 9 - 5 - - - 7 1 4";
        ftemp.ans = "413649681759372596982151968495261892836";
        asSet.push_back(ftemp);
        ftemp.pro = "5 - - - 1 - 7 - 9 1 - - 4 7 - - 5 - 9 - 2 3 - - 4 1 8 6 - - - - - 8 7 4 - 8 7 5 - 4 9 2 - 4 2 1 - - - - - 3 7 9 5 - - 1 3 - 2 - 1 - - 9 5 - - 7 8 - 6 - 3 - - - 5";
        ftemp.ans = "642833892675659123361987566482386447219";
        asSet.push_back(ftemp);
        ftemp.pro = "2 8 3 - - 4 - 7 - 4 - 9 2 3 6 - - 8 6 1 - 7 - 8 - - 2 - - - - 7 - 8 6 5 - 5 - - - - - 9 - 7 9 6 - 4 - - - - 8 - - 5 - 7 - 1 4 9 - - 4 1 2 5 - 3 - 4 - 9 - - 7 2 6";
        ftemp.ans = "156971559341243938621478523132696785183";
        asSet.push_back(ftemp);
        ftemp.pro = "2 7 8 - - - 5 - - 6 9 - 2 - - 1 8 3 - - - - - 9 4 - - 3 - 9 - 7 - 2 - 6 5 8 6 9 - 2 7 3 4 4 - 7 - 6 - 8 - 1 - - 2 3 - - - - - 9 6 5 - - 1 - 4 7 - - 1 - - - 9 2 5";
        ftemp.ans = "134694571536872148512539749561882383746";
        asSet.push_back(ftemp);
    }
    
    public:void ReadStandardScoreboard() {                                      // 讀取標準數讀記分板 
        fstream inFile;
        string fileName = "StandardScoreboard.txt";
        string temp;
        AScoreBoard.clear();
        inFile.clear();
        inFile.open( fileName.c_str(), fstream::in );
        if ( inFile.is_open() ) {
            while( getline( inFile, temp ) ) {
                ASB ftemp;
                ftemp.name = temp;
                temp = "";
                getline ( inFile, temp );
                ftemp.score = temp;
                AScoreBoard.push_back(ftemp);
            }
            inFile.close();
        }
    }
    
    public:void DisplayStandardScoreboard() {                                   // 依照分數高低顯示記分板 
        int c = 0, temppos = 0, cur = 0, total = AScoreBoard.size();
        ASB temp;
        while ( c < total ) { 
            temppos = 0;
            cur = 1;
            temp = AScoreBoard[0];                                              // 先暫存第一組分數 
            for ( vector<ASB>::iterator it = AScoreBoard.begin() + 1; it < AScoreBoard.end(); it++ ) {
                if ( it->score.compare( temp.score ) < 0 ) {                    // 若it分數比剛暫存的還高就讀進去，並且記錄是第幾筆資料 
                    temp.score = it->score;
                    temp.name = it->name;
                    temppos = cur;
                }
                ++cur;
            }
            cout << "(" << ++c << ") " << temp.name << " : " << temp.score << "秒" << endl;
            AScoreBoard.erase( AScoreBoard.begin() + temppos );                 // 輸出之後就從陣列中將剛剛輸出的(剩下的資料中分數最高的)資料刪除 
        }
        ReadStandardScoreboard();                                               // 最後再重新讀入記分板 
    }
    
    void SaveScore( string name, double timeUsed ) {                            // 將一次分數存入記分板陣列中 
        ASB ftemp;
        ftemp.name = name;
        ftemp.score = Ins.db2str( timeUsed );
        AScoreBoard.push_back(ftemp);
    }
    
    void OutputAdvancedScoreboard() {                                           // 將分數存檔 
        ofstream outFile;
        string fileName = "StandardScoreboard.txt";
        outFile.open(fileName.c_str(), fstream::out);
        for (vector<ASB>::iterator it = AScoreBoard.begin(); it < AScoreBoard.end(); it++) {
            outFile << it->name << endl;
            outFile << it->score << endl;
        }
    }
    
    void SelectOneProblemRandomlyAndPrint( int &n ) {                           // 隨機從題庫中選擇一題並且顯示出來 
        ReadStandardProblemsFile();
        srand((unsigned)time(NULL));
        n = rand()%(asSet.size());
        cout << asSet[n].pro.substr( 0, 17 ) << endl;
        cout << asSet[n].pro.substr( 18, 17 ) << endl;
        cout << asSet[n].pro.substr( 36, 17 ) << endl;
        cout << asSet[n].pro.substr( 54, 17 ) << endl;
        cout << asSet[n].pro.substr( 72, 17 ) << endl;
        cout << asSet[n].pro.substr( 90, 17 ) << endl;
        cout << asSet[n].pro.substr( 108, 17 ) << endl;
        cout << asSet[n].pro.substr( 126, 17 ) << endl;
        cout << asSet[n].pro.substr( 144, 17 ) << endl;
        cout << "輸入:";
    }
    
    public:void StartOneGame() {                                                // 標準數獨挑戰模式 
        int n = 0;
        string ans, name;
        clock_t t1, t2;
        cout << "請由左至右，再由上而下填答，且請一次輸入完再按ENTER送出答案\n" << endl;
        SelectOneProblemRandomlyAndPrint( n );
        t1 = clock();
        cin >> ans;
        while ( ans.compare( asSet[n].ans ) != 0 ) {
            cout << "答錯囉! 請重新作答" << endl;
            cout << "輸入:"; 
            ans = "";
            cin >> ans;
        }
        t2 = clock();
        cout << "恭喜作答完成!! 耗時:" << double(t2 - t1)/CLOCKS_PER_SEC << "秒" << endl;
        cout << "請輸入你想留在記分板上的名字:";
        cin >> name;
        SaveScore( name, double(t2 - t1)/CLOCKS_PER_SEC );
        OutputAdvancedScoreboard();
    }
};

int main() {
    AllOthers Ins1;                                                             //宣告CLASSES
    PracticeModeProcess Ins2;
    StandardModeProcess Ins3;
    AdvancedModeProcess Ins4; 
    vector<allS> sSet;                                                          //sSet用來暫存題庫內所有題型 
    allS temp;                                                                  //temp用來暫存單一題型以供使用 
    Ins2.ReadSavedProblem(sSet);                                                //讀取題庫檔案
    Ins3.ReadScoreboard();                                                      //讀取記分板
    Ins4.ReadStandardScoreboard();                                              //讀取標準數獨的計分板 
    int i, j;                                                                   //i用於讀取使用者輸入的指令
    cout << "0. 結束\n1. 管理\n2. 遊戲\n3. 進階模式\n輸入:";                    //接下來即是依照題目所規定的介面設計 
    cin >> i;
    while ( i != 0 ) {
        while ( i == 1 ) {
            cout << "0. 新增題型\n1. 顯示題型\n2. 刪除題型\n3. 回上一頁\n輸入:";
            cin >> j;
            if ( j == 0 ) {
                do {
                    Ins1.CreateOneSudoku(temp);
                } while (Ins2.CheckIfItExist(sSet, temp.save));
                Ins1.DisplayOneSudokuProblem(temp.save);
                Ins2.SaveProblem(sSet, temp);
                cout << "新增完成";
            }
            else if ( j == 1 ) { 
                if ( !sSet.empty() )
                    Ins1.DisplayAllSudokuProblem(sSet);
                else
                    cout << "尚未建立題庫，請新增題型!" << endl;
            } 
            else if ( j == 2 ) {
                cout << "請輸入要刪除的題號:";
                cin >> j;
                if ( j <= sSet.size() && j > 0 ) {
                    Ins2.DeleteOneSudokuProblem( sSet, --j );
                    cout << "刪除完成" << endl;
                } 
                else
                    cout << "查無此題!" << endl;
            }
            else if ( j == 3 )
                break;
            else
                cout << "指令錯誤!" << endl;
        }
        while ( i == 2 ) {
            cout << "0. 練習\n1. 開始闖關\n2. 觀看得分\n3. 回上一頁\n輸入:";
            cin >> j;
            if ( j == 0 ) {
                if ( !sSet.empty() )
                    Ins2.Practice(sSet);
                else
                    cout << "尚未建立題庫，請新增題型!" << endl;
            } 
            else if ( j == 1 ) {
                Ins3.Standard();
                Ins3.OutputScoreBoard();
            }
            else if ( j == 2 ) {
                if ( !ScoreBoard.empty() )
                    Ins3.DisplayScoreboard();
                else
                    cout << "尚未闖過關，請至少玩過一次闖關模式!" << endl;
            }
            else if ( j == 3 )
                break;
            else
                cout << "指令錯誤!" << endl;
        }
        while ( i == 3 ) {
            cout << "此為標準數獨挑戰模式!\n建議準備紙筆作答會比較方便\n0. 開始挑戰\n1. 查看排名\n2. 回上一頁\n輸入:";
            cin >> j;
            if ( j == 0 ) {
                Ins4.StartOneGame();
            }
            else if ( j == 1 ) {
                if ( !AScoreBoard.empty() )
                    Ins4.DisplayStandardScoreboard();
                else
                    cout << "尚未開始過挑戰，請至少玩過一次標準數獨的挑戰模式!" << endl; 
            }
            else if ( j == 2 )
                break;
            else
                cout << "指令錯誤!" << endl;
        }
        if ( i < 0 || i > 3 )
            cout << "指令錯誤!" << endl;
        cout << "0. 結束\n1. 管理\n2. 遊戲:\n3. 進階模式\n輸入:";
        cin >> i;
    }
    if ( !sSet.empty() )
        Ins2.OutputProblem( sSet );
    system("pause");
    return 0;
}
