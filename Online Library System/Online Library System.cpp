#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

string To_Find_Name;
string To_Find_Title;

class User {

private:
    string Name, Gender, Age, Email, Password, National_ID, Date_of_Birth;
    static int Incremental_ID;
    const int College_ID;

    static const string Letters;
    static const string Numbers;

public:
    User(string name = "New User", string age = "N/A", string national_ID = "00000000000000") 
    : Name(name), Gender("N/A"), Age(age), College_ID(Incremental_ID), National_ID(national_ID), Date_of_Birth("DD/MM/YYYY") {

        Incremental_ID++;

        random_device Rng;
        uniform_int_distribution<int> Letters_Distibution(0, Letters.length() - 1);
        uniform_int_distribution<int> Numbers_Distibution(0, Numbers.length() - 1);

        short i = 0;

        while (Email.length() != 15) {

            int Random_Value = Letters_Distibution(Rng);

            if (Email.length() == 0 && Random_Value == 0 || Email.length() == 14 && Random_Value == 0) {

                continue;
            }
            else {

                Email += Letters[Random_Value];

                if (i) {

                    if (Email[i] == '.' && Email[i - 1] == '.') {

                        Email[i] = Letters[41];
                    }
                }

                i++;
            }
        }

        Email += "@eng-st.cu.eg.edu";

        while (Password.length() != 9) {

            Password += Numbers[Numbers_Distibution(Rng)];
        }

        if (National_ID != "00000000000000") {

            if (National_ID[0] == '3') {

                Date_of_Birth = "";
                Date_of_Birth += National_ID[5];
                Date_of_Birth += National_ID[6];
                Date_of_Birth += '/';
                Date_of_Birth += National_ID[3];
                Date_of_Birth += National_ID[4];
                Date_of_Birth += "/20";
                Date_of_Birth += National_ID[1];
                Date_of_Birth += National_ID[2];
            }
            else if (National_ID[0] == '2') {

                Date_of_Birth = "";
                Date_of_Birth += National_ID[5];
                Date_of_Birth += National_ID[6];
                Date_of_Birth += '/';
                Date_of_Birth += National_ID[3];
                Date_of_Birth += National_ID[4];
                Date_of_Birth += "/19";
                Date_of_Birth += National_ID[1];
                Date_of_Birth += National_ID[2];
            }

            if (National_ID[12] == '1' || National_ID[12] == '3' || National_ID[12] == '5' || National_ID[12] == '7' || National_ID[12] == '9') {

                Gender = "Male";
            }
            else if (National_ID[12] == '0' || National_ID[12] == '2' || National_ID[12] == '4' || National_ID[12] == '6' || National_ID[12] == '8') {

                Gender = "Female";
            }
        }
    }

    User(const User& U) : Name(U.Name), Gender(U.Gender), Age(U.Age), Email(U.Email), Password(U.Password), College_ID(U.College_ID), National_ID(U.National_ID), Date_of_Birth(U.Date_of_Birth) {}

    ~User() {}

    friend istream& operator>>(istream& Obj, User& U) {

        cout << "\n New Student:-\n\n Enter Student's Name: ";

        string N;

        cin.ignore();
        getline(Obj, N);

        try {

            for (int i = 0; i < N.length(); i++) {

                if (N[i] < 65 && N[i] != 32 || N[i] > 122 || N[i] >= 91 && N[i] <= 96) {

                    throw "\n Invalid Student Name!\n Only Letters From \'a\' To \'z\' Or From \'A\' To \'Z\' Are Allowed\n";
                }

                if (i == 0 && N[i] == ' ') {

                    throw "\n Invalid Student Name!\n Name Must Not Start With A Space\n";
                }

                if (i) {

                    if (N[i] == ' ' && N[i - 1] == ' ') {

                        throw "\n Invalid Student Name!\n Too Many Spaces Between Student's Name\n";
                    }
                }

                if (i == (N.length() - 1) && N[i] == ' ') {

                    throw "\n Invalid Student Name!\n Name Must Not End With A Space\n";
                }
            }

            U.Set_Name(N);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Student's Name: ";

                getline(Obj, N);

                for (int i = 0; i < N.length(); i++) {

                    if (N[i] < 65 && N[i] != 32 || N[i] > 122 || N[i] >= 91 && N[i] <= 96) {

                        cout << "\n Invalid Student Name!\n Only Letters From \'a\' To \'z\' Or From \'A\' To \'Z\' Are Allowed\n";

                        Valid = false;

                        break;
                    }

                    if (i == 0 && N[i] == ' ') {

                        cout << "\n Invalid Student Name!\n Name Must Not Start With A Space\n";

                        Valid = false;

                        break;
                    }

                    if (i) {

                        if (N[i] == ' ' && N[i - 1] == ' ') {

                            cout << "\n Invalid Student Name!\n Too Many Spaces Between Student's Name\n";

                            Valid = false;

                            break;
                        }
                    }

                    if (i == (N.length() - 1) && N[i] == ' ') {

                        cout << "\n Invalid Student Name!\n Name Must Not End With A Space\n";

                        Valid = false;

                        break;
                    }
                }
            } 
            while (!Valid);

            U.Set_Name(N);
        }

        cout << "\n Enter Student's Age: ";

        string A;

        Obj >> A;

        try {

            if (A[0] == '0') {

                throw "\n Invalid Student Age!\n Age Must Not Start With \'0\'\n";
            }

            for (int i = 0; i < A.length(); i++) {

                if (A[i] < 48 || A[i] > 57) {

                    throw "\n Invalid Student Age!\n Only Numbers From \'0\' To \'9\' Are Allowed\n";

                }
            }

            U.Set_Age(A);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Student's Age: ";

                Obj >> A;

                if (A[0] == '0') {

                    cout << "\n Invalid Student Age!\n Age Must Not Start with \'0\'\n";

                    Valid = false;
                }
                else {

                    for (int i = 0; i < A.length(); i++) {

                        if (A[i] < 48 || A[i] > 57) {

                            cout << "\n Invalid Student Age!\n Only Numbers From \'0\' To \'9\' Are Allowed\n";

                            Valid = false;

                            break;
                        }
                    }
                }
            } 
            while (!Valid);

