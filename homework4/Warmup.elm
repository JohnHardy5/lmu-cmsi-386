module Warmup exposing (..)

import List exposing (..)
import Basics exposing (..)

change: Int -> Result String (Int, Int, Int, Int)
change amount =
  if amount < 0 then Err "amount cannot be negative" else
    Ok <|
      let
        quarters = amount
        dimes = quarters % 25
        nickles = dimes % 10
        pennies = nickles % 5
      in
        (,,,) (quarters // 25) (dimes // 10) (nickles // 5) pennies

stripQuotes: String -> String
stripQuotes input = ""

powers: Int -> Int -> Result String (List Int)
powers base limit =
  if base < 0 then Err "negative base" else
    Ok <|
      List.map (\a -> base ^ a) (range 0 (floor (logBase (toFloat base) (toFloat limit))))

sumOfCubesOfOdds: List Int -> Int
sumOfCubesOfOdds input = 0

daysBetween: String -> String  -> Result String (Int)
daysBetween firstDate secondDate =
  Ok <| 0
