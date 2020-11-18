

#include <windows.h>  
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
 
const int max_size = 9;
const int AttrLine = 0x0E;
int m_size = max_size;
int m_max, m_mid, m_col, m_row, m_ans;
const char cText[] ="　１２３４５６７８９101112";
 
int Board[max_size*max_size];
int Solve[max_size*max_size];
int Play[max_size*max_size];
 
HANDLE hOut;
 
int SetPos(int x, int y)
{
  COORD pos;
  pos.X=x;
  pos.Y=y;
  return SetConsoleCursorPosition(hOut, pos); 
}
 
int Display( WORD wAttrs, const char *format, ...)   
{
  if (wAttrs)
     SetConsoleTextAttribute( hOut, wAttrs );
  va_list argptr; 
  va_start( argptr, format); 
  int ret = vprintf( format, argptr );
  va_end( argptr);
  return ret;
}
 
int Display( int x, int y, WORD wAttrs, const char *format, ...)   
{
  SetPos(x, y);
  if (wAttrs)
     SetConsoleTextAttribute( hOut, wAttrs );
  va_list argptr; 
  va_start( argptr, format); 
  int ret = vprintf( format, argptr );
  va_end( argptr);
  return ret;
}
// 左:[CB]E04B   上:[C8]E048   下:[D0]E050   右:[CD]E04D   
// Ins:[D2]E052   Del:[D3]E053   Home:[C7]E047   End:[CF]E04F   PgUp:[C9]E049   PgDn:[D1]E051
// Tab: 0009    空白: 0020   Enter: 000D   Back: 0008   Esc: 001B 
int wgetch()
{
  int c = _getch();
  if (!c)
  {
     c=_getch();
     if (c>=0x3B && c<=0x44) return c-0x3A+0xF0;  // 將F1..F10 轉成 0x00F1~0x00FA
     return c<<8; 
  }
  if (c>=0x80)
  {
     int d = _getch();
     if (c==0xE0)
     {  // 將受影響的BIG5: E047詿 E048詡 E049訿 E04B誂 E04D詵 E04F誁 E050詴 E051詺 E052谼 E053豋
        if (d==0x85 || d==0x86) return 0xFB+d-0x85;  // 將F11/F12 轉換成 0x00FB/0x00FC 
        if (d>=0x47 && d<=0x53 && d!=0x4A && d!=0x4C && d!=0x4E) 
           return 0xC0+d-0x40;  // 將特殊鍵轉換為 0xC0..0xDF
     }
     c = (c<<8) + d;   // 中文碼
  }
  return c;
}
// 顯示盤面的一行 --------------
void ShowLine(int r, int *b, int p, char *s )
{
  SetPos(0, r);
  Display(AttrLine, "%c%c", s[0], s[1] );
  for(int c=0; c<m_size; c++)
  {
     if(b==NULL || b[c]==0) Display(AttrLine, "%c%c", s[2], s[3]);
     else if(Board[p+c]!=0) Display(0x0B, "%c%c",cText[b[c]*2], cText[b[c]*2+1] );
     else if(Solve[p+c]!=0) Display(0x04, "%c%c",cText[b[c]*2], cText[b[c]*2+1] );
     else Display(0x07, "%c%c",cText[b[c]*2], cText[b[c]*2+1] );
     if (c+1==m_size) Display(AttrLine, "%c%c", s[8], s[9]);
     else if(c%m_col+1==m_col) Display(AttrLine, "%c%c", s[6], s[7]);
     else Display(AttrLine, "%c%c", s[4], s[5]);
  }
}
// 顯示全盤面 ------------------
void ShowBoard(int *b)  
{
  int row = 4;
  for(int i=0; i<max_size*2+3; i++)
     Display(0, row+i-1, 0x07, "%79s", " ");
 
  ShowLine(row++, NULL, 0, "╔═╤╦╗");
  for(int r=0; r<m_size; r++)
  {
    ShowLine(row++, &b[r*m_size], r*m_size, "║　│║║" );
    if (r+1==m_size) ShowLine(row++, NULL, 0, "╚═╧╩╝");
    else if (r%m_row+1==m_row) ShowLine(row++, NULL, 0,"╠═╪╬╣");
    else ShowLine(row++, NULL, 0, "╟─┼╫╢");
  }
}
 
