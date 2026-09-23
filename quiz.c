#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_NO_OF_QUESTIONS 10

struct Question
{
    char question[300];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int answer;
};

int loadQuestions(char filename[], struct Question questions[])
{

    FILE *file;
    int i;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf(" %s is empty\n", filename);
        return 0;
    }

    for (i = 0; i < TOTAL_NO_OF_QUESTIONS; i++)
    {

        if (fgets(questions[i].question, sizeof(questions[i].question), file) == NULL)
            break;

        if (fgets(questions[i].option1, sizeof(questions[i].option1), file) == NULL)
            // sizeof(questions[i].option1), file) == NULL)
            break;

        if (fgets(questions[i].option2, sizeof(questions[i].option2), file) == NULL)
            // sizeof(questions[i].option2), file) == NULL)
            break;

        if (fgets(questions[i].option3, sizeof(questions[i].option3), file) == NULL)
            // sizeof(questions[i].option3), file) == NULL)
            break;

        if (fgets(questions[i].option4, sizeof(questions[i].option4), file) == NULL)
            // sizeof(questions[i].option4), file) == NULL)
            break;

        if (fscanf(file, "%d\n", &questions[i].answer) != 1)
            break;
    }

    fclose(file);

    return i;
}

void startQuiz(char filename[], char subject[])
{

    struct Question questions[TOTAL_NO_OF_QUESTIONS];

    int total;
    int choice;
    int score = 0;
    int i;

    total = loadQuestions(filename, questions);

    if (total == 0)
    {
        printf("No questions found!\n");
        return;
    }

    printf("\n====================================\n");
    printf("          %s QUIZ\n", subject);
    printf("====================================\n");

    for (i = 0; i < total; i++)
    {

        printf("\nQuestion %d:\n", i + 1);
        printf("%s\n\n", questions[i].question);

        printf("1. %s\n", questions[i].option1);
        printf("2. %s\n", questions[i].option2);
        printf("3. %s\n", questions[i].option3);
        printf("4. %s\n", questions[i].option4);

        printf("\nEnter your answer (1-4): ");
        scanf("%d", &choice);

        if (choice == questions[i].answer)
        {

            printf("\nCongratulations! You are right.\n");
            score++;
        }
        else
        {

            printf("\nYour selected option is incorrect.\n");

            printf("The right answer is: ");

            switch (questions[i].answer)
            {

            case 1:
                printf("%s\n", questions[i].option1);
                break;

            case 2:
                printf("%s\n", questions[i].option2);
                break;

            case 3:
                printf("%s\n", questions[i].option3);
                break;

            case 4:
                printf("%s\n", questions[i].option4);
                break;
            }
        }
    }

    printf("\n                                  \n");
    printf("             QUIZ RESULT\n");
    printf("                                    \n");

    printf("Subject : %s\n", subject);
    printf("Score   : %d/%d\n", score, total);

    if (score == total)
        printf("Excellent! \n");
    else if (score >= 7)
        printf("Amazing! \n");
    else if (score >= 5)
        printf("Good,, But you can do better\n");
    else
        printf("you Failed\n");
}

int main()
{

    int choice;

    while (1)
    {

        printf("\n\n                                    \n");
        printf("       YOUR EXAM YOUR QUIZ SYSTEM\n");
        printf("                                         \n");

        printf("1. Math\n");
        printf("2. Science\n");
        printf("3. History\n");
        printf("4. Coding\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            startQuiz("math.txt", "MATH");
            break;

        case 2:
            startQuiz("science.txt", "SCIENCE");
            break;

        case 3:
            startQuiz("history.txt", "HISTORY");
            break;

        case 4:
            startQuiz("coding.txt", "CODING");
            break;

        case 5:
            printf("\n(: Koi Baat Nhi Baad Me De Lena :)\n");
            exit(0);

        default:
            printf("\n choose from given options :) \n");
        }
    }

    return 0;
}