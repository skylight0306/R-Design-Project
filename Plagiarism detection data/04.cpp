#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
class Sudo {
	public:
	char m[16];
	Sudo *next;
};
class paihon {
	public:
	char name[20];
	int point;
}; 
void plus1sudo16( Sudo &a, int i ){
	if(i==1) strcpy(a.m,"1234341221434321");
    else if(i==2) strcpy(a.m,"1234341223414123"); 
    else if(i==3) strcpy(a.m,"1234341241232341");
    else if(i==4) strcpy(a.m,"1234341243212143");
    else if(i==5) strcpy(a.m,"1234342121434312");
    else if(i==6) strcpy(a.m,"1234342143122143");
    else if(i==7) strcpy(a.m,"1243341221344321");
    else if(i==8) strcpy(a.m,"1243341243212134");
    else if(i==9) strcpy(a.m,"1243342121344312");
    else if(i==10) strcpy(a.m,"1243342123144132");
    else if(i==11) strcpy(a.m,"1243342141322314");
    else if(i==12) strcpy(a.m,"1243342143122134");
    else if(i==13) strcpy(a.m,"1234431221433421");
    else if(i==14) strcpy(a.m,"1234431234212143");
    else if(i==15) strcpy(a.m,"1234432121433412");
    else if(i==16) strcpy(a.m,"1234432124133142");
    else if(i==17) strcpy(a.m,"1234432131422413");
    else if(i==18) strcpy(a.m,"1234432134122143");
    else if(i==19) strcpy(a.m,"1243431221343421");
    else if(i==20) strcpy(a.m,"1243431224313124");
    else if(i==21) strcpy(a.m,"1243431231242431");
    else if(i==22) strcpy(a.m,"1243431234212134");
    else if(i==23) strcpy(a.m,"1243432121343412");
    else if(i==24) strcpy(a.m,"1243432134122134");
    else if(i==25) strcpy(a.m,"1324241331424213");
    else if(i==26) strcpy(a.m,"1324241332414132");
    else if(i==27) strcpy(a.m,"1324241341323241");
    else if(i==28) strcpy(a.m,"1324241342313142");
    else if(i==29) strcpy(a.m,"1324243131424213");
    else if(i==30) strcpy(a.m,"1324243142133142");
    else if(i==31) strcpy(a.m,"1342241331244231");
    else if(i==32) strcpy(a.m,"1342241342313124");
    else if(i==33) strcpy(a.m,"1342243131244213");
    else if(i==34) strcpy(a.m,"1342243132144123");
    else if(i==35) strcpy(a.m,"1342243141233214");
    else if(i==36) strcpy(a.m,"1342243142133124");
    else if(i==37) strcpy(a.m,"1324421324313142");
    else if(i==38) strcpy(a.m,"1324421331422431");
    else if(i==39) strcpy(a.m,"1324423121433412");
    else if(i==40) strcpy(a.m,"1324423124133142");
    else if(i==41) strcpy(a.m,"1324423131422413");
    else if(i==42) strcpy(a.m,"1324423134122143");
    else if(i==43) strcpy(a.m,"1342421321343421");
    else if(i==44) strcpy(a.m,"1342421324313124");
    else if(i==45) strcpy(a.m,"1342421331242431");
    else if(i==46) strcpy(a.m,"1342421334212134");
    else if(i==47) strcpy(a.m,"1342423124133124");
    else if(i==48) strcpy(a.m,"1342423131242413");
    else if(i==49) strcpy(a.m,"1423231431424231");
    else if(i==50) strcpy(a.m,"1423231432414132");
    else if(i==51) strcpy(a.m,"1423231441323241");
    else if(i==52) strcpy(a.m,"1423231442313142");
    else if(i==53) strcpy(a.m,"1423234132144132");
    else if(i==54) strcpy(a.m,"1423234141323214");
    else if(i==55) strcpy(a.m,"1432231432414123");
    else if(i==56) strcpy(a.m,"1432231441233241");
    else if(i==57) strcpy(a.m,"1432234131244213");
    else if(i==58) strcpy(a.m,"1432234132144123");
    else if(i==59) strcpy(a.m,"1432234141233214");
    else if(i==60) strcpy(a.m,"1432234142133124");
    else if(i==61) strcpy(a.m,"1423321423414132");
    else if(i==62) strcpy(a.m,"1423321441322341");
    else if(i==63) strcpy(a.m,"1423324121344312");
    else if(i==64) strcpy(a.m,"1423324123144132");
    else if(i==65) strcpy(a.m,"1423324141322314");
    else if(i==66) strcpy(a.m,"1423324143122134");
    else if(i==67) strcpy(a.m,"1432321421434321");
    else if(i==68) strcpy(a.m,"1432321423414123");
    else if(i==69) strcpy(a.m,"1432321441232341");
    else if(i==70) strcpy(a.m,"1432321443212143");
    else if(i==71) strcpy(a.m,"1432324123144123");
    else if(i==72) strcpy(a.m,"1432324141232314");
    else if(i==73) strcpy(a.m,"2134341212434321");
    else if(i==74) strcpy(a.m,"2134341243211243");
    else if(i==75) strcpy(a.m,"2134342112434312");
    else if(i==76) strcpy(a.m,"2134342113424213");
    else if(i==77) strcpy(a.m,"2134342142131342");
    else if(i==78) strcpy(a.m,"2134342142121243");
    else if(i==79) strcpy(a.m,"2143341212344321");
    else if(i==80) strcpy(a.m,"2143341213244231");
    else if(i==81) strcpy(a.m,"2143341242311324");
    else if(i==82) strcpy(a.m,"2143341243211234");
    else if(i==83) strcpy(a.m,"2143342112344312");
    else if(i==84) strcpy(a.m,"2143342143121234");
    else if(i==85) strcpy(a.m,"2134431212433421");
    else if(i==86) strcpy(a.m,"2134431214233241");
    else if(i==87) strcpy(a.m,"2134431232411423");
    else if(i==88) strcpy(a.m,"2134431234211243");
    else if(i==89) strcpy(a.m,"2134432112433412");
    else if(i==90) strcpy(a.m,"2134432134121243");
    else if(i==91) strcpy(a.m,"2143431212343421");
    else if(i==92) strcpy(a.m,"2143431234211234");
    else if(i==93) strcpy(a.m,"2143432112343412");
    else if(i==94) strcpy(a.m,"2143432114323214");
    else if(i==95) strcpy(a.m,"2143432132141432");
    else if(i==96) strcpy(a.m,"2143432134121234");
    else if(i==97) strcpy(a.m,"2314142331424231");
    else if(i==98) strcpy(a.m,"2314142332414132");
    else if(i==99) strcpy(a.m,"2314142341323241");
    else if(i==100) strcpy(a.m,"2314142342313142");
    else if(i==101) strcpy(a.m,"2314143232414123");
    else if(i==102) strcpy(a.m,"2314143241233241");
    else if(i==103) strcpy(a.m,"2341142332144132");
    else if(i==104) strcpy(a.m,"2341142341323214");
    else if(i==105) strcpy(a.m,"2341143231244213");
    else if(i==106) strcpy(a.m,"2341143232144123");
    else if(i==107) strcpy(a.m,"2341143241233214");
    else if(i==108) strcpy(a.m,"2341143242133124");
    else if(i==109) strcpy(a.m,"2314412314323241");
    else if(i==110) strcpy(a.m,"2314412332411432");
    else if(i==111) strcpy(a.m,"2314413212433421");
    else if(i==112) strcpy(a.m,"2314413214233241");
    else if(i==113) strcpy(a.m,"2314413232411423");
    else if(i==114) strcpy(a.m,"2314413234211243");
    else if(i==115) strcpy(a.m,"2341412312343412");
    else if(i==116) strcpy(a.m,"2341412314323214");
    else if(i==117) strcpy(a.m,"2341412332141432");
    else if(i==118) strcpy(a.m,"2341412334121234");
    else if(i==119) strcpy(a.m,"2341413214233214");
    else if(i==120) strcpy(a.m,"2341413232141423");
    else if(i==121) strcpy(a.m,"2413132431424231");
    else if(i==122) strcpy(a.m,"2413132432414132");
    else if(i==123) strcpy(a.m,"2413132441323241");
    else if(i==124) strcpy(a.m,"2413132442313142");
    else if(i==125) strcpy(a.m,"2413134231244231");
    else if(i==126) strcpy(a.m,"2413134242313124");
    else if(i==127) strcpy(a.m,"2431132431424213");
    else if(i==128) strcpy(a.m,"2431132442133142");
    else if(i==129) strcpy(a.m,"2431134231244213");
    else if(i==130) strcpy(a.m,"2431134232144123");
    else if(i==131) strcpy(a.m,"2431134241233214");
    else if(i==132) strcpy(a.m,"2431134242133124");
    else if(i==133) strcpy(a.m,"2413312413424231");
    else if(i==134) strcpy(a.m,"2413312442311342");
    else if(i==135) strcpy(a.m,"2413314212344321");
    else if(i==136) strcpy(a.m,"2413314213244231");
    else if(i==137) strcpy(a.m,"2413314242311342");
    else if(i==138) strcpy(a.m,"2413314243211234");
    else if(i==139) strcpy(a.m,"2431312412434312");
    else if(i==140) strcpy(a.m,"2431312442131342");
    else if(i==141) strcpy(a.m,"2431312413424213");
    else if(i==142) strcpy(a.m,"2431312443121243");
    else if(i==143) strcpy(a.m,"2431314213244213");
    else if(i==144) strcpy(a.m,"2431314242131324");
    else if(i==145) strcpy(a.m,"3124241313424231");
    else if(i==146) strcpy(a.m,"3124241342311342");
    else if(i==147) strcpy(a.m,"3124243112434312");
    else if(i==148) strcpy(a.m,"3124243113424213");
    else if(i==149) strcpy(a.m,"3124243142131342");
    else if(i==150) strcpy(a.m,"3124243143121243");
    else if(i==151) strcpy(a.m,"3142241312344321");
    else if(i==152) strcpy(a.m,"3142241313244231");
    else if(i==153) strcpy(a.m,"3142241342311324");
    else if(i==154) strcpy(a.m,"3142241343211234");
    else if(i==155) strcpy(a.m,"3142243113244213");
    else if(i==156) strcpy(a.m,"3142243142131324");
    else if(i==157) strcpy(a.m,"3124421313422431");
    else if(i==158) strcpy(a.m,"3124421314322341");
    else if(i==159) strcpy(a.m,"3124421323411432");
    else if(i==160) strcpy(a.m,"3124421324311342");
    else if(i==161) strcpy(a.m,"3124423113422413");
    else if(i==162) strcpy(a.m,"3124423124131342");
    else if(i==163) strcpy(a.m,"3142421313242431");
    else if(i==164) strcpy(a.m,"3142421324311324");
    else if(i==165) strcpy(a.m,"3142423113242413");
    else if(i==166) strcpy(a.m,"3142423114232314");
    else if(i==167) strcpy(a.m,"3142423123141423");
    else if(i==168) strcpy(a.m,"3142423124131324");
    else if(i==169) strcpy(a.m,"3214142323414132");
    else if(i==170) strcpy(a.m,"3214142341322341");
    else if(i==171) strcpy(a.m,"3214143221434321");
    else if(i==172) strcpy(a.m,"3214143223414123");
    else if(i==173) strcpy(a.m,"3214143241232341");
    else if(i==174) strcpy(a.m,"3214143243212143");
    else if(i==175) strcpy(a.m,"3241142321344312");
    else if(i==176) strcpy(a.m,"3241142323144132");
    else if(i==177) strcpy(a.m,"3241142341322314");
    else if(i==178) strcpy(a.m,"3241142343122134");
    else if(i==179) strcpy(a.m,"3241143223324114");
    else if(i==180) strcpy(a.m,"3241143241232314");
    else if(i==181) strcpy(a.m,"3214412313422431");
    else if(i==182) strcpy(a.m,"3214412314322341");
    else if(i==183) strcpy(a.m,"3214412323411432");
    else if(i==184) strcpy(a.m,"3214412324311342");
    else if(i==185) strcpy(a.m,"3214413214232341");
    else if(i==186) strcpy(a.m,"3214413223411423");
    else if(i==187) strcpy(a.m,"3241412314322314");
    else if(i==188) strcpy(a.m,"3241412323141432");
    else if(i==189) strcpy(a.m,"3241413213242413");
    else if(i==190) strcpy(a.m,"3241413214232314");
    else if(i==191) strcpy(a.m,"3241413223141423");
    else if(i==192) strcpy(a.m,"3241413224131324");
    else if(i==193) strcpy(a.m,"3412123421434321");
    else if(i==194) strcpy(a.m,"3412123423414123");
    else if(i==195) strcpy(a.m,"3412123441232341");
    else if(i==196) strcpy(a.m,"3412123443212143");
    else if(i==197) strcpy(a.m,"3412124321344321");
    else if(i==198) strcpy(a.m,"3412124343212134");
    else if(i==199) strcpy(a.m,"3421123421434312");
    else if(i==200) strcpy(a.m,"3421123443122143");
    else if(i==201) strcpy(a.m,"3421124321344312");
    else if(i==202) strcpy(a.m,"3421124323144132");
    else if(i==203) strcpy(a.m,"3421124341322314");
    else if(i==204) strcpy(a.m,"3421124343122134");
    else if(i==205) strcpy(a.m,"3412213412434321");
    else if(i==206) strcpy(a.m,"3412213443211243");
    else if(i==207) strcpy(a.m,"3412214312344321");
    else if(i==208) strcpy(a.m,"3412214313244231");
    else if(i==209) strcpy(a.m,"3412214342311324");
    else if(i==210) strcpy(a.m,"3412214343211234");
    else if(i==211) strcpy(a.m,"3421213412434312");
    else if(i==212) strcpy(a.m,"3421213413424213");
    else if(i==213) strcpy(a.m,"3421213442131342");
    else if(i==214) strcpy(a.m,"3421213443121243");
    else if(i==215) strcpy(a.m,"3421214312344312");
    else if(i==216) strcpy(a.m,"3421214343121234");
    else if(i==217) strcpy(a.m,"4123231414323241");
    else if(i==218) strcpy(a.m,"4123231432411432");
    else if(i==219) strcpy(a.m,"4123234112343412");
    else if(i==220) strcpy(a.m,"4123234114323214");
    else if(i==221) strcpy(a.m,"4123234132141432");
    else if(i==222) strcpy(a.m,"4123234134121234");
    else if(i==223) strcpy(a.m,"4132231412433421");
    else if(i==224) strcpy(a.m,"4132231414233241");
    else if(i==225) strcpy(a.m,"4132231432411423");
    else if(i==226) strcpy(a.m,"4132231434211243");
    else if(i==227) strcpy(a.m,"4132234114233214");
    else if(i==228) strcpy(a.m,"4132234132141423");
    else if(i==229) strcpy(a.m,"4123321413422431");   
    else if(i==230) strcpy(a.m,"4123321414322341");
    else if(i==231) strcpy(a.m,"4123321423411432");
    else if(i==232) strcpy(a.m,"4123321424311342");
    else if(i==233) strcpy(a.m,"4123324114322314");
    else if(i==234) strcpy(a.m,"4123324123141432");
    else if(i==235) strcpy(a.m,"4132321414232341");
    else if(i==236) strcpy(a.m,"4132321423411423");
    else if(i==237) strcpy(a.m,"4132324113242413");
    else if(i==238) strcpy(a.m,"4132324114232314");
    else if(i==239) strcpy(a.m,"4132324123141423");
    else if(i==240) strcpy(a.m,"4132324124131324");
    else if(i==241) strcpy(a.m,"4213132424313142");
    else if(i==242) strcpy(a.m,"4213132431422431");
    else if(i==243) strcpy(a.m,"4213134221343421");
    else if(i==244) strcpy(a.m,"4213134224313124");
    else if(i==245) strcpy(a.m,"4213134231242431");
    else if(i==246) strcpy(a.m,"4213134234212134");
    else if(i==247) strcpy(a.m,"4231132421433412");
    else if(i==248) strcpy(a.m,"4231132424133142");
    else if(i==249) strcpy(a.m,"4231132431422413");
    else if(i==250) strcpy(a.m,"4231132434122143");
    else if(i==251) strcpy(a.m,"4231134224133124");
    else if(i==252) strcpy(a.m,"4231134231242413");
    else if(i==253) strcpy(a.m,"4213312413422431");
    else if(i==254) strcpy(a.m,"4213312414322341");
    else if(i==255) strcpy(a.m,"4213312423411432");
    else if(i==256) strcpy(a.m,"4213312424311342");
    else if(i==257) strcpy(a.m,"4213314213242431");
    else if(i==258) strcpy(a.m,"4213314224311324");
    else if(i==259) strcpy(a.m,"4231312413422413");
    else if(i==260) strcpy(a.m,"4231312424131342");
    else if(i==261) strcpy(a.m,"4231314213242413");
    else if(i==262) strcpy(a.m,"4231314214232314");
    else if(i==263) strcpy(a.m,"4231314223141423");
    else if(i==264) strcpy(a.m,"4231314224131324");
    else if(i==265) strcpy(a.m,"4312123421433421");
    else if(i==266) strcpy(a.m,"4312123434212143");
    else if(i==267) strcpy(a.m,"4312124321343421");
    else if(i==268) strcpy(a.m,"4312124324313124");
    else if(i==269) strcpy(a.m,"4312124331242431");
    else if(i==270) strcpy(a.m,"4312124334212134");
    else if(i==271) strcpy(a.m,"4321123421433412");
    else if(i==272) strcpy(a.m,"4321123424133142");
    else if(i==273) strcpy(a.m,"4321123431422413");
    else if(i==274) strcpy(a.m,"4321123434122143");
    else if(i==275) strcpy(a.m,"4321124321343412");
    else if(i==276) strcpy(a.m,"4321124334122134");
    else if(i==277) strcpy(a.m,"4312213412433421");
    else if(i==278) strcpy(a.m,"4312213414233241");
    else if(i==279) strcpy(a.m,"4312213432411423");
    else if(i==280) strcpy(a.m,"4312213434211243");
    else if(i==281) strcpy(a.m,"4312214312343421");
    else if(i==282) strcpy(a.m,"4312214334211234");
    else if(i==283) strcpy(a.m,"4321213412433412");
    else if(i==284) strcpy(a.m,"4321213434121243");
    else if(i==285) strcpy(a.m,"4321214312343412");
    else if(i==286) strcpy(a.m,"4321214314323214");
    else if(i==287) strcpy(a.m,"4321214332141432");
    else if(i==288) strcpy(a.m,"4321214334121234");
    
}