void ShowMenu()
{
  SetPos(0,1);
  Display( 0x07, "選項:  ");
  Display( 0x70, "F2");  Display( 0x07, "自訂題目 " );
  Display( 0x70, "F3");  Display( 0x07, "電腦出題 " );  
  Display( 0x70, "F4");  Display( 0x07, "自行解答 " );    
  Display( 0x70, "F5");  Display( 0x07, "電腦解答 " ); 
  Display( 0x70, "F6");  Display( (m_size==6)? 0x4E: 0x07, " 6x6" );  Display( 0x07, " " ); 
  Display( 0x70, "F8");  Display( (m_size==8)? 0x4E: 0x07, " 8x8" );  Display( 0x07, " " ); 
  Display( 0x70, "F9");  Display( (m_size==9)? 0x4E: 0x07, " 9x9" );  Display( 0x07, " " ); 
  Display( 0x70, "F10"); Display( 0x07, "結束" ); 
}
 
void InitBoard(int num)
{
  if (num!=6 && num!=8) num=9;
  m_size = num;
  m_max = m_size*m_size;
  m_mid = (m_max+1)/2; 
  for(m_col = m_size, m_row=2; m_row<m_col; m_row++)
     if (m_size%m_row==0) m_col=m_size/m_row;
  m_row = m_size/m_col;
  m_ans = 0;
  for(int i=0; i<max_size*max_size; i++)
     Board[i]=0;
  ShowBoard(Board);
  ShowMenu();
}
// 產生完整數獨盤面 ============================
 
// ------ 填入 
int Do(int p, int num)
{
  if (Board[p]!=0) return 0;  
  for(int i=0; i<m_size; i++)
    if(Board[p/m_size*m_size+i]==num || Board[i*m_size+p%m_size]==num) return 0;
  Board[p]=num;  
  return 1;
}
// ----- 產生完整數獨盤面
 
