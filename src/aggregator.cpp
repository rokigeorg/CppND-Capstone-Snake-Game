#include "aggregator.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "SDL.h"


Aggregator::~Aggregator() {}

Aggregator::Aggregator(Game &game) : _game(game)
{
}

void Aggregator::Run()
{
    bool running = true;
    Clear();

    while (running)
    {
        AskUser();

        switch (taskNum_)
        {
        case eQuitGame:
            running = false;
            return;
            break;
        case eDisplayResults:
            DisplayGameResult();
            break;
        case eDisplayRanking:
            DisplayRankingTable();
            break;
        case eSaveOwnResults:
            SaveResults();
            running = false;
            break;
        default:
            break;
        }
    }
}

void Aggregator::AskUser()
{
    int user_input;
    std::cout << "***********************************\n";
    std::cout << "******   Snake Menu    ************\n";
    std::cout << "***********************************\n";
    std::cout << "\n";

    std::cout << "- OPTION 0: Quit the game. \n";
    std::cout << "- OPTION 1: Display last results. \n";
    std::cout << "- OPTION 2: Display overall ranking. \n";
    std::cout << "- OPTION 3: Save own results and quit game. \n\n";

    while (true)
    {
        std::cout << "Please, enter number of the OPTION: ";
        std::cin >> user_input;

        if (user_input >= 0 && user_input < Task::eMaxNumberTasks)
        {
            taskNum_ = static_cast<Task>(user_input);
            std::cout << "____________________________\n";

            return;
        }
    }
}

void Aggregator::DisplayGameResult()
{
    std::cout << "Score: " << _game.GetScore() << "\n";
    std::cout << "Size: " << _game.GetSize() << "\n";
}

void Aggregator::DisplayRankingTable()
{
    std::cout << "Ranking \n";
    ReadFile();
    //Sort items, highest score first
    std::sort(resultItems.begin(), resultItems.end(), Aggregator::CompareScore);

    std::cout << "----------------------------------------\n";
    std::cout << "| "
              << " RANK "
              << " | "
              << " SCORE "
              << " | "
              << " SCORE "
              << " | "
              << "  SIZE "
              << " |" << std::endl;
    std::cout << "----------------------------------------\n";

    int rank = 1;
    for (ResultItem ri : resultItems)
    {
        std::cout << "| " << rank << " | " << ri._name << " | " << ri._score << " | " << ri._size << " |" << std::endl;
        rank++;
    }

    resultItems.clear();
}

void Aggregator::SaveResults()
{
    //Ask user to save there name
    std::string name = InputUserName();
    std::string resultLine = name;
    resultLine += " ";
    resultLine += std::to_string(_game.GetScore());
    resultLine += " ";
    resultLine += std::to_string(_game.GetSize());
    resultLine += "\n";

    SDL_RWops *rw = SDL_RWFromFile("results.txt", "a+");
    if (rw != NULL)
    {
        const char *str = resultLine.c_str();
        size_t len = SDL_strlen(str);
        if (SDL_RWwrite(rw, str, 1, len) != len)
        {
            printf("Couldn't fully write string\n");
        }
        else
        {
            printf("Wrote %ld 1-byte blocks\n", len);
            std::cout << "Saved: " + resultLine;
        }
        SDL_RWclose(rw);
    }
}

std::string Aggregator::InputUserName()
{
    std::string user_input;
    DisplayGameResult();
    std::cout << "For saving these results.\n";
    std::cout << "Please, enter your name: ";
    std::cin >> user_input;
    return user_input;
}

void Aggregator::ReadFile()
{
    std::string name, score, size;
    std::string line;
    std::ifstream stream(kResultFileName);
    if (stream.is_open())
    {
        while (std::getline(stream, line))
        {
            std::istringstream linestream(line);
            linestream >> name >> score >> size;

            ResultItem item(name, atoi(score.c_str()), atoi(size.c_str()));
            resultItems.emplace_back(item);
        }
    }
    else
    {
        std::cout << "No results.txt found. Operation not possible!\n";
    }
}

bool Aggregator::CompareScore(ResultItem r1, ResultItem r2)
{
    return r1._score > r2._score;
}


void Aggregator::Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}