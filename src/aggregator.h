#ifndef AGGREGATOR_H
#define AGGREGATOR_H

#include <vector>
#include "SDL.h"
#include "game.h"

enum Task
{
    eQuitGame = 0,
    eDisplayResults = 1,
    eDisplayRanking = 2,
    eSaveOwnResults = 3,
    eMaxNumberTasks
};

enum SortOptions
{
    eScore = 0,
    eSize,
    eMaxSortOption
};

struct ResultItem
{
    unsigned int _score;
    unsigned int _size;
    std::string _name;

    ResultItem(std::string name, int score, int size) : _name(name), _score(score), _size(size) {}
};

constexpr int kMaxInputBufferSize = 65536;
const std::string kResultFileName{"results.txt"};

class Aggregator
{
public:
    Aggregator(Game &game);
    ~Aggregator();

    void Run();

private:
    void DisplayGameResult();
    void DisplayRankingTable();

    void SaveResults();
    void AskUser();
    std::string InputUserName();

    void ReadFile();
    void SortResultItems();
    static bool CompareScore(ResultItem r1, ResultItem r2);
    static void Clear();


    /**
     * Holds the game instance
     * */
    Game &_game;
    /**
     * Name of the file which saves all results
     * */
    std::string _filename;

    /**
     * Currently choosen task, which the aggregator executes
     * */
    Task taskNum_;

    /**
     * List of result entries read from file 
     * */
    std::vector<ResultItem> resultItems;
};

#endif