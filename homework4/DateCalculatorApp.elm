import Html exposing (..)
import Html.Attributes exposing (..)
-- import Warmup exposing (..)

main =
  body [style
      [ ("text-align", "center")
      ,  ("font", "16px Arial")
      ,  ("background-color", "linen")
      ,  ("margin", "0")
      ]
    ]
    [ h1 [style
          [ ("font", "bold 40px Avenir")
          ,  ("margin-top", "0")
          ,  ("padding", "5px")
          ,  ("background-color", "cyan")
          ]
        ]
        [ text "Date Calculator" ]
    , p [] [text "From", input [] []]
    , p [] []
    , p [] []
    ]
