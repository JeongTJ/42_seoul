#include <iostream>
#include <fstream>

std::string getReplaceStr(std::string curr, std::string &s1, std::string &s2)
{
	std::string res("");
	std::string::size_type oldp = 0;
	std::string::size_type newp = 0;

	while (true) {
		newp = curr.find(s1, oldp);
		if (newp == std::string::npos) {
			res.append(curr.substr(oldp));
			break ;
		}
		res.append(curr.substr(oldp, newp - oldp));
		res.append(s2);
		oldp = newp + s1.size(); 
	}
	return (res);
}

std::string getFileInfo(std::ifstream& r) {
	std::string res("");
	std::string tmp;

	while (!r.eof()) {
		std::getline(r, tmp);
		res.append(tmp);
		if (!r.eof())
			res.append("\n");
	}
	return (res);
}

int main( int argc, char *argv[] ) {
	std::ifstream readFile;
	std::ofstream writeFile;
	std::string str;
	std::string replaceStr;

	if (argc != 4)
		return (1);

	std::string fileName(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	if (s1.length() == 0) {
		std::cout << "Wrong input s1, please input non-empty string" << std::endl;
		return (1);
	}

	readFile.open(fileName);
	if (!readFile.is_open()) {
		std::cout << "readFile open failed" << std::endl;
		return (1);
	}

	writeFile.open(fileName + ".replace", std::ios_base::trunc);
	if (!writeFile.is_open()) {
		readFile.close();
		std::cout << "writeFile open failed" << std::endl;
		return (1);
	}

	str = getFileInfo(readFile);
	replaceStr = getReplaceStr(str, s1, s2);
	writeFile.write(replaceStr.c_str(), replaceStr.size());

	readFile.close();
	writeFile.close();
	return (0);
}