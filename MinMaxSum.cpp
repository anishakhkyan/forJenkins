#include <iostream>

/* min is a function which will return min of two numbers */
int min(int number1, int number2) {
	if (number2 >= number1) {
		return number1;
	}
	return number2;
}

/*max is a function which will return max of two numbers*/
int max(int number1, int number2) {
	if (number1 >= number2) {
		return number1;
	}
	return number2;
}

/*sum is a function which will return sum of two numbers*/
int sum(int number1, int number2) {
	return number1 + number2;
}

/*check is a function which will check whether input is integer or not*/
int check(int input) {
	while(std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();

		std::cout << "Please enter an integer: ";
		std::cin >> input;
	}
	return input;
}

int main() {
	std::cout << "Please, enter two numbers: " << std::endl;
	int a = 0;
	int b = 0;

	std::cout << "Insert a: ";
	/*input first number*/
	std::cin >> a;
	/*check if a is an integer*/
	a = check(a);

	std::cout << "Insert b: ";
	/*input second number*/
	std::cin >> b;
	/*check if b is an integer*/
	b = check(b);

	/* call min function to get maximum of two inputted numbers */
	std::cout << "Min: " << min (a, b) << std::endl;

	/* call max function to get maximum of two inputted numbers */
	std::cout << "Max: " << max (a, b) << std::endl;

	/* call sum function to get sum of two inputted numbers */
	std::cout << "Sum: " << sum (a, b) << std::endl;
	
	return 0;
}