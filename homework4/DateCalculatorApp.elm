import Html exposing (..)
import Html.Attributes exposing (..)
-- import Warmup exposing (..)

main : Html msg
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
    , p [] [text "From", input [style
                    [ ("border", "2px solid grey")
                    , ("margin-left", "8px")
                    ]
                    , id "from"
                    , type_ "date"
                    ] []]
    , p [] [text "to", input [style
                    [ ("border", "2px solid grey")
                    , ("margin-left", "8px")
                    ]
                    , id "to"
                    , type_ "date"
                    ] []]
    , p [] [text "is", span [] []]
    ]