void FullSudoku()
{
  int loc, re, i; 
  int pos[max_size];
 
  for(i=0; i<m_size*m_size; i++) Board[i]=Solve[i]=0;
  for(i=0; i<m_size; i++)
    pos[i] = i/m_col*m_size+i%m_col;   // 小宮格內順序 
  
  for(int num=1; num<=m_size; num++)  // 預填入數字 
  {
    re = 0;      
    for(int block=0; block<m_size; block++)  // 小宮格 
    {
        loc = block/m_row*m_row*m_size+block%m_row*m_col;  // 小宮格位置 
        for(i=0; i<m_size; i++)  // 打亂小宮格內順序
        {
           int j = rand()%m_size;
           int t = pos[i];  pos[i]=pos[j]; pos[j] = t;  //交換     
        }        
        while(--i>=0 && !Do(loc+pos[i], num));  // 填入 
        if (i<0)
        {  // 填入失敗 -- 還原所填數字 
           for(int p=0; p<m_max; p++)
              if(Board[p]==num) Board[p]=0;           
           block = -1;   // 重來~~ (讓block從0開始)
           if(++re>m_size) break; // 若重來次數過多, 跳離 
        }
    }
    if (re>m_size) num-=2;  // 若重來次數過多, 退回前一數字 
  } 
}
//-----------------------------------
bool CheckEnd(int *b)
{
  int p, i, r, c, l, s;
  for(p=0; p<m_max; p++)
  {
    if (b[p]==0) return false;
    r=p/m_size; c=p%m_size;  l=r/m_row*m_row*m_size+c/m_col*m_col;  // 位置換算 
    for(i=0; i<m_size; i++)  //  檢查 行列與小九宮內是否重複 
    {
      s = l + i/m_col*m_size+i%m_col;
      if((i!=c && b[r*m_size+i]==b[p]) || ( i!=r && b[i*m_size+c]==b[p])
         || ( s!=p && b[s]==b[p]) )  return false;  //有重覆則跳離 
    }
  }
  return true;
}
// 解數獨(暴力解) ================================
int SolveSudoku(int *b)
{
  int p, num, r, c, l, s, i, a=0;
  for(p=m_max-1; p>=0 && b[p]!=0; p--);   // 找尋空格 
  if (p>=0)
  {  // p為空格位置 
    r=p/m_size; c=p%m_size;  l=r/m_row*m_row*m_size+c/m_col*m_col;  // 位置換算 
    for(num=1; num<=m_size; num++)   // 將填入的數字 
    { 
      b[p] = num;       
      for(i=0; i<m_size; i++)  // 檢查 行列與小九宮內是否重複 
      {
        s = l + i/m_col*m_size+i%m_col;
        if((i!=c && b[r*m_size+i]==num) || ( i!=r && b[i*m_size+c]==num)
           || ( s!=p && b[s]==num) )  break;  //有重覆則跳離 
      }
      if (i==m_size && SolveSudoku(b)!=0) a=1;  //沒重覆則繼續...[遞迴] 
      if (m_ans>1) break;  // 有多重解 -- 
    }
    b[p] = 0;
    return a;
  }
  if (m_ans++<1)
    for(p=0; p<m_max; p++) Solve[p] = b[p];   // 記錄解答 
  return 1;  
}
// 出題(挖洞法) ==================================
int DigSudoku()
{
   int d, ka, kb, kc; 
   int Dig[(max_size*max_size+1)/2];   // 挖洞順序
   for(d=0; d<m_mid; d++) Dig[d]=d;
   for(d=0; d<m_mid; d++)  // 打亂挖洞順序
   {
      int n = rand()%m_mid;
      int t = Dig[n];  Dig[n]=Dig[d]; Dig[d] = t;  //交換     
   }     
   for(d=0; d<m_mid; d++)
   {
      m_ans=0; kb = -1; kc = m_max-Dig[d]-1;
      ka = Board[Dig[d]];  Board[Dig[d]]=0;  // 挖洞
      if (kc!=Dig[d]) 
      {  kb = Board[kc];  Board[kc] = 0; }   // 對稱挖洞
      SolveSudoku(Board);
      if (m_ans>1)  // 有多重解, 挖洞需填回
      {
         Board[Dig[d]] = ka;
         if (kb>0) Board[kc] = kb;
      }
   }
   for(int i=0; i<m_max; i++) Solve[i]=0;
   return 1;
}
 
