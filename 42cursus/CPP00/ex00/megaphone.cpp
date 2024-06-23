#include <iostream>
#include <string>

int	main(int argc, char *argv[]) {
	if (argc < 1)
		return (1);
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];

		for (std::string::iterator curr = str.begin(); curr != str.end(); curr++)
			std::cout << static_cast<char>(std::toupper(*curr));
		std::cout << std::endl;
	}
	return (0);
}
