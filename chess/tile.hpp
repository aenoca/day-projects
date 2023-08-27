#include <string>
using namespace std;

struct Location
{
    char column;
    int row;
};

class Tile
{
    private:
        string color;
        Location location;

        // static member declaration
        static string allowed_letters; // only one copy is used for all objects (allocates memory only once)

        bool valid_letter(char& letter)
        {
            for (char& c : allowed_letters )
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
        Tile(string tile_color, char tile_column, int tile_row)
        {
            if (tile_color == "black" || tile_color == "white")
            {
                color = tile_color;
            } else
            {
                throw "Invalid color '" + tile_color + "' for tile. Must be black or white.";
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

        string get_color() const
        {
            return color;
        }

        Location get_location() const
        {
            return location;
        }
};

// initialization of static variable of class
string Tile::allowed_letters = "abcdefgh";