/******************************************************************
 * Section 13 Challenge
 * Movies.h
 *
 * Models a collection of Movies as a std::vector
 *
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

/*************************************************************************
   Movies no-args constructor
**************************************************************************/
Movies::Movies()
{
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies()
{
}

/*************************************************************************
  add_movie expects the name of the movie, rating and watched count

  It will search the movies vector to see if a movie object already exists
  with the same name.

  If it does then return false since the movie already exists
  Otherwise, create a movie object from the provided information
  and add that movie object to the movies vector and return true
  *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched)
{
    int size = movies.size();
    for (int i{}; i < size; i++)
    {
        if (movies.at(i).get_name() == name)
        {
            return false;
        }
    }
    Movie myMovie(name, rating, watched);
    movies.push_back(myMovie);
    return true;
}

/*************************************************************************
   increment_watched expects the name of the movie to increment the
   watched count

   It will search the movies vector to see if a movie object already exists
   with the same name.
   If it does then increment that objects watched by 1 and return true.

   Otherwise, return false since then no movies object with the movie name
   provided exists to increment
   *********************************************************************/
bool Movies::increment_watched(std::string name)
{
    int size = movies.size();
    for (int i{}; i < size; i++)
    {
        if (movies.at(i).get_name() == name)
        {
            movies.at(i).increment_watched();
            return true;
        }
    }
    return false;
}

/*************************************************************************
    display

    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const
{
    int size = movies.size();
    for (int i{}; i < size; i++)
    {
        movies.at(i).display();
    }
    // You implement this method
}