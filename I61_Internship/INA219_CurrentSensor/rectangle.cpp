#include <iostream>
#include "../Debug_MessagePrinter/Debug_MessagePrinter.h"

class rectangle{
	public:
		int area(void);
		void sides(int one, int two);

	private:
		int a;
		int b;

}rect;

int rectangle::area(void){return a * b;}

void rectangle::sides(int one, int two){a = one; b = two;}

int main(void)
{
	rect.sides(5, 5);
	std::cout << std::to_string(rect.area()) << std::endl;
	MSG_Prnt msg;
	msg.info_msg(true, "Hello");
	return 0;
}