            U.Set_Age(A);
        }

        cout << "\n Enter Student's National ID: ";

        string I;

        Obj >> I;

        try {

            if (I.length() != 14) {

                throw "\n Invalid Student National ID!\n National ID Must Be 14 Digits Long\n";
            }

            if (I[0] != '2' && I[0] != '3') {

                throw "\n Invalid Student National ID!\n The First Number Must Be \'2\' Or \'3\'\n";
            }

            for (int i = 0; i < I.length(); i++) {

                if (I[i] < 48 || I[i] > 57) {

                    throw "\n Invalid Student National ID!\n Only Numbers From \'0\' To \'9\' Are Allowed\n";
                }
            }

            U.Set_National_ID(I);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Student's National ID: ";

                Obj >> I;

                if (I.length() != 14) {

                    cout << "\n Invalid Student National ID!\n National ID Must Be 14 Digits Long\n";

                    Valid = false;
                }
                else if (I[0] != '2' && I[0] != '3') {

                    cout << "\n Invalid Student National ID!\n The First Number Must Be \'2\' Or \'3\'\n";

                    Valid = false;
                }
                else {

                    for (int i = 0; i < I.length(); i++) {

                        if (I[i] < 48 || I[i] > 57) {

                            cout << "\n Invalid Student National ID!\n Only Numbers From \'0\' To \'9\' Are Allowed\n";

                            Valid = false;
                            
                            break;
                        }
                    }
                }
            } 
            while (!Valid);

            U.Set_National_ID(I);
        }

        if (U.National_ID[0] == '3') {

            U.Date_of_Birth = "";
            U.Date_of_Birth += U.National_ID[5];
            U.Date_of_Birth += U.National_ID[6];
            U.Date_of_Birth += '/'; 
            U.Date_of_Birth += U.National_ID[3];
            U.Date_of_Birth += U.National_ID[4];
            U.Date_of_Birth += "/20";
            U.Date_of_Birth += U.National_ID[1];
            U.Date_of_Birth += U.National_ID[2];
        }
        else if (U.National_ID[0] == '2') {

            U.Date_of_Birth = "";
            U.Date_of_Birth += U.National_ID[5];
            U.Date_of_Birth += U.National_ID[6];
            U.Date_of_Birth += '/';
            U.Date_of_Birth += U.National_ID[3];
            U.Date_of_Birth += U.National_ID[4];
            U.Date_of_Birth += "/19";
            U.Date_of_Birth += U.National_ID[1];
            U.Date_of_Birth += U.National_ID[2];
        }

        if (U.National_ID[12] == '1' || U.National_ID[12] == '3' || U.National_ID[12] == '5' || U.National_ID[12] == '7' || U.National_ID[12] == '9') {

            U.Gender = "Male";
        }
        else if (U.National_ID[12] == '0' || U.National_ID[12] == '2' || U.National_ID[12] == '4' || U.National_ID[12] == '6' || U.National_ID[12] == '8') {

            U.Gender = "Female";
        }

        return Obj;
    }

    friend istream& operator+(istream& Obj, User& U) {

        cout << "\n Assign Student To Book:-\n\n Enter Student's Name: ";

        getline(Obj, To_Find_Name);

        try {

            for (int i = 0; i < To_Find_Name.length(); i++) {

                if (To_Find_Name[i] < 65 && To_Find_Name[i] != 32 || To_Find_Name[i] > 122 || To_Find_Name[i] >= 91 && To_Find_Name[i] <= 96) {

                    throw "\n Invalid Student Name!\n Only Letters From \'a\' To \'z\' Or From \'A\' To \'Z\' Are Allowed\n";
                }

                if (i == 0 && To_Find_Name[i] == ' ') {

                    throw "\n Invalid Student Name!\n Name Must Not Start With A Space\n";
                }

                if (i) {

                    if (To_Find_Name[i] == ' ' && To_Find_Name[i - 1] == ' ') {

                        throw "\n Invalid Student Name!\n Too Many Spaces Between Student's Name\n";
                    }
                }

                if (i == (To_Find_Name.length() - 1) && To_Find_Name[i] == ' ') {

                    throw "\n Invalid Student Name!\n Name Must Not End With A Space\n";
                }
            }
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Student's Name: ";

                getline(Obj, To_Find_Name);

                for (int i = 0; i < To_Find_Name.length(); i++) {

                    if (To_Find_Name[i] < 65 && To_Find_Name[i] != 32 || To_Find_Name[i] > 122 || To_Find_Name[i] >= 91 && To_Find_Name[i] <= 96) {

                        cout << "\n Invalid Student Name!\n Only Letters From \'a\' To \'z\' Or From \'A\' To \'Z\' Are Allowed\n";

                        Valid = false;

                        break;
                    }

                    if (i == 0 && To_Find_Name[i] == ' ') {

                        cout << "\n Invalid Student Name!\n Name Must Not Start With A Space\n";

                        Valid = false;

                        break;
                    }

                    if (i) {

                        if (To_Find_Name[i] == ' ' && To_Find_Name[i - 1] == ' ') {

                            cout << "\n Invalid Student Name!\n Too Many Spaces Between Student's Name\n";

                            Valid = false;

                            break;
                        }
                    }

                    if (i == (To_Find_Name.length() - 1) && To_Find_Name[i] == ' ') {

                        cout << "\n Invalid Student Name!\n Name Must Not End With A Space\n";

                        Valid = false;

                        break;
                    }
                }
            } while (!Valid);
        }

        return Obj;
    }


    friend ostream& operator<<(ostream& Obj, const User& U) {

        U.Display_Info();

        return Obj;
    }

    User& operator=(const User& U) {

        Name = U.Name;
        Gender = U.Gender;
        Age = U.Age;
        Email = U.Email;
        Password = U.Password;
        National_ID = U.National_ID;
        Date_of_Birth = U.Date_of_Birth;

        int* ID_Ptr = const_cast<int*>(&College_ID);
        *ID_Ptr = U.College_ID;

        return *this;
    }

    void Set_Name(string name) {

        Name = name;
    }

    void Get_Name() const {

        cout << " Student Name: " << Name << endl;
    }

    string Get_Name(int) const {

        return Name;
    }

    void Set_Gender(string gender) {

        Gender = gender;
    }

    void Get_Gender() const {

        cout << " Student Gender: " << Gender << endl;
    }

    void Set_Age(string age) {

        Age = age;
    }

    void Get_Age() const {

        cout << " Student Age: " << Age << endl;
    }

    void Set_Email(string email) {

        Email = email;
    }

    void Get_Email() const {

        cout << " Student Email: " << Email << endl;
    }

    void Set_Password(string password) {

        Password = password;
    }

    void Get_Password() const {

        cout << " Student Password: " << Password << endl;
    }

    void Set_National_ID(string national_ID) {

        National_ID = national_ID;
    }

    void Get_National_ID() const {

        cout << " Student National ID: " << National_ID << endl;
    }

    void Set_Date_of_Birth(string date_of_Birth) {
    
        Date_of_Birth = date_of_Birth;
    }

    void Get_Date_of_Birth() const {

        cout << " Student Date Of Birth: " << Date_of_Birth << endl;
    }

    void Get_College_ID() const {

        cout << " Student College ID: " << College_ID << endl;
    }

    void Display_Info() const {

        cout << "\n =========================Student Information=========================\n";
        Get_Name();
        Get_Gender();
        Get_Age();
        Get_Email();
        Get_Password();
        Get_College_ID();
        Get_National_ID();
        Get_Date_of_Birth();
        cout << " =====================================================================\n";
    }
};

