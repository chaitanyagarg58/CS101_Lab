#include <iostream>
#include <cmath>
#include <vector>

struct Transaction
{
    int user_id;
    bool is_deposit;
    int amount, balance;

    void print()
    {
        if (is_deposit)
            std::cout << user_id << " deposit " << amount << " " << balance << std::endl;
        else
            std::cout << user_id << " withdraw " << amount << " " << balance << std::endl;
    }
};

struct User
{
    int id;
    int balance;
    int n_deposits = 0, n_withdrawls = 0;
    std::vector<Transaction> transac;

    int deposit(int amount)
    {
        balance += amount;
        Transaction temp = {id, true, amount, balance};
        transac.push_back(temp);
        n_deposits++;
        return 0;
    }

    int withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            Transaction temp = {id, false, amount, balance};
            transac.push_back(temp);
            n_withdrawls++;
            return 0;
        }
        else
            return -1;
    }

    void print_history()
    {
        if (transac.size() > 0)
            transac[transac.size() - 1].print();
        if (transac.size() > 1)
            transac[transac.size() - 2].print();
        if (transac.size() > 2)
            transac[transac.size() - 3].print();
    }
};

struct Request
{
    int user_id;
    bool is_deposit;
    int amount;

    void print()
    {
        if (is_deposit)
            std::cout << user_id << " deposit " << amount << std::endl;
        else
            std::cout << user_id << " withdraw " << amount << std::endl;
    }
};

struct Bank
{
    int n_users = 0;
    User users[10];
    int n_reqs = 0;
    Request reqs[10];

    int add_user(int init_bal)
    {
        if (n_users < 10)
        {
            users[n_users].id = n_users;
            users[n_users].balance = init_bal;
            n_users++;
            return 0;
        }
        return -1;
    }

    void add_request(int user_id, bool is_deposit, int amount)
    {
        if (n_reqs < 10)
        {
            reqs[n_reqs].user_id = user_id;
            reqs[n_reqs].is_deposit = is_deposit;
            reqs[n_reqs].amount = amount;
            n_reqs++;
        }
        return;
    }

    int get_balance(int user_id)
    {
        return users[user_id].balance;
    }

    int get_num_deposits(int user_id)
    {
        return users[user_id].n_deposits;
    }

    int get_num_withdrawals(int user_id)
    {
        return users[user_id].n_withdrawls;
    }

    void deposit(int user_id, int amount)
    {
        users[user_id].deposit(amount);
    }

    void withdraw(int user_id, int amount)
    {
        users[user_id].withdraw(amount);
    }

    void print_user_history(int user_id)
    {
        users[user_id].print_history();
    }
};