/* Copyright (C) 2020 Sai Manasa S
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Description: This is a program used to demo CPP class, C structure
 *              and a few string operations 
 *
 * Revision History:
 * Initial version: Oct 8th, 2020
 */

#include<cstdio>
#include<iostream>

#include<string>

// Charan & Vamsi need to explain what this is
using namespace std;

typedef struct struct_ticket
{
	//string customer_name;
	char customer_name2[25]; // 'Char array' type member variable
	char *customer_name3; // 'Pointer to char' type member variable
	long double phone_num;
};

class class_ticket
{
public: // access specifier
	string customer_name;
	int phone_num;

protected:
	//Nothing defined here for now!

private:
	//Nothing defined here for now!
};

/*****************************************************/
// Function:     demo_cppstring()
// Description:  This function demos the various ways
//               of assignment to string type variables
// Inputs:       in_t1 and in_t2 of type class_ticket
// Return value: None
/*****************************************************/
void demo_cppstring(class_ticket in_t1, class_ticket in_t2)
{
	class_ticket t1, t2;
	t1 = in_t1;
	t2 = in_t2;

	char name[] = "Krishna";
	char *newname = "Krish2";
	char name2[25] = "Vishnu";

	// Direct string assignment using ('=') assignment operator
	t1.customer_name = "Class_customer";
	cout << "Customer name (through assignment): " << t1.customer_name << endl;
	
	// Taking user input
	cout << "Enter a customer name: " << endl;
	cin >> t1.customer_name;
	cout << "Customer name (through user input): " << t1.customer_name << endl;
	
	// Assignment of one variable's member to another variable's member
	t2.customer_name = t1.customer_name;
	cout << "Customer name (through user input): " << t2.customer_name << endl;

	// Can I use string library functions to assign?
	//strcpy_s(t1.customer_name, name);
	cout << "Customer name (using string lib?): " << t2.customer_name << endl;

	// Can I assign a char * to a string data type variable?
	t2.customer_name = newname;
	cout << "Customer name (using char * to string assmt?): " << t2.customer_name << endl;

	// Can I assign a char [] to a string data type variable?
	t2.customer_name = name;
	cout << "Customer name (using char [] to string assmt?): " << t2.customer_name << endl;

	// Can I assign a (const) char [25] to a string data type variable?
	t2.customer_name = name2;
	cout << "Customer name (using char [25] to string assmt?): " << t2.customer_name << endl;

}

/*****************************************************/
// Function:     demo_cstring()
// Description:  This function demos the various ways
//               of assignment to char array, char *
//               & char [] type variables to hold strings
// Inputs:       in_t1 and in_t2 of type struct_ticket
// Return value: None
/*****************************************************/
void demo_cstring(struct_ticket in_t1, struct_ticket in_t2)
{
	struct_ticket t1, t2;
	t1 = in_t1;
	t2 = in_t2;

	char name[] = "Krishna";
	char newname[] = "Krish2";

    // 'Char array' type member variable Demo
	// Taking user input to a 'Char array' type member variable
    printf("Enter a name: \n");
	scanf_s("%s", &t1.customer_name2);

	printf("Debg stmt: Line 111\n");

	printf("Customer Name2: %s\n", t1.customer_name2);
	printf("Debg stmt: Line 115\n");

	// Assigning value using '=' (assignment operator) to a 'Char array' type member variable
	//t1.customer_name2 = "Krishna"; // Only can use with the 'string' Data type in C++
	//NOTE: Always remember we CANNOT ASSIGN VALUE to char array using '=' operator
	printf("Customer Name2: %s\n", t1.customer_name2);
	printf("Debg stmt: Line 121\n");

	// Assign value using standard 'string' library functions
	strcpy_s(t1.customer_name2, name);
	printf("Debg stmt: Line 125\n");
	printf("Customer Name2: %s\n", t1.customer_name2);
	printf("Debg stmt: Line 127\n");

	// 'Pointer to char' type member variable Demo
	// Taking user input to a 'Pointer to char' type member variable
    printf("Enter a name: \n");
	scanf_s("%s", &t1.customer_name3);
	printf("Debg stmt: Line 133\n");
	printf("Customer Name3: %s\n", t1.customer_name3);
	printf("Debg stmt: Line 134\n");

	// Assigning value using '=' (assignment operator) to a 'Pointer to char' type member variable
	t1.customer_name3 = "Vish";
	printf("Customer Name3: %s\n", t1.customer_name3);

	// Assign value using standard 'string' library functions
	//strcpy_s(t1.customer_name3, newname);
	printf("Customer Name3: %s\n", t1.customer_name3);

	//t2.customer_name2 = t1.customer_name2; // Cannot use the assignment operators with char arrays
	t2.customer_name3 = t1.customer_name3;

	cout << "Customer Name2: " << (t2.customer_name2) << endl;
	cout << "Customer Name3: " << (t2.customer_name3) << endl;
}

/*****************************************************/
// Function:     demo_Cstruct()
// Description:  This function demos the C language
//               structure member variable assignment 
//               and access
// Inputs:       None
// Return value: None
/*****************************************************/
void demo_Cstruct()
{
	struct_ticket in_t1 = {}, in_t2 = {};
	demo_cstring(in_t1, in_t2);

	in_t1.phone_num = 8877663421;
 	printf("Customer Phone: %d\n", in_t1.phone_num);
}

/*****************************************************/
// Function:     demo_Cppclass()
// Description:  This function demos the C++ language
//               class member variable assignment 
//               and access
// Inputs:       None
// Return value: None
/*****************************************************/
void demo_Cppclass()
{
	class_ticket in_t1, in_t2;
	demo_cppstring(in_t1, in_t2);

 	printf("Customer Phone: %d\n", in_t1.phone_num);
}

/*****************************************************/
// Function:     main()
// Description:  This is the main() function for entry
//               into program execution
// Inputs:       None
// Return value: None
/*****************************************************/
void main()
{
	demo_Cstruct();
	demo_Cppclass();

	while(1);
}
