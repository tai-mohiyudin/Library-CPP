#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
protected:
    string title;
    string author;
    string dueDate;
    bool isCheckedOut;

public:
    LibraryItem(string t, string a)
    {
        title = t;
        author = a;
        dueDate = "Not Issued";
        isCheckedOut = false;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    bool getStatus()
    {
        return isCheckedOut;
    }

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
private:
    string isbn;
    int pages;

public:
    Book(string t, string a, string i, int p) : LibraryItem(t, a)
    {
        isbn = i;
        pages = p;
    }

    void checkOut()
    {
        if (!isCheckedOut)
        {
            isCheckedOut = true;
            dueDate = "15 days from today";
            cout << "Book \"" << title << "\" checked out successfully!" << endl;
        }
        else
        {
            cout << "Book is already checked out!" << endl;
        }
    }
    void returnItem()
    {
        if (isCheckedOut)
        {
            isCheckedOut = false;
            dueDate = "Not Issued";
            cout << "Book \"" << title << "\" returned successfully!" << endl;
        }
        else
        {
            cout << "Book was not checked out!" << endl;
        }
    }

void displayDetails()
    {
        cout << "\n----- Book Details -----" << endl;
        cout << "Title   : " << title << endl;
        cout << "Author  : " << author << endl;
        cout << "ISBN    : " << isbn << endl;
        cout << "Pages   : " << pages << endl;
        cout << "Status  : " << (isCheckedOut ? "Checked Out" : "Available") << endl;
        cout << "Due Date: " << dueDate << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, int d) : LibraryItem(t, a)
    {
        duration = d;
    }

void checkOut()
    {
        if (!isCheckedOut)
        {
            isCheckedOut = true;
            dueDate = "7 days from today";
            cout << "DVD \"" << title << "\" checked out successfully!" << endl;
        }
        else
        {
            cout << "DVD is already checked out!" << endl;
        }
    }

  void returnItem()
    {
        if (isCheckedOut)
        {
            isCheckedOut = false;
            dueDate = "Not Issued";
            cout << "DVD \"" << title << "\" returned successfully!" << endl;
        }
        else
        {
            cout << "DVD was not checked out!" << endl;
        }
    }
 void displayDetails()
    {
        cout << "\n----- DVD Details -----" << endl;
        cout << "Title    : " << title << endl;
        cout << "Director : " << author << endl;
        cout << "Duration : " << duration << " minutes" << endl;
        cout << "Status   : " << (isCheckedOut ? "Checked Out" : "Available") << endl;
        cout << "Due Date : " << dueDate << endl;
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, int issue) : LibraryItem(t, a)
    {
        issueNumber = issue;
    }

 void checkOut()
    {
        if (!isCheckedOut)
        {
            isCheckedOut = true;
            dueDate = "3 days from today";
            cout << "Magazine \"" << title << "\" checked out successfully!" << endl;
        }
        else
        {
            cout << "Magazine is already checked out!" << endl;
        }
    }

    void returnItem()
    {
        if (isCheckedOut)
        {
            isCheckedOut = false;
            dueDate = "Not Issued";
            cout << "Magazine \"" << title << "\" returned successfully!" << endl;
        }
        else
        {
            cout << "Magazine was not checked out!" << endl;
        }
    }

void displayDetails()
    {
        cout << "\n----- Magazine Details -----" << endl;
        cout << "Title        : " << title << endl;
        cout << "Publisher    : " << author << endl;
        cout << "Issue Number : " << issueNumber << endl;
        cout << "Status       : " << (isCheckedOut ? "Checked Out" : "Available") << endl;
        cout << "Due Date     : " << dueDate << endl;
    }
};

int main()
{
    LibraryItem *items[5];
    int itemCount = 0;

    items[itemCount++] = new Book("The Alchemist", "Paulo Coelho", "978-0061122415", 208);
    items[itemCount++] = new Book("Atomic Habits", "James Clear", "978-0735211292", 320);
    items[itemCount++] = new DVD("Inception", "Christopher Nolan", 148);
    items[itemCount++] = new Magazine("National Geographic", "NatGeo Society", 245);
    items[itemCount++] = new DVD("Interstellar", "Christopher Nolan", 169);

    int choice;
    do
    {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========" << endl;
        cout << "1. Display All Items" << endl;
        cout << "2. Check Out Item" << endl;
        cout << "3. Return Item" << endl;
        cout << "4. Search by Title" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

    try
        {
            if (cin.fail())
            {
                throw "Invalid input! Please enter a number.";
            }

            switch (choice)
            {
            case 1:
                cout << "\n--- All Library Items ---" << endl;
                for (int i = 0; i < itemCount; i++)
                {
                    items[i]->displayDetails();
                }
                break;

            case 2:
            {
                int index;
                cout << "Enter item number (1 to " << itemCount << "): ";
                cin >> index;

                if (index < 1 || index > itemCount)
                {
                    throw "Invalid item number!";
                }
                items[index - 1]->checkOut();
                break;
            }

            case 3:
            {
                int index;
                cout << "Enter item number (1 to " << itemCount << "): ";
                cin >> index;

                if (index < 1 || index > itemCount)
                {
                    throw "Invalid item number!";
                }
                items[index - 1]->returnItem();
                break;
            }

            case 4:
            {
                string searchTitle;
                cout << "Enter title to search: ";
                cin.ignore();
                getline(cin, searchTitle);

                bool found = false;
                for (int i = 0; i < itemCount; i++)
                {
                    if (items[i]->getTitle() == searchTitle)
                    {
                        items[i]->displayDetails();
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Item not found!" << endl;
                }
                break;
            }

            case 5:
                cout << "Thank you for using Library Management System!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        }
        catch (const char *msg)
        {
            cout << "Error: " << msg << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (choice != 5);

    for (int i = 0; i < itemCount; i++)
    {
        delete items[i];
    }

    return 0;
}