class Author {

private:
    string Name, Date_of_Birth, Date_of_Death, Number_of_Works;

public:
    Author(string name = "Undefined", string date_of_Birth = "DD/MM/YYYY", string date_of_Death = "DD/MM/YYYY", string number_of_Works = "0")
    : Name(name), Date_of_Birth(date_of_Birth), Date_of_Death(date_of_Death), Number_of_Works(number_of_Works) {}

    Author(const Author& A) : Name(A.Name), Date_of_Birth(A.Date_of_Birth), Date_of_Death(A.Date_of_Death), Number_of_Works(A.Number_of_Works) {}

    ~Author() {}

    friend istream& operator>>(istream& Obj, Author& A) {

        cout << "\n New Author:-\n\n Enter Author's Name: ";

        string N;

        cin.ignore();
        getline(Obj, N);

        try {

            for (int i = 0; i < N.length(); i++) {

                if (N[i] < 65 && N[i] != 32 || N[i] > 122 || N[i] >= 91 && N[i] <= 96) {

                    throw "\n Invalid Author Name!\n Only Letters From \'a\' To \'z\' Or From \'A\' To \'Z\' Are Allowed\n";
                }

                if (i == 0 && N[i] == ' ') {

                    throw "\n Invalid Author Name!\n Name Must Not Start With A Space\n";
                }

                if (i) {

                    if (N[i] == ' ' && N[i - 1] == ' ') {

                        throw "\n Invalid Author Name!\n Too Many Spaces Between Author's Name\n";
                    }
                }

                if (i == (N.length() - 1) && N[i] == ' ') {

                    throw "\n Invalid Author Name!\n Name Must Not End With A Space\n";
                }
            }

            A.Set_Name(N);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Author's Name: ";

                getline(Obj, N);

                for (int i = 0; i < N.length(); i++) {

                    if (N[i] < 65 && N[i] != 32 || N[i] > 122 || N[i] >= 91 && N[i] <= 96) {

                        cout << "\n Invalid Author Name!\n Only Letters From \'a\' To \'z\' Or From \'A\' To \'Z\' Are Allowed\n";

                        Valid = false;

                        break;
                    }

                    if (i == 0 && N[i] == ' ') {

                        cout << "\n Invalid Author Name!\n Name Must Not Start With A Space\n";

                        Valid = false;

                        break;
                    }

                    if (i) {

                        if (N[i] == ' ' && N[i - 1] == ' ') {

                            cout << "\n Invalid Author Name!\n Too Many Spaces Between Author's Name\n";

                            Valid = false;

                            break;
                        }
                    }

                    if (i == (N.length() - 1) && N[i] == ' ') {

                        cout << "\n Invalid Author Name!\n Name Must Not End With A Space\n";

                        Valid = false;

                        break;
                    }
                }
            } while (!Valid);

            A.Set_Name(N);
        }

        cout << "\n Enter Author's Date Of Birth: ";

        string DOB;

        Obj >> DOB;

