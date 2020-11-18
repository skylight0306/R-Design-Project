/*
��Ƶ��c�ĤG���@�~ 
��T�u�{�G�~�A�Z
�L��n 10327216
���¥� 10327207 
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

typedef struct allS {                                                           // �Ψ��x�s�g�A�ƿW���D�� 
    string save;
} allS;

typedef struct allAS {                                                          // �Ψ��x�s�зǼƿW���D�� 
    string pro;
    string ans;
} allAS;

typedef struct SB {                                                             // �Ψ��x�s�g�A�ƿW���O���O 
    string score;
} SB;

typedef struct ASB {                                                            // �Ψ��x�s�зǼƿW���O���O
    string name; 
    string score;
} ASB;

vector<SB> ScoreBoard;                                                          // �O���O�}�C 

vector<ASB> AScoreBoard;                                                        // �P�W 

class AllOthers {
    string int2str( int &i ) {                                                  // �N�Ʀr��r��H�K�x�s�Τ�� 
        string s;
        stringstream ss(s);
        ss << i;
        return ss.str();
    }

    public:string db2str( double &i ) {                                         // �N�p����r��H�K�x�s 
        string s;
        stringstream ss(s);
        ss << i;
        return ss.str();
    }
    
    public:void Convert(string itemp, string &otemp, int &FTC1, int &FTC2, int &STC1, int &STC2 ) {
        otemp = itemp.substr(0, 16);                                            // �N�x�s���D���ন��K��ܪ��榡 
        FTC1 = itemp[16] - '0';
        FTC2 = itemp[17] - '0';
        STC1 = itemp[18] - '0';
        STC2 = itemp[19] - '0';
    }
    
    public:void CreateOneSudoku(allS &save) {                                   //�s�W�D��_________
        save.save = ""; 
	    int a[4][4] = {0},aline=0,bline=0,num=0,num1 = 0,num2 = 0;              // aline�N���a�C�Abline�N���C �Aa[1][2]�N���a�C��1��C��2�����ӼƦr ,num1,num2���]�^��һݪ��ܼƤu��
        int FTC1, FTC2, STC1, STC2;                                             // FTC�������O�Ψӫ��Ů氵���D�إΪ��A�ΨӬ���������m 
        srand((unsigned)time(NULL));                                            // �H�ɶ��ǦC��üƺؤl	 
	    int number ;                                                            // Ū���üƪ��ܼ� 
	    int atrue = 0,btrue = 0,abtrue = 0;                                     // �P�_��A�C�A��椺�O�_�����ƪ��Ʀr 
	    int runtime=0;                                                          // runtime���j��]������ 
	    FTC1 = rand()%4 ;                                                       // �����Ů�һݪ��üƺU�� 
	    FTC2 = rand()%4 ;
	    STC1 = rand()%4 ;
	    STC2 = rand()%4 ;
	    while(STC1==FTC1&&STC2==FTC2){                                          // �p�G����P�@�Ӯ�N���� 
			STC1 = rand()%4 ;
	        STC2 = rand()%4 ;
        }
	    while(aline < 4){                                                       //��W�L��4�檺�ɭԴN���� 
		    while(a[aline][bline] == 0 ){                                       //��o�Ӱ}�C�̪��Ƭ�0�ɡA�N�@�����ư��o�� 
	  	        number = rand()%4 + 1;                                          //Ū���ܼ� 
		        while(num<4){
			        if(number == a[aline][num])                                 //�P�_�P�@��̪��Ʀr�O�_������ 
			            atrue = 1;                                              //�O���ܴN����1
                    if(number == a[num][bline])                                 //�P�_�P�@�C�̪��Ʀr�O�_������  
			            btrue = 1;
                    while(num1 < 4){                                            //�P�_�������̬O�_�����ƪ���
			            if(aline/2 == num1/2 ){                                 //�⥪�k����ݩ�P�@���X�� 
			     	        while(num2 < 4){                 
				                if(bline/2 == num2/2)                           //��W�U����ݩ�P�@���X��  
			                        if(number == a[num1][num2])
				                        abtrue = 1;                             //�i��o�̥N��|�Ө����̦����ƼƦr 
                                num2++;
	                        }
			                num2=0;
		                }
				        num1++;
		            }
		            num1 = 0;
			        num++;
	            }
		        if(!atrue && !btrue && !abtrue){                                //��P�_�����_�ɥN��W�z�T�سW�h���ŦX�A�]����number�s�b�}�C�� 
		  	        a[aline][bline] =number;
		  	        runtime = 0;
		        }
		        else
		            runtime++;
 	            atrue =0;
	 	        btrue=0;
  	            abtrue=0;
                num=0;
	            if(runtime>=100){                                               //�p�G�P�@��Ƨ�F100�M���S���G�A�N���Ϊ��Ʀr���ܤj���v���Q�Χ��F�A�]�����s��o�� 
		            for(int i = 0;i<4;i++)
		                a[aline][i] = 0;
		            bline = 0;
		            runtime = 0;
	            }
		    }
		    bline++;
		    if(bline>=4){                                                       //�N��{�b�o��w�g��4�ӼƦr�F�A�n���U�@��F 
			    aline++;
			    bline = 0; 
		    }
	    }
	    int i = 0;
	    string t;
	    for ( aline = 0 ; aline < 4 ; aline++ )                                 // �s���r���K�s�� 
            for ( bline = 0, t = "" ; bline < 4 ; bline++, t = "" ) {
                t = int2str(a[aline][bline]);
                save.save += t;
            }
        t = int2str(FTC1);                                                      //�s�i�@�Ӧr�ꤤ 
        save.save += t;
        t = int2str(FTC2);
        save.save += t;
        t = int2str(STC1);
        save.save += t;
        t = int2str(STC2);
        save.save += t;
    }
    
    public:void DisplayOneSudokuProblem(string iSave) {                         //��ܤ@���D�� 
        int a[4][4] = {0}, FTC1, FTC2, STC1, STC2;
        string oSave;
        Convert( iSave, oSave, FTC1, FTC2, STC1, STC2 );
        for(int y = 0, i = 0; y < 4 ; y++ )                                     //�N���x�s���ƿW�q�r�ꫬ����^�}�C���� 
            for( int z = 0 ; z < 4 ; z++, i++ )
                a[y][z] = oSave[i] - '0';
	    for(int i =0;i<4;i++){                                                  //��w����n����m�B�� 
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

    public:void DisplayAllSudokuProblem( vector<allS> sSet ) {                  // ����D�w���Ҧ��D�� 
        int i = 0;
        for (vector<allS>::iterator it = sSet.begin(); it < sSet.end(); ++it) {
            cout << "( " << ++i << " )\n";
            DisplayOneSudokuProblem( it->save );
            cout << "\n";
        }
    }
};

class PracticeModeProcess {                                                     // �P�D�w�B�m�ߦ�����FUNCTION�����b�o��CLASS 
    AllOthers Ins;
    public:void ReadSavedProblem( vector<allS> &sSet) {                         // Ū���D�w�� 
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
                sSet.push_back(ftemp);                                          // Ū�줧��s�i�D�w�}�C 
            }
            inFile.close();
        }
    }
    
    public:void OutputProblem( vector<allS> sSet ) {                            // �N�D�w�g�� 
        ofstream outFile;
        string fileName = "SavedProblem.txt";
        outFile.open(fileName.c_str(), fstream::out);
        for (vector<allS>::iterator it = sSet.begin(); it < sSet.end(); it++) {
            outFile << it->save << endl;
        }
    }
    
    public:void SaveProblem( vector<allS> &sSet, allS temp ) {                  // �N�@���D�ئs�J�D�w�}�C�� 
        sSet.push_back(temp);
    }

    public:bool CheckIfItExist( vector<allS> sSet, string temp ) {              //�ˬd�@���D�جO�_�w�g�b�D�w�}�C�� 
        bool check = false;
        for (vector<allS>::iterator it = sSet.begin(); it < sSet.end(); it++) {
            if ( it->save.compare(temp) == 0 )
                check = true;
        }
        return check;
    }

    public:void DeleteOneSudokuProblem( vector<allS> &sSet, int i ) {           // �R���D�w����i�D 
        sSet.erase( sSet.begin() + i );
    }

    void PracticeWrite( string it, bool &quit){                                 // �m�߼Ҧ� 
        string oSave;
        int FTC1, FTC2, STC1, STC2;
        Ins.Convert( it, oSave, FTC1, FTC2, STC1, STC2 );                       // �N�ϥئr���ন��K��ܪ��榡 
        Ins.DisplayOneSudokuProblem( it );                                      // ��ܤ@�D 
        int ans1, ans2, i = 0, j = 0;
        ans1 = oSave[FTC1*4+FTC2] - '0';
        ans2 = oSave[STC1*4+STC2] - '0';
        cout << " x=";                                                          // �}�l�@�� 
        cin >> i;
        if( i != 0 ){
            cout << " y=";
            cin >> j;
            if ( j != 0 ) {
                while ( i != ans1 || j != ans2 ) {
                    cout << "�A�����F!�Э��s�@��\n x=";
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
                    cout << "�A����F!\n";
            }
            else
                quit = true;
        }
        else
            quit = true;
    }

    public:void Practice( vector<allS> sSet ) {                                 // �b�m�߼Ҧ��]�L�D�w���C�@�D 
        bool quit = false;
        cout << "�p�n���}�m�߼Ҧ��п�J'0'\n"; 
        for (vector<allS>::iterator it = sSet.begin(); it < sSet.end() && !quit; it++) {
            PracticeWrite( it->save, quit );
        }
    }
};

class StandardModeProcess {                                                     // �����Ҧ�������FUNCTION�����b��CLASS 
    AllOthers Ins;
    public:void SaveScore( double timeUsed ) {                                  // �N�@�����Ʀs�J����O���O�� 
        SB ftemp;
        ftemp.score = Ins.db2str( timeUsed );
        ScoreBoard.push_back(ftemp);
    }

    public:void Standard() {                                                    // �����Ҧ� 
        int x = 1;
        clock_t t1, t2;
        allS temp;
        int a[4][4] = {0}, FTC1, FTC2, STC1, STC2, ans1 = 0, ans2 = 0;
        string problem;
        t1 = clock();
        while ( x < 5 ) {
            Ins.CreateOneSudoku(temp);
            Ins.Convert( temp.save, problem, FTC1, FTC2, STC1, STC2 );
            for(int y = 0, i = 0; y < 4 ; y++ )                                 //�N���x�s���ƿW�q�r�ꫬ����^�}�C���� 
                for( int z = 0 ; z < 4 ; z++, i++ )
                    a[y][z] = problem[i] - '0';
            cout << " (" << x << ")\n";
            for(int i =0;i<4;i++){                                              //��w����n����m�B�� 
                for(int q=0;q<4;q++){                                           // �H�U�P�m�߼Ҧ� 
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
	        if ( x > 2 ) {                                                      // �����Ҧ��]�����������׮t�O�A�]���e���D�����Ů���֡A����D�~�}��ĤG�Ů� 
                cout << " y=";
                cin >> ans2;
            }
            while ( ans1 != a[FTC1][FTC2] || (ans2 != a[STC1][STC2] && x > 2 ) ) {
	            cout << "�A�����F�A�Э��s�@��!\n x=";
	            cin >> ans1;
	            if ( x > 2 ) {
                    cout << " y=";
                    cin >> ans2;
                }
            }
            cout << "�A����F!\n"; 
            x++;
        }
        t2 = clock();
        cout << "���ߧ@������!! �Ӯ�:" << double(t2 - t1)/CLOCKS_PER_SEC << "��" << endl;
        SaveScore( double(t2 - t1)/CLOCKS_PER_SEC );
    }

    public:void ReadScoreboard() {                                              // Ū���O���O�ɮ� 
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

    public:void DisplayScoreboard() {                                           // ��ܰO���O 
        int c = 0;
        for (vector<SB>::iterator it = ScoreBoard.begin(); it < ScoreBoard.end(); it++) {
            cout << "(" << ++c << ") " << it->score << "��" << endl;
        }
    }

    public:void OutputScoreBoard() {                                            // �N����O���O�ܼƦs�� 
        ofstream outFile;
        string fileName = "Scoreboard.txt";
        outFile.open(fileName.c_str(), fstream::out);
        for (vector<SB>::iterator it = ScoreBoard.begin(); it < ScoreBoard.end(); it++) {
            outFile << it->score << endl;
        }
    }
};

class AdvancedModeProcess {
    vector<allAS> asSet;                                                        //�зǼƿW�D�w 
    allAS temp;                                                                 //�Ȧs�D�w���䤤�@�D 
    AllOthers Ins;
    
    void ReadStandardProblemsFile() {                                           //�إ�9*9��Ū�D�w 
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
    
    public:void ReadStandardScoreboard() {                                      // Ū���зǼ�Ū�O���O 
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
    
    public:void DisplayStandardScoreboard() {                                   // �̷Ӥ��ư��C��ܰO���O 
        int c = 0, temppos = 0, cur = 0, total = AScoreBoard.size();
        ASB temp;
        while ( c < total ) { 
            temppos = 0;
            cur = 1;
            temp = AScoreBoard[0];                                              // ���Ȧs�Ĥ@�դ��� 
            for ( vector<ASB>::iterator it = AScoreBoard.begin() + 1; it < AScoreBoard.end(); it++ ) {
                if ( it->score.compare( temp.score ) < 0 ) {                    // �Yit���Ƥ��Ȧs���ٰ��NŪ�i�h�A�åB�O���O�ĴX����� 
                    temp.score = it->score;
                    temp.name = it->name;
                    temppos = cur;
                }
                ++cur;
            }
            cout << "(" << ++c << ") " << temp.name << " : " << temp.score << "��" << endl;
            AScoreBoard.erase( AScoreBoard.begin() + temppos );                 // ��X����N�q�}�C���N����X��(�ѤU����Ƥ����Ƴ̰���)��ƧR�� 
        }
        ReadStandardScoreboard();                                               // �̫�A���sŪ�J�O���O 
    }
    
    void SaveScore( string name, double timeUsed ) {                            // �N�@�����Ʀs�J�O���O�}�C�� 
        ASB ftemp;
        ftemp.name = name;
        ftemp.score = Ins.db2str( timeUsed );
        AScoreBoard.push_back(ftemp);
    }
    
    void OutputAdvancedScoreboard() {                                           // �N���Ʀs�� 
        ofstream outFile;
        string fileName = "StandardScoreboard.txt";
        outFile.open(fileName.c_str(), fstream::out);
        for (vector<ASB>::iterator it = AScoreBoard.begin(); it < AScoreBoard.end(); it++) {
            outFile << it->name << endl;
            outFile << it->score << endl;
        }
    }
    
    void SelectOneProblemRandomlyAndPrint( int &n ) {                           // �H���q�D�w����ܤ@�D�åB��ܥX�� 
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
        cout << "��J:";
    }
    
    public:void StartOneGame() {                                                // �зǼƿW�D�ԼҦ� 
        int n = 0;
        string ans, name;
        clock_t t1, t2;
        cout << "�Хѥ��ܥk�A�A�ѤW�ӤU�񵪡A�B�Ф@����J���A��ENTER�e�X����\n" << endl;
        SelectOneProblemRandomlyAndPrint( n );
        t1 = clock();
        cin >> ans;
        while ( ans.compare( asSet[n].ans ) != 0 ) {
            cout << "�����o! �Э��s�@��" << endl;
            cout << "��J:"; 
            ans = "";
            cin >> ans;
        }
        t2 = clock();
        cout << "���ߧ@������!! �Ӯ�:" << double(t2 - t1)/CLOCKS_PER_SEC << "��" << endl;
        cout << "�п�J�A�Q�d�b�O���O�W���W�r:";
        cin >> name;
        SaveScore( name, double(t2 - t1)/CLOCKS_PER_SEC );
        OutputAdvancedScoreboard();
    }
};

int main() {
    AllOthers Ins1;                                                             //�ŧiCLASSES
    PracticeModeProcess Ins2;
    StandardModeProcess Ins3;
    AdvancedModeProcess Ins4; 
    vector<allS> sSet;                                                          //sSet�ΨӼȦs�D�w���Ҧ��D�� 
    allS temp;                                                                  //temp�ΨӼȦs��@�D���H�Ѩϥ� 
    Ins2.ReadSavedProblem(sSet);                                                //Ū���D�w�ɮ�
    Ins3.ReadScoreboard();                                                      //Ū���O���O
    Ins4.ReadStandardScoreboard();                                              //Ū���зǼƿW���p���O 
    int i, j;                                                                   //i�Ω�Ū���ϥΪ̿�J�����O
    cout << "0. ����\n1. �޲z\n2. �C��\n3. �i���Ҧ�\n��J:";                    //���U�ӧY�O�̷��D�ةҳW�w�������]�p 
    cin >> i;
    while ( i != 0 ) {
        while ( i == 1 ) {
            cout << "0. �s�W�D��\n1. ����D��\n2. �R���D��\n3. �^�W�@��\n��J:";
            cin >> j;
            if ( j == 0 ) {
                do {
                    Ins1.CreateOneSudoku(temp);
                } while (Ins2.CheckIfItExist(sSet, temp.save));
                Ins1.DisplayOneSudokuProblem(temp.save);
                Ins2.SaveProblem(sSet, temp);
                cout << "�s�W����";
            }
            else if ( j == 1 ) { 
                if ( !sSet.empty() )
                    Ins1.DisplayAllSudokuProblem(sSet);
                else
                    cout << "�|���إ��D�w�A�зs�W�D��!" << endl;
            } 
            else if ( j == 2 ) {
                cout << "�п�J�n�R�����D��:";
                cin >> j;
                if ( j <= sSet.size() && j > 0 ) {
                    Ins2.DeleteOneSudokuProblem( sSet, --j );
                    cout << "�R������" << endl;
                } 
                else
                    cout << "�d�L���D!" << endl;
            }
            else if ( j == 3 )
                break;
            else
                cout << "���O���~!" << endl;
        }
        while ( i == 2 ) {
            cout << "0. �m��\n1. �}�l����\n2. �[�ݱo��\n3. �^�W�@��\n��J:";
            cin >> j;
            if ( j == 0 ) {
                if ( !sSet.empty() )
                    Ins2.Practice(sSet);
                else
                    cout << "�|���إ��D�w�A�зs�W�D��!" << endl;
            } 
            else if ( j == 1 ) {
                Ins3.Standard();
                Ins3.OutputScoreBoard();
            }
            else if ( j == 2 ) {
                if ( !ScoreBoard.empty() )
                    Ins3.DisplayScoreboard();
                else
                    cout << "�|�����L���A�Цܤ֪��L�@�������Ҧ�!" << endl;
            }
            else if ( j == 3 )
                break;
            else
                cout << "���O���~!" << endl;
        }
        while ( i == 3 ) {
            cout << "�����зǼƿW�D�ԼҦ�!\n��ĳ�ǳƯȵ��@���|�����K\n0. �}�l�D��\n1. �d�ݱƦW\n2. �^�W�@��\n��J:";
            cin >> j;
            if ( j == 0 ) {
                Ins4.StartOneGame();
            }
            else if ( j == 1 ) {
                if ( !AScoreBoard.empty() )
                    Ins4.DisplayStandardScoreboard();
                else
                    cout << "�|���}�l�L�D�ԡA�Цܤ֪��L�@���зǼƿW���D�ԼҦ�!" << endl; 
            }
            else if ( j == 2 )
                break;
            else
                cout << "���O���~!" << endl;
        }
        if ( i < 0 || i > 3 )
            cout << "���O���~!" << endl;
        cout << "0. ����\n1. �޲z\n2. �C��:\n3. �i���Ҧ�\n��J:";
        cin >> i;
    }
    if ( !sSet.empty() )
        Ins2.OutputProblem( sSet );
    system("pause");
    return 0;
}
