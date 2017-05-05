/* MenyBuganim 302490610	BaruchRothkoff 311603252 */

#include <iostream>
#include "ArrayList.h"

int main(){
	{
		std::cout << "========================================================" << std::endl;		//our names.
		std::cout << "Meny Buganim  302490610 ---- Baruch Rothkoff  311603252" << std::endl;
		std::cout << "========================================================" << std::endl << std::endl;
		std::cout << "1-int arrayList." << std::endl;
		std::cout << "2-char arrayList." << std::endl;
		std::cout << "3-Exit." << std::endl;

		int menu;
		int menu2;
		std::cin >> menu;
		while (menu < 1 || menu>3){											//validate input.
			std::cin.clear();
			std::cout << "wrong, try again:" << std::endl;
			std::cout << "1-int arrayList." << std::endl;
			std::cout << "2-char arrayList." << std::endl;
			std::cout << "3-Exit." << std::endl;
			std::cin >> menu;
		}

		if (menu == 1){
			ArrayList<int>INT;
			do{																//option 1 int.
				std::cout << "1-add element." << std::endl;
				std::cout << "2-add element & index." << std::endl;
				std::cout << "3-remove minimum & print." << std::endl;
				std::cout << "4-remove maximum & print." << std::endl;
				std::cout << "5-print array size." << std::endl;
				std::cout << "6-print all the array." << std::endl;
				std::cout << "7-exit." << std::endl;
				std::cin >> menu2;
				switch (menu2){
				case 1:
					int add;
					std::cout << "enter element number please: " << std::endl;
					std::cin >> add;
					while (!std::cin.good()){										//validate input
						std::cout << "wrong type, enter element number please:" << std::endl;
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
						std::cin >> add;
					}
					INT.addElement(add);
					break;
				case 2:
					std::cout << "enter element number please: " << std::endl;		//element & index.
					std::cin >> add;
					while (!std::cin.good()){											//validate input
						std::cout << "wrong type, enter element number please:" << std::endl;
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
						std::cin >> add;
					}
					std::cout << "enter wanted index please: " << std::endl;
					int index;
					std::cin >> index;
					while (!std::cin.good()){
						std::cout << "wrong, try again:" << std::endl;
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
						std::cin >> index;
					}
					INT.addElement(add, index);
					break;
				case 3:
					std::cout << "minimum element is: " << INT.popMin() << std::endl << std::endl;
					break;
				case 4:
					std::cout << "maximum element is: " << INT.popMax() << std::endl << std::endl;
					break;
				case 5:
					std::cout << "the array size is: " << INT.getSize() << std::endl << std::endl;
					break;
				case 6:
					INT.print();
					std::cout << std::endl;
					break;
				case 7:
					break;
				default:
					std::cout << "wrong, try again:" << std::endl;
					break;
				}
			} while (menu2 != 7);								//end do loop. while not 7 keep looping.

		}

		else if (menu == 2){
			ArrayList<char>CHAR;
			do{
				std::cout << "1-add element." << std::endl;
				std::cout << "2-add element & index." << std::endl;
				std::cout << "3-remove minimum & print." << std::endl;
				std::cout << "4-remove maximum & print." << std::endl;
				std::cout << "5-print array size." << std::endl;
				std::cout << "6-print all the array." << std::endl;
				std::cout << "7-exit." << std::endl;
				std::cin >> menu2;
				switch (menu2){
				case 1:
					char add;
					std::cout << "enter wanted char please: " << std::endl;
					std::cin >> add;
					std::cin.ignore(INT_MAX, '\n');
					CHAR.addElement(add);
					break;
				case 2:															//validate input
					std::cout << "enter wanted char please: " << std::endl;
					std::cin >> add;
					std::cin.ignore(INT_MAX, '\n');

					std::cout << "enter wanted index please: " << std::endl;
					int index;
					std::cin >> index;
					while (!std::cin.good()){								//validate input
						std::cout << "ERROR, please choose again index." << std::endl;
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
						std::cin >> index;
					}
					CHAR.addElement(add, index);
					break;
				case 3:
					std::cout << "minimum element is: " << CHAR.popMin() << std::endl << std::endl;
					break;
				case 4:
					std::cout << "maxmimum element is: " << CHAR.popMax() << std::endl << std::endl;
					break;
				case 5:
					std::cout << "the array size is: " << CHAR.getSize() << std::endl << std::endl;
					break;
				case 6:
					CHAR.print();
					std::cout << std::endl;
					break;
				case 7:
					break;
				default:
					std::cout << "wrong, try again:" << std::endl;
					break;
				}
			} while (menu2 != 7);									//end do loop. while not 7 keep looping.
		}
	}

	system("pause");
	return 0;
}
