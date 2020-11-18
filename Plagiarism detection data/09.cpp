

#include <windows.h>  
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
 
const int max_size = 9;
const int AttrLine = 0x0E;
int m_size = max_size;
int m_max, m_mid, m_col, m_row, m_ans;
const char cText[] ="�@������������������101112";
 
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
// ��:[CB]E04B   �W:[C8]E048   �U:[D0]E050   �k:[CD]E04D   
// Ins:[D2]E052   Del:[D3]E053   Home:[C7]E047   End:[CF]E04F   PgUp:[C9]E049   PgDn:[D1]E051
// Tab: 0009    �ť�: 0020   Enter: 000D   Back: 0008   Esc: 001B 
int wgetch()
{
  int c = _getch();
  if (!c)
  {
     c=_getch();
     if (c>=0x3B && c<=0x44) return c-0x3A+0xF0;  // �NF1..F10 �ন 0x00F1~0x00FA
     return c<<8; 
  }
  if (c>=0x80)
  {
     int d = _getch();
     if (c==0xE0)
     {  // �N���v�T��BIG5: E047�G E048�H E049�I E04B�K E04D�M E04F�O E050�P E051�Q E052�R E053�S
        if (d==0x85 || d==0x86) return 0xFB+d-0x85;  // �NF11/F12 �ഫ�� 0x00FB/0x00FC 
        if (d>=0x47 && d<=0x53 && d!=0x4A && d!=0x4C && d!=0x4E) 
           return 0xC0+d-0x40;  // �N�S�����ഫ�� 0xC0..0xDF
     }
     c = (c<<8) + d;   // ����X
  }
  return c;
}
// ��ܽL�����@�� --------------
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
// ��ܥ��L�� ------------------
void ShowBoard(int *b)  
{
  int row = 4;
  for(int i=0; i<max_size*2+3; i++)
     Display(0, row+i-1, 0x07, "%79s", " ");
 
  ShowLine(row++, NULL, 0, "����������");
  for(int r=0; r<m_size; r++)
  {
    ShowLine(row++, &b[r*m_size], r*m_size, "���@�x����" );
    if (r+1==m_size) ShowLine(row++, NULL, 0, "����������");
    else if (r%m_row+1==m_row) ShowLine(row++, NULL, 0,"����������");
    else ShowLine(row++, NULL, 0, "��w�q����");
  }
}
 
