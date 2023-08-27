#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <string>
#include "tile.hpp"
using namespace std;

enum Type {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING};

string get_type_name(Type t)
{
    switch (t)
    {
        case PAWN:
            return "Pawn";
        case ROOK:
            return "Rook";
        case KNIGHT:
            return "Knight";
        case BISHOP:
            return "Bishop";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        default:
            return "Unknown";
    }
}



class Piece
{
    private:
        

    
    protected:
        Type type;
        Color color;
        // each Piece is associated to a Tile, i.e., points to a Tile. 
        Tile* location;


        //Location location;
        bool alive;

    public:
        Piece(Type type, Color color, Tile* loc)
        : type(type), color(color), alive(true)
        {
            location = loc;
            loc->set_piece(this);
        }

        virtual bool move(char column, int row) = 0; // virtual pure method, must be implemented by derived classes

        Location get_location() const
        {
            return location->get_location();
        }

        friend ostream& operator<<(ostream& os, const Piece& piece)
        {
            Location l = piece.location->get_location();

            os << get_color_name(piece.color) << " " << get_type_name(piece.type) << " at " << l.column << l.row;
            return os;
        }

};

class Pawn : public Piece
{
    private:
        
    public:
        Pawn(Color color, Tile* loc)
        : Piece(PAWN, color, loc)
        {}


        /**
         * The pawn has the following moves:
         *  - if on row 2 and white or row 7 and black
         *      - may advance of 2 moves forward (enables the prise en passant)
         *  - may advance one tile forward (increasing for white, decreasing for black)
         *  - may move in diagonal if opposite color piece occupies it
         *  - may not move to tile that is occupied by a same colored piece
         *  - when moving to the last row (8 for white, 1 for black), get upgraded to another piece
        */
        bool move(char column, int row)
        {
            /// 1) check that target tile is not occupied by same colored piece

            return true;
        }
};

class Rook : public Piece
{
    private:
        
    public:
        Rook(Color color, Tile* loc)
        : Piece(ROOK, color, loc)
        {}

        /**
         * The rook has the following moves:
         *  - may move on all tiles of row or column (until blockage)
         *  - can castle with king
         *  - 
        */
        bool move(char column, int row)
        {
            return true;
        }
};

class Knight : public Piece
{
    private:
        
    public:
        Knight(Color color, Tile* loc)
        : Piece(KNIGHT, color, loc)
        {}

        /**
         * The knight has the following moves:
         *  - can move in L shape
         *  - can move over the other pieces
        */
        bool move(char column, int row)
        {
            return true;
        }
};

class Bishop : public Piece
{
    private:
        
    public:
        Bishop(Color color, Tile* loc)
        : Piece(BISHOP, color, loc)
        {}

        /**
         * The bishop has the following moves:
         *  - can move in diagonal (must always stay on the same color)
         *
        */
        bool move(char column, int row)
        {
            return true;
        }
};

class Queen : public Piece
{
    private:
        
    public:
        Queen(Color color, Tile* loc)
        : Piece(QUEEN, color, loc)
        {}

        /**
         * The queen has the following moves:
         *  - can move in diagonal (like a bishop)
         *  - can move along rows or columns (like a rook)
        */
        bool move(char column, int row)
        {
            return true;
        }
};

class King : public Piece
{
    private:
        
    public:
        King(Color color, Tile* loc)
        : Piece(KING, color, loc)
        {}

        /**
         * The king has the following moves:
         *  - may only move 1 tile in any direction
         *  - may castle with either rook (if possible, i.e., no piece in between and no piece cutting the trajectory)
        */
        bool move(char column, int row)
        {
            return true;
        }
};

#endif