#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void FullSudoku();
int Do(int p, int num); 
int SolveSudoku(int *b);
int DigSudoku();

void Show(int *b);

const int Size = 9;  // 要建立數獨盤面的大小 Size x Size
const int Max = Size*Size;
const int Mid = (Max+1)/2;
int Col, Row;

int Board[Max];   
int Solve[Max];
int Ans;
// =========================== 主程式 
int main()
{
  srand((unsigned)time(NULL)); 
  for(int p=0; p<Max; p++) 
     Board[p] = 0;
  for(Col = Size, Row=2; Row<Col; Row++)
     if (Size%Row==0) Col=Size/Row;
  Row = Size/Col;
  
  FullSudoku();  // 產生完整數獨盤面
  printf( "\n產生完整的數獨盤面 :\n" );
  Show(Board);
  DigSudoku();   // 挖洞法唯一解出題
  printf( "\n挖洞後的唯一解數獨盤面 :\n" );
  Show(Board);
  Ans=0;
  SolveSudoku(Board);  // 解數獨
  printf( "\n數獨解答 :\n" );
  Show(Solve);
  system("pause");  // 暫停一下 
  return 0;
}

// 顯示盤面的一行 --------------
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
// 顯示全盤面 ------------------
void Show(int *b)  
{
  ShowLine(NULL, "╔═╤╦╗");
  for(int r=0; r<Size; r++)
  {
    ShowLine( &b[r*Size], "║  │║║" );
    if (r+1==Size) ShowLine( NULL, "╚═╧╩╝");
    else if (r%Row+1==Row) ShowLine( NULL, "╠═╪╬╣");
    else ShowLine( NULL, "╟─┼╫╢");
  }
}

// 產生完整數獨盤面 ============================
void FullSudoku()
{
  int loc, re, i; 
  int pos[Size];
  
  for(i=0; i<Size; i++)
    pos[i] = i/Col*Size+i%Col;   // 小宮格內順序 
  
  for(int num=1; num<=Size; num++)  // 預填入數字 
  {
    re = 0;      
    for(int block=0; block<Size; block++)  // 小宮格 
    {
        loc = block/Row*Row*Size+block%Row*Col;  // 小宮格位置 
        for(i=0; i<Size; i++)  // 打亂小宮格內順序
        {
           int j = rand()%Size;
           int t = pos[i];  pos[i]=pos[j]; pos[j] = t;  //交換     
        }        
        while(--i>=0 && !Do(loc+pos[i], num));  // 填入 
        if (i<0)
        {  // 填入失敗 -- 還原所填數字 
           for(int p=0; p<Max; p++)
              if(Board[p]==num) Board[p]=0;           
           block = -1;   // 重來~~ (讓block從0開始)
           if(++re>Size) break; // 若重來次數過多, 跳離 
        }
    }
    if (re>Size) num-=2;  // 若重來次數過多, 退回前一數字 
  } 
}
// ------ 填入 
int Do(int p, int num)
{
  if (Board[p]!=0) return 0;  
  for(int i=0; i<Size; i++)
    if(Board[p/Size*Size+i]==num || Board[i*Size+p%Size]==num) return 0;
  Board[p]=num;  
  return 1;
}

// 出題(挖洞法) ==================================
int DigSudoku()
{
   int d, ka, kb, kc; 
   int Dig[Mid];   // 挖洞順序
   
   for(d=0; d<Mid; d++) Dig[d]=d;
   for(d=0; d<Mid; d++)  // 打亂挖洞順序
   {
      int n = rand()%Mid;
      int t = Dig[n];  Dig[n]=Dig[d]; Dig[d] = t;  //交換     
   }    

   for(d=0; d<Mid; d++)
   {
      Ans=0; kb = -1; kc = Max-Dig[d]-1;
      ka = Board[Dig[d]];  Board[Dig[d]]=0;  // 挖洞
      if (kc!=Dig[d]) 
      {  kb = Board[kc];  Board[kc] = 0; }   // 對稱挖洞
      SolveSudoku(Board);
      if (Ans>1)  // 有多重解, 挖洞需填回
      {
         Board[Dig[d]] = ka;
         if (kb>0) Board[kc] = kb;
      }
   }
   return 1;
}
// 解數獨(暴力解) ================================
int SolveSudoku(int *b)
{
  int p, num, r, c, l, s, i, a=0;
  for(p=Max-1; p>=0 && b[p]!=0; p--);   // 找尋空格 
  if (p>=0)
  {  // p為空格位置 
    r=p/Size; c=p%Size;  l=r/Row*Row*Size+c/Col*Col;  // 位置換算 
    for(num=1; num<=Size; num++)   // 將填入的數字 
    { 
      b[p] = num;       
      for(i=0; i<Size; i++)  // 檢查 行列與小九宮內是否重複 
      {
        s = l + i/Col*Size+i%Col;
        if((i!=c && b[r*Size+i]==num) || ( i!=r && b[i*Size+c]==num)
           || ( s!=p && b[s]==num) )  break;  //有重覆則跳離 
      }
      if (i==Size && SolveSudoku(b)!=0) a=1;  //沒重覆則繼續...[遞迴] 
      if (Ans>1) break;  // 有多重解 -- 
    }
    b[p] = 0;
    return a;
  }
  if (Ans++<1)
    for(p=0; p<Max; p++) Solve[p] = b[p];   // 記錄解答 
  return 1;  
}
//=================================================