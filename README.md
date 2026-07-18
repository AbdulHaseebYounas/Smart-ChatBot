# 🤖 Smart ChatBot

A console-based Smart ChatBot developed in **C++** that interacts with users by answering predefined questions and continuously improves by learning new questions and answers from user input.

The chatbot stores learned knowledge in a file, allowing it to remember information even after the program is closed and restarted.

---

# Features

- 💬 Interactive question-and-answer system
- 🧠 Learns new questions and answers from users
- 💾 Persistent data storage using file handling
- 🔍 Case-insensitive question matching
- ✅ Input validation and error handling
- 📂 Automatically loads previously learned knowledge at startup
- 🛠️ Modular code using functions

# Technologies Used

- **Language:** C++
- Arrays
- Strings
- Functions
- Loops
- Conditional Statements
- File Handling (`ifstream` & `ofstream`)
- Console-based User Interface

---

# How It Works

1. The chatbot loads previously learned questions and answers.
2. The user enters a question.
3. If the chatbot knows the answer, it displays it.
4. If it doesn't know the answer, it asks the user to teach it.
5. The new question and answer are saved to a file.
6. The next time the program runs, the chatbot remembers the newly learned information.

# Learning Outcomes

This project helped me strengthen my understanding of:

- C++ programming fundamentals
- File handling and persistent data storage
- Modular programming using functions
- User input validation
- String manipulation
- Building interactive console applications
- Problem-solving and logical thinking


## Sample Output

```
Welcome to Smart ChatBot!

You: What is C++?

Bot: C++ is a general-purpose programming language.

You: Who created ChatGPT?

Bot: I don't know the answer.
Would you like to teach me? (Y/N): Y

Enter the answer:
ChatGPT was developed by OpenAI.

Thank you! I will remember that.
```
Author

**Abdul Haseeb Younas**

- LinkedIn: linkedin.com/in/abdul-haseeb-b188043b6

