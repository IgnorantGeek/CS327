#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string temp = "SPEED 17+111d3005";
	int i, bfin, dfin;
	bfin = dfin = 0;
	string base,dice,sides;
	for (i = temp.find(" ")+1; i < temp.length(); i++)
			{
				if (temp.at(i) == '+')
				{
					bfin = 1;
					i++;
				}
				if (!bfin)
				{
					base += temp.at(i);
				}
				if (temp.at(i) == 'd')
				{
					dfin = 1;
					i++;
				}
				if (!dfin && bfin)
				{
					dice += temp.at(i);
				}
				else if (dfin)
				{
					sides += temp.at(i);
				}
			}
	int tempbase, tempdice, tempsides;
	stringstream b(base);
	stringstream d(dice);
	stringstream s(sides);
	b >> tempbase;
	d >> tempdice;
	s >> tempsides;
	cout << tempbase << endl;
	cout << tempdice << endl;
	cout << tempsides << endl;
}
