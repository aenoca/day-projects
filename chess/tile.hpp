#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <iostream>

using namespace std;

// prototype for Piece, necessary for removing circular dependencies
class Piece;

/**
 * Structure to define the location of a tile on the chess board.
*/
struct Location
{
    char column;
    int row;
};

enum Color {BLACK, WHITE};

string get_color_name(Color c)
{
    switch(c)
    {
        case BLACK:
            return "black";
        case WHITE:
            return "white";
    }
}

/**
 * Class to define a single square on the chess board.
*/
class Tile
{
    private:
        Color color;
        Location location;

        Piece* piece = nullptr; // each Tile is associated to a piece, initialized to nullptr

        // static member declaration
        static string allowed_letters; // only one copy is used for all objects (allocates memory only once)

        bool valid_letter(char& letter)
        {
            for (char c : allowed_letters )
            {
                if (letter == c)
                {
                    return true;
                }
            }

            return false;
        }

        bool valid_number(int row_num)
        {
            if (row_num >= 1 && row_num <= 8)
            {
                return true;
            }

            return false;
        }

    public:
        Tile()
        {
            color = WHITE;
            location.row = 1;
            location.column = 'a';
        }

        Tile(Color tile_color, char tile_column, int tile_row)
        {
            if (tile_color == BLACK || tile_color == WHITE)
            {
                color = tile_color;
            } else
            {
                throw "Invalid color '" + get_color_name(tile_color) + "' for tile. Must be black or white.";
            }

            if (!valid_letter(tile_column) || !valid_number(tile_row))
            {
                throw "Invalid tile location '" + tile_column + to_string(tile_row) + "'";
            } else
            {
                location.row = tile_row;
                location.column = tile_column;
            }
        }

        void set_piece(Piece* p)
        {
            piece = p;
        }

        Piece* get_piece() const
        {
            return piece;
        }

        bool occupied() const
        {
            if (piece == nullptr) return false;
            return true;
        }

        Color get_color() const
        {
            return color;
        }

        Location get_location() const
        {
            return location;
        }

        string get_allowed_letters() const
        {
            return allowed_letters;
        }

        /// override the << operator to print the tile
        friend ostream& operator<<(ostream& os, const Tile& tile)
        {
            os << get_color_name(tile.color) << "_" << tile.location.column << tile.location.row;
            return os;
        }

};

// initialization of static variable of class
string Tile::allowed_letters = "abcdefgh";

#endif