

unsigned int my_pow(unsigned int x,unsigned  int y)
{
		int i,s=1;
		for(i=1;i<=y;i++)
		{
				s *= x;
		}
		return s;
}
