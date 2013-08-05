#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
using namespace std;
map<string, string> unitConvert;
void init()
{

    unitConvert["mile"]="miles";
    unitConvert["yard"]="yards";
    unitConvert["inch"]="inches";
    unitConvert["foot"]="feet";
    unitConvert["fath"]="faths";
    unitConvert["furlong"]="furlongs";
}
map<string,double> values;
void work()
{
    for(int i=0; i<6; i++)
    {
        string s;
        char tmp[20];
        double value;
        scanf("%*s%s%*s%lf%*s",tmp,&value);
        s=tmp;
        values[s]=value;
        values[unitConvert[s]]=value;
    }
    scanf("\n");
    char *stk;

    for(int i=0; i<10; i++)
    {
        double ans=0;
        char tmp[200];
        gets(tmp+2);
        tmp[0]='+';
        tmp[1]=' ';
        stk=strtok(tmp," ");
        for(;;)
        {
        	string s1=stk;
            stk=strtok(NULL," ");
            double value;
            sscanf(stk,"%lf",&value);
            stk=strtok(NULL," ");
            string s3=stk;

            if(s1=="+")
            {
                ans+=value*values[s3];
			}
			else
            {
				ans-=value*values[s3];
            }

            stk=strtok(NULL," ");
            if(stk==NULL) break;
		}
		printf("%.2f m\n",ans);
    }

}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cout<<"lee@kilee.net\n"<<endl;
    init();
    work();
    fclose(stdout);
    return 0;
}
