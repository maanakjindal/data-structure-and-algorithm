#include <bits/stdc++.h> // Name - Nitin
using namespace std;     // SID - 21105091   // Branch - ECE

// // To Make a Member Class for Making a Node for taking Name and Age
class Member
{
public:
    string Member_name;
    int Member_Age;
    Member *Next_Member;
    Member *Prev_Member;
    Member(string Member_name, int Member_Age)
    {
        this->Member_name = Member_name;
        Next_Member = NULL;
        this->Member_Age = Member_Age;
        Prev_Member = NULL;
    }
};


// // To Add Family Member 
void Add_Family_Member(Member *&Family_head, string Member_name, int Member_Age)
{
    if (Family_head == NULL)
    {
        Family_head = new Member(Member_name, Member_Age);
        return;
    }
    Member *Temporary_Member = Family_head;
    while (Temporary_Member->Next_Member != NULL)
    {
        Temporary_Member = Temporary_Member->Next_Member;
    }
    Temporary_Member->Next_Member = new Member(Member_name, Member_Age);
    Temporary_Member->Next_Member->Prev_Member = Temporary_Member;
}

// To Display Members List Starting From Family Head
void displayByFamily_Head(Member *Family_head)
{
    if (Family_head == NULL)
        return;
    Member *Temporary_Member = Family_head;
    while (Temporary_Member->Next_Member != NULL)
    {
        cout << "Name : " << Temporary_Member->Member_name << " , "
             << "Age : " << Temporary_Member->Member_Age << " <===>\n";
        Temporary_Member = Temporary_Member->Next_Member;
    }
    cout << "Name : " << Temporary_Member->Member_name << " , "
         << "Age : " << Temporary_Member->Member_Age;
}

// To Display Members List Starting From Family Junior
void displayByFamily_junior(Member *Family_junior)
{
    if (Family_junior == NULL)
        return;
    Member *Temporary_Member = Family_junior;
    while (Temporary_Member->Prev_Member != NULL)
    {
        cout << "Name : " << Temporary_Member->Member_name << " , "
             << "Age : " << Temporary_Member->Member_Age << " <===>\n";
        Temporary_Member = Temporary_Member->Prev_Member;
    }
    cout << "Name : " << Temporary_Member->Member_name << " , "
         << "Age : " << Temporary_Member->Member_Age;
}

// To Find Family Junior By Using Family Head  
Member *Family_junior(Member *Family_head)
{
    Member *Temporary_Member = Family_head;
    while (Temporary_Member->Next_Member != NULL)
    {
        Temporary_Member = Temporary_Member->Next_Member;
    }
    return Temporary_Member;
}

int main()
{

    Member *Family_head = NULL;
    Add_Family_Member(Family_head,"Baldev Kumar", 75);
    Add_Family_Member(Family_head, "Santosh Mittal", 70);
    Add_Family_Member(Family_head, "Rakesh Kumar", 55);
    Add_Family_Member(Family_head, "Manisha Mittal", 53);
    Add_Family_Member(Family_head, "Shivam", 21);
    Add_Family_Member(Family_head, "Nitin", 19);

    cout << "Displaying From Family Head First\n"
         << endl;
    displayByFamily_Head(Family_head);
    cout << '\n'
         << endl
         << endl
         << endl;
    cout << "Displaying From Family Junior First\n"
         << endl;
    displayByFamily_junior(Family_junior(Family_head));

    return 0;
}

//                                           ----- BONUS -----
//  Yes , It is Possible by comparing Age We can easily find their relationship and link them accordingly.
//  But in Miscellanous Case we have to take input of relationship to arrange them otherwise it is not possible.