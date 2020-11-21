#include "msp.h"

msp::msp(int m_l, int m_r, int s):max_left(m_l), max_right(m_r), sum(s)
{
}
int msp::Max_left() 
{
	return max_left;
}
int msp::Max_right() 
{
	return max_right;
}
int msp::Sum() 
{
	return sum;
}