void easywa( Sudo &b, char &n ){
	int i = rand();
	n = b.m[i%16];
	b.m[i%16]='a';
	
}

void hardwa( Sudo &b, char n[] ){
	int i = rand();
	if( i%4 == 0) {
	  n[0]=b.m[0];
	  b.m[0]='a';
	}
	else if( i%4 == 1) {
	  n[0]=b.m[1];
	  b.m[1]='a';
	}
	else if( i%4 == 2) {
	  n[0]=b.m[4];
	  b.m[4]='a';
	}
	else if( i%4 == 3) {
	  n[0]=b.m[5];
	  b.m[5]='a';
	}
	
    i = rand();
	if( i%4 == 0) {
	  n[1]=b.m[2];
	  b.m[2]='b';
	}
	else if( i%4 == 1) {
	  n[1]=b.m[3];
	  b.m[3]='b';
	}
	else if( i%4 == 2) {
	  n[1]=b.m[6];
	  b.m[6]='b';
	}
	else if( i%4 == 3) {
	  n[1]=b.m[7];
	  b.m[7]='b';
	}
	
	i = rand();
	if( i%4 == 0) {
	  n[2]=b.m[8];
	  b.m[8]='c';
	}
	else if( i%4 == 1) {
	  n[2]=b.m[9];
	  b.m[9]='c';
	}
	else if( i%4 == 2) {
	  n[2]=b.m[12];
	  b.m[12]='c';
	}
	else if( i%4 == 3) {
	  n[2]=b.m[13];
	  b.m[13]='c';
	}
	
	i = rand();
	if( i%4 == 0) {
	  n[3]=b.m[10];
	  b.m[10]='d';
	}
	else if( i%4 == 1) {
	  n[3]=b.m[11];
	  b.m[11]='d';
	}
	else if( i%4 == 2) {
	  n[3]=b.m[14];
	  b.m[14]='d';
	}
	else if( i%4 == 3) {
	  n[3]=b.m[15];
	  b.m[15]='d';
	}
}

