//*********************** ************************************************************************/
//�{��²��
//�t��:��u�G��
//�m�W: ���R    10327127
//      ���a�d  10311138
//************************************************************************************************/

#include <iostream>															            //���n���Y��, �ɶq �Ų����I
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
#include <time.h>
#include <string.h>

using namespace std;

class dog{
    public :

        char aname[1000];
        char qname[1000];
};

vector<dog> sudo;                       //sudo�̭����ܦhdog
vector<int> point(20);                  //zero�̭����ܦhint

void getNewSudo(int[5][5]);
dog SaveSudo(int[5][5]);

void ShowSudo(char[]);
void RemoveSudo(char[]);
void PracticeSudo();
void Printzero(int[5][5]);
bool Lookforzero(int[5][5],int[5][5]);
bool Havezeroornot(int[5][5]);
void PlaySudo();
void LookPoints();


int cat[5][5] ;
int cat2[5][5] ; // ��ѵ��Ϊ�
int points = 10;
int num = 1;
fstream file;                       //�ŧi�ɮ�

int main(int argc, char *argv[])
{
    char thefirstcommand;
    cout << "***** �W�ŵL�İg�A�ƿW�p�C�� *****\n";
    cout << "*****      Q. �C������       *****\n";
    cout << "*****      M. �޲z           *****\n";
    cout << "*****      P. �C��           *****\n";
    cout << "**********************************\n";
    cout << "Input a command(Q, M, P): \n";
    cin >> thefirstcommand;
    int command = 0;

    while (thefirstcommand != 'Q') {
        if (thefirstcommand == 'M') {            // �i�J�޲z

            cout << "***** �W�ŵL�İg�A�ƿW�p�C�� *****\n";
            cout << "*****      0. ���X�޲z       *****\n";
            cout << "*****      1. �s�W�D��       *****\n";
            cout << "*****      2. ����D��       *****\n";
            cout << "*****      3. �R���D��       *****\n";
            cout << "**********************************\n";
            cout << "Input a command(0, 1, 2, 3): \n";
	        cin >> command;

         	char input[1000];

        	while ( command != 0 ) {

	            if ( command == 1 ) {
	                getNewSudo(cat);
	                sudo.push_back (SaveSudo(cat));
    	            cout << "���s�W������\n" << "\n";

             	}
            	else if (command == 2 ) {
    	            cout << "�п�J[�D��]+[Q]\n";
    	            cin >> input ;
        	        ShowSudo(input);
	            }
    	        else if ( command == 3 ) {
                    cout << "�п�J[�D��]+[Q]\n";
	                cin >> input ;
	                RemoveSudo(input);
            	}

                cout << "***** �W�ŵL�İg�A�ƿW�p�C�� *****\n";
                cout << "*****      0. ���X�޲z       *****\n";
                cout << "*****      1. �s�W�D��       *****\n";
                cout << "*****      2. ����D��       *****\n";
                cout << "*****      3. �R���D��       *****\n";
                cout << "**********************************\n";
	            cout << "Input a command(0, 1, 2, 3): \n";
                cin >> command;
	        } // while

        } //if
        else if (thefirstcommand == 'P') {            // �i�J�C��


            cout << "***** �W�ŵL�İg�A�ƿW�p�C�� *****\n";
            cout << "*****      0. ���X�C��       *****\n";
            cout << "*****      1. �m��           *****\n";
            cout << "*****      2. �}�l����       *****\n";
            cout << "*****      3. �[�ݱo��       *****\n";
            cout << "**********************************\n";
            cout << "Input a command(0, 1, 2, 3): \n";
	        cin >> command;

	        for (int i = 0 ; i < 10 ; i++){         //���J10�D
                getNewSudo(cat);
                sudo.push_back (SaveSudo(cat));
            }

            while (command != 0) {

                if (command == 1){
                    cout << "���ثe�w��10�D��\n" << "�п�J[�D��1~10]+[Q]\n";
                    PracticeSudo();
                }
                else if (command == 2){
                    cout << "\n";
                    cout << "�p���覡 : ����10���A�����@�����@���A��������C\n" << "\n";
                    cout << "\n";
                    cout << "���ثe�w��10�D��\n" << "�п�J[�D��1~10]+[Q]\n";
                    PlaySudo();

                    int number = point.size(); //���Ʃ�ipoint��
                    point.push_back(points);
                    points = 10;
                }
                else if (command == 3){
                    LookPoints();
                }

                cout << "***** �W�ŵL�İg�A�ƿW�p�C�� *****\n";
                cout << "*****      0. ���X�C��       *****\n";
                cout << "*****      1. �m��           *****\n";
                cout << "*****      2. �}�l����       *****\n";
                cout << "*****      3. �[�ݱo��       *****\n";
                cout << "**********************************\n";
                cout << "Input a command(0, 1, 2, 3): \n";

                cin >> command;
            }
        }
        cout << "***** �W�ŵL�İg�A�ƿW�p�C�� *****\n";
        cout << "*****      Q. �C������       *****\n";
        cout << "*****      M. �޲z           *****\n";
        cout << "*****      P. �C��           *****\n";
        cout << "**********************************\n";
        cout << "Input a command(Q, M, P): \n";
        cin >> thefirstcommand;
    }

    system("PAUSE");
    return 0;
}

