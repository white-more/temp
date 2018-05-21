#include <stdio.h>
#define STRLEN 20
//void  myStrcat(char *schar, char *tchar,int tlength);
void myStrcatArray(char schar[],char tchar[],int tlength);
int main(int argc, char const *argv[])
{
	char str1[STRLEN]="abcdeddfdf";
	char str2[]="fghijkdsdfsfasdffdds";
	printf("原str1=%s\t原str2=%s\n",str1,str2);
	myStrcatArray(str2,str1,STRLEN);
	printf("现str1=%s\t现str2=%s\n",str1,str2);
	return 0;
}


void myStrcatArray(char schar[],char tchar[],int tlength){
	//初始化原指针所指向的字符串的长度为0
	int scharl=0;
	int tcharl=0;
	int i=0;
	int j=0;
	if(tlength<1)
	{
		return ;
	}
	while(schar[scharl]!='\0'){
		scharl++;
	}
	while(tchar[tcharl]!='\0'){
		tcharl++;
	}
	if(tlength<tcharl+scharl){
		//当目标数组的长度小于两者之和时，则要截取部分字符
		for(i=tcharl,j=0;i<tlength-1;i++,j++){
			tchar[i]=schar[j];
			//循环将原数组中的每一个字符追加至目标数组
		}tchar[i]='\0';//别忘了加上'\0' ,这是C 风格字符串结尾的标志
		return;
	}else{
		//当目标数组的长度大于两者之和时，则全部追加
		for(i=tcharl,j=0;j<scharl;i++,j++){
			tchar[i]=schar[j];
			//循环将原数组中的每一个字符追加至目标数组
		}
		tchar[i]='\0';
		return;
	}
		
}


/**
*  一维字符数组作为函数参数，先当与一级指针
*  *schar:源字符串，将要追加至目标字符串的子串,这个参数可以写作char schar[]
*  *tchar:目标字串，追加后得到的字串,这个参数可以写作char tchar[]
*  tlength:目标字串数组的长度，是数组的长度
*/


/* void  myStrcat(char *schar, char *tchar ,int tlength)
{
	//获取原指针
	char *ps=schar;
	char *pt=tchar;
	//初始化原指针所指向的字符串的长度为0
	int scharl=0;
	int tcharl=0;
	//定义迭代变量
	int i=0;
	int j=0;
	if(tlength<1)
	{
		return ;
	}
	
	while(*(ps+scharl++));
	//相当于while(ps[scharl++]!='\0');
	//只要字符不为'\0',则循环，循环结束，将得出源字符串的长度
	while(*(pt+tcharl++));
	//相当于while(ps[tcharl++]!='\0');
	//只要字符不为'\0',则循环，循环结束，将得出目标字符串的长度，非所在数组的长度
	if(tlength<tcharl+scharl){
		//当目标数组的长度小于两者之和时，则要截取部分字符
		for(i=tcharl-1,j=0;i<tlength-1;i++,j++){
			pt[i]=ps[j];
			//循环将原数组中的每一个字符追加至目标数组
		}pt[i]='\0';//别忘了加上'\0' ,这是C 风格字符串结尾的标志
		return;
	}else{
		//当目标数组的长度大于两者之和时，则全部追加
		for(i=tcharl-1,j=0;j<scharl;i++,j++){
			pt[i]=ps[j];
			//循环将原数组中的每一个字符追加至目标数组
		}
		pt[i]='\0';
		return;
	}
} */