        try {

            if (DOB.length() != 10) {

                throw "\n Invalid Author Date Of Birth!\n Date Of Birth Must Be 10 Characters Long\n";
            }

            if (DOB[2] != '/' || DOB[5] != '/' || DOB[7] == '/' || DOB[8] == '/') {

                throw "\n Invalid Author Date Of Birth!\n Date Of Birth Must Be In \"DD/MM/YYYY\" Format\n";
            }

            if (DOB[0] > '3' || DOB[0] == '0' && DOB[1] == '0' || DOB[0] == '3' && DOB[1] > '1') {

                throw "\n Invalid Author Date Of Birth!\n Day Must Be From \'01\' To \'31\'\n";
            }

            if (DOB[3] > '1' || DOB[3] == '0' && DOB[4] == '0' || DOB[3] == '1' && DOB[4] > '2') {

                throw "\n Invalid Author Date Of Birth!\n Month Must Be From \'01\' To \'12\'\n";
            }

            if (DOB[6] > '2' || DOB[6] == '2' && DOB[7] != '0' || DOB[6] == '2' && DOB[8] == '2' && DOB[9] > '3' || DOB[6] == '2' && DOB[8] > '2') {

                throw "\n Invalid Author Date Of Birth!\n Year Exceeds Current Year \"2023\"\n";
            }

            for (int i = 0; i < DOB.length(); i++) {

                if (i) {

                    if (DOB[i] == '/' && DOB[i - 1] == '/') {

                        throw "\n Invalid Author Date Of Birth!\n Date Of Birth Must Be In \"DD/MM/YYYY\" Format\n";
                    }
                }

                if (DOB[0] == '/' || DOB[9] == '/') {

                    throw "\n Invalid Author Date Of Birth!\n Date Of Birth Must Be In \"DD/MM/YYYY\" Format\n";
                }

                if (DOB[i] < 47 || DOB[i] > 57) {

                    throw "\n Invalid Author Date Of Birth!\n Only Numbers From \'0\' To \'9\' And The Character \'/\' Are Allowed\n";
                }
            }

            A.Set_Date_of_Birth(DOB);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Author's Date Of Birth: ";

                Obj >> DOB;

                if (DOB.length() != 10) {

                    cout << "\n Invalid Author Date Of Birth!\n Date Of Birth Must Be 10 Characters Long\n";

                    Valid = false;
                }
                else if (DOB[2] != '/' || DOB[5] != '/' || DOB[7] == '/' || DOB[8] == '/') {

                    cout << "\n Invalid Author Date Of Birth!\n Date Of Birth Must Be In \"DD/MM/YYYY\" Format\n";

                    Valid = false;
                }
                else if (DOB[0] > '3' || DOB[0] == '0' && DOB[1] == '0' || DOB[0] == '3' && DOB[1] > '1') {

                    cout << "\n Invalid Author Date Of Birth!\n Day Must Be From \'01\' To \'31\'\n";

                    Valid = false;
                }
                else if (DOB[3] > '1' || DOB[3] == '0' && DOB[4] == '0' || DOB[3] == '1' && DOB[4] > '2') {

                    cout << "\n Invalid Author Date Of Birth!\n Month Must Be From \'01\' To \'12\'\n";

                    Valid = false;
                }
                else if (DOB[6] > '2' || DOB[6] == '2' && DOB[7] != '0' || DOB[6] == '2' && DOB[8] == '2' && DOB[9] > '3' || DOB[6] == '2' && DOB[8] > '2') {

                    cout << "\n Invalid Author Date Of Birth!\n Year Exceeds Current Year \"2023\"\n";

                    Valid = false;
                }
                else {

                    for (int i = 0; i < DOB.length(); i++) {

                        if (i) {

                            if (DOB[i] == '/' && DOB[i - 1] == '/') {

                                cout << "\n Invalid Author Date Of Birth!\n Date Of Birth Must Be In \"DD/MM/YYYY\" Format\n";

                                Valid = false;

                                break;
                            }
                        }

                        if (DOB[0] == '/' || DOB[9] == '/') {

                            cout << "\n Invalid Author Date Of Birth!\n Date Of Birth Must Be In \"DD/MM/YYYY\" Format\n";

                            Valid = false;

                            break;
                        }

                        if (DOB[i] < 47 || DOB[i] > 57) {

                            cout << "\n Invalid Author Date Of Birth!\n Only Numbers From \'0\' To \'9\' And The Character \'/\' Are Allowed\n";

                            Valid = false;

                            break;
                        }
                    }
                }

            } while (!Valid);

