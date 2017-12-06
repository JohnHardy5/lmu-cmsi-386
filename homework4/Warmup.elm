module Warmup exposing (..)

import List exposing (..)
import Basics exposing (..)
--import Tuple exposing (..)

change: Int -> (Int, Int, Int, Int)
change amount = (0, 0, 0, 0)

stripQuotes: String -> String -> Int
stripQuotes firstDate secondDate = 0

powers: Int -> Int -> List Int
powers x limit =
  map (\a -> x ^ a) (range 0 (floor (logBase (toFloat x) (toFloat limit))))

sumOfCubesOfOdds: List Int -> Int
sumOfCubesOfOdds input = 0

daysBetween: String -> Int
daysBetween input = 0