void inputpai( paihon pai[] ){
	int i = 0;
	FILE *fp;
	char name[20];
	fp=fopen("paihon.txt","r");
	for(i=0;i<10;i++){
		fscanf(fp,"%s",pai[i].name);
		fscanf(fp,"%s",name);
		pai[i].point = atoi(name);
	}
}

void changepai( paihon pai[], int point, char name[] ){
  int i;
  char n1[20];
  int p1;
  for(i=0;point<pai[i].point;i++);
  strcpy(n1,pai[i].name);
  p1=pai[i].point;
  strcpy(pai[i].name,name);
  pai[i].point= point;
  for(i=i+1;i<10;i++){
    strcpy(name,pai[i].name);
    point=pai[i].point;
    strcpy(pai[i].name,n1);
    pai[i].point=p1;
    strcpy(n1,name);
    p1=point;
  }
}

void savepai(paihon pai[]){
  int i;
  FILE *fp;
  remove("排行榜.txt");
  fp = fopen("排行榜.txt","a");
  for(i=0;i<10;i++) fprintf(fp,"%s\n%d\n",pai[i].name,pai[i].point);
  fclose(fp);
}
int main() {
	srand(time(NULL));
	Sudo *a, *b;
	a = new Sudo;
	Sudo *head;
	a->next =NULL;
	head = a;
	int point = 0;
	int i=0,j;
	int q = 0;
	int guan = 0;
	char k1,k2;
	char n[4]; 
	FILE *fp;
	bool re[288] = {false};
	paihon pai[10];
	inputpai(pai);
	char name[20];
	double t3[100] = {0};
	printf("///////////////////歡迎來到4*4迷你數獨遊戲//////////////////\n");
	printf("新增4*4題型請輸入:1\n");
	printf("顯示4*4題型請輸入:2\n"); 
	printf("刪除4*4題型請輸入:3\n");
	printf("練習4*4題型請輸入:4\n");
	printf("開始闖關4*4題型請輸入:5(每關結束會顯示上一關所花時間)\n");
	printf("查詢分數請輸入:6\n");
	printf("查看排行榜請輸入:7\n");
	printf("查看所有數獨題型輸入:8\n");
	
	while(i!=-1){
	  scanf("%d", &i);
	  if(i==1){
	  	q++;
	  	i=rand();
	  	while(re[i%288+1]==true) i=rand();
        if(re[i%288+1]==false){
		plus1sudo16( *a, i%288+1 );      
	    fp = fopen("Sudo.txt","a");
	    fprintf(fp,"第%d題:\n", q );
	    fprintf(fp," %c %c %c %c \n", a->m[0],a->m[1],a->m[2],a->m[3]);
	    fprintf(fp," %c %c %c %c \n", a->m[4],a->m[5],a->m[6],a->m[7]);
	    fprintf(fp," %c %c %c %c \n", a->m[8],a->m[9],a->m[10],a->m[11]);
	    fprintf(fp," %c %c %c %c \n", a->m[12],a->m[13],a->m[14],a->m[15]);
	    fclose(fp);
	    }
	    a->next = new Sudo;
	    a= a->next;
	    a->next = NULL;
	    i=0;
	  }
	  if(i==2){
	  	i=q;
	  	fp = fopen("Sudo.txt","r");
	  	fscanf(fp,"%s", n);
	  	while(i>0){
	  	j=1;
		printf("%s\n", n);
          while(j<17) {
          	fscanf(fp,"%s", n);
        	printf(" %s ", n);
        	if(j%4==0) printf("\n");
        	j++;
		}
		fscanf(fp,"%s", n);
		i--;
	    }
 	    fclose(fp);
 	    i=0;
	  }
	  if(i == 3){
	   remove("Sudo.txt");
	   q=0;
	   i=0;
      }
	  
	  if(i==4){
	  	Sudo n1;
	  	i=rand();
	  	plus1sudo16( n1, i%288+1 ); 
	  	easywa( n1, k1 );
	  	for(i=0;i<16;i++){
	  		printf("%c", n1.m[i]);
	  		if(i%4==3)printf("\n");
		  }
		printf("a=");
	  	scanf("%d", &j);
	  	if(j==1) k2='1';
	  	else if(j==2) k2='2';
	  	else if(j==3) k2='3';
	  	else if(j==4) k2='4';
	  	if ( k1 == k2 ) printf("答對啦!!\n"); 
		else printf("答錯囉 請在加加油~\n");
		i=0;
	  }
	  
	  if(i==5){
	  	bool lose = false;
	  	point = 0;
	  	guan = 1;
	  	time_t t1,t2;
	  	double t3[100]={0};
	  	time(&t1);
	  	while(!lose){
	  	  printf("///////////////////第%d關////////////////\n", guan);
	  	  i = rand();
	  	  plus1sudo16( *a, i%288+1 );
		  hardwa( *a , n );
		  for(i=0;i<16;i++){
	  	  printf("%c", a->m[i]);
	  	  if(i%4==3)printf("\n");
		  }	
		  printf("a=");
		  scanf("%d", &j);
		  if(j==1) k2='1';
	  	  else if(j==2) k2='2';
	  	  else if(j==3) k2='3';
	  	  else if(j==4) k2='4';
	  	  if(k2!=n[0]) lose = true;
		  printf("b=");
		  scanf("%d", &j);
		  if(j==1) k2='1';
	  	  else if(j==2) k2='2';
	  	  else if(j==3) k2='3';
	  	  else if(j==4) k2='4';
	  	  if(k2!=n[1]) lose = true;
		  printf("c=");
		  scanf("%d", &j);
		  if(j==1) k2='1';
	  	  else if(j==2) k2='2';
	  	  else if(j==3) k2='3';
	  	  else if(j==4) k2='4';
	  	  if(k2!=n[2]) lose = true;
		  printf("d=");
		  scanf("%d", &j);
		  if(j==1) k2='1';
	  	  else if(j==2) k2='2';
	  	  else if(j==3) k2='3';
	  	  else if(j==4) k2='4';
	  	  if(k2!=n[3]) lose = true; 
		  time(&t2);
		  if(!lose){
		  	if(difftime(t2,t1)>=60) point = point + 1;
		  	if(difftime(t2,t1)<60&&difftime(t2,t1)>30) point = point + 5;
		  	if(difftime(t2,t1)<=30) point = point + 10;
		  } 
		  printf("%fsec\n", difftime(t2,t1));
		  t1=t2;
		  guan++;	  
		  }
		if(point>pai[9].point) {
			printf("恭喜你成績卓越,進入了排行榜請輸入你的id:");
			scanf("%s", name);
			changepai(pai,point,name);
			savepai(pai);
		}
		printf("答案錯誤,闖關結束\n");
		i=0;
	  }
	  
	  if(i==6){
	  	printf("您在上一關所得分數為%d\n", point);
	  	i=0;
	  }
	  
	  if(i==7){
	  	inputpai(pai);
	  	for(i=0;i<10;i++) printf("第%d名        %s          %d分\n",i+1,pai[i].name,pai[i].point);
	  	i=0;
	  }
	  
      
	  if(i==8){
	  	Sudo in; 
	    for(i=1;i<=288;i++){
	    	plus1sudo16( in, i ); 
	    	printf("第%d題\n",i);
	    	printf("%c %c %c %c\n%c %c %c %c\n", in.m[0],in.m[1],in.m[2],in.m[3],in.m[4],in.m[5],in.m[6],in.m[7]);
	    	printf("%c %c %c %c\n%c %c %c %c\n\n", in.m[8],in.m[9],in.m[10],in.m[11],in.m[12],in.m[13],in.m[14],in.m[15]);
		} 
		i=0;
	} 
    } 
    
     

}
