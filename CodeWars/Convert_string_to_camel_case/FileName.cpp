/*
"the-stealth-warrior" "theStealthWarrior"

"The_Stealth_Warrior"  "TheStealthWarrior"

"The_Stealth-Warrior"  "TheStealthWarrior"
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>


// find - найти элемент
//Замена символов в строке. - replace()
//  Вставка символов в строке. Функция insert(). 

/*
Assert::That(to_camel_case("the_stealth_warrior"), Equals("theStealthWarrior"));
Assert::That(to_camel_case("The-Stealth-Warrior"), Equals("TheStealthWarrior"));
Assert::That(to_camel_case("A-B-C"), Equals("ABC"));
*/

std::string to_camel_case(std::string text)
{
	int pos = 1;
	int temp = 0;
	

	for (;;)
	{
		if ( (temp = text.find('-')) > 0)
		{
			pos = text.find('-');
		}
		else if ((temp = text.find('_')) > 0)
		{
			pos = text.find('_');
		}
		else
			pos = -1;
			
		if (pos < 0) break;
		text.erase(pos, 1);

		text[pos] = std::toupper(text[pos]);
		
	}


	return text;
}




int main()
{
	std::cout << to_camel_case("the_stealth_warrior") << std::endl;

	return 0;
}