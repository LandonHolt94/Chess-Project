#pragma once
void Display_Grid(char Grid[][8])
{
	system("CLS"); //Invoking an operating system command 
	std::cout << "    ";
	for (int j = 0; j < 8; j++)
		std::cout << (char)(j + 97) << " ";
	std::cout << std::endl;
	std::cout << "   ";
	for (int i = 0; i < 16; i++)
		std::cout << HORIZONTAL_LINE;
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << (8 - i) << " " << VERTICAL_LINE << " ";
		for (int j = 0; j < 8; j++)
		{
			std::cout << Grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}