void ShowMenu()
{
  SetPos(0,1);
  Display( 0x07, "�ﶵ:  ");
  Display( 0x70, "F2");  Display( 0x07, "�ۭq�D�� " );
  Display( 0x70, "F3");  Display( 0x07, "�q���X�D " );  
  Display( 0x70, "F4");  Display( 0x07, "�ۦ�ѵ� " );    
  Display( 0x70, "F5");  Display( 0x07, "�q���ѵ� " ); 
  Display( 0x70, "F6");  Display( (m_size==6)? 0x4E: 0x07, " 6x6" );  Display( 0x07, " " ); 
  Display( 0x70, "F8");  Display( (m_size==8)? 0x4E: 0x07, " 8x8" );  Display( 0x07, " " ); 
  Display( 0x70, "F9");  Display( (m_size==9)? 0x4E: 0x07, " 9x9" );  Display( 0x07, " " ); 
  Display( 0x70, "F10"); Display( 0x07, "����" ); 
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
// ���ͧ���ƿW�L�� ============================
 
// ------ ��J 
int Do(int p, int num)
{
  if (Board[p]!=0) return 0;  
  for(int i=0; i<m_size; i++)
    if(Board[p/m_size*m_size+i]==num || Board[i*m_size+p%m_size]==num) return 0;
  Board[p]=num;  
  return 1;
}
// ----- ���ͧ���ƿW�L��
 
void FullSudoku()
{
  int loc, re, i; 
  int pos[max_size];
 
  for(i=0; i<m_size*m_size; i++) Board[i]=Solve[i]=0;
  for(i=0; i<m_size; i++)
    pos[i] = i/m_col*m_size+i%m_col;   // �p�c�椺���� 
  
  for(int num=1; num<=m_size; num++)  // �w��J�Ʀr 
  {
    re = 0;      
    for(int block=0; block<m_size; block++)  // �p�c�� 
    {
        loc = block/m_row*m_row*m_size+block%m_row*m_col;  // �p�c���m 
        for(i=0; i<m_size; i++)  // ���äp�c�椺����
        {
           int j = rand()%m_size;
           int t = pos[i];  pos[i]=pos[j]; pos[j] = t;  //�洫     
        }        
        while(--i>=0 && !Do(loc+pos[i], num));  // ��J 
        if (i<0)
        {  // ��J���� -- �٭�Ҷ�Ʀr 
           for(int p=0; p<m_max; p++)
              if(Board[p]==num) Board[p]=0;           
           block = -1;   // ����~~ (��block�q0�}�l)
           if(++re>m_size) break; // �Y���Ӧ��ƹL�h, ���� 
        }
    }
    if (re>m_size) num-=2;  // �Y���Ӧ��ƹL�h, �h�^�e�@�Ʀr 
  } 
}
//-----------------------------------
bool CheckEnd(int *b)
{
  int p, i, r, c, l, s;
  for(p=0; p<m_max; p++)
  {
    if (b[p]==0) return false;
    r=p/m_size; c=p%m_size;  l=r/m_row*m_row*m_size+c/m_col*m_col;  // ��m���� 
    for(i=0; i<m_size; i++)  //  �ˬd ��C�P�p�E�c���O�_���� 
    {
      s = l + i/m_col*m_size+i%m_col;
      if((i!=c && b[r*m_size+i]==b[p]) || ( i!=r && b[i*m_size+c]==b[p])
         || ( s!=p && b[s]==b[p]) )  return false;  //�����Ыh���� 
    }
  }
  return true;
}
// �ѼƿW(�ɤO��) ================================
int SolveSudoku(int *b)
{
  int p, num, r, c, l, s, i, a=0;
  for(p=m_max-1; p>=0 && b[p]!=0; p--);   // ��M�Ů� 
  if (p>=0)
  {  // p���Ů��m 
    r=p/m_size; c=p%m_size;  l=r/m_row*m_row*m_size+c/m_col*m_col;  // ��m���� 
    for(num=1; num<=m_size; num++)   // �N��J���Ʀr 
    { 
      b[p] = num;       
      for(i=0; i<m_size; i++)  // �ˬd ��C�P�p�E�c���O�_���� 
      {
        s = l + i/m_col*m_size+i%m_col;
        if((i!=c && b[r*m_size+i]==num) || ( i!=r && b[i*m_size+c]==num)
           || ( s!=p && b[s]==num) )  break;  //�����Ыh���� 
      }
      if (i==m_size && SolveSudoku(b)!=0) a=1;  //�S���Ыh�~��...[���j] 
      if (m_ans>1) break;  // ���h���� -- 
    }
    b[p] = 0;
    return a;
  }
  if (m_ans++<1)
    for(p=0; p<m_max; p++) Solve[p] = b[p];   // �O���ѵ� 
  return 1;  
}
// �X�D(���}�k) ==================================
int DigSudoku()
{
   int d, ka, kb, kc; 
   int Dig[(max_size*max_size+1)/2];   // ���}����
   for(d=0; d<m_mid; d++) Dig[d]=d;
   for(d=0; d<m_mid; d++)  // ���ë��}����
   {
      int n = rand()%m_mid;
      int t = Dig[n];  Dig[n]=Dig[d]; Dig[d] = t;  //�洫     
   }     
   for(d=0; d<m_mid; d++)
   {
      m_ans=0; kb = -1; kc = m_max-Dig[d]-1;
      ka = Board[Dig[d]];  Board[Dig[d]]=0;  // ���}
      if (kc!=Dig[d]) 
      {  kb = Board[kc];  Board[kc] = 0; }   // ��٫��}
      SolveSudoku(Board);
      if (m_ans>1)  // ���h����, ���}�ݶ�^
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
 
  Display(0, 0, 0x1C, "�y���B���]�z ");
  Display(0x1E,"�ƿW Console�� ");
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
     else if(key==0xF3)  // �q���X�D
     {
        FullSudoku();
        DigSudoku(); 
        ShowBoard(Board);
        PlayMode=0;
     }
     else if(key==0xF2)  // �ۭq�D��
     {
        PlayMode=1;
        InitBoard(m_size);
        Display( 1, 3, 0x0F, "���� �ۭq�D�� ����  " );
        Display( 0x02, "�ШϥΤW�U���k�䲾��, �èϥμƦr�� 0~%d �i��]�w�P����", m_size ); 
        cx = cy =0;
     }
     else if(key==0xF5 || key==0xF4)  // �q���ѵ� �P �ۦ�ѵ�
     {
        for(i=0; i<m_max; i++) Play[i]=Board[i];
        m_ans=0;
        SolveSudoku(Play);  // �ѼƿW
        if (key==0xF5) ShowBoard(Solve);
        if (m_ans!=1)
        {
           Display( 1, 5+m_size*2, 0x0C, "�D���T�ƿW, �]��%s!!", m_ans? "���h����": "���D�L��" );
           continue;  // ���]�w PlayMode--
        }
        if (key==0xF4)  // --- �ۦ�ѵ�
        {
           for(i=0,n=-1; i<m_max; i++)
              if((Play[i]=Board[i])==(Solve[i]=0) && n<0) n=i;
           ShowBoard(Play);
           if (n<0) continue;  // ���񺡤F, ���઱...
           Display( 1, 3, 0x0F, "���� �ۦ�ѵ� ����  " );
           Display( 0x09, "�ШϥΤW�U���k�䲾��, �èϥμƦr�� 0~%d �i��]�w�P����", m_size ); 
           cx = n%m_size;  cy=n/m_size;
           PlayMode=2;
        }
        else PlayMode=0;
     }
     else if (PlayMode==1) // �ۭq�D��
     {
        switch(key)
        {
           case 0xC8: if(--cy<0) cy=m_size-1;  // �W
                      break; 
           case 0xD0: if(++cy>=m_size) cy=0;   // �U
                      break;
           case 0xCB: if(--cx<0) cx=m_size-1;  // ��
                      break; 
           case 0xCD: if(++cx>=m_size) cx=0;   // �k
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
           case 0xC8: do{  //  �W
                         if(--cy<0) { cy=m_size-1; if(--cx<0) cx=m_size-1; }
                      }while(Board[cy*m_size+cx]!=0);  
                      break; 
           case 0xD0: do{  // �U
                         if(++cy>=m_size) { cy=0; if(++cx>=m_size) cx=0; }
                      }while(Board[cy*m_size+cx]!=0);  
                      break;
           case 0xCB: do{  // ��
                         if(--cx<0) { cx=m_size-1; if(--cy<0) cy=m_size-1; }
                      }while(Board[cy*m_size+cx]!=0);  
                      break; 
           case 0x07: // Tab
           case 0xCD: do{  // �k
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
                       if (i==m_max) // ���񧹤F..
                       {
                          if(CheckEnd(Play))
                          {
                             Display( 1, 5+m_size*2, 0x0C, "�w���Q�����ƿW!! ����!!" );
                             Display(0, 3, 0x07, "%79s", " ");
                             PlayMode=0;
                          }
                          else Display( 1, 5+m_size*2, 0x0C, "���צ����D, �иԲ��ˬd�P�ץ�!!" );
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
