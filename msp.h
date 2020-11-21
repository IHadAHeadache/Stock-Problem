#ifndef MSP_H
#define MSP_H

class msp
{
public:
	explicit msp(int = 0, int = 0, int = 0);
	int Max_left() ;
	int Max_right() ;
	int Sum() ;
private:
	int max_left;
	int max_right;
	int sum;
};

#endif
