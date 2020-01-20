



#include <stdio.h>
int main()
{
		if(IGNSts&& BatSts&& FuncFlag )
		{
		     printf("0\n");
		}
		else if(IGNSts&& BatSts&& FuncFlag && !(Signalinvailed) )
		{
				printf("0\n");
		}
		else if(IGNSts&& BatSts&& FuncFlg &&!(SignalTimeout))
		{
				printf("0\n");
		}
		else if(IGNSts&& BatSts&& FuncFlag&& Signal1==1 )
		{
				printf("1\n");
		}
		else if(IGNSts&& BatSts&& FuncFlag&& Signal1==1 &&Signal2==0 &&SignalTimeout==0&& Sinalinvailed==0)
		{
				printf("2\n");
		}
		else if(IGNSts&& BatSts&& FuncFlag&& Signal1==2 &&Signal2==1 &&SignalTimeout==0&& Sinalinvailed==0)
		{
				printf("3\n");
		}
		else if(IGNSts&& BatSts&& FuncFlag&& Signal1==3 &&Signal2==0 &&SignalTimeout==0&& Sinalinvailed==0)
		{
				printf("4\n");
		}
		else if(IGNSts&& BatSts&& FuncFlag&& Signal1==4 &&Signal2==1 &&SignalTimeout==0&& Sinalinvailed==0)
		{
				printf("5\n");
		}
		else if(IGNSts&& BatSts&& FuncFlag&& Signal1==5 &&Signal2==0 &&SignalTimeout==0&& Sinalinvailed==0)
		{
				printf("6\n");
		}
		else if(IGNSts&& BatSts&& FuncFlag&& Signal1==6 &&Signal2==1 &&SignalTimeout==0&& Sinalinvailed==0)
		{
				printf("7\n");
		}
		return 0;
}
