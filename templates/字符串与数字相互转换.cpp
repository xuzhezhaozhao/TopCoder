#include <sstream>
#Include <string>
// 缺点是处理大量数据转换速度较慢..
// 数字到字符串
string num2str(double i)
{
        stringstream ss;
        ss << i;
        return ss.str();
}
// 字符串到数字
int str2num(string s)
 {   
        int num;
        stringstream ss(s);
        ss>>num;
        return num;
}

// C library中的sprintf, sscanf 相对更快
//数字到字符串
int H, M, S;
string time_str;
H=seconds/3600;
M=(seconds%3600)/60;
S=(seconds%3600)%60;
char ctime[10];
sprintf(ctime, "%d:%d:%d", H, M, S);             // 将整数转换成字符串
time_str=ctime; 

// 字符串到数字
char    str[] = "15.455";
int     i;
float     fp;
sscanf( str, "%d", &i );         // 将字符串转换成整数   i = 15
sscanf( str, "%f", &fp );      // 将字符串转换成浮点数 fp = 15.455000
//打印
printf( "Integer: = %d ",  i+1 );
printf( "Real: = %f ",  fp+1 ); 
return 0;                                                // 结果

// C标准库了提供了 atoi, atof, atol
char    str[] = "15.455";
double     db;
int     i;
db = atof(str);   // db = 15.455
i = atoi(str);    // i = 15