#include<iostream>
#include<array>

int main()
{
	std::cout << "Hello AIE" << std::endl;
	std::cout << "Regulate - Warren G. feat Nate Dogg\n"
				 "Still D.R.E. by Dr. Dre feat. Snoop Dogg\n"
				 "Laffy Taffy by D4L\n""Billie Jean by Michael Jackson\n"
				 "Mambo No. 5 for some reason" << std::endl;
	std::cout << "0\n1\n2\n3\n4\n5" << std::endl;
	std::cout << "5\n4\n3\n2\n1\n0" << std::endl; // \n is SPIFFY but GROSS don't forget it

	std::cout << "Howdy AIE" << std::endl;
	std::cout << "It's a fine day today as any!" << std::endl;
	std::cout << "I really wish I had some potatoes..." << std::endl;

	std::cout << "Four score and seven years ago" << std::endl;
	std::cout << "our fathers brought forth on this continent," << std::endl;
	std::cout << "a new nation," << std::endl;
	std::cout << "conceived in Libery, and dedicated to the proposition" << std::endl;
	std::cout << "that all men are created equal." << std::endl;

	std::cout << "Now we are engaged in a great civil war," << std::endl;
	std::cout << "testing whether that nation, or any nation" << std::endl;
	std::cout << "so conceived and so dedicated, can long endure." << std::endl;

	const char* myArray[] = {"This", "That", "The other", "Another thing", "something else"};

	for (int i = 0; i < std::size(myArray); i++)
	{
		std::cout << myArray[i] << std::endl;
	}



	system("pause");

	return 0;
}