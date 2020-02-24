//西安科技大学-计算机科学与技术学院
/*
#include <iostream>  
#include <string>  
#include <cmath>  
   
using namespace std;  
   
const  double  PRECISION = 1E-6;  
const  int  COUNT_OF_NUMBER  = 4;  
const  int  NUMBER_TO_BE_CAL = 24;  
double  number[COUNT_OF_NUMBER];  
string  expression[COUNT_OF_NUMBER];  
bool Judgement = false;                    //判断是否有解。
int count = 0;   
   
void  Search(int   n)  
{  
   if (n   ==   1)
   {  
     if ( fabs(number[0] - NUMBER_TO_BE_CAL) <= PRECISION   )  //对于除法，要小心小数的精确位数
	 {  
     cout << expression[0] << "\t\t"; 
     Judgement = true;
     count ++;
     if((count % 3)==0)
     cout<<endl;
     }  
   else 
   { }
   
   }  
   
   for(int i=0;  i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
    {  
       double   a,   b;  
       string   expa,   expb;  
	   a   =   number[i];  
       b   =   number[j];  
       number[j]  =  number[n - 1];   //递归之后，n比以前小一位，所以可以不停向前赋值 
	   expa   =   expression[i];  
       expb   =   expression[j];  
       expression[j]  =  expression[n - 1];   //递归之后，n比以前小一位，所以可以不停向前赋值
	   expression[i]   =   '('   +   expa   +   '+'   +   expb   +   ')';   //加法不需要分顺序
       number[i]   =   a   +   b;  
       Search(n-1);
       expression[i]   =   '('   +   expa   +   '-'   +   expb   +   ')';   //减法应该分顺序，减数以及被减数
       number[i]   =   a   -   b;  
       Search(n-1); 
	   expression[i]   =   '('   +   expb   +   '-'   +   expa   +   ')';   //减法应该分顺序，减数以及被减数
       number[i]   =   b   -   a;  
       Search(n-1); 
	   expression[i]   =   '('   +   expa   +   '*'   +   expb   +   ')';   //乘法不需要分顺序
       number[i]   =   a   *   b;  
       Search(n-1); 
	   if (b != 0)
      {  
         expression[i]   =   '('   +   expa   +   '/'   +   expb   +   ')';   //除法应该分顺序，除数以及被除数
         number[i] = a / b;  
         Search(n-1);  
      }    
       if (a != 0)
      {  
         expression[i]   =   '('   +   expb   +   '/'   +   expa   +   ')';   //除法应该分顺序，除数以及被除数
         number[i]   =   b  /  a;  
         Search(n-1);  
      }  
   
         number[i]   =   a;                  //这4句语句是为了防止如果上面几种可能都失败了的话,
         number[j]   =   b;                  //就把原来的赋值撤消回去,以无干扰的正确的进入到下一次
         expression[i]   =   expa;           //for循环队列中。
         expression[j]   =   expb;           //
      }  
    }
}  
   
int  main()  
{  
  cout<<"请依次输入4个数字:\n";
  for (int i = 0; i < COUNT_OF_NUMBER; i++) 
  {  
    char   buffer[20];   
    cout<<"第"<<i+1<<"个卡片:";
    cin   >>   number[i];                  
    itoa(number[i],   buffer,   10);   //itoa()函数的作用是把第一个参数(数值)传送到第二个参数(字符串)中去，第三个
               //参数(int型)是该数值在字符串里以什么进制存放。
    expression[i]   =   buffer;  
  }
  cout<<endl;
  Search(COUNT_OF_NUMBER) ;
  if(Judgement==true)
  {  
    cout   <<   "\n成功"   <<   endl;
    cout<<"所以可以计算的次数总和 = "<<count<<endl;
  }  
  else
  {  
    cout   <<   "失败"   <<   endl;  
  }       
  system("pause");
  return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;


int main()
{
    int num;
    while(cin>>num)
    {
        vector<int> arr;
        int tmp;
        for(int i=0;i<num;i++)
        {
            cin>>tmp;
            arr.push_back(tmp);
        }

	int sum = 0;
	int max = 0;
    int count=0;
    int min=arr[0];
	for (int i = 0; i < num; i++)
	{
		sum = sum + arr[i];
		max = max>sum ? max : sum;
		if (sum < 0)
		{
			sum = 0;
		}
        if(arr[i]<0)
        {
            count++;
            min=min>arr[i]?min:arr[i];
        }
	}
    if(count==num)
    {
        cout<<min<<endl;
    }
    else
    {
        cout<<max<<endl;
    }
    
    }

    system("pause");
    return 0;
}

/*
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        if(!s1.size())
           continue;
        set<char> arr(s2.begin(),s2.end());
        string::iterator it = s1.begin();
        while(it<s1.end())
        {
            if(arr.count(*it) != 0)
            {
                s1.erase(it);
                continue;
            }
            it++;
        }
        cout<<s1<<endl;
    }
    system("pause");
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int a[256]={0};
        string::iterator it = s2.begin();
        while(it <s2.end())
        {
            ++a[*it];
            it++;
        }
        it = s1.begin();
        while(it<s1.end())
        {
            if(0 != a[*it])
            {
                s1.erase(it);
                continue;
            }
            it++;
        }
        cout<<s1<<endl;
    }
        system("pause");
    return 0;
}*/