void getNewSudo(int cat[5][5]){              //�гy�s�ƿW

    for (int i = 0 ; i < 5 ; i++) {         //��l��
        for (int j = 0 ; j < 5 ; j++) {
            cat[i][j] = 0;
        }
    }

    for (int i = 0 ; i < 5 ; i++) {          //��l��
        for (int j = 0 ; j < 5 ; j++) {
            cat2[i][j] = 0;
        }
    }

    int temp,count = 0;
    bool repeatornot = false ;
    srand(time(NULL));

    for (int i = 1 ; i <= 4 ; i ++){
        for (int j = 1 ; j <= 4 ; j++){
            if (count > 50) {
                j = 1;
                count = 0 ;
            }

            temp = rand()%4 + 1;               //���ü�
            cat[i][j] = temp;

            if (j >= 2) {
                for (int z = j-1 ; z >= 1 ; z--)
                    if (cat[i][j] == cat[i][z]) repeatornot = true ; //�p�G���ƨ�F
            }

            if (i >= 2) {
                for (int z = i-1 ; z >= 1 ; z--)
                    if (cat[i][j] == cat[z][j]) repeatornot = true ; //�p�G���ƨ�F
            }

            if ( i == 2 ) {
                if (cat[2][1] == cat[1][2] || cat[2][2] == cat[1][1] ||
                    cat[2][3] == cat[1][4] || cat[2][4] == cat[1][3]) repeatornot = true ; // ����2x2
            }

            if ( i == 4 ) {
                if (cat[4][1] == cat[3][2] || cat[4][2] == cat[3][1] ||
                    cat[4][3] == cat[3][4] || cat[4][4] == cat[3][3]) repeatornot = true ; // �k��2x2
            }


            if (repeatornot){ //�p�G����
                j--;
                count++;
            }
            repeatornot = false;
        }
    }
}

dog SaveSudo(int cat[5][5]){            //�x�s�ƿW

    dog tiger;
    int i = 0;
    char buffer[5];                     //���F�L�X�s�b
    itoa(num,tiger.aname,10);                  // int to string

    for (i = 0 ; tiger.aname[i] != '\0' ; i++ );
    tiger.aname[i] = 'A';
    tiger.aname[i+1] = '\0';

    file.open(tiger.aname, ios::out);                    // �s�J�ƿW
    for(int j = 1 ; j <= 4 ; j++) {
        for (int i = 1 ; i <= 4 ; i ++) file << cat[i][j];
        file << "\n";
    }

    file.close();       //�����ɮ�

    //-------------------------------------------------------------

    itoa(num,tiger.qname,10);                  // int to string

    for (i = 0 ; tiger.qname[i] != '\0' ; i++ );
    tiger.qname[i] = 'Q';
    tiger.qname[i+1] = '\0';

    file.open(tiger.qname, ios::out);                    // �s�D��
    for (int x = 0 ; x < 5 ; x++) {
         int a = rand()%4 + 1;
         int b = rand()%4 + 1;
         cat[a][b] = 0;
    }

    for(int j = 1 ; j <= 4 ; j++) {
        for (int i = 1 ; i <= 4 ; i ++) file << cat[i][j];
        file << "\n";
    }

    file.close();       //�����ɮ�

    num++;
    return tiger;

}