            A.Set_Date_of_Birth(DOB);
        }

        cout << "\n Enter Author's Date Of Death: ";

        string DOD;

        Obj >> DOD;

        try {

            if (DOD.length() != 10) {

                throw "\n Invalid Author Date Of Death!\n Date Of Death Must Be 10 Characters Long\n";
            }

            if (DOD[2] != '/' || DOD[5] != '/' || DOD[7] == '/' || DOD[8] == '/') {

                throw "\n Invalid Author Date Of Death!\n Date Of Death Must Be In \"DD/MM/YYYY\" Format\n";
            }

            if (DOD[0] > '3' || DOD[0] == '0' && DOD[1] == '0' || DOD[0] == '3' && DOD[1] > '1') {

                throw "\n Invalid Author Date Of Death!\n Day Must Be From \'01\' To \'31\'\n";
            }

            if (DOD[3] > '1' || DOD[3] == '0' && DOD[4] == '0' || DOD[3] == '1' && DOD[4] > '2') {

                throw "\n Invalid Author Date Of Death!\n Month Must Be From \'01\' To \'12\'\n";
            }

            if (DOD[6] > '2' || DOD[6] == '2' && DOD[7] != '0' || DOD[6] == '2' && DOD[8] == '2' && DOD[9] > '3' || DOD[6] == '2' && DOD[8] > '2') {

                throw "\n Invalid Author Date Of Death!\n Year Exceeds Current Year \"2023\"\n";
            }

            for (int i = 0; i < DOD.length(); i++) {

                if (i) {

                    if (DOD[i] == '/' && DOD[i - 1] == '/') {

                        throw "\n Invalid Author Date Of Death!\n Date Of Death Must Be In \"DD/MM/YYYY\" Format\n";
                    }
                }

                if (DOD[0] == '/' || DOD[9] == '/') {

                    throw "\n Invalid Author Date Of Death!\n Date Of Death Must Be In \"DD/MM/YYYY\" Format\n";
                }

                if (DOD[i] < 47 || DOD[i] > 57) {

                    throw "\n Invalid Author Date Of Death!\n Only Numbers From \'0\' To \'9\' And The Character \'/\' Are Allowed\n";
                }
            }

            if (DOD == DOB) {

                throw "\n Invalid Author Date Of Death!\n Date Of Death Must Not Equal Date Of Birth\n";
            }

            if (DOD[6] < DOB[6] || DOD[6] == DOB[6] && DOD[7] < DOB[7] || DOD[6] == DOB[6] && DOD[7] == DOB[7] && DOD[8] < DOB[8] || DOD[6] == DOB[6] && DOD[7] == DOB[7] && DOD[8] == DOB[8] && DOD[9] < DOB[9]) {

                throw "\n Invalid Author Date Of Death!\n Date Of Death Must Not Be Prior To Date Of Birth\n";
            }

            A.Set_Date_of_Death(DOD);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Author's Date Of Death: ";

                Obj >> DOD;

                if (DOD.length() != 10) {

                    cout << "\n Invalid Author Date Of Death!\n Date Of Death Must Be 10 Characters Long\n";

                    Valid = false;
                }
                else if (DOD[2] != '/' || DOD[5] != '/' || DOD[7] == '/' || DOD[8] == '/') {

                    cout << "\n Invalid Author Date Of Death!\n Date Of Death Must Be In \"DD/MM/YYYY\" Format\n";

                    Valid = false;
                }
                else if (DOD[0] > '3' || DOD[0] == '0' && DOD[1] == '0' || DOD[0] == '3' && DOD[1] > '1') {

                    cout << "\n Invalid Author Date Of Death!\n Day Must Be From \'01\' To \'31\'\n";

                    Valid = false;
                }
                else if (DOD[3] > '1' || DOD[3] == '0' && DOD[4] == '0' || DOD[3] == '1' && DOD[4] > '2') {

                    cout << "\n Invalid Author Date Of Death!\n Month Must Be From \'01\' To \'12\'\n";

                    Valid = false;
                }
                else if (DOD[6] > '2' || DOD[6] == '2' && DOD[7] != '0' || DOD[6] == '2' && DOD[8] == '2' && DOD[9] > '3' || DOD[6] == '2' && DOD[8] > '2') {

                    cout << "\n Invalid Author Date Of Death!\n Year Exceeds Current Year \"2023\"\n";

                    Valid = false;
                }
                else if (DOD == DOB) {

                    cout << "\n Invalid Author Date Of Death!\n Date Of Death Must Not Equal Date Of Birth\n";

                    Valid = false;
                }
                else {

                    for (int i = 0; i < DOD.length(); i++) {

                        if (i) {

                            if (DOD[i] == '/' && DOD[i - 1] == '/') {

                                cout << "\n Invalid Author Date Of Death!\n Date Of Death Must Be In \"DD/MM/YYYY\" Format\n";

                                Valid = false;

                                break;
                            }
                        }

                        if (DOD[0] == '/' || DOD[9] == '/') {

                            cout << "\n Invalid Author Date Of Death!\n Date Of Death Must Be In \"DD/MM/YYYY\" Format\n";

                            Valid = false;

                            break;
                        }

                        if (DOD[i] < 47 || DOD[i] > 57) {

                            cout << "\n Invalid Author Date Of Death!\n Only Numbers From \'0\' To \'9\' And The Character \'/\' Are Allowed\n";

                            Valid = false;

                            break;
                        }

                        if (DOD == DOB) {

                            cout << "\n Invalid Author Date Of Death!\n Date Of Death Must Not Equal Date Of Birth\n";

                            Valid = false;

                            break;
                        }

                        if (DOD[6] < DOB[6] || DOD[6] == DOB[6] && DOD[7] < DOB[7] || DOD[6] == DOB[6] && DOD[7] == DOB[7] && DOD[8] < DOB[8] || DOD[6] == DOB[6] && DOD[7] == DOB[7] && DOD[8] == DOB[8] && DOD[9] < DOB[9]) {

                            cout << "\n Invalid Author Date Of Death!\n Date Of Death Must Not Be Prior To Date Of Birth\n";

                            Valid = false;

                            break;
                        }
                    }
                }

            } while (!Valid);

            A.Set_Date_of_Death(DOD);
        }

        cout << "\n Enter Author's Number Of Works: ";

        string NOF;

        Obj >> NOF;

        try {

            if (NOF.length() > 1 && NOF[0] == '0') {

                throw "\n Invalid Author Number Of Works!\n Number Of Works Must Not Start With \'0\'\n";
            }

            for (int i = 0; i < NOF.length(); i++) {

                if (NOF[i] < 48 || NOF[i] > 57) {

                    throw "\n Invalid Author Number Of Works!\n Only Numbers From \'0\' To \'9\' Are Allowed\n";

                }
            }

            A.Set_Number_of_Works(NOF);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Author's Number Of Works ";

                Obj >> NOF;

                if (NOF.length() > 1 && NOF[0] == '0') {

                    cout << "\n Invalid Author Number Of Works!\n Number Of Works Must Not Start with \'0\'\n";

                    Valid = false;
                }
                else {

                    for (int i = 0; i < NOF.length(); i++) {

                        if (NOF[i] < 48 || NOF[i] > 57) {

                            cout << "\n Invalid Author Number Of Works!\n Only Numbers From \'0\' To \'9\' Are Allowed\n";

                            Valid = false;

                            break;
                        }
                    }
                }
            } while (!Valid);

            A.Set_Number_of_Works(NOF);
        }


        To_Find_Name = N;

        return Obj;
    }

    friend ostream& operator<<(ostream& Obj, const Author& A) {

        A.Display_Info();

        return Obj;
    }

    Author& operator=(const Author& A) {

        Name = A.Name;
        Date_of_Birth = A.Date_of_Birth;
        Date_of_Death = A.Date_of_Death;
        Number_of_Works = A.Number_of_Works;

        return *this;
    }

    void Set_Name(string name) {

        Name = name;
    }

    void Get_Name() const {

        cout << " Author Name: " << Name << endl;
    }

    string Get_Name(int) const {

        return Name;
    }

    void Set_Date_of_Birth(string date_of_Birth) {

        Date_of_Birth = date_of_Birth;
    }

    void Get_Date_of_Birth() const {

        cout << " Author Date Of Birth: " << Date_of_Birth << endl;
    }

    void Set_Date_of_Death(string date_of_Death) {

        Date_of_Death = date_of_Death;
    }

    void Get_Date_of_Death() const {

        cout << " Author Date Of Death: " << Date_of_Death << endl;
    }

    void Set_Number_of_Works(string number_of_Works) {

        Number_of_Works = number_of_Works;
    }

    void Get_Number_of_Works() const {

        cout << " Author Number Of Works: " << Number_of_Works << endl;
    }

    void Display_Info() const {

        cout << "\n =========================Author Information==========================\n";
        Get_Name();
        Get_Date_of_Birth();
        Get_Date_of_Death();
        Get_Number_of_Works();
        cout << " =====================================================================\n";
    }
};

