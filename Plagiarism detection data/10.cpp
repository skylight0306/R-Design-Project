#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void FullSudoku();
int Do(int p, int num); 
int SolveSudoku(int *b);
int DigSudoku();

void Show(int *b);

const int Size = 9;  // �n�إ߼ƿW�L�����j�p Size x Size
const int Max = Size*Size;
const int Mid = (Max+1)/2;
int Col, Row;

int Board[Max];   
int Solve[Max];
int Ans;
// =========================== �D�{�� 
int main()
{
  srand((unsigned)time(NULL)); 
  for(int p=0; p<Max; p++) 
     Board[p] = 0;
  for(Col = Size, Row=2; Row<Col; Row++)
     if (Size%Row==0) Col=Size/Row;
  Row = Size/Col;
  
  FullSudoku();  // ���ͧ���ƿW�L��
  printf( "\n���ͧ��㪺�ƿW�L�� :\n" );
  Show(Board);
  DigSudoku();   // ���}�k�ߤ@�ѥX�D
  printf( "\n���}�᪺�ߤ@�ѼƿW�L�� :\n" );
  Show(Board);
  Ans=0;
  SolveSudoku(Board);  // �ѼƿW
  printf( "\n�ƿW�ѵ� :\n" );
  Show(Solve);
  system("pause");  // �Ȱ��@�U 
  return 0;
}

// ��ܽL�����@�� --------------
void ShowLine(int *b, char *s )
{
  printf("%c%c", s[0], s[1] );
  for(int c=0; c<Size; c++)
  {
     if(b==NULL || b[c]==0) printf("%c%c", s[2], s[3]);
     else printf("%2d",b[c]);
     if (c+1==Size) printf("%c%c\n", s[8], s[9]);
     else if(c%Col+1==Col) printf("%c%c", s[6], s[7]);
     else printf("%c%c", s[4], s[5]);
  }
}
// ��ܥ��L�� ------------------
void Show(int *b)  
{
  ShowLine(NULL, "����������");
  for(int r=0; r<Size; r++)
  {
    ShowLine( &b[r*Size], "��  �x����" );
    if (r+1==Size) ShowLine( NULL, "����������");
    else if (r%Row+1==Row) ShowLine( NULL, "����������");
    else ShowLine( NULL, "��w�q����");
  }
}

// ���ͧ���ƿW�L�� ============================
void FullSudoku()
{
  int loc, re, i; 
  int pos[Size];
  
  for(i=0; i<Size; i++)
    pos[i] = i/Col*Size+i%Col;   // �p�c�椺���� 
  
  for(int num=1; num<=Size; num++)  // �w��J�Ʀr 
  {
    re = 0;      
    for(int block=0; block<Size; block++)  // �p�c�� 
    {
        loc = block/Row*Row*Size+block%Row*Col;  // �p�c���m 
        for(i=0; i<Size; i++)  // ���äp�c�椺����
        {
           int j = rand()%Size;
           int t = pos[i];  pos[i]=pos[j]; pos[j] = t;  //�洫     
        }        
        while(--i>=0 && !Do(loc+pos[i], num));  // ��J 
        if (i<0)
        {  // ��J���� -- �٭�Ҷ�Ʀr 
           for(int p=0; p<Max; p++)
              if(Board[p]==num) Board[p]=0;           
           block = -1;   // ����~~ (��block�q0�}�l)
           if(++re>Size) break; // �Y���Ӧ��ƹL�h, ���� 
        }
    }
    if (re>Size) num-=2;  // �Y���Ӧ��ƹL�h, �h�^�e�@�Ʀr 
  } 
}
// ------ ��J 
int Do(int p, int num)
{
  if (Board[p]!=0) return 0;  
  for(int i=0; i<Size; i++)
    if(Board[p/Size*Size+i]==num || Board[i*Size+p%Size]==num) return 0;
  Board[p]=num;  
  return 1;
}

// �X�D(���}�k) ==================================
int DigSudoku()
{
   int d, ka, kb, kc; 
   int Dig[Mid];   // ���}����
   
   for(d=0; d<Mid; d++) Dig[d]=d;
   for(d=0; d<Mid; d++)  // ���ë��}����
   {
      int n = rand()%Mid;
      int t = Dig[n];  Dig[n]=Dig[d]; Dig[d] = t;  //�洫     
   }    

   for(d=0; d<Mid; d++)
   {
      Ans=0; kb = -1; kc = Max-Dig[d]-1;
      ka = Board[Dig[d]];  Board[Dig[d]]=0;  // ���}
      if (kc!=Dig[d]) 
      {  kb = Board[kc];  Board[kc] = 0; }   // ��٫��}
      SolveSudoku(Board);
      if (Ans>1)  // ���h����, ���}�ݶ�^
      {
         Board[Dig[d]] = ka;
         if (kb>0) Board[kc] = kb;
      }
   }
   return 1;
}
// �ѼƿW(�ɤO��) ================================
int SolveSudoku(int *b)
{
  int p, num, r, c, l, s, i, a=0;
  for(p=Max-1; p>=0 && b[p]!=0; p--);   // ��M�Ů� 
  if (p>=0)
  {  // p���Ů��m 
    r=p/Size; c=p%Size;  l=r/Row*Row*Size+c/Col*Col;  // ��m���� 
    for(num=1; num<=Size; num++)   // �N��J���Ʀr 
    { 
      b[p] = num;       
      for(i=0; i<Size; i++)  // �ˬd ��C�P�p�E�c���O�_���� 
      {
        s = l + i/Col*Size+i%Col;
        if((i!=c && b[r*Size+i]==num) || ( i!=r && b[i*Size+c]==num)
           || ( s!=p && b[s]==num) )  break;  //�����Ыh���� 
      }
      if (i==Size && SolveSudoku(b)!=0) a=1;  //�S���Ыh�~��...[���j] 
      if (Ans>1) break;  // ���h���� -- 
    }
    b[p] = 0;
    return a;
  }
  if (Ans++<1)
    for(p=0; p<Max; p++) Solve[p] = b[p];   // �O���ѵ� 
  return 1;  
}
//=================================================