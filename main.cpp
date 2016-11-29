
/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 
C++ GPA Calculator
 : This is my first side project with C++ as well as my first experience with arrays of pointers. The 
 : program prints a prompt requesting a number of courses to be graded by the user. The program 
 : then asks the user for a number of grades and credits per class which are stored in corresponding 
 : arrays. The program calculates and prints the user's GPA using the following formula on line 108.
 
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/



#include <iostream>
#include <iomanip>
#include <string>



float calculateGPA(int, char[], float[], std::string[]);
void getClassData(int, char[], float[], std::string[]);
float calcCreditsEarned(int, char[], float[]);
float calcCreditsPossible(int, float[]);
void printInstructions();
int getNumClasses();
void printGPA(float);
void getGPA();



int main() {
    
    printInstructions();  // Text Instructions
    getGPA(); // Runs Program

    return 0;
}



void printInstructions()  // Called once. Function prints instructions to the console.
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "  COLLEGIATE GPA CALCULATOR" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "\nInstructions:\n1. Enter the number of classes to be graded." << std::endl;
    std::cout << "2. Following the prompt, enter the credits per class and the grade received (A,B,C,D,F). " << std::endl;
    std::cout << "3. Your GPA will be printed to the window. You may then exit or add additional courses  " << std::endl;
    std::cout << "\nNote : You may exit the program at anytime by typing \"exit\" or -1 into the prompt." << std::endl;
    std::cout << "________________________________________________________________" << std::endl;
}



void getGPA ()
{
    int classAmount = getNumClasses();  // Defines the number of classses to be graded.
    
    char* letterGrade = new char[classAmount];  // Arrays of pointers. Size determined by user upon runtime.
    float* creditHours = new float[classAmount];
    std::string* courseName = new std::string[classAmount];
    
    getClassData(classAmount, letterGrade, creditHours, courseName);  // Fetches grades, course names, and course credits.
    printGPA(calculateGPA(classAmount, letterGrade, creditHours, courseName));  // Calculated float type GPA is printed.
}



int getNumClasses()
{
    int amountInput;
    
    std::cout << "\nEnter the number of coures to be graded : ";
    std::cin >> amountInput;
    
    std::cin.ignore(); // Clears Buffer
    
    return amountInput;
}



void getClassData(int classAmount, char letterGrade[], float creditHours[], std::string courseName[]) 
{
    for (int i = 0; i < classAmount; i++)  // Repeats for the number of classes to be graded.
    {
        std::cout << "\nEnter Course Name : ";  //  Inputs are strored in the argued arrays.
        std::getline(std::cin,courseName[i]);
        std::cout << "Enter Course Grade : ";
        std::cin >> letterGrade[i];
        std::cout << "Enter Course Credits : ";
        std::cin >> creditHours[i];
        
        std::cin.ignore();  // Clears Buffer
    }
}



float calculateGPA(int classAmount, char letterGrade[], float creditHours[], std::string courseName[])
{
    float finalGPA = 0.0,
            creditsEarned = calcCreditsEarned(classAmount, letterGrade, creditHours),
            totalCreditsPossible = calcCreditsPossible(classAmount, creditHours);
    
    finalGPA = creditsEarned / totalCreditsPossible;    // The final GPA is calculated with this formula.
    
    return finalGPA;
}



float calcCreditsPossible(int classAmount, float creditHours[])
{
    float totalPossibleCredits = 0.0;
    
    for (int i = 0; i < classAmount; i++)
    {
        totalPossibleCredits += creditHours[i];  // Calculates total possible credits
    }
    
    return totalPossibleCredits;
}



float calcCreditsEarned(int classAmount, char letterGrade[], float creditHours[])
{
    float totalCreditsEarned = 0.0;
    
    for (int i = 0; i < classAmount; i++)
    {
        // Switch calculates credits earned depending on the letter grade recieved and adds to the sum of totalCreditsEarned.
        switch (letterGrade[i])
        {
            case 'A':
                totalCreditsEarned += creditHours[i] * 4.0;
                break;
            case 'B':
                totalCreditsEarned += creditHours[i] * 3.0;
                break;
            case 'C':
                totalCreditsEarned += creditHours[i] * 2.0;
                break;
            case 'D':
                totalCreditsEarned += creditHours[i] * 1.0;
                break;
            case 'F':
                totalCreditsEarned += creditHours[i] * 0.0;
                break;
            default: std::cout << "Error in Switch" << std::endl;
                break;
        }
    }
    
    return totalCreditsEarned;
}



void printGPA(float GPA)
{
    std::cout << "\n---------------------" << std::endl;
    std::cout << "Final GPA : " << std::setprecision(2) << std::fixed << GPA << std::endl;
    std::cout << "---------------------\n" << std::endl;
}



