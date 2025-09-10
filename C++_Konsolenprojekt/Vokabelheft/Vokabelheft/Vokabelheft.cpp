#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

int main()
{
    vector<string> vocabulary_german;
    vector<string> vocabulary_english;

    fstream in{};
    fstream in2{};

    in.open("../vocabulary_german.txt");

    string str;

    while (in.is_open() && getline(in, str))
    {
        if (str.size() > 0)
        {
            vocabulary_german.push_back(str);
        }
    }

    in2.open("../vocabulary_english.txt");

    while (in2.is_open() && getline(in2, str))
    {
        if (str.size() > 0)
        {
            vocabulary_english.push_back(str);
        }
    }

    cout << "Vokabelheft\n";
    cout << "\n";
    cout << "Bitte treffe eine Auswahl: \n";
    cout << "(1) Neue Vokabel Hinzufuegen\n";
    cout << "(2) Vokabeln Ueben\n";
    cout << "\n";
    cout << "Eingabe: ";
    string choice;
    cin >> choice;
    cout << "\n";

    if (choice == "1")
    {
        cout << "Wie lautet die Deutsche Vokabel?";
        cout << "\n";
        cout << "Eingabe: ";
        string german;
        string english;
        cin >> german;
        cout << "\n";

        cout << "Wie lautet die Englische Vokabel?";
        cout << "\n";
        cout << "Eingabe: ";
        cin >> english;
        cout << "\n";

        vocabulary_german.push_back(german);
        vocabulary_english.push_back(english);

        cout << german + " bedeutet " + english + ".\n";
        cout << "\n";

        cout << "Vokabel wurde angelegt.\n";
        cout << "Aktuell sind: " + to_string(vocabulary_german.size()) + " Vokabeln im Heft.\n";
        cout << "\n";

        ofstream output_file("C:/Users/kevin/Desktop/SAE/5FSC0XD101_P_0925/Portfolio_5FSC0XD101_P_0925/C++_Konsolenprojekt/Vokabelheft/vocabulary_german.txt");
        ostream_iterator<string> output_iterator(output_file, "\n");
        copy(vocabulary_german.begin(), vocabulary_german.end(), output_iterator);

        ofstream output_file2("C:/Users/kevin/Desktop/SAE/5FSC0XD101_P_0925/Portfolio_5FSC0XD101_P_0925/C++_Konsolenprojekt/Vokabelheft/vocabulary_english.txt");
        ostream_iterator<string> output_iterator2(output_file2, "\n");
        copy(vocabulary_english.begin(), vocabulary_english.end(), output_iterator2);
    }
    else
    {
        cout << "Vokabeln Ueben";
    }

    return 0;
}