#include <stdio.h>

struct QuizQuestion {
    int id;
    char question[100];
    char options[4][100];
    int correctOption;
};

void displayQuestion(struct QuizQuestion question) {
    printf("Question %d: %s\n", question.id, question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
    printf("Enter your answer (1-4): ");
    int userAnswer;
    scanf("%d", &userAnswer);
    if (userAnswer == question.correctOption) {
        printf("Correct!\n");
    } else {
        printf("Wrong. The correct answer is %d.\n", question.correctOption);
    }
    printf("\n");
}

int main() {
    struct QuizQuestion questions[] = {
        {1, "What is the capital of France?", {"Paris", "London", "Berlin", "Madrid"}, 1},
        {2, "Who was the first person to climb Mount Everest?", {"Kenya", "Rafael Nilo", "Rick Stephenson", "Everest"}, 4},
        {3, "What is the largest island in the world?", 
            {"Greenland",
            "Iceland",
            "Antarctica",
            "Madagascar"}, 1},
        {4, "What is the name of the famous American author who wrote the classic novel 'To Kill a Mockingbird'?", {"Harper Lee", "J.D. Salinger", "Mark Twain", "Harriet Tubman"}, 1}
    };
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questions[i]);
    }
    return 0;}
