module Warmup exposing (..)

import List exposing (..)
import Basics exposing (..)

change: Int -> (Int, Int, Int, Int)
change amount =
  let
    a = amount
    b = a % 25
    c = b % 10
    d = c % 5
  in
    (,,,) (a // 25) (b // 10) (c // 5) d

stripQuotes: String -> Int
stripQuotes input = 0

powers: Int -> Int -> List Int
powers x limit =
  List.map (\a -> x ^ a) (range 0 (floor (logBase (toFloat x) (toFloat limit))))

sumOfCubesOfOdds: List Int -> Int
sumOfCubesOfOdds input = 0

daysBetween: String -> String  -> Int
daysBetween firstDate secondDate = 0
