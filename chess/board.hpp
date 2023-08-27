#include <array>
#include "tile.hpp"

using namespace std;

/**
 * Class to define the chess board, and the pieces on it.
*/
class Board
{
    private:
        array<array<Tile, 8>, 8> tiles;

    public:
        Board()
        {
            /// initialize the board with tiles, start with row 1 and work up to 8
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++) 
                {
                    if ((i + j) % 2 == 0)
                    {
                        tiles[i][j] = Tile("white", 'a' + j, i+1);
                    } else
                    {
                        tiles[i][j] = Tile("black", 'a' + j, i+1);
                    }
                }
            }
        }

        /// override the << operator to print the board, friend function (i.e. not a member function)
        friend ostream& operator<<(ostream& os, const Board& board)
        {
            for (int i = 7; i >=0 ; i--)
            {
                os << i+1 << "\t";
                for (int j = 0; j < 8; j++)
                {
                    os << board.tiles[i][j] << "\t";
                }
                os << endl;
            }

            for (int i = 0; i < 8; i++)
            {
                os << "\t" << char ('a' + i);
            }
            os << endl;
            return os;
        }


};