//=================================================
int main(int argc, char *argv[])
{
  hOut = GetStdHandle ( STD_OUTPUT_HANDLE );

  CONSOLE_SCREEN_BUFFER_INFO csInfo; 
  GetConsoleScreenBufferInfo(hOut, &csInfo);
  WORD wOldAttrs = csInfo.wAttributes; 
 
  Display(0, 0, 0x1C, "『阿丁之窟』 ");
  Display(0x1E,"數獨 Console版 ");
  Display(0x1B, " Ver.1.00  ");
  Display(0x1A, "%41s", "http://homepage.seed.net.tw/web/ading/ " );
 
  int PlayMode=0;
  int i, n, key=0; 
  InitBoard(9);
  int cx = 0, cy = 0; 
  while(key!=0xFA && key!=0x1B )
  {
     if (PlayMode==0) SetPos(5,1);
     else SetPos(cx*4+2,cy*2+5);
     key = wgetch();
     if(key==0xF6 || key==0xF8 || key==0xF9 )
     {
        InitBoard(key&0x0F);
        PlayMode=0;
     }
     else if(key==0xF3)  // 電腦出題
     {
        FullSudoku();
        DigSudoku(); 
        ShowBoard(Board);
        PlayMode=0;
     }
     else if(key==0xF2)  // 自訂題目
     {
        PlayMode=1;
        InitBoard(m_size);
        Display( 1, 3, 0x0F, "◎◎ 自訂題目 ◎◎  " );
        Display( 0x02, "請使用上下左右鍵移動, 並使用數字鍵 0~%d 進行設定與移除", m_size ); 
        cx = cy =0;
     }
     else if(key==0xF5 || key==0xF4)  // 電腦解答 與 自行解答
     {
        for(i=0; i<m_max; i++) Play[i]=Board[i];
        m_ans=0;
        SolveSudoku(Play);  // 解數獨
        if (key==0xF5) ShowBoard(Solve);
        if (m_ans!=1)
        {
           Display( 1, 5+m_size*2, 0x0C, "非正確數獨, 因為%s!!", m_ans? "有多重解": "此題無解" );
           continue;  // 不設定 PlayMode--
        }
        if (key==0xF4)  // --- 自行解答
        {
           for(i=0,n=-1; i<m_max; i++)
              if((Play[i]=Board[i])==(Solve[i]=0) && n<0) n=i;
           ShowBoard(Play);
           if (n<0) continue;  // 都填滿了, 不能玩...
           Display( 1, 3, 0x0F, "◎◎ 自行解答 ◎◎  " );
           Display( 0x09, "請使用上下左右鍵移動, 並使用數字鍵 0~%d 進行設定與移除", m_size ); 
           cx = n%m_size;  cy=n/m_size;
           PlayMode=2;
        }
        else PlayMode=0;
     }
     else if (PlayMode==1) // 自訂題目
     {
        switch(key)
        {
           case 0xC8: if(--cy<0) cy=m_size-1;  // 上
                      break; 
           case 0xD0: if(++cy>=m_size) cy=0;   // 下
                      break;
           case 0xCB: if(--cx<0) cx=m_size-1;  // 左
                      break; 
           case 0xCD: if(++cx>=m_size) cx=0;   // 右
                      break;           
           case 0xD3: // Del
           case 0x0D: // Enter 
           case 0x08: // <-
           case 0x20: key=0x30;
           default: if(key>=0x30 && key<=0x30+m_size)
                    {
                       n = key&0x0F;
                       Board[cy*m_size+cx]=n; 
                       Display(0x07, "%c%c",cText[n*2], cText[n*2+1] );
                    }
                    break;
        }
     }
     else if (PlayMode==2)  // 
     {
        switch(key)
        {
           case 0xC8: do{  //  上
                         if(--cy<0) { cy=m_size-1; if(--cx<0) cx=m_size-1; }
                      }while(Board[cy*m_size+cx]!=0);  
                      break; 
           case 0xD0: do{  // 下
                         if(++cy>=m_size) { cy=0; if(++cx>=m_size) cx=0; }
                      }while(Board[cy*m_size+cx]!=0);  
                      break;
           case 0xCB: do{  // 左
                         if(--cx<0) { cx=m_size-1; if(--cy<0) cy=m_size-1; }
                      }while(Board[cy*m_size+cx]!=0);  
                      break; 
           case 0x07: // Tab
           case 0xCD: do{  // 右
                         if(++cx>=m_size) { cx=0; if(++cy>=m_size) cy=0; }
                      }while(Board[cy*m_size+cx]!=0);  
                      break;           
           case 0xD3: // Del
           case 0x0D: // Enter 
           case 0x08: // <-
           case 0x20: key=0x30;
           default: if(key>=0x30 && key<=0x30+m_size)
                    {
                       int n = key&0x0F;
                       Play[cy*m_size+cx]=n; 
                       Display(0x07, "%c%c",cText[n*2], cText[n*2+1] );
                       for(i=0; i<m_max; i++) if(Play[i]==0) break;
                       if (i==m_max) // 都填完了..
                       {
                          if(CheckEnd(Play))
                          {
                             Display( 1, 5+m_size*2, 0x0C, "已順利完成數獨!! 恭喜!!" );
                             Display(0, 3, 0x07, "%79s", " ");
                             PlayMode=0;
                          }
                          else Display( 1, 5+m_size*2, 0x0C, "答案有問題, 請詳細檢查與修正!!" );
                       }
                       else Display(0, 5+m_size*2, 0x07, "%79s", " ");
                    }
                    break;
        }
     }
  }
  SetConsoleTextAttribute ( hOut, wOldAttrs);
  return 0;
}
//=======================================================
