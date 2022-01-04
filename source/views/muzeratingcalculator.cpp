/*
    Copyright (C) 2020 Robert J. Joynt and Kester Falge.

    This software uses the QT (https://www.qt.io/) GPLv3 Open Source License
    (https://doc.qt.io/qt-5/gpl.html).

    This software is distributed under the GNU General Public License Version 3.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    (https://www.gnu.org/licenses/).
*/

/*
    This namepace includes functions to calculate the Muze Rating
    given an array of star ratings. The nth element in the star array
     is the number of tracks with an n-1 star rating.
*/

#include "muzeratingcalculator.h"


namespace MuzeRatingCalculator {

    float muzeRating(int stars[5]) {

        // Set the scale factor and shift

        static constexpr float RATING_SCALE = 3.0f / 2.0f;
        static constexpr float RATING_SHIFT = 5.0f;


        // Get the raw rating.

        double r = rawRating(stars);


        // Scale and shift the raw rating.

        r =  r * RATING_SCALE + RATING_SHIFT;


        // Round the rating

        r = round(r * 10.0f) / 10.0f;
        return r;
    }

    std::string  muzeRatingString(int stars[5]) {

        float rating = MuzeRatingCalculator::muzeRating(stars);
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << rating;
        std::string ratingString = ss.str();
        return ratingString;
    }

    float starsPerRatedTrack(int stars[5]) {

        // Calculate

        float starsPerRatedTrack = (float) numberOfStars(stars) / (float) numberOfTracks(stars);


        // Round the stars per track

        starsPerRatedTrack = round(starsPerRatedTrack * 10.0f) / 10.0f;

        return starsPerRatedTrack;
    }

    std::string starsPerRatedTrackString(int stars[5]) {

        float starsPerRatedTrack = MuzeRatingCalculator::starsPerRatedTrack(stars);
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << starsPerRatedTrack;
        std::string starsPerRatedTrackString = ss.str();
        return starsPerRatedTrackString;
    }

    int numberOfTracks(int stars[5]) {
        int n = 0;

        for (int i = 0; i < 5; i++)
            n += stars[i];

        return n;
    }

    int numberOfStars(int stars[5]) {
        int n = 0;

        for(int i = 0; i < 5; i++)
            n = n + stars[i] * (i + 1);

        return n;
    }

    namespace
    {
        // internal fuction to the namespace to calculate the raw muze rating
        // The raw muze rating is the calculation before scaling and shifting

        double rawRating(int stars[5]) {

            // Set the mean to be 3 stars.

            const int MEAN = 3;
            int n = 0;
            double sum = 0;


            // Loop through the sigma function to calculate the deviation from the mean
            // and apply a 3/2 power.

            for(int i = 0; i < 5; i++) {
                int f = stars[i];
                if(f != 0) {
                    int x = i + 1;
                    n = n + f;
                    int deviation = x - MEAN;
                    sum = sum + f * (deviation >= 0? 1.0f : -1.0f) * pow(std::abs(deviation), 3.0f/2.0f);
                 }
            }

            // Divide by the root of n

            double base = sum / std::sqrt(n);


            // Apply a 3/2 root to the sigma result (including the root denominator).

            double rawRating = (base >= 0? 1.0f : -1.0f) * pow(std::abs(base), (2.0f/3.0f));
            return rawRating;
        }
    }
}







