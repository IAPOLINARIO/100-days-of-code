<?php
namespace  App;
function FindAndcountSkewersForType($skewers){
    $totalVegetarianSkewers = 0;
    $totalNonVegetarianSkewers = 0;

    foreach ($skewers as $skewer){
        if(mb_strpos($skewer, 'x') !== false){
            $totalNonVegetarianSkewers++;
        }else{
            $totalVegetarianSkewers++;
        }
    }

    echo "We have {$totalVegetarianSkewers} vegetarian skewers! \n";
    echo "We have {$totalNonVegetarianSkewers} non-vegetarian skewers!\n";

    return [
        $totalVegetarianSkewers,
        $totalNonVegetarianSkewers
    ];
}