import           Test.Tasty
import           Test.Tasty.HUnit

import           Skewers

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup
  "Barbecue skewers"
  [ testCase "No skewers"            testNoSkewers
  , testCase "Vegetarian skewer"     testVegetarianSkewer
  , testCase "Non-vegetarian skewer" testNonVegetarianSkewer
  , testCase "Empty skewer"          testEmptySkewer
  , testCase "Mixed grill"           testMixedGrills
  ]

testNoSkewers :: Assertion
testNoSkewers = skewers [] @?= (0, 0)

testVegetarianSkewer :: Assertion
testVegetarianSkewer = skewers ["--oo--o--oo--"] @?= (1, 0)

testNonVegetarianSkewer :: Assertion
testNonVegetarianSkewer = skewers ["--xo--x--ox--"] @?= (0, 1)

testEmptySkewer :: Assertion
testEmptySkewer = skewers ["-------"] @?= (1, 0)

testMixedGrills :: Assertion
testMixedGrills = map skewers grills @?= [(1, 4), (2, 3), (3, 2)]
 where
  grills =
    [ [ "--xo--x--ox--"
      , "--xx--x--xx--"
      , "--oo--o--oo--"
      , "--xx--x--ox--"
      , "--xx--x--ox--"
      ]
    , [ "--oooo-ooo--"
      , "--xx--x--xx--"
      , "--o---o--oo--"
      , "--xx--x--ox--"
      , "--xx--x--ox--"
      ]
    , [ "--oooo-ooo--"
      , "--xxxxxxxx--"
      , "--o---"
      , "-o-----o---x--"
      , "--o---o-----"
      ]
    ]
