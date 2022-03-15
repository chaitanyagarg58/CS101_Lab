#include <simplecpp>

bool lab_marks(int &total_marks)
{
    // We will add all input marks, the subtract 2 minimum marks
    int marks;           // marks = marks in a particular lab
    int minimum1 = 1000; // minimum initialised to be a large no. for fist iteration,
    int minimum2 = 1000; // We need to eliminate 2 minimum values
    repeat(7)
    {
        cin >> marks;
        total_marks += marks;
        int temp = minimum1; // temporary variable to see if min1 changes
        minimum1 = min(minimum1, marks);
        if (minimum1 == temp) // If first minimum did not change, lets see if second minimum should change
        {
            minimum2 = min(minimum2, marks);
        }
    }
    total_marks -= (minimum1 + minimum2);
    int cheated;
    cin >> cheated;
    return cheated;
}

bool quiz_marks(int &total_marks)
{
    // We will add all input marks, the subtract minimum one
    int minimum = 1000, marks; // minimum initialised to be a large no. for fist iteration, marks = marks in a particular lab
    repeat(6)                  // It is simpler because only one minimum should be eliminated
    {
        cin >> marks;
        total_marks += marks;
        minimum = min(minimum, marks);
    }
    total_marks -= minimum;
    int cheated;
    cin >> cheated;
    return cheated;
}

int midsem_marks()
{
    int midsem;
    cin >> midsem;
    return midsem;
}

int endsem_marks()
{
    int endsem;
    cin >> endsem;
    return endsem;
}

bool project_marks(int &total_marks)
{
    int project;
    cin >> project;
    if (total_marks > 80)
        total_marks += project;
    int cheated;
    cin >> cheated;
    return cheated;
}

int calculate_grade(int total_marks, bool plag_in_quiz, bool plag_in_lab, bool plag_in_project)
{
    total_marks -= 10 * (plag_in_lab + plag_in_project + plag_in_quiz);
    if (total_marks <= 100 && total_marks > 90)
        return 10;
    else if (total_marks <= 90 && total_marks > 80)
        return 9;
    else if (total_marks <= 80 && total_marks > 70)
        return 8;
    else if (total_marks <= 70 && total_marks > 60)
        return 7;
    else if (total_marks <= 60 && total_marks > 50)
        return 6;
    else if (total_marks <= 50 && total_marks > 40)
        return 5;
    else if (total_marks <= 40 && total_marks > 30)
        return 4;
    else if (total_marks <= 30 && total_marks >= 0)
        return 0;

    // control should never reach this line according to code.
    // this would check if it is otherwise
    // also gives grade = 0 in case total marks come out negative
    return 0;
}