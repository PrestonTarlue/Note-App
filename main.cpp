#include <iostream>
#include <string>
#include <fstream>


void GetNote()
{
    std::string note;
    std::cout << "Enter your note: ";
    std::getline(std::cin, note);

    std::ofstream outFile("note.txt");
    if (outFile.is_open())
    {
        outFile << note << std::endl;
        outFile.close();
        std::cout << "Note saved to note.txt" << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void ReadNote()
{
    std::ifstream inFile("note.txt");
    if (inFile.is_open())
    {
        std::string note;
        std::getline(inFile, note);
        inFile.close();
        std::cout << "Your note: " << note << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}


int main()
{
    while (true)
    {
        std::cout << "1. Write a note" << std::endl;
        std::cout << "2. Read the note" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer

        switch (choice)
        {
            case 1:
                GetNote();
                break;
            case 2:
                ReadNote();
                break;
            case 3:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
    
}