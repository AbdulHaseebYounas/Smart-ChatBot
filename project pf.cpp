#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


void storeNewQuestion(char questions[][256], char answers[][256], int& count, const char* newQuestion, const char* newAnswer);

int main() {
    char questions[50][256] = { "how are you", "ranking of air university", "location of aumc", "who developed this project" };
    char answers[50][256] = { "I'm ChatBot, I don't have feelings!", "overall 2 in pakistan.", "Chak 5-Faiz, Bahawalpur Road, Multan.", "The developer of this program are these following\n1.Abdul Haseeb\n2.Haseeb M\n3.Qamar S" };
    int count = 4;

    
    ifstream fin("new_questions.txt");
    if (fin.is_open()) {
        while (fin.getline(questions[count], 256)) {
            fin.getline(answers[count], 256);
            count++;
            if (count >= 50) break; 
        }
        fin.close();
    }

    char input[256];
    bool keepRunning = true;

    cout << "============================================================\n";
    cout << "                 WELCOME TO SMART CHATBOT\n";
    cout << "============================================================\n";
    cout << "           Type 'exit' to quit the chatbot.\n\n";

    while (keepRunning) {
        cout << "Ask a question: ";
        cin.getline(input, 256);

        
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                input[i] = input[i] + 32;
            }
        }

    
        if (strcmp(input, "exit") == 0) {
            keepRunning = false;
            cout << "Goodbye!" << endl;
            break;
        }

        
        if (strlen(input) == 0) {
            cout << "Question cannot be empty!" << endl;
            continue;
        }

        // Search for existing question
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (strcmp(input, questions[i]) == 0) {
                cout << answers[i] << endl;
                found = true;
                break;
            }
        }

        // Learn new question
        if (!found) {
            char newAnswer[256];
            cout << "I don't know the answer to that. Can you teach me? " << endl;
            cout << "Your answer: ";
            cin.getline(newAnswer, 256);

            if (strlen(newAnswer) == 0) {
                cout << "Answer cannot be empty. Try again." << endl;
                continue;
            }

            storeNewQuestion(questions, answers, count, input, newAnswer);
            cout << "Thanks! I've learned something new!" << endl;
        }
    }

    return 0;
}


void storeNewQuestion(char questions[][256], char answers[][256], int& count, const char* newQuestion, const char* newAnswer) {
    if (count < 50) { // must match array size
        strcpy(questions[count], newQuestion);
        strcpy(answers[count], newAnswer);

        // Save  new question and answer to file
        ofstream fout("new_questions.txt", ios::app); // append mode
        if (fout.is_open()) {
            fout << newQuestion << endl;
            fout << newAnswer << endl;
            fout.close();
        }

        count++;
    } else {
        cout << "Sorry, I can't store more questions right now!" << endl;
    }
}