void ShowSudo(char input[]) {                //��ܼƿW

    int n = sudo.size();
    bool repeat = false;
    for (int i = 0 ; i < n ; i++){      //���@�˪��ɦW�Ytrue
        if (strcmp(input,sudo[i].qname) == 0 )repeat = true;
    }

    char buffer[5];                     //���F�L�X�s�b
    if (repeat){
        file.open(input, ios::in); //�һ��ɦW���ƿW��Ū�����A
        for(int a = 1 ; a <= 4 ; a++) {
            file.getline(buffer,sizeof(buffer));      //�L�X�ƿW
            cout << buffer << "\n";
        }
    }
    else cout << "�|�������ƿW!\n" ;              //�_�h

    file.close();    //�����ɮ�
}

void RemoveSudo(char input[]) {
    int n = sudo.size();
    int i = 0;
    bool repeat = false;
    for (i = 0 ; i < n ; i++){                 //���@�˪��ɦW�Ytrue
        if (strcmp(input,sudo[i].qname) == 0 )repeat = true;
        cout << sudo[i].qname << "\n";
        cout << "\n";
    }

    int a = i - 1;
    if (repeat){
        sudo.erase(sudo.begin()+a);
    }
    else cout << "�|�������ƿW!\n" ;              //�_�h

    repeat = false;

}

void PracticeSudo() {               //�m�߶}�l

    for (int i = 0 ; i < 5 ; i++) {      //��l��
        for (int j = 0 ; j < 5 ; j++) {
            cat[i][j] = 0;
        }
    }

    for (int i = 0 ; i < 5 ; i++) {       //��l��
        for (int j = 0 ; j < 5 ; j++) {
            cat2[i][j] = 0;
        }
    }

    cout << "�m�߶}�l\n";
    int fish;
    char input2[1000];
    cin >> input2;
    bool finish = false;
    int aa = 0 ; // �m���D�bvector����m

    int n = sudo.size();
    bool repeat = false;
    for (aa = 0 ; aa < n ; aa++){      //���@�˪��ɦW�Ytrue
        if (strcmp(input2,sudo[aa].qname) == 0 ){
            fish = aa;
            repeat = true;
        }
    }

    char temp;                     //���F�L�X�s�b
    if (repeat){
        file.open(input2, ios::in); //�һ��ɦW���ƿW��Ū�����A
        for(int i = 1 ; i < 5 ; i++) {
            for (int j = 1 ; j < 5 ; j++){
                file.get(temp);      //�L�X�ƿW
                cout << temp ;
                cat[i][j] = (int)temp - 48;
            }
            file.get(temp); // Ū������
            cout << "\n";
        }
    }
    else cout << "�|�������ƿW!\n" ;              //�_�h

    file.close();    //�����ɮ�

    file.open(sudo[fish].aname, ios::in); //�һ��ɦW���ƿW��Ū�����A
    for(int i = 1 ; i < 5 ; i++) {
        for (int j = 1 ; j < 5 ; j++){
            file.get(temp);      //�L�X�ƿW
            cat2[i][j] = (int)temp - 48;
        }
        file.get(temp); // Ū������
        cout << "\n";

    }

    file.close();    //�����ɮ�

    //------------------------------------------------------------------------

    while (!finish){ // ������
      cout << "�п�J�A�n��������m : ";
      Printzero(cat); //��0�æL�X��m

      if ( Lookforzero(cat,cat2) ) { // �p�G��J������O0

          if (Havezeroornot(cat)) {  // �p�G�٦�0
            for(int i = 1 ; i < 5 ; i++) {
                for (int j = 1 ; j < 5 ; j++) cout << cat[i][j];
                cout << "\n";
            }
            cout << "\n";

          }
          else finish = true; // �D�بS��0�F �N�����j��

      } // if
      else cout << "���A��J����m���~!!��\n";   //�p�G��J�����椣�O0
    } // while

    cout << "�����ߧA����F!!!��\n";
    cout << "\n";

}