class Book {

private:
    string Title, Category, ISBN, Average_Rating;
    User Borrower;

public:

    Author Book_Author;

    Book(string title = "Undefined", string category = "General", string iSBN = "###-#-##-######-#", string average_Rating = "0.0", Author book_Author = {"Undefined", "DD/MM/YYYY", "DD/MM/YYYY", "0"}, User borrower = {"New User", "N/A", "00000000000000"})
    : Title(title), Category(category), ISBN(iSBN), Average_Rating(average_Rating), Book_Author(book_Author), Borrower(borrower) {}

    Book(const Book& B) : Title(B.Title), Category(B.Category), ISBN(B.ISBN), Average_Rating(B.Average_Rating), Book_Author(B.Book_Author), Borrower(B.Borrower) {}

    ~Book() {}

    friend istream& operator>>(istream& Obj, Book& B) {

        cout << "\n New Book:-\n\n Enter Book's Title: ";

        string N;

        cin.ignore();
        getline(Obj, N);

        try {

            for (int i = 0; i < N.length(); i++) {

                if (i == 0 && N[i] == ' ') {

                    throw "\n Invalid Book Title!\n Title Must Not Start With A Space\n";
                }

                if (i) {

                    if (N[i] == ' ' && N[i - 1] == ' ') {

                        throw "\n Invalid Book Title!\n Too Many Spaces Between Book's Title\n";
                    }
                }

                if (i == (N.length() - 1) && N[i] == ' ') {

                    throw "\n Invalid Book Title!\n Title Must Not End With A Space\n";
                }
            }

            B.Set_Title(N);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Book's Title: ";

                getline(Obj, N);

                for (int i = 0; i < N.length(); i++) {

                    if (i == 0 && N[i] == ' ') {

                        cout << "\n Invalid Book Title!\n Title Must Not Start With A Space\n";

                        Valid = false;

                        break;
                    }

                    if (i) {

                        if (N[i] == ' ' && N[i - 1] == ' ') {

                            cout << "\n Invalid Book Title!\n Too Many Spaces Between Book's Title\n";

                            Valid = false;

                            break;
                        }
                    }

                    if (i == (N.length() - 1) && N[i] == ' ') {

                        cout << "\n Invalid Book Title!\n Title Must Not End With A Space\n";

                        Valid = false;

                        break;
                    }
                }
            } 
            while (!Valid);

            B.Set_Title(N);
        }

        cout << "\n Enter Book's Category: ";
        
        string C;

        getline(Obj, C);

        try {

            for (int i = 0; i < C.length(); i++) {

                if (i == 0 && C[i] == 32) {

                    throw "\n Invalid Book Category!\n Category Must Not Start With A Space\n";
                }

                if (i) {

                    if (C[i] == 32 && C[i - 1] == 32) {

                        throw "\n Invalid Book Category!\n Too Many Spaces Between Book's Category\n";
                    }
                }

                if (i == (C.length() - 1) && C[i] == ' ') {

                    throw "\n Invalid Book Category!\n Category Must Not End With A Space\n";
                }

                if (C[i] < 65 && C[i] != 45 && C[i] != 32 && C[i] != 39 || C[i] > 122 || C[i] >= 91 && C[i] <= 96) {

                    throw "\n Invalid Book Category!\n Only Letters From \'a\' To \'z\' Or From \'A\' To \'Z\' And The Characters \'-\' And \''\' Are Allowed\n";
                }
            }

            B.Set_Category(C);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Book's Category: ";

                getline(Obj, C);

                for (int i = 0; i < C.length(); i++) {

                    if (i == 0 && C[i] == ' ') {

                        cout << "\n Invalid Book Category!\n Category Must Not Start With A Space\n";

                        Valid = false;

                        break;
                    }

                    if (i) {

                        if (C[i] == 32 && C[i - 1] == 32) {

                            cout << "\n Invalid Book Category!\n Too Many Spaces Between Book's Category\n";

                            Valid = false;

                            break;
                        }
                    }

                    if (i == (C.length() - 1) && C[i] == ' ') {

                        cout << "\n Invalid Book Category!\n Category Must Not End With A Space\n";

                        Valid = false;

                        break;
                    }

                    if (C[i] < 65 && C[i] != 45 && C[i] != 32 && C[i] != 39 || C[i] > 122 || C[i] >= 91 && C[i] <= 96) {

                        cout << "\n Invalid Book Category!\n Only Letters From \'a\' To \'z\' Or From \'A\' To \'Z\' And The Characters \'-\' And \''\' Are Allowed\n";

                        Valid = false;

                        break;
                    }
                }
            } 
            while (!Valid);

