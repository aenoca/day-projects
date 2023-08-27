#include <array>
#include <vector>
#include "tile.hpp"
#include "piece.hpp"

using namespace std;

/**
 * Class to define the chess board, and the pieces on it.
*/
class Board
{
    private:
        /// @brief 2D array of tiles, 8x8. First index is columns, second is rows
        array<array<Tile, 8>, 8> tiles;

        /// @brief vector of pieces on the board
        vector<Piece*> pieces;

        void initialize_pieces(Color c)
        {
            // initalize the pawns first 
            int row = 2;

            if (c == BLACK) row = 7;

            string allowed_letters = tiles[0][0].get_allowed_letters();
            for (int i = 0; i < 8; i++)
            {
                pieces.push_back(new Pawn(c, &tiles[i][row-1]));
            }

            // initalize the pieces
            row = 1;
            if (c == BLACK) row = 8;

            pieces.push_back(new Rook(c, &tiles[0][row-1]));
            pieces.push_back(new Knight(c, &tiles[1][row-1]));
            pieces.push_back(new Bishop(c, &tiles[2][row-1]));
            pieces.push_back(new Queen(c, &tiles[3][row-1]));
            pieces.push_back(new King(c, &tiles[4][row-1]));
            pieces.push_back(new Bishop(c, &tiles[5][row-1]));
            pieces.push_back(new Knight(c, &tiles[6][row-1]));
            pieces.push_back(new Rook(c, &tiles[7][row-1]));
        }


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
                        tiles[i][j] = Tile(WHITE, 'a' + i, j+1);
                    } else
                    {
                        tiles[i][j] = Tile(BLACK, 'a' + i, j+1);
                    }
                }
            }

            initialize_pieces(WHITE);
            initialize_pieces(BLACK);

            // pieces.push_back(new Pawn(WHITE, &tiles[0][0]));

            /*
            /// initialize the pieces on the board
            /// black pieces
            pieces.push_back(new Rook(WHITE, 'a', 1));
            pieces.push_back(new Knight(WHITE, 'b', 1));
            pieces.push_back(new Bishop(WHITE, 'c', 1));
            pieces.push_back(new Queen(WHITE, 'd', 1));
            pieces.push_back(new King(WHITE, 'e', 1));
            pieces.push_back(new Bishop(WHITE, 'f', 1));
            pieces.push_back(new Knight(WHITE, 'g', 1));
            pieces.push_back(new Rook(WHITE, 'h', 1));

            string allowed_letters = tiles[0][0].get_allowed_letters();
            for (int i = 0; i < 8; i++)
            {
                pieces.push_back(new Pawn(WHITE, allowed_letters[i], 2));
            }

            /// white pieces
            pieces.push_back(new Rook(BLACK, 'a', 8));
            pieces.push_back(new Knight(BLACK, 'b', 8));
            pieces.push_back(new Bishop(BLACK, 'c', 8));
            pieces.push_back(new Queen(BLACK, 'd', 8));
            pieces.push_back(new King(BLACK, 'e', 8));
            pieces.push_back(new Bishop(BLACK, 'f', 8));
            pieces.push_back(new Knight(BLACK, 'g', 8));
            pieces.push_back(new Rook(BLACK, 'h', 8));

            for (int i = 0; i < 8; i++)
            {
                pieces.push_back(new Pawn(BLACK, allowed_letters[i], 7));
            }
            */
        }

        ~Board()
        {
            for (Piece* piece : pieces)
            {
                delete piece;
            }
        }

        /// @brief print the board
        ostream& print_board(ostream& os) const
        {
            for (int i = 7; i >=0 ; i--)
            {
                os << i+1 << "\t";
                for (int j = 0; j < 8; j++)
                {
                    os << tiles[i][j] << "\t";
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

        /// @brief print the pieces
        ostream& print_pieces(ostream& os) const
        {
            for (Piece* piece : pieces)
            {
                os << *piece << endl;
            }
            return os;
        }

        /// override the << operator to print the board, friend function (i.e. not a member function)
        friend ostream& operator<<(ostream& os, const Board& board)
        {
            board.print_board(os);
            board.print_pieces(os);

            return os;
        }


};