void Printzero(int cat[5][5]){  // �L0����m

    for (int i = 1 ; i < 5 ; i++){
       for (int j = 1 ; j < 5 ; j++){
           if (cat[i][j] == 0 ) {
               cout << "(" << i << "," << j << ") ";
           }
       }
    }
    cout << "�C\n";
    cout << "\n";
}

bool Lookforzero(int cat[5][5],int cat2[5][5]){  // �ݬO���O0����m���ˬd���ץ������T
    int x,y;
    int input3;
    cout << "x = ";
    cin >> x;
    cout << "\n";

    cout << "y = ";
    cin >> y;
    cout << "\n";

    if (cat[x][y] == 0 ) {
        cout << "���׬O : ";
        cin >> input3 ;
        cout << "\n";

        if ( cat2[x][y] == input3 ) {
            cout << "���浪��F!!\n" ;
            cout << "\n";
            cat[x][y] = input3; // ���T���״��W�h
        }
        else {
            points--;
            cout << "���浪���F!!\n";
        }

        return true;
    }
    else return false ;
}

bool Havezeroornot(int cat[5][5]){
    for(int i = 1 ; i < 5 ; i++) {
        for (int j = 1 ; j < 5 ; j++) {
            if (cat[i][j] == 0) return true;     //�u�n���ݨ�0�N�^��true
        }
    }
    return false;
}

void PlaySudo() {
    time_t start_time, end_time;      //�p����
    start_time = time(NULL);

    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            cat[i][j] = 0;
        }
    }

    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            cat2[i][j] = 0;
        }
    }

    cout << "�����}�l\n";
    int fish;
    char input2[1000];
    cin >> input2;
    bool finish = false;
    int aa = 0 ; // �m���D�bvector����m

    int n = sudo.size();
    bool repeat = false;
    for (aa = 0 ; aa < n ; aa++){      //���@�˪��ɦW�Ytrue
        if (strcmp(input2,sudo[aa].qname) == 0 ){
            fish = aa;
            repeat = true;
        }
    }

    char temp;                     //���F�L�X�s�b
    if (repeat){
        file.open(input2, ios::in); //�һ��ɦW���ƿW��Ū�����A
        for(int i = 1 ; i < 5 ; i++) {
            for (int j = 1 ; j < 5 ; j++){
                file.get(temp);      //�L�X�ƿW
                cout << temp ;
                cat[i][j] = (int)temp - 48;
            }
            file.get(temp); // Ū������
            cout << "\n";
        }
    }
    else cout << "�|�������ƿW!\n" ;              //�_�h

    file.close();    //�����ɮ�

    file.open(sudo[fish].aname, ios::in); //�һ��ɦW���ƿW��Ū�����A
    for(int i = 1 ; i < 5 ; i++) {
        for (int j = 1 ; j < 5 ; j++){
            file.get(temp);      //�L�X�ƿW
            cat2[i][j] = (int)temp - 48;
        }
        file.get(temp); // Ū������
        cout << "\n";

    }

    file.close();    //�����ɮ�

    //------------------------------------------------------------------------

    while (!finish){ // ������
      cout << "�п�J�A�n��������m : ";
      Printzero(cat); //��0�æL�X��m

      if ( Lookforzero(cat,cat2) ) { // �p�G��J������O0

          if (Havezeroornot(cat)) {  // �p�G�٦�0
            for(int i = 1 ; i < 5 ; i++) {
                for (int j = 1 ; j < 5 ; j++) cout << cat[i][j];
                cout << "\n";
            }
            cout << "\n";

          }
          else finish = true; // �D�بS��0�F �N�����j��

      } // if
      else cout << "���A��J����m���~!!��\n";   //�p�G��J�����椣�O0
    } // while

    end_time = time(NULL);
    int min = difftime(end_time,start_time);

    cout << "�����ߧA����F!!!��\n";
    cout << "\n";
    cout << "�A���o�� : " << points << "��\n";
    cout << "\n";
    cout << "�ɶ��@��F : " << min << "��\n";
    cout << "\n";
}

void LookPoints() {
    int many = 1 ;
    for (int i = 0 ; i < point.size() ; i++) {    //�L�X����
        if (point[i] != 0) {
            cout << "��" << many << "���o�� : " << point[i] << "\n";
            many++;
        }
    }
}