            B.Set_Category(C);
        }

        cout << "\n Enter Book's ISBN: ";

        string I;

        Obj >> I;

        try {

            if (I.length() != 17) {

                throw "\n Invalid Book ISBN!\n ISBN Must Be 17 Characters Long\n";
            }

            if (I[0] == '#' || I[1] == '#' || I[2] == '#' || I[3] != '-' || I[4] == '#' || I[5] != '-' || I[6] == '#' || I[7] == '#' || I[8] != '-' 
            || I[9] == '#' || I[10] == '#' || I[11] == '#' || I[12] == '#' || I[13] == '#' || I[14] == '#' || I[15] != '-' || I[16] == '#') {

                throw "\n Invalid Book ISBN!\n ISBN Must Be In \"###-#-##-######-#\" Format\n";
            }

            for (int i = 0; i < I.length(); i++) {

                if (I[i] < 48 && I[i] != 45 || I[i] > 57) {

                    throw "\n Invalid Book ISBN!\n Only Numbers From \'0\' To \'9\' And The Character \'-\' Are Allowed\n";
                }
            }

            B.Set_ISBN(I);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Book's ISBN: ";

                Obj >> I;

                if (I.length() != 17) {

                    cout << "\n Invalid Book ISBN!\n ISBN Must Be 17 Characters Long\n";

                    Valid = false;
                }
                else if (I[0] == '-' || I[1] == '-' || I[2] == '-' || I[3] != '-' || I[4] == '-' || I[5] != '-' || I[6] == '-' || I[7] == '-' || I[8] != '-'
                || I[9] == '-' || I[10] == '-' || I[11] == '-' || I[12] == '-' || I[13] == '-' || I[14] == '-' || I[15] != '-' || I[16] == '-') {
                
                    cout << "\n Invalid Book ISBN!\n ISBN Must Be In \"###-#-##-######-#\" Format\n";

                    Valid = false;
                }
                else {

                    for (int i = 0; i < I.length(); i++) {

                        if (I[i] < 48 && I[i] != 45 || I[i] > 57) {

                            cout << "\n Invalid Book ISBN!\n Only Numbers From \'0\' To \'9\' And The Character \'-\' Are Allowed\n";

                            Valid = false;

                            break;
                        }
                    }
                }

            } 
            while (!Valid);

            B.Set_ISBN(I);
        }

        cout << "\n Enter Book's Average Rating: ";
        
        string A;

        Obj >> A;

        try {

            if (A.length() != 3) {

                throw "\n Invalid Book Average Rating!\n Average Rating Must Be 3 Characters Long And In \"0.0\" Format\n";
            }

            if (A[0] == '.' || A[1] != '.' || A[2] == '.') {

                throw "\n Invalid Book Average Rating!\n Average Rating Must Be In \"0.0\" Format\n";
            }

            for (int i = 0; i < A.length(); i++) {

                if (A[i] < 48 && A[i] != 46 || A[i] > 57) {

                    throw "\n Invalid Book Average Rating!\n Only Numbers From \'0\' To \'9\' And The Character \'.\' Are Allowed\n";
                }
            }

            if (A[0] > '5' && A[0] <= '9' || A[0] == '5' && A[2] > '0' && A[2] <= '9') {

                throw "\n Invalid Book Average Rating!\n Max Average Rating Is \"5.0\"\n";
            }

            B.Set_Average_Rating(A);
        }
        catch (const char* Msg) {

            bool Valid;

            cout << Msg;

            do {

                Valid = true;

                cout << "\n Enter Book's Average Rating: ";

                Obj >> A;

                if (A.length() != 3) {

                    cout << "\n Invalid Book Average Rating!\n Average Rating Must Be 3 Characters Long And In \"0.0\" Format\n";

                    Valid = false;
                }
                else if (A[0] == '.' || A[1] != '.' || A[2] == '.') {

                    cout << "\n Invalid Book Average Rating!\n Average Rating Must Be In \"0.0\" Format\n";

                    Valid = false;
                }
                else if (A[0] > '5' && A[0] <= '9' || A[0] == '5' && A[2] > '0' && A[2] <= '9') {

                    cout << "\n Invalid Book Average Rating!\n Max Average Rating Is \"5.0\"\n";

                    Valid = false;
                }
                else {

                    for (int i = 0; i < A.length(); i++) {

                        if (A[i] < 48 && A[i] != 46 || A[i] > 57) {

                            cout << "\n Invalid Book Average Rating!\n Only Numbers From \'0\' To \'9\' And The Character \'.\' Are Allowed\n";

                            Valid = false;

                            break;
                        }
                    }
                }

            } 
            while (!Valid);

            B.Set_Average_Rating(A);
        }

        Obj >> B.Book_Author;

        return Obj;
    }

    friend ostream& operator<<(ostream& Obj, const Book& B) {

        B.Display_Info();

        return Obj;
    }

    Book& operator=(const Book& B) {

        Title = B.Title;
        Category = B.Category;
        ISBN = B.ISBN;
        Average_Rating = B.Average_Rating;
        Book_Author = B.Book_Author;
        Borrower = B.Borrower;

        return *this;
    }

    friend void Equal_User(Book& B, const User& A);

    void Set_Title(string title) {

        Title = title;
    }

    void Get_Title() const {

        cout << " Book Title: " << Title << endl;
    }

    string Get_Title(int) const {

        return Title;
    }

    void Set_Category(string category) {

        Category = category;
    }

    void Get_Category() const {

        cout << " Book Category: " << Category << endl;
    }

    void Set_ISBN(string iSBN) {

        ISBN = iSBN;
    }

    void Get_ISBN() const {

        cout << " Book ISBN: " << ISBN << endl;
    }

    void Set_Average_Rating(string average_Rating) {

        Average_Rating = average_Rating;
    }

    void Get_Average_Rating() const {

        cout << " Book Average Rating: " << Average_Rating << endl;
    }

    void Set_Book_Author() {

        cin >> Book_Author;
    }

    void Get_Book_Author() const {

        cout << Book_Author;
    }

    void Set_Borrower() {

        cin >> Borrower;
    }

    friend void Set_Borrower(Book& B);

    void Get_Borrower() const {

        cout << Borrower;
    }
    
    void Display_Info() const {

        cout << "\n =========================Book Information============================\n";
        Get_Title();
        Get_Category();
        Get_ISBN();
        Get_Average_Rating();
        cout << " =====================================================================\n";
        Get_Book_Author();
        Get_Borrower();
    }

    bool Is_Available() const {

        return Borrower.Get_Name(1) == "New User";
    }
};

