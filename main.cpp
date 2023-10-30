#include <iostream>
#include <string>
using namespace std;

// Struktura przechowująca pytanie, odpowiedzi i poprawną odpowiedź
struct Question {
    string text;
    string options[3];
    char correctAnswer;
};

// Funkcja do zadawania i oceniania pytań
int askQuestion(const Question& question) {
    cout << question.text << endl;
    for (int i = 0; i < 3; i++) {
        cout << char('a' + i) << ") " << question.options[i] << endl;
    }

    char userAnswer;
    cout << "Twoja odpowiedz (a, b, c): ";
    cin >> userAnswer;

    if (userAnswer == question.correctAnswer) {
        cout << "Poprawna odpowiedz!\n";
        return 1;
    } else {
        cout << "Zla odpowiedz. Poprawna odpowiedz to: " << question.correctAnswer << "\n";
        return 0;
    }
}

int main() {
    int score = 0;

    cout << "Witaj w quizie! Odpowiedz na 5 pytan (a, b, c)." << endl;

    Question questions[] = {
        {"Kiedy byl chrzest Polski", {"1453", "966", "1876"}, 'b'},
        {"Uniwersytet Im.Adama Mickiewicza miesci sie w:", {"Poznaniu", "Gliwicach", "Wroclawiu"}, 'a'},
        {"Ktora planeta jest najblizej Slonca?", {"Ziemia", "Wenus", "Merkury"}, 'c'},
        {"Jak w mitologi greckiej nazywal sie bog kowalstwa?", {"Zeus", "Kronos", "Hefajstos"}, 'c'},
        {"Anemie powoduje niedobor:", {"Witaminy D", "Zelaza", "Magnezu"}, 'b'}
    };

    for (int i = 0; i < 5; i++) {
        score += askQuestion(questions[i]);
    }

    cout << "Twoj wynik to: " << score << " na 5 punktow." << endl;

    return 0;
}
