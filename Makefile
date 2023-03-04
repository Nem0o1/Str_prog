all: lab_1

lab_1: lab_1.cpp for_lab_1.cpp
	g++ -Wall -Werror -Wextra lab_1.cpp for_lab_1.cpp -o lab_1.exe