int User::Incremental_ID = 1319001;

const string User::Letters = ".abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const string User::Numbers = "0123456789";

vector <User> Users_Data;
vector <Book> Books_Data;

bool Found_User(User& U) {

    return U.Get_Name(1) == To_Find_Name;
}

bool Found_Book(Book& B) {

    return B.Get_Title(1) == To_Find_Title;
}

void Equal_User(Book& B, const User& A) {

    B.Borrower = A;

    return;
}

void Set_Borrower(Book& B) {

    cin + B.Borrower;

    auto it = find_if(Users_Data.begin(), Users_Data.end(), Found_User);

    if (it != Users_Data.end()) {

        for (auto& it : Users_Data) {

            if (it.Get_Name(1) == To_Find_Name) {

                Equal_User(B, it);
            }
        }
    }
    else {

        cout << "\n Student Is Not Subscribing\n Do You Want To Add Him To The System?\n";
    }

    return;
}

void P1() {

    cout << "\n How Many Users Would You Like To Add?\n Number Of Users: ";

    int N;

    cin >> N;

    if (!N) {

        cout << "\n No Users Were Added To The System\n ";

        return;
    }
    
    while (N--) {

        User U;

        cin >> U;

        To_Find_Name = U.Get_Name(1);

        auto it = find_if(Users_Data.begin(), Users_Data.end(), Found_User);

        if (it != Users_Data.end()) {

            cout << "\n User Is Already Assigned!\n Returning To Main Menu\n";

            return;
        }
        else {
        
            Users_Data.push_back(U);

            cout << "\n User Was Successfully Added To The System\n ";
        }
    }

    cout << "\n All Users Were Successfully Added To The System\n ";

    return;
}

void P2() {

    cout << "\n How Many Books Would You Like To Add?\n Number Of Books: ";

    int N;

    cin >> N;

    if (!N) {

        cout << "\n No Books Were Added To The System\n ";

        return;
    }

    while (N--) {

        Book B;

        cin >> B;

        To_Find_Title = B.Get_Title(1);

        auto it = find_if(Books_Data.begin(), Books_Data.end(), Found_Book);

        if (it != Books_Data.end()) {

            cout << "\n Book Is Already Assigned!\n Returning To Main Menu\n";

            return;
        }
        else {

            Books_Data.push_back(B);

            cout << "\n Book Was Successfully Added To The System\n ";
        }
    }

    cout << "\n All Books Were Successfully Added To The System\n ";

    return;
}

void P3() {

    cout << "\n Please Enter The Student's Name: ";

    cin.ignore();
    getline(cin, To_Find_Name);

    auto it = find_if(Users_Data.begin(), Users_Data.end(), Found_User);

    if (it != Users_Data.end()) {

        cout << "\n Student Is Subscribing\n";
    }
    else {

        cout << "\n Student Is Not Subscribing\n Do You Want To Add The Student To The System?\n";
    }

    return;
}

void P4() {

    cout << "\n Please Enter The Books's Title: ";

    cin.ignore();
    getline(cin, To_Find_Title);

    auto it = find_if(Books_Data.begin(), Books_Data.end(), Found_Book);

    if (it != Books_Data.end()) {

        for (auto& it : Books_Data) {

            if (it.Get_Title(1) == To_Find_Title) {

                if (it.Is_Available()) {

                    Set_Borrower(it);

                    cout << "\n Book Is Now Assigned To User\n";

                    break;
                }
                else {

                    cout << "\n Book Is Already Borrowed\n";

                    break;
                }
            }
        }
    }
    else {

        cout << "\n Book Is Not Found\n Do You Want To Add It To The System?\n";
    }

    return;
}

void P5() {

    if (Users_Data.size() == 0) {

        cout << "\n No Data To Show!\n";
    }
    else {

        for (auto it : Users_Data) {

            cout << it;
        }
    }
}

void P6() {

    if (Books_Data.size() == 0) {

        cout << "\n No Data To Show!\n";
    }
    else {

        for (auto it : Books_Data) {

            cout << it;
        }
    }
}

int main()
{

    while (1) {

        char Process = '6';

        cout << "\n 1. Add Users\n 2. Add Books\n 3. Query On A Subscription\n 4. Borrow A Book\n 5. View Users\n 6. View Books\n 7. Close\n\n Please Enter Your Choice: ";

        cin >> Process;

        if (Process == '1') {

            P1();
        }
        else if (Process == '2') {

            P2();
        }
        else if (Process == '3') {

            P3();
        }
        else if (Process == '4') {

            P4();
        }
        else if (Process == '5') {

            P5();
        }
        else if (Process == '6') {

            P6();
        }
        else if (Process == '7') {

            cout << "\n Thank You For Using OLS (Online Library System)!\n ";

            return 0;
        }
        else {

            cout << "\n Invalid Input!\n Please Choose A Number From \'1\' To \'6\'\n";
        }

        Users_Data.shrink_to_fit();
        Books_Data.shrink_to_fit();
    }
}