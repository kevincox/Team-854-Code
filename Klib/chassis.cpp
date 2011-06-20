using namespace std;
#include <vector>

class Chassis
{
	vector<double> wheel; ///< Wheels

public:

	unsigned int addWheel(double nw);
	void move(Vector d, double r);
};

unsigned int Chassis::addWheel(double nw)
{
	wheel.push_back(nw);
	return wheel.size() - 1 ;
}

void Chassis::move(Vector d, double r)
{
	int i;

}
