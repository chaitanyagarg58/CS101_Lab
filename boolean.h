#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SYMBOLS = 5;
const int MAX_EXPR_SIZE = 20;

class Symbol
{
public:
    char name;
    bool value;

    bool operator+(Symbol b)
    {
        return value && b.value;
    }

    bool operator*(Symbol b)
    {
        return value || b.value;
    }
};

int n = 0; // to keep track if boolean is called first time or other time
// in first time, we get rid of all !

bool boolean(Symbol *symbols, int symbol_len, char *expr, int expr_len)
{
    if (expr_len == 1)
        return symbols[0].value;
    else if (n == 0)
    {
        char exp[expr_len];
        int k = 0, exp_len = expr_len;
        for (int i = 0; i < expr_len; i++)
        {
            if (expr[i] == '!')
            {
                for (int j = 0; j < symbol_len; j++)
                {
                    if (symbols[j].name == expr[i + 1])
                        symbols[j].value = !symbols[j].value;
                }
                exp_len--;
            }
        }
        for (int i = 0; i < expr_len; i++)
        {
            if (expr[i] != '!')
            {
                exp[k] = expr[i];
                k++;
            }
        }
        n++;
        return boolean(symbols, symbol_len, exp, exp_len);
    }
    else if (expr[1] == '+')
    {
        symbols[1].value = symbols[0] + symbols[1];
        return boolean(&symbols[1], symbol_len - 1, &expr[2], expr_len - 2);
    }
    else if (expr[1] == '*')
    {
        symbols[1].value = symbols[0] * symbols[1];
        return boolean(&symbols[1], symbol_len - 1, &expr[2], expr_len - 2);
    }
    return 0;
}

class BooleanExpr
{
private:
    int symbol_cnt;
    int expr_len;
    Symbol symbols[MAX_SYMBOLS];
    char expr[MAX_EXPR_SIZE];

public:
    void read_expr(char *expr, int expr_size, char *symbols, int symbols_size)
    {
        this->symbol_cnt = symbols_size;
        for (int i = 0; i < symbols_size; i++)
            this->symbols[i].name = symbols[i];
        this->expr_len = expr_size;
        for (int i = 0; i < expr_size; i++)
            this->expr[i] = expr[i];
    }

    void print_truth_table()
    {
        for (int i = 0; i < symbol_cnt; i++)
            cout << symbols[i].name << " ";
        cout << "-> (";
        for (int i = 0; i < expr_len; i++)
            cout << expr[i];
        cout << ")" << endl;
        for (int i = 0; i < round(pow(2, symbol_cnt)); i++)
        {
            int k = i;
            for (int j = symbol_cnt - 1; j >= 0; j--)
            {
                symbols[j].value = k % 2;
                k = k / 2;
            }
            for (int j = 0; j < symbol_cnt; j++)
                cout << symbols[j].value << " ";
            cout << "-> " << boolean(symbols, symbol_cnt, expr, expr_len) << endl;
            n = 0;
        